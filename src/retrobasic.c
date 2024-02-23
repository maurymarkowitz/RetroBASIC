/* Interpreter for RetroBASIC
 Copyright (C) 2020 Maury Markowitz
 
 Based on gnbasic
 Copyright (C) 1998 James Bowman
 
 This file is part of RetroBASIC.
 
 RetroBASIC is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2, or (at your option)
 any later version.
 
 RetroBASIC is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with RetroBASIC; see the file COPYING.  If not, write to
 the Free Software Foundation, 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */

#include <sys/time.h> // for run timers
#include <unistd.h>   // used for sleep

#include "retrobasic.h"
#include "parse.h"

#if _WIN32
  #include <conio.h>
#else
  #include <sys/termios.h>
#endif

/* here's the actual definition of the interpreter state which is extern in the header */
interpreterstate_t interpreter_state;

/* and the same for the various flags */
bool run_program = true;							// default to running the program, not just parsing it
bool print_stats = false;							// do not print or write stats by default
bool write_stats = false;
int tab_columns = 10;									// based on PET BASIC, which is a good enough target
bool trace_lines = false;
bool upper_case = false;							// force INPUT to upper case
int array_base = 1;										// lower bound of arrays, can be set to 0 with OPTION BASE
int random_seed = -1;									// reset with RANDOMIZE, if -1 then auto-seeds
bool string_slicing = false;					// are references like A$(1,1) referring to an array entry or doing slicing?
bool goto_next_highest = false;				// if a branch targets an non-existant line, should we go to the next highest?
bool ansi_on_boundaries = false;			// if the value for an ON statement <1 or >num entries, should it continue or error?
bool ansi_tab_behaviour = false;			// if a TAB < current column, ANSI inserts a CR, MS does not

char *source_file = "";
char *input_file = "";
char *print_file = "";
char *stats_file = "";

/* private types used only within the interpreter */

/* value_t is used to store (and process) the results of an evaluation */
// NOTE: this currently cannot return an array, so MAT instructions are not possible
typedef struct {
  int type;            /* NUMBER, STRING */
  char *string;
  double number;
} value_t;

/* function_storage_t holds the expression from the DEF */
typedef struct {
  int type;               /* NUMBER, STRING */
  list_t *parameters;     // parameters, if any, as variable_reference_t
  expression_t *formula;	// related formula
} function_storage_t;

/* forward declares */
static bool slice_limits(const variable_reference_t *variable, const variable_storage_t *value, int *start, int* end);

static value_t evaluate_expression(expression_t *e);

static int line_for_statement(const list_t *s);
static int current_line(void);

static void print_variables(void);
static void delete_variables(void);
static void delete_functions(void);
static void delete_lines(void);
static void clear_stack(void);
static void reset_data_pointer(int line);

/* definitions of variables used by the static analyzer */
clock_t start_ticks = 0, end_ticks = 0;	// start and end ticks, for calculating CPU time
struct timeval start_time, end_time;    // start and end clock, for total run time
struct timeval reset_time;     					// if the user resets the time with TIME$, this replaces start_time

/************************************************************************/

/**
 * Error reporting routine that also prints the line number of the error.
*/
static void basic_error(const char *message)
{
  fprintf(stderr, "%s at line %d\n", message, current_line());
}

/**
 * Gets a keystroke, or null if no key is pressed. Used for INKEY$.
 *
 * @return the keycode, NULL if no key is pressed or an error occurred.
 *
 * See: https://stackoverflow.com/questions/1798511/how-to-avoid-pressing-enter-with-getchar-for-reading-a-single-character-only
*/
int getkey(int fd)
{
#if _WIN32
    if (kbhit) {
      return getch();
    } else {
      return 0;
    }
#else
  int ch;
  unsigned char buf[1];
  struct termios oldt, newt;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  cfmakeraw(&newt);
  newt.c_cc[VMIN] = 0;
  newt.c_cc[VTIME] = 0;
  newt.c_lflag &= ~(ICANON | ECHO);
//  newt.c_cc[VMIN] = 0;
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  ch = (int)read(STDIN_FILENO, buf, 1);
  if (ch > 0)
      ch = buf[0];
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  return ch;
#endif
}

/* Returns an int containing the type of the variable based on its name
	 or an initial type being passed in. Note that this only works on variable
	 *references*, not the stored versions, as those have mangled names. */
int variable_type(const variable_reference_t *variable)
{
	int type;
	
	char trailer = variable->name[strlen(variable->name) - 1];
	if (trailer == '$')
		type = STRING;
	else if (trailer == '%')
		type = INTEGER;
	else if (trailer == '!')
		type = SINGLE;
	else if (trailer == '#')
		type = DOUBLE;
	else
		type = NUMBER; // this works for all of them, int, dbl, etc.

	return type;
}

/* Returns the storage record for a given variable. */
// NOTE: this should be refactored so we don't duplicate the code below
variable_storage_t* variable_storage(const variable_reference_t *variable)
{
  variable_storage_t *storage;
  char *storage_name = str_new(variable->name);
  if ((!string_slicing || variable_type(variable) != STRING) && variable->subscripts != NULL)
    str_append(storage_name, "(");

  // see if we can find the entry in the symbol list
  storage = lst_data_with_key(interpreter_state.variable_values, storage_name);
  return storage;
}

/* Returns an either_t containing a string or a number for the underlying
   variable, along with its type in the out-parameter 'type'. If the
   variable has not been encountered before it will be created here. */
/* NOTE: this code also handles string slicing. it would be much preferable
   to do that as a function call so it could overload the MID$-style functions
   but I could not figure out how to do that at runtime in the yacc code. */
either_t* variable_value(const variable_reference_t *variable, int *type)
{
  variable_storage_t *storage;
  char *storage_name;
  bool isArray = false;
	int index;
  
  // In MS basic, A() and A are two different variables, so here
  // we mangle the name to include a "(" if it's an array. This is also5
	// true in the original Dartmouth BASIC, according to the DTSS emulator.
	// Also see notes in CHANGE/CONVERT.
	//
	// If we are in a dialect where () is a string slice, not an array access,
	// like HP and Atari, then references to A$() are actually to A$ and we
	// do *not* munge the name.
  storage_name = str_new(variable->name);
  if ((!string_slicing || variable_type(variable) != STRING) && variable->subscripts != NULL) {
    str_append(storage_name, "(");
    isArray = true;
  }

	// see if we can find the entry in the symbol list
	storage = lst_data_with_key(interpreter_state.variable_values, storage_name);
  
  // if not, make a new variable slot in values and set it up
  if (storage == NULL) {
    // calloc a single slot, if it's an array we'll use this as the template
    storage = calloc(1, sizeof(*storage));
    
		// the type is normally set as part of the variable name, like $
		// however, there is an exception to this in later MS dialects,
		// they include the DEFSTR/SNG/DBL/INT, in which case the variable
		// names do not have the trailer. To handle this case, we pass in
		// the type when encountering those statements.
		storage->type = variable_type(variable);
    storage->actual_dimensions = NULL;
    storage->dimed_dimensions = NULL;
    
    // now calloc the result and insert it into the values tree
    storage->value = calloc(1, sizeof(storage->value[0]));
		interpreter_state.variable_values = lst_insert_with_key_sorted(interpreter_state.variable_values, storage, storage_name);
  }
  
  // if we haven't started running yet, we were being called during parsing to
  // populate the variable table. In that case, we don't need the value, so...
  if (interpreter_state.running_state == 0)
    return NULL;
  
  // at this point we have either found or created the variable, so...
  
  // compute array index, or leave it at zero if there is none
  index = 0;
  if (!string_slicing && isArray) {
    list_t *act_dimensions;         // list of actual dimensions in storage, maybe the default 10
		list_t *dim_dimensions;					// list of DIMmed dimensions, if a DIM was encountered
    list_t *variable_indexes;       // list of indices in this variable reference, each is an expression, likely a constant
    
		act_dimensions = lst_first_node(storage->actual_dimensions);
		dim_dimensions = lst_first_node(storage->dimed_dimensions);
    variable_indexes = lst_first_node(variable->subscripts);
    
    // first off, test whether this array has been set up yet, which is in act_
    if (!act_dimensions) {
      // we have not been set up. two possibilities here:
      //
      // if there is a DIM statement for this variable, then the first time
      // we enter this code it's almost certainly as part of the DIM. In that
      // case, the values in dim_dimensions should have already been set and
      // we can make the array that large.
      //
      // if there is no DIM statement, then when we get here it's likely that
      // they are using the default 0..10 dimensions. In that case, dim_ should
      // be empty so we can tell the difference.
      
      // now calculate how large to make the array
      value_t v;
      int slots = 1;
      int actual = 1;
      if (dim_dimensions) {
        // if there are DIMmed dimensions, always use that size
        for (list_t *L = dim_dimensions; L != NULL; L = lst_next(L)) {
          // dimmed dimensions are stored as integer values, no need to eval
          actual = POINTER_TO_INT(L->data);
          
          // copy that value into actual
          storage->actual_dimensions = lst_append(storage->actual_dimensions, INT_TO_POINTER(actual));

          // and add 1 slot for item 0
          slots *= actual + 1; // +1 for the 0th entry
        }
      }
      else {
        // if there was no DIM previously encountered, use the values
        // in this reference, but make them a minimum of 11
        for (list_t *L = variable->subscripts; L != NULL; L = lst_next(L)) {
          v = evaluate_expression(L->data);
          actual = (int)v.number + 1;       // we need to add one more slot for index 0

          // in this case we don't have a DIM, so it's always a minimum of 11 slots
          if (actual < 11)
            actual = 11;
          
          slots *= actual;
          
          // save the result to act_
          storage->actual_dimensions = lst_append(storage->actual_dimensions, INT_TO_POINTER(actual));
        }
      }
      
      // and now calloc it
      // FIXME: we should free the single slot original set up above
      storage->value = calloc(slots, sizeof(storage->value[0]));
      
      // and since we have now set up the actual_dimensions, re-cache this
      act_dimensions = lst_first_node(storage->actual_dimensions);
    } // setting up new array
    
    // the array is now set up, now calculate which slot is being accessed, if any
    
    // the *number* of dimensions has to match, you can't DIM A(1,1) and then LET B=A(1)
    if (lst_length(act_dimensions) != lst_length(variable_indexes))
      basic_error("Array dimension of variable does not match storage");
    else
      while (act_dimensions && variable_indexes) {
        // evaluate the variable reference's index for a given dimension
        value_t this_index = evaluate_expression(variable_indexes->data);
        
        // have to clamp that value
        this_index.number = floor(this_index.number);
				
        // and get the originally defined size for that same dimension
				// NOTE: this may or may not be the same as the DIM, see notes above
				int original_dimension = POINTER_TO_INT(act_dimensions->data);

				// make sure the index is within the originally DIMed bounds
				// NOTE: should check against array_base, not 0, but this doesn't work in Dartmouth. see notes
        if ((this_index.number < 0) || (original_dimension < this_index.number)) {
          basic_error("Array subscript out of bounds");
					this_index.number = 0;//array_base; // the first entry in the C array, so it continues
        }
				
				// now check to see if there are dimed_dimensions, and check against them
				if (dim_dimensions != NULL) {
					int def_dimension = POINTER_TO_INT(dim_dimensions->data);
					if ((this_index.number < 0) || (def_dimension < this_index.number)) {
						basic_error("Array subscript out of DIMmed bounds");
						this_index.number = 0;
					}
				}
        
        // C arrays start at 0, BASIC arrays start at array_base
				index = (index * original_dimension) + this_index.number; // - array_base;
        
        // then move on to the next index in the list
        dim_dimensions = lst_next(dim_dimensions);
        act_dimensions = lst_next(act_dimensions);
        variable_indexes = lst_next(variable_indexes);
      }
  } // isArray
  
  // done with this temp name
  free(storage_name);
  
  // returning the type
	// NOTE: if this is part of a DIM, it's been correctly set above
  *type = storage->type;
  
  // if we are using string slicing OR there is a ANSI-style slice, return that part of the string
  if (*type == STRING) {
    int slice_start, slice_end;
    if (slice_limits(variable, storage, &slice_start, &slice_end)) {
      // if there was a slice, and slicing is on, we need to ignore the subscripts
      if (string_slicing)
        index = 0;
  
      // build a new string (this is leaking!)
      either_t orig_string = storage->value[index];
      either_t *result = calloc(1, sizeof(*result));
      result->string = str_new(orig_string.string);
      str_erase(result->string, slice_start, slice_end - slice_start + 1);
      return result; // NOTE: this is leaking!
    } // had a slice
  } // looking for slicing

  // all done, return the value at that index
  return &storage->value[index];
}

/* cover method for variable_value, allows it to be exported to the parser
 without it having to know about either_t, which is private.
 */
void insert_variable(const variable_reference_t *variable)
{
  int ignore = 0;
  variable_value(variable, &ignore);
}

/* and another version which takes the type for use with DEFINT etc. */
void insert_typed_variable(const variable_reference_t *variable, int type)
{
  variable_value(variable, &type);
}

/* Returns true if the variable is a string and the ref has a slice applied. If true
 it returns the start and end points for the slice, otherwise -1. */
bool slice_limits(const variable_reference_t *variable, const variable_storage_t *storage, int* start, int* end)
{
  // the slice could be in the slice list or the subscripts lists
  list_t *slice_param = NULL;

  // default these to failed
  *start = -1;
  *end = -1;
  
  // needs to be a string, obviously
  if (storage->type != STRING)
    return false;
    
  // see if there is an ANSI slice defined, if so, use that
  if (lst_length(variable->slicing)) {
    // ANSI slices will always have two parameters in the slicing list
    if (lst_length(variable->slicing) != 2)
      basic_error("Wrong number of parameters in string slice");
    
    slice_param = variable->slicing;
  }
  
  // the other possibility is that we have the slicing option turned on,
  // in that case the index we calculated earlier is not correct, so we
  // return that to zero and then use those params as the slices
  if (string_slicing && lst_length(variable->subscripts) > 0) {
    // HP style slices will have one or two parameters
    if (string_slicing && (lst_length(variable->subscripts) != 1 && lst_length(variable->subscripts) != 2))
      basic_error("Wrong number of parameters in string slice");
    
    slice_param = variable->subscripts;
  }
  
  // if either of those got us something, pull out both parameters
  if (slice_param != NULL) {
    *start = evaluate_expression(slice_param->data).number;
    slice_param = lst_next(slice_param);
    if (slice_param && slice_param->data)
      *end = evaluate_expression(slice_param->data).number;
    else
      *end = *start;
    
    // according to ANSI, numbers outside the string should be forced to the string's bounds
    // for non-ANSI, we'll error on odd numbers?
    if (variable->slicing != NULL) {
      *start = (int)fmax(*start, 1);
      *end = (int)fmin(*end, strlen(storage->value->string));
    } else {
      if (*start < 1 || *end < 1 || *end > strlen(storage->value->string)) // no -1, we adjust that next line
        basic_error("String slice out of bounds");
    }
    
    // the numbers above are 1-indexed from BASIC, so we need to...
    *start = *start - 1;
    *end = *end - 1;
    
    // and we're good
    return true;
  }
  
  // if we got here, there was no slice on the reference, so...
  return false;
}


/* Similar to variable_value in concept, this code looks through the list of
 user-defined functions to find a matching name and/or inserts it if it's new.
 the difference is that this returns an expression which we then evaluate.
 */
expression_t *function_expression(const variable_reference_t *function, expression_t *expression)
{
  // see if we can find the entry in the symbol list
  function_storage_t *storage;
	storage = lst_data_with_key(interpreter_state.functions, function->name);
  
  // if not, make a new slot in functions and set it up
  if (!storage) {
    // calloc an entry
    storage = calloc(1, sizeof(*storage));
    
    // set the return type based on the name
    char trailer = function->name[strlen(function->name) - 1];
    if (trailer == '$')
      storage->type = STRING;
    else
      storage->type = NUMBER; // this works for all of them, int, dbl, etc.
    
    // and the subtype, if supplied
    if (trailer == '%')
      storage->type = INTEGER;
    else if (trailer == '!')
      storage->type = SINGLE;
    else if (trailer == '#')
      storage->type = DOUBLE;
    
    // copy over the list of parameters
    storage->parameters = lst_copy(function->subscripts);
    
    // now store the expression/formula
    storage->formula = expression;
    
    // and insert it into storage
		interpreter_state.functions = lst_insert_with_key_sorted(interpreter_state.functions, storage, function->name);
  }
  
  // at this point we have either found or created the formula, so...
  return storage->formula;
}

/* converts a number to a new value_t */
static value_t double_to_value(const double v)
{
  value_t r;
  r.type = NUMBER;
  r.number = v;
  return r;
}

/* converts a number to a string */
/* this system follows the rules found in MS BASICs like the PET
 that is, generally:
 1) if the number is zero, return 0
 2) otherwise, move the decimal until the mantissa is 1e8 <= FAC < 1e9
 3) **round** the resulting 9-digit value
 4) if the number of decimal places moved is -10 < TMPEXP > 1 then just print the result with the decimal moved back
 5) otherwise, use E format
 in all cases, add a leading space for 0 or +ve values, - for -ve
 
 Item (3) means that 9,999,999,999 is printed as 1E+10, which is precisely the G format in C.
 So the code below it needlessly complex as anything other than 0 uses G. However, we'll leave
 in the IFs so that if we find new versions in the future that follow other rules its easy to
 add them.
 */
static char *number_to_string(const double d)
{
  static char str[40]; // use static so we know it won't be collected between calls
  if (d == 0.0) {
    sprintf(str, " 0"); // note the leading space, here and below
  } else if (d >= 0.01 && d <= 999999999) {
    sprintf(str, "% -.9G", d);
  } else if (d <= -0.01 && d >= -999999999) {
    sprintf(str, "% -.9G", d);
  } else {
    sprintf(str, "% -.9G", d);
  }
  return str;
}

/* C does not include formatters to convert to binary, only hex and oct, so from:
 * https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
 */
static char* number_to_bin_string(const double d)
{
  static char str[33]; // use static so we know it won't be collected between calls
  str[0] = '\0';       // safety first!

  // floor the value, assuming BASICs would INT() it
  int i = floor(d);
  
  // type prunning because signed shift is implementation-defined
  unsigned u = *(unsigned *)&i;
  for (int bit = 32; bit > 0; bit >>= 1)
    strcat(str, ((u & bit) == bit) ? "1" : "0");
  
  return str;
}

/* for oct and hex, we can just use the formatters
 */
static char* number_to_oct_string(const double d)
{
  static char str[33];
  int i = floor(d);
  sprintf(str, "%o", i);
  return str;
}
static char* number_to_hex_string(const double d)
{
  static char str[33];
  int i = floor(d);
  sprintf(str, "%X", i);
  return str;
}

/* number of jiffies since program start (or reset) 1/60th in Commodore/Atari format */
static int elapsed_jiffies(void) {
	struct timeval current_time, elapsed_time, reset_delta;
	
	// get the delta between the original start time and the reset time (likely zero)
	timersub(&reset_time, &start_time, &reset_delta);
	
	// then add that to the current time (seconds only, the format has no jiffies)
	gettimeofday(&current_time, NULL);
	timersub(&current_time, &start_time, &elapsed_time);

	// adjust for any seconds in the reset
	elapsed_time.tv_sec += reset_delta.tv_sec;
	
	// convert to jiffies
	long jiffies = elapsed_time.tv_sec * 60;
	jiffies += (int)(elapsed_time.tv_usec / 1000000 * 60);
	
	// the result has to be clamped to 5183999 (=24*60^3 -1) to match MS BASIC
	// we'll mod the number to prevent an overflow in BASIC, but given the run
	// times this should never occur
	jiffies %= 5183999;
	
	return (int)jiffies;
}

/* recursively evaluates an expression and returns a value_t with the result */
static value_t evaluate_expression(expression_t *expression)
{
  value_t result;
  value_t parameters[3];
  
  switch (expression->type) {
      // for number and string constants, simply copy the value and return it
    case number:
      result.type = NUMBER;
      result.number = expression->parms.number;
      break;
    case string:
      result.type = STRING;
      result.string = expression->parms.string;
      break;
      
      // variables are also easy, just copy over their value from storage
    case variable:
    {
      int type = 0;
      either_t *p = variable_value(expression->parms.variable, &type);
      result.type = type;
			
			// user functions will call this method while being set up and at that time the
			// values are not valid, so...
			if (type == STRING) {
				if (p)
					result.string = p->string;
				else
					result.string = "";
			}
			else {
				if (p)
					result.number = p->number;
				else
					result.string = 0;
			}
    }
      break;
      
      // user functions are not so simple, because the variable references
      // in the original definition have to be mapped onto the parameters
      // being passed in here. So this code looks at the original definition
      // to get the list of variable names, caches those values on a stack,
      // recalculates those variables based on the inputs to the function call,
      // runs the calculation using those variables, and then pops the original
      // values back off the stack.
    case fn:
    {
      // assume this is numeric for the moment
      result.type = NUMBER;
      result.number = 0;
      // get the original definition or error out if we can't find it
      char *func_name = expression->parms.variable->name;
			function_storage_t *original_definition;
			original_definition = lst_data_with_key(interpreter_state.functions, func_name);
      if (original_definition == NULL) {
        char buffer[80];
        sprintf(buffer, "User-defined function '%s' is being called but has not been defined", func_name);
        basic_error(buffer);
        result.type = NUMBER;
        result.number = 0;
        break;
      }
      // if we found the function, check that it has the same number of parameters as this function call
      if (lst_length(original_definition->parameters) != lst_length(expression->parms.variable->subscripts)) {
        basic_error("User-defined function '%s' is being called with the wrong number of parameters");
        break;
      }

      // for each parameter name in the original function call, copy the current value
      // of any global version of that variable's value onto a temporary stack...
			list_t *stack = NULL;
      variable_storage_t *storage;
      either_t *stored_val;
      expression_t *original_parameter = original_definition->parameters->data; // pre-flight for the first time through
      int type = 0;
      for (list_t *param = expression->parms.variable->subscripts; param != NULL; param = lst_next(param)) {
        // retrieve the original value
        stored_val = variable_value(original_parameter->parms.variable, &type);

        // make a slot and push the value onto the stack
        storage = calloc(1, sizeof(*storage));
        storage->type = type;
        storage->value = calloc(1, sizeof(either_t));
          if (type == STRING)
            storage->value->string = stored_val->string;
          else
            storage->value->number = stored_val->number;
				stack = lst_insert_with_key_sorted(stack, storage, original_parameter->parms.variable->name);
        
        // move to the next item in the original parameter list, if there's any left
        if (original_definition->parameters->next != NULL)
          original_parameter = lst_next(original_definition->parameters)->data;
      }
      
      // now loop over the list of inputs, calculate them, and update the global variable
      value_t updated_val;
      for (list_t *param = expression->parms.variable->subscripts; param != NULL; param = lst_next(param)) {
        // calculate the value for the parameter expression
        updated_val = evaluate_expression(param->data);
        
        // find and update the global value
        stored_val = variable_value(original_parameter->parms.variable, &type);
        if (updated_val.type == type) {
          if (type == STRING)
            stored_val->string = updated_val.string;
          else
            stored_val->number = updated_val.number;
        } else {
          // if the type we stored last time is different than this time...
          basic_error("Type mismatch in user-defined function call");
          break;
        }
        
        // move to the next parameter
        if (original_definition->parameters->next != NULL)
          original_parameter = lst_next(original_definition->parameters)->data;
      }
      
      // with the global values updated, we can calculate our expression
      expression_t *p = NULL;
      p = function_expression(expression->parms.variable, p);
      if (p == NULL) {
        char buffer[80];
        sprintf(buffer, "User-defined function '%s' is being called but has not been defined", expression->parms.variable->name);
        basic_error(buffer);
      } else {
        result = evaluate_expression(p);
      }
      
      // and then pop the values back off the stack into the globals
      variable_storage_t *temp_val;
      original_parameter = original_definition->parameters->data; // pre-flight for the first time through
      for (list_t *param = expression->parms.variable->subscripts; param != NULL; param = lst_next(param)) {
        // retrieve the original name and value
        either_t *global_val = variable_value(original_parameter->parms.variable, &type);
        
        // find the original value in the stack
				temp_val = lst_data_with_key(stack, original_parameter->parms.variable->name);
        
        // copy the value back
        if (type == STRING)
          global_val->string = temp_val->value->string;
        else
          global_val->number = temp_val->value->number;
        
        // kill the stack entry
				stack = lst_remove_node_with_key(stack, original_parameter->parms.variable->name);
        free(temp_val);
        
        // move to the next parameter
        if (original_definition->parameters->next != NULL)
          original_parameter = lst_next(original_definition->parameters)->data;
      }
    }
      break;
      
      // and now for the fun bit, the operators and function list...
    case op:
      // build a list of values for each of the parameters by recursing
      // on them until they return a value
      for (int i = 0; i < expression->parms.op.arity; i++)
        parameters[i] = evaluate_expression(expression->parms.op.p[i]);
      
      // now calculate the results based on those values
      if (expression->parms.op.arity == 0) {
        result.type = NUMBER;

        switch (expression->parms.op.opcode) {
          case FRE:
            result.number = 0; // always return zero
            break;
          case PI:
            result.number = M_PI;
            break;
            
          case RND:
          {
            // if the value is negative, perform a randomize with that value
            if (parameters[0].number < 0.0) {
              srand(parameters[0].number);
              // prime the RNG, see notes in main loop
              (void)rand();
              (void)rand();
            }
            
            // get a value between 0..<1
            result.number = ((double)rand() / (double)RAND_MAX); // don't forget the cast!
            
            // and if the parameter > 1 then multiply it and floor to get 0..x
            if (parameters[0].number >= 1.0) {
              result.number = floor(result.number * floor(parameters[0].number));
            }
          }
            break;
						
						// TIME is the number of jiffies since the last restart, always 1/60 even on PAL.
						// In our code, we treat the start of the program as the restart time. This can
						// be changed by setting the value of TIME$ (which is really weird if you think
						// about it, why not set TIME?) so we keep track of that value in reset_ticks
						// and modify the value if it's not zero
					case TIME:
					{
						result.type = NUMBER;
						result.number = elapsed_jiffies();
					}
						break;
						
						// returns the number of seconds since restart in HMS format
						// this is the case where TIME$ appears on its own in a function-like call,
						// the other syntax is TIME=value, which is handled as a statement, not a function
					case TIME_STR:
					{
						result.type = STRING;
						
						int elapsed_secs = (int)(elapsed_jiffies() / 60);
						int h = (elapsed_secs / 3600);
						int m = (elapsed_secs - (3600 * h)) / 60;
						int s = (elapsed_secs - (3600 * h) - (m * 60));
						
						char buff[7];
						sprintf(buff, "%02d%02d%02d", h, m, s);
						result.string = str_new(buff);
					}
						break;

          case INKEY:
          {
            // INKEY returns a string containing either nothing or the character
            // currently being pressed. it relies on the terminal settings having
            // buffering turned of when this code is entered.
            char buff[2];
            int c = getkey(STDIN_FILENO);
            
            if (c > 0) {
              buff[0] = (char)c;
              buff[1] = '\0';
            } else {
              buff[0] = '\0';
            }
            result.type = STRING;
            result.string = str_new(buff);
          }
            break;

					default:
						basic_error("Unhandled arity-0 function");
        }
      }
      else if (expression->parms.op.arity == 1) {
        // most of the following functions return numbers, so default to that
        result.type = NUMBER;
        
        // get the first parameter, in this case, the only one
        double a = parameters[0].number;
        
        switch (expression->parms.op.opcode) {
          case '-':
            result.number = -a;
            break;
          case NOT:
            result.number = ~(int)a;
            break;
          case ABS:
            result.number = fabs(a);
            break;
          case ATN:
            result.number = atan(a);
            break;
          case ACS:
            result.number = acos(a);
            break;
          case ASN:
            result.number = asin(a);
            break;
          case CHR:
          {
            char c[2];
            c[0] = (char)a;
            c[1] = '\0';
            result.type = STRING;
            result.string = str_new(c);
          }
            break;
          case CLOG:
            result.number = log10(a);
            break;
          case EXP:
            result.number = exp(a);
            break;
          case LEN: // this is the only arity-1 function that takes a string parameter
            // the string may never have been assigned, so...
            if (parameters[0].string == NULL)
              result.number = 0;
            else
              result.number = strlen(parameters[0].string);
            break;
          case STR:
            result.type = STRING;
            result.string = str_new(number_to_string(a));
            break;
          case LOG:
            result.number = log(a);
            break;
          case SIN:
            result.number = sin(a);
            break;
          case SINH:
            result.number = sinh(a);
            break;
          case COS:
            result.number = cos(a);
            break;
          case COSH:
            result.number = cosh(a);
            break;
          case FIX:
            result.number = trunc(a);
            break;
          case INT:
            result.number = floor(a);
            break;
					case FRAC:
						result.number = a - trunc(a);
						break;
          case ROUND:
            result.number = round(a); // this is the 1-arity case
            break;
         case SQR:
            result.number = sqrt(a);
            break;
          case SGN:
            // early MS variants return 1 for 0, this implements the newer version where 0 returns 0
            if (a < 0)
              result.number = -1;
            else if (a == 0)
              result.number = 0;
            else
              result.number = 1;
            break;
          case TAN:
            result.number = tan(a);
            break;
          case TANH:
            result.number = tanh(a);
            break;
          case VAL:
            result.number = atof(parameters[0].string);
            break;
            
          case PEEK:
            // always return zero
            result.number = 0;
            break;
          case POS:
            // this is the arity-1 version, which is a dummy expression
            // the arity-2 and -3 versions are aliases for INSTR
            result.number = (double)interpreter_state.cursor_column; //FIXME: should this be +1?
            break;
          case TAB:
            // MS basics do nothing if the current cursor position is past the number being passed in,
            // otherwise it adds spaces to move the cursor to that column number. ANSI will insert a
            // CR and go to that column of the next line. ANSI columns start at 1, MS at 0.
            // note that in "real" basic this is a psuedo-function that simply moves the cursor
            //   and doesn't return anything, but here it works by returning a string
            result.type = STRING;
            result.string = str_new("");
            int tabs = (int)parameters[0].number;
            if (ansi_tab_behaviour)
              tabs++;
            if (tabs > interpreter_state.cursor_column) {
              for (int i = interpreter_state.cursor_column; i <= tabs - 1; i++) {
                str_append(result.string, " ");
              }
            } else {
              if (ansi_tab_behaviour) {
                str_append(result.string, "\n");
                for (int i = 0; i <= tabs - 1; i++) {
                  str_append(result.string, " ");
                }
              }
            }
            break;
          case SPC:
            // SPC adds the indicated number of spaces to the output
						// NOTE: this also handles SPACE$, which is a little different in most BASICs because
						//       SPC would normally not return anything, it simply writes the spaces directly
						//       to the outuput. Since we're handling all of this with a string, SPC works
						//       for SPACE$ too
            result.type = STRING;
            result.string = str_new("");
            for (int i = 0; i <= parameters[0].number - 1; i++) {
              str_append(result.string, " ");
            }
            break;
          case LIN:
            // from HP, inserts a number of CR's - not like IB's VTAB which can move up as well
            result.type = STRING;
            result.string = str_new("");
            int lines = (int)parameters[0].number;
            for (int i = 0; i <= lines - 1; i++) {
              str_append(result.string, "\n");
            }
            break;
            
						// these are out of order to keep them closer to the string functions below
					case LCASE:
					{
						result.type = STRING;
						result.string = str_new(str_tolower(parameters[0].string));
					}
						break;
					case UCASE:
					{
						result.type = STRING;
						result.string = str_new(str_toupper(parameters[0].string));
					}
						break;
            
            // clustered these for clarity
          case BIN:
          {
            result.number = (double)strtoul(parameters[0].string, NULL, 2);
          }
            break;
          case OCT:
          {
            result.number = (double)strtoul(parameters[0].string, NULL, 8);
          }
            break;
          case HEX:
          {
            result.number = (double)strtoul(parameters[0].string, NULL, 16);
          }
            break;

          case BINSTR:
          {
            result.type = STRING;
            result.string = str_new(number_to_bin_string(parameters[0].number));
          }
            break;
          case OCTSTR:
          {
            result.type = STRING;
            result.string = str_new(number_to_oct_string(parameters[0].number));
          }
            break;
          case HEXSTR:
          {
            result.type = STRING;
            result.string = str_new(number_to_hex_string(parameters[0].number));
          }
            break;
            
            // 1-arity versions of UBOUND and LBOUND
          case UBOUND:
          {
            result.type = NUMBER;

            // the 1-arity version is just a variable
            variable_reference_t *exp = expression->parms.op.p[0]->parms.variable;

            // like CHANGE and CONVERT, you do not pass in the ()'s here, so the name has to be munged
            char *array_storage_name = str_new(exp->name);
            str_append(array_storage_name, "("); // we are assuming it is missing, don't have to check type here
            variable_storage_t *array_store = lst_data_with_key(interpreter_state.variable_values, array_storage_name);
            free(array_storage_name);

            // and if it does, get the first value
            if (lst_length(array_store->actual_dimensions) > 0)
              result.number = (double)POINTER_TO_INT(array_store->actual_dimensions->data);
            else if (lst_length(array_store->dimed_dimensions) > 0)
              result.number = (double)POINTER_TO_INT(array_store->dimed_dimensions->data);
            else {
              basic_error("UBOUND called on non-array variable");
              result.number = 0;
            }
          }
            break;
            
            // and this one is really easy...
          case LBOUND:
            result.number = (double)array_base;
            break;
												
          default:
            basic_error("Unhandled arity-1 function");
        } //switch
      } //arity = 1
      
      // now the functions that take two parameters
      else if (expression->parms.op.arity == 2) {
        // cache the parameters
        double a = parameters[0].number;
        double b = parameters[1].number;
        result.type = NUMBER;
        
        switch (expression->parms.op.opcode) {
          case '+':
            if (parameters[0].type == STRING && parameters[1].type == STRING) {
              result.type = STRING;
              result.string = str_new(parameters[0].string);
              result.string = strcat(result.string, parameters[1].string);

              //result.string = str_new(str_append(parameters[0].string, parameters[1].string));
            }
            else if (parameters[0].type >= NUMBER && parameters[1].type >= NUMBER)
              result = double_to_value(a + b);
            else {
              result.number = 0;
              basic_error("Type mismatch, string and number in addition");
            }
            break;
          case '-':
            result = double_to_value(a - b);
            break;
          case '&': // ANSI concat
            if (parameters[0].type == STRING && parameters[1].type == STRING) {
              result.type = STRING;
              result.string = str_new(parameters[0].string);
              result.string = str_append(result.string, parameters[1].string);
            } else {
              result.string = str_new("");
              basic_error("Type mismatch, non-string values in concatenation");
            }
            break;
          case '*':
            result = double_to_value(a * b);
            break;
          case '/':
            if (b == 0)
              basic_error("Division by zero");
            result = double_to_value(a / b);
            break;
          case '^':
            result = double_to_value(pow(a, b));
            break;
          case MOD:
            result = double_to_value((int)floor(a) % (int)floor(b));
            break;
          case DIV:
            result = double_to_value((int)floor(a) / (int)floor(b));
            break;
          case '=':
            if (parameters[0].type >= NUMBER)
              result = double_to_value(-(a == b));
            else
              result = double_to_value(-!strcmp(parameters[0].string, parameters[1].string));
            break;
          case '<':
						if (parameters[0].type >= NUMBER)
							result = double_to_value(-(a < b));
						else
							result = double_to_value(-!strcmp(parameters[0].string, parameters[1].string));
						break;
          case '>':
						if (parameters[0].type >= NUMBER)
							result = double_to_value(-(a > b));
						else
							result = double_to_value(strcmp(parameters[0].string, parameters[1].string) > 0 ? -1 : 0);
						break;
          case CMP_LE:
						if (parameters[0].type >= NUMBER)
							result = double_to_value(-(a <= b));
						else
							result = double_to_value(strcmp(parameters[0].string, parameters[1].string) < 0 ? -1 : 0);
						break;
          case CMP_GE:
						if (parameters[0].type >= NUMBER)
							result = double_to_value(-(a >= b));
						else
							result = double_to_value(strcmp(parameters[0].string, parameters[1].string) >= 0 ? -1 : 0);
						break;
          case CMP_NE:
          case CMP_HASH:
						if (parameters[0].type >= NUMBER)
							result = double_to_value(-(a != b));
						else
							result = double_to_value(strcmp(parameters[0].string, parameters[1].string) != 0 ? -1 : 0);
						break;
          case AND:
            result = double_to_value((int)a & (int)b);
            break;
          case OR:
            result = double_to_value((int)a | (int)b);
            break;
          case XOR:
            result = double_to_value((int)a ^ (int)b);
            break;
          case ROUND: { // this is the 2-arity case
            double t = a * pow(10, b);
            t = round(t);
            t = t / pow(10, b);
            result.type = NUMBER;
            result.number = t;
          }
            break;

            // NOTE: the strings in BASIC start on index 1, so we have to adjust that here for C
            //   so the starting-point parameters need to be shifted back one
          case LEFT:
            result.type = STRING;
          {
            size_t len = strlen(parameters[0].string);
            result.string = str_new(parameters[0].string);
            str_truncate(result.string, len - b);
          }
            break;
          case RIGHT:
            result.type = STRING;
          {
            size_t len = strlen(parameters[0].string);
            result.string = str_new(parameters[0].string);
            str_fruncate(result.string, len - b);
          }
            break;
          case MID: // this is the two-parameter version, three follows
            // this version returns the right side of the string starting at b-1
            result.type = STRING;
          {
            size_t len = strlen(parameters[0].string);
            result.string = str_new(parameters[0].string);
            str_erase(result.string, b - 1, len - b + 1);
          }
            break;
					case STRNG:
						// makes N copies of the given string or ASCII char
						result.type = STRING;
						result.string = str_new("");
            
            // the length is in the first parameter
            int len = parameters[0].number;
            
            // the second parameter can be a string or an ASCII value
						char *temp;
						if (parameters[1].type == STRING)
							temp = parameters[1].string;
						else {
              char asc[2] = {0};
							asc[0] = (char)parameters[1].number;
							temp = str_new((char *)&asc);
						}
						
						for (int i = 0; i <= len - 1; i++) {
							str_append(result.string, temp);
						}
						break;
            
          case INSTR:
          case POS:
            // this is the arity-2 version, both parameters must be strings
            result.type = NUMBER;
            result.number = 0;

            // check that this is an INSTR, not a mis-parsed POS
            if (parameters[0].type > STRING || parameters[1].type > STRING) {
              basic_error("INSTR/INDEX/POS called with non-string inputs");
              break;
            }

            // the following are based on the rules for GW-BASIC, see:
            // https://hwiegman.home.xs4all.nl/gw-man/INSTR.html
            if (parameters[0].string == NULL || strlen(parameters[0].string) == 0)
              result.number = 0;
            else if (parameters[1].string == NULL || strlen(parameters[1].string) == 0)
              result.number = 1; // if the pattern is null, it matches immediately
            else {
              char *src = parameters[0].string;
              char *loc = strstr(parameters[0].string, parameters[1].string);
              if (loc == NULL)
                result.number = 0;
              else
                result.number = loc - src + 1;
            }
            break;

            // 2-arity versions of UBOUND and LBOUND, which differ from the
            // 1-arity versions in that they have to traverse the list to get
            // the right axis
          case UBOUND:
          {
            result.type = NUMBER;
            
            variable_reference_t *exp = expression->parms.op.p[0]->parms.variable;
            int axis = parameters[1].number;
            
            // munge the name
            char *array_storage_name = str_new(exp->name);
            str_append(array_storage_name, "(");
            variable_storage_t *array_store = lst_data_with_key(interpreter_state.variable_values, array_storage_name);
            free(array_storage_name);
            
            // so first, let's just check the bounds now, to simplify the following
            // remember: basic is 1-based!
            if (lst_length(array_store->actual_dimensions) < axis - 1 && lst_length(array_store->dimed_dimensions) < axis - 1) {
              basic_error("UBOUND called with index greater than variable dimensions");
              result.number = 0.0;
              break;
            }
            
            // the index is OK, get that dimension and return it
            list_t *dim;
            if (lst_length(array_store->actual_dimensions) <= axis) {
              dim = lst_first_node(array_store->actual_dimensions);
            } else {
              dim = lst_first_node(array_store->dimed_dimensions);
            }
            for (int i = 1; i < axis; i++)
              dim = lst_next(dim);
            if (dim != NULL && dim->data != NULL)
              result.number = (double)POINTER_TO_INT(dim->data);
            else
              result.number = 0.0;
          }
            break;
            
            // and this one is still really easy
          case LBOUND:
            result.number = (double)array_base;
            break;

          default:
            result.number = 0;
            basic_error("Unhandled arity-2 function");
            break;
        } //switch
      } //arity = 2
      
      // and finally, arity=3
      else if (expression->parms.op.arity == 3)  {
        
        switch (expression->parms.op.opcode) {
            
          case INSTR: // this is the arity-3 version
          case POS:
            result.type = NUMBER;
            result.number = 0;

            // check for validity and parse out the parameters
            int start;
            char *src, *pat;
            if (parameters[0].type > STRING) {
              if (parameters[1].type > STRING || parameters[2].type > STRING) {
                basic_error("INSTR/INDEX/POS called with non-string inputs");
                break;
              }
              start = parameters[0].number;
              src = parameters[1].string + start;
              pat = parameters[2].string;
            }
            // and one where its at the end
            else {
              if (parameters[0].type > STRING || parameters[1].type > STRING) {
                basic_error("INSTR/INDEX/POS called with non-string inputs");
                break;
              }
              start = parameters[2].number;
              src = parameters[0].string + start;
              pat = parameters[1].string;
            }
              
            // the following are based on the rules for GW-BASIC, see:
            // https://hwiegman.home.xs4all.nl/gw-man/INSTR.html
            if (src == NULL || strlen(src) == 0)
              result.number = 0;
            else if (pat == NULL || strlen(pat) == 0)
              result.number = start; // if the pattern is null, it matches immediately, which in this case is start
            else if (start > strlen(src))
              result.number = 0;
            else {
              char *loc = strstr(src, pat);
              if (loc == NULL)
                result.number = 0;
              else
                result.number = loc - src + 1;
            }
            break;

          case MID:
					case SEG:
					case SUBSTR:
          {
            double b = parameters[1].number;
            double c = parameters[2].number; // yeah, these could be ints

            result.type = STRING;
            result.string = str_new(parameters[0].string);
						
						// SEG is based on positions, not lengths, so adjust parameter c
						if (expression->parms.op.opcode == SEG)
							c = c - b + 1;
						
            str_erase(result.string, b - 1, c);
          }
            break;
                                 
          default:
            result.number = 0;
            basic_error("Unhandled arity-3 function");
            break;
        } // switch
      } //arity = 3
      
      // anything we didn't handle above...
      else {
        result.number = 0;
        break;
      }
  }
  return result;
}

/* handles the PRINT and PRINT USING statements, which can get complex */
static void print_expression(expression_t *e, const char *format)
{
  // get the value of the expression for this item
  value_t v = evaluate_expression(e);
	
	// if the format string is empty, NULL it
	if (format != NULL && strlen(format) == 0)
		format = NULL;
  
  // if there is a USING string, build a c-style format string from it
  if (format != NULL) {
    char copy[MAXSTRING];
    char *hash;
    int width = 0, prec = 0;
    
    // TODO: this doesn't handle string formatters, see GW-BASIC manual
    strcpy(copy, format);
    // look for any hash characters in front and behind a period
    hash = strchr(copy, '#');
    if (hash) {
      char *pc = hash;
      while (*pc == '#') {
        width++;
        pc++;
      }
      while (*pc == '.') {
        width++;
        pc++;
      }
      while (*pc == '#') {
        prec++;
        width++;
        pc++;
      }
      sprintf(hash, "%%*.*f");  // replace ##.## with % spec
      strcat(hash, pc);         // append the rest of string
    }
    // and now print it out using that format
    switch (v.type) {
      case NUMBER:
        interpreter_state.cursor_column += printf(copy, width, prec, v.number);
        break;
      case STRING:
        interpreter_state.cursor_column += printf(copy, width, prec, str_escape(v.string));
        break;
    }
  }
  // there was no USING format, so use a default formatter instead,
  // potentially limited to the fieldwidth if its tabular
  else {
    switch (v.type) {
      case NUMBER:
      {
        // for some reason, PRINT adds a space at the end of numbers
        char* a = number_to_string(v.number);
        interpreter_state.cursor_column += printf("%s ", a); // note the trailing space
      }
        break;
      case STRING:
        interpreter_state.cursor_column += printf("%-s", v.string);
        break;
    }
  }
}

/* given a statement, this returns the line number it's part of */
/* NOTE: this is likely expensive, because is uses the index lookup
				methods in list_t, which loop. So only use it when required!
 */
static int line_for_statement(const list_t *statement)
{
  // get a pointer to the program from the first line
  list_t *program = interpreter_state.lines[interpreter_state.first_line];
  
  // get the index of this statement in that list
  int target_index = lst_index_of_data(program, statement->data);
  
  // loop forward through the program until we find a line who's
  // first statement is higher than that index. That means we must
  // be on the previous line
  int this_index, previous_line = interpreter_state.first_line;
  for (int i = interpreter_state.first_line; i < MAXLINE; i++) {
    // skip empty lines
    if (interpreter_state.lines[i] == NULL) continue;
    
    // get the index of the first statement on that line
    this_index = lst_index_of_data(program, interpreter_state.lines[i]->data);
    
    // now see if we're in this line or the previous one
    if (this_index == target_index) return i;
    if (this_index > target_index) return previous_line;
    
    // otherwise keep looking
    previous_line = i;
  }
  // didn't find it
  return -1;
}

/* curries line_for_statement to return the current line */
static int current_line(void)
{
  return line_for_statement(interpreter_state.current_statement);
}

/* returns a pointer to the named line or returns an error if it's not found */
static list_t *find_line(int linenumber)
{
  char buffer[50];
  
  // negative numbers are not allowed
  if (linenumber < 0) {
    sprintf(buffer, "Negative target line %i in branch", linenumber);
    basic_error(buffer);
    return NULL;
  }
  
  // apparently some BASICs allow you to branch to a non-existant line and it will
  // go to the next-highest. this is definitely not what MS does, nor ANSI apparently,
  // but if this does come up we can use this flag on the command line
  if (goto_next_highest) {
    while ((linenumber < MAXLINE) && (interpreter_state.lines[linenumber] == NULL))
      linenumber++;
    
    // if we fell off the end, report an error
    if (linenumber == MAXLINE) {
      basic_error("Undefined line in branch, beyond highest line number");
      return NULL;
    }
  } else {
    // in MS-like BASICs, any null target line returns an error
    if (interpreter_state.lines[linenumber] == NULL) {
      sprintf(buffer, "Undefined target line %i in branch", linenumber);
      basic_error(buffer);
      return NULL;
    }
  }
  
  // otherwise we did find a line, so return it
  return interpreter_state.lines[linenumber];
}

/* returns the number of (non-empty) lines between two lines.
 used in the statistics to calculate how far a jump is */
// NOTE: not currently used
//static int lines_between(int first_line, int second_line)
//{
//    // may as well try this just in case...
//    if (first_line == second_line)
//        return 0;
//    // otherwise, simply count the non-empty lines between the two
//    int distance = 0;
//    int first = (first_line < second_line) ? first_line : second_line;
//    int last = (first_line >= second_line) ? second_line : first_line;
//    for(int i = first; i <= last; i++) {
//        if (interpreter_state.lines[i]) distance++;
//    }
//    return distance;
//}

/* performs a single statement */
static void perform_statement(list_t *statement_entry)
{
  // now process this statement
  statement_t *statement = statement_entry->data;
  if (statement) {
    switch (statement->type) {
			case BASE:
				if (statement->parms.generic_parameter != NULL) {
					value_t baseval;
					baseval = evaluate_expression(statement->parms.generic_parameter);
					if (baseval.number == 0 || baseval.number == 1)
						array_base = (int)baseval.number;
					else {
						char buffer[80];
						sprintf(buffer, "OPTION BASE with invalid parameter %g", baseval.number);
						basic_error(buffer);
					}
				} else {
					basic_error("OPTION BASE with no parameter");
				}
				break;

      case BYE:
        // unlike END, this exits BASIC entirely
        exit(EXIT_SUCCESS);
        break;
        
      case CALL:
        // do nothing
        break;

			case CHANGE:
			case CONVERT:
				// converts a string into a numeric array of ASCII values or vice versa
				// this code assumes it only works between two variables, and not expressions
				//
				// the complexity here is because we are stepping through elements in the array,
				// which is normally only possible using an index expression in the source code.
				// So here we have to duplicate a small portion of the code in variable_value to
				// get the right slot in the heap to insert into. This is somewhat eased by the
				// fact that the array has to be 1-dimensional so finding the right slot is easy.
				//
				// NOTE: In Dartmouth, A and A() are the same variable, and one can CHANGE A to A$
				//        this means we will have possible confusion between A and A(). However,
				//        every example of the CHANGE command has a DIM on the array, likely as
				//        the default value is 10 and that's too small in practice. So this code
				//        assumes the stored variable is A( and adds the paren where needed
			{
				either_t *first_val;
				variable_storage_t *array_store;
				int type1 = 0, type2 = 0;
				
				// get the types of the two variables
				first_val = variable_value(statement->parms.change.var1, &type1);
				variable_value(statement->parms.change.var2, &type2); // we only need the type here, the value is not used
				
				// make sure one is a string and the other is snumeric
				if (type1 == STRING && type2 != NUMBER)
					basic_error("Type mismatch in CHANGE, string to ?");
				else if (type1 == NUMBER && type2 != STRING)
					basic_error("Type mismatch in CHANGE, number to ?");
				
				// get the storage for the numeric value by adding the (
				char *array_storage_name = str_new((type1 == NUMBER) ? statement->parms.change.var1->name : statement->parms.change.var2->name);
				str_append(array_storage_name, "("); // we are assuming it is missing, don't have to check type here
				array_store = lst_data_with_key(interpreter_state.variable_values, array_storage_name);
				free(array_storage_name);

				// whichever one is a number has to be an array
				if (lst_length(array_store->actual_dimensions) == 0)
					basic_error("Type mismatch in CHANGE, numeric variable is not an array");
				
				// and that array has to be one-dimensional
				if (lst_length(array_store->actual_dimensions) > 1)
					basic_error("Type mismatch in CHANGE, numeric variable has multiple dimensions");
											
				// we are good to go...
				if (type1 == STRING) {
					// CONVERT STRING TO ARRAY OF ASCII
					
					// make sure the array is long enough for the string
					int string_length = (int)strlen(first_val->string);
					if (POINTER_TO_INT(array_store->actual_dimensions->data) < string_length)
						basic_error("Out of memory in CHANGE, numeric variable is too small to hold the string");
					
					// put the length in the first slot
					array_store->value[0].number = string_length;

					// now loop over the string and insert the values
					for (int i = 1; i <= string_length; i++) {
						array_store->value[i].number = (int)first_val->string[i - 1];
					}
					// and pad out the rest of the array with zeros to be safe
					for (int i = string_length + 1; i < POINTER_TO_INT(array_store->actual_dimensions->data); i++) {
						array_store->value[i].number = 0;
					}
				}
				else {
					// CONVERT ARRAY OF ASCII TO STRING
					variable_storage_t *string_store;

					// this one is a little easier, we can keep going until we see a zero
					char new_string[MAXSTRING];
          int i;
					for (i = 1; i <= POINTER_TO_INT(array_store->actual_dimensions->data) && array_store->value[i].number != 0; i++) {
						new_string[i - 1] = (char)array_store->value[i].number;
					}
          // and then set the last char to 0
          new_string[i] = 0;
					
					// delete any old value in the string and copy in the new one
					string_store = lst_data_with_key(interpreter_state.variable_values, statement->parms.change.var2->name);
					free(string_store->value->string);
					string_store->value->string = str_new(new_string);
				}
			}
				break;

      case CLEAR:
        // wipe out any variables and other program state, reset to un-run condition
      {
        delete_variables();
        clear_stack();
        reset_data_pointer(interpreter_state.first_line);
      }
        break;
        
      case CLS:
#if _WIN32
        clrscr();
#else
        printf("\e[2J\e[H"); // ANSI escapes, should work in most consoles
#endif
        break;
        
      case CMD:
        // redirects input/output to a different device. do nothing
        break;
        
      case DATA:
        // basically works like a REM, so just move on, all the logic is in the READ
        break;
        
      case DEF:
        // sets up a function in storage
        function_expression(statement->parms.def.signature, statement->parms.def.formula);
        break;

			case DEFDBL:
			case DEFINT:
			case DEFSNG:
			case DEFSTR:
				// don't do anything here, the variables will be set up already
				// NOTE: what to do about STR? it appears to allow A="HELLO"
				// we could test type changes here, like the bounds test in DIM
        break;
				
				case DIM:
        // the parser has already pulled out the variable names and set them up,
        // so here at runtime all we do is write down the original definition
        // so we can check bounds. In most cases the first instance of an array
        // will be the DIM, but we do this for the "invisible DIM" cases where
        // the parser set it to the minimum length of 10 and now we are actually
        // interpreting the real bounds. it also gives us a chance to look for
        // a REDIMing if the original_bounds are not null. This also checks for
        // the case where an array is DIMmed with a variable, in which case it
        // evaluated to zero and thus got the default 0..10 bounds. Here we can
        // re-build the array if the values are larger.
				{
					// there is a varlist of items in the parameters, loop over them
					for (list_t *variable = lst_first_node(statement->parms.dim); variable != NULL; variable = lst_next(variable)) {
						// get the name of this variable and munge it to an array if appropriate
						variable_reference_t *var = variable->data;
						
						// if this is a DIM on a string, and we're using slicing, then this is DIMming
						// the string's length, not making an array. In that case we want the original
						// variable name, not the munged version
						char *storage_name = str_new(var->name);
						if ((!string_slicing || variable_type(var) != STRING) && var->subscripts != NULL)
							str_append(storage_name, "(");
						
						// look up the storage, error if it's not found (should never happen)
						variable_storage_t *storage;
						storage = lst_data_with_key(interpreter_state.variable_values, storage_name);
						if (storage == NULL) {
							basic_error("DIM on unknown variable.");
							break;
						}
						
						// see if there already are dimensions, if so report a redim
            if (storage->dimed_dimensions != NULL) {
              basic_error("REDIM of already DIMmed variable.");
              break;
            }
						
						// loop over the dimensions, eval them, and insert
						// NOTE: we do NOT add a slot for 0 here, this is only for bounds checking
						value_t v;
						for (list_t *L = var->subscripts; L != NULL; L = lst_next(L)) {
							v = evaluate_expression(L->data);
							storage->dimed_dimensions = lst_append(storage->dimed_dimensions, INT_TO_POINTER(v.number));
						}
            
            // and all done with this
            free(storage_name);
            
            // and now call value again so that the dimensions are set up in storage
            int ignore = 0;
            variable_value(var, &ignore);
					}
				}
				break;
        
      case END:
        // set the instruction pointer to null so it exits below
        interpreter_state.next_statement = NULL;
        break;
        
      case EXIT:
        // when found in a sub, EXIT is essentially a RETURN, but in
        // a FOR loop it has to find and move past the NEXT
      {
        list_t *stack_node;
        stack_entry_t *stack_entry;
        
        // error if there is nothing there
        if (interpreter_state.runtime_stack  == NULL || lst_length(interpreter_state.runtime_stack) == 0) {
          basic_error("EXIT without FOR or GOSUB");
          break;
        }
        
        // get the last item on the stack
        stack_node = lst_last_node(interpreter_state.runtime_stack);
        stack_entry = stack_node->data;
        
        // for a sub, we simply remove the entry and go to that line
        if (stack_entry->type == gosub_entry) {
          interpreter_state.next_statement = stack_entry->gosub.returnpoint;
          interpreter_state.runtime_stack = lst_remove_node_with_data(interpreter_state.runtime_stack, stack_entry);
        }
        
        // for the FOR..NEXT case, we need to find the NEXT and move past it
        else {
          // pop the NEXT so it doesn't continue looping if it sees it
          interpreter_state.runtime_stack = lst_remove_node_with_data(interpreter_state.runtime_stack, stack_entry);

          // and now roll foward until we get to a corresponding NEXT statement in the code,
          // and then set the next statement to the one after that
          list_t *test_statement = interpreter_state.next_statement;
          while (test_statement != NULL) {
            if (((statement_t *)test_statement->data)->type == NEXT)
              break;
            else
              test_statement = lst_next(test_statement);
          }
          // see if the last thing we found was a NEXT
          if (test_statement != NULL && ((statement_t *)test_statement->data)->type == NEXT) {
            interpreter_state.next_statement = test_statement->next;
          }
        } // it's a FOR
      }
        break;
        
      case FOR:
      {
        stack_entry_t *new_for = calloc(1, sizeof(*new_for));
        interpreter_state.runtime_stack = lst_append(interpreter_state.runtime_stack, new_for);
        
        new_for->type = for_entry;
        new_for->_for.head = statement_entry; // unlike a gosub, we return to the front of the FOR
        new_for->_for.index_variable = statement->parms._for.variable;
        new_for->_for.begin = evaluate_expression(statement->parms._for.begin).number;
        new_for->_for.end = evaluate_expression(statement->parms._for.end).number;
        
        // the original gnbasic code did this, which is definitely non-standard and caused problems in SST
        // is this perhaps ANSI? UPDATE: nope, ANSI actually uses this as an example of a no-body loop
        //                        if (new_for->begin < new_for->end)
        //                            new_for->step = 1;
        //                        else
        //                            new_for->step = -1;
        if (statement->parms._for.step)
          new_for->_for.step = evaluate_expression(statement->parms._for.step).number;
        else
          new_for->_for.step = 1;
        
        // update the variable in storage to the starting value
        int type = 0;
        either_t *loop_value = variable_value(new_for->_for.index_variable, &type);
        loop_value->number = new_for->_for.begin;
      }
        break;
        
      case GOSUB:
      {
        stack_entry_t *new_sub = calloc(1, sizeof(*new_sub));
        interpreter_state.runtime_stack = lst_append(interpreter_state.runtime_stack, new_sub);

        new_sub->type = gosub_entry;
        new_sub->gosub.returnpoint = lst_next(statement_entry);
        // the GOSUB can take any expression, so we have to evaluate it (GOTO as well, but *not* THEN)
        interpreter_state.next_statement = find_line(evaluate_expression(statement->parms.gosub).number);
      }
        break;
        
      case GOTO:
      {
        interpreter_state.next_statement = find_line(evaluate_expression(statement->parms._goto).number);
      }
        break;
        
      case IF:
      {
        value_t cond = evaluate_expression(statement->parms._if.condition);
        // if only does something when the condition is true
        if (cond.number != 0) {
          // THEN might be an expression including a GOTO or an implicit GOTO
          if (statement->parms._if.then_expression) {
            // in gnbasic this was next = perform_statement, which meant it could only
            // perform a single statement after the IF, which is not the case in
						// MS. for this to work properly, the then_expression has to be a list
						// that is not connected to the next line, it has to end on a NULL.
            for (list_t *I = statement->parms._if.then_expression; I != NULL; I = lst_next(I)) {
              perform_statement(I);
            }
          } else {
            // if the THEN is not an expression, jump to that line
            interpreter_state.next_statement = find_line(statement->parms._if.then_linenumber);
          }
        }
      }
        break;
        
      case INPUT:
      {
        // INPUT can mix together prompts and variables, it doesn't
        // *have* to be a single prompt at the start, although that is
        // the typical convention. this code handles this possibility
        // by rolling over the expression list, doing a print if it's
        // not a variable, and a scan if it is
        //
        // NOTE: in C64 an empty input will exit without setting the
        //    value of the associated variable, leaving it what it
				//    was. you can see this in SST - for instance, if you
				//    simply press return on the computer command input it
				//    will run the last command again.
        
        // loop over the items in the variable/prompt list
        for (list_t *I = statement->parms.input; I != NULL; I = lst_next(I)) {
          either_t *value;
          int type = 0;
          
          printitem_t *ppi = I->data;
					if (ppi->expression == NULL) {
						// skip this one
					}
					else if (ppi->expression->type == variable) {
            char line[80];
            
            // if there is a previous item in the printlist, look at the separator
            // and suppress question mark prompt if it is a comma
            if (I->prev == NULL)
              printf("?");
            else {
              printitem_t *prev_item = I->prev->data;
              if (prev_item->separator != ',')
                printf("?");
            }
            
            // see if we can get some data, we should at least get a return
            fflush(stdout);
            if (fgets(line, sizeof(line), stdin) != line)
              exit(EXIT_FAILURE);
            
            // we got something, so null-terminate the string
            line[strlen(line) - 1] = '\0';
            
            // optionally convert to upper case
            if (upper_case) {
              char *c = line;
              while (*c) {
                *c = toupper((unsigned char) *c);
                c++;
              }
            }
            
            // find the storage for this variable, and assign the value
            value = variable_value(ppi->expression->parms.variable, &type);
            if (type >= NUMBER) {
              sscanf(line, "%lg", &value->number);
            } else {
              value->string = str_new(line);
            }
          }
          // if it's not a variable, it's some sort of prompt, so print it
          else {
            print_expression(ppi->expression, NULL);
          }
        }
      }
        break;
        
        // LABEL doesn't do anything at run time, everything has already
        // been set up at parse time
      case LABEL:
        break;

      case LET:
      {
        // this handles both the explicit and implicit LET
        either_t *stored_val;
        int type = 0;
        value_t exp_val;
        
        // get/make the storage entry for this variable
        stored_val = variable_value(statement->parms.let.variable, &type);
        
        // evaluate the expression
        exp_val = evaluate_expression(statement->parms.let.expression);
        
        // make sure we got the right type, and assign it if we did
        if (exp_val.type != type) {
          basic_error("Type mismatch in assignment");
          break;
        }
        
        // it was the right type, so...
        if (type > STRING) {
          // it's a number, cast it to the right underlying type
          switch (type) {
            case INTEGER:
              stored_val->number = floor(exp_val.number);   // MS BASIC does a floor, *not* a trunc
              break;
            default:
              stored_val->number = exp_val.number;          // which it likely is already, but just in case...
              break;
          }
          
        } else {
          // see if the variable being assigned to has a slice
          variable_storage_t *stored_var = variable_storage(statement->parms.let.variable);
          int slice_start, slice_end;
          if (slice_limits(statement->parms.let.variable, stored_var, &slice_start, &slice_end)) {
            // limit the length of the replacement to the shorter of the slice or the inserted string
            if (slice_end - slice_start < strlen(exp_val.string) - 1)
              slice_end = (int)strlen(exp_val.string) - slice_start;
            
            // copy everything over, except the trailing null
            for (int i = 0; i <= slice_end - slice_start; i++)
              stored_var->value->string[i + slice_start] = exp_val.string[i];
          } else {
            stored_val->string = exp_val.string;
          }
        }
      } //let
        break;
        
      case NEXT:
      {
        list_t *stack_node, *previous_node;
        stack_entry_t *stack_entry;
        
        // make sure there is a stack
        if (interpreter_state.runtime_stack  == NULL || lst_length(interpreter_state.runtime_stack) == 0) {
          basic_error("NEXT without FOR");
          break;
        }

        // get the most-recent FOR, which should be the last item on the stack.
        // unlike a gosub, there doesn't seem to be a case where the last item is
        // is a leftover RETURN, if one exited from a gosub then the RETURN should
        // have been removed one way or the other. It IS possible to exit from
        // a FOR inside a gosub, but this should have removed the for statements
        // as it exited. Nevertheless, better safe than sorry...
        stack_node = lst_last_node(interpreter_state.runtime_stack);
        while (stack_node != NULL && ((stack_entry_t *)stack_node->data)->type != for_entry) {
          previous_node = lst_previous(stack_node);
          lst_remove_node_with_data(interpreter_state.runtime_stack, stack_node);
          stack_node = previous_node;
        }
        
        // if that emptied the stack...
        if (stack_node == NULL) {
          basic_error("NEXT without FOR");
          break;
        }
        
        // we have a for
        stack_entry = stack_node->data;
				
				// see if the next has any variable names, that is, NEXT I vs. NEXT,
				// and if so, ensure the latest FOR on the stack is one of those variables
				if (lst_length(statement->parms.next) > 0) {
					bool foundIt = false;
					list_t *var = lst_first_node(statement->parms.next);
					for (int i = 0; i < lst_length(statement->parms.next); i++) {
						if (strcmp(stack_entry->_for.index_variable->name, ((variable_reference_t *)var->data)->name) == 0) {
							foundIt = true;
						}
						else {
							var = lst_next(statement->parms.next);
						}
					}
					if (!foundIt) {
						basic_error("NEXT with mismatched FOR");
						break;
					}
				}
				
				// do a STEP
        int type = 0;
				either_t *lv = variable_value(stack_entry->_for.index_variable, &type);
        lv->number += stack_entry->_for.step;
				
				// and see if we need to go back to the FOR or we're done and we continue on
        if (((stack_entry->_for.step < 0) && (lv->number >= stack_entry->_for.end)) ||
            ((stack_entry->_for.step > 0) && (lv->number <= stack_entry->_for.end))) {
          // we're not done, go back to the head of the loop
          interpreter_state.next_statement = lst_next(stack_entry->_for.head);
        } else {
          // we are done, remove this entry from the stack and just keep going
          interpreter_state.runtime_stack = lst_remove_node_with_data(interpreter_state.runtime_stack, stack_entry);
					free(stack_entry);
        }
      } // next
        break;
        
      case NEW:
        // it's not entirely clear what this should do INSIDE a program, but...
      {
        // wipe out any variables and functions and create new lists
        delete_variables();
        delete_functions();
        delete_lines();
				interpreter_state.next_statement = NULL; // stop execution, there's nothing left
      }
        break;
        
      case ON:
			case OF:
      {
        list_t *numslist;
        numslist = statement->parms.on.numbers;

        // eval, returning a double...
        value_t val = evaluate_expression(statement->parms.on.expression);
        
        // if the value is not a number...
        if (val.type == STRING)
          basic_error("Index value for ON is a string");

        // ON does an INT, and since a valid index is +ve, INT always rounds down...
        int n = (int)floor(val.number);
        /* C arrays are zero-indexed, not 1, so... */
        --n;
        
        // in ANSI (and MS as it turns out), if the index is <1 or >the number of items, an error is returned
        if (n < 0)
          basic_error("Index value for ON less than 1");
        
        // ... or if we're beyond the end of the list
        if (n > lst_length(numslist) && ansi_on_boundaries)
          basic_error("Index value for ON greater than list of line numbers");

        // otherwise, try to get the nth item
        expression_t *item = lst_data_at(numslist, n);
        if (item == NULL) {
            // an IF statement simply runs the next statement if the condition fails,
            // likewise, if the ON value points to an item that is not in the number
            // list, if simply falls off to the next statement
            break;
        }
        
        // we found the nth entry, so evaluate it
        value_t lineval;
        lineval = evaluate_expression(item);
        
        // turn it into a line number
        int linenum = (int)floor(lineval.number);
        
        // and then it's either GOTO or GOSUB...
        if (statement->parms.on.type == GOTO) {
          interpreter_state.next_statement = find_line(linenum);
        } else {
          stack_entry_t *new_sub = calloc(1, sizeof(*new_sub));
          new_sub->type = gosub_entry;
          new_sub->gosub.returnpoint = lst_next(statement_entry);
          interpreter_state.runtime_stack = lst_append(interpreter_state.runtime_stack, new_sub);
          interpreter_state.next_statement = find_line(linenum);
        }
      }
        break;
        
        // two different things here, if there are no paramters it pauses until
        // a key is hit, otherwise the parameter is the number of jiffies, which
        // we assume to be 1/6ths of a second
      case PAUSE:
      {
        if (statement->parms.generic_parameter == NULL) {
          // only pause if we're not reading from a file
          if (strcmp(input_file,"")) {
            getchar();
          }
        } else {
          value_t sleep_value = evaluate_expression(statement->parms.generic_parameter);
          sleep(sleep_value.number / 60.0);
        }
      }
        break;
        
      case POKE:
        // do nothing
        break;
        
      case POP:
        // see also EXIT
      {
        list_t *stack_node;
        
        // error if there is nothing there
        if (interpreter_state.runtime_stack  == NULL || lst_length(interpreter_state.runtime_stack) == 0) {
          basic_error("POP without FOR or GOSUB");
          break;
        }
        
        // get the last item
        stack_node = lst_last_node(interpreter_state.runtime_stack);
        
        // for a POP, we simply remove the entry
        if (stack_node != NULL) {
          lst_remove_node_with_data(interpreter_state.runtime_stack, stack_node);
        }
      }
        break;
        
      case PRINT:
      {
        printitem_t *pp;
				
				// see if the list has a formatter, and set up the format string or set it to default
				value_t format_string;
				format_string.type = STRING;
				if (statement->parms.print.format)
					format_string = evaluate_expression(statement->parms.print.format);
				else
					format_string.string = NULL;
				
        // now loop over the items in the print list
				for (list_t *I = statement->parms.print.item_list; I != NULL; I = lst_next(I)) {
					pp = I->data;
					
					// if this is a printsep, there will only be the separator and no expression
					// but the separator itself will be handled below, so for now we just need
					// to see if there is an expression to print
					if (pp->expression != NULL) {
						print_expression(pp->expression, format_string.string);
					}
					
					// for each item in the list, look at the separator, if there is one
					// and it's a comma, advance the cursor to the next tab column
					if (pp->separator == ',')
						//FIXME: this should wrap at 80 columns
						while (interpreter_state.cursor_column % tab_columns != 0) {
							printf(" ");
							interpreter_state.cursor_column++;
						}
				}
        
        // now get the last item in the list so we can see if it's a ; or ,
        if (lst_last_node(statement->parms.print.item_list))
          pp = (printitem_t *)(lst_last_node(statement->parms.print.item_list)->data);
        else
          pp = NULL;
        
				// if the last item is SPC or TAB, fake a trailing semi, which is the way PET does it
				if (pp != NULL && pp->expression != NULL && pp->expression->type == op)
					if (pp->expression->parms.op.opcode == SPC || pp->expression->parms.op.opcode == TAB)
						pp->separator = ';';
        
        // if there are no more items, or it's NOT a separator, do a CR
        if (pp == NULL || pp->separator == 0) {
          printf("\n");
          interpreter_state.cursor_column = 0; // and reset this!
        }
      }
        break;
        
      case RANDOMIZE:
      {
        // GW BASIC and Dartmouth work differently. In Dartmouth, RANDOMIZE with no
        // parameter is supposed to select a random seed, which is what happens here.
        // in GW, that should display a prompt asking for the value, which seems
        // odd. To get the Dartmouth behaviour in GW, one uses RANDOMIZE TIMER
        // which is even more odd.
        
        // see if there's a parameter, if not, seed time
        if (statement->parms.generic_parameter == NULL)
          srand((unsigned int)time(NULL));
        else {
          value_t seed_value = evaluate_expression(statement->parms.generic_parameter);
          srand(seed_value.number);
        }
				
				// prime the RNG, see notes in main loop
				(void)rand();
				(void)rand();
      }
        break;

      case READ:
      {
        list_t *variable_list;
        
        if (interpreter_state.current_data_statement == NULL) {
          basic_error("No more DATA for READ");
        }
        
        variable_list = statement->parms.read;
        while (variable_list) {
          either_t *variable_definition;
          int type = 0;
          value_t data_value;
          
          // look for the next valid DATA item
          if (interpreter_state.current_data_element == NULL) {
            interpreter_state.current_data_statement = lst_next(interpreter_state.current_data_statement);
            while (interpreter_state.current_data_statement != NULL) {
              if ((interpreter_state.current_data_statement->data != NULL) &&
                  (((statement_t *)(interpreter_state.current_data_statement->data))->type == DATA))
                break;
              interpreter_state.current_data_statement = lst_next(interpreter_state.current_data_statement);
            }
            interpreter_state.current_data_element = lst_first_node(((statement_t *)(interpreter_state.current_data_statement->data))->parms.data);
          }
          
          // eval the DATA element, which is what we'll ultimately return
          data_value = evaluate_expression(interpreter_state.current_data_element->data);
          
          // retrieve the variable from storage
          variable_definition = variable_value(variable_list->data, &type);
          
          // test the type, if the variable and data are the same type assign it, otherwise return an error
          if (data_value.type == type) {
            if (type == STRING)
              variable_definition->string = data_value.string;
            else
              variable_definition->number = data_value.number;
          } else {
            char buffer[80];
            sprintf(buffer, "Type mismatch in READ, reading a %s but got a %s",
                    (type == STRING) ? "string" : "number",
                    (type >= NUMBER) ? "number" : "string" );
            basic_error(buffer);
          }
          
          // move to the next variable from the READ and the next item in the DATA
          variable_list = lst_next(variable_list);
          interpreter_state.current_data_element = lst_next(interpreter_state.current_data_element);
        }
      }
        break;
        
      case REM:
      case QUOTEREM:
      case BANGREM:
        break;
        
      case RESTORE:
        // resets the DATA pointer
      {
        int linenum;
        if (statement->parms.generic_parameter != NULL)
          linenum = (int)evaluate_expression(statement->parms.generic_parameter).number;
        else
          linenum = interpreter_state.first_line;

        interpreter_state.current_data_statement = find_line(linenum);
        interpreter_state.current_data_element = NULL;
      }
        break;
        
      case RETURN:
      {
        list_t *stack_node, *previous_node;
        
        // check that we have something
				if (interpreter_state.runtime_stack == NULL || lst_length(interpreter_state.runtime_stack) == 0) {
					basic_error("RETURN without GOSUB");
					break;
				}
        
        // if we call a sub that has FORs, and then return from inside one,
        // there will be FOR entries on the stack above the return point.
        // we need to remove any non-GOSUB entries first
        stack_node = lst_last_node(interpreter_state.runtime_stack);
        while (stack_node != NULL && ((stack_entry_t *)stack_node->data)->type != gosub_entry) {
          previous_node = lst_previous(stack_node);
          lst_remove_node_with_data(interpreter_state.runtime_stack, stack_node);
          stack_node = previous_node;
        }
        
        // if that emptied the stack...
        if (stack_node == NULL) {
          basic_error("RETURN without GOSUB");
          break;
        }

        // set the next statement to the returnpoint
        interpreter_state.next_statement = ((stack_entry_t *)stack_node->data)->gosub.returnpoint;
        
        // and remove the RETURN
        interpreter_state.runtime_stack = lst_remove_node_with_data(interpreter_state.runtime_stack, stack_node->data);
      }
        break;
        
      case STOP:
      {
        if (statement->parms.generic_parameter != NULL) {
          value_t message = evaluate_expression(statement->parms.generic_parameter);
          printf("STOP: %s\n", message.string);
        } else {
          printf("STOPped at line: %d\n", current_line());
        }
        exit(EXIT_SUCCESS);
      }
        break;
				
        // this is Integer BASIC's TAB, which is a statement, not a function
      case TAB:
      {
        int tabs = 0;
        if (statement->parms.generic_parameter != NULL) {
          tabs = (int)evaluate_expression(statement->parms.generic_parameter).number;
          if (tabs > interpreter_state.cursor_column) {
            for (int i = interpreter_state.cursor_column; i <= tabs - 1; i++) {
              putchar(32);
            }
          } else {
            if (ansi_tab_behaviour) {
              for (int i = 0; i <= tabs - 1; i++) {
                putchar(32);
              }
            }
          }
        }
      }
        break;

				// this handles the weird-syntax case of TIME$=, which looks like a variable set but
				// is really a statement
			case TIME_STR:
			{
				if (statement->parms.generic_parameter != NULL) {
					// value is in HMS format, so make sure we got a strong
					value_t hms = evaluate_expression(statement->parms.generic_parameter);
					if (hms.type != STRING) {
						basic_error("TIME$ being set with non-string value");
						break;
					}
					// and that it's exactly six digits long
					if (strlen(hms.string) != 6) {
						basic_error("TIME$ being set with string of the wrong length");
						break;
					}
					// pull it apart into ints
					int h, m, s;
					char bit[2];

					memcpy(bit, &hms.string[0], 2);
					h = atoi(bit);
					if (h > 23)
						h = 23;
					if (h < 0)
						h = 0;

					memcpy(bit, &hms.string[2], 2);
					m = atoi(bit);
					if (m > 59)
						m = 59;
					if (m < 0)
						m = 0;

					memcpy(bit, &hms.string[4], 2);
					s = atoi(bit);
					if (s > 59)
						s = 59;
					if (s < 0)
						s = 0;

					// now convert that into jiffies offset from the start time
					// note theres no way to change the jiffies
					int delta = (h * 3600) + (m * 60) + s;
					reset_time.tv_sec = start_time.tv_sec + delta;
				}
			}
				break;

      case VARLIST:
        print_variables();
        break;
        
      default:
        printf("Unimplemented statement %d\n", statement->type);
				exit(EXIT_FAILURE);
    } //end switch
  }
}

/* variable tree walking methods */

/* cheater method for printing out all the variable names */
static void print_symbol(void *key, void *value, void *unused)
{
  printf("\n%s ", (char *)key);
}
/* ...and their values */
//static int print_value(void *key, void *value, void *unused)
//{
//	variable_value_t *storage;
//	storage = lst_data_with_key(interpreter_state.variable_values, key);
//
//  either_t *p = storage->value;
//  int type = storage->type;
//  if (type == STRING)
//    if (p->string == 0)
//      printf("\n%s: %s", (char *)key, "NULL");
//    else
//      printf("\n%s: %s", (char *)key, (char *)p->string);
//  else
//    printf("\n%s: %f", (char *)key, (double)p->number);
//  return FALSE;
//}
/* used for VARLIST in those versions of BASIC that support it */
static void print_variables(void) {
	lst_foreach(interpreter_state.variable_values, print_symbol, NULL);
  printf("\n\n");
}
/* used for CLEAR, NEW and similar instructions. */
static void delete_variables(void) {
	lst_free_everything(interpreter_state.variable_values);
	interpreter_state.variable_values = NULL;
}
static void delete_functions(void) {
	lst_free_everything(interpreter_state.functions);
	interpreter_state.functions = NULL;
}
static void delete_lines(void) {
  for(int i = MAXLINE - 1; i >= 0; i--) {
    if (interpreter_state.lines[i] != NULL) {
      lst_free(interpreter_state.lines[i]);
    }
  }
}
/* clear the runtime stack on CLEAR */
static void clear_stack(void) {
  lst_free(interpreter_state.runtime_stack);
}
/* reset the DATA pointer CLEAR */
static void reset_data_pointer(int line) {
  list_t *first_statement = interpreter_state.lines[interpreter_state.first_line];
  interpreter_state.current_statement = first_statement;          // the first statement
  interpreter_state.current_data_statement = first_statement;     // the DATA can point anywhere
}

/* set up empty trees to store variables and user functions as we find them */
void interpreter_setup(void)
{
	interpreter_state.variable_values = NULL;
	interpreter_state.functions = NULL;
}

/* labels are stored as variables, but variables don't get an actual
  value until they are encountered in the program, which is too late
  for a forward jump - which is often the purpose of a label. So now
  that the program is a single long string of statements, we check all
  of them to see if it is a label, and if so, call eval to set its
  value. The code is essentially identical to LET. This is called from
  post_setup, so it doesn't need to be public */
void interpreter_eval_labels(void)
{
  list_t *next_statement = interpreter_state.lines[interpreter_state.first_line];
  while (next_statement) {
    statement_t *ps = next_statement->data;
    if (ps && ps->type == LABEL) {
      
      // get/make the storage entry for this variable
      variable_storage_t *stored_val = variable_storage(ps->parms.label.variable);
      
      // and set it's number
      stored_val->value->number = (double)ps->parms.label.linenumber;
    }
    next_statement = lst_next(next_statement);
  }
}

/* after yacc has done it's magic, we form a program by pointing
 the ->next for each line to the head of the next non-empty line.
 that way we don't have to search through the line array for the
 next non-null entry during the run loop, we just keep stepping
 through the ->next until we fall off the end. this is how most
interpreters handled it anyway. */
void interpreter_post_parse(void)
{
  // look for the first entry in the lines array with a non-empty statement list
  int first_line = 0;
  while ((first_line < MAXLINE - 1) && (interpreter_state.lines[first_line] == NULL))
    first_line++;
  
  // that statement is going to be the head of the list when we're done
  list_t *first_statement = interpreter_state.lines[first_line];
  
  // now find the next non-null line and concat it to the first one, and repeat
  for (int i = first_line + 1; i < MAXLINE; i++) {
    if (interpreter_state.lines[i])
      first_statement = lst_concat(first_statement, interpreter_state.lines[i]);
  }
  
  // and set the resulting list back into the first line
  // NOTE: do we need to do this? isn't this already there?
  interpreter_state.lines[first_line] = first_statement;
  // and keep track of this for posterity
  interpreter_state.first_line = first_line;
  
  // a program runs from the first line, so...
  interpreter_state.current_statement = first_statement;
  
  // should be empty, but just in case...
  clear_stack();
  
  // reset the DATA pointer
  reset_data_pointer(first_line);
  
  // and find and cache all the labels
  interpreter_eval_labels();
}

/* the main loop for the program */
void interpreter_run(void)
{
  // the cursor starts in col 0
  interpreter_state.cursor_column = 0;

  // start the clocks
  start_ticks = clock();
	gettimeofday(&start_time, NULL);
	gettimeofday(&reset_time, NULL);
  
  // mark us as running
  interpreter_state.running_state = 1;
  
  // last line number we ran, used for tracing/stepping
  int last_line = interpreter_state.first_line;
  if (trace_lines)
    printf("[%i]\n", last_line);
  
  // very simple - perform_statement returns the next statement and the
  // main below set us up to point to the first one, so just call
  // that one function until you get a NULL
  while (interpreter_state.current_statement) {
    // get the next statement from the one we're about to run
    interpreter_state.next_statement = lst_next(interpreter_state.current_statement);

    // run the one we're on
    perform_statement(interpreter_state.current_statement);
    // and move to the next statement, which might have changed inside perform
    interpreter_state.current_statement = interpreter_state.next_statement;
    
    // trace, only on line changes
    if (trace_lines && interpreter_state.current_statement != NULL && last_line != current_line()) {
      last_line = current_line();
      printf("[%i]\n", last_line);
    }
  }
  
  // stop the clock and mark us as stopped
  end_ticks = clock();
  gettimeofday(&end_time, NULL);
  interpreter_state.running_state = 0;
}

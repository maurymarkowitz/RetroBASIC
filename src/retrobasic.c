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

#include <sys/time.h>

#include "retrobasic.h"
#include "parse.h"

/* here's the actual definition of the interpreter state which is extern in the header */
interpreterstate_t interpreter_state;

/* and the same for the various flags */
bool run_program = true;                 // default to running the program, not just parsing it
bool print_stats = false;                // do not print or write stats by default
bool write_stats = false;
int tab_columns = 10;                   // based on PET BASIC, which is a good enough target
bool trace_lines = false;
bool upper_case = false;                 // force INPUT to upper case
int array_base = 1;                     // lower bound of arrays, can be set to 0 with OPTION BASE
double random_seed = -1;                // reset with RANDOMIZE, if -1 then auto-seeds
bool string_slicing = false;             // are references like A$(1,1) referring to an array entry or doing slicing?
bool goto_next_highest = false;          // if a branch targets an non-existant line, should we go to the next highest?
bool ansi_on_boundaries = false;         // if the value for an ON statement <1 or >num entries, should it continue or error?
bool ansi_tab_behaviour = false;         // if a TAB < current column, ANSI inserts a CR, MS does not

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
  list_t *parameters;     // parameters, if any, as variable_t
  expression_t *formula;	// related formula
} function_storage_t;

/* forward declares */
static value_t evaluate_expression(expression_t *e);
static int line_for_statement(const list_t *s);
static int current_line(void);

static void print_variables(void);
static void delete_variables(void);
static void delete_functions(void);
static void delete_lines(void);

/* defitions of variables used by the static analyzer */
clock_t start_ticks = 0, end_ticks = 0;	// start and end ticks, for calculating CPU time
struct timeval start_time, end_time;    // start and end clock, for total run time
struct timeval reset_time;     					// if the user resets the time with TIME$, this replaces start_time

/************************************************************************/

static void basic_error(const char *message)
{
  fprintf(stderr, "%s at line %d\n", message, current_line());
}

/* Returns an either_t containing a string or a number for the underlying
   variable, along with its type in the out-parameter 'type'. If the
   variable has not been encountered before it will be created here. */
/* NOTE: this code also handles string slicing. it would be much preferrable
   to do that as a function call so it could overload the MID$-style functions
   but I could not figure out how to do that at runtime in the yacc code. */
either_t *variable_value(const variable_t *variable, int *type)
{
  variable_storage_t *storage;
  char *storage_name;
	int index;
  
  // In MS basic, A() and A are two different variables, so here
  // we mangle the name to include a "(" if it's an array. This is also
	// true in the original Dartmouth BASIC, according to the DTSS emulator.
	// also see notes in CHANGE/CONVERT
	//
	// NOTE: Dartmouth v4 page 38 states all variables can be used as an
	//       array of 0..10 without a DIM statement, and DIM is only needed
	//       if it is larger. Using a PET emulator, I found that this is
	//       also true for 2D arrays, you can assign to A(5,5) without it
	//       being DIMed. This code thus makes the minimum size of any
	//       dimension 11 slots. The only downside to this approach is that
	//       if a DIM is encountered with smaller limits it has no effect,
	//       which means that a SUBSCRIPT ERROR will not be raised. Given
	//       we are running known-good code, this seems fine.
  storage_name = str_new(variable->name);
  if (variable->subscripts != NULL)
    str_append(storage_name, "(");

	// see if we can find the entry in the symbol list
	storage = lst_data_with_key(interpreter_state.variable_values, storage_name);
  
  // if not, make a new variable slot in values and set it up
  if (storage == NULL) {
    int slots;
    
    // malloc a single slot, if it's an array we'll use this as the template
    storage = malloc(sizeof(*storage));
    
    // set the type based on the name, which will override any passed type
		// NOTE: don't use storage_name here, we might have added a (, always use variable->name
    char trailer = variable->name[strlen(variable->name) - 1];
    if (trailer == '$')
      storage->type = STRING;
    else
      storage->type = NUMBER; // this works for all of them, int, dbl, etc.
    
    // see if we have a type being passed in, which is used in the DEFINT/SNG/DBL/STR
		// NOTE: use >0 because DIM passes -1
    if (*type > 0)
      storage->type = *type;
    // otherwise see if there's a subtype in the trailer
    else if (trailer == '%')
      storage->type = INTEGER;
    else if (trailer == '!')
      storage->type = SINGLE;
    else if (trailer == '#')
      storage->type = DOUBLE;
		
    // now see if this reference includes subscripts
    if (variable->subscripts != NULL) {
      value_t v;
      
      // now clear out any existing list of subscripts in storage, eval each of the
      // values in the variable ref, and store that value in our ->subs list_t
      // (as the value, not a pointer), and then calculate the total size we need
			storage->actual_dimensions = NULL;
			storage->defed_dimensions = NULL;
      slots = 1;
      for (list_t *L = variable->subscripts; L != NULL; L = lst_next(L)) {
        v = evaluate_expression(L->data);
				int actual = (int)v.number + 1; 			// we need to add one more slot for index 0
				
				// if the line that's calling us is DIM A(5), we need to make it 5+1 slots, but if
				// we're being called by an "invisible DIM" we need to set it to 10+1, no matter
				// what the actual parameter is. Otherwise if you have A(1)=10:A(2)=11 it will fail
				// because the first instance would dim it to 1+1.
				// NOTE: if there is a real DIM, it should return a BAD SUBSCRIPT if the index is
				//   larger, so DIM A(5) should return an error on PRINT A(6). In this code, the
				//   minimum dimension is always 10, so this will not return an error
				if (actual < 10)
					actual = 11;
				
        storage->actual_dimensions = lst_append(storage->actual_dimensions, INT_TO_POINTER(actual));
        slots *= actual;
      }
    }
    // if it doesn't include subscripts, null them out and set the number of slots to 1
    else {
      storage->actual_dimensions = NULL;
      slots = 1;
    }
    
    // now malloc the result and insert it into the values tree
    storage->value = malloc(slots * sizeof(storage->value[0]));
		interpreter_state.variable_values = lst_insert_with_key_sorted(interpreter_state.variable_values, storage, storage_name);
  }
  
  // if we haven't started runnning yet, we were being called during parsing to
  // populate the variable table. In that case, we don't need the value, so...
  if (interpreter_state.running_state == 0)
    return NULL;
  
  // at this point we have either found or created the variable, so...
  
  // compute array index, or leave it at zero if there is none
  index = 0;
  if (!string_slicing) {
    list_t *num_dimensions;         // list of actual dimensions in storage, maybe the default 10
		list_t *def_dimensions;					// list of DIMmed dimensions, if a DIM was encountered
    list_t *variable_indexes;       // list of indices in this variable reference, each is an expression, likely a constant
    
		num_dimensions = lst_first_node(storage->actual_dimensions);
		def_dimensions = lst_first_node(storage->defed_dimensions);
    variable_indexes = lst_first_node(variable->subscripts);
    
    // the *number* of dimensions has to match, you can't DIM A(1,1) and then LET B=A(1)
    if (lst_length(num_dimensions) != lst_length(variable_indexes))
      basic_error("Array dimension of variable does not match storage"); // should we exit at this point?
    else
      while (num_dimensions && variable_indexes) {
        // evaluate the variable reference's index for a given dimension
        value_t this_index = evaluate_expression(variable_indexes->data);
				
        // and get the originally defined size for that same dimension
				// NOTE: this may or may not be the same as the DIM, see notes above
				int original_dimension = POINTER_TO_INT(num_dimensions->data);

				// make sure the index is within the originally DIMed bounds
				// NOTE: should check against array_base, not 0, but this doesn't work in Dartmouth. see notes
        if ((this_index.number < 0) || (original_dimension < this_index.number)) {
          basic_error("Array subscript out of bounds");
					this_index.number = 0;//array_base; // the first entry in the C array, so it continues
        }
				
				// now check to see if there are dimed_dimensions, and check against them
				if (def_dimensions != NULL) {
					int def_dimension = POINTER_TO_INT(def_dimensions->data);
					if ((this_index.number < 0) || (def_dimension < this_index.number)) {
						basic_error("Array subscript out of DIMmed bounds");
						this_index.number = 0;
					}
				}
        
        // C arrays start at 0, BASIC arrays start at array_base
				index = (index * original_dimension) + this_index.number; // - array_base;
        
        // then move on to the next index in the list
        num_dimensions = lst_next(num_dimensions);
        variable_indexes = lst_next(variable_indexes);
      }
  }
  
  // done with this temp name, but don't pass TRUE or it will kill the original too
  //free(storage_name);
  
  // returning the type
	// NOTE: if this is part of a DIM, it's been correctly set above
  *type = storage->type;
  
  // if we are using string slicing OR there is a ANSI-style slice, return that part of the string
  if (*type == STRING) {
    value_t startPoint, endPoint;
    list_t *slice_param = NULL;
    
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
      index = 0;
      
      // HP style slices will have one or two parameters
      if (string_slicing && (lst_length(variable->subscripts) != 1 && lst_length(variable->subscripts) != 2))
        basic_error("Wrong number of parameters in string slice");
      
      slice_param = variable->subscripts;
    }
    
    // if either of those got us something, pull out both parameters
    if (slice_param != NULL) {
      long slice_start, slice_end;
      
      startPoint = evaluate_expression(slice_param->data);
      slice_start = (long)startPoint.number;
      slice_param = lst_next(slice_param);
			if (slice_param && slice_param->data)
				endPoint = evaluate_expression(slice_param->data);
			else
				endPoint = startPoint;
      slice_end = (long)endPoint.number;

      // according to ANSI, numbers outside the string should be forced to the string's bounds
      // for non-ANSI, we'll error on odd numbers?
      if (variable->slicing != NULL) {
        slice_start = (int)fmax(slice_start, 1);
        slice_end = (int)fmin(slice_end, strlen(storage->value->string));
      } else {
        if (slice_start < 1 || slice_end < 1 || slice_end > strlen(storage->value->string) - 1)
          basic_error("String slice out of bounds");
      }
      
      // again, the numbers above are 1-indexed from BASIC, so we need to...
      slice_start--;
      slice_end--;

      // the source string is at the selected array index, which is zero for non-ANSI
      either_t orig_string = storage->value[index];
      
      // build a new string (this is leaking!)
      either_t *result = malloc(sizeof(*result));
      result->string = str_new(orig_string.string);
      str_erase(result->string, slice_start, slice_end - slice_start + 1);
      
      return result; // this is being leaked?
      // otherwise just continue...
    }
  }

  // all done, return the value at that index
  return &storage->value[index];
}

/* cover method for variable_value, allows it to be exported to the parser
 without it having to know about either_t, which is private.
 */
void insert_variable(const variable_t *variable)
{
  int ignore = 0;
  variable_value(variable, &ignore);
}

/* and another version which takes the type for use with DEFINT etc. */
void insert_typed_variable(const variable_t *variable, int type)
{
  variable_value(variable, &type);
}

/* Similar to variable_value in concept, this code looks through the list of
 user-defined functions to find a matching name and/or inserts it if it's new.
 the difference is that this returns an expression which we then evaluate.
 */
expression_t *function_expression(const variable_t *function, expression_t *expression)
{
  // see if we can find the entry in the symbol list
  function_storage_t *storage;
	storage = lst_data_with_key(interpreter_state.functions, function->name);
  
  // if not, make a new slot in functions and set it up
  if (!storage) {
    // malloc an entry
    storage = malloc(sizeof(*storage));
    
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

/* number of jiffies since program start (or reset) 1/60th in Commodore/Atari format */
static int elapsed_jiffies() {
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
        storage = malloc(sizeof(*storage));
        storage->type = type;
        storage->value = malloc(sizeof(either_t));
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
      
      // and now for the fun bit, the operators list...
    case op:
      // build a list of values for each of the parameters by recursing
      // on them until they return a value
      for (int i = 0; i < expression->parms.op.arity; i++)
        parameters[i] = evaluate_expression(expression->parms.op.p[i]);
      
      // now calculate the results based on those values
      if (expression->parms.op.arity == 0) {
        // so far all of these are numbers
        result.type = NUMBER;

        switch (expression->parms.op.opcode) {
          case FRE:
            result.number = 0; // always return zero
            break;
          case RND:
            // TODO: support alternative RNDs that return limited values
            result.number = ((double)rand() / (double)RAND_MAX); // don't forget the cast!
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
          case _ABS:
            result.number = fabs(a);
            break;
          case ATN:
            result.number = atan(a);
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
          case COS:
            result.number = cos(a);
            break;
          case INT:
            result.number = floor(a);
            break;
          case FIX:
            result.number = trunc(a);
            break;
					case FRAC:
						result.number = a - trunc(a);
						break;
         case SQR:
            result.number = sqrt(a);
            break;
          case VAL:
            result.number = atof(parameters[0].string);
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
          case PEEK:
            // always return zero
            result.number = 0;
            break;
          case POS:
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
												
          default:
            basic_error("Unhandled arity-1 function");
        } //switch
      } //arity = 1
      
      // now the functions that take two parameters
      else if (expression->parms.op.arity == 2) {
        // cache the parameters
        double a = parameters[0].number;
        double b = parameters[1].number;
        
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
						// makes N copies of the given string
						result.type = STRING;
						result.string = str_new("");
						
						// BASIC-PLUS allows the first parameter to be either a string or ASCII number
						char *temp;
						if (parameters[0].type == STRING)
							temp = parameters[0].string;
						else {
							char asc = parameters[0].number;
							temp = str_new((char *)&asc);
						}
						
						for (int i = 0; i <= parameters[1].number - 1; i++) {
							str_append(result.string, temp);
						}
						break;

          default:
            result.number = 0;
            basic_error("Unhandled arity-2 function");
            break;
        }
      }
      
      // and finally, arity=3, which is currently only the MID/SEG/SUBSTR
      else if (expression->parms.op.arity == 3)  {
        double b = parameters[1].number;
        double c = parameters[2].number; // yeah, these could be ints
        
        switch (expression->parms.op.opcode) {
          case MID:
					case SEG:
					case SUBSTR:
          {
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
        }
      }
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
static int current_line()
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
static void perform_statement(list_t *L)
{
  // now process this statement
  statement_t *ps = L->data;
  if (ps) {
    switch (ps->type) {
			case BASE:
				if (ps->parms.generic_parameter != NULL) {
					value_t baseval;
					baseval = evaluate_expression(ps->parms.generic_parameter);
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
				first_val = variable_value(ps->parms.change.var1, &type1);
				variable_value(ps->parms.change.var2, &type2); // we only need the type here, the value is not used
				
				// make sure one is a string and the other is snumeric
				if (type1 == STRING && type2 != NUMBER)
					basic_error("Type mismatch in CHANGE, string to ?");
				else if (type1 == NUMBER && type2 != STRING)
					basic_error("Type mismatch in CHANGE, number to ?");
				
				// get the storage for the numeric value by adding the (
				char *array_storage_name = str_new((type1 == NUMBER) ? ps->parms.change.var1->name : ps->parms.change.var2->name);
				str_append(array_storage_name, "("); // we are assuming it is missing
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
					for (int i = 1; i <= POINTER_TO_INT(array_store->actual_dimensions->data) && array_store->value[i].number != 0; i++) {
						new_string[i - 1] = (char)array_store->value[i].number;
					}
					
					// delete any old value in the string and copy in the new one
					string_store = lst_data_with_key(interpreter_state.variable_values, ps->parms.change.var2->name);
					free(string_store->value->string);
					string_store->value->string = str_new(new_string);
				}
			}
				break;

      case CLEAR:
        // wipe out any variables and create a fresh list
        delete_variables();
        break;
        
      case CLS:
        // does nothing
        break;
        
      case CMD:
        // redirects input/output to a different device. do nothing
        break;
        
      case DATA:
        // basically works like a REM, so just move on, all the logic is in the READ
        break;
        
      case DEF:
        // sets up a function in storage
        function_expression(ps->parms.def.signature, ps->parms.def.formula);
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
				  // a REDIMing if the original_bounds are not null
				{
					// there is a varlist of items in the parameters, loop over them
					for (list_t *variable = lst_first_node(ps->parms.dim); variable != NULL; variable = lst_next(variable)) {
						// get the name of this variable and munge it to an array have
						variable_t *var = variable->data;
						char *storage_name = str_new(var->name);
						if (var->subscripts != NULL)
							str_append(storage_name, "(");
						
						// look up the storage, error if it's not found (should never happen)
						variable_storage_t *storage;
						storage = lst_data_with_key(interpreter_state.variable_values, storage_name);
						if (storage == NULL) {
							basic_error("DIM on unknown variable.");
							break;
						}
						
						// see if there already are dimensions, if so report a redim
						if (storage->defed_dimensions != NULL)
							basic_error("REDIM of already DIMmed variable.");
						
						// loop over the dimensions, eval them, and insert
						// NOTE: we do NOT add a slot for 0 here, this is only for bounds checking
						value_t v;
						for (list_t *L = var->subscripts; L != NULL; L = lst_next(L)) {
							v = evaluate_expression(L->data);
							storage->defed_dimensions = lst_append(storage->defed_dimensions, INT_TO_POINTER(v.number));
						}
					}
				}
				break;
        
      case END:
        // set the instruction pointer to null so it exits below
        interpreter_state.next_statement = NULL;
        break;
        
      case EXIT:
      case POP:
        // TODO: make this work, should be easy enough
				// NOTE: exit is not the same as pop
        break;
        
      case FOR:
      {
        forcontrol_t *new_for = malloc(sizeof(*new_for));
        either_t *loop_value;
        int type = 0;
        
        new_for->index_variable = ps->parms._for.variable;
        new_for->begin = evaluate_expression(ps->parms._for.begin).number;
        new_for->end = evaluate_expression(ps->parms._for.end).number;
        if (ps->parms._for.step)
          new_for->step = evaluate_expression(ps->parms._for.step).number;
        else {
          new_for->step = 1;
          
          // the original gnbasic code did this, which is definitely non-standard and caused problems in SST
          // is this perhaps ANSI? UPDATE: nope, ANSI actually uses this as an example of a no-body loop
          //                        if (new_for->begin < new_for->end)
          //                            new_for->step = 1;
          //                        else
          //                            new_for->step = -1;
        }
        new_for->head = L;
        loop_value = variable_value(new_for->index_variable, &type);
        loop_value->number = new_for->begin;
        
        interpreter_state.forstack = lst_append(interpreter_state.forstack, new_for);
      }
        break;
        
      case GOSUB:
      {
        gosubcontrol_t *new = malloc(sizeof(*new));
        
        new->returnpoint = lst_next(L);
        interpreter_state.gosubstack = lst_append(interpreter_state.gosubstack, new);
        interpreter_state.next_statement = find_line(evaluate_expression(ps->parms.gosub).number);
      }
        break;
        
      case GOTO:
      {
        interpreter_state.next_statement = find_line(evaluate_expression(ps->parms._goto).number);
      }
        break;
        
      case IF:
      {
        value_t cond = evaluate_expression(ps->parms._if.condition);
        /* if only does something when the condition is true */
        if (cond.number != 0) {
          /* THEN might be an expression including a GOTO or an implicit GOTO */
          if (ps->parms._if.then_expression) {
            // in gnbasic this was next = perform_statement, which meant it could only
            // perform a single statement after the IF, which is not the case in
						// MS. for this to work properly, the then_expression has to be a list
						// that is not connected to the next line, it has to end on a NULL.
            for (list_t *I = ps->parms._if.then_expression; I != NULL; I = lst_next(I)) {
              perform_statement(I);
            }
          } else {
            // if the THEN is not an expression, jump to that line
            interpreter_state.next_statement = find_line(ps->parms._if.then_linenumber);
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
        for (list_t *I = ps->parms.input; I != NULL; I = lst_next(I)) {
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
        
      case LET:
      {
        // this handles both the explicit and implicit LET
        either_t *stored_val;
        int type = 0;
        value_t exp_val;
        
        // get/make the storage entry for this variable
        stored_val = variable_value(ps->parms.let.variable, &type);
        
        // evaluate the expression
        exp_val = evaluate_expression(ps->parms.let.expression);
        
        // make sure we got the right type, and assign it if we did
        if (exp_val.type == type) {
          if (type == STRING)
            stored_val->string = exp_val.string;
          else
            stored_val->number = exp_val.number;
        } else {
          // if the type we stored last time is different than this time...
          basic_error("Type mismatch in assignment");
        }
      }
        break;
        
      case NEXT:
      {
				// make sure there is a stack
				if (interpreter_state.forstack  == NULL || lst_length(interpreter_state.forstack) == 0) {
					basic_error("NEXT without FOR");
					break;
				}
				
				// get the most-recent FOR, which is the *end* of the list
				forcontrol_t *pfc = lst_last_node(interpreter_state.forstack)->data;
				
				// see if the next has any variable names, that is, NEXT I vs. NEXT,
				// and if so, ensure the latest FOR on the stack is one of those variables
				if (lst_length(ps->parms.next) > 0) {
					bool foundIt = false;
					list_t *var = lst_first_node(ps->parms.next);
					for (int i = 0; i < lst_length(ps->parms.next); i++) {
						if (strcmp(pfc->index_variable->name, ((variable_t *)var->data)->name) == 0) {
							foundIt = true;
						}
						else {
							var = lst_next(ps->parms.next);
						}
					}
					if (!foundIt) {
						basic_error("NEXT with mismatched FOR");
						break;
					}
				}
				
				// do a STEP
        int type = 0;
				either_t *lv = variable_value(pfc->index_variable, &type);
        lv->number += pfc->step;
				
				// and see if we need to go back to the FOR or we're done and we continue on
        if (((pfc->step < 0) && (lv->number >= pfc->end)) ||
            ((pfc->step > 0) && (lv->number <= pfc->end))) {
          // we're not done, go back to the head of the loop
          interpreter_state.next_statement = lst_next(pfc->head);
        } else {
          // we are done, remove this entry from the stack and just keep going
          interpreter_state.forstack = lst_remove_node_with_data(interpreter_state.forstack, pfc);
					free(pfc);
        }
      }
        break;
        
      case NEW:
        /* it's not entirely clear what this should do INSIDE a program, but... */
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
        numslist = ps->parms.on.numbers;

        // eval, returning a double...
        value_t val = evaluate_expression(ps->parms.on.expression);
        
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
        if (ps->parms.on.type == GOTO) {
          interpreter_state.next_statement = find_line(linenum);
        } else {
          gosubcontrol_t *new = malloc(sizeof(*new));
          new->returnpoint = lst_next(L);
          interpreter_state.gosubstack = lst_append(interpreter_state.gosubstack, new);
          interpreter_state.next_statement = find_line(linenum);
        }
      }
        break;
        
      case POKE:
        // do nothing
        break;
        
      case PRINT:
      {
        printitem_t *pp;
				
				// see if the list has a formatter, and set up the format string or set it to default
				value_t format_string;
				format_string.type = STRING;
				if (ps->parms.print.format)
					format_string = evaluate_expression(ps->parms.print.format);
				else
					format_string.string = NULL;
				
        // now loop over the items in the print list
				for (list_t *I = ps->parms.print.item_list; I != NULL; I = lst_next(I)) {
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
        if (lst_last_node(ps->parms.print.item_list))
          pp = (printitem_t *)(lst_last_node(ps->parms.print.item_list)->data);
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
        if (ps->parms.generic_parameter == NULL)
          srand((unsigned int)time(0));
        else {
          value_t seed_value = evaluate_expression(ps->parms.generic_parameter);
          srand(seed_value.number);
        }
      }
        break;

      case READ:
      {
        list_t *variable_list;
        
        if (interpreter_state.current_data_statement == NULL) {
          basic_error("No more DATA for READ");
        }
        
        variable_list = ps->parms.read;
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
        if (ps->parms.generic_parameter != NULL) {
          // if there is a parameter, treat it as a line number
          // Wang BASIC treats the parameter as an ordinal, 'reset to nth global entry', we do not support it
          value_t linenum = evaluate_expression(ps->parms.generic_parameter);
          interpreter_state.current_data_statement = find_line((int)linenum.number);
          interpreter_state.current_data_element = NULL;
        } else {
          // if there's no parameter, reset it to the first item
          interpreter_state.current_data_statement = find_line(interpreter_state.first_line);
          interpreter_state.current_data_element = NULL;
        }
        break;
        
      case RETURN:
      {
				gosubcontrol_t *pgc;
				if (interpreter_state.gosubstack == NULL || lst_length(interpreter_state.gosubstack) == 0) {
					basic_error("RETURN without GOSUB");
					break;
				}

        pgc = lst_last_node(interpreter_state.gosubstack)->data;
        interpreter_state.next_statement = pgc->returnpoint;
        interpreter_state.gosubstack = lst_remove_node_with_data(interpreter_state.gosubstack, pgc);
      }
        break;
        
      case STOP:
      {
        if (ps->parms.generic_parameter != NULL) {
          value_t message = evaluate_expression(ps->parms.generic_parameter);
          printf("STOP: %s\n", message.string);
        }
        exit(0);
      }
        break;
				
				// this handles the weird-syntax case of TIME$=, which looks like a variable set but
				// is really a statement
			case TIME_STR:
			{
				if (ps->parms.generic_parameter != NULL) {
					// value is in HMS format, so make sure we got a strong
					value_t hms = evaluate_expression(ps->parms.generic_parameter);
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
        printf("Unimplemented statement %d\n", ps->type);
				exit(0);
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
//	variable_storage_t *storage;
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
static void print_variables() {
	lst_foreach(interpreter_state.variable_values, print_symbol, NULL);
  printf("\n\n");
}
/* used for CLEAR, NEW and similar instructions. */
static void delete_variables() {
	lst_free_everything(interpreter_state.variable_values);
	interpreter_state.variable_values = NULL;
}
static void delete_functions() {
	lst_free_everything(interpreter_state.functions);
	interpreter_state.functions = NULL;
}
static void delete_lines() {
  for(int i = MAXLINE - 1; i >= 0; i--) {
    if (interpreter_state.lines[i] != NULL) {
      lst_free(interpreter_state.lines[i]);
    }
  }
}

/* set up empty trees to store variables and user functions as we find them */
void interpreter_setup()
{
	interpreter_state.variable_values = NULL;
	interpreter_state.functions = NULL;
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
  interpreter_state.current_statement = first_statement;          // the first statement
  interpreter_state.current_data_statement = first_statement;     // the DATA can point anywhere
  interpreter_state.current_data_element = NULL;                  // the element within the DATA is nothing
}

/* the main loop for the program */
void interpreter_run(void)
{
  // the cursor starts in col 0
  interpreter_state.cursor_column = 0;

  // start the clock and mark us as running
  start_ticks = clock();
	gettimeofday(&start_time, NULL);
  interpreter_state.running_state = 1;
	
	// and set the reset to now as well
	gettimeofday(&reset_time, NULL);
  
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
    if (trace_lines && last_line != current_line()) {
      last_line = current_line();
      printf("[%i]\n", last_line);
    }
  }
  
  // stop the clock and mark us as stopped
  end_ticks = clock();
  gettimeofday(&end_time, NULL);
  interpreter_state.running_state = 0;
}

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

#include "retrobasic.h"
#include "parse.h"

#include <sys/time.h>

/* here's the actual definition of the interpreter state which is extern in the header */
interpreterstate_t interpreter_state;

/* and the same for the various flags */
int run_program = TRUE;                 // default to running the program, not just parsing it
int print_stats = FALSE;                // do not print or write stats by default
int write_stats = FALSE;
int tab_columns = 10;                   // based on PET BASIC, which is a good enough target
int trace_lines = FALSE;
int upper_case = FALSE;                 // force INPUT to upper case
int array_base = 1;                     // lower bound of arrays, can be set to 0 with OPTION BASE
double random_seed = -1;                // reset with RANDOMIZE, if -1 then auto-seeds
int string_slicing = FALSE;             // are references like A$(1,1) referring to an array entry or doing slicing?
int goto_next_highest = FALSE;          // if a branch targets an non-existant line, should we go to the next highest?
int ansi_on_boundaries = FALSE;         // if the value for an ON statement <1 or >num entries, should it continue or error?
int ansi_tab_behaviour = FALSE;         // if a TAB < current column, ANSI inserts a CR, MS does not

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
  list_t *parameters;      // parameters, if any, as variable_t
  expression_t *formula;  // related formula
} function_storage_t;

/* forward declares */
static value_t evaluate_expression(expression_t *e);
static int line_for_statement(list_t *s);
static int current_line(void);

static void print_variables(void);
static void delete_variables(void);
static void delete_functions(void);
static void delete_lines(void);

/* defitions of variables used by the static analyzer */
clock_t start_ticks = 0, end_ticks = 0;  // start and end ticks, for calculating CPU time
struct timeval start_time, end_time;     // start and end clock, for total run time

/************************************************************************/

static void basic_error(char *message)
{
  fprintf(stderr, "%s at line %d\n", message, current_line());
}

/************************************************************************/

///* basic string compare used in the symbol tree to find variable names.
// returning true stops the tree walk, so we do that on a match */
//int symbol_compare(gconstpointer a, gconstpointer b)
//{
//  return strcasecmp(a, b);
//}

/* Returns an either_t containing a string or a number for the underlying
 variable, along with its type in the out-parameter 'type'. If the
 variable has not been encountered before it will be created here. */
/* NOTE: this code also handles string slicing. it would be much preferrable
 to do that as a function call so it could overload the MID$-style functions
 but I could not figure out how to do that at runtime in the yacc code. */
either_t *variable_value(variable_t *variable, int *type)
{
  variable_storage_t *storage;
  char *storage_name;
  long index;
  
  // in MS basic, A() and A are two different variables, so here
  // we mangle the name to include a "(" if its an array
  storage_name = str_new(variable->name);
  if (variable->subscripts != NULL)
    str_append(storage_name, "(");
  
  // see if we can find the entry in the symbol list
	storage = lst_data_with_key(interpreter_state.variable_values, storage_name);
  //storage = g_tree_lookup(interpreter_state.variable_values, storage_name);
  
  // if not, make a new variable slot in values and set it up
  if (storage == NULL) {
    int slots;
    
    // malloc a single slot, if it's an array we'll use this as the template
    storage = malloc(sizeof(*storage));
    
    // set the type based on the name, which will override any passed type
    char trailer = variable->name[strlen(variable->name) - 1];
    if (trailer == '$')
      storage->type = STRING;
    else
      storage->type = NUMBER; // this works for all of them, int, dbl, etc.
    
    // see if we have a type being passed in, which is used in the DEFINT/SNG/DBL/STR
    if (*type != 0)
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
      
      // now clear out any existing list of subscripts in storage,
      // eval each of the ones in the variable ref, and store that value
      // in our ->sub list_t (as the pointer, not a structure), and then
      // calculate the total size we need
      storage->subscripts = NULL;
      slots = 1;
      for (list_t *L = variable->subscripts; L != NULL; L = lst_next(L)) {
        v = evaluate_expression(L->data);
				size_t actual = (int)v.number + (1 - array_base); // if we're using 0-base indexing, we need to add one more slot
        storage->subscripts = lst_append(storage->subscripts, (void *)(actual));
        slots *= actual;
      }
    }
    // if it doesn't include subscripts, null them out and set the number of slots to 1
    else {
      storage->subscripts = NULL;
      slots = 1;
    }
    
    // now malloc the result and insert it into the values tree
    storage->value = malloc(slots * sizeof(storage->value[0]));
		lst_insert_with_key_sorted(interpreter_state.variable_values, storage, storage_name);
    //g_tree_insert(interpreter_state.variable_values, storage_name, storage);
  }
  
  // if we haven't started runnning yet, we were being called during parsing to
  // populate the variable table. In that case, we don't need the value, so...
  if (interpreter_state.running_state == 0)
    return NULL;
  
  // at this point we have either found or created the variable, so...
  
  // compute array index, or leave it at zero if there is none
  index = 0;
  if (!string_slicing) {
    list_t *original_dimensions;         // list of actual dimensions in storage (from the DIM), stored as integers
    list_t *variable_indexes;            // list of indices in this variable reference, each is an expression, likely a constant
    
    original_dimensions = storage->subscripts;
    variable_indexes = variable->subscripts;
    
    // the *number* of dimensions has to match, you can't DIM A(1,1) and then LET B=A(1)
    if (lst_length(original_dimensions) != lst_length(variable_indexes))
      basic_error("Array dimension of variable does not match storage"); // should we exit at this point?
    else
      while (original_dimensions && variable_indexes) {
        // evaluate the variable reference's index for a given dimension
        value_t this_index = evaluate_expression(variable_indexes->data);
        // and get the originally DIMmed size for that same dimension
				long original_dimension = (long)(original_dimensions->data);
        
        // make sure the index is within the originally DIMed bounds
        if ((this_index.number < array_base) || (original_dimension < this_index.number - array_base)) {
          basic_error("Array subscript out of bounds");
          this_index.number = array_base; // the first entry in the C array, so it continues
        }
        
        // C arrays start at 0, BASIC arrays start at array_base
        index = (index * original_dimension) + (long)this_index.number - array_base;
        
        // then move on to the next index in the list
        original_dimensions = lst_next(original_dimensions);
        variable_indexes = lst_next(variable_indexes);
      }
  }
  
  // done with this temp name, but don't pass TRUE or it will kill the original too
  //free(storage_name);
  //g_string_free(storage_name, FALSE);
  
  // returning the type
  *type = storage->type;
  
  // if we are using string slicing OR there is a ANSI-style slice, return that part of the string
  if (*type == STRING) {
    value_t startPoint, endPoint;
    list_t *slice_param = NULL;
    
    // see if there is an ANSI slice defined, if so, use that
    if (variable->slicing != NULL && lst_length(variable->slicing)) {
      // ANSI slices will always have two parameters in the slicing list
      if (variable->slicing != NULL && lst_length(variable->slicing) != 2)
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
			if(slice_param && slice_param->data)
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
      
      // build a new string
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
 without it having to know about either_t, which is private  */
void insert_variable(variable_t *variable)
{
  int ignore = 0;
  variable_value(variable, &ignore);
}

/* and another version which takes the type for use with DEFINT etc. */
void insert_typed_variable(variable_t *variable, int type)
{
  variable_value(variable, &type);
}

/* Similar to variable_value in concept, this code looks through the list of
 user-defined functions to find a matching name and/or inserts it if it's new.
 the difference is that this returns an expression which we then evaluate.
 */
expression_t *function_expression(variable_t *function, expression_t *expression)
{
  // see if we can find the entry in the symbol list
  function_storage_t *storage;
	storage = lst_data_with_key(interpreter_state.functions, function->name);
  //storage = g_tree_lookup(interpreter_state.functions, function->name);
  
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
		lst_insert_with_key_sorted(interpreter_state.functions, storage, function->name);
    //g_tree_insert(interpreter_state.functions, function->name, storage);
  }
  
  // at this point we have either found or created the formula, so...
  return storage->formula;
}

/* converts a number to a new value_t */
static value_t double_to_value(double v)
{
  value_t r;
  r.type = NUMBER;
  r.number = v;
  return r;
}

/* converts a number to a string using MS's odd formatting rules */
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
static char *number_to_string(double d)
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
      either_t *p;
      p = variable_value(expression->parms.variable, &type);
      result.type = type;
      if (type == STRING)
        result.string = p->string;
      else
        result.number = p->number;
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
			//= g_tree_lookup(interpreter_state.functions, func_name);
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
			list_t *stack = NULL;// = g_tree_new(symbol_compare);
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
				lst_insert_with_key_sorted(stack, storage, original_parameter->parms.variable->name);
        //g_tree_insert(stack, original_parameter->parms.variable->name, storage);
        
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
        //temp_val = g_tree_lookup(stack, original_parameter->parms.variable->name);
        
        // copy the value back
        if (type == STRING)
          global_val->string = temp_val->value->string;
        else
          global_val->number = temp_val->value->number;
        
        // kill the stack entry
				lst_remove_node_with_key(stack, original_parameter->parms.variable->name);
        //g_tree_remove(stack, original_parameter->parms.variable->name);
        free(temp_val);
        
        // move to the next parameter
        if (original_definition->parameters->next != NULL)
          original_parameter = lst_next(original_definition->parameters)->data;
      }

      // kill the stack to be safe
			lst_free_everything(stack);
      //g_tree_destroy(stack);
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
            if(parameters[0].string == NULL)
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
            result = double_to_value(-(a < b));
            break;
          case '>':
            result = double_to_value(-(a > b));
            break;
          case CMP_LE:
            result = double_to_value(-(a <= b));
            break;
          case CMP_GE:
            result = double_to_value(-(a >= b));
            break;
          case CMP_NE:
          case CMP_HASH:
            if (parameters[0].type >= NUMBER)
              result = double_to_value(-(a != b));
            else
              result = double_to_value(-!!strcmp(parameters[0].string, parameters[1].string));
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
          default:
            result.number = 0;
            basic_error("Unhandled arity-2 function");
            break;
        }
      }
      
      // and finally, arity=3, which is currently only the MID
      else if (expression->parms.op.arity == 3)  {
        double b = parameters[1].number;
        double c = parameters[2].number; // yeah, these could be ints
        
        switch (expression->parms.op.opcode) {
          case MID:
            result.type = STRING;
          {
            result.string = str_new(parameters[0].string);
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
static void print_expression(expression_t *e, char *format)
{
  // get the value of the expression for this item
  value_t v = evaluate_expression(e);
  
  // if there is a USING string, build a c-style format string from it
  if (format) {
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
static int line_for_statement(list_t *statement)
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
//    if(first_line == second_line)
//        return 0;
//    // otherwise, simply count the non-empty lines between the two
//    int distance = 0;
//    int first = (first_line < second_line) ? first_line : second_line;
//    int last = (first_line >= second_line) ? second_line : first_line;
//    for(int i = first; i <= last; i++) {
//        if(interpreter_state.lines[i]) distance++;
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
      case BYE:
        // unlike END, this exits BASIC entirely
        exit(EXIT_SUCCESS);
        break;
        
      case CALL:
        // do nothing
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
        // sets up a function in storage. the only interesting thing here is that the
        function_expression(ps->parms.def.signature, ps->parms.def.formula);
        break;
        
      case DIM:
        // the parser has already pulled out the variable names, so they already
        // have slots in the table. we still need to call insert_variable to set up
      {
        for (list_t *I = ps->parms.dim; I != NULL; I = lst_next(I)) {
          variable_t *pv = I->data;
          insert_variable(pv);
        }
      }
        break;
        
      case DEFSTR:
      case DEFINT:
      case DEFSNG:
      case DEFDBL:
        // done here because they are really varieties of DIM, not DEF
      {
        for (list_t *I = ps->parms.deftype.vars; I != NULL; I = lst_next(I)) {
          variable_t *pv = I->data;
          insert_typed_variable(pv, ps->parms.deftype.type);
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
        break;
        
      case FOR:
      {
        forcontrol_t *new_for = malloc(sizeof(*new_for));
        either_t *lv;
        int type = 0;
        
        new_for->index_variable = ps->parms._for.variable;
        new_for->begin = evaluate_expression(ps->parms._for.begin).number;
        new_for->end = evaluate_expression(ps->parms._for.end).number;
        if(ps->parms._for.step)
          new_for->step = evaluate_expression(ps->parms._for.step).number;
        else {
          new_for->step = 1;
          
          // the original gnbasic code did this, which is definitely non-standard and caused problems in SST
          // is this perhaps ANSI?
          //                        if (new_for->begin < new_for->end)
          //                            new_for->step = 1;
          //                        else
          //                            new_for->step = -1;
        }
        new_for->head = L;
        lv = variable_value(new_for->index_variable, &type);
        lv->number = new_for->begin;
        
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
            // this was formerly next = perform_statement, which meant it could only
            // perform a single statement after the IF. for this to work properly,
            // the then_expression has to be a list that is not connected to the
            // next line, it has to end on a NULL
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
        //    value of the associated variable, we do that here
        
        // loop over the items in the variable/prompt list
        for (list_t *I = ps->parms.input; I != NULL; I = lst_next(I)) {
          either_t *value;
          int type = 0;
          
          printitem_t *ppi = I->data;
          if (ppi->expression->type == variable) {
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
        // this version does not precisely match MS, it always gets the last
        // entry on the FOR stack and uses that variable, ignoring the variable
        // that might have been entered in the source. this means you can't put a
        // NEXT J inside a NEXT I
        // FIXME: this is easy to fix, simply get the variable name from the FOR
        //  stack and then check if it's the same as the one in the NEXT, error out
        forcontrol_t *pfc = lst_last_node(interpreter_state.forstack)->data;
        either_t *lv;
        int type = 0;
        
        lv = variable_value(pfc->index_variable, &type);
        lv->number += pfc->step;
        if (((pfc->step < 0) && (lv->number >= pfc->end)) ||
            ((pfc->step > 0) && (lv->number <= pfc->end))) {
          // we're not done, go back to the head of the loop
          interpreter_state.next_statement = lst_next(pfc->head);
        } else {
          // we are done, remove this entry from the stack
          interpreter_state.forstack = lst_remove_node_with_data(interpreter_state.forstack, pfc);
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
      }
        interpreter_state.next_statement = NULL; // stop execution, there's nothing left
        break;
        
      case ON:
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
        
      case POKE:
        // do nothing
        break;
        
      case PRINT:
      {
        printitem_t *pp;
        // loop over the items in the print list
        for (list_t *I = ps->parms.print.item_list; I != NULL; I = lst_next(I)) {
          pp = I->data;
          
          // if there's a USING, evaluate the format string it and print using it
          if (ps->parms.print.format) {
            value_t format_string;
            format_string = evaluate_expression(ps->parms.print.format);
            print_expression(pp->expression, format_string.string);
          }
          // otherwise, see if there's a separator and print using the width
          else {
            print_expression(pp->expression, NULL);
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
        if (pp != NULL && pp->expression->type == op && (pp->expression->parms.op.opcode == SPC || pp->expression->parms.op.opcode == TAB)) {
          pp->separator = ';';
        }
        
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
        gosubcontrol_t *pgc = lst_last_node(interpreter_state.gosubstack)->data;
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
        assert(1==2);
      }
        break;

      case VARLIST:
        print_variables();
        break;
        
      default:
        printf("Unimplemented statement %d\n", ps->type);
        assert(0);
    } //end switch
  }
}

/* variable tree walking methods, returning FALSE means "keep going" */

/* cheater method for printing out all the variable names */
static void print_symbol(void *key, void *value, void *unused)
{
  printf("\n%s ", (char *)key);
}
/* ...and their values */
static int print_value(void *key, void *value, void *unused)
{
	variable_storage_t *storage;
	storage = lst_data_with_key(interpreter_state.variable_values, key);
	//= g_tree_lookup(interpreter_state.variable_values, key);
	
  either_t *p = storage->value;
  int type = storage->type;
  if (type == STRING)
    if (p->string == 0)
      printf("\n%s: %s", (char *)key, "NULL");
    else
      printf("\n%s: %s", (char *)key, (char *)p->string);
  else
    printf("\n%s: %f", (char *)key, (double)p->number);
  return FALSE;
}
/* used for VARLIST in those versions of BASIC that support it */
static void print_variables() {
	lst_foreach(interpreter_state.variable_values, print_symbol, NULL);
  //g_tree_foreach(interpreter_state.variable_values, print_symbol, NULL);
  printf("\n\n");
}
/* used for CLEAR, NEW and similar instructions. */
static void delete_variables() {
	lst_free_everything(interpreter_state.variable_values);
  //g_tree_destroy(interpreter_state.variable_values);
	interpreter_state.variable_values = NULL; //g_tree_new(symbol_compare);
}
static void delete_functions() {
	lst_free_everything(interpreter_state.functions);
  //g_tree_destroy(interpreter_state.functions);
	interpreter_state.functions = NULL;// g_tree_new(symbol_compare);
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
	interpreter_state.variable_values = NULL;//g_tree_new(symbol_compare);
	interpreter_state.functions = NULL; //g_tree_new(symbol_compare);
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

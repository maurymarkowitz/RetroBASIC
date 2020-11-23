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

#include <getopt.h>

/* here's the actual definition of the interpreter state,
   which is extern in the header */
interpreterstate_t interpreter_state;

/* internal state variables used for I/O and other tasks */
static int run_program = 1; // default to running the program, not just parsing it
static int print_stats = 1;
static int write_stats = 0;
static int tab_columns = 16;
static int trace_lines = FALSE;
static double random_seed = -1;
//static char *program_file = "";
static char *input_file = "";
static char *print_file = "";
static char *stats_file = "";

/* private types used only within the interpreter */
/* value_t is used to store (and process) the results of an evaluation */
typedef struct {
    int type;			/* NUMBER, STRING */
    GString *string;
    double number;
} value_t;

/* either_t is used within value_t for the actual data
  FIXME: is the union worthwhile? why not use two slots instead of a union? 4 wasted bytes? */
typedef union {
    GString *s;
    double d;
} either_t;

/* variable_storage_t holds the *value* of a variable in memory */
typedef struct {
    int type;			/* NUMBER, STRING */
    GList *sub;         // subscripts, if any
    either_t *value;    // actual value, for non-arrays
} variable_storage_t;

/* function_storage_t holds the expression from the DEF */
typedef struct {
    int type;               /* NUMBER, STRING */
    GList *sub;             // parameters, if any
    expression_t *formula;  // related formula
} function_storage_t;

/* forward declares */
static value_t evaluate_expression(expression_t *e);
static int line_for_statement(GList *s);
static int current_line(void);

static void print_variables(void);
static void delete_variables(void);

/* defitions of variables used by the static analyzer */
int variables_total = 0;
int variables_default = 0;
int variables_int = 0;
int variables_float = 0;
int variables_double = 0;
int variables_string = 0;
int numeric_constants_total = 0;
int numeric_constants_float = 0;
int numeric_constants_zero = 0;
int numeric_constants_one = 0;
int numeric_constants_minus_one = 0;
int numeric_constants_one_digit = 0;
int numeric_constants_two_digit = 0;
int numeric_constants_three_digit = 0;
int numeric_constants_four_digit = 0;
int numeric_constants_five_digit = 0;
int numeric_constants_one_byte = 0;
int numeric_constants_two_byte = 0;
int numeric_constants_four_byte = 0;
int numeric_constants_big = 0;
int numeric_constants_10 = 0;
int numeric_constants_16 = 0;
int numeric_constants_256 = 0;

int string_constants_total = 0;
int string_constants_one_byte = 0;
int string_constants_two_byte = 0;
int string_constants_four_byte = 0;
int string_constants_eight_byte = 0;
int string_constants_sixteen_byte = 0;
int string_constants_big = 0;
int string_constants_max = 0;
int linenum_constants_total = 0;
int linenum_forwards = 0;
int linenum_backwards = 0;
int linenum_goto_totals = 0;
int linenum_then_goto_totals = 0;
int linenum_gosub_totals = 0;
int linenum_on_totals = 0;
int for_loops_total = 0;
int for_loops_step_1 = 0;
int for_loops_all_constant = 0;

/************************************************************************/

static void basic_error(char *message)
{
    fprintf(stderr, "%s at line %d\n", message, current_line());
}

/************************************************************************/

/* basic string compare used in the symbol tree to find variable names.
   returning true stops the tree walk, so we do that on a match */
gint symbol_compare(gconstpointer a, gconstpointer b)
{
    return strcasecmp(a, b);
}

/* Returns an either_t containing a string or a number for the underlying
   variable, along with its type in the out-parameter 'type'. If the
   variable has not been encountered before it will be created here. */
either_t *variable_value(variable_t *variable, int *type)
{
    variable_storage_t *storage;
    GString *storage_name;
    int index = 0;

    // in MS basic, A() and A are two different variables,
    // so what we do is mangle the name here in the lookup
    // so that every time someone looks up A(1,1) it looks
    // for A(, and if they look for A it looks for A
    storage_name = g_string_new(variable->name->str);
    if (variable->sub != NULL)
        storage_name = g_string_append(storage_name, "(");
    
    // see if we can find the entry in the symbol list
    storage = g_tree_lookup(interpreter_state.values, storage_name->str);
    
    // if not, make a new variable slot in values and set it up
    if (storage == NULL) {
        int slots = 0;

        // malloc a single slot, if it's an array we'll use this as the template
        storage = malloc(sizeof(*storage));
        
        // set the type based on the name
        char trailer = variable->name->str[strlen(variable->name->str) - 1];
        if (trailer == '$')
            storage->type = STRING;
        else
            storage->type = NUMBER; // this works for all of them, int, dbl, etc.
        
        // now see if this reference includes subscripts
        if (variable->sub != NULL) {
            value_t v;
            int actual;

            // now clear out any existing list of subscripts in storage,
            // eval each of the ones in the variable ref, and store that value
            // in our ->sub GList (as the pointer, not a structure), and then
            // calculate the total size we need
            storage->sub = NULL;
            slots = 1;
            for (GList *L = variable->sub; L != NULL; L = g_list_next(L)) {
                v = evaluate_expression(L->data);
                actual = (int)v.number;
                storage->sub = g_list_append(storage->sub, GINT_TO_POINTER(actual));
                slots *= actual;
            }
        }
        // if it doesn't include subscripts, null them out and set index = 1
        else {
            storage->sub = NULL;
            slots = 1;
        }
        
        // now malloc the result and insert it into the values tree
        storage->value = malloc(slots * sizeof(storage->value[0]));
        g_tree_insert(interpreter_state.values, storage_name->str, storage);
    }
    
    // at this point we have either found or created the variable, so...
    
    /* get the type */
    *type = storage->type;
    /* compute array index */
    index = 0;
    {
        GList *LA;			/* list of actual sizes in storage (from the DIM) */
        GList *LI;			/* list of indices in this reference */
        
        LA = storage->sub;
        LI = variable->sub;
        
        if (g_list_length(LA) != g_list_length(LI))
            basic_error("Array dimension of variable does not match storage");
        else
            while (LA != NULL && LI != NULL) {
                // evaluate the variable reference's index for a given dimension
                value_t v = evaluate_expression(LI->data);
                // and get the originally DIMmed size for that same dimension
                int actual = GPOINTER_TO_INT(LA->data);
                
                if ((v.number < 0) || (actual < v.number - 1)) {
                    //printf("Array subscript out of bounds for variable %s, name %s, is %i in call and %i in storage.\n", variable->name->str, storage_name->str, (int)v.number, (int)actual);
                    basic_error("Array subscript out of bounds");
                    v.number = 1;
                }
                
                // note the -1, we have to offset the index
                // TODO: if we add OPTION BASE, the -1 might change, and above too
                index = (index * actual) + (int)v.number - 1;
                LA = g_list_next(LA);
                LI = g_list_next(LI);
            }
    }
    
    // done with this, but don't pass TRUE!
    g_string_free(storage_name, FALSE);
    
    // all done, return the value at that index
    return &storage->value[index];
}

/* Similar to variable_value in concept, this code looks through the list of
   user-defined functions to find a matching name and/or inserts it if it's new.
   the difference is that this returns an expression which we then evaluate. */
expression_t *function_definition(variable_t *function, expression_t *expression)
{
    // see if we can find the entry in the symbol list
    function_storage_t *storage;
    storage = g_tree_lookup(interpreter_state.functions, function->name->str);
    
    // if not, make a new slot in functions and set it up
    if (storage == NULL) {
        // malloc an entry
        storage = malloc(sizeof(*storage));
        
        // set the type based on the name
        char trailer = function->name->str[strlen(function->name->str) - 1];
        if (trailer == '$')
            storage->type = STRING;
        else
            storage->type = NUMBER; // this works for all of them, int, dbl, etc.
        
        // copy over the list of parameters
        storage->sub = g_list_copy(function->sub);
        
        // now store the expression/formula
        storage->formula = expression;

        // and insert it into storage
        g_tree_insert(interpreter_state.functions, function->name->str, storage);
    }
    
    // at this point we have either found or created the formula, so...
    return storage->formula;
}

static value_t perform_infix_operation(double v)
{
    value_t r;
    
    r.type = NUMBER;
    r.number = v;
    return r;
}

/* recursively evaluates an expression and returns a value_t with the result */
static value_t evaluate_expression(expression_t *e)
{
    value_t r;
    value_t p[10];
    int i;
    double a, b, c;
    
    switch (e->type) {
        // for number and string constants, simply copy the value
        case number:
            r.type = NUMBER;
            r.number = e->parms.number;
            break;
        case string:
            r.type = STRING;
            r.string = e->parms.string;
            break;
            
        // variables are also easy, just copy over their value from storage
        case variable:
            {
                int type;
                either_t *p;
                p = variable_value(e->parms.variable, &type);
                r.type = type;
                if (type == STRING)
                    r.string = p->s;
                else
                    r.number = p->d;
            }
            break;
            
        // user functions are not so simple, because the variable references
		// in the definition have to replace those in the main list.
        // TODO: we need to eval the parameters and pass them in
        case fn:
            {
                expression_t *p;
                p = function_definition(e->parms.variable, p); // note the re-use of the "variable" slot here
                r = evaluate_expression(p);
            }
            break;
            
        // and now for the fun bit, the operators list...
        case op:
            // build a list of values for each of the parameters by recursing
            // on them until they return a value
            for (i = 0; i < e->parms.op.arity; i++)
                p[i] = evaluate_expression(e->parms.op.p[i]);
            
            // now calculate the results based on those values
            if (e->parms.op.arity == 1) {
                // most of the following functions return numbers, so default to that
                r.type = NUMBER;
                
                // get the first parameter, in this case, the only one
                a = p[0].number;
                
                switch (e->parms.op.o) {
                    case '-':
                        r.number = -a;
                        break;
                    case NOT:
                        r.number = ~(int)a;
                        break;
                    case _ABS:
                        r.number = fabs(a);
                        break;
                    case ATN:
                        r.number = atan(a);
                        break;
                    case CHR:
						{
							char c[2];
							c[0] = (char)a;
							c[1] = '\0';
							r.type = STRING;
							r.string = g_string_new(c);
						}
                        break;
                    case CLOG:
                        r.number = log10(a);
                        break;
                    case EXP:
                        r.number = exp(a);
                        break;
                    case LEN:
                        r.number = strlen(p[0].string->str);
                        break;
                    case STR:
                        {
                            char str[80];
                            sprintf(str, "%lf", a); // FIXME: need to put in the right format here, might differ among platforms
                            r.type = STRING;
                            r.string = g_string_new(str);
                        }
                    case LOG:
                        r.number = log(a);
                        break;
                    case SIN:
                        r.number = sin(a);
                        break;
                    case COS:
                        r.number = cos(a);
                        break;
                    case INT:
                        r.number = floor(a);
                        break;
                    case SQR:
                        r.number = sqrt(a);
                        break;
                    case RND:
                        // TODO: support alternative RNDs that return limited values
                        r.number = (rand() / (double)RAND_MAX); // don't forget the cast!
                        break;
                    case VAL:
                        r.number = atof(p[0].string->str);
                        break;
                    case SGN:
                        // early MS variants return 1 for 0, this implements the newer version where 0 returns 0
                        if (a < 0)
                            r.number = -1;
                        else if (a == 0)
                            r.number = 0;
                        else
                            r.number = 1;
                        break;
                    case PEEK:
                        // always return zero
                        r.number = 0;
                        break;
                    case POS:
                        r.number = (double)interpreter_state.cursor_column; //FIXME: should this be +1?
                        break;
                    case TAB:
                        // TAB does nothing if the current cursor position is past
                        // the number being passed in, otherwise it adds spaces to
                        // move the cursor to that column number
                        r.type = STRING;
                        r.string = g_string_new("");
                        int tabs = (int)p[0].number;
                        if (tabs > interpreter_state.cursor_column) {
                            for (int i = interpreter_state.cursor_column; i <= tabs - 1; i++) {
                                r.string = g_string_append(r.string, " ");
                            }
                        }
                        break;
                    case SPC:
                        // spc always adds the indicated number of spaces
                        r.type = STRING;
                        r.string = g_string_new("");
                        for (int i = 0; i <= p[0].number - 1; i++) {
                            r.string = g_string_append(r.string, " ");
                        }
                        
                    default:
                        basic_error("Unhandled arity-1 function");
                } //switch
            } //arity = 1
            
            // now the functions that take two parameters
            else if (e->parms.op.arity == 2) {
				// cache the parameters
                a = p[0].number;
                b = p[1].number;
                
                switch (e->parms.op.o) {
                    case '+':
                        if (p[0].type == STRING && p[1].type == STRING) {
                            r.type = STRING;
                            r.string = g_string_new(g_strconcat(p[0].string->str, p[1].string->str, NULL));
                        }
                        else if (p[0].type == NUMBER && p[1].type == NUMBER)
                            r = perform_infix_operation(a + b);
                        else {
                            r.number = 0;
                            basic_error("Type mismatch");
                        }
                        break;
                    case '-':
                        r = perform_infix_operation(a - b);
                        break;
                    case '*':
                        r = perform_infix_operation(a * b);
                        break;
                    case '/':
                        r = perform_infix_operation(a / b);
                        break;
                    case '^':
                        r = perform_infix_operation(pow(a, b));
                        break;
                    case '=':
                        if (p[0].type == NUMBER)
                            r = perform_infix_operation(-(a == b));
                        else
                            r = perform_infix_operation(-!strcmp(p[0].string->str, p[1].string->str));
                        break;
                    case '<':
                        r = perform_infix_operation(-(a < b));
                        break;
                    case '>':
                        r = perform_infix_operation(-(a > b));
                        break;
                    case CMP_LE:
                        r = perform_infix_operation(-(a <= b));
                        break;
                    case CMP_GE:
                        r = perform_infix_operation(-(a >= b));
                        break;
                    case CMP_NE:
                        if (p[0].type == NUMBER)
                            r = perform_infix_operation(-(a != b));
                        else
                            r = perform_infix_operation(-!!strcmp(p[0].string->str, p[1].string->str));
                        break;
                    case CMP_HASH: // be nice if you could have multiple consts in this case...
                        if (p[0].type == NUMBER)
                            r = perform_infix_operation(-(a != b));
                        else
                            r = perform_infix_operation(-!!strcmp(p[0].string->str, p[1].string->str));
                        break;
                    case AND:
                        r = perform_infix_operation((int)a & (int)b);
                        break;
                    case OR:
                        r = perform_infix_operation((int)a | (int)b);
                        break;
                    case LEFT:
                        r.type = STRING;
						{
							time_t len = strlen(p[0].string->str);
							r.string = g_string_new(p[0].string->str);
							if (b < len)
								g_string_truncate(r.string, b);
						}
                        break;
                    case RIGHT:
                        r.type = STRING;
						{
							time_t len = strlen(p[0].string->str);
							r.string = g_string_new(p[0].string->str);
							if (b < len)
								r.string = g_string_erase(r.string, 0, len - b);
						}
                        break;
                    case MID: // this is the two-parameter version
                        r.type = STRING;
						{
							time_t len = strlen(p[0].string->str);
							r.string = g_string_new(p[0].string->str);
							if (b < len)
								r.string = g_string_erase(r.string, 0, b - 1);
						}
                        break;
                        
                    default:
                        r.number = 0;
                        basic_error("Unhandled arity-2 function");
						break;
                }
            }
            
            // and finally, arity=3, which is currently only the MID
            else if (e->parms.op.arity == 3)  {
                b = p[1].number;
                c = p[2].number;
                
                switch (e->parms.op.o) {
                    case MID:
                        r.type = STRING;
						{
							r.string = g_string_new(p[0].string->str);
							
							time_t len = strlen(p[0].string->str);
							if (b < len)
								r.string = g_string_erase(r.string, 0, b - 1); // note the -1
							
							len = strlen(r.string->str);
							if (c < len)
								g_string_truncate(r.string, c);
						}
                        break;
                        
                    default:
                        r.number = 0;
                        basic_error("Unhandled arity-3 function");
						break;
                }
            }
            else {
                r.number = 0;
                break;
            }
    }
    return r;
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
        
        // FIXME: this doesn't handle string formatters, see GW-BASIC manual
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
            sprintf(hash, "%%*.*f");    // replace ##.## with % spec
            strcat(hash, pc);		    // append the rest of string
        }
        // and now print it out using that format
        switch (v.type) {
            case NUMBER:
                interpreter_state.cursor_column += printf(copy, width, prec, v.number);
                break;
            case STRING:
                interpreter_state.cursor_column += printf(copy, width, prec, g_strescape(v.string->str, NULL));
                break;
        }
    }
    // there was no USING format, so use a default formatter instead,
    // potentially limited to the fieldwidth if its tabular
    else {
        switch (v.type) {
            case NUMBER:
                // in MS rules, numbers have a leading - or invisible +, and a trailing space
                interpreter_state.cursor_column += printf("% -g ", v.number);
                break;
            case STRING:
                interpreter_state.cursor_column += printf("%-s", v.string->str);
                break;
        }
    }
}

/* given a statement, this returns the line number it's part of */
/* NOTE: this is likely expensive, because is uses the index lookup
   methods in GList, which loop. So only use it when required! */
static int line_for_statement(GList *statement)
{
    // get a pointer to the program from the first line
    GList *program = interpreter_state.lines[interpreter_state.first_line];
    
    // get the index of this statement in that list
    int target_index = g_list_position(program, statement);
    
    // loop forward through the program until we find a line who's
    // first statement is higher than that index. That means we must
    // be on the previous line
    int this_index, previous_line = interpreter_state.first_line;
    for (int i = interpreter_state.first_line; i < MAXLINE; i++) {
        // skip empty lines
        if (interpreter_state.lines[i] == NULL) continue;
        
        // get the index of the first statement on that line
        this_index = g_list_position(program, interpreter_state.lines[i]);
        
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

/* starts at the given number and looks forward until it finds
 that line or falls off the end. So find_line(0) will find the
 first line even if that's numbered 10. */
static GList *find_line(int linenumber)
{
    // negative numbers are not allowed
    if (linenumber < 0) {
        basic_error("Negative line in GOTO/GOSUB.");
        //exit(EXIT_FAILURE);
        return NULL;
    }
    
    // find this line or the next higher
    while ((interpreter_state.lines[linenumber] == NULL) &&
           (linenumber < MAXLINE))
        linenumber++;
    
    // if we fell off the end, exit
    if (linenumber == MAXLINE) {
        basic_error("Undefined line in find_line");
        //exit(EXIT_FAILURE);
        return NULL;
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
static GList *perform_statement(GList *L)
{
    // get the next statement to run, which, by default, is the next statement in the program
    // this may be changed GOTO, GOSUB, ON, IF...
    GList *next = g_list_next(L);
    
    // now process this statement
    statement_t *ps = L->data;
    if (ps) {
        switch (ps->type) {
            case BREAK:
                abort();
                break;

            case BYE:
				// unlike END, this exits BASIC entirely
                exit(EXIT_SUCCESS);
                break;

            case CLEAR:
				{
					// wipe out any variables and create a fresh list
					delete_variables();
					interpreter_state.values = g_tree_new(symbol_compare);
				}
                break;
                
            case CLS:
                // does nothing
                break;
                
            case DATA:
				// basically works like a REM, so just move on, all the logic is in the READ
                break;
                
            case DEF:
                // sets up a function, we simply copy the name, parameters and formula into storage
                {
                    function_definition(ps->parms.def.function, ps->parms.def.expression);
                }
                break;

            case DIM:
                // the parser has already pulled out the variable names, so all we have to
                // do here is loop over the list and call variable_value to initialize them
				{
					GList *L;
					for (L = ps->parms.dim; L != NULL; L = g_list_next(L)) {
						variable_t *pv = L->data;
						int type;
						variable_value(pv, &type);
					}
				}
                break;
                
            case END:
				// set the instruction pointer to null so it exits below
				next = NULL;
				break;
                
            case FOR:
				{
					forcontrol_t *new_for = malloc(sizeof(*new_for));
					either_t *lv;
					int type;
					
					new_for->variable = ps->parms._for.variable;
					new_for->begin = evaluate_expression(ps->parms._for.begin).number;
					new_for->end = evaluate_expression(ps->parms._for.end).number;
					if(ps->parms._for.step)
						new_for->step = evaluate_expression(ps->parms._for.step).number;
					else {
						if (new_for->begin < new_for->end)
							new_for->step = 1;
						else
							new_for->step = -1;
					}
					new_for->head = L;
					lv = variable_value(new_for->variable, &type);
					lv->d = new_for->begin;
					
					interpreter_state.forstack = g_list_append(interpreter_state.forstack, new_for);
				}
				break;
                
            case GOSUB:
				{
					gosubcontrol_t *new = malloc(sizeof(*new));
					
					new->returnpoint = g_list_next(L);
					interpreter_state.gosubstack = g_list_append(interpreter_state.gosubstack, new);
					next = find_line(evaluate_expression(ps->parms.gosub).number);
				}
				break;
                
            case GOTO:
				{
					next = find_line(evaluate_expression(ps->parms._goto).number);
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
                            for (GList *L = ps->parms._if.then_expression; L != NULL; L = g_list_next(L)) {
                                perform_statement(L);
                            }
						} else {
                            // if the THEN is not an expression, jump to that line
							next = find_line(ps->parms._if.then_linenumber);
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
					
					// first off, see if the first item in the list is a variable,
					// if so, that means there's nothing suppressing the prompt, so
					// we want to display it. we don't have to do that for other
					// items in the list because it's handled in the loop
					printitem_t *ppi= ps->parms.input->data;
					if (ppi->expression->type == variable)
						printf("?");
					
					// and now loop over what else we find on the line
					for (GList *I = ps->parms.input; I != NULL; I = g_list_next(I)) {
						either_t *value;
						int type;
						
						ppi = I->data;
						if (ppi->expression->type == variable) {
							char line[80];
							
							// see if we can get some data
							fflush(stdout);
							if (fgets(line, sizeof(line), stdin) != line)
								exit(EXIT_FAILURE);
							
							// we did, so complete the string
							line[strlen(line) - 1] = '\0';
							
							// find the storage for this variable, and assign the value
							value = variable_value(ppi->expression->parms.variable, &type);
							if (type == NUMBER) {
								sscanf(line, "%lg", &value->d);
							} else {
								value->s = g_string_new(line);
							}
						}
						// if it's not a variable, it's some sort of prompt, so print it
						else {
							print_expression(ppi->expression, NULL);
							// and if the sep is a comma, suppress the ?, otherwise add it
							if (ppi->separator != ',')
								printf("?");
						}
					}
				}
                break;
                
            case LET:
				{
					// this handles both the explicit and implicit LET
					either_t *stored_val;
					int type;
					value_t exp_val;
					
					// get the storage entry for this variable
					stored_val = variable_value(ps->parms.let.variable, &type);
					
					// evaluate the expression
					exp_val = evaluate_expression(ps->parms.let.expression);
					
					// make sure we got the right type, and assign it if we did
					if (exp_val.type == type) {
						if (type == STRING)
							stored_val->s = exp_val.string;
						else
							stored_val->d = exp_val.number;
					} else {
						// if the type we stored last time is different than this time...
						basic_error("Type mismatch");
					}
				}
                break;
                
            case NEXT:
				{
                    // this version does not precisely match MS, it always gets the last
                    // entry on the FOR stack and uses that variable, ignoring the variable
                    // that might have been entered in the source.
                    // FIXME: this is easy to fix, simply get the variable name from the FOR
                    //  stack and then check if it's the same as the one in the NEXT, error out
					forcontrol_t *pfc = g_list_last(interpreter_state.forstack)->data;
					either_t *lv;
					int type;
                    
					lv = variable_value(pfc->variable, &type);
					lv->d += pfc->step;
					if (((pfc->step < 0) && (lv->d >= pfc->end)) ||
						((pfc->step > 0) && (lv->d <= pfc->end))) {
                        /* Go back to the head of the loop */
						next = g_list_next(pfc->head);
					} else {
                        interpreter_state.forstack = g_list_remove(interpreter_state.forstack, pfc);
					}
				}
                break;
                
            case NEW:
                /* it's not entirely clear what this should do INSIDE a program, but... */
				{
					// wipe out any variables and create a new list
					delete_variables();
					interpreter_state.values = g_tree_new(symbol_compare);
					
					// clear out the program
					// TODO : do this!
				}
                break;
                
            case ON:
				{
					/* first we evaluate the expression */
					value_t val = evaluate_expression(ps->parms.on.expression);
					
					/* ON does an INT, and since a valid line is +ve, INT always rounds down... */
					int n = (int)floor(val.number);
					/* C arrays are zero-indexed, not 1, so... */
					--n;
					
					/* if it calced OK, see if we can find that entry in the list of numbers */
					GList *numslist;
					numslist = ps->parms.on.numbers;
					expression_t *item = g_list_nth_data(numslist, (guint)n);
					if (item == NULL) {
						// an IF statement simply runs the next statement if the condition fails,
						// likewise, if the ON value points to an item that is not in the number
						// list, if simply falls off to the next statement
						break;
					}
					
					/* we found the nth entry, so evaluate it */
					value_t lineval;
					lineval = evaluate_expression(item);
					
					/* turn it into a line number */
					int linenum = (int)floor(lineval.number);
					
					/* and then it's either GOTO or GOSUB... */
					if (ps->parms.on.type == GOTO) {
						next = find_line(linenum);
					} else {
						gosubcontrol_t *new = malloc(sizeof(*new));
						new->returnpoint = g_list_next(L);
						interpreter_state.gosubstack = g_list_append(interpreter_state.gosubstack, new);
						next = find_line(linenum);
					}
				}
                break;
                
            case POKE:
                // do nothing
                break;
                
            case PRINT:
				{
					GList *L;
					printitem_t *pp;
					
					// loop over the items in the print list
					for (L = ps->parms.print.item_list; L != NULL; L = g_list_next(L)) {
						pp = L->data;
						
						// if there's a USING, evaluate the format string it and print using it
						if (ps->parms.print.format) {
							value_t format_string;
                            format_string = evaluate_expression(ps->parms.print.format);
							print_expression(pp->expression, format_string.string->str);
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
					if (g_list_last(ps->parms.print.item_list))
						pp = (printitem_t *)(g_list_last(ps->parms.print.item_list)->data);
					else
						pp = NULL;
					
					// if there are no more items, or it's NOT a separator, do a CR
					if ((pp == NULL) || (pp->separator == 0)) {
						printf("\n");
                        interpreter_state.cursor_column = 0; // and reset this!
					}
				}
                break;
                
            case READ:
				{
					GList *LL;			/* destination variable list */
					
					if (interpreter_state.current_data_statement == NULL) {
						basic_error("No more DATA");
					}
					
					LL = ps->parms.read;
					while (LL) {
						either_t *lv;
						int type;
						value_t v;
						
						if (interpreter_state.current_data_element == NULL) {
							interpreter_state.current_data_statement = g_list_next(interpreter_state.current_data_statement);
							while (interpreter_state.current_data_statement != NULL) {
								if ((interpreter_state.current_data_statement->data != NULL) &&
									(((statement_t *)(interpreter_state.current_data_statement->data))->type == DATA))
									break;
								interpreter_state.current_data_statement = g_list_next(interpreter_state.current_data_statement);
							}
							interpreter_state.current_data_element = g_list_first(((statement_t *)(interpreter_state.current_data_statement->data))->parms.data);
						}
						lv = variable_value(LL->data, &type);
						v = evaluate_expression(interpreter_state.current_data_element->data);
						if (v.type == type) {
							if (type == STRING)
								lv->s = v.string;
							else
								lv->d = v.number;
						} else {
							//printf("Expected %s\n", (type == STRING) ? "string" : "number");
							basic_error("Type mismatch in READ");
						}
						
						LL = g_list_next(LL);
						interpreter_state.current_data_element = g_list_next(interpreter_state.current_data_element);
					}
				}
                break;
                
            case REM:
                // next is already good, so...
				break;
                
            case RESTORE:
				{
					// resets the DATA pointer
					// TODO: there versions that take a line number, and/or element number
					interpreter_state.current_data_statement = find_line(0);
					interpreter_state.current_data_element = NULL;
				}
                break;
                
            case RETURN:
				{
					gosubcontrol_t *pgc = g_list_last(interpreter_state.gosubstack)->data;
					next = pgc->returnpoint;
					interpreter_state.gosubstack = g_list_remove(interpreter_state.gosubstack, pgc);
				}
                break;
                
            case STOP:
                exit(EXIT_SUCCESS);
                break;
                
            case VARLIST:
                print_variables();
                break;
                
            default:
                printf("Unimplemented statement %d\n", ps->type);
                assert(0);
        } //end switch
    }
    // return the pointer to the next statement so you can just keep looping
    return next;
}

static gboolean is_string(gpointer key, gpointer value, gpointer user_data)
{
	variable_storage_t *data = (variable_storage_t *)value;
	int *tot = (int*)user_data;
    if(data->type == STRING) *tot += 1;
	return FALSE;
}
static gboolean is_single(gpointer key, gpointer value, gpointer user_data)
{
 	variable_storage_t *data = (variable_storage_t *)value;
	int *tot = (int*)user_data;
    if(data->type == NUMBER && strstr(key, "!") != NULL) *tot += 1;
	return FALSE;
}
static gboolean is_double(gpointer key, gpointer value, gpointer user_data)
{
	variable_storage_t *data = (variable_storage_t *)value;
	int *tot = (int*)user_data;
    if(data->type == NUMBER && strstr(key, "#") != NULL) *tot += 1;
	return FALSE;
}
static gboolean is_integer(gpointer key, gpointer value, gpointer user_data)
{
 	variable_storage_t *data = (variable_storage_t *)value;
	int *tot = (int*)user_data;
    if(data->type == NUMBER && strstr(key, "%") != NULL) *tot += 1;
	return FALSE;
}

/* variable tree walking methods, returning FALSE means "keep going" */
/* cheater method for printing out all the variable names */
static gboolean print_symbol(gpointer key, gpointer value, gpointer unused)
{
    printf("\n%s ", (char *)key);
    return FALSE;
}
/* used for VARLIST in those versions of BASIC that support it */
static void print_variables() {
    g_tree_foreach(interpreter_state.values, print_symbol, NULL);
    printf("\n\n");
}
/* used for CLEAR, NEW and similar instructions. */
static void delete_variables() {
    g_tree_destroy(interpreter_state.values);
}

/* the main loop for the program */
void run(void)
{
    // last line number we ran, used for tracing/stepping
    int last_line = interpreter_state.first_line;
    if (trace_lines)
        printf("[%i]\n", last_line);

    // very simple - perform_statement returns the next statement and the
    // main below set us up to point to the first one, so just call
    // that one function until you get a NULL
    while (interpreter_state.current_statement) {
        interpreter_state.current_statement = perform_statement(interpreter_state.current_statement);
        
        // trace, only on line changes
        if (trace_lines && last_line != current_line()) {
            last_line = current_line();
            printf("[%i]\n", last_line);
        }
    }
}

/* simple version info for --version command line option */
void print_version()
{
    puts("RetroBASIC 1.0\n");
}

void print_usage()
{
    puts("RetroBASIC 1.0\n");
}

/* prints out various statistics from the static code,
   or if the write_stats flag is on, writes them to a file */
void print_statistics()
{
    int lines_total, line_min, line_max;
    
    // start with line number stats
    lines_total = 0;
    line_max = MAXLINE + 1;
    line_min = -1;
	// just look for any entry with a list
    for(int i = 0; i < MAXLINE; i++) {
        if (interpreter_state.lines[i] != NULL) {
            lines_total++;
            if (i < line_max) line_max = i;
            if (i > line_min) line_min = i;
        }
    }
    
    // exit if there's no program
    if (lines_total == 0) {
        printf("\nNO PROGRAM TO EXAMINE\n\n");
        return;
    }
    
    // since the statements are run together as one long list, it's
    // easy to print out the total number, but not so easy to print
	// out the number per line. so this code checks each node to see
	// if the ->next is the first item on the next line
    int stmts_max = 0, diff = 0, next_num;
    GList *this, *next;
    GList *start = interpreter_state.lines[interpreter_state.first_line];
    
	for(int i = interpreter_state.first_line; i < MAXLINE - 1; i++) {
        // try again if this line is empty
        if(interpreter_state.lines[i] == NULL) continue;
        
		// otherwise get the statements on this line
        this = interpreter_state.lines[i];
        
        // and find the next non-empty line
        next_num = i + 1; // note to me, no, you can't i++ here!
        while ((interpreter_state.lines[next_num] == NULL) && (next_num < MAXLINE))
            next_num++;
        
        // if we ran off the end of the list, exit
        if(next_num == MAXLINE - 1) break;
        
        // otherwise we found the next line
        next = interpreter_state.lines[next_num];

        // now count the number of statements between them
        diff = g_list_position(start, next) - g_list_position(start, this);
        if(diff > stmts_max) stmts_max = diff;
	}
    
    // variables
    // finding the references in the code is non-trivial,
    // but we can look at the values after they've been
    // populated by running the program
    int num_total = g_tree_nnodes(interpreter_state.values);
    int num_int = 0, num_sng = 0, num_dbl = 0, num_str = 0;
    g_tree_foreach(interpreter_state.values, is_integer, &num_int);
    g_tree_foreach(interpreter_state.values, is_single, &num_sng);
    g_tree_foreach(interpreter_state.values, is_double, &num_dbl);
    g_tree_foreach(interpreter_state.values, is_single, &num_sng);
    g_tree_foreach(interpreter_state.values, is_string, &num_str);
	
    // output to screen if selected
    print_stats = 1;
    if(print_stats) {
        printf("\nLINE NUMBERS\n\n");
        printf("  total: %i\n", lines_total);
        printf("  first: %i\n", line_max);
        printf("   last: %i\n", line_min);
        
        printf("\nSTATEMENTS\n\n");
        printf("  total: %i\n", g_list_length(interpreter_state.lines[line_max]));
        printf(" max/ln: %i\n", stmts_max);
        printf("average: %2.2f\n", (double)g_list_length(interpreter_state.lines[line_max])/(double)lines_total);

        printf("\nVARIABLES\n\n");
        printf("  total: %i\n",num_total);
        printf("string : %i\n",num_str);
        printf("(nums) : %i\n",num_total-num_str-num_int-num_sng-num_dbl);
        printf("ints   : %i\n",num_int);
        printf("singles: %i\n",num_sng);
        printf("doubles: %i\n",num_dbl);

        printf("\nNUMERIC CONSTANTS\n\n");
        printf("  total: %i\n",numeric_constants_total);
        printf("    int: %i\n",numeric_constants_total - numeric_constants_float);
        printf("non-int: %i\n",numeric_constants_float);
        printf("  zeros: %i\n",numeric_constants_zero);
        printf("   ones: %i\n",numeric_constants_one);
        printf("  -ones: %i\n",numeric_constants_minus_one);
        printf("1 digit: %i\n",numeric_constants_one_digit);
        printf("2 digit: %i\n",numeric_constants_two_digit);
        printf("3 digit: %i\n",numeric_constants_three_digit);
        printf("4 digit: %i\n",numeric_constants_four_digit);
        printf("5 digit: %i\n",numeric_constants_five_digit);
        printf(" bigger: %i\n",numeric_constants_big);
        printf(" 1 byte: %i\n",numeric_constants_one_byte);
        printf(" 2 byte: %i\n",numeric_constants_two_byte);
        printf(" 3 byte: %i\n",numeric_constants_four_byte);
        printf("     10: %i\n",numeric_constants_10);
        printf("     16: %i\n",numeric_constants_16);
        printf("    256: %i\n",numeric_constants_256);

        printf("\nSTRING CONSTANTS\n\n");
        printf("  total: %i\n",string_constants_total);
        printf(" 1 char: %i\n",string_constants_one_byte);
        printf("2 chars: %i\n",string_constants_two_byte);
        printf("4 chars: %i\n",string_constants_four_byte);
        printf("8 chars: %i\n",string_constants_eight_byte);
        printf("16 char: %i\n",string_constants_sixteen_byte);
        printf(" bigger: %i\n",string_constants_big);
        printf("biggest: %i\n",string_constants_max);

        printf("\nBRANCHES\n\n");
        printf("  total: %i\n",linenum_constants_total);
        printf(" gosubs: %i\n",linenum_gosub_totals);
        printf("  gotos: %i\n",linenum_goto_totals);
        printf("  thens: %i\n",linenum_then_goto_totals);
        printf("    ons: %i\n",linenum_on_totals);
        printf("forward: %i\n",linenum_forwards);
        printf("bckward: %i\n",linenum_backwards);
    }
    if(write_stats) {
        //check that the file name is reasonable, and then try to open it
        FILE* fp = fopen(stats_file, "w+");
        if(!fp) return;

        fprintf(fp, "LINE NUMBERS,total,%i\n", lines_total);
        fprintf(fp, "LINE NUMBERS,first,%i\n", line_max);
        fprintf(fp, "LINE NUMBERS,last,%i\n", line_min);
        
        fprintf(fp, "STATEMENTS,total,%i\n", g_list_length(interpreter_state.lines[line_max]));
        fprintf(fp, "STATEMENTS,max/ln,%i\n", stmts_max);
        fprintf(fp, "STATEMENTS,average,%g\n", (double)g_list_length(interpreter_state.lines[line_max])/(double)lines_total);

        fprintf(fp, "VARIABLES,total,%i\n",num_total);
        fprintf(fp, "VARIABLES,string,%i\n",num_str);
        fprintf(fp, "VARIABLES,default,%i\n",num_total-num_str-num_int-num_sng-num_dbl);
        fprintf(fp, "VARIABLES,ints,%i\n",num_int);
        fprintf(fp, "VARIABLES,singles,%i\n",num_sng);
        fprintf(fp, "VARIABLES,doubles,%i\n",num_dbl);

        fprintf(fp, "NUMERIC CONSTANTS,total,%i\n",numeric_constants_total);
        fprintf(fp, "NUMERIC CONSTANTS,int,%i\n",numeric_constants_total - numeric_constants_float);
        fprintf(fp, "NUMERIC CONSTANTS,non-int,%i\n",numeric_constants_float);
        fprintf(fp, "NUMERIC CONSTANTS,zeros,%i\n",numeric_constants_zero);
        fprintf(fp, "NUMERIC CONSTANTS,ones,%i\n",numeric_constants_one);
        fprintf(fp, "NUMERIC CONSTANTS,-ones,%i\n",numeric_constants_minus_one);
        fprintf(fp, "NUMERIC CONSTANTS,1 digit,%i\n",numeric_constants_one_digit);
        fprintf(fp, "NUMERIC CONSTANTS,2 digit,%i\n",numeric_constants_two_digit);
        fprintf(fp, "NUMERIC CONSTANTS,3 digit,%i\n",numeric_constants_three_digit);
        fprintf(fp, "NUMERIC CONSTANTS,4 digit,%i\n",numeric_constants_four_digit);
        fprintf(fp, "NUMERIC CONSTANTS,5 digit,%i\n",numeric_constants_five_digit);
        fprintf(fp, "NUMERIC CONSTANTS,bigger,%i\n",numeric_constants_big);
        fprintf(fp, "NUMERIC CONSTANTS,1 byte,%i\n",numeric_constants_one_byte);
        fprintf(fp, "NUMERIC CONSTANTS,2 byte,%i\n",numeric_constants_two_byte);
        fprintf(fp, "NUMERIC CONSTANTS,3 byte,%i\n",numeric_constants_four_byte);
        fprintf(fp, "NUMERIC CONSTANTS,10,%i\n",numeric_constants_10);
        fprintf(fp, "NUMERIC CONSTANTS,16,%i\n",numeric_constants_16);
        fprintf(fp, "NUMERIC CONSTANTS,256,%i\n",numeric_constants_256);

        fprintf(fp, "STRING CONSTANTS,total,%i\n",string_constants_total);
        fprintf(fp, "STRING CONSTANTS,1 char,%i\n",string_constants_one_byte);
        fprintf(fp, "STRING CONSTANTS,2 chars,%i\n",string_constants_two_byte);
        fprintf(fp, "STRING CONSTANTS,4 chars,%i\n",string_constants_four_byte);
        fprintf(fp, "STRING CONSTANTS,8 chars,%i\n",string_constants_eight_byte);
        fprintf(fp, "STRING CONSTANTS,16 chars,%i\n",string_constants_sixteen_byte);
        fprintf(fp, "STRING CONSTANTS,bigger,%i\n",string_constants_big);
        fprintf(fp, "STRING CONSTANTS,biggest,%i\n",string_constants_max);

        fprintf(fp, "BRANCHES,total,%i\n",linenum_constants_total);
        fprintf(fp, "BRANCHES,gosubs,%i\n",linenum_gosub_totals);
        fprintf(fp, "BRANCHES,gotos,%i\n",linenum_goto_totals);
        fprintf(fp, "BRANCHES,thens,%i\n",linenum_then_goto_totals);
        fprintf(fp, "BRANCHES,ons,%i\n",linenum_on_totals);
        fprintf(fp, "BRANCHES,forward,%i\n",linenum_forwards);
        fprintf(fp, "BRANCHES,bckward,%i\n",linenum_backwards);
        
        fclose(fp);
    }
}

/* pretty bog-standard options processing based on getopt */
/* options are:
 
 -v/--version = print the version
 -h/--help = print the usage notes
 -f/--file = name of the program to run
 -t/--tabs = sets the number of columns per tab for comma-separated output
 -p/--print-stats = prints statistics in human form to the standard output
 -w/--write-stats = prints stats in machine form to the named file
 -i/--input-file = redirects INPUT statements to take values from the named file
 -o/--output-file = redirects PRINT statements to write to the named file
 -n/--no-run = doesn't run the file, just parses it (and optionally prints stats)
 -r/--random = seed the random number generator with the given value
 */
static struct option program_options[] =
{
    {"help", no_argument, NULL, 'h'},
    {"version", no_argument, NULL, 'v'},
    {"tabs", required_argument, NULL, 't'},
    {"random", required_argument, NULL, 'r'},
    {"input-file", required_argument, NULL, 'i'},
    {"output-file", required_argument,  NULL, 'o'},
    {"print-stats", no_argument, &print_stats, 1},
    {"write-stats", required_argument, NULL, 'w'},
    {"no-run", no_argument, &run_program, 'n'},
    {0, 0, 0, 0}
};
//static char usage[] = "usage: %s [-dmp] -f fname [-s sname] name [name ...]\n";

void parse_options(int argc, char *argv[])
{
    int c;
    int option_index = 0;
    
    while(1) {
        // eat an option and exit if we're done
        c = getopt_long(argc, argv, "hvf:i:o:pw:n", program_options, &option_index);
        if (c == -1) break;
        
        //testing
        printf ("option %s", program_options[option_index].name);
        if (optarg)
            printf (" with arg %s", optarg);
        
        switch (c) {
            case 0:
                // flag-setting options return 0 - these are p and n
                if (program_options[option_index].flag != 0)
                    break;
                printf ("\n");
                break;
                
            case 'h':
                print_usage();
                break;
                
            case 'v':
                print_version();
                break;
                
            case 'i':
                input_file = optarg;
                break;
                
            case 'o':
                print_file = optarg;
                break;
                
            case 'w':
                write_stats = 1;
                stats_file = optarg;
                break;
                
            case 'r':
                random_seed = strtol(optarg, 0, INT_MAX);

            case '?':
                /* getopt_long already printed an error message. */
                break;
                
            default:
                abort();
        }
    } // while
}

int main(int argc, char *argv[])
{
    extern int yyparse(void);
    extern FILE *yyin;
    
    // turn this on to add verbose debugging
    #if YYDEBUG
       yydebug = 1;
    #endif
    
    // parse the options and make sure we got a filename somewhere
    parse_options(argc, argv);
    
    // set up an empty tree to store variables and user functions as we find them
    interpreter_state.values = g_tree_new(symbol_compare);
    interpreter_state.functions = g_tree_new(symbol_compare);

    // open the file and run it through the parser, or use stdin
    yyin = fopen(argv[1], "r");
    if (yyin == NULL)
        yyin = stdin;
    yyparse();
    
    // run all the lines together into a single continuous list
    // by pointing the ->next for each line to the head of the next
    // non-empty line. that way we don't have to search through the line
    // array for the next non-null entry during the run loop, we just
	// keep stepping through the ->next until we fall off the end
    {
        // look for the first entry in the lines array with a non-empty statement list
        int first_line;
        for (first_line = 0;
             (first_line < MAXLINE) && (interpreter_state.lines[first_line] == NULL);
             first_line++);
        
        // that statement is going to be the head of the list when we're done
        GList *first_statement = interpreter_state.lines[first_line];
        
        // now find the next non-null line and contact it to the first one, and repeat
        for (int i = first_line + 1; (i < MAXLINE); i++) {
            if (interpreter_state.lines[i])
                first_statement = g_list_concat(first_statement, interpreter_state.lines[i]);
        }
        
        // and set the resulting list back into the first line
        // NOTE: do we need to do this? isn't this already there?
        interpreter_state.lines[first_line] = first_statement;
        interpreter_state.first_line = first_line;
        
        // a program runs from the first line, so...
        interpreter_state.current_statement = first_statement;          // the first statement
        interpreter_state.current_data_statement = first_statement;     // the DATA can point anywhere
        interpreter_state.current_data_element = NULL;                  // the element within the DATA is nothing
   }
    
    // cursor starts in col 0
    interpreter_state.cursor_column = 0;

    // seed the random
    if (random_seed >= 0)
        srand(random_seed);
    else
        srand((unsigned int)time(0));
    
    // and go!
    if (run_program)
        run();
    
    // we're done, print/write desired stats
    if (print_stats || write_stats)
        print_statistics();

    // and exit
    exit(EXIT_SUCCESS);
}

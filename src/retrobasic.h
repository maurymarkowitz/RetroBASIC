/* Interpreter (header) for RetroBASIC
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

#ifndef __RETROBASIC_H__
#define __RETROBASIC_H__

#include "stdhdr.h"

#define MAXLINE 32767
#define MAXSTRING 256

 /* variables */
 /* ultimately the only thing we store in the variable reference is
    its name and any dimensional size if it's an array.
    Values are stored in a private type in a separate area.
  */
typedef struct {
    GString *name;
    GList *subscripts;			/* subscripts, list of expressions */
} variable_t;

/* expressions */
typedef enum {
    number, string, variable, op, fn
} expression_type_t;

typedef struct expression_struct {
    expression_type_t type;
    union {
        double number;
        GString *string;
        variable_t *variable;   // also used for user-defined function names and parameters
        struct {
            int arity;
            int opcode;
            struct expression_struct *p[3]; // arity can be up to 3 in BASIC
        } op;
    } parms;
} expression_t;

/* printlists */
/* print lists are different from other lists in BASIC because they
   have three possible separators, nulls, commas and semis
 */
typedef struct {
    expression_t *expression;
    int separator;			/* ';' ',' or 0 */
} printitem_t;

/* every statement in the program gets a statement entry. the most
 basic forms are simply a type, which contains the token value. So
 something like a REM will generate an otherwise empty entry
 (although perhaps it should save the string?). Other statements
 can store additional parameters in the params union.
 */
typedef struct statement_struct {
    int type;
    union {
        expression_t *generic_parameter;
        GList *data; // list of values for data statements
        struct {
            variable_t *signature;
            expression_t *formula;
        } def;
        GList *dim; // list of variable definitions
        struct {
            variable_t *variable;
            expression_t *begin, *end, *step;
        } _for;
        expression_t *gosub;
        expression_t *_goto;
        struct {
            expression_t *condition;
            GList *then_expression;
            int then_linenumber; // implicit goto case
        } _if;
        GList *input;
        struct {
            variable_t *variable;
            expression_t *expression;
        } let;
        struct {
            int type; /* GOTO or GOSUB */
            expression_t *expression;
            GList *numbers;
        } on;
        variable_t *next;
        struct {
            expression_t *format;
            GList *item_list;
        } print;
        GList *read;
        GString *rem;
//        struct {
//            GList *numbers;
//        } _sys;
    } parms;
} statement_t;

/* runtime stacks */
/* used for tracking GOSUB, FOR/NEXT, etc. It is not clear that there needs to
   be two separate types here, as this might making popping a FOR from an early
   RETURN more difficult?
 */
typedef struct {
    GList *head;
    variable_t *index_variable;
    double begin, end, step;
} forcontrol_t;

typedef struct {
    GList *returnpoint;
} gosubcontrol_t;

/* this is the main state for the interpreter, largely consisting of the lines of
   code, a pointer to the first line for easy lookup, a pointer to the current
   statement, a list of variables and their values, and the runtime stack for
   GOSUB and FOR/NEXT */
typedef struct {
    GList *lines[MAXLINE];          // the lines in the program, stored as an array of statement lists
    int first_line;		            // index of the first line in the lines array
    GList *current_statement;       // currently executing statement
    GList *next_statement;          // next statement to run, might change for GOTO and such
    GList *current_data_statement;	// current 'DATA' statement
    GList *current_data_element;	// current 'DATA' expression within psd
    GTree *values;		            // name/value pairs used to store variable *values*
    GTree *functions;               // name/expression pairs for user-defined functions
    GList *forstack;	            // of forcontrol_t
    GList *gosubstack;	            // of gosubcontrol_t
    int cursor_column;              // current column of the output cursor
    int running_state;              // is the program running (1), paused/stopped (0)
} interpreterstate_t;

/* and here's the link to an instance of interpstate_t defined in the c side */
extern interpreterstate_t interpreter_state;

/* the only piece of the interpreter the parser needs to know about is the variable table */
void insert_variable(variable_t *variable);

/* additional externs used for the static analyzer, used in parse.y */
extern int variables_total;
extern int variables_default;
extern int variables_int;
extern int variables_float;
extern int variables_double;
extern int variables_string;
extern int numeric_constants_total;
extern int numeric_constants_float;
extern int numeric_constants_zero;
extern int numeric_constants_one;
extern int numeric_constants_minus_one;
extern int numeric_constants_one_digit;
extern int numeric_constants_two_digit;
extern int numeric_constants_three_digit;
extern int numeric_constants_four_digit;
extern int numeric_constants_five_digit;
extern int numeric_constants_big;
extern int numeric_constants_one_byte;
extern int numeric_constants_two_byte;
extern int numeric_constants_four_byte;
extern int numeric_constants_10;
extern int numeric_constants_16;
extern int numeric_constants_256;
extern int string_constants_total;
extern int string_constants_one_byte;
extern int string_constants_two_byte;
extern int string_constants_four_byte;
extern int string_constants_eight_byte;
extern int string_constants_sixteen_byte;
extern int string_constants_big;
extern int string_constants_max;
extern int linenum_constants_total;
extern int linenum_forwards;
extern int linenum_backwards;
extern int linenum_goto_totals;
extern int linenum_then_goto_totals;
extern int linenum_gosub_totals;
extern int linenum_on_totals;
extern int for_loops_total;
extern int for_loops_step_1;
extern int for_loops_all_constant;

#endif

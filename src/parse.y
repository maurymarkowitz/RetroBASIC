%{
/* Parser for RetroBASIC
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

 /* used to track the line number being processed so
    that errors can report it */
static double errline;

void yyerror(const char *message)
{
  fprintf(stderr, "Syntax error at line %g: %s\n", errline, message);
  exit(1);
}

int yylex(void);

static statement_t *make_statement(int t)
{
  statement_t *new = malloc(sizeof(*new));
  new->type = t;
  return new;
}

static expression_t *make_expression(expression_type_t t)
{
  expression_t *new = malloc(sizeof(*new));
  new->type = t;
  return new;
}

static expression_t *make_operator(int arity, int o)
{
  expression_t *new = make_expression(op);
  new->parms.op.o = o;
  new->parms.op.arity = arity;
  return new;
}

#define YYDEBUG 1

 /************************************************************************/

%}

 /* Bison declarations */

 //%define parse.error verbose

%union {
  double d;
  int i;
  GString *s;
  GList *l;
  statement_t *statement;
  expression_t *expression;
  variable_t *variable;
}

%type <l> program line statements
%type <l> printlist exprlist varlist //assignlist //numlist
%type <i> printsep binary_op comparison_op e2op term unary_op fn_1 fn_2 fn_x
%type <expression> expression expression0 expression1 expression2 expression3 expression4 function factor
%type <statement> statement
%type <variable> variable user_function

%token <d> NUMBER, DOUBLE, SINGLE, INTEGER
%token <s> STRING
%token <s> VARIABLE_NAME
%token <s> FUNCTION_NAME

%token BREAK
%token BYE
%token CALL
%token CLEAR
%token CLS
%token CMD
%token DATA
%token DEF
%token DIM
%token END
%token EXIT
%token FOR
%token GET
%token GOSUB
%token GOTO
%token IF
%token INPUT
%token LET
%token LIST
%token NEXT
%token NEW
%token ON
%token PEEK
%token POKE
%token POP
%token PRINT
%token PUT
%token READ
%token REM
%token RESTORE
%token RETURN
%token RUN
%token SHORTREM
%token STEP
%token STOP
%token SYS
%token THEN
%token TO
%token USING
%token VARLIST
%token WAIT

 /* putting these down here for clarity, they are the PRINT# etc. */
%token OPEN CLOSE STATUS
%token PRINT_FILE
%token INPUT_FILE
%token GET_FILE
%token PUT_FILE

%token _ABS SGN
%token ATN COS SIN TAN
%token CLOG EXP LOG SQR
%token RND
%token INT FIX CINT CSNG CDBL // fix=SGN(x)*INT(ABS(x))

%token ASC
%token LEFT MID RIGHT
%token LEN STR VAL CHR

%token AND OR NOT XOR
%token CMP_LE CMP_GE CMP_NE CMP_HASH /* we keep hash separate for LISTing purposes */

%token FRE
%token SPC
%token TAB
%token POS
%token USR

%%

/* Grammar rules */
program:
    line
	|
	program '\n' line
	|
    program error '\n'
	;

line:
	/* can be nothing but the CR captured above */
	{
	}
	|
    // keep track of the line number as we parse so we can report offending lines
	NUMBER { errline = $1; } statements
	{
	  interpreter_state.lines[(int)$1] = $3;
	}       
	;

statements:
	statement
	{
	  $$ = g_list_prepend(NULL, $1);
	}
	|
    statement ':' statements
    {
	  $$ = g_list_prepend($3, $1);
    }
	;

statement:
	/* can be empty, in which case we remove it */
    // NOTE: should we? or should we insert a placeholder?
    {
	  $$ = NULL;
	}
    |
    BREAK
    {
      statement_t *new = make_statement(BREAK);
      $$ = new;
    }
	|
	BYE
	{
	  statement_t *new = make_statement(BYE);
	  $$ = new;
	}
    |
    CALL
    {
      statement_t *new = make_statement(CALL);
      $$ = new;
    }
    |
    CLS
    {
      statement_t *new = make_statement(CLS);
      $$ = new;
    }
    |
    CMD
    {
      statement_t *new = make_statement(CMD);
      $$ = new;
    }
	|
    /* DATA can have any type in it, but it is unlikely true expressions are allowed, although we allow them here */
	DATA exprlist
    {
	  statement_t *new = make_statement(DATA);
	  new->parms.data = $2;
	  $$ = new;
	}
	|
	DEF user_function '=' expression
	{
	  statement_t *new = make_statement(DEF);
      new->parms.def.function = $2;
      new->parms.def.expression = $4;
	  $$ = new;
	}
	|
	DIM varlist
	{
	  statement_t *new = make_statement(DIM);
	  new->parms.dim = $2;
	  $$ = new;
	}
	|
	END
	{
	  statement_t *new = make_statement(END);
	  $$ = new;
	}
    |
    EXIT
    {
      statement_t *new = make_statement(EXIT);
      $$ = new;
    }
	|
	FOR variable '=' expression TO expression
	{
	  statement_t *new = make_statement(FOR);
	  new->parms._for.variable = $2;
	  new->parms._for.begin = $4;
	  new->parms._for.end = $6;
	  new->parms._for.step = NULL;
	  $$ = new;
	}
	|
	FOR variable '=' expression TO expression STEP expression
	{
	  statement_t *new = make_statement(FOR);
	  new->parms._for.variable = $2;
	  new->parms._for.begin = $4;
	  new->parms._for.end = $6;
	  new->parms._for.step = $8;
	  $$ = new;
	}
	|
	GOSUB expression
	{
	  statement_t *new = make_statement(GOSUB);
	  new->parms.gosub = $2;
	  $$ = new;
      
      /* static analyzer */
      linenum_constants_total++;
      linenum_gosub_totals++;
      if ($2->parms.number) {
          if ($2->parms.number > errline) {
              linenum_forwards++;
          } else {
              linenum_backwards++;
          }
      }
    }
	|
	GOTO expression
	{
	  statement_t *new = make_statement(GOTO);
	  new->parms._goto = $2;
	  $$ = new;
      
      /* static analyzer */
      linenum_constants_total++;
      linenum_goto_totals++;
      if ($2->parms.number) {
          if ($2->parms.number > errline) {
              linenum_forwards++;
          } else {
              linenum_backwards++;
          }
      } else {
          // formula case?
      }
	}
	|
	INPUT printlist
	{
	  statement_t *new = make_statement(INPUT);
	  new->parms.input = $2;
	  $$ = new;
	}
	|
	IF expression THEN NUMBER
    {
	  statement_t *new = make_statement(IF);
	  new->parms._if.condition = $2;
	  new->parms._if.then_expression = NULL;
	  new->parms._if.then_linenumber = $4;
	  $$ = new;
      
      /* static analyzer */
      // this handles the implicit GOTO case, GOSUBs are always explicit so they are caught in the next rule
      linenum_constants_total++;
      linenum_then_goto_totals++;
      if ($2->parms.number) {
          if ($2->parms.number > errline) {
              linenum_forwards++;
          } else {
              linenum_backwards++;
          }
      } else {
          // formula case?
      }
	}
	|
	IF expression THEN statements // yes, statement**s**, they all run or don't run as a group in MS
	{
	  statement_t *new = make_statement(IF);
	  new->parms._if.condition = $2;
	  new->parms._if.then_expression = $4;
	  new->parms._if.then_linenumber = 0;
	  $$ = new;
	}
	|
	LET variable '=' expression /* visible LET, invisible LET is at the bottom */
	{
	  statement_t *new = make_statement(LET);
	  new->parms.let.variable = $2;
	  new->parms.let.expression = $4;
	  $$ = new;
	}
	|
	NEXT variable
	{
	  statement_t *new = make_statement(NEXT);
	  new->parms.next = $2;
	  $$ = new;
	}
    |
    NEXT /* later versions of MS allowed the variable to be ignored */
    {
      statement_t *new = make_statement(NEXT);
      new->parms.next = NULL;
      $$ = new;
    }
	|
	ON expression GOTO exprlist
	{
	  statement_t *new = make_statement(ON);
	  new->parms.on.type = GOTO;
	  new->parms.on.expression = $2;
	  new->parms.on.numbers = $4;
	  $$ = new;
      
      linenum_constants_total++;
      linenum_on_totals++;
	}
	|
	ON expression GOSUB exprlist
	{
	  statement_t *new = make_statement(ON);
	  new->parms.on.type = GOSUB;
	  new->parms.on.expression = $2;
	  new->parms.on.numbers = $4;
	  $$ = new;
      
      linenum_constants_total++;
      linenum_on_totals++;
    }
    |
    POKE expression ',' expression
    {
      // since we don't actually perform the poke, we toss the parameters
      statement_t *new = make_statement(POKE);
      $$ = new;
    }
    |
    POP
    {
      statement_t *new = make_statement(POP);
      $$ = new;
    }
	|
	PRINT printlist
	{
	  statement_t *new = make_statement(PRINT);
	  new->parms.print.format = NULL;
	  new->parms.print.item_list = $2;
	  $$ = new;
	}
	|
	PRINT USING expression ';' printlist
	{
	  statement_t *new = make_statement(PRINT);
	  new->parms.print.format = $3;
	  new->parms.print.item_list = $5;
	  $$ = new;
	}
	|
	READ varlist
	{
	  statement_t *new = make_statement(READ);
	  new->parms.read = $2;
	  $$ = new;
	}
	|
    REM
	{
	  statement_t *new = make_statement(REM);
	  new->parms.rem = yylval.s;
	  $$ = new;
	}	
	|
	RESTORE /* some basics allow a parameter here, representing a line number in some or an ordinal */
	{
	  statement_t *new = make_statement(RESTORE);
	  $$ = new;
	}
	|
	RETURN
	{
	  statement_t *new = make_statement(RETURN);
	  $$ = new;
	}
    |
    SHORTREM /* FIXME: this should also store the indicator character in .rem */
    {
      statement_t *new = make_statement(REM);
      new->parms.rem = yylval.s;
      $$ = new;
    }
	|
	STOP
	{
	  statement_t *new = make_statement(STOP);
	  $$ = new;
	}
    |
    SYS expression /* same as CALL */
    {
      statement_t *new = make_statement(SYS);
      $$ = new;
    }
	|
	VARLIST /* lists out all the variables and their values */
	{
	  statement_t *new = make_statement(VARLIST);
	  $$ = new;
	}
    |
    WAIT exprlist /* watches a memory location, does nothing here so ignore the list */
    {
      statement_t *new = make_statement(WAIT);
      $$ = new;
    }
	|
	variable '=' expression /* invisible LET, visible LET is above */
	{
	  statement_t *new = make_statement(LET);
	  new->parms.let.variable = $1;
	  new->parms.let.expression = $3;
	  $$ = new;
	}
	;

 /* precedence in RetroBASIC is handled through this
    pattern tree, but it is not clear that is the best solution
  */
expression: expression0;

expression0:
	expression1
	|
	expression0 binary_op expression1
	{
	  expression_t *new = make_operator(2, $2);
	  new->parms.op.p[0] = $1;
	  new->parms.op.p[1] = $3;
	  $$ = new;
	}
	;

binary_op:
    AND { $$ = AND; } |
    OR  { $$ = OR;  }
    ;

expression1:
	expression2
	|
	expression1 comparison_op expression2
	{
	  expression_t *new = make_operator(2, $2);
	  new->parms.op.p[0] = $1;
	  new->parms.op.p[1] = $3;
	  $$ = new;
	}
	;

comparison_op:
    '=' { $$ = '='; } |
    '<' { $$ = '<'; } |
    '>' { $$ = '>'; } |
    CMP_LE { $$ = CMP_LE; } |
    CMP_GE { $$ = CMP_GE; } |
    CMP_NE { $$ = CMP_NE; } |
    CMP_HASH { $$ = CMP_HASH; }
	;

expression2:
	expression3
	|
	expression2 e2op expression3
	{
	  expression_t *new = make_operator(2, $2);
	  new->parms.op.p[0] = $1;
	  new->parms.op.p[1] = $3;
	  $$ = new;
	}
	;

e2op:   '+' { $$ = '+'; } |
        '-' { $$ = '-'; } ;

expression3:
	expression4
	|
	expression3 term expression4
	{
	  expression_t *new = make_operator(2, $2);
	  new->parms.op.p[0] = $1;
	  new->parms.op.p[1] = $3;
	  $$ = new;
	}
	;

term:   '*' { $$ = '*'; } |
        '/' { $$ = '/'; } |
        '^' { $$ = '^'; } ;

expression4:
	function
	|
	unary_op function
	{
	  expression_t *new = make_operator(1, $1);
	  new->parms.op.p[0] = $2;
	  $$ = new;
	}
	;

unary_op:
    '-' { $$ = '-'; } |
    NOT { $$ = NOT; }
    ;

function:
	factor
	|
	fn_1 '(' expression ')'
	{
	  expression_t *new = make_operator(1, $1);
	  new->parms.op.p[0] = $3;
	  $$ = new;
	}
	|
	fn_2 '(' expression ',' expression ')'
	{
	  expression_t *new = make_operator(2, $1);
	  new->parms.op.p[0] = $3;
	  new->parms.op.p[1] = $5;
	  $$ = new;
	}
    /* multi-arity function being called with two inputs... */
    |
    fn_x '(' expression ',' expression ')'
    {
      expression_t *new = make_operator(2, $1);
      new->parms.op.p[0] = $3;
      new->parms.op.p[1] = $5;
      $$ = new;
    }
    /* ...or three */
	|
	fn_x '(' expression ',' expression ',' expression ')'
	{
	  expression_t *new = make_operator(3, $1);
	  new->parms.op.p[0] = $3;
	  new->parms.op.p[1] = $5;
      new->parms.op.p[2] = $7;
	  $$ = new;
	}
	;

 /* arity-1 functions */
fn_1:
   _ABS { $$ = _ABS; } |
	ATN  { $$ = ATN; } |
	CHR  { $$ = CHR; } |
	CLOG { $$ = CLOG;} |
	COS  { $$ = COS; } |
    EXP  { $$ = EXP; } |
    FRE  { $$ = FRE; } |
	INT  { $$ = INT; } |
    LEN  { $$ = LEN; } |
    STR  { $$ = STR; } |
	LOG  { $$ = LOG; } |
    RND  { $$ = RND; } |
    SGN  { $$ = SGN; } |
	SIN  { $$ = SIN; } |
	SPC  { $$ = SPC; } |
	SQR  { $$ = SQR; } |
	TAB  { $$ = TAB; } |
	VAL  { $$ = VAL; } |
    USR  { $$ = USR; }
    ;
	
 /* arity-2 functions */
fn_2:
    LEFT { $$ = LEFT; } |
    RIGHT { $$ = RIGHT; }
	;

 /* arity-2 or 3 functions */
fn_x:
    MID { $$ = MID; };

 /* ultimately all expressions end up here in factor, which is either a
    constant value, a variable value, or a parened expression. in
    all cases, the result of the expression is a value. most books on
    language design call this level a "factor", so we'll do the same. */
factor:
	NUMBER
	{
      /* actual parsing code */
	  expression_t *new = make_expression(number);
	  new->parms.number = $1;
	  $$ = new;
      
      /* static analyzer code */
      /* numbers here are not *all* of numbers in a program, line numbers
         (for instance) don't end up here. This *is* what we want for the
         analyzer.
         This means we have to track line numbers separately, like in the
         case of GOTO etc. This will, however, capture all the numbers found
         in expressions, PRINT statements, user formulas, POKEs, etc.
       */
      numeric_constants_total++;
      
      /* basic sizes for ints */
      double num = new->parms.number;
      if (floorf(num) == num) {
          // count decimal digits
          if (num == 0) {
              numeric_constants_zero++;
          } else if (num == 1) {
              numeric_constants_one++;
          } else if (num == -1) {
              numeric_constants_minus_one++;
          } else if (num >= -9 && num <= 9) {
              numeric_constants_one_digit++; // note: not 1 or zero
          } else if (num >= -99 && num <= 99) {
              numeric_constants_two_digit++;
          } else if (num >= -999 && num <= 999) {
              numeric_constants_three_digit++;
          } else if (num >= -9999 && num <= 9999) {
              numeric_constants_four_digit++;
          } else if (num >= -99999 && num <= 99999) {
              numeric_constants_five_digit++;
          } else {
              numeric_constants_big++;
          }
          
          // count number of bytes separately
          if (num >= -128 && num <= 256) {
              numeric_constants_one_byte++;
          } else if (num >= -32767 && num <= 65536) {
              numeric_constants_two_byte++;
          } else if (num >= INT_MIN && num <= INT_MAX) {
              /* this one is probably redundant! */
              numeric_constants_four_byte++;
          }
          
          // and look for a few other key ones
          if (num == 10) {
              numeric_constants_10++;
          } else if (num == 16) {
              numeric_constants_16++;
          } else if (num == 256) {
              numeric_constants_256++;
          }
      }
      /* everything else is a float */
      else {
          numeric_constants_float++;
      }
	}
	|
	STRING
	{
	  expression_t *new = make_expression(string);
	  new->parms.string = $1;
	  $$ = new;
      
      /* static analyzer code */
      string_constants_total++;
      if ($1->len == 1) {
          string_constants_one_byte++;
      } else if ($1->len == 2) {
        string_constants_two_byte++;
      } else if ($1->len <= 4) {
        string_constants_four_byte++;
      } else if ($1->len <= 8) {
        string_constants_eight_byte++;
      } else if ($1->len <= 16) {
        string_constants_sixteen_byte++;
      } else {
          string_constants_big++;
      }
      if ($1->len > string_constants_max) string_constants_max = (int)$1->len;
	}
	|
	variable
	{
	  expression_t *new = make_expression(variable);
	  new->parms.variable = $1;
	  $$ = new;
	}
    |
    user_function
    {
      expression_t *new = make_expression(fn);
      new->parms.variable = $1;
      $$ = new;
    }
	|
	'(' expression ')'
	{
	  $$ = $2;
	}
	;

 /* functions MUST have at least the empty parameter list
    in Commodore BASIC, you can only have a single parameter, BBC seems to allow three
  */
user_function:
    FUNCTION_NAME '(' exprlist ')'
    {
      variable_t *new = malloc(sizeof(*new));
      new->name = $1;
      new->sub = $3;
      $$ = new;
    }

 /* variables may contain an array reference or parameter list for functions */
variable:
    VARIABLE_NAME
    {
	  variable_t *new = malloc(sizeof(*new));
	  new->name = $1;
	  new->sub = NULL;
	  $$ = new;
      
      /* add it to the interpreter's variable list for the analyizer*/
      insert_variable(new);
	}
	|
    VARIABLE_NAME '(' exprlist ')'
	{
	  variable_t *new = malloc(sizeof(*new));
	  new->name = $1;
	  new->sub = $3;
	  $$ = new;

      /* add it to the interpreter's variable list for the analyizer*/
      insert_variable(new);
    }

 /* a null printlist is valid, it means "new line" */
printlist:
    {
	  $$ = NULL;
    }
    |
	expression
	{
	  printitem_t *new = malloc(sizeof(*new));
	  new->expression = $1;
	  new->separator = 0;
	  $$ = g_list_prepend(NULL, new);
	}
    |
    // this handles MS semi-is-the-same as nothing, PRINT"I="I
    expression printlist
    {
      printitem_t *new = malloc(sizeof(*new));
      new->expression = $1;
      new->separator = 0;
      $$ = g_list_prepend($2, new);
    }
    |
	expression printsep printlist
	{
	  printitem_t *new = malloc(sizeof(*new));
	  new->expression = $1;
	  new->separator = $2;
	  $$ = g_list_prepend($3, new);
	}
    |
	// this is found in the BCG "bug.bas", it's a print with a *leading* semi
    printsep printlist
    {
      printitem_t *new = malloc(sizeof(*new));
      new->expression = NULL;
      new->separator = $1;
      $$ = g_list_prepend($2, new);
    }
	;

printsep:
	','
    {
	  $$ = ',';
	}
    |
	';'
    {
	  $$ = ';';
	}
    ;
	
 /* used in lots of places that take a list of expressions, functions, DATA, defn, etc. */
exprlist:
	expression
	{
	  $$ = g_list_prepend(NULL, $1);
	}
	|
	exprlist ',' expression
	{
	  $$ = g_list_append($1, $3);
	}
	;
	
 /* used only in PATB style multiple-assignment LETs */
 /* not currently used 
 assignlist:
	variable '=' expression
	{
	  $$ = g_list_prepend($1, $3);
	}
	|
	assignlist variable '=' expression ',' 
	{
	  $$ = g_list_append($3, $5);
	}
	;
	*/

 /* used in READ statements and DEFs */
varlist:
	variable
	{
	  $$ = g_list_prepend(NULL, $1);
	}
	|
	varlist ',' variable
	{
	  $$ = g_list_append($1, $3);
	}
	;

 /* used in the ON syntax for the list of line numbers
    Not currently used, re-using expression instead because that's
    a pointer so its easy to put into the list. however, we could
    take the number, INT it, and the put that into the pointer
numlist:
	NUMBER
	{
	  $$ = g_list_prepend(NULL, &($1));
	}
	|
	numlist ',' NUMBER
	{
	  $$ = g_list_append($1, &($3));
	}
	;
	*/

%%

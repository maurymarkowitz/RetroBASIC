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
#include "statistics.h"

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

static expression_t *make_expression(expression_type_e t)
{
  expression_t *new = malloc(sizeof(*new));
  new->type = t;
  return new;
}

static expression_t *make_operator(int arity, int o)
{
  expression_t *new = make_expression(op);
  new->parms.op.opcode = o;
  new->parms.op.arity = arity;
  return new;
}

#define YYDEBUG 1

 /************************************************************************/

%}

 /* Bison declarations */

  // %define parse.error verbose
  // %define parse.trace true

%union {
  double d;
  int i;
  char *s;
  list_t *l;
  statement_t *statement;
  expression_t *expression;
  variable_reference_t *variable;
}

%type <l> program line statements
%type <l> printlist exprlist varlist slicelist //assignlist
%type <i> printsep binary_op comparison_op e2op term unary_op fn_0 fn_1 fn_2 fn_x
%type <expression> expression expression0 expression1 expression2 expression3 expression4 function factor
%type <statement> statement
%type <variable> variable user_function

 /* make sure STRING is before the numbers, so you can test all numbers as > STRING */
%token <s> STRING
%token <d> NUMBER DOUBLE SINGLE INTEGER
%token <s> VARIABLE_NAME
%token <s> FUNCTION_NAME
%token <s> HEX_STR OCT_STR BIN_STR

 /* primary statements and commands */
%token REM
%token QUOTEREM
%token BANGREM
%token BYE
%token CLEAR
%token CLR
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
%token OF
%token ON
%token PRINT
%token PUT
%token READ
%token RESTORE
%token RETURN
%token RUN
%token STEP
%token STOP
%token THEN
%token TO
%token USING
%token WAIT   // Altair version here, but perhaps should be PAUSE synonym

 /* putting these down here for clarity, they are the PRINT# etc. */
%token OPEN CLOSE STATUS
%token PRINT_FILE
%token INPUT_FILE
%token GET_FILE
%token PUT_FILE

 /* some later additions and custom stuff */
%token CALL
%token CLS
%token CMD
%token OPTION
%token BASE
%token PEEK
%token POKE
%token POP
%token RANDOMIZE
%token SYS
%token VARLIST
%token PAUSE
%token SLEEP /* BASIC-PLUS variation */

 /* common math functions */
%token ABS SGN
%token CLOG EXP LOG SQR
%token PI     // pseudo-value/function
%token RND
%token INT FIX FRAC // fix=SGN(x)*INT(ABS(x)), frac=A-INT(A)
%token ROUND  // two versions, round-to-int and round-to-place
%token CINT CSNG CDBL
%token MOD MOD_INT DIV

 /* trig set */
%token COS SIN ATN
%token ACS ASN TAN
%token COSH SINH TANH

 /* string functions */
%token ASC
%token LEFT MID RIGHT
%token LEN STR VAL CHR
%token SEG SUBSTR
%token INSTR
%token INKEY

 /* boolean operations and comparisons */
%token AND OR NOT XOR EQV IMP
%token CMP_LE CMP_GE CMP_NE CMP_HASH /* we keep hash separate for LISTing purposes */

 /* system functions */
%token ADR
%token FRE
%token SPC
%token TAB
%token POS
%token USR
%token LIN /* from HP, a vertical version of TAB */

 /* type definitions added circa 1979 */
%token DEFSTR DEFINT DEFSNG DEFDBL

 /* Dartmouth-style string manipulation */
%token CHANGE
 /* otherwise identical command from HP */
%token CONVERT
 /* and some later string-related additions */
%token UCASE LCASE
 /* string builders */
%token STRNG

 /* time and date patterned on MS style */
%token TIME
%token TIME_STR

 /* hex, oct and binary strings */
%token HEX OCT BIN
%token HEXSTR OCTSTR BINSTR

/* array utilities */
%token UBOUND LBOUND

 /* line labels, procedures, etc. */
%token LABEL

/* matrix set */
%token MAT
%token MATPRINT
%token MATINPUT
%token MATREAD
%token MATGET /* GET and PUT not currently supported */
%token MATPUT
%token MATZER
%token MATCON
%token MATIDN
%token MATTRN
%token MATINV
%token MATDET

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
  /* can be nothing but the CR captured above
   FIXME: blank lines appear to cause errors at runtime */
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
    $$ = lst_prepend(NULL, $1);
  }
  |
  statement ':' statements
  {
    $$ = lst_prepend($3, $1);
  }
  |
  statements QUOTEREM
  {
    $$ = lst_prepend($1, NULL);
  }
  |
  statements BANGREM
  {
    $$ = lst_prepend($1, NULL);
  }
  ;

statement:
  /* can be empty, in which case we remove it */
  // NOTE: should we? or should we insert a placeholder?
  {
    $$ = NULL;
  }
  |
  REM
  {
    statement_t *new = make_statement(REM);
    new->parms.rem = yylval.s;
    $$ = new;
  }
  |
  QUOTEREM
  {
    statement_t *new = make_statement(QUOTEREM);
    new->parms.rem = yylval.s;
    $$ = new;
  }
  |
  BANGREM
  {
    statement_t *new = make_statement(BANGREM);
    new->parms.rem = yylval.s;
    $$ = new;
  }
  |
  BYE
  {
    statement_t *new = make_statement(BYE);
    $$ = new;
  }
  |
  CALL expression
  {
    statement_t *new = make_statement(CALL);
    $$ = new;
  }
  |
  CHANGE variable TO variable
  {
    statement_t *new = make_statement(CHANGE);
    new->parms.change.var1 = $2;
    new->parms.change.var2 = $4;
    $$ = new;
  }
  |
  CONVERT variable TO variable
  {
    statement_t *new = make_statement(CONVERT);
    new->parms.change.var1 = $2;
    new->parms.change.var2 = $4;
    $$ = new;
  }
  |
  CLEAR
  {
    statement_t *new = make_statement(CLEAR);
    $$ = new;
  }
  |
  CLR
  {
    statement_t *new = make_statement(CLEAR);
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
    new->parms.def.signature = $2;
    new->parms.def.formula = $4;
    $$ = new;
  }
  |
  DEFDBL varlist
  {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = $2;
    new->parms.deftype.type = DOUBLE;
    $$ = new;
  }
  |
  DEFINT varlist
  {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = $2;
    new->parms.deftype.type = INTEGER;
    $$ = new;
  }
  |
  DEFSNG varlist
  {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = $2;
    new->parms.deftype.type = SINGLE;
    $$ = new;
  }
  |
  DEFSTR varlist
  {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = $2;
    new->parms.deftype.type = STRING;
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
    
    /* static analyser */
    for_loops_total++;
    for_loops_step_1++;
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
  
    /* static analyser - consider anything with a STEP special even if it is a 1 */
    for_loops_total++;
  }
  |
  GOSUB NUMBER
  {
    statement_t *new = make_statement(GOSUB);
    expression_t *exp = make_expression(number);
    exp->parms.number = $2;
    new->parms._goto = exp;
    $$ = new;
      
    /* static analyzer */
    linenum_gosub_totals++;
    linenum_constants_total++;
    if ($2 == errline) {
      linenum_same_line++;
    } else if ($2 > errline) {
      linenum_forwards++;
    } else {
      linenum_backwards++;
    }
  }
  |
  GOSUB expression
  {
    statement_t *new = make_statement(GOSUB);
    new->parms.gosub = $2;
    $$ = new;
      
    /* static analyzer */
    linenum_gosub_totals++;
    linenum_constants_total++;
    if ($2->parms.number) {
      if ($2->parms.number == errline) {
        linenum_same_line++;
      } else if ($2->parms.number > errline) {
          linenum_forwards++;
      } else {
          linenum_backwards++;
      }
    }
  }
  |
  GOSUB expression OF exprlist // this is the alternative form of ON..GOSUB seen in some dialects
  {
    statement_t *new = make_statement(OF);
    new->parms.on.type = GOSUB;
    new->parms.on.expression = $2;
    new->parms.on.numbers = $4;
    $$ = new;
      
    linenum_constants_total += lst_length($4);
    linenum_on_totals++;
  }
  |
  GOTO NUMBER
  {
    statement_t *new = make_statement(GOTO);
    expression_t *exp = make_expression(number);
    exp->parms.number = $2;
    new->parms._goto = exp;
    $$ = new;
      
    /* static analyzer */
    linenum_goto_totals++;
    linenum_constants_total++;
    if ($2 == errline) {
      linenum_same_line++;
    } else if ($2 > errline) {
      linenum_forwards++;
    } else {
      linenum_backwards++;
    }
  }
  |
  GOTO expression
  {
    statement_t *new = make_statement(GOTO);
    new->parms._goto = $2;
    $$ = new;
      
    /* static analyzer */
    linenum_goto_totals++;
    linenum_constants_total++;
    if ($2->parms.number) {
      if ($2->parms.number == errline) {
        linenum_same_line++;
      } else if ($2->parms.number > errline) {
          linenum_forwards++;
      } else {
          linenum_backwards++;
      }
    }
  }
  |
  GOTO expression OF exprlist
  {
    statement_t *new = make_statement(OF);
    new->parms.on.type = GOTO;
    new->parms.on.expression = $2;
    new->parms.on.numbers = $4;
    $$ = new;
      
    linenum_constants_total += lst_length($4);
    linenum_on_totals++;
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
    // this handles the implicit GOTO case, GOSUBs are always explicit so they are caught in the THEN statements
    linenum_then_goto_totals++;
    linenum_constants_total++;
    if ($2->parms.number) {
      if ($2->parms.number == errline) {
        linenum_same_line++;
      } else if ($2->parms.number > errline) {
        linenum_forwards++;
      } else {
        linenum_backwards++;
      }
    }
  }
  |
  IF expression GOTO NUMBER // this alternate form is seen in some BASICs like Bally and MS
  {
    statement_t *new = make_statement(IF);
    new->parms._if.condition = $2;
    new->parms._if.then_expression = NULL;
    new->parms._if.then_linenumber = $4;
    $$ = new;
    
    /* static analyzer */
    linenum_then_goto_totals++;
    linenum_constants_total++;
    if ($2->parms.number == errline) {
      linenum_same_line++;
    } else if ($2->parms.number > errline) {
      linenum_forwards++;
    } else {
      linenum_backwards++;
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
  LABEL variable // labels are placeholders for their own linenumber, which we can get...
  {
    statement_t *new = make_statement(LABEL);
    new->parms.label.variable = $2;
    new->parms.label.linenumber = errline;
    $$ = new;
  }
  |
  LET variable '=' expression /* explicit LET, implicit LET is at the bottom */
  {
    statement_t *new = make_statement(LET);
    new->parms.let.variable = $2;
    new->parms.let.expression = $4;
    $$ = new;
    
    /* static analyser - see if we are setting a value to 0 or 1 */
    //NOTE: same code below in invisible LET
    if (new->parms.let.expression->type == number) {
      if ((int)new->parms.let.expression->parms.number == 0) {
          assign_zero++;
      } else if ((int)new->parms.let.expression->parms.number == 1
                 && (int)new->parms.let.expression->parms.number == new->parms.let.expression->parms.number) {
        assign_one++;
      } else {
        assign_other++;
      }
    }
  }
  |
  MAT PRINT printlist
  {
    statement_t *new = make_statement(MATPRINT);
    new->parms.print.format = NULL;
    new->parms.print.item_list = $3;
    $$ = new;
  }
  |
  MAT INPUT printlist
  {
    statement_t *new = make_statement(MATINPUT);
    new->parms.print.format = NULL;
    new->parms.print.item_list = $3;
    $$ = new;
  }
  |
  MAT READ varlist
  {
    statement_t *new = make_statement(MATREAD);
    new->parms.print.format = NULL;
    new->parms.print.item_list = $3;
    $$ = new;
  }
  |
  MAT variable '=' expression
  {
    statement_t *new = make_statement(MAT);
    new->parms.let.variable = $2;
    new->parms.let.expression = $4;
    $$ = new;
  }
  |
  NEXT varlist // this handles one or more index variables, no need for a single-var case
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
  NEW
  {
    statement_t *new = make_statement(NEW);
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
      
    linenum_constants_total += lst_length($4);
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
    
    linenum_constants_total += lst_length($4);
    linenum_on_totals++;
  }
  |
  OPTION BASE expression
  {
    statement_t *new = make_statement(OPTION);
    new->parms.generic_parameter = $3;
    $$ = new;
  }
  |
  PAUSE // if there is no expression, it waits for a keypress
  {
    statement_t *new = make_statement(PAUSE);
    $$ = new;
  }
  |
  PAUSE expression // if there is an expression it's jiffies
  {
    statement_t *new = make_statement(PAUSE);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  POKE expression ',' expression
  {
    statement_t *new = make_statement(POKE);
    new->parms.generic_parameter = $2;
    new->parms.generic_parameter2 = $4;
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
  RANDOMIZE
  {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = NULL;
    $$ = new;
  }
  |
  RANDOMIZE expression
  {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = $2;
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
  RESTORE
  {
    statement_t *new = make_statement(RESTORE);
    $$ = new;
  }
  |
  RESTORE expression /* some basics allow a parameter here, representing a line number in some or an ordinal in others */
  {
    statement_t *new = make_statement(RESTORE);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  RETURN
  {
    statement_t *new = make_statement(RETURN);
    $$ = new;
  }
  |
  RETURN expression /* version seen in MSX that allows a line number */
  {
    statement_t *new = make_statement(RETURN);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  STOP
  {
    statement_t *new = make_statement(STOP);
    $$ = new;
  }
  |
  STOP expression /* Wang BASIC allows a print-like expression here */
  {
    statement_t *new = make_statement(STOP);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  STRING expression
  {
    statement_t *new = make_statement(STOP);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  SYS expression /* same as CALL */
  {
    statement_t *new = make_statement(SYS);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  TAB expression /* Integer BASIC's tab statement */
  {
    statement_t *new = make_statement(TAB);
    new->parms.generic_parameter = $2;
    $$ = new;
  }
  |
  TIME_STR '=' expression /* this is the weird variable-set version, which operates as a statement */
  {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic_parameter = $3;
    $$ = new;
  }
  |
  LET TIME_STR '=' expression /* unlikely to ever be see in the wild, but just in case... */
  {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic_parameter = $4;
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
  /* invisible LET, visible LET is above */
  |
  variable '=' expression
  {
    statement_t *new = make_statement(LET);
    new->parms.let.variable = $1;
    new->parms.let.expression = $3;
    $$ = new;
    
    /* static analyser - see if we are setting a value to 0 or 1 */
    //NOTE: same code above in LET
    if (new->parms.let.expression->type == number) {
      if ((int)new->parms.let.expression->parms.number == 0) {
          assign_zero++;
      } else if ((int)new->parms.let.expression->parms.number == 1
                 && (int)new->parms.let.expression->parms.number == new->parms.let.expression->parms.number) {
        assign_one++;
      } else {
        assign_other++;
      }
    }

  }
  ;

 /* precedence in RetroBASIC is handled through this pattern tree,
    but it is not clear that is the best solution
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
    
    /* static analyser - see if this is a comparison to zero or one */
    if (new->parms.op.p[1]->type == number) {
      // test for floats first
      if (ceil(new->parms.op.p[1]->parms.number) != new->parms.op.p[1]->parms.number) {
        if (new->parms.op.opcode == '=') {
          compare_equals_other++;
        } else {
          compare_not_equals_other++;
        }
      } else { // otherwise test ints
        if ((int)new->parms.op.p[1]->parms.number == 0) {
          if (new->parms.op.opcode == '=') {
            compare_equals_zero++;
          } else {
            compare_not_equals_zero++;
          }
        } else if ((int)new->parms.op.p[1]->parms.number == 1) {
          if (new->parms.op.opcode == '=') {
            compare_equals_one++;
          } else {
            compare_not_equals_one++;
          }
        } else {
          if (new->parms.op.opcode == '=') {
            compare_equals_other++;
          } else {
            compare_not_equals_other++;
          }
        }
      }
    }
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
    
    /* static analyser - if it's + or - 1, record it as an increment */
    if (new->parms.op.p[1]->type == number
        && (int)new->parms.op.p[1]->parms.number == 1
        && (int)new->parms.op.p[1]->parms.number == new->parms.op.p[1]->parms.number) {
      if (new->parms.op.opcode == '+') {
        increments++;
      } else {
        decrements++;
      }
    }
  }
  ;

e2op:   '+' { $$ = '+'; } |
        '-' { $$ = '-'; } |
        '&' { $$ = '&'; }
        ;

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
        MOD { $$ = MOD; } |
        DIV { $$ = DIV; } |
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
  /* functions with no parameters, like TIME */
  fn_0
  {
    expression_t *new = make_operator(0, $1);
    $$ = new;
  }
  |
  /* functions with optional parameters, which we store but ignore */
  fn_0 '(' ')'
  {
    expression_t *new = make_operator(0, $1);
    $$ = new;
  }
  |
  fn_0 '(' expression ')'
  {
    expression_t *new = make_operator(0, $1);
    new->parms.op.p[0] = $3;
    $$ = new;
  }
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
  /* multi-arity function being called with zero inputs... */
  |
  fn_x
  {
    expression_t *new = make_operator(0, $1);
    $$ = new;
  }
  /* ...or one ...*/
  |
  fn_x '(' expression ')'
  {
    expression_t *new = make_operator(1, $1);
    new->parms.op.p[0] = $3;
    $$ = new;
  }
  /* ...or two ...*/
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
  
 /* optional-parameter functions */
fn_0:
  INKEY { $$ = INKEY; } |
  FRE { $$ = FRE; } |
  PI { $$ = PI; } |
  RND { $$ = RND; } |
  TIME { $$ = TIME; } |
  TIME_STR { $$ = TIME_STR; }
  ;

 /* arity-1 functions */
fn_1:
  ABS { $$ =  ABS; } |
  ADR  { $$ = ADR; } |
  ATN  { $$ = ATN; } |
  BIN  { $$ = BIN; } |
  BINSTR { $$ = BINSTR; } |
  CHR  { $$ = CHR; } |
  CLOG { $$ = CLOG;} |
  COS  { $$ = COS; } |
  EXP  { $$ = EXP; } |
  FIX  { $$ = FIX; } |
  FRAC  { $$ = FRAC; } |
  HEX  { $$ = HEX; } |
  HEXSTR { $$ = HEXSTR; } |
  INT  { $$ = INT; } |
  LCASE  { $$ = LCASE; } |
  LEN  { $$ = LEN; } |
  LIN  { $$ = LIN; } |
  LOG  { $$ = LOG; } |
  OCT  { $$ = OCT; } |
  OCTSTR { $$ = OCTSTR; } |
  PEEK { $$ = PEEK;} |
  SGN  { $$ = SGN; } |
  SIN  { $$ = SIN; } |
  SPC  { $$ = SPC; } |
  SQR  { $$ = SQR; } |
  STR  { $$ = STR; } |
  TAB  { $$ = TAB; } |
  VAL  { $$ = VAL; } |
  UCASE  { $$ = UCASE; } |
  USR  { $$ = USR; }
  ;
  
 /* arity-2 functions */
fn_2:
  DIV  { $$ = DIV; } |
  MOD  { $$ = MOD; } |
  LEFT { $$ = LEFT; } |
  RIGHT { $$ = RIGHT; } |
  STRNG { $$ = STRNG; }
  ;

 /* arity-0, 1, 2 or 3 functions */
fn_x:
  INSTR { $$ = INSTR; } |
  POS { $$ = POS; } |
  MID { $$ = MID; } |
  SEG { $$ = SEG; } |
  SUBSTR { $$ = SUBSTR; } |
  ROUND  { $$ = ROUND; } |
  UBOUND  { $$ = UBOUND; } |
  LBOUND  { $$ = LBOUND; } |
  MATCON  { $$ = MATCON; } |
  MATDET  { $$ = MATDET; } |
  MATIDN  { $$ = MATIDN; } |
  MATINV  { $$ = MATINV; } |
  MATTRN  { $$ = MATTRN; } |
  MATZER  { $$ = MATZER; }
  ;

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
    size_t len = strlen($1);
    string_constants_total++;
    if (len == 0) {
      string_constants_zero++;
    } else if (len == 1) {
      string_constants_one_byte++;
    } else {
        string_constants_big++;
    }
    if (len > string_constants_max) string_constants_max = (int)len;
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
    new->parms.variable = $1; // use the variable slot here, it has the same signature
    $$ = new;
  }
  |
  '(' expression ')'
  {
    $$ = $2;
  }
  ;

 /* user functions MUST have at least the empty parameter list
    in Commodore BASIC, you can only have a single parameter,
    BBC seems to allow three
  */
user_function:
  FUNCTION_NAME '(' exprlist ')'
  {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = $1;
    new->subscripts = $3;
    $$ = new;
    // do NOT insert it now, the variables are private and will be set up during the DEF
  }

variable:
  VARIABLE_NAME
  {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = $1;
    new->subscripts = NULL;
    new->slicing = NULL;
    $$ = new;
    
    /* add it to the interpreter's variable list for the analyizer*/
    insert_variable(new);
  }
  |
  VARIABLE_NAME '(' exprlist ')'
  {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = $1;
    new->subscripts = $3;
    new->slicing = NULL;
    $$ = new;
    
    /* this may result in errors about array bounds if you OPTION BASE after the DIM */
    insert_variable(new);
  }
  |
  VARIABLE_NAME '[' exprlist ']'
  {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = $1;
    new->subscripts = $3;
    new->slicing = NULL;
    $$ = new;
    
    // square brackets tell us we are in the HP dialect, which means...
    string_slicing = true;
    
    insert_variable(new);
  }
  |
  VARIABLE_NAME '(' slicelist  ')'
  {
    /* this is the ANSI-style slicing command */
    /* NOTE: this should only ever occur in non-HP dialects, so the []'s would never appear */
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = $1;
    new->subscripts = NULL;
    new->slicing = $3;
    $$ = new;
    
    insert_variable(new);
  }
  |
  VARIABLE_NAME '(' exprlist  ')' '(' slicelist  ')'
  {
    /* and this is ANSI slicing of an entry in a string array */
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = $1;
    new->subscripts = $3;
    new->slicing = $6;
    $$ = new;
    
    insert_variable(new);
  }
  ;

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
    $$ = lst_append(NULL, new);
  }
  |
  // this handles MS semi-is-the-same as nothing, PRINT"I="I
  printlist expression
  {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = $2;
    new->separator = 0;
    $$ = lst_append($1, new);
  }
  |
  // this is found in the BCG "bug.bas", it's a print with a *leading* semi
  printsep
  {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = $1;
    $$ = lst_append(NULL, new);
  }
  |
  printlist printsep
  {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = $2;
    $$ = lst_append($1, new);
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
    $$ = lst_prepend(NULL, $1);
  }
  |
  exprlist ',' expression
  {
    $$ = lst_append($1, $3);
  }
  ;
  
  /* ANSI-style string slicing */
  // NOTE: the ANSI docs suggest the only correct format is two-parameter, start and end
  //       this contrasts with most other systems, where one or the other can be left off
slicelist:
    expression ':' expression
    {
      $$ = lst_prepend(NULL, $1);
      $$ = lst_append($$, $3);
    }
    |
    expression TO expression
    {
      $$ = lst_prepend(NULL, $1);
      $$ = lst_append($$, $3);
    }
    ;

 /* used only in PATB style multiple-assignment LETs */
 /* not currently used
 assignlist:
  variable '=' expression
  {
    $$ = lst_prepend($1, $3);
  }
  |
  assignlist variable '=' expression ','
  {
    $$ = lst_append($3, $5);
  }
  ;
  */

 /* used in READ statements and DEFs */
varlist:
  variable
  {
    $$ = lst_prepend(NULL, $1);
  }
  |
  varlist ',' variable
  {
    $$ = lst_append($1, $3);
  }
  ;

%%

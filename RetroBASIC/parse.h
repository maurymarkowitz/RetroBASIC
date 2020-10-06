/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    STRING = 259,
    IDENTIFIER = 260,
    BYE = 261,
    CLEAR = 262,
    CLS = 263,
    DATA = 264,
    DEF = 265,
    DIM = 266,
    END = 267,
    FOR = 268,
    GOSUB = 269,
    GOTO = 270,
    IF = 271,
    INPUT = 272,
    LET = 273,
    LIST = 274,
    NEXT = 275,
    NEW = 276,
    ON = 277,
    PRINT = 278,
    READ = 279,
    REM = 280,
    RESTORE = 281,
    RETURN = 282,
    RUN = 283,
    STEP = 284,
    STOP = 285,
    THEN = 286,
    TO = 287,
    USING = 288,
    VARLIST = 289,
    OPEN = 290,
    CLOSE = 291,
    STATUS = 292,
    PRINT_FILE = 293,
    INPUT_FILE = 294,
    GET_FILE = 295,
    _ABS = 296,
    SGN = 297,
    ATN = 298,
    COS = 299,
    SIN = 300,
    TAN = 301,
    CLOG = 302,
    EXP = 303,
    LOG = 304,
    SQR = 305,
    RND = 306,
    INT = 307,
    FIX = 308,
    CINT = 309,
    CSNG = 310,
    CDBL = 311,
    LEFT = 312,
    MID = 313,
    RIGHT = 314,
    LEN = 315,
    STR = 316,
    VAL = 317,
    CHR = 318,
    AND = 319,
    OR = 320,
    NOT = 321,
    XOR = 322,
    CMP_LE = 323,
    CMP_GE = 324,
    CMP_NE = 325,
    CMP_HASH = 326,
    ASC = 327,
    FRE = 328,
    SPC = 329,
    TAB = 330,
    POS = 331
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define STRING 259
#define IDENTIFIER 260
#define BYE 261
#define CLEAR 262
#define CLS 263
#define DATA 264
#define DEF 265
#define DIM 266
#define END 267
#define FOR 268
#define GOSUB 269
#define GOTO 270
#define IF 271
#define INPUT 272
#define LET 273
#define LIST 274
#define NEXT 275
#define NEW 276
#define ON 277
#define PRINT 278
#define READ 279
#define REM 280
#define RESTORE 281
#define RETURN 282
#define RUN 283
#define STEP 284
#define STOP 285
#define THEN 286
#define TO 287
#define USING 288
#define VARLIST 289
#define OPEN 290
#define CLOSE 291
#define STATUS 292
#define PRINT_FILE 293
#define INPUT_FILE 294
#define GET_FILE 295
#define _ABS 296
#define SGN 297
#define ATN 298
#define COS 299
#define SIN 300
#define TAN 301
#define CLOG 302
#define EXP 303
#define LOG 304
#define SQR 305
#define RND 306
#define INT 307
#define FIX 308
#define CINT 309
#define CSNG 310
#define CDBL 311
#define LEFT 312
#define MID 313
#define RIGHT 314
#define LEN 315
#define STR 316
#define VAL 317
#define CHR 318
#define AND 319
#define OR 320
#define NOT 321
#define XOR 322
#define CMP_LE 323
#define CMP_GE 324
#define CMP_NE 325
#define CMP_HASH 326
#define ASC 327
#define FRE 328
#define SPC 329
#define TAB 330
#define POS 331

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 74 "parse.y" /* yacc.c:1909  */

  double d;
  int i;
  GString *s;
  GList *l;
  statement_t *statement;
  expression_t *expression;
  variable_t *variable;

#line 216 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

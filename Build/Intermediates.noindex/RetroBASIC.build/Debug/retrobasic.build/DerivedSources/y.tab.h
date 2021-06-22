/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     STRING = 259,
     VARIABLE_NAME = 260,
     FUNCTION_NAME = 261,
     BREAK = 262,
     BYE = 263,
     CALL = 264,
     CLEAR = 265,
     CLS = 266,
     DATA = 267,
     DEF = 268,
     DIM = 269,
     END = 270,
     FOR = 271,
     GET = 272,
     GOSUB = 273,
     GOTO = 274,
     IF = 275,
     INPUT = 276,
     LET = 277,
     LIST = 278,
     NEXT = 279,
     NEW = 280,
     ON = 281,
     PEEK = 282,
     POKE = 283,
     PRINT = 284,
     PUT = 285,
     READ = 286,
     REM = 287,
     RESTORE = 288,
     RETURN = 289,
     RUN = 290,
     STEP = 291,
     STOP = 292,
     SYS = 293,
     THEN = 294,
     TO = 295,
     USING = 296,
     VARLIST = 297,
     WAIT = 298,
     OPEN = 299,
     CLOSE = 300,
     STATUS = 301,
     PRINT_FILE = 302,
     INPUT_FILE = 303,
     GET_FILE = 304,
     PUT_FILE = 305,
     _ABS = 306,
     SGN = 307,
     ATN = 308,
     COS = 309,
     SIN = 310,
     TAN = 311,
     CLOG = 312,
     EXP = 313,
     LOG = 314,
     SQR = 315,
     RND = 316,
     INT = 317,
     FIX = 318,
     CINT = 319,
     CSNG = 320,
     CDBL = 321,
     ASC = 322,
     LEFT = 323,
     MID = 324,
     RIGHT = 325,
     LEN = 326,
     STR = 327,
     VAL = 328,
     CHR = 329,
     AND = 330,
     OR = 331,
     NOT = 332,
     XOR = 333,
     CMP_LE = 334,
     CMP_GE = 335,
     CMP_NE = 336,
     CMP_HASH = 337,
     FRE = 338,
     SPC = 339,
     TAB = 340,
     POS = 341,
     USR = 342
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define STRING 259
#define VARIABLE_NAME 260
#define FUNCTION_NAME 261
#define BREAK 262
#define BYE 263
#define CALL 264
#define CLEAR 265
#define CLS 266
#define DATA 267
#define DEF 268
#define DIM 269
#define END 270
#define FOR 271
#define GET 272
#define GOSUB 273
#define GOTO 274
#define IF 275
#define INPUT 276
#define LET 277
#define LIST 278
#define NEXT 279
#define NEW 280
#define ON 281
#define PEEK 282
#define POKE 283
#define PRINT 284
#define PUT 285
#define READ 286
#define REM 287
#define RESTORE 288
#define RETURN 289
#define RUN 290
#define STEP 291
#define STOP 292
#define SYS 293
#define THEN 294
#define TO 295
#define USING 296
#define VARLIST 297
#define WAIT 298
#define OPEN 299
#define CLOSE 300
#define STATUS 301
#define PRINT_FILE 302
#define INPUT_FILE 303
#define GET_FILE 304
#define PUT_FILE 305
#define _ABS 306
#define SGN 307
#define ATN 308
#define COS 309
#define SIN 310
#define TAN 311
#define CLOG 312
#define EXP 313
#define LOG 314
#define SQR 315
#define RND 316
#define INT 317
#define FIX 318
#define CINT 319
#define CSNG 320
#define CDBL 321
#define ASC 322
#define LEFT 323
#define MID 324
#define RIGHT 325
#define LEN 326
#define STR 327
#define VAL 328
#define CHR 329
#define AND 330
#define OR 331
#define NOT 332
#define XOR 333
#define CMP_LE 334
#define CMP_GE 335
#define CMP_NE 336
#define CMP_HASH 337
#define FRE 338
#define SPC 339
#define TAB 340
#define POS 341
#define USR 342




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 71 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
{
  double d;
  int i;
  GString *s;
  GList *l;
  statement_t *statement;
  expression_t *expression;
  variable_t *variable;
}
/* Line 1529 of yacc.c.  */
#line 233 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


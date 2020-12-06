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
     DOUBLE = 259,
     SINGLE = 260,
     INTEGER = 261,
     STRING = 262,
     VARIABLE_NAME = 263,
     FUNCTION_NAME = 264,
     REM = 265,
     QUOTEREM = 266,
     BANGREM = 267,
     BREAK = 268,
     BYE = 269,
     CALL = 270,
     CLEAR = 271,
     CLS = 272,
     CMD = 273,
     DATA = 274,
     DEF = 275,
     DIM = 276,
     END = 277,
     EXIT = 278,
     FOR = 279,
     GET = 280,
     GOSUB = 281,
     GOTO = 282,
     IF = 283,
     INPUT = 284,
     LET = 285,
     LIST = 286,
     NEXT = 287,
     NEW = 288,
     ON = 289,
     PEEK = 290,
     POKE = 291,
     POP = 292,
     PRINT = 293,
     PUT = 294,
     READ = 295,
     RESTORE = 296,
     RETURN = 297,
     RUN = 298,
     STEP = 299,
     STOP = 300,
     SYS = 301,
     THEN = 302,
     TO = 303,
     USING = 304,
     VARLIST = 305,
     WAIT = 306,
     OPEN = 307,
     CLOSE = 308,
     STATUS = 309,
     PRINT_FILE = 310,
     INPUT_FILE = 311,
     GET_FILE = 312,
     PUT_FILE = 313,
     _ABS = 314,
     SGN = 315,
     ATN = 316,
     COS = 317,
     SIN = 318,
     TAN = 319,
     CLOG = 320,
     EXP = 321,
     LOG = 322,
     SQR = 323,
     RND = 324,
     INT = 325,
     FIX = 326,
     CINT = 327,
     CSNG = 328,
     CDBL = 329,
     ASC = 330,
     LEFT = 331,
     MID = 332,
     RIGHT = 333,
     LEN = 334,
     STR = 335,
     VAL = 336,
     CHR = 337,
     AND = 338,
     OR = 339,
     NOT = 340,
     XOR = 341,
     CMP_LE = 342,
     CMP_GE = 343,
     CMP_NE = 344,
     CMP_HASH = 345,
     FRE = 346,
     SPC = 347,
     TAB = 348,
     POS = 349,
     USR = 350
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define DOUBLE 259
#define SINGLE 260
#define INTEGER 261
#define STRING 262
#define VARIABLE_NAME 263
#define FUNCTION_NAME 264
#define REM 265
#define QUOTEREM 266
#define BANGREM 267
#define BREAK 268
#define BYE 269
#define CALL 270
#define CLEAR 271
#define CLS 272
#define CMD 273
#define DATA 274
#define DEF 275
#define DIM 276
#define END 277
#define EXIT 278
#define FOR 279
#define GET 280
#define GOSUB 281
#define GOTO 282
#define IF 283
#define INPUT 284
#define LET 285
#define LIST 286
#define NEXT 287
#define NEW 288
#define ON 289
#define PEEK 290
#define POKE 291
#define POP 292
#define PRINT 293
#define PUT 294
#define READ 295
#define RESTORE 296
#define RETURN 297
#define RUN 298
#define STEP 299
#define STOP 300
#define SYS 301
#define THEN 302
#define TO 303
#define USING 304
#define VARLIST 305
#define WAIT 306
#define OPEN 307
#define CLOSE 308
#define STATUS 309
#define PRINT_FILE 310
#define INPUT_FILE 311
#define GET_FILE 312
#define PUT_FILE 313
#define _ABS 314
#define SGN 315
#define ATN 316
#define COS 317
#define SIN 318
#define TAN 319
#define CLOG 320
#define EXP 321
#define LOG 322
#define SQR 323
#define RND 324
#define INT 325
#define FIX 326
#define CINT 327
#define CSNG 328
#define CDBL 329
#define ASC 330
#define LEFT 331
#define MID 332
#define RIGHT 333
#define LEN 334
#define STR 335
#define VAL 336
#define CHR 337
#define AND 338
#define OR 339
#define NOT 340
#define XOR 341
#define CMP_LE 342
#define CMP_GE 343
#define CMP_NE 344
#define CMP_HASH 345
#define FRE 346
#define SPC 347
#define TAB 348
#define POS 349
#define USR 350




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
#line 249 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


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
     RANDOMIZE = 295,
     READ = 296,
     RESTORE = 297,
     RETURN = 298,
     RUN = 299,
     STEP = 300,
     STOP = 301,
     SYS = 302,
     THEN = 303,
     TO = 304,
     USING = 305,
     VARLIST = 306,
     WAIT = 307,
     OPEN = 308,
     CLOSE = 309,
     STATUS = 310,
     PRINT_FILE = 311,
     INPUT_FILE = 312,
     GET_FILE = 313,
     PUT_FILE = 314,
     _ABS = 315,
     SGN = 316,
     ATN = 317,
     COS = 318,
     SIN = 319,
     TAN = 320,
     CLOG = 321,
     EXP = 322,
     LOG = 323,
     SQR = 324,
     RND = 325,
     INT = 326,
     FIX = 327,
     CINT = 328,
     CSNG = 329,
     CDBL = 330,
     ASC = 331,
     LEFT = 332,
     MID = 333,
     RIGHT = 334,
     LEN = 335,
     STR = 336,
     VAL = 337,
     CHR = 338,
     AND = 339,
     OR = 340,
     NOT = 341,
     XOR = 342,
     CMP_LE = 343,
     CMP_GE = 344,
     CMP_NE = 345,
     CMP_HASH = 346,
     FRE = 347,
     SPC = 348,
     TAB = 349,
     POS = 350,
     USR = 351
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
#define RANDOMIZE 295
#define READ 296
#define RESTORE 297
#define RETURN 298
#define RUN 299
#define STEP 300
#define STOP 301
#define SYS 302
#define THEN 303
#define TO 304
#define USING 305
#define VARLIST 306
#define WAIT 307
#define OPEN 308
#define CLOSE 309
#define STATUS 310
#define PRINT_FILE 311
#define INPUT_FILE 312
#define GET_FILE 313
#define PUT_FILE 314
#define _ABS 315
#define SGN 316
#define ATN 317
#define COS 318
#define SIN 319
#define TAN 320
#define CLOG 321
#define EXP 322
#define LOG 323
#define SQR 324
#define RND 325
#define INT 326
#define FIX 327
#define CINT 328
#define CSNG 329
#define CDBL 330
#define ASC 331
#define LEFT 332
#define MID 333
#define RIGHT 334
#define LEN 335
#define STR 336
#define VAL 337
#define CHR 338
#define AND 339
#define OR 340
#define NOT 341
#define XOR 342
#define CMP_LE 343
#define CMP_GE 344
#define CMP_NE 345
#define CMP_HASH 346
#define FRE 347
#define SPC 348
#define TAB 349
#define POS 350
#define USR 351




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
#line 251 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


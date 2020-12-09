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
     BYE = 268,
     CLEAR = 269,
     DATA = 270,
     DEF = 271,
     DIM = 272,
     END = 273,
     EXIT = 274,
     FOR = 275,
     GET = 276,
     GOSUB = 277,
     GOTO = 278,
     IF = 279,
     INPUT = 280,
     LET = 281,
     LIST = 282,
     NEXT = 283,
     NEW = 284,
     ON = 285,
     PRINT = 286,
     PUT = 287,
     READ = 288,
     RESTORE = 289,
     RETURN = 290,
     RUN = 291,
     STEP = 292,
     STOP = 293,
     THEN = 294,
     TO = 295,
     USING = 296,
     WAIT = 297,
     OPEN = 298,
     CLOSE = 299,
     STATUS = 300,
     PRINT_FILE = 301,
     INPUT_FILE = 302,
     GET_FILE = 303,
     PUT_FILE = 304,
     BREAK = 305,
     CALL = 306,
     CLS = 307,
     CMD = 308,
     OPTION = 309,
     BASE = 310,
     PEEK = 311,
     POKE = 312,
     POP = 313,
     RANDOMIZE = 314,
     SYS = 315,
     VARLIST = 316,
     _ABS = 317,
     SGN = 318,
     ATN = 319,
     COS = 320,
     SIN = 321,
     TAN = 322,
     CLOG = 323,
     EXP = 324,
     LOG = 325,
     SQR = 326,
     RND = 327,
     INT = 328,
     FIX = 329,
     CINT = 330,
     CSNG = 331,
     CDBL = 332,
     ASC = 333,
     LEFT = 334,
     MID = 335,
     RIGHT = 336,
     LEN = 337,
     STR = 338,
     VAL = 339,
     CHR = 340,
     AND = 341,
     OR = 342,
     NOT = 343,
     XOR = 344,
     CMP_LE = 345,
     CMP_GE = 346,
     CMP_NE = 347,
     CMP_HASH = 348,
     FRE = 349,
     SPC = 350,
     TAB = 351,
     POS = 352,
     USR = 353
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
#define BYE 268
#define CLEAR 269
#define DATA 270
#define DEF 271
#define DIM 272
#define END 273
#define EXIT 274
#define FOR 275
#define GET 276
#define GOSUB 277
#define GOTO 278
#define IF 279
#define INPUT 280
#define LET 281
#define LIST 282
#define NEXT 283
#define NEW 284
#define ON 285
#define PRINT 286
#define PUT 287
#define READ 288
#define RESTORE 289
#define RETURN 290
#define RUN 291
#define STEP 292
#define STOP 293
#define THEN 294
#define TO 295
#define USING 296
#define WAIT 297
#define OPEN 298
#define CLOSE 299
#define STATUS 300
#define PRINT_FILE 301
#define INPUT_FILE 302
#define GET_FILE 303
#define PUT_FILE 304
#define BREAK 305
#define CALL 306
#define CLS 307
#define CMD 308
#define OPTION 309
#define BASE 310
#define PEEK 311
#define POKE 312
#define POP 313
#define RANDOMIZE 314
#define SYS 315
#define VARLIST 316
#define _ABS 317
#define SGN 318
#define ATN 319
#define COS 320
#define SIN 321
#define TAN 322
#define CLOG 323
#define EXP 324
#define LOG 325
#define SQR 326
#define RND 327
#define INT 328
#define FIX 329
#define CINT 330
#define CSNG 331
#define CDBL 332
#define ASC 333
#define LEFT 334
#define MID 335
#define RIGHT 336
#define LEN 337
#define STR 338
#define VAL 339
#define CHR 340
#define AND 341
#define OR 342
#define NOT 343
#define XOR 344
#define CMP_LE 345
#define CMP_GE 346
#define CMP_NE 347
#define CMP_HASH 348
#define FRE 349
#define SPC 350
#define TAB 351
#define POS 352
#define USR 353




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
#line 255 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


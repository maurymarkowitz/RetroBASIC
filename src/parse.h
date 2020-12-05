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
     BREAK = 265,
     BYE = 266,
     CALL = 267,
     CLEAR = 268,
     CLS = 269,
     CMD = 270,
     DATA = 271,
     DEF = 272,
     DIM = 273,
     END = 274,
     EXIT = 275,
     FOR = 276,
     GET = 277,
     GOSUB = 278,
     GOTO = 279,
     IF = 280,
     INPUT = 281,
     LET = 282,
     LIST = 283,
     NEXT = 284,
     NEW = 285,
     ON = 286,
     PEEK = 287,
     POKE = 288,
     POP = 289,
     PRINT = 290,
     PUT = 291,
     READ = 292,
     REM = 293,
     RESTORE = 294,
     RETURN = 295,
     RUN = 296,
     SHORTREM = 297,
     STEP = 298,
     STOP = 299,
     SYS = 300,
     THEN = 301,
     TO = 302,
     USING = 303,
     VARLIST = 304,
     WAIT = 305,
     OPEN = 306,
     CLOSE = 307,
     STATUS = 308,
     PRINT_FILE = 309,
     INPUT_FILE = 310,
     GET_FILE = 311,
     PUT_FILE = 312,
     _ABS = 313,
     SGN = 314,
     ATN = 315,
     COS = 316,
     SIN = 317,
     TAN = 318,
     CLOG = 319,
     EXP = 320,
     LOG = 321,
     SQR = 322,
     RND = 323,
     INT = 324,
     FIX = 325,
     CINT = 326,
     CSNG = 327,
     CDBL = 328,
     ASC = 329,
     LEFT = 330,
     MID = 331,
     RIGHT = 332,
     LEN = 333,
     STR = 334,
     VAL = 335,
     CHR = 336,
     AND = 337,
     OR = 338,
     NOT = 339,
     XOR = 340,
     CMP_LE = 341,
     CMP_GE = 342,
     CMP_NE = 343,
     CMP_HASH = 344,
     FRE = 345,
     SPC = 346,
     TAB = 347,
     POS = 348,
     USR = 349
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
#define BREAK 265
#define BYE 266
#define CALL 267
#define CLEAR 268
#define CLS 269
#define CMD 270
#define DATA 271
#define DEF 272
#define DIM 273
#define END 274
#define EXIT 275
#define FOR 276
#define GET 277
#define GOSUB 278
#define GOTO 279
#define IF 280
#define INPUT 281
#define LET 282
#define LIST 283
#define NEXT 284
#define NEW 285
#define ON 286
#define PEEK 287
#define POKE 288
#define POP 289
#define PRINT 290
#define PUT 291
#define READ 292
#define REM 293
#define RESTORE 294
#define RETURN 295
#define RUN 296
#define SHORTREM 297
#define STEP 298
#define STOP 299
#define SYS 300
#define THEN 301
#define TO 302
#define USING 303
#define VARLIST 304
#define WAIT 305
#define OPEN 306
#define CLOSE 307
#define STATUS 308
#define PRINT_FILE 309
#define INPUT_FILE 310
#define GET_FILE 311
#define PUT_FILE 312
#define _ABS 313
#define SGN 314
#define ATN 315
#define COS 316
#define SIN 317
#define TAN 318
#define CLOG 319
#define EXP 320
#define LOG 321
#define SQR 322
#define RND 323
#define INT 324
#define FIX 325
#define CINT 326
#define CSNG 327
#define CDBL 328
#define ASC 329
#define LEFT 330
#define MID 331
#define RIGHT 332
#define LEN 333
#define STR 334
#define VAL 335
#define CHR 336
#define AND 337
#define OR 338
#define NOT 339
#define XOR 340
#define CMP_LE 341
#define CMP_GE 342
#define CMP_NE 343
#define CMP_HASH 344
#define FRE 345
#define SPC 346
#define TAB 347
#define POS 348
#define USR 349




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
#line 247 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


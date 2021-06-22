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
     STRING = 258,
     NUMBER = 259,
     DOUBLE = 260,
     SINGLE = 261,
     INTEGER = 262,
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
     CALL = 305,
     CLS = 306,
     CMD = 307,
     OPTION = 308,
     BASE = 309,
     PEEK = 310,
     POKE = 311,
     POP = 312,
     RANDOMIZE = 313,
     SYS = 314,
     VARLIST = 315,
     _ABS = 316,
     SGN = 317,
     ATN = 318,
     COS = 319,
     SIN = 320,
     TAN = 321,
     CLOG = 322,
     EXP = 323,
     LOG = 324,
     SQR = 325,
     RND = 326,
     INT = 327,
     FIX = 328,
     CINT = 329,
     CSNG = 330,
     CDBL = 331,
     ASC = 332,
     LEFT = 333,
     MID = 334,
     RIGHT = 335,
     LEN = 336,
     STR = 337,
     VAL = 338,
     CHR = 339,
     AND = 340,
     OR = 341,
     NOT = 342,
     XOR = 343,
     CMP_LE = 344,
     CMP_GE = 345,
     CMP_NE = 346,
     CMP_HASH = 347,
     FRE = 348,
     SPC = 349,
     TAB = 350,
     POS = 351,
     USR = 352,
     DEFSTR = 353,
     DEFINT = 354,
     DEFSNG = 355,
     DEFDBL = 356
   };
#endif
/* Tokens.  */
#define STRING 258
#define NUMBER 259
#define DOUBLE 260
#define SINGLE 261
#define INTEGER 262
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
#define CALL 305
#define CLS 306
#define CMD 307
#define OPTION 308
#define BASE 309
#define PEEK 310
#define POKE 311
#define POP 312
#define RANDOMIZE 313
#define SYS 314
#define VARLIST 315
#define _ABS 316
#define SGN 317
#define ATN 318
#define COS 319
#define SIN 320
#define TAN 321
#define CLOG 322
#define EXP 323
#define LOG 324
#define SQR 325
#define RND 326
#define INT 327
#define FIX 328
#define CINT 329
#define CSNG 330
#define CDBL 331
#define ASC 332
#define LEFT 333
#define MID 334
#define RIGHT 335
#define LEN 336
#define STR 337
#define VAL 338
#define CHR 339
#define AND 340
#define OR 341
#define NOT 342
#define XOR 343
#define CMP_LE 344
#define CMP_GE 345
#define CMP_NE 346
#define CMP_HASH 347
#define FRE 348
#define SPC 349
#define TAB 350
#define POS 351
#define USR 352
#define DEFSTR 353
#define DEFINT 354
#define DEFSNG 355
#define DEFDBL 356




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
#line 261 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


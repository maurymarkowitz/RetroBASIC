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
     HEX_STR = 265,
     OCT_STR = 266,
     BIN_STR = 267,
     REM = 268,
     QUOTEREM = 269,
     BANGREM = 270,
     BYE = 271,
     CLEAR = 272,
     CLR = 273,
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
     OF = 289,
     ON = 290,
     PRINT = 291,
     PUT = 292,
     READ = 293,
     RESTORE = 294,
     RETURN = 295,
     RUN = 296,
     STEP = 297,
     STOP = 298,
     THEN = 299,
     TO = 300,
     USING = 301,
     WAIT = 302,
     OPEN = 303,
     CLOSE = 304,
     STATUS = 305,
     PRINT_FILE = 306,
     INPUT_FILE = 307,
     GET_FILE = 308,
     PUT_FILE = 309,
     CALL = 310,
     CLS = 311,
     CMD = 312,
     OPTION = 313,
     BASE = 314,
     PEEK = 315,
     POKE = 316,
     POP = 317,
     RANDOMIZE = 318,
     SYS = 319,
     VARLIST = 320,
     PAUSE = 321,
     _ABS = 322,
     SGN = 323,
     ATN = 324,
     COS = 325,
     SIN = 326,
     TAN = 327,
     CLOG = 328,
     EXP = 329,
     LOG = 330,
     SQR = 331,
     RND = 332,
     INT = 333,
     FIX = 334,
     FRAC = 335,
     CINT = 336,
     CSNG = 337,
     CDBL = 338,
     ASC = 339,
     LEFT = 340,
     MID = 341,
     RIGHT = 342,
     LEN = 343,
     STR = 344,
     VAL = 345,
     CHR = 346,
     SEG = 347,
     SUBSTR = 348,
     INSTR = 349,
     AND = 350,
     OR = 351,
     NOT = 352,
     XOR = 353,
     CMP_LE = 354,
     CMP_GE = 355,
     CMP_NE = 356,
     CMP_HASH = 357,
     FRE = 358,
     SPC = 359,
     TAB = 360,
     POS = 361,
     USR = 362,
     LIN = 363,
     DEFSTR = 364,
     DEFINT = 365,
     DEFSNG = 366,
     DEFDBL = 367,
     CHANGE = 368,
     CONVERT = 369,
     UCASE = 370,
     LCASE = 371,
     STRNG = 372,
     TIME = 373,
     TIME_STR = 374,
     HEX = 375,
     OCT = 376,
     BIN = 377,
     HEXSTR = 378,
     OCTSTR = 379,
     BINSTR = 380,
     UBOUND = 381,
     LBOUND = 382,
     LABEL = 383
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
#define HEX_STR 265
#define OCT_STR 266
#define BIN_STR 267
#define REM 268
#define QUOTEREM 269
#define BANGREM 270
#define BYE 271
#define CLEAR 272
#define CLR 273
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
#define OF 289
#define ON 290
#define PRINT 291
#define PUT 292
#define READ 293
#define RESTORE 294
#define RETURN 295
#define RUN 296
#define STEP 297
#define STOP 298
#define THEN 299
#define TO 300
#define USING 301
#define WAIT 302
#define OPEN 303
#define CLOSE 304
#define STATUS 305
#define PRINT_FILE 306
#define INPUT_FILE 307
#define GET_FILE 308
#define PUT_FILE 309
#define CALL 310
#define CLS 311
#define CMD 312
#define OPTION 313
#define BASE 314
#define PEEK 315
#define POKE 316
#define POP 317
#define RANDOMIZE 318
#define SYS 319
#define VARLIST 320
#define PAUSE 321
#define _ABS 322
#define SGN 323
#define ATN 324
#define COS 325
#define SIN 326
#define TAN 327
#define CLOG 328
#define EXP 329
#define LOG 330
#define SQR 331
#define RND 332
#define INT 333
#define FIX 334
#define FRAC 335
#define CINT 336
#define CSNG 337
#define CDBL 338
#define ASC 339
#define LEFT 340
#define MID 341
#define RIGHT 342
#define LEN 343
#define STR 344
#define VAL 345
#define CHR 346
#define SEG 347
#define SUBSTR 348
#define INSTR 349
#define AND 350
#define OR 351
#define NOT 352
#define XOR 353
#define CMP_LE 354
#define CMP_GE 355
#define CMP_NE 356
#define CMP_HASH 357
#define FRE 358
#define SPC 359
#define TAB 360
#define POS 361
#define USR 362
#define LIN 363
#define DEFSTR 364
#define DEFINT 365
#define DEFSNG 366
#define DEFDBL 367
#define CHANGE 368
#define CONVERT 369
#define UCASE 370
#define LCASE 371
#define STRNG 372
#define TIME 373
#define TIME_STR 374
#define HEX 375
#define OCT 376
#define BIN 377
#define HEXSTR 378
#define OCTSTR 379
#define BINSTR 380
#define UBOUND 381
#define LBOUND 382
#define LABEL 383




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
{
  double d;
  int i;
  char *s;
  list_t *l;
  statement_t *statement;
  expression_t *expression;
  variable_reference_t *variable;
}
/* Line 1529 of yacc.c.  */
#line 315 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


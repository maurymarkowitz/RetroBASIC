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
     ABS = 322,
     SGN = 323,
     CLOG = 324,
     EXP = 325,
     LOG = 326,
     SQR = 327,
     PI = 328,
     RND = 329,
     INT = 330,
     FIX = 331,
     FRAC = 332,
     ROUND = 333,
     CINT = 334,
     CSNG = 335,
     CDBL = 336,
     MOD = 337,
     DIV = 338,
     COS = 339,
     SIN = 340,
     ATN = 341,
     ACS = 342,
     ASN = 343,
     TAN = 344,
     COSH = 345,
     SINH = 346,
     TANH = 347,
     ASC = 348,
     LEFT = 349,
     MID = 350,
     RIGHT = 351,
     LEN = 352,
     STR = 353,
     VAL = 354,
     CHR = 355,
     SEG = 356,
     SUBSTR = 357,
     INSTR = 358,
     INKEY = 359,
     AND = 360,
     OR = 361,
     NOT = 362,
     XOR = 363,
     EQV = 364,
     IMP = 365,
     CMP_LE = 366,
     CMP_GE = 367,
     CMP_NE = 368,
     CMP_HASH = 369,
     ADR = 370,
     FRE = 371,
     SPC = 372,
     TAB = 373,
     POS = 374,
     USR = 375,
     LIN = 376,
     DEFSTR = 377,
     DEFINT = 378,
     DEFSNG = 379,
     DEFDBL = 380,
     CHANGE = 381,
     CONVERT = 382,
     UCASE = 383,
     LCASE = 384,
     STRNG = 385,
     TIME = 386,
     TIME_STR = 387,
     HEX = 388,
     OCT = 389,
     BIN = 390,
     HEXSTR = 391,
     OCTSTR = 392,
     BINSTR = 393,
     UBOUND = 394,
     LBOUND = 395,
     LABEL = 396,
     MAT = 397,
     MATPRINT = 398,
     MATINPUT = 399,
     MATREAD = 400,
     MATGET = 401,
     MATPUT = 402,
     MATZER = 403,
     MATCON = 404,
     MATIDN = 405,
     MATTRN = 406,
     MATINV = 407,
     MATDET = 408
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
#define ABS 322
#define SGN 323
#define CLOG 324
#define EXP 325
#define LOG 326
#define SQR 327
#define PI 328
#define RND 329
#define INT 330
#define FIX 331
#define FRAC 332
#define ROUND 333
#define CINT 334
#define CSNG 335
#define CDBL 336
#define MOD 337
#define DIV 338
#define COS 339
#define SIN 340
#define ATN 341
#define ACS 342
#define ASN 343
#define TAN 344
#define COSH 345
#define SINH 346
#define TANH 347
#define ASC 348
#define LEFT 349
#define MID 350
#define RIGHT 351
#define LEN 352
#define STR 353
#define VAL 354
#define CHR 355
#define SEG 356
#define SUBSTR 357
#define INSTR 358
#define INKEY 359
#define AND 360
#define OR 361
#define NOT 362
#define XOR 363
#define EQV 364
#define IMP 365
#define CMP_LE 366
#define CMP_GE 367
#define CMP_NE 368
#define CMP_HASH 369
#define ADR 370
#define FRE 371
#define SPC 372
#define TAB 373
#define POS 374
#define USR 375
#define LIN 376
#define DEFSTR 377
#define DEFINT 378
#define DEFSNG 379
#define DEFDBL 380
#define CHANGE 381
#define CONVERT 382
#define UCASE 383
#define LCASE 384
#define STRNG 385
#define TIME 386
#define TIME_STR 387
#define HEX 388
#define OCT 389
#define BIN 390
#define HEXSTR 391
#define OCTSTR 392
#define BINSTR 393
#define UBOUND 394
#define LBOUND 395
#define LABEL 396
#define MAT 397
#define MATPRINT 398
#define MATINPUT 399
#define MATREAD 400
#define MATGET 401
#define MATPUT 402
#define MATZER 403
#define MATCON 404
#define MATIDN 405
#define MATTRN 406
#define MATINV 407
#define MATDET 408




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 73 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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
#line 365 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


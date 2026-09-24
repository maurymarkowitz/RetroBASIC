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
     COMMON = 277,
     REDIM = 278,
     END = 279,
     EXIT = 280,
     FOR = 281,
     GET = 282,
     GOSUB = 283,
     GOTO = 284,
     IF = 285,
     INPUT = 286,
     INPUT_LINE = 287,
     LET = 288,
     LIST = 289,
     LIST_FILE = 290,
     LOAD = 291,
     CHAIN = 292,
     SAVE = 293,
     NEXT = 294,
     NEW = 295,
     OF = 296,
     ON = 297,
     PRINT = 298,
     PUT = 299,
     READ = 300,
     RETURN = 301,
     RUN = 302,
     CONT = 303,
     STEP = 304,
     STOP = 305,
     THEN = 306,
     TO = 307,
     USING = 308,
     WAIT = 309,
     OPEN = 310,
     CLOSE = 311,
     STATUS = 312,
     PRINT_FILE = 313,
     INPUT_FILE = 314,
     GET_FILE = 315,
     PUT_FILE = 316,
     _EOF = 317,
     CALL = 318,
     CLS = 319,
     CMD = 320,
     OPTION = 321,
     BASE = 322,
     PEEK = 323,
     POKE = 324,
     POP = 325,
     RANDOMIZE = 326,
     SYS = 327,
     VARLIST = 328,
     PAUSE = 329,
     PRESERVE = 330,
     SLEEP = 331,
     RESTORE = 332,
     ABS = 333,
     SGN = 334,
     CLOG = 335,
     EXP = 336,
     LOG = 337,
     SQR = 338,
     PI = 339,
     RND = 340,
     INT = 341,
     FIX = 342,
     FRAC = 343,
     ROUND = 344,
     CINT = 345,
     CSNG = 346,
     CDBL = 347,
     MOD = 348,
     MOD_INT = 349,
     DIV = 350,
     MAX = 351,
     MIN = 352,
     COS = 353,
     SIN = 354,
     ATN = 355,
     ACS = 356,
     ASN = 357,
     TAN = 358,
     COSH = 359,
     SINH = 360,
     TANH = 361,
     ASC = 362,
     LEFT = 363,
     MID = 364,
     RIGHT = 365,
     LEN = 366,
     STR = 367,
     VAL = 368,
     CHR = 369,
     SEG = 370,
     SUBSTR = 371,
     INSTR = 372,
     INKEY = 373,
     AND = 374,
     OR = 375,
     NOT = 376,
     XOR = 377,
     EQV = 378,
     IMP = 379,
     CMP_LE = 380,
     CMP_GE = 381,
     CMP_NE = 382,
     HASH = 383,
     STMT_SEP = 384,
     ADR = 385,
     FRE = 386,
     SPC = 387,
     TAB = 388,
     POS = 389,
     USR = 390,
     LIN = 391,
     TRAP = 392,
     RESUME = 393,
     ERROR = 394,
     RAISE = 395,
     BREAK = 396,
     ERR = 397,
     EL = 398,
     ER = 399,
     DEFSTR = 400,
     DEFINT = 401,
     DEFSNG = 402,
     DEFDBL = 403,
     CHANGE = 404,
     CONVERT = 405,
     UCASE = 406,
     LCASE = 407,
     STRNG = 408,
     TIME = 409,
     TIME_STR = 410,
     CLK = 411,
     HEX = 412,
     OCT = 413,
     BIN = 414,
     HEXSTR = 415,
     OCTSTR = 416,
     BINSTR = 417,
     UBOUND = 418,
     LBOUND = 419,
     LABEL = 420,
     MAT = 421,
     MATPRINT = 422,
     MATINPUT = 423,
     MATREAD = 424,
     MATGET = 425,
     MATPUT = 426,
     MATZER = 427,
     MATNUL = 428,
     MATCON = 429,
     MATIDN = 430,
     MATTRN = 431,
     MATINV = 432,
     MATDET = 433,
     MATADD = 434,
     MATSUB = 435,
     MATMUL = 436,
     MATSCA = 437,
     MATFIL = 438,
     NUM = 439
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
#define COMMON 277
#define REDIM 278
#define END 279
#define EXIT 280
#define FOR 281
#define GET 282
#define GOSUB 283
#define GOTO 284
#define IF 285
#define INPUT 286
#define INPUT_LINE 287
#define LET 288
#define LIST 289
#define LIST_FILE 290
#define LOAD 291
#define CHAIN 292
#define SAVE 293
#define NEXT 294
#define NEW 295
#define OF 296
#define ON 297
#define PRINT 298
#define PUT 299
#define READ 300
#define RETURN 301
#define RUN 302
#define CONT 303
#define STEP 304
#define STOP 305
#define THEN 306
#define TO 307
#define USING 308
#define WAIT 309
#define OPEN 310
#define CLOSE 311
#define STATUS 312
#define PRINT_FILE 313
#define INPUT_FILE 314
#define GET_FILE 315
#define PUT_FILE 316
#define _EOF 317
#define CALL 318
#define CLS 319
#define CMD 320
#define OPTION 321
#define BASE 322
#define PEEK 323
#define POKE 324
#define POP 325
#define RANDOMIZE 326
#define SYS 327
#define VARLIST 328
#define PAUSE 329
#define PRESERVE 330
#define SLEEP 331
#define RESTORE 332
#define ABS 333
#define SGN 334
#define CLOG 335
#define EXP 336
#define LOG 337
#define SQR 338
#define PI 339
#define RND 340
#define INT 341
#define FIX 342
#define FRAC 343
#define ROUND 344
#define CINT 345
#define CSNG 346
#define CDBL 347
#define MOD 348
#define MOD_INT 349
#define DIV 350
#define MAX 351
#define MIN 352
#define COS 353
#define SIN 354
#define ATN 355
#define ACS 356
#define ASN 357
#define TAN 358
#define COSH 359
#define SINH 360
#define TANH 361
#define ASC 362
#define LEFT 363
#define MID 364
#define RIGHT 365
#define LEN 366
#define STR 367
#define VAL 368
#define CHR 369
#define SEG 370
#define SUBSTR 371
#define INSTR 372
#define INKEY 373
#define AND 374
#define OR 375
#define NOT 376
#define XOR 377
#define EQV 378
#define IMP 379
#define CMP_LE 380
#define CMP_GE 381
#define CMP_NE 382
#define HASH 383
#define STMT_SEP 384
#define ADR 385
#define FRE 386
#define SPC 387
#define TAB 388
#define POS 389
#define USR 390
#define LIN 391
#define TRAP 392
#define RESUME 393
#define ERROR 394
#define RAISE 395
#define BREAK 396
#define ERR 397
#define EL 398
#define ER 399
#define DEFSTR 400
#define DEFINT 401
#define DEFSNG 402
#define DEFDBL 403
#define CHANGE 404
#define CONVERT 405
#define UCASE 406
#define LCASE 407
#define STRNG 408
#define TIME 409
#define TIME_STR 410
#define CLK 411
#define HEX 412
#define OCT 413
#define BIN 414
#define HEXSTR 415
#define OCTSTR 416
#define BINSTR 417
#define UBOUND 418
#define LBOUND 419
#define LABEL 420
#define MAT 421
#define MATPRINT 422
#define MATINPUT 423
#define MATREAD 424
#define MATGET 425
#define MATPUT 426
#define MATZER 427
#define MATNUL 428
#define MATCON 429
#define MATIDN 430
#define MATTRN 431
#define MATINV 432
#define MATDET 433
#define MATADD 434
#define MATSUB 435
#define MATMUL 436
#define MATSCA 437
#define MATFIL 438
#define NUM 439




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 77 "src/parse.y"
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
#line 427 "src/parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


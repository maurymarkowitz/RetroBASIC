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
     REDIM = 277,
     END = 278,
     EXIT = 279,
     FOR = 280,
     GET = 281,
     GOSUB = 282,
     GOTO = 283,
     IF = 284,
     INPUT = 285,
     INPUT_LINE = 286,
     LET = 287,
     LIST = 288,
     NEXT = 289,
     NEW = 290,
     OF = 291,
     ON = 292,
     PRINT = 293,
     PUT = 294,
     READ = 295,
     RETURN = 296,
     RUN = 297,
     STEP = 298,
     STOP = 299,
     THEN = 300,
     TO = 301,
     USING = 302,
     WAIT = 303,
     OPEN = 304,
     CLOSE = 305,
     STATUS = 306,
     PRINT_FILE = 307,
     INPUT_FILE = 308,
     GET_FILE = 309,
     PUT_FILE = 310,
     _EOF = 311,
     CALL = 312,
     CLS = 313,
     CMD = 314,
     OPTION = 315,
     BASE = 316,
     PEEK = 317,
     POKE = 318,
     POP = 319,
     RANDOMIZE = 320,
     SYS = 321,
     VARLIST = 322,
     PAUSE = 323,
     PRESERVE = 324,
     SLEEP = 325,
     RESTORE = 326,
     ABS = 327,
     SGN = 328,
     CLOG = 329,
     EXP = 330,
     LOG = 331,
     SQR = 332,
     PI = 333,
     RND = 334,
     INT = 335,
     FIX = 336,
     FRAC = 337,
     ROUND = 338,
     CINT = 339,
     CSNG = 340,
     CDBL = 341,
     MOD = 342,
     MOD_INT = 343,
     DIV = 344,
     MAX = 345,
     MIN = 346,
     COS = 347,
     SIN = 348,
     ATN = 349,
     ACS = 350,
     ASN = 351,
     TAN = 352,
     COSH = 353,
     SINH = 354,
     TANH = 355,
     ASC = 356,
     LEFT = 357,
     MID = 358,
     RIGHT = 359,
     LEN = 360,
     STR = 361,
     VAL = 362,
     CHR = 363,
     SEG = 364,
     SUBSTR = 365,
     INSTR = 366,
     INKEY = 367,
     AND = 368,
     OR = 369,
     NOT = 370,
     XOR = 371,
     EQV = 372,
     IMP = 373,
     CMP_LE = 374,
     CMP_GE = 375,
     CMP_NE = 376,
     HASH = 377,
     ADR = 378,
     FRE = 379,
     SPC = 380,
     TAB = 381,
     POS = 382,
     USR = 383,
     LIN = 384,
     TRAP = 385,
     RESUME = 386,
     ERROR = 387,
     RAISE = 388,
     ERR = 389,
     EL = 390,
     ER = 391,
     DEFSTR = 392,
     DEFINT = 393,
     DEFSNG = 394,
     DEFDBL = 395,
     CHANGE = 396,
     CONVERT = 397,
     UCASE = 398,
     LCASE = 399,
     STRNG = 400,
     TIME = 401,
     TIME_STR = 402,
     HEX = 403,
     OCT = 404,
     BIN = 405,
     HEXSTR = 406,
     OCTSTR = 407,
     BINSTR = 408,
     UBOUND = 409,
     LBOUND = 410,
     LABEL = 411,
     MAT = 412,
     MATPRINT = 413,
     MATINPUT = 414,
     MATREAD = 415,
     MATGET = 416,
     MATPUT = 417,
     MATZER = 418,
     MATNUL = 419,
     MATCON = 420,
     MATIDN = 421,
     MATTRN = 422,
     MATINV = 423,
     MATDET = 424,
     MATADD = 425,
     MATSUB = 426,
     MATMUL = 427,
     MATSCA = 428,
     MATFIL = 429,
     NUM = 430
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
#define REDIM 277
#define END 278
#define EXIT 279
#define FOR 280
#define GET 281
#define GOSUB 282
#define GOTO 283
#define IF 284
#define INPUT 285
#define INPUT_LINE 286
#define LET 287
#define LIST 288
#define NEXT 289
#define NEW 290
#define OF 291
#define ON 292
#define PRINT 293
#define PUT 294
#define READ 295
#define RETURN 296
#define RUN 297
#define STEP 298
#define STOP 299
#define THEN 300
#define TO 301
#define USING 302
#define WAIT 303
#define OPEN 304
#define CLOSE 305
#define STATUS 306
#define PRINT_FILE 307
#define INPUT_FILE 308
#define GET_FILE 309
#define PUT_FILE 310
#define _EOF 311
#define CALL 312
#define CLS 313
#define CMD 314
#define OPTION 315
#define BASE 316
#define PEEK 317
#define POKE 318
#define POP 319
#define RANDOMIZE 320
#define SYS 321
#define VARLIST 322
#define PAUSE 323
#define PRESERVE 324
#define SLEEP 325
#define RESTORE 326
#define ABS 327
#define SGN 328
#define CLOG 329
#define EXP 330
#define LOG 331
#define SQR 332
#define PI 333
#define RND 334
#define INT 335
#define FIX 336
#define FRAC 337
#define ROUND 338
#define CINT 339
#define CSNG 340
#define CDBL 341
#define MOD 342
#define MOD_INT 343
#define DIV 344
#define MAX 345
#define MIN 346
#define COS 347
#define SIN 348
#define ATN 349
#define ACS 350
#define ASN 351
#define TAN 352
#define COSH 353
#define SINH 354
#define TANH 355
#define ASC 356
#define LEFT 357
#define MID 358
#define RIGHT 359
#define LEN 360
#define STR 361
#define VAL 362
#define CHR 363
#define SEG 364
#define SUBSTR 365
#define INSTR 366
#define INKEY 367
#define AND 368
#define OR 369
#define NOT 370
#define XOR 371
#define EQV 372
#define IMP 373
#define CMP_LE 374
#define CMP_GE 375
#define CMP_NE 376
#define HASH 377
#define ADR 378
#define FRE 379
#define SPC 380
#define TAB 381
#define POS 382
#define USR 383
#define LIN 384
#define TRAP 385
#define RESUME 386
#define ERROR 387
#define RAISE 388
#define ERR 389
#define EL 390
#define ER 391
#define DEFSTR 392
#define DEFINT 393
#define DEFSNG 394
#define DEFDBL 395
#define CHANGE 396
#define CONVERT 397
#define UCASE 398
#define LCASE 399
#define STRNG 400
#define TIME 401
#define TIME_STR 402
#define HEX 403
#define OCT 404
#define BIN 405
#define HEXSTR 406
#define OCTSTR 407
#define BINSTR 408
#define UBOUND 409
#define LBOUND 410
#define LABEL 411
#define MAT 412
#define MATPRINT 413
#define MATINPUT 414
#define MATREAD 415
#define MATGET 416
#define MATPUT 417
#define MATZER 418
#define MATNUL 419
#define MATCON 420
#define MATIDN 421
#define MATTRN 422
#define MATINV 423
#define MATDET 424
#define MATADD 425
#define MATSUB 426
#define MATMUL 427
#define MATSCA 428
#define MATFIL 429
#define NUM 430




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 80 "src/parse.y"
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
#line 409 "src/parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


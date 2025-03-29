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
     INPUT_LINE = 285,
     LET = 286,
     LIST = 287,
     NEXT = 288,
     NEW = 289,
     OF = 290,
     ON = 291,
     PRINT = 292,
     PUT = 293,
     READ = 294,
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
     _EOF = 310,
     CALL = 311,
     CLS = 312,
     CMD = 313,
     OPTION = 314,
     BASE = 315,
     PEEK = 316,
     POKE = 317,
     POP = 318,
     RANDOMIZE = 319,
     SYS = 320,
     VARLIST = 321,
     PAUSE = 322,
     SLEEP = 323,
     RESTORE = 324,
     ABS = 325,
     SGN = 326,
     CLOG = 327,
     EXP = 328,
     LOG = 329,
     SQR = 330,
     PI = 331,
     RND = 332,
     INT = 333,
     FIX = 334,
     FRAC = 335,
     ROUND = 336,
     CINT = 337,
     CSNG = 338,
     CDBL = 339,
     MOD = 340,
     MOD_INT = 341,
     DIV = 342,
     MAX = 343,
     MIN = 344,
     COS = 345,
     SIN = 346,
     ATN = 347,
     ACS = 348,
     ASN = 349,
     TAN = 350,
     COSH = 351,
     SINH = 352,
     TANH = 353,
     ASC = 354,
     LEFT = 355,
     MID = 356,
     RIGHT = 357,
     LEN = 358,
     STR = 359,
     VAL = 360,
     CHR = 361,
     SEG = 362,
     SUBSTR = 363,
     INSTR = 364,
     INKEY = 365,
     AND = 366,
     OR = 367,
     NOT = 368,
     XOR = 369,
     EQV = 370,
     IMP = 371,
     CMP_LE = 372,
     CMP_GE = 373,
     CMP_NE = 374,
     HASH = 375,
     ADR = 376,
     FRE = 377,
     SPC = 378,
     TAB = 379,
     POS = 380,
     USR = 381,
     LIN = 382,
     TRAP = 383,
     RESUME = 384,
     ERROR = 385,
     RAISE = 386,
     ERR = 387,
     EL = 388,
     ER = 389,
     DEFSTR = 390,
     DEFINT = 391,
     DEFSNG = 392,
     DEFDBL = 393,
     CHANGE = 394,
     CONVERT = 395,
     UCASE = 396,
     LCASE = 397,
     STRNG = 398,
     TIME = 399,
     TIME_STR = 400,
     HEX = 401,
     OCT = 402,
     BIN = 403,
     HEXSTR = 404,
     OCTSTR = 405,
     BINSTR = 406,
     UBOUND = 407,
     LBOUND = 408,
     LABEL = 409,
     MAT = 410,
     MATPRINT = 411,
     MATINPUT = 412,
     MATREAD = 413,
     MATGET = 414,
     MATPUT = 415,
     MATZER = 416,
     MATCON = 417,
     MATIDN = 418,
     MATTRN = 419,
     MATINV = 420,
     MATDET = 421,
     MATADD = 422,
     MATSUB = 423,
     MATMUL = 424,
     MATSCA = 425,
     MATFIL = 426,
     NUM = 427
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
#define INPUT_LINE 285
#define LET 286
#define LIST 287
#define NEXT 288
#define NEW 289
#define OF 290
#define ON 291
#define PRINT 292
#define PUT 293
#define READ 294
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
#define _EOF 310
#define CALL 311
#define CLS 312
#define CMD 313
#define OPTION 314
#define BASE 315
#define PEEK 316
#define POKE 317
#define POP 318
#define RANDOMIZE 319
#define SYS 320
#define VARLIST 321
#define PAUSE 322
#define SLEEP 323
#define RESTORE 324
#define ABS 325
#define SGN 326
#define CLOG 327
#define EXP 328
#define LOG 329
#define SQR 330
#define PI 331
#define RND 332
#define INT 333
#define FIX 334
#define FRAC 335
#define ROUND 336
#define CINT 337
#define CSNG 338
#define CDBL 339
#define MOD 340
#define MOD_INT 341
#define DIV 342
#define MAX 343
#define MIN 344
#define COS 345
#define SIN 346
#define ATN 347
#define ACS 348
#define ASN 349
#define TAN 350
#define COSH 351
#define SINH 352
#define TANH 353
#define ASC 354
#define LEFT 355
#define MID 356
#define RIGHT 357
#define LEN 358
#define STR 359
#define VAL 360
#define CHR 361
#define SEG 362
#define SUBSTR 363
#define INSTR 364
#define INKEY 365
#define AND 366
#define OR 367
#define NOT 368
#define XOR 369
#define EQV 370
#define IMP 371
#define CMP_LE 372
#define CMP_GE 373
#define CMP_NE 374
#define HASH 375
#define ADR 376
#define FRE 377
#define SPC 378
#define TAB 379
#define POS 380
#define USR 381
#define LIN 382
#define TRAP 383
#define RESUME 384
#define ERROR 385
#define RAISE 386
#define ERR 387
#define EL 388
#define ER 389
#define DEFSTR 390
#define DEFINT 391
#define DEFSNG 392
#define DEFDBL 393
#define CHANGE 394
#define CONVERT 395
#define UCASE 396
#define LCASE 397
#define STRNG 398
#define TIME 399
#define TIME_STR 400
#define HEX 401
#define OCT 402
#define BIN 403
#define HEXSTR 404
#define OCTSTR 405
#define BINSTR 406
#define UBOUND 407
#define LBOUND 408
#define LABEL 409
#define MAT 410
#define MATPRINT 411
#define MATINPUT 412
#define MATREAD 413
#define MATGET 414
#define MATPUT 415
#define MATZER 416
#define MATCON 417
#define MATIDN 418
#define MATTRN 419
#define MATINV 420
#define MATDET 421
#define MATADD 422
#define MATSUB 423
#define MATMUL 424
#define MATSCA 425
#define MATFIL 426
#define NUM 427




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 80 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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
#line 403 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/DerivedData/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
    YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


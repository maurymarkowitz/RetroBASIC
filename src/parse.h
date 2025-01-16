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
     RETURN = 294,
     RUN = 295,
     STEP = 296,
     STOP = 297,
     THEN = 298,
     TO = 299,
     USING = 300,
     WAIT = 301,
     OPEN = 302,
     CLOSE = 303,
     STATUS = 304,
     PRINT_FILE = 305,
     INPUT_FILE = 306,
     GET_FILE = 307,
     PUT_FILE = 308,
     _EOF = 309,
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
     SLEEP = 322,
     RESTORE = 323,
     ABS = 324,
     SGN = 325,
     CLOG = 326,
     EXP = 327,
     LOG = 328,
     SQR = 329,
     PI = 330,
     RND = 331,
     INT = 332,
     FIX = 333,
     FRAC = 334,
     ROUND = 335,
     CINT = 336,
     CSNG = 337,
     CDBL = 338,
     MOD = 339,
     MOD_INT = 340,
     DIV = 341,
     MAX = 342,
     MIN = 343,
     COS = 344,
     SIN = 345,
     ATN = 346,
     ACS = 347,
     ASN = 348,
     TAN = 349,
     COSH = 350,
     SINH = 351,
     TANH = 352,
     ASC = 353,
     LEFT = 354,
     MID = 355,
     RIGHT = 356,
     LEN = 357,
     STR = 358,
     VAL = 359,
     CHR = 360,
     SEG = 361,
     SUBSTR = 362,
     INSTR = 363,
     INKEY = 364,
     AND = 365,
     OR = 366,
     NOT = 367,
     XOR = 368,
     EQV = 369,
     IMP = 370,
     CMP_LE = 371,
     CMP_GE = 372,
     CMP_NE = 373,
     CMP_HASH = 374,
     ADR = 375,
     FRE = 376,
     SPC = 377,
     TAB = 378,
     POS = 379,
     USR = 380,
     LIN = 381,
     TRAP = 382,
     RESUME = 383,
     ERROR = 384,
     RAISE = 385,
     ERR = 386,
     EL = 387,
     ER = 388,
     DEFSTR = 389,
     DEFINT = 390,
     DEFSNG = 391,
     DEFDBL = 392,
     CHANGE = 393,
     CONVERT = 394,
     UCASE = 395,
     LCASE = 396,
     STRNG = 397,
     TIME = 398,
     TIME_STR = 399,
     HEX = 400,
     OCT = 401,
     BIN = 402,
     HEXSTR = 403,
     OCTSTR = 404,
     BINSTR = 405,
     UBOUND = 406,
     LBOUND = 407,
     LABEL = 408,
     MAT = 409,
     MATPRINT = 410,
     MATINPUT = 411,
     MATREAD = 412,
     MATGET = 413,
     MATPUT = 414,
     MATZER = 415,
     MATCON = 416,
     MATIDN = 417,
     MATTRN = 418,
     MATINV = 419,
     MATDET = 420,
     MATADD = 421,
     MATSUB = 422,
     MATMUL = 423,
     MATSCA = 424,
     MATFIL = 425,
     NUM = 426
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
#define RETURN 294
#define RUN 295
#define STEP 296
#define STOP 297
#define THEN 298
#define TO 299
#define USING 300
#define WAIT 301
#define OPEN 302
#define CLOSE 303
#define STATUS 304
#define PRINT_FILE 305
#define INPUT_FILE 306
#define GET_FILE 307
#define PUT_FILE 308
#define _EOF 309
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
#define SLEEP 322
#define RESTORE 323
#define ABS 324
#define SGN 325
#define CLOG 326
#define EXP 327
#define LOG 328
#define SQR 329
#define PI 330
#define RND 331
#define INT 332
#define FIX 333
#define FRAC 334
#define ROUND 335
#define CINT 336
#define CSNG 337
#define CDBL 338
#define MOD 339
#define MOD_INT 340
#define DIV 341
#define MAX 342
#define MIN 343
#define COS 344
#define SIN 345
#define ATN 346
#define ACS 347
#define ASN 348
#define TAN 349
#define COSH 350
#define SINH 351
#define TANH 352
#define ASC 353
#define LEFT 354
#define MID 355
#define RIGHT 356
#define LEN 357
#define STR 358
#define VAL 359
#define CHR 360
#define SEG 361
#define SUBSTR 362
#define INSTR 363
#define INKEY 364
#define AND 365
#define OR 366
#define NOT 367
#define XOR 368
#define EQV 369
#define IMP 370
#define CMP_LE 371
#define CMP_GE 372
#define CMP_NE 373
#define CMP_HASH 374
#define ADR 375
#define FRE 376
#define SPC 377
#define TAB 378
#define POS 379
#define USR 380
#define LIN 381
#define TRAP 382
#define RESUME 383
#define ERROR 384
#define RAISE 385
#define ERR 386
#define EL 387
#define ER 388
#define DEFSTR 389
#define DEFINT 390
#define DEFSNG 391
#define DEFDBL 392
#define CHANGE 393
#define CONVERT 394
#define UCASE 395
#define LCASE 396
#define STRNG 397
#define TIME 398
#define TIME_STR 399
#define HEX 400
#define OCT 401
#define BIN 402
#define HEXSTR 403
#define OCTSTR 404
#define BINSTR 405
#define UBOUND 406
#define LBOUND 407
#define LABEL 408
#define MAT 409
#define MATPRINT 410
#define MATINPUT 411
#define MATREAD 412
#define MATGET 413
#define MATPUT 414
#define MATZER 415
#define MATCON 416
#define MATIDN 417
#define MATTRN 418
#define MATINV 419
#define MATDET 420
#define MATADD 421
#define MATSUB 422
#define MATMUL 423
#define MATSCA 424
#define MATFIL 425
#define NUM 426




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
#line 401 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/DerivedData/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
    YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


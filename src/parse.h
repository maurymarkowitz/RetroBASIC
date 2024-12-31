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
     CALL = 309,
     CLS = 310,
     CMD = 311,
     OPTION = 312,
     BASE = 313,
     PEEK = 314,
     POKE = 315,
     POP = 316,
     RANDOMIZE = 317,
     SYS = 318,
     VARLIST = 319,
     PAUSE = 320,
     SLEEP = 321,
     RESTORE = 322,
     ABS = 323,
     SGN = 324,
     CLOG = 325,
     EXP = 326,
     LOG = 327,
     SQR = 328,
     PI = 329,
     RND = 330,
     INT = 331,
     FIX = 332,
     FRAC = 333,
     ROUND = 334,
     CINT = 335,
     CSNG = 336,
     CDBL = 337,
     MOD = 338,
     MOD_INT = 339,
     DIV = 340,
     MAX = 341,
     MIN = 342,
     COS = 343,
     SIN = 344,
     ATN = 345,
     ACS = 346,
     ASN = 347,
     TAN = 348,
     COSH = 349,
     SINH = 350,
     TANH = 351,
     ASC = 352,
     LEFT = 353,
     MID = 354,
     RIGHT = 355,
     LEN = 356,
     STR = 357,
     VAL = 358,
     CHR = 359,
     SEG = 360,
     SUBSTR = 361,
     INSTR = 362,
     INKEY = 363,
     AND = 364,
     OR = 365,
     NOT = 366,
     XOR = 367,
     EQV = 368,
     IMP = 369,
     CMP_LE = 370,
     CMP_GE = 371,
     CMP_NE = 372,
     CMP_HASH = 373,
     ADR = 374,
     FRE = 375,
     SPC = 376,
     TAB = 377,
     POS = 378,
     USR = 379,
     LIN = 380,
     TRAP = 381,
     RESUME = 382,
     ERROR = 383,
     RAISE = 384,
     ERR = 385,
     EL = 386,
     ER = 387,
     DEFSTR = 388,
     DEFINT = 389,
     DEFSNG = 390,
     DEFDBL = 391,
     CHANGE = 392,
     CONVERT = 393,
     UCASE = 394,
     LCASE = 395,
     STRNG = 396,
     TIME = 397,
     TIME_STR = 398,
     HEX = 399,
     OCT = 400,
     BIN = 401,
     HEXSTR = 402,
     OCTSTR = 403,
     BINSTR = 404,
     UBOUND = 405,
     LBOUND = 406,
     LABEL = 407,
     MAT = 408,
     MATPRINT = 409,
     MATINPUT = 410,
     MATREAD = 411,
     MATGET = 412,
     MATPUT = 413,
     MATZER = 414,
     MATCON = 415,
     MATIDN = 416,
     MATTRN = 417,
     MATINV = 418,
     MATDET = 419,
     MATADD = 420,
     MATSUB = 421,
     MATMUL = 422,
     MATSCA = 423,
     MATFIL = 424,
     NUM = 425
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
#define CALL 309
#define CLS 310
#define CMD 311
#define OPTION 312
#define BASE 313
#define PEEK 314
#define POKE 315
#define POP 316
#define RANDOMIZE 317
#define SYS 318
#define VARLIST 319
#define PAUSE 320
#define SLEEP 321
#define RESTORE 322
#define ABS 323
#define SGN 324
#define CLOG 325
#define EXP 326
#define LOG 327
#define SQR 328
#define PI 329
#define RND 330
#define INT 331
#define FIX 332
#define FRAC 333
#define ROUND 334
#define CINT 335
#define CSNG 336
#define CDBL 337
#define MOD 338
#define MOD_INT 339
#define DIV 340
#define MAX 341
#define MIN 342
#define COS 343
#define SIN 344
#define ATN 345
#define ACS 346
#define ASN 347
#define TAN 348
#define COSH 349
#define SINH 350
#define TANH 351
#define ASC 352
#define LEFT 353
#define MID 354
#define RIGHT 355
#define LEN 356
#define STR 357
#define VAL 358
#define CHR 359
#define SEG 360
#define SUBSTR 361
#define INSTR 362
#define INKEY 363
#define AND 364
#define OR 365
#define NOT 366
#define XOR 367
#define EQV 368
#define IMP 369
#define CMP_LE 370
#define CMP_GE 371
#define CMP_NE 372
#define CMP_HASH 373
#define ADR 374
#define FRE 375
#define SPC 376
#define TAB 377
#define POS 378
#define USR 379
#define LIN 380
#define TRAP 381
#define RESUME 382
#define ERROR 383
#define RAISE 384
#define ERR 385
#define EL 386
#define ER 387
#define DEFSTR 388
#define DEFINT 389
#define DEFSNG 390
#define DEFDBL 391
#define CHANGE 392
#define CONVERT 393
#define UCASE 394
#define LCASE 395
#define STRNG 396
#define TIME 397
#define TIME_STR 398
#define HEX 399
#define OCT 400
#define BIN 401
#define HEXSTR 402
#define OCTSTR 403
#define BINSTR 404
#define UBOUND 405
#define LBOUND 406
#define LABEL 407
#define MAT 408
#define MATPRINT 409
#define MATINPUT 410
#define MATREAD 411
#define MATGET 412
#define MATPUT 413
#define MATZER 414
#define MATCON 415
#define MATIDN 416
#define MATTRN 417
#define MATINV 418
#define MATDET 419
#define MATADD 420
#define MATSUB 421
#define MATMUL 422
#define MATSCA 423
#define MATFIL 424
#define NUM 425



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
#line 397 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
    YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


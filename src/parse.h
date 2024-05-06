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
     COS = 341,
     SIN = 342,
     ATN = 343,
     ACS = 344,
     ASN = 345,
     TAN = 346,
     COSH = 347,
     SINH = 348,
     TANH = 349,
     ASC = 350,
     LEFT = 351,
     MID = 352,
     RIGHT = 353,
     LEN = 354,
     STR = 355,
     VAL = 356,
     CHR = 357,
     SEG = 358,
     SUBSTR = 359,
     INSTR = 360,
     INKEY = 361,
     AND = 362,
     OR = 363,
     NOT = 364,
     XOR = 365,
     EQV = 366,
     IMP = 367,
     CMP_LE = 368,
     CMP_GE = 369,
     CMP_NE = 370,
     CMP_HASH = 371,
     ADR = 372,
     FRE = 373,
     SPC = 374,
     TAB = 375,
     POS = 376,
     USR = 377,
     LIN = 378,
     TRAP = 379,
     RESUME = 380,
     ERROR = 381,
     DEFSTR = 382,
     DEFINT = 383,
     DEFSNG = 384,
     DEFDBL = 385,
     CHANGE = 386,
     CONVERT = 387,
     UCASE = 388,
     LCASE = 389,
     STRNG = 390,
     TIME = 391,
     TIME_STR = 392,
     HEX = 393,
     OCT = 394,
     BIN = 395,
     HEXSTR = 396,
     OCTSTR = 397,
     BINSTR = 398,
     UBOUND = 399,
     LBOUND = 400,
     LABEL = 401,
     MAT = 402,
     MATPRINT = 403,
     MATINPUT = 404,
     MATREAD = 405,
     MATGET = 406,
     MATPUT = 407,
     MATZER = 408,
     MATCON = 409,
     MATIDN = 410,
     MATTRN = 411,
     MATINV = 412,
     MATDET = 413
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
#define COS 341
#define SIN 342
#define ATN 343
#define ACS 344
#define ASN 345
#define TAN 346
#define COSH 347
#define SINH 348
#define TANH 349
#define ASC 350
#define LEFT 351
#define MID 352
#define RIGHT 353
#define LEN 354
#define STR 355
#define VAL 356
#define CHR 357
#define SEG 358
#define SUBSTR 359
#define INSTR 360
#define INKEY 361
#define AND 362
#define OR 363
#define NOT 364
#define XOR 365
#define EQV 366
#define IMP 367
#define CMP_LE 368
#define CMP_GE 369
#define CMP_NE 370
#define CMP_HASH 371
#define ADR 372
#define FRE 373
#define SPC 374
#define TAB 375
#define POS 376
#define USR 377
#define LIN 378
#define TRAP 379
#define RESUME 380
#define ERROR 381
#define DEFSTR 382
#define DEFINT 383
#define DEFSNG 384
#define DEFDBL 385
#define CHANGE 386
#define CONVERT 387
#define UCASE 388
#define LCASE 389
#define STRNG 390
#define TIME 391
#define TIME_STR 392
#define HEX 393
#define OCT 394
#define BIN 395
#define HEXSTR 396
#define OCTSTR 397
#define BINSTR 398
#define UBOUND 399
#define LBOUND 400
#define LABEL 401
#define MAT 402
#define MATPRINT 403
#define MATINPUT 404
#define MATREAD 405
#define MATGET 406
#define MATPUT 407
#define MATZER 408
#define MATCON 409
#define MATIDN 410
#define MATTRN 411
#define MATINV 412
#define MATDET 413




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
#line 375 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
    YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


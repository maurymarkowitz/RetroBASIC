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
     SLEEP = 322,
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
     DEFSTR = 379,
     DEFINT = 380,
     DEFSNG = 381,
     DEFDBL = 382,
     CHANGE = 383,
     CONVERT = 384,
     UCASE = 385,
     LCASE = 386,
     STRNG = 387,
     TIME = 388,
     TIME_STR = 389,
     HEX = 390,
     OCT = 391,
     BIN = 392,
     HEXSTR = 393,
     OCTSTR = 394,
     BINSTR = 395,
     UBOUND = 396,
     LBOUND = 397,
     LABEL = 398,
     MAT = 399,
     MATPRINT = 400,
     MATINPUT = 401,
     MATREAD = 402,
     MATGET = 403,
     MATPUT = 404,
     MATZER = 405,
     MATCON = 406,
     MATIDN = 407,
     MATTRN = 408,
     MATINV = 409,
     MATDET = 410
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
#define SLEEP 322
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
#define DEFSTR 379
#define DEFINT 380
#define DEFSNG 381
#define DEFDBL 382
#define CHANGE 383
#define CONVERT 384
#define UCASE 385
#define LCASE 386
#define STRNG 387
#define TIME 388
#define TIME_STR 389
#define HEX 390
#define OCT 391
#define BIN 392
#define HEXSTR 393
#define OCTSTR 394
#define BINSTR 395
#define UBOUND 396
#define LBOUND 397
#define LABEL 398
#define MAT 399
#define MATPRINT 400
#define MATINPUT 401
#define MATREAD 402
#define MATGET 403
#define MATPUT 404
#define MATZER 405
#define MATCON 406
#define MATIDN 407
#define MATTRN 408
#define MATINV 409
#define MATDET 410




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 73 "/Users/maury/Documents/RetroBASIC/src/parse.y"
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
#line 369 "/Users/maury/Documents/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


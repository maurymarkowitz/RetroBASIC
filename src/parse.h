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
     COS = 338,
     SIN = 339,
     ATN = 340,
     ACS = 341,
     ASN = 342,
     TAN = 343,
     COSH = 344,
     SINH = 345,
     TANH = 346,
     ASC = 347,
     LEFT = 348,
     MID = 349,
     RIGHT = 350,
     LEN = 351,
     STR = 352,
     VAL = 353,
     CHR = 354,
     SEG = 355,
     SUBSTR = 356,
     INSTR = 357,
     INKEY = 358,
     AND = 359,
     OR = 360,
     NOT = 361,
     XOR = 362,
     CMP_LE = 363,
     CMP_GE = 364,
     CMP_NE = 365,
     CMP_HASH = 366,
     FRE = 367,
     SPC = 368,
     TAB = 369,
     POS = 370,
     USR = 371,
     LIN = 372,
     DEFSTR = 373,
     DEFINT = 374,
     DEFSNG = 375,
     DEFDBL = 376,
     CHANGE = 377,
     CONVERT = 378,
     UCASE = 379,
     LCASE = 380,
     STRNG = 381,
     TIME = 382,
     TIME_STR = 383,
     HEX = 384,
     OCT = 385,
     BIN = 386,
     HEXSTR = 387,
     OCTSTR = 388,
     BINSTR = 389,
     UBOUND = 390,
     LBOUND = 391,
     LABEL = 392
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
#define COS 338
#define SIN 339
#define ATN 340
#define ACS 341
#define ASN 342
#define TAN 343
#define COSH 344
#define SINH 345
#define TANH 346
#define ASC 347
#define LEFT 348
#define MID 349
#define RIGHT 350
#define LEN 351
#define STR 352
#define VAL 353
#define CHR 354
#define SEG 355
#define SUBSTR 356
#define INSTR 357
#define INKEY 358
#define AND 359
#define OR 360
#define NOT 361
#define XOR 362
#define CMP_LE 363
#define CMP_GE 364
#define CMP_NE 365
#define CMP_HASH 366
#define FRE 367
#define SPC 368
#define TAB 369
#define POS 370
#define USR 371
#define LIN 372
#define DEFSTR 373
#define DEFINT 374
#define DEFSNG 375
#define DEFDBL 376
#define CHANGE 377
#define CONVERT 378
#define UCASE 379
#define LCASE 380
#define STRNG 381
#define TIME 382
#define TIME_STR 383
#define HEX 384
#define OCT 385
#define BIN 386
#define HEXSTR 387
#define OCTSTR 388
#define BINSTR 389
#define UBOUND 390
#define LBOUND 391
#define LABEL 392




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
#line 333 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
    YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


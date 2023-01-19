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
     REM = 265,
     QUOTEREM = 266,
     BANGREM = 267,
     BYE = 268,
     CLEAR = 269,
     CLR = 270,
     DATA = 271,
     DEF = 272,
     DIM = 273,
     END = 274,
     EXIT = 275,
     FOR = 276,
     GET = 277,
     GOSUB = 278,
     GOTO = 279,
     IF = 280,
     INPUT = 281,
     LET = 282,
     LIST = 283,
     NEXT = 284,
     NEW = 285,
     OF = 286,
     ON = 287,
     PRINT = 288,
     PUT = 289,
     READ = 290,
     RESTORE = 291,
     RETURN = 292,
     RUN = 293,
     STEP = 294,
     STOP = 295,
     THEN = 296,
     TO = 297,
     USING = 298,
     WAIT = 299,
     OPEN = 300,
     CLOSE = 301,
     STATUS = 302,
     PRINT_FILE = 303,
     INPUT_FILE = 304,
     GET_FILE = 305,
     PUT_FILE = 306,
     CALL = 307,
     CLS = 308,
     CMD = 309,
     OPTION = 310,
     BASE = 311,
     PEEK = 312,
     POKE = 313,
     POP = 314,
     RANDOMIZE = 315,
     SYS = 316,
     VARLIST = 317,
     _ABS = 318,
     SGN = 319,
     ATN = 320,
     COS = 321,
     SIN = 322,
     TAN = 323,
     CLOG = 324,
     EXP = 325,
     LOG = 326,
     SQR = 327,
     RND = 328,
     INT = 329,
     FIX = 330,
     FRAC = 331,
     CINT = 332,
     CSNG = 333,
     CDBL = 334,
     ASC = 335,
     LEFT = 336,
     MID = 337,
     RIGHT = 338,
     LEN = 339,
     STR = 340,
     VAL = 341,
     CHR = 342,
     SEG = 343,
     SUBSTR = 344,
     AND = 345,
     OR = 346,
     NOT = 347,
     XOR = 348,
     CMP_LE = 349,
     CMP_GE = 350,
     CMP_NE = 351,
     CMP_HASH = 352,
     FRE = 353,
     SPC = 354,
     TAB = 355,
     POS = 356,
     USR = 357,
     LIN = 358,
     DEFSTR = 359,
     DEFINT = 360,
     DEFSNG = 361,
     DEFDBL = 362,
     CHANGE = 363,
     CONVERT = 364,
     UCASE = 365,
     LCASE = 366,
     STRNG = 367,
     TIME = 368,
     TIME_STR = 369
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
#define REM 265
#define QUOTEREM 266
#define BANGREM 267
#define BYE 268
#define CLEAR 269
#define CLR 270
#define DATA 271
#define DEF 272
#define DIM 273
#define END 274
#define EXIT 275
#define FOR 276
#define GET 277
#define GOSUB 278
#define GOTO 279
#define IF 280
#define INPUT 281
#define LET 282
#define LIST 283
#define NEXT 284
#define NEW 285
#define OF 286
#define ON 287
#define PRINT 288
#define PUT 289
#define READ 290
#define RESTORE 291
#define RETURN 292
#define RUN 293
#define STEP 294
#define STOP 295
#define THEN 296
#define TO 297
#define USING 298
#define WAIT 299
#define OPEN 300
#define CLOSE 301
#define STATUS 302
#define PRINT_FILE 303
#define INPUT_FILE 304
#define GET_FILE 305
#define PUT_FILE 306
#define CALL 307
#define CLS 308
#define CMD 309
#define OPTION 310
#define BASE 311
#define PEEK 312
#define POKE 313
#define POP 314
#define RANDOMIZE 315
#define SYS 316
#define VARLIST 317
#define _ABS 318
#define SGN 319
#define ATN 320
#define COS 321
#define SIN 322
#define TAN 323
#define CLOG 324
#define EXP 325
#define LOG 326
#define SQR 327
#define RND 328
#define INT 329
#define FIX 330
#define FRAC 331
#define CINT 332
#define CSNG 333
#define CDBL 334
#define ASC 335
#define LEFT 336
#define MID 337
#define RIGHT 338
#define LEN 339
#define STR 340
#define VAL 341
#define CHR 342
#define SEG 343
#define SUBSTR 344
#define AND 345
#define OR 346
#define NOT 347
#define XOR 348
#define CMP_LE 349
#define CMP_GE 350
#define CMP_NE 351
#define CMP_HASH 352
#define FRE 353
#define SPC 354
#define TAB 355
#define POS 356
#define USR 357
#define LIN 358
#define DEFSTR 359
#define DEFINT 360
#define DEFSNG 361
#define DEFDBL 362
#define CHANGE 363
#define CONVERT 364
#define UCASE 365
#define LCASE 366
#define STRNG 367
#define TIME 368
#define TIME_STR 369




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
  variable_t *variable;
}
/* Line 1529 of yacc.c.  */
#line 287 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
    YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


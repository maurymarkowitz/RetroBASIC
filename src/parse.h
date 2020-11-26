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
     NUMBER = 258,
     STRING = 259,
     VARIABLE_NAME = 260,
     FUNCTION_NAME = 261,
     BREAK = 262,
     BYE = 263,
     CALL = 264,
     CLEAR = 265,
     CLS = 266,
     CMD = 267,
     DATA = 268,
     DEF = 269,
     DIM = 270,
     END = 271,
     EXIT = 272,
     FOR = 273,
     GET = 274,
     GOSUB = 275,
     GOTO = 276,
     IF = 277,
     INPUT = 278,
     LET = 279,
     LIST = 280,
     NEXT = 281,
     NEW = 282,
     ON = 283,
     PEEK = 284,
     POKE = 285,
     POP = 286,
     PRINT = 287,
     PUT = 288,
     READ = 289,
     REM = 290,
     RESTORE = 291,
     RETURN = 292,
     RUN = 293,
     SHORTREM = 294,
     STEP = 295,
     STOP = 296,
     SYS = 297,
     THEN = 298,
     TO = 299,
     USING = 300,
     VARLIST = 301,
     WAIT = 302,
     OPEN = 303,
     CLOSE = 304,
     STATUS = 305,
     PRINT_FILE = 306,
     INPUT_FILE = 307,
     GET_FILE = 308,
     PUT_FILE = 309,
     _ABS = 310,
     SGN = 311,
     ATN = 312,
     COS = 313,
     SIN = 314,
     TAN = 315,
     CLOG = 316,
     EXP = 317,
     LOG = 318,
     SQR = 319,
     RND = 320,
     INT = 321,
     FIX = 322,
     CINT = 323,
     CSNG = 324,
     CDBL = 325,
     ASC = 326,
     LEFT = 327,
     MID = 328,
     RIGHT = 329,
     LEN = 330,
     STR = 331,
     VAL = 332,
     CHR = 333,
     AND = 334,
     OR = 335,
     NOT = 336,
     XOR = 337,
     CMP_LE = 338,
     CMP_GE = 339,
     CMP_NE = 340,
     CMP_HASH = 341,
     FRE = 342,
     SPC = 343,
     TAB = 344,
     POS = 345,
     USR = 346
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define STRING 259
#define VARIABLE_NAME 260
#define FUNCTION_NAME 261
#define BREAK 262
#define BYE 263
#define CALL 264
#define CLEAR 265
#define CLS 266
#define CMD 267
#define DATA 268
#define DEF 269
#define DIM 270
#define END 271
#define EXIT 272
#define FOR 273
#define GET 274
#define GOSUB 275
#define GOTO 276
#define IF 277
#define INPUT 278
#define LET 279
#define LIST 280
#define NEXT 281
#define NEW 282
#define ON 283
#define PEEK 284
#define POKE 285
#define POP 286
#define PRINT 287
#define PUT 288
#define READ 289
#define REM 290
#define RESTORE 291
#define RETURN 292
#define RUN 293
#define SHORTREM 294
#define STEP 295
#define STOP 296
#define SYS 297
#define THEN 298
#define TO 299
#define USING 300
#define VARLIST 301
#define WAIT 302
#define OPEN 303
#define CLOSE 304
#define STATUS 305
#define PRINT_FILE 306
#define INPUT_FILE 307
#define GET_FILE 308
#define PUT_FILE 309
#define _ABS 310
#define SGN 311
#define ATN 312
#define COS 313
#define SIN 314
#define TAN 315
#define CLOG 316
#define EXP 317
#define LOG 318
#define SQR 319
#define RND 320
#define INT 321
#define FIX 322
#define CINT 323
#define CSNG 324
#define CDBL 325
#define ASC 326
#define LEFT 327
#define MID 328
#define RIGHT 329
#define LEN 330
#define STR 331
#define VAL 332
#define CHR 333
#define AND 334
#define OR 335
#define NOT 336
#define XOR 337
#define CMP_LE 338
#define CMP_GE 339
#define CMP_NE 340
#define CMP_HASH 341
#define FRE 342
#define SPC 343
#define TAB 344
#define POS 345
#define USR 346




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 71 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
{
  double d;
  int i;
  GString *s;
  GList *l;
  statement_t *statement;
  expression_t *expression;
  variable_t *variable;
}
/* Line 1529 of yacc.c.  */
#line 241 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


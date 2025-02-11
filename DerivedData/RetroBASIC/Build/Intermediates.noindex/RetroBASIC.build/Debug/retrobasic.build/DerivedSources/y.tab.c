/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     HASH = 374,
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
#define HASH 374
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




/* Copy the first part of user declarations.  */
#line 1 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"

/* Parser for RetroBASIC
   Copyright (C) 2020 Maury Markowitz
      
   Based on gnbasic
   Copyright (C) 1998 James Bowman
    
This file is part of RetroBASIC.

RetroBASIC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

RetroBASIC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RetroBASIC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/**
 * @file parse.y
 * @author Maury Markowitz
 * @brief yacc/bison parser
 *
 */

#include "retrobasic.h"
#include "statistics.h"

#define YYDEBUG 1

 /* used to track the line number being processed so
    that errors can report it */
static double errline;

void yyerror(const char *message)
{
  fprintf(stderr, "Syntax error at line %g: %s\n", errline, message);
  exit(1);
}

int yylex(void);

static statement_t *make_statement(int t)
{
  statement_t *new = malloc(sizeof(*new));
  new->type = t;
  return new;
}

static expression_t *make_expression(expression_type_t t)
{
  expression_t *new = malloc(sizeof(*new));
  new->type = t;
  return new;
}

static expression_t *make_operator(int arity, int o)
{
  expression_t *new = make_expression(op);
  new->parms.op.opcode = o;
  new->parms.op.arity = arity;
  return new;
}

 /************************************************************************/



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 522 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/DerivedData/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 535 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/DerivedData/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2789

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  189
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  242
/* YYNRULES -- Number of states.  */
#define YYNSTATES  401

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   426

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     172,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   184,     2,
     177,   178,   181,   179,   175,   180,     2,   185,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   173,   176,
     182,   174,   183,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   187,     2,   188,   186,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    15,    19,    21,
      25,    28,    31,    32,    34,    36,    38,    40,    43,    48,
      53,    55,    57,    60,    64,    66,    68,    71,    76,    79,
      82,    85,    88,    91,    93,    96,    98,   105,   114,   117,
     123,   126,   129,   134,   137,   140,   145,   148,   154,   159,
     164,   169,   172,   177,   180,   182,   184,   189,   194,   199,
     206,   214,   218,   220,   223,   228,   230,   233,   239,   245,
     253,   256,   262,   265,   267,   270,   273,   276,   278,   281,
     284,   287,   289,   291,   294,   296,   299,   302,   305,   308,
     312,   317,   320,   322,   324,   327,   331,   336,   343,   350,
     357,   366,   373,   377,   381,   385,   390,   398,   403,   408,
     416,   421,   429,   437,   447,   455,   457,   459,   463,   465,
     467,   469,   473,   475,   477,   479,   481,   483,   485,   487,
     489,   493,   495,   497,   499,   501,   505,   507,   509,   511,
     513,   515,   517,   519,   521,   524,   526,   528,   530,   532,
     536,   541,   546,   553,   555,   560,   567,   576,   578,   580,
     582,   584,   586,   588,   590,   592,   594,   596,   598,   600,
     602,   604,   606,   608,   610,   612,   614,   616,   618,   620,
     622,   624,   626,   628,   630,   632,   634,   636,   638,   640,
     642,   644,   646,   648,   650,   652,   654,   656,   658,   660,
     662,   664,   666,   668,   670,   672,   674,   676,   678,   680,
     682,   684,   686,   688,   690,   692,   694,   696,   698,   700,
     702,   704,   706,   708,   712,   717,   719,   724,   729,   734,
     742,   743,   745,   748,   750,   753,   755,   757,   759,   763,
     767,   771,   773
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     190,     0,    -1,   191,    -1,   190,   172,   191,    -1,   190,
       1,   172,    -1,    -1,    -1,     4,   192,   193,    -1,   194,
      -1,   194,   173,   193,    -1,   193,    14,    -1,   193,    15,
      -1,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      55,   195,    -1,   138,   213,    44,   213,    -1,   139,   213,
      44,   213,    -1,    17,    -1,    18,    -1,    48,   195,    -1,
      48,   119,   195,    -1,    56,    -1,    57,    -1,    19,   216,
      -1,    20,   212,   174,   195,    -1,   137,   218,    -1,   135,
     218,    -1,   136,   218,    -1,   134,   218,    -1,    21,   218,
      -1,    22,    -1,   129,   195,    -1,    23,    -1,    24,   213,
     174,   195,    44,   195,    -1,    24,   213,   174,   195,    44,
     195,    41,   195,    -1,    25,   213,    -1,    25,   119,   195,
     175,   213,    -1,    26,     4,    -1,    26,   195,    -1,    26,
     195,    34,   216,    -1,    27,     4,    -1,    27,   195,    -1,
      27,   195,    34,   216,    -1,    29,   214,    -1,    29,   119,
     195,   175,   214,    -1,    28,   195,    43,     4,    -1,    28,
     195,    27,     4,    -1,    28,   195,    43,   193,    -1,   153,
     213,    -1,    30,   213,   174,   195,    -1,    32,   218,    -1,
      32,    -1,    33,    -1,    35,   195,    27,   216,    -1,    35,
     195,    26,   216,    -1,    35,   129,    27,   216,    -1,    47,
     195,   175,   195,   175,   195,    -1,    47,   119,   195,   175,
     195,   175,   195,    -1,    58,    59,   195,    -1,    66,    -1,
      66,   195,    -1,    61,   195,   175,   195,    -1,    62,    -1,
      36,   214,    -1,    36,   119,   195,   175,   214,    -1,    36,
      45,   195,   176,   214,    -1,    36,   119,   195,    45,   195,
     176,   214,    -1,    37,   195,    -1,    37,   119,   195,   175,
     195,    -1,   130,   195,    -1,    63,    -1,    63,   195,    -1,
      63,    63,    -1,    38,   218,    -1,    68,    -1,    68,   195,
      -1,   128,    32,    -1,   128,   195,    -1,   128,    -1,    39,
      -1,    39,   195,    -1,    42,    -1,    42,   195,    -1,   142,
     195,    -1,    64,   195,    -1,   123,   195,    -1,   144,   174,
     195,    -1,    30,   144,   174,   195,    -1,   127,   195,    -1,
     127,    -1,    65,    -1,    46,   216,    -1,   213,   174,   195,
      -1,   154,   213,   174,   213,    -1,   154,   213,   174,   177,
     195,   178,    -1,   154,   213,   174,   213,   179,   213,    -1,
     154,   213,   174,   213,   180,   213,    -1,   154,   213,   174,
     177,   195,   178,   181,   213,    -1,   154,   213,   174,   213,
     181,   213,    -1,   154,    36,   214,    -1,   154,    29,   214,
      -1,   154,    38,   218,    -1,   154,   213,   174,   161,    -1,
     154,   213,   174,   161,   177,   216,   178,    -1,   154,   213,
     174,   165,    -1,   154,   213,   174,   160,    -1,   154,   213,
     174,   160,   177,   216,   178,    -1,   154,   213,   174,   162,
      -1,   154,   213,   174,   162,   177,   216,   178,    -1,   154,
     213,   174,   164,   177,   213,   178,    -1,   154,   213,   174,
     164,   177,   213,   178,   175,   213,    -1,   154,   213,   174,
     163,   177,   213,   178,    -1,   196,    -1,   198,    -1,   196,
     197,   198,    -1,   110,    -1,   111,    -1,   200,    -1,   198,
     199,   200,    -1,   174,    -1,   182,    -1,   183,    -1,   116,
      -1,   117,    -1,   118,    -1,   119,    -1,   202,    -1,   200,
     201,   202,    -1,   179,    -1,   180,    -1,   184,    -1,   204,
      -1,   202,   203,   204,    -1,   181,    -1,   185,    -1,    84,
      -1,    86,    -1,    87,    -1,    88,    -1,   186,    -1,   206,
      -1,   205,   206,    -1,   180,    -1,   112,    -1,   211,    -1,
     207,    -1,   207,   177,   178,    -1,   207,   177,   195,   178,
      -1,   208,   177,   195,   178,    -1,   209,   177,   195,   175,
     195,   178,    -1,   210,    -1,   210,   177,   195,   178,    -1,
     210,   177,   195,   175,   195,   178,    -1,   210,   177,   195,
     175,   195,   175,   195,   178,    -1,   109,    -1,   121,    -1,
      75,    -1,    76,    -1,   143,    -1,   144,    -1,   132,    -1,
     133,    -1,   165,    -1,    69,    -1,   120,    -1,    91,    -1,
     147,    -1,   150,    -1,   105,    -1,    71,    -1,    89,    -1,
      54,    -1,    72,    -1,    78,    -1,    79,    -1,   145,    -1,
     148,    -1,    77,    -1,   141,    -1,   102,    -1,   126,    -1,
      73,    -1,   146,    -1,   149,    -1,    60,    -1,    70,    -1,
      90,    -1,   122,    -1,    74,    -1,   103,    -1,   123,    -1,
     104,    -1,   140,    -1,   125,    -1,   131,    -1,    86,    -1,
      84,    -1,    87,    -1,    88,    -1,    99,    -1,   101,    -1,
     142,    -1,   108,    -1,   124,    -1,   100,    -1,   106,    -1,
     107,    -1,    80,    -1,   151,    -1,   152,    -1,   161,    -1,
     162,    -1,   164,    -1,   163,    -1,   160,    -1,   171,    -1,
       4,    -1,     3,    -1,   213,    -1,   212,    -1,   177,   195,
     178,    -1,     9,   177,   216,   178,    -1,     8,    -1,     8,
     177,   216,   178,    -1,     8,   187,   216,   188,    -1,     8,
     177,   217,   178,    -1,     8,   177,   216,   178,   177,   217,
     178,    -1,    -1,   195,    -1,   214,   195,    -1,   215,    -1,
     214,   215,    -1,   175,    -1,   176,    -1,   195,    -1,   216,
     175,   195,    -1,   195,   173,   195,    -1,   195,    44,   195,
      -1,   213,    -1,   218,   175,   213,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   258,   258,   260,   262,   268,   272,   272,   279,   284,
     289,   294,   303,   307,   314,   321,   328,   334,   340,   348,
     356,   362,   368,   375,   382,   388,   394,   401,   409,   417,
     425,   433,   441,   448,   454,   461,   467,   481,   494,   501,
     509,   529,   549,   561,   581,   601,   613,   620,   628,   651,
     671,   680,   688,   709,   716,   723,   730,   742,   754,   765,
     774,   783,   790,   796,   803,   811,   817,   825,   834,   842,
     851,   858,   866,   873,   880,   887,   895,   902,   908,   915,
     924,   931,   937,   943,   950,   956,   963,   970,   977,   984,
     991,   998,  1005,  1012,  1018,  1025,  1047,  1067,  1075,  1092,
    1109,  1123,  1140,  1147,  1154,  1162,  1169,  1177,  1186,  1193,
    1201,  1208,  1216,  1224,  1234,  1246,  1249,  1251,  1261,  1262,
    1266,  1268,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1320,
    1322,  1342,  1343,  1344,  1348,  1350,  1359,  1360,  1361,  1362,
    1363,  1364,  1365,  1368,  1370,  1379,  1380,  1384,  1387,  1394,
    1400,  1407,  1414,  1423,  1430,  1438,  1447,  1459,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,
    1486,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1495,
    1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1508,  1509,
    1510,  1511,  1512,  1513,  1514,  1519,  1520,  1521,  1522,  1523,
    1524,  1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1540,
    1597,  1616,  1623,  1630,  1641,  1651,  1663,  1675,  1689,  1702,
    1717,  1721,  1730,  1739,  1747,  1757,  1762,  1770,  1775,  1785,
    1791,  1815,  1820
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NUMBER", "DOUBLE", "SINGLE",
  "INTEGER", "VARIABLE_NAME", "FUNCTION_NAME", "HEX_STR", "OCT_STR",
  "BIN_STR", "REM", "QUOTEREM", "BANGREM", "BYE", "CLEAR", "CLR", "DATA",
  "DEF", "DIM", "END", "EXIT", "FOR", "GET", "GOSUB", "GOTO", "IF",
  "INPUT", "LET", "LIST", "NEXT", "NEW", "OF", "ON", "PRINT", "PUT",
  "READ", "RETURN", "RUN", "STEP", "STOP", "THEN", "TO", "USING", "WAIT",
  "OPEN", "CLOSE", "STATUS", "PRINT_FILE", "INPUT_FILE", "GET_FILE",
  "PUT_FILE", "_EOF", "CALL", "CLS", "CMD", "OPTION", "BASE", "PEEK",
  "POKE", "POP", "RANDOMIZE", "SYS", "VARLIST", "PAUSE", "SLEEP",
  "RESTORE", "ABS", "SGN", "CLOG", "EXP", "LOG", "SQR", "PI", "RND", "INT",
  "FIX", "FRAC", "ROUND", "CINT", "CSNG", "CDBL", "MOD", "MOD_INT", "DIV",
  "MAX", "MIN", "COS", "SIN", "ATN", "ACS", "ASN", "TAN", "COSH", "SINH",
  "TANH", "ASC", "LEFT", "MID", "RIGHT", "LEN", "STR", "VAL", "CHR", "SEG",
  "SUBSTR", "INSTR", "INKEY", "AND", "OR", "NOT", "XOR", "EQV", "IMP",
  "CMP_LE", "CMP_GE", "CMP_NE", "HASH", "ADR", "FRE", "SPC", "TAB", "POS",
  "USR", "LIN", "TRAP", "RESUME", "ERROR", "RAISE", "ERR", "EL", "ER",
  "DEFSTR", "DEFINT", "DEFSNG", "DEFDBL", "CHANGE", "CONVERT", "UCASE",
  "LCASE", "STRNG", "TIME", "TIME_STR", "HEX", "OCT", "BIN", "HEXSTR",
  "OCTSTR", "BINSTR", "UBOUND", "LBOUND", "LABEL", "MAT", "MATPRINT",
  "MATINPUT", "MATREAD", "MATGET", "MATPUT", "MATZER", "MATCON", "MATIDN",
  "MATTRN", "MATINV", "MATDET", "MATADD", "MATSUB", "MATMUL", "MATSCA",
  "MATFIL", "NUM", "'\\n'", "':'", "'='", "','", "';'", "'('", "')'",
  "'+'", "'-'", "'*'", "'<'", "'>'", "'&'", "'/'", "'^'", "'['", "']'",
  "$accept", "program", "line", "@1", "statements", "statement",
  "expression", "expression0", "binary_op", "expression1", "comparison_op",
  "expression2", "e2op", "expression3", "term", "expression4", "unary_op",
  "function", "fn_0", "fn_1", "fn_2", "fn_x", "factor", "user_function",
  "variable", "printlist", "printsep", "exprlist", "slicelist", "varlist", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,    10,    58,    61,    44,    59,    40,    41,    43,
      45,    42,    60,    62,    38,    47,    94,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   189,   190,   190,   190,   191,   192,   191,   193,   193,
     193,   193,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   195,   196,   196,   197,   197,
     198,   198,   199,   199,   199,   199,   199,   199,   199,   200,
     200,   201,   201,   201,   202,   202,   203,   203,   203,   203,
     203,   203,   203,   204,   204,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     209,   209,   209,   209,   209,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   211,
     211,   211,   211,   211,   212,   213,   213,   213,   213,   213,
     214,   214,   214,   214,   214,   215,   215,   216,   216,   217,
     217,   218,   218
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     0,     3,     1,     3,
       2,     2,     0,     1,     1,     1,     1,     2,     4,     4,
       1,     1,     2,     3,     1,     1,     2,     4,     2,     2,
       2,     2,     2,     1,     2,     1,     6,     8,     2,     5,
       2,     2,     4,     2,     2,     4,     2,     5,     4,     4,
       4,     2,     4,     2,     1,     1,     4,     4,     4,     6,
       7,     3,     1,     2,     4,     1,     2,     5,     5,     7,
       2,     5,     2,     1,     2,     2,     2,     1,     2,     2,
       2,     1,     1,     2,     1,     2,     2,     2,     2,     3,
       4,     2,     1,     1,     2,     3,     4,     6,     6,     6,
       8,     6,     3,     3,     3,     4,     7,     4,     4,     7,
       4,     7,     7,     9,     7,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     3,
       4,     4,     6,     1,     4,     6,     8,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     4,     4,     4,     7,
       0,     1,     2,     1,     2,     1,     1,     1,     3,     3,
       3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     6,     0,     2,    12,     1,     0,     5,   225,    13,
      14,    15,    16,    20,    21,     0,     0,     0,    33,    35,
       0,     0,     0,     0,     0,   230,     0,    54,    55,     0,
     230,     0,     0,    82,    84,     0,     0,     0,     0,    24,
      25,     0,     0,    65,    73,     0,    93,    62,    77,     0,
      92,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     0,     4,     3,     0,
       0,   220,   219,     0,   174,   187,   166,   188,   172,   175,
     184,   191,   159,   160,   180,   176,   177,   210,   199,   198,
     200,   201,   173,   189,   168,   202,   207,   203,   182,   192,
     194,   171,   208,   209,   205,   157,   146,   167,   158,   190,
     193,   206,   196,   183,   197,   163,   164,   195,   181,   204,
     161,   162,   178,   185,   169,   179,   186,   170,   211,   212,
     217,   213,   214,   216,   215,   165,   218,     0,   145,   237,
     115,   116,   120,   129,   134,     0,   143,   148,     0,     0,
     153,   147,   222,   221,    26,     0,   241,    32,     0,     0,
      38,   219,    41,   219,    44,     0,     0,   235,   236,   231,
      46,   233,     0,     0,    53,     0,     0,     0,     0,    66,
       0,    70,    76,    83,    85,    94,     0,     0,     0,    22,
      17,     0,     0,    75,    74,    87,    63,    78,    88,    91,
      79,    80,    34,    72,    31,    29,    30,    28,     0,     0,
      86,     0,    51,   230,   230,     0,     0,    10,    11,    12,
       0,   237,     0,     0,     0,     0,     0,   118,   119,     0,
     125,   126,   127,   128,   122,   123,   124,     0,   131,   132,
     133,     0,   138,   139,   140,   141,   136,   137,   142,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,   232,   234,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    61,     0,
       0,     0,    89,   103,   102,   104,     0,     9,    95,     0,
       0,   226,   228,   227,     0,   223,   117,   121,   130,   135,
     149,     0,     0,     0,     0,   238,    27,   242,     0,     0,
      42,    45,    49,    48,    50,   230,    90,    52,    58,    57,
      56,   230,     0,   230,     0,     0,     0,    64,    18,    19,
     108,   105,   110,     0,     0,   107,     0,    96,   240,   239,
       0,   224,   150,   151,     0,     0,   154,     0,    39,    47,
      68,     0,    67,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
     230,     0,    59,     0,     0,     0,     0,     0,    97,    98,
      99,   101,   229,   152,     0,   155,     0,    69,    60,   109,
     106,   111,   114,   112,     0,     0,    37,     0,   100,   156,
     113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    64,    65,   139,   140,   229,   141,
     237,   142,   241,   143,   249,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   170,   171,   154,   223,   157
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -193
static const yytype_int16 yypact[] =
{
      36,  -193,    14,  -193,  2635,  -193,  -128,    36,  -142,  -193,
    -193,  -193,  -193,  -193,  -193,  1878,    37,    40,  -193,  -193,
      40,    18,  2028,  2178,  1878,   528,     0,    40,  -193,   828,
     378,   978,    40,  1878,  1878,  1878,  1128,  1278,  1878,  -193,
    -193,    -3,  1878,  -193,  1428,  1878,  -193,  1878,  1878,  1878,
    1878,  1578,  1878,  1878,    40,    40,    40,    40,    40,    40,
    1878,  -109,    40,    28,    60,  -104,   -78,  -193,  -193,  1878,
    1878,  -193,  -193,  -101,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  1878,  -193,  -193,
      19,   -56,  -112,   -45,  -193,  2328,  -193,   -83,   -76,   -60,
     -52,  -193,  -193,  -193,   -47,   -43,  -193,   -42,   -39,  1878,
    -193,     5,    98,    10,   104,     6,  1878,  -193,  -193,  -193,
     678,  -193,   -35,   -31,   -42,   115,    94,  1878,  1878,   678,
    1878,  -193,   -42,  -193,  -193,   -47,  1878,   -30,  1878,  -193,
    -193,  1878,   -28,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   -42,   -42,   -42,   -42,   102,   105,
    -193,  1878,  -193,   678,   678,    40,   -26,  -193,  -193,  2635,
    1878,   -23,  -105,   -27,  -141,  1878,   -24,  -193,  -193,  1878,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  1878,  -193,  -193,
    -193,  1878,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  1878,
    -193,  1728,  1878,  1878,  1878,  1878,  1878,    40,  1878,   -22,
    1878,  1878,   148,  2493,   -20,  -193,  -193,  1878,  1878,  1878,
    1878,  1878,   -19,   -41,   -17,   -16,  1878,  -193,  -193,  1878,
      40,    40,  -193,   678,   678,   -42,     4,    60,  -193,  1878,
    1878,   -21,  -193,  -193,   -88,  -193,   -56,  -112,   -45,  -193,
    -193,   -18,   -15,   -14,   -80,  -193,  -193,  -193,   118,    40,
     -47,   -47,  -193,  -193,    60,   678,  -193,  -193,   -47,   -47,
     -47,   678,  1878,   678,  1878,  1878,    -5,  -193,  -193,  -193,
      -6,    -2,    -1,     2,     3,  -193,  1878,   -98,  -193,  -193,
    1878,  -193,  -193,  -193,  1878,  1878,  -193,  1878,  -193,   678,
     678,    11,   678,  -193,    20,  1878,  1878,  1878,  1878,    40,
      40,    16,    40,    40,    40,   -23,    21,    22,   -66,   131,
     678,  1878,  -193,   -65,   -64,   -59,    23,    24,    -8,  -193,
    -193,  -193,  -193,  -193,  1878,  -193,  1878,   678,  -193,  -193,
    -193,  -193,  -193,    29,    40,    25,  -193,    40,  -193,  -193,
    -193
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,   167,  -193,  -192,  -193,    55,  -193,  -193,   -33,
    -193,   -40,  -193,   -36,  -193,   -51,  -193,    61,  -193,  -193,
    -193,  -193,  -193,   191,    -4,   -29,  -161,   -32,  -132,   -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -44
static const yytype_int16 yytable[] =
{
      66,   179,   174,   185,   322,   -40,   -40,   182,     8,   266,
     -43,   -43,     8,   156,     5,     6,   158,   160,   266,   -40,
     -40,   289,   173,   156,   -43,   -43,     8,   287,   156,   204,
     205,   206,   207,   262,   255,    69,     8,   222,   224,   242,
       1,   243,   244,   245,    67,    70,    73,   293,     8,   263,
     156,   156,   156,   156,   208,   209,   191,   213,   212,   216,
     230,   231,   232,   233,   214,   211,   215,   238,   239,   219,
     255,   314,   240,   291,   217,   218,   225,   162,   164,   165,
     169,   362,   363,   364,   176,   169,   181,   255,   183,   184,
     341,   187,   189,   190,   251,   345,   220,   192,   346,   194,
     195,   252,   196,   197,   198,   199,   201,   202,   203,   384,
     255,   255,   385,   389,   390,   210,   255,   253,   234,   391,
     270,   271,   266,   266,   221,   254,   235,   236,   255,   227,
     228,   256,   260,   257,   323,   258,   246,   159,   261,   267,
     247,   248,   269,   268,   172,   276,   280,   279,   286,   281,
     290,   292,   312,   309,   295,   315,   340,   321,   324,   325,
     342,   344,   347,   343,   330,   331,   332,   333,   334,   335,
     355,   356,   386,   394,    68,   357,   358,   -40,   -40,   359,
     360,   336,   -43,   -43,   283,   284,     7,   370,   266,   266,
     285,   266,   226,   294,   378,   371,   296,   297,   299,   382,
     383,   392,   393,   399,   397,   298,   250,   155,   366,     0,
       0,   156,     0,     0,   259,    66,     0,     0,     0,     0,
       0,   264,     0,     0,     0,   265,   266,     0,   310,   311,
       0,     0,   272,   273,   265,   274,     0,   318,   319,   320,
       0,   275,     0,   277,     0,     0,   278,     0,     0,     0,
       0,     0,     0,   307,     0,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     0,     0,   282,     0,   169,   169,
       0,     0,     0,     0,     0,   288,   328,   329,     0,     0,
       0,     0,   337,     0,     0,     0,   349,     0,     0,     0,
       0,     0,   350,     0,   352,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   348,   301,   302,   303,   304,
     305,   306,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   316,   317,   373,   374,   375,     0,     0,     0,
       0,   326,     0,     0,   327,     0,     0,     0,   265,   265,
       0,   387,     0,     0,   338,   339,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,   377,     0,   379,   380,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,     0,   169,   351,   169,   353,
     354,    71,    72,     0,     0,     0,     8,    73,     0,     0,
     398,   361,     0,   400,     0,   365,     0,     0,     0,   367,
     368,     0,   369,     0,   265,   265,     0,   265,     0,     0,
     372,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   177,     0,   169,   388,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,   395,
       0,   396,   265,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   178,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,   167,   168,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   166,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,   167,   168,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,   167,   168,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,   175,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   180,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   186,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   188,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,   193,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
     200,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,   300,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,   161,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,   163,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,    71,    72,     0,     0,     0,     8,    73,   130,   131,
     132,   133,   134,   135,     0,     0,     0,     0,     0,   136,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,    88,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,     0,     0,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,   133,   134,   135,     0,     0,     0,   313,     0,   136,
       0,     8,     0,     0,     0,   137,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,    27,    28,     0,    29,    30,
      31,    32,    33,     0,     0,    34,     0,     0,     0,    35,
      36,    37,     0,     0,     0,     0,     0,     0,    38,    39,
      40,    41,     0,     0,    42,    43,    44,    45,    46,    47,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    49,     0,     0,     0,
      50,    51,    52,    53,     0,     0,     0,    54,    55,    56,
      57,    58,    59,     0,     0,    60,     0,    61,     0,     0,
       0,     0,     0,     8,     0,     0,    62,    63,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,    27,    28,     0,
      29,    30,    31,    32,    33,     0,     0,    34,     0,     0,
       0,    35,    36,    37,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    41,     0,     0,    42,    43,    44,    45,
      46,    47,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,     0,    50,    51,    52,    53,     0,     0,     0,    54,
      55,    56,    57,    58,    59,     0,     0,    60,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    62,    63
};

static const yytype_int16 yycheck[] =
{
       4,    30,    27,    35,    45,     0,     1,    32,     8,   170,
       0,     1,     8,    17,     0,     1,    20,    21,   179,    14,
      15,    44,    26,    27,    14,    15,     8,   219,    32,    54,
      55,    56,    57,    27,   175,   177,     8,    69,    70,    84,
       4,    86,    87,    88,   172,   187,     9,   188,     8,    43,
      54,    55,    56,    57,    58,    59,    59,    29,    62,    63,
     116,   117,   118,   119,    36,   174,    38,   179,   180,   173,
     175,   263,   184,   178,    14,    15,   177,    22,    23,    24,
      25,   179,   180,   181,    29,    30,    31,   175,    33,    34,
     178,    36,    37,    38,   177,   175,   174,    42,   178,    44,
      45,   177,    47,    48,    49,    50,    51,    52,    53,   175,
     175,   175,   178,   178,   178,    60,   175,   177,   174,   178,
      26,    27,   283,   284,    69,   177,   182,   183,   175,   110,
     111,   174,    34,   175,   175,   174,   181,   119,    34,   174,
     185,   186,    27,   174,   144,   175,    44,   175,   174,    44,
     173,   178,     4,   175,   178,   175,   177,   176,   175,   175,
     178,   175,    44,   178,   160,   161,   162,   163,   164,   165,
     175,   177,    41,   181,     7,   177,   177,   172,   173,   177,
     177,   177,   172,   173,   213,   214,   172,   176,   349,   350,
     215,   352,   137,   225,   178,   175,   229,   237,   249,   178,
     178,   178,   178,   178,   175,   241,   145,    16,   340,    -1,
      -1,   215,    -1,    -1,   159,   219,    -1,    -1,    -1,    -1,
      -1,   166,    -1,    -1,    -1,   170,   387,    -1,   260,   261,
      -1,    -1,   177,   178,   179,   180,    -1,   269,   270,   271,
      -1,   186,    -1,   188,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,   263,
      -1,    -1,    -1,    -1,    -1,    -1,   211,    -1,   213,   214,
      -1,    -1,    -1,    -1,    -1,   220,   280,   281,    -1,    -1,
      -1,    -1,   286,    -1,    -1,    -1,   315,    -1,    -1,    -1,
      -1,    -1,   321,    -1,   323,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   309,   251,   252,   253,   254,
     255,   256,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   267,   268,   356,   357,   358,    -1,    -1,    -1,
      -1,   276,    -1,    -1,   279,    -1,    -1,    -1,   283,   284,
      -1,   370,    -1,    -1,   289,   290,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   359,   360,    -1,   362,   363,
     364,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     315,    -1,    -1,    -1,    -1,    -1,   321,   322,   323,   324,
     325,     3,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,
     394,   336,    -1,   397,    -1,   340,    -1,    -1,    -1,   344,
     345,    -1,   347,    -1,   349,   350,    -1,   352,    -1,    -1,
     355,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,   370,   371,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,   384,
      -1,   386,   387,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   176,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   176,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,   176,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,   129,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,   178,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,    -1,    -1,     8,     9,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   177,    -1,    -1,   180,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,   124,   125,   126,    -1,    -1,    -1,    -1,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,    -1,    -1,    -1,     4,    -1,   171,
      -1,     8,    -1,    -1,    -1,   177,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      57,    58,    -1,    -1,    61,    62,    63,    64,    65,    66,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,
     127,   128,   129,   130,    -1,    -1,    -1,   134,   135,   136,
     137,   138,   139,    -1,    -1,   142,    -1,   144,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    -1,   153,   154,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    -1,    -1,    61,    62,    63,    64,
      65,    66,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,   127,   128,   129,   130,    -1,    -1,    -1,   134,
     135,   136,   137,   138,   139,    -1,    -1,   142,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,   154
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,   190,   191,   192,     0,     1,   172,     8,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    32,    33,    35,
      36,    37,    38,    39,    42,    46,    47,    48,    55,    56,
      57,    58,    61,    62,    63,    64,    65,    66,    68,   123,
     127,   128,   129,   130,   134,   135,   136,   137,   138,   139,
     142,   144,   153,   154,   193,   194,   213,   172,   191,   177,
     187,     3,     4,     9,    54,    60,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    84,    86,
      87,    88,    89,    90,    91,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   112,   120,   121,   122,
     123,   124,   125,   126,   131,   132,   133,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     160,   161,   162,   163,   164,   165,   171,   177,   180,   195,
     196,   198,   200,   202,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   216,   212,   213,   218,   213,   119,
     213,     4,   195,     4,   195,   195,   119,   175,   176,   195,
     214,   215,   144,   213,   218,   129,   195,    45,   119,   214,
     119,   195,   218,   195,   195,   216,   119,   195,   119,   195,
     195,    59,   195,    63,   195,   195,   195,   195,   195,   195,
      32,   195,   195,   195,   218,   218,   218,   218,   213,   213,
     195,   174,   213,    29,    36,    38,   213,    14,    15,   173,
     174,   195,   216,   217,   216,   177,   195,   110,   111,   197,
     116,   117,   118,   119,   174,   182,   183,   199,   179,   180,
     184,   201,    84,    86,    87,    88,   181,   185,   186,   203,
     206,   177,   177,   177,   177,   175,   174,   175,   174,   195,
      34,    34,    27,    43,   195,   195,   215,   174,   174,    27,
      26,    27,   195,   195,   195,   195,   175,   195,   195,   175,
      44,    44,   195,   214,   214,   218,   174,   193,   195,    44,
     173,   178,   178,   188,   216,   178,   198,   200,   202,   204,
     178,   195,   195,   195,   195,   195,   195,   213,   195,   175,
     216,   216,     4,     4,   193,   175,   195,   195,   216,   216,
     216,   176,    45,   175,   175,   175,   195,   195,   213,   213,
     160,   161,   162,   163,   164,   165,   177,   213,   195,   195,
     177,   178,   178,   178,   175,   175,   178,    44,   213,   214,
     214,   195,   214,   195,   195,   175,   177,   177,   177,   177,
     177,   195,   179,   180,   181,   195,   217,   195,   195,   195,
     176,   175,   195,   216,   216,   216,   213,   213,   178,   213,
     213,   213,   178,   178,   175,   178,    41,   214,   195,   178,
     178,   178,   178,   178,   181,   195,   195,   175,   213,   178,
     213
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 268 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
  }
    break;

  case 6:
#line 272 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { errline = (yyvsp[(1) - (1)].d); }
    break;

  case 7:
#line 273 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    interpreter_state.lines[(int)(yyvsp[(1) - (3)].d)] = (yyvsp[(3) - (3)].l);
  }
    break;

  case 8:
#line 280 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].statement));
  }
    break;

  case 9:
#line 285 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].statement));
  }
    break;

  case 10:
#line 290 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(1) - (2)].l), NULL);
  }
    break;

  case 11:
#line 295 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(1) - (2)].l), NULL);
  }
    break;

  case 12:
#line 303 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.statement) = NULL;
  }
    break;

  case 13:
#line 308 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(REM);
    new->parms.rem = yylval.s; // the string has been modified in scan to remove the REM
    (yyval.statement) = new;
  }
    break;

  case 14:
#line 315 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(QUOTEREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 15:
#line 322 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(BANGREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 16:
#line 329 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(BYE);
    (yyval.statement) = new;
  }
    break;

  case 17:
#line 335 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CALL);
    (yyval.statement) = new;
  }
    break;

  case 18:
#line 341 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CHANGE);
    new->parms.change.var1 = (yyvsp[(2) - (4)].variable);
    new->parms.change.var2 = (yyvsp[(4) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 19:
#line 349 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CONVERT);
    new->parms.change.var1 = (yyvsp[(2) - (4)].variable);
    new->parms.change.var2 = (yyvsp[(4) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 20:
#line 357 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLEAR);
    (yyval.statement) = new;
  }
    break;

  case 21:
#line 363 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLEAR);
    (yyval.statement) = new;
  }
    break;

  case 22:
#line 369 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLOSE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 23:
#line 376 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLOSE);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  }
    break;

  case 24:
#line 383 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLS);
    (yyval.statement) = new;
  }
    break;

  case 25:
#line 389 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CMD);
    (yyval.statement) = new;
  }
    break;

  case 26:
#line 395 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DATA);
    new->parms.data = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 27:
#line 402 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEF);
    new->parms.def.signature = (yyvsp[(2) - (4)].variable);
    new->parms.def.formula = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 28:
#line 410 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = DOUBLE;
    (yyval.statement) = new;
  }
    break;

  case 29:
#line 418 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = INTEGER;
    (yyval.statement) = new;
  }
    break;

  case 30:
#line 426 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = SINGLE;
    (yyval.statement) = new;
  }
    break;

  case 31:
#line 434 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = STRING;
    (yyval.statement) = new;
  }
    break;

  case 32:
#line 442 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DIM);
    new->parms.dim = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 33:
#line 449 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(END);
    (yyval.statement) = new;
  }
    break;

  case 34:
#line 455 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RAISE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 35:
#line 462 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(EXIT);
    (yyval.statement) = new;
  }
    break;

  case 36:
#line 468 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(FOR);
    new->parms._for.variable = (yyvsp[(2) - (6)].variable);
    new->parms._for.begin = (yyvsp[(4) - (6)].expression);
    new->parms._for.end = (yyvsp[(6) - (6)].expression);
    new->parms._for.step = NULL;
    (yyval.statement) = new;
    
    /* static analyser */
    for_loops_total++;
    for_loops_step_1++;
  }
    break;

  case 37:
#line 482 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(FOR);
    new->parms._for.variable = (yyvsp[(2) - (8)].variable);
    new->parms._for.begin = (yyvsp[(4) - (8)].expression);
    new->parms._for.end = (yyvsp[(6) - (8)].expression);
    new->parms._for.step = (yyvsp[(8) - (8)].expression);
    (yyval.statement) = new;
  
    /* static analyser - consider anything with a STEP special even if it is a 1 */
    for_loops_total++;
  }
    break;

  case 38:
#line 495 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(GET);
    new->parms.generic.generic_variable = (yyvsp[(2) - (2)].variable);
    (yyval.statement) = new;
  }
    break;

  case 39:
#line 502 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(GET_FILE);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (5)].expression);
    new->parms.generic.generic_variable = (yyvsp[(5) - (5)].variable);
    (yyval.statement) = new;
  }
    break;

  case 40:
#line 510 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(GOSUB);
    expression_t *exp = make_expression(number);
    exp->parms.number = (yyvsp[(2) - (2)].d);
    new->parms._goto = exp;
    (yyval.statement) = new;
      
    /* static analyzer */
    linenum_gosub_totals++;
    linenum_constants_total++;
    if ((yyvsp[(2) - (2)].d) == errline) {
      linenum_same_line++;
    } else if ((yyvsp[(2) - (2)].d) > errline) {
      linenum_forwards++;
    } else {
      linenum_backwards++;
    }
  }
    break;

  case 41:
#line 530 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(GOSUB);
    new->parms.gosub = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
      
    /* static analyzer */
    linenum_gosub_totals++;
    linenum_constants_total++;
    if ((yyvsp[(2) - (2)].expression)->parms.number) {
      if ((yyvsp[(2) - (2)].expression)->parms.number == errline) {
        linenum_same_line++;
      } else if ((yyvsp[(2) - (2)].expression)->parms.number > errline) {
          linenum_forwards++;
      } else {
          linenum_backwards++;
      }
    }
  }
    break;

  case 42:
#line 550 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OF);
    new->parms.on.type = GOSUB;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
      
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  }
    break;

  case 43:
#line 562 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(GOTO);
    expression_t *exp = make_expression(number);
    exp->parms.number = (yyvsp[(2) - (2)].d);
    new->parms._goto = exp;
    (yyval.statement) = new;
      
    /* static analyzer */
    linenum_goto_totals++;
    linenum_constants_total++;
    if ((yyvsp[(2) - (2)].d) == errline) {
      linenum_same_line++;
    } else if ((yyvsp[(2) - (2)].d) > errline) {
      linenum_forwards++;
    } else {
      linenum_backwards++;
    }
  }
    break;

  case 44:
#line 582 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(GOTO);
    new->parms._goto = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
      
    /* static analyzer */
    linenum_goto_totals++;
    linenum_constants_total++;
    if ((yyvsp[(2) - (2)].expression)->parms.number) {
      if ((yyvsp[(2) - (2)].expression)->parms.number == errline) {
        linenum_same_line++;
      } else if ((yyvsp[(2) - (2)].expression)->parms.number > errline) {
          linenum_forwards++;
      } else {
          linenum_backwards++;
      }
    }
  }
    break;

  case 45:
#line 602 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OF);
    new->parms.on.type = GOTO;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
      
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  }
    break;

  case 46:
#line 614 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(INPUT);
    new->parms.input = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 47:
#line 621 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(INPUT_FILE);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (5)].expression);
    new->parms.input = (yyvsp[(5) - (5)].l);
    (yyval.statement) = new;
  }
    break;

  case 48:
#line 629 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(IF);
    new->parms._if.condition = (yyvsp[(2) - (4)].expression);
    new->parms._if.then_expression = NULL;
    new->parms._if.then_linenumber = (yyvsp[(4) - (4)].d);
    (yyval.statement) = new;
    
    /* static analyzer */
    // this handles the implicit GOTO case, GOSUBs are always explicit so they are caught in the THEN statements
    linenum_then_goto_totals++;
    linenum_constants_total++;
    if ((yyvsp[(2) - (4)].expression)->parms.number) {
      if ((yyvsp[(2) - (4)].expression)->parms.number == errline) {
        linenum_same_line++;
      } else if ((yyvsp[(2) - (4)].expression)->parms.number > errline) {
        linenum_forwards++;
      } else {
        linenum_backwards++;
      }
    }
  }
    break;

  case 49:
#line 652 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(IF);
    new->parms._if.condition = (yyvsp[(2) - (4)].expression);
    new->parms._if.then_expression = NULL;
    new->parms._if.then_linenumber = (yyvsp[(4) - (4)].d);
    (yyval.statement) = new;
    
    /* static analyzer */
    linenum_then_goto_totals++;
    linenum_constants_total++;
    if ((yyvsp[(2) - (4)].expression)->parms.number == errline) {
      linenum_same_line++;
    } else if ((yyvsp[(2) - (4)].expression)->parms.number > errline) {
      linenum_forwards++;
    } else {
      linenum_backwards++;
    }
  }
    break;

  case 50:
#line 672 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(IF);
    new->parms._if.condition = (yyvsp[(2) - (4)].expression);
    new->parms._if.then_expression = (yyvsp[(4) - (4)].l);
    new->parms._if.then_linenumber = 0;
    (yyval.statement) = new;
  }
    break;

  case 51:
#line 681 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(LABEL);
    new->parms.label.variable = (yyvsp[(2) - (2)].variable);
    new->parms.label.linenumber = errline;
    (yyval.statement) = new;
  }
    break;

  case 52:
#line 689 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(LET);
    new->parms.let.variable = (yyvsp[(2) - (4)].variable);
    new->parms.let.expression = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
    
    /* static analyser - see if we are setting a value to 0 or 1 */
    //NOTE: same code below in invisible LET
    if (new->parms.let.expression->type == number) {
      if ((int)new->parms.let.expression->parms.number == 0) {
          assign_zero++;
      } else if ((int)new->parms.let.expression->parms.number == 1
                 && (int)new->parms.let.expression->parms.number == new->parms.let.expression->parms.number) {
        assign_one++;
      } else {
        assign_other++;
      }
    }
  }
    break;

  case 53:
#line 710 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 54:
#line 717 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = NULL;
    (yyval.statement) = new;
  }
    break;

  case 55:
#line 724 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEW);
    new->parms.next = NULL;
    (yyval.statement) = new;
  }
    break;

  case 56:
#line 731 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = GOTO;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
      
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  }
    break;

  case 57:
#line 743 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = GOSUB;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
    
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  }
    break;

  case 58:
#line 755 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = TRAP;
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
    
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  }
    break;

  case 59:
#line 766 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OPEN);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (6)].expression);
    new->parms.generic.generic_parameter2 = (yyvsp[(4) - (6)].expression);
    new->parms.generic.generic_parameter3 = (yyvsp[(6) - (6)].expression);
    (yyval.statement) = new;
  }
    break;

  case 60:
#line 775 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OPEN);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (7)].expression);
    new->parms.generic.generic_parameter2 = (yyvsp[(5) - (7)].expression);
    new->parms.generic.generic_parameter3 = (yyvsp[(7) - (7)].expression);
    (yyval.statement) = new;
  }
    break;

  case 61:
#line 784 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OPTION);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  }
    break;

  case 62:
#line 791 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PAUSE);
    (yyval.statement) = new;
  }
    break;

  case 63:
#line 797 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PAUSE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 64:
#line 804 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(POKE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (4)].expression);
    new->parms.generic.generic_parameter2 = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 65:
#line 812 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(POP);
    (yyval.statement) = new;
  }
    break;

  case 66:
#line 818 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PRINT);
    new->parms.print.format = NULL;
    new->parms.print.item_list = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 67:
#line 826 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PRINT_FILE);
    new->parms.print.channel = (yyvsp[(3) - (5)].expression);
    new->parms.print.format = NULL;
    new->parms.print.item_list = (yyvsp[(5) - (5)].l);
    (yyval.statement) = new;
  }
    break;

  case 68:
#line 835 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PRINT);
    new->parms.print.format = (yyvsp[(3) - (5)].expression);
    new->parms.print.item_list = (yyvsp[(5) - (5)].l);
    (yyval.statement) = new;
  }
    break;

  case 69:
#line 843 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PRINT_FILE);
    new->parms.print.channel = (yyvsp[(3) - (7)].expression);
    new->parms.print.format = (yyvsp[(5) - (7)].expression);
    new->parms.print.item_list = (yyvsp[(7) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 70:
#line 852 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PUT);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 71:
#line 859 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PUT_FILE);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (5)].expression);
    new->parms.generic.generic_parameter2 = (yyvsp[(5) - (5)].expression);
    (yyval.statement) = new;
  }
    break;

  case 72:
#line 867 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RAISE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 73:
#line 874 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic.generic_parameter = NULL;
    (yyval.statement) = new;
  }
    break;

  case 74:
#line 881 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 75:
#line 888 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    // this handles RANDOMIZE TIMER because scan converts TIMER to RANDOMIZE
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic.generic_parameter = NULL;
    (yyval.statement) = new;
  }
    break;

  case 76:
#line 896 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(READ);
    new->parms.read = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 77:
#line 903 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    (yyval.statement) = new;
  }
    break;

  case 78:
#line 909 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 79:
#line 916 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESUME);
    expression_t *exp = make_expression(number);
    exp->parms.number = -1;
    new->parms.generic.generic_parameter = exp;
    (yyval.statement) = new;
  }
    break;

  case 80:
#line 925 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESUME);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 81:
#line 932 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESUME);
    (yyval.statement) = new;
  }
    break;

  case 82:
#line 938 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RETURN);
    (yyval.statement) = new;
  }
    break;

  case 83:
#line 944 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RETURN);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 84:
#line 951 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(STOP);
    (yyval.statement) = new;
  }
    break;

  case 85:
#line 957 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(STOP);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 86:
#line 964 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(STRNG);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 87:
#line 971 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(SYS);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 88:
#line 978 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TAB);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 89:
#line 985 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  }
    break;

  case 90:
#line 992 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic.generic_parameter = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 91:
#line 999 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TRAP);
    new->parms.generic.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 92:
#line 1006 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TRAP);
    new->parms.generic.generic_parameter = NULL;
    (yyval.statement) = new;
  }
    break;

  case 93:
#line 1013 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(VARLIST);
    (yyval.statement) = new;
  }
    break;

  case 94:
#line 1019 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(WAIT);
    (yyval.statement) = new;
  }
    break;

  case 95:
#line 1026 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(LET);
    new->parms.let.variable = (yyvsp[(1) - (3)].variable);
    new->parms.let.expression = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
    
    /* static analyser - see if we are setting a value to 0 or 1 */
    //NOTE: same code above in LET
    if (new->parms.let.expression->type == number) {
      if ((int)new->parms.let.expression->parms.number == 0) {
        assign_zero++;
      } else if ((int)new->parms.let.expression->parms.number == 1
                 && (int)new->parms.let.expression->parms.number == new->parms.let.expression->parms.number) {
        assign_one++;
      } else {
        assign_other++;
      }
    }
  }
    break;

  case 96:
#line 1048 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    new->parms.mat.variable2 = (yyvsp[(4) - (4)].variable);
    
    // for all of the mat instructions, a sub-array can be defined by putting
    // subscripts on either the LHR (IBM only) or RHS. RetroBASIC assumes the
    // latter overrides the former, so if we find subs on one of the parameters,
    // copy them over to the LHS to make them easier to find at runtime.
    //
    // NOTE: in theory there should only be one set of sub-array specifiers,
    //  and more should be an error. but we just use the right most one we find
    if (new->parms.mat.variable2->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable2->subscripts;
    }
    
    (yyval.statement) = new;
  }
    break;

  case 97:
#line 1068 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.mat.variable = (yyvsp[(2) - (6)].variable);
    new->parms.mat.expression = (yyvsp[(5) - (6)].expression);
    (yyval.statement) = new;
  }
    break;

  case 98:
#line 1076 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATADD);
    new->parms.mat.variable = (yyvsp[(2) - (6)].variable);
    new->parms.mat.variable2 = (yyvsp[(4) - (6)].variable);
    new->parms.mat.variable3 = (yyvsp[(6) - (6)].variable);

    if (new->parms.mat.variable2->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable2->subscripts;
    }
    if (new->parms.mat.variable3->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable3->subscripts;
    }

    (yyval.statement) = new;
  }
    break;

  case 99:
#line 1093 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATSUB);
    new->parms.mat.variable = (yyvsp[(2) - (6)].variable);
    new->parms.mat.variable2 = (yyvsp[(4) - (6)].variable);
    new->parms.mat.variable3 = (yyvsp[(6) - (6)].variable);

    if (new->parms.mat.variable2->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable2->subscripts;
    }
    if (new->parms.mat.variable3->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable3->subscripts;
    }

    (yyval.statement) = new;
  }
    break;

  case 100:
#line 1110 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATSCA);
    new->parms.mat.variable = (yyvsp[(2) - (8)].variable);
    new->parms.mat.expression = (yyvsp[(5) - (8)].expression);
    new->parms.mat.variable3 = (yyvsp[(8) - (8)].variable);

    if (new->parms.mat.variable3->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable3->subscripts;
    }

    (yyval.statement) = new;
  }
    break;

  case 101:
#line 1124 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATMUL);
    new->parms.mat.variable = (yyvsp[(2) - (6)].variable);
    new->parms.mat.variable2 = (yyvsp[(4) - (6)].variable);
    new->parms.mat.variable3 = (yyvsp[(6) - (6)].variable);

    if (new->parms.mat.variable2->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable2->subscripts;
    }
    if (new->parms.mat.variable3->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable3->subscripts;
    }

    (yyval.statement) = new;
  }
    break;

  case 102:
#line 1141 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATPRINT);
    new->parms.print.item_list = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  }
    break;

  case 103:
#line 1148 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATINPUT);
    new->parms.input = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  }
    break;

  case 104:
#line 1155 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATREAD);
    new->parms.read = (yyvsp[(3) - (3)].l);
    
    (yyval.statement) = new;
  }
    break;

  case 105:
#line 1163 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATCON);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 106:
#line 1170 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATCON);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 107:
#line 1178 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    // there are two ways to get the DET, one is a normal function,
    // the other is the IBM version of INV
    statement_t *new = make_statement(MATDET);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 108:
#line 1187 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATZER);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 109:
#line 1194 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATZER);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 110:
#line 1202 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 111:
#line 1209 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 112:
#line 1217 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATINV);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable2 = (yyvsp[(6) - (7)].variable);
    (yyval.statement) = new;
  }
    break;

  case 113:
#line 1225 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    // this is the IBM 5100 version, which returns the determinant
    statement_t *new = make_statement(MATINV);
    new->parms.mat.variable = (yyvsp[(2) - (9)].variable);
    new->parms.mat.variable2 = (yyvsp[(6) - (9)].variable);
    new->parms.mat.variable3 = (yyvsp[(9) - (9)].variable);
    (yyval.statement) = new;
  }
    break;

  case 114:
#line 1235 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATTRN);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable2 = (yyvsp[(6) - (7)].variable);
    (yyval.statement) = new;
  }
    break;

  case 117:
#line 1252 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
  }
    break;

  case 118:
#line 1261 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = AND; }
    break;

  case 119:
#line 1262 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = OR;  }
    break;

  case 121:
#line 1269 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
    
    /* static analyser - see if this is a comparison to zero or one */
    if (new->parms.op.p[1]->type == number) {
      // test for floats first
      if (ceil(new->parms.op.p[1]->parms.number) != new->parms.op.p[1]->parms.number) {
        if (new->parms.op.opcode == '=') {
          compare_equals_other++;
        } else {
          compare_not_equals_other++;
        }
      } else { // otherwise test ints
        if ((int)new->parms.op.p[1]->parms.number == 0) {
          if (new->parms.op.opcode == '=') {
            compare_equals_zero++;
          } else {
            compare_not_equals_zero++;
          }
        } else if ((int)new->parms.op.p[1]->parms.number == 1) {
          if (new->parms.op.opcode == '=') {
            compare_equals_one++;
          } else {
            compare_not_equals_one++;
          }
        } else {
          if (new->parms.op.opcode == '=') {
            compare_equals_other++;
          } else {
            compare_not_equals_other++;
          }
        }
      }
    }
  }
    break;

  case 122:
#line 1310 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '='; }
    break;

  case 123:
#line 1311 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '<'; }
    break;

  case 124:
#line 1312 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '>'; }
    break;

  case 125:
#line 1313 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_LE; }
    break;

  case 126:
#line 1314 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_GE; }
    break;

  case 127:
#line 1315 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_NE; }
    break;

  case 128:
#line 1316 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = HASH; }
    break;

  case 130:
#line 1323 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
    
    /* static analyser - if it's + or - 1, record it as an increment */
    if (new->parms.op.p[1]->type == number
        && (int)new->parms.op.p[1]->parms.number == 1
        && (int)new->parms.op.p[1]->parms.number == new->parms.op.p[1]->parms.number) {
      if (new->parms.op.opcode == '+') {
        increments++;
      } else {
        decrements++;
      }
    }
  }
    break;

  case 131:
#line 1342 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '+'; }
    break;

  case 132:
#line 1343 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 133:
#line 1344 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '&'; }
    break;

  case 135:
#line 1351 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
  }
    break;

  case 136:
#line 1359 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '*'; }
    break;

  case 137:
#line 1360 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '/'; }
    break;

  case 138:
#line 1361 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MOD; }
    break;

  case 139:
#line 1362 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = DIV; }
    break;

  case 140:
#line 1363 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MAX; }
    break;

  case 141:
#line 1364 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MIN; }
    break;

  case 142:
#line 1365 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '^'; }
    break;

  case 144:
#line 1371 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (2)].i));
    new->parms.op.p[0] = (yyvsp[(2) - (2)].expression);
    (yyval.expression) = new;
  }
    break;

  case 145:
#line 1379 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 146:
#line 1380 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = NOT; }
    break;

  case 148:
#line 1388 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (1)].i));
    (yyval.expression) = new;
  }
    break;

  case 149:
#line 1395 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (3)].i));
    (yyval.expression) = new;
  }
    break;

  case 150:
#line 1401 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  }
    break;

  case 151:
#line 1408 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  }
    break;

  case 152:
#line 1415 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  }
    break;

  case 153:
#line 1424 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (1)].i));
    (yyval.expression) = new;
  }
    break;

  case 154:
#line 1431 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  }
    break;

  case 155:
#line 1439 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  }
    break;

  case 156:
#line 1448 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(3, (yyvsp[(1) - (8)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (8)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (8)].expression);
    new->parms.op.p[2] = (yyvsp[(7) - (8)].expression);
    (yyval.expression) = new;
  }
    break;

  case 157:
#line 1459 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = INKEY; }
    break;

  case 158:
#line 1460 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = FRE; }
    break;

  case 159:
#line 1461 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = PI; }
    break;

  case 160:
#line 1462 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = RND; }
    break;

  case 161:
#line 1463 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = TIME; }
    break;

  case 162:
#line 1464 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = TIME_STR; }
    break;

  case 163:
#line 1465 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = EL; }
    break;

  case 164:
#line 1466 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ER; }
    break;

  case 165:
#line 1467 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATDET; }
    break;

  case 166:
#line 1472 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) =  ABS; }
    break;

  case 167:
#line 1473 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ADR; }
    break;

  case 168:
#line 1474 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ATN; }
    break;

  case 169:
#line 1475 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = BIN; }
    break;

  case 170:
#line 1476 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = BINSTR; }
    break;

  case 171:
#line 1477 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CHR; }
    break;

  case 172:
#line 1478 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CLOG;}
    break;

  case 173:
#line 1479 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = COS; }
    break;

  case 174:
#line 1480 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = _EOF; }
    break;

  case 175:
#line 1481 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = EXP; }
    break;

  case 176:
#line 1482 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = FIX; }
    break;

  case 177:
#line 1483 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = FRAC; }
    break;

  case 178:
#line 1484 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = HEX; }
    break;

  case 179:
#line 1485 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = HEXSTR; }
    break;

  case 180:
#line 1486 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = INT; }
    break;

  case 181:
#line 1487 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LCASE; }
    break;

  case 182:
#line 1488 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LEN; }
    break;

  case 183:
#line 1489 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LIN; }
    break;

  case 184:
#line 1490 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LOG; }
    break;

  case 185:
#line 1491 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = OCT; }
    break;

  case 186:
#line 1492 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = OCTSTR; }
    break;

  case 187:
#line 1493 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = PEEK;}
    break;

  case 188:
#line 1494 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SGN; }
    break;

  case 189:
#line 1495 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SIN; }
    break;

  case 190:
#line 1496 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SPC; }
    break;

  case 191:
#line 1497 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SQR; }
    break;

  case 192:
#line 1498 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = STR; }
    break;

  case 193:
#line 1499 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = TAB; }
    break;

  case 194:
#line 1500 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = VAL; }
    break;

  case 195:
#line 1501 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = UCASE; }
    break;

  case 196:
#line 1502 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = USR; }
    break;

  case 197:
#line 1503 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ERR; }
    break;

  case 198:
#line 1508 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = DIV; }
    break;

  case 199:
#line 1509 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MOD; }
    break;

  case 200:
#line 1510 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MAX; }
    break;

  case 201:
#line 1511 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MIN; }
    break;

  case 202:
#line 1512 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LEFT; }
    break;

  case 203:
#line 1513 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = RIGHT; }
    break;

  case 204:
#line 1514 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = STRNG; }
    break;

  case 205:
#line 1519 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = INSTR; }
    break;

  case 206:
#line 1520 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = POS; }
    break;

  case 207:
#line 1521 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MID; }
    break;

  case 208:
#line 1522 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SEG; }
    break;

  case 209:
#line 1523 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SUBSTR; }
    break;

  case 210:
#line 1524 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ROUND; }
    break;

  case 211:
#line 1525 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = UBOUND; }
    break;

  case 212:
#line 1526 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LBOUND; }
    break;

  case 213:
#line 1527 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATCON; }
    break;

  case 214:
#line 1528 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATIDN; }
    break;

  case 215:
#line 1529 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATINV; }
    break;

  case 216:
#line 1530 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATTRN; }
    break;

  case 217:
#line 1531 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATZER; }
    break;

  case 218:
#line 1532 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = NUM; }
    break;

  case 219:
#line 1541 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    /* actual parsing code */
    expression_t *new = make_expression(number);
    new->parms.number = (yyvsp[(1) - (1)].d);
    (yyval.expression) = new;
    
    /* static analyzer code */
    /* numbers here are not *all* of numbers in a program, line numbers
       (for instance) don't end up here. This *is* what we want for the
       analyzer.
       This means we have to track line numbers separately, like in the
       case of GOTO etc. This will, however, capture all the numbers found
       in expressions, PRINT statements, user formulas, POKEs, etc.
     */
    numeric_constants_total++;
    
    /* basic sizes for ints */
    double num = new->parms.number;
    if (floorf(num) == num) {
      // count decimal digits
      if (num == 0) {
        numeric_constants_zero++;
      } else if (num == 1) {
        numeric_constants_one++;
      } else if (num == -1) {
        numeric_constants_minus_one++;
      } else if (num >= -9 && num <= 9) {
        numeric_constants_one_digit++; // note: not 1 or zero
      } else if (num >= -99 && num <= 99) {
        numeric_constants_two_digit++;
      } else if (num >= -999 && num <= 999) {
        numeric_constants_three_digit++;
      } else if (num >= -9999 && num <= 9999) {
        numeric_constants_four_digit++;
      } else if (num >= -99999 && num <= 99999) {
        numeric_constants_five_digit++;
      } else {
        numeric_constants_big++;
      }
      
      // count number of bytes separately
      if (num >= -128 && num <= 256) {
        numeric_constants_one_byte++;
      } else if (num >= -32767 && num <= 65536) {
        numeric_constants_two_byte++;
      } else if (num >= INT_MIN && num <= INT_MAX) {
        /* this one is probably redundant! */
        numeric_constants_four_byte++;
      }
    }
    /* everything else is a float */
    else {
        numeric_constants_float++;
    }
  }
    break;

  case 220:
#line 1598 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(string);
    new->parms.string = (yyvsp[(1) - (1)].s);
    (yyval.expression) = new;
      
    /* static analyzer code */
    size_t len = strlen((yyvsp[(1) - (1)].s));
    string_constants_total++;
    if (len == 0) {
      string_constants_zero++;
    } else if (len == 1) {
      string_constants_one_byte++;
    } else {
        string_constants_big++;
    }
    if (len > string_constants_max) string_constants_max = (int)len;
  }
    break;

  case 221:
#line 1617 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(variable);
    new->parms.variable = (yyvsp[(1) - (1)].variable);
    (yyval.expression) = new;
  }
    break;

  case 222:
#line 1624 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(fn);
    new->parms.variable = (yyvsp[(1) - (1)].variable); // use the variable slot here, it has the same signature
    (yyval.expression) = new;
  }
    break;

  case 223:
#line 1631 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.expression) = (yyvsp[(2) - (3)].expression);
  }
    break;

  case 224:
#line 1642 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;
    // do NOT insert it now, the variables are private and will be set up during the DEF
  }
    break;

  case 225:
#line 1652 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (1)].s);
    new->subscripts = NULL;
    new->slicing = NULL;
    (yyval.variable) = new;
    
    /* add it to the interpreter's variable list for the analyizer*/
    insert_variable(new);
  }
    break;

  case 226:
#line 1664 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    new->slicing = NULL;
    (yyval.variable) = new;
    
    /* this may result in errors about array bounds if you OPTION BASE after the DIM */
    insert_variable(new);
  }
    break;

  case 227:
#line 1676 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    new->slicing = NULL;
    (yyval.variable) = new;
    
    // square brackets tell us we are in the HP dialect, which means...
    string_slicing = true;
    
    insert_variable(new);
  }
    break;

  case 228:
#line 1690 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    /* this is the ANSI-style slicing command */
    /* NOTE: this should only ever occur in non-HP dialects, so the []'s would never appear */
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = NULL;
    new->slicing = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;
    
    insert_variable(new);
  }
    break;

  case 229:
#line 1703 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    /* and this is ANSI slicing of an entry in a string array */
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (7)].s);
    new->subscripts = (yyvsp[(3) - (7)].l);
    new->slicing = (yyvsp[(6) - (7)].l);
    (yyval.variable) = new;
    
    insert_variable(new);
  }
    break;

  case 230:
#line 1717 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = NULL;
  }
    break;

  case 231:
#line 1722 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(1) - (1)].expression);
    new->separator = 0;
    (yyval.l) = lst_append(NULL, new);
  }
    break;

  case 232:
#line 1731 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(2) - (2)].expression);
    new->separator = 0;
    (yyval.l) = lst_append((yyvsp[(1) - (2)].l), new);
  }
    break;

  case 233:
#line 1740 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(1) - (1)].i);
    (yyval.l) = lst_append(NULL, new);
  }
    break;

  case 234:
#line 1748 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(2) - (2)].i);
    (yyval.l) = lst_append((yyvsp[(1) - (2)].l), new);
  }
    break;

  case 235:
#line 1758 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.i) = ',';
  }
    break;

  case 236:
#line 1763 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.i) = ';';
  }
    break;

  case 237:
#line 1771 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].expression));
  }
    break;

  case 238:
#line 1776 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].expression));
  }
    break;

  case 239:
#line 1786 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
      (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (3)].expression));
      (yyval.l) = lst_append((yyval.l), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 240:
#line 1792 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
      (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (3)].expression));
      (yyval.l) = lst_append((yyval.l), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 241:
#line 1816 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].variable));
  }
    break;

  case 242:
#line 1821 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].variable));
  }
    break;


/* Line 1267 of yacc.c.  */
#line 4701 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/DerivedData/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1826 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"



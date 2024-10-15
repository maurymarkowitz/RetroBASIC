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
     RAISE = 382,
     ERR = 383,
     EL = 384,
     ER = 385,
     DEFSTR = 386,
     DEFINT = 387,
     DEFSNG = 388,
     DEFDBL = 389,
     CHANGE = 390,
     CONVERT = 391,
     UCASE = 392,
     LCASE = 393,
     STRNG = 394,
     TIME = 395,
     TIME_STR = 396,
     HEX = 397,
     OCT = 398,
     BIN = 399,
     HEXSTR = 400,
     OCTSTR = 401,
     BINSTR = 402,
     UBOUND = 403,
     LBOUND = 404,
     LABEL = 405,
     MAT = 406,
     MATPRINT = 407,
     MATINPUT = 408,
     MATREAD = 409,
     MATGET = 410,
     MATPUT = 411,
     MATZER = 412,
     MATCON = 413,
     MATIDN = 414,
     MATTRN = 415,
     MATINV = 416,
     MATDET = 417
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
#define RAISE 382
#define ERR 383
#define EL 384
#define ER 385
#define DEFSTR 386
#define DEFINT 387
#define DEFSNG 388
#define DEFDBL 389
#define CHANGE 390
#define CONVERT 391
#define UCASE 392
#define LCASE 393
#define STRNG 394
#define TIME 395
#define TIME_STR 396
#define HEX 397
#define OCT 398
#define BIN 399
#define HEXSTR 400
#define OCTSTR 401
#define BINSTR 402
#define UBOUND 403
#define LBOUND 404
#define LABEL 405
#define MAT 406
#define MATPRINT 407
#define MATINPUT 408
#define MATREAD 409
#define MATGET 410
#define MATPUT 411
#define MATZER 412
#define MATCON 413
#define MATIDN 414
#define MATTRN 415
#define MATINV 416
#define MATDET 417




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

static expression_t *make_expression(expression_type_e t)
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

#define YYDEBUG 1

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
#line 504 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 517 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"

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
#define YYLAST   1799

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  180
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNRULES -- Number of states.  */
#define YYNSTATES  352

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     163,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   175,     2,
     168,   169,   170,   173,   166,   174,     2,   176,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   164,   167,
     171,   165,   172,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   178,     2,   179,   177,     2,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    15,    19,    21,
      25,    28,    31,    32,    34,    36,    38,    40,    43,    48,
      53,    55,    57,    59,    61,    64,    69,    72,    75,    78,
      81,    84,    86,    89,    91,    98,   107,   110,   113,   118,
     121,   124,   129,   132,   137,   142,   147,   150,   155,   158,
     160,   162,   167,   172,   177,   181,   183,   186,   191,   193,
     196,   202,   205,   207,   210,   213,   215,   218,   221,   224,
     226,   228,   231,   233,   236,   239,   242,   245,   249,   254,
     257,   259,   261,   264,   268,   273,   281,   290,   298,   310,
     314,   318,   322,   327,   335,   340,   348,   353,   361,   366,
     374,   376,   378,   382,   384,   386,   388,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   412,   414,   416,   418,
     420,   424,   426,   428,   430,   432,   434,   436,   439,   441,
     443,   445,   447,   451,   456,   461,   468,   470,   475,   482,
     491,   493,   495,   497,   499,   501,   503,   505,   507,   509,
     511,   513,   515,   517,   519,   521,   523,   525,   527,   529,
     531,   533,   535,   537,   539,   541,   543,   545,   547,   549,
     551,   553,   555,   557,   559,   561,   563,   565,   567,   569,
     571,   573,   575,   577,   579,   581,   583,   585,   587,   589,
     591,   593,   595,   597,   599,   601,   603,   605,   607,   609,
     611,   613,   615,   619,   624,   626,   631,   636,   641,   649,
     650,   652,   655,   657,   660,   662,   664,   666,   670,   674,
     678,   680
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     181,     0,    -1,   182,    -1,   181,   163,   182,    -1,   181,
       1,   163,    -1,    -1,    -1,     4,   183,   184,    -1,   185,
      -1,   185,   164,   184,    -1,   184,    14,    -1,   184,    15,
      -1,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      54,   186,    -1,   135,   204,    44,   204,    -1,   136,   204,
      44,   204,    -1,    17,    -1,    18,    -1,    55,    -1,    56,
      -1,    19,   207,    -1,    20,   203,   165,   186,    -1,   134,
     209,    -1,   132,   209,    -1,   133,   209,    -1,   131,   209,
      -1,    21,   209,    -1,    22,    -1,   126,   186,    -1,    23,
      -1,    24,   204,   165,   186,    44,   186,    -1,    24,   204,
     165,   186,    44,   186,    41,   186,    -1,    26,     4,    -1,
      26,   186,    -1,    26,   186,    34,   207,    -1,    27,     4,
      -1,    27,   186,    -1,    27,   186,    34,   207,    -1,    29,
     205,    -1,    28,   186,    43,     4,    -1,    28,   186,    27,
       4,    -1,    28,   186,    43,   184,    -1,   150,   204,    -1,
      30,   204,   165,   186,    -1,    32,   209,    -1,    32,    -1,
      33,    -1,    35,   186,    27,   207,    -1,    35,   186,    26,
     207,    -1,    35,   126,    27,   207,    -1,    57,    58,   186,
      -1,    65,    -1,    65,   186,    -1,    60,   186,   166,   186,
      -1,    61,    -1,    36,   205,    -1,    36,    45,   186,   167,
     205,    -1,   127,   186,    -1,    62,    -1,    62,   186,    -1,
      38,   209,    -1,    67,    -1,    67,   186,    -1,   125,    32,
      -1,   125,   186,    -1,   125,    -1,    39,    -1,    39,   186,
      -1,    42,    -1,    42,   186,    -1,     3,   186,    -1,    63,
     186,    -1,   120,   186,    -1,   141,   165,   186,    -1,    30,
     141,   165,   186,    -1,   124,   186,    -1,   124,    -1,    64,
      -1,    46,   207,    -1,   204,   165,   186,    -1,   151,   204,
     165,   186,    -1,   151,   204,   165,   186,   168,   207,   169,
      -1,   151,   204,   165,   168,   186,   169,   170,   204,    -1,
     151,   204,   168,   207,   169,   165,   186,    -1,   151,   204,
     165,   168,   186,   169,   170,   204,   168,   207,   169,    -1,
     151,    36,   205,    -1,   151,    29,   205,    -1,   151,    38,
     209,    -1,   151,   204,   165,   158,    -1,   151,   204,   165,
     158,   168,   207,   169,    -1,   151,   204,   165,   162,    -1,
     151,   204,   165,   162,   168,   207,   169,    -1,   151,   204,
     165,   157,    -1,   151,   204,   165,   157,   168,   207,   169,
      -1,   151,   204,   165,   159,    -1,   151,   204,   165,   159,
     168,   207,   169,    -1,   187,    -1,   189,    -1,   187,   188,
     189,    -1,   107,    -1,   108,    -1,   191,    -1,   189,   190,
     191,    -1,   165,    -1,   171,    -1,   172,    -1,   113,    -1,
     114,    -1,   115,    -1,   116,    -1,   193,    -1,   191,   192,
     193,    -1,   173,    -1,   174,    -1,   175,    -1,   195,    -1,
     193,   194,   195,    -1,   170,    -1,   176,    -1,    83,    -1,
      85,    -1,   177,    -1,   197,    -1,   196,   197,    -1,   174,
      -1,   109,    -1,   202,    -1,   198,    -1,   198,   168,   169,
      -1,   198,   168,   186,   169,    -1,   199,   168,   186,   169,
      -1,   200,   168,   186,   166,   186,   169,    -1,   201,    -1,
     201,   168,   186,   169,    -1,   201,   168,   186,   166,   186,
     169,    -1,   201,   168,   186,   166,   186,   166,   186,   169,
      -1,   106,    -1,   118,    -1,    74,    -1,    75,    -1,   140,
      -1,   141,    -1,   129,    -1,   130,    -1,    68,    -1,   117,
      -1,    88,    -1,   144,    -1,   147,    -1,   102,    -1,    70,
      -1,    86,    -1,    71,    -1,    77,    -1,    78,    -1,   142,
      -1,   145,    -1,    76,    -1,   138,    -1,    99,    -1,   123,
      -1,    72,    -1,   143,    -1,   146,    -1,    59,    -1,    69,
      -1,    87,    -1,   119,    -1,    73,    -1,   100,    -1,   120,
      -1,   101,    -1,   137,    -1,   122,    -1,   128,    -1,    85,
      -1,    83,    -1,    96,    -1,    98,    -1,   139,    -1,   105,
      -1,   121,    -1,    97,    -1,   103,    -1,   104,    -1,    79,
      -1,   148,    -1,   149,    -1,   158,    -1,   162,    -1,   159,
      -1,   161,    -1,   160,    -1,   157,    -1,     4,    -1,     3,
      -1,   204,    -1,   203,    -1,   168,   186,   169,    -1,     9,
     168,   207,   169,    -1,     8,    -1,     8,   168,   207,   169,
      -1,     8,   178,   207,   179,    -1,     8,   168,   208,   169,
      -1,     8,   168,   207,   169,   168,   208,   169,    -1,    -1,
     186,    -1,   205,   186,    -1,   206,    -1,   205,   206,    -1,
     166,    -1,   167,    -1,   186,    -1,   207,   166,   186,    -1,
     186,   164,   186,    -1,   186,    44,   186,    -1,   204,    -1,
     209,   166,   204,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   248,   248,   250,   252,   258,   262,   262,   269,   274,
     279,   284,   293,   297,   304,   311,   318,   324,   330,   338,
     346,   352,   358,   364,   371,   378,   386,   394,   402,   410,
     418,   425,   431,   438,   444,   458,   471,   491,   511,   523,
     543,   563,   575,   582,   605,   625,   634,   642,   663,   670,
     677,   684,   696,   708,   719,   726,   732,   739,   747,   753,
     761,   769,   776,   783,   790,   797,   803,   810,   819,   826,
     832,   838,   845,   851,   858,   865,   872,   879,   886,   893,
     900,   907,   913,   920,   942,   950,   959,   967,   977,   985,
     992,   999,  1006,  1013,  1021,  1028,  1036,  1043,  1051,  1058,
    1088,  1091,  1093,  1103,  1104,  1108,  1110,  1152,  1153,  1154,
    1155,  1156,  1157,  1158,  1162,  1164,  1184,  1185,  1186,  1190,
    1192,  1201,  1202,  1203,  1204,  1205,  1208,  1210,  1219,  1220,
    1224,  1227,  1234,  1240,  1247,  1254,  1263,  1270,  1278,  1287,
    1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1311,  1312,
    1313,  1314,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1333,  1334,  1335,  1336,  1337,  1338,  1339,  1340,  1341,  1346,
    1347,  1348,  1349,  1350,  1355,  1356,  1357,  1358,  1359,  1360,
    1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1376,  1433,
    1452,  1459,  1466,  1477,  1487,  1499,  1511,  1525,  1538,  1553,
    1557,  1566,  1575,  1583,  1593,  1598,  1606,  1611,  1621,  1627,
    1651,  1656
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
  "PUT_FILE", "CALL", "CLS", "CMD", "OPTION", "BASE", "PEEK", "POKE",
  "POP", "RANDOMIZE", "SYS", "VARLIST", "PAUSE", "SLEEP", "RESTORE", "ABS",
  "SGN", "CLOG", "EXP", "LOG", "SQR", "PI", "RND", "INT", "FIX", "FRAC",
  "ROUND", "CINT", "CSNG", "CDBL", "MOD", "MOD_INT", "DIV", "COS", "SIN",
  "ATN", "ACS", "ASN", "TAN", "COSH", "SINH", "TANH", "ASC", "LEFT", "MID",
  "RIGHT", "LEN", "STR", "VAL", "CHR", "SEG", "SUBSTR", "INSTR", "INKEY",
  "AND", "OR", "NOT", "XOR", "EQV", "IMP", "CMP_LE", "CMP_GE", "CMP_NE",
  "CMP_HASH", "ADR", "FRE", "SPC", "TAB", "POS", "USR", "LIN", "TRAP",
  "RESUME", "ERROR", "RAISE", "ERR", "EL", "ER", "DEFSTR", "DEFINT",
  "DEFSNG", "DEFDBL", "CHANGE", "CONVERT", "UCASE", "LCASE", "STRNG",
  "TIME", "TIME_STR", "HEX", "OCT", "BIN", "HEXSTR", "OCTSTR", "BINSTR",
  "UBOUND", "LBOUND", "LABEL", "MAT", "MATPRINT", "MATINPUT", "MATREAD",
  "MATGET", "MATPUT", "MATZER", "MATCON", "MATIDN", "MATTRN", "MATINV",
  "MATDET", "'\\n'", "':'", "'='", "','", "';'", "'('", "')'", "'*'",
  "'<'", "'>'", "'+'", "'-'", "'&'", "'/'", "'^'", "'['", "']'", "$accept",
  "program", "line", "@1", "statements", "statement", "expression",
  "expression0", "binary_op", "expression1", "comparison_op",
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
     415,   416,   417,    10,    58,    61,    44,    59,    40,    41,
      42,    60,    62,    43,    45,    38,    47,    94,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   180,   181,   181,   181,   182,   183,   182,   184,   184,
     184,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   190,
     190,   190,   190,   190,   191,   191,   192,   192,   192,   193,
     193,   194,   194,   194,   194,   194,   195,   195,   196,   196,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     198,   198,   198,   198,   198,   198,   198,   198,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   200,
     200,   200,   200,   200,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   202,   202,
     202,   202,   202,   203,   204,   204,   204,   204,   204,   205,
     205,   205,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   209
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     0,     3,     1,     3,
       2,     2,     0,     1,     1,     1,     1,     2,     4,     4,
       1,     1,     1,     1,     2,     4,     2,     2,     2,     2,
       2,     1,     2,     1,     6,     8,     2,     2,     4,     2,
       2,     4,     2,     4,     4,     4,     2,     4,     2,     1,
       1,     4,     4,     4,     3,     1,     2,     4,     1,     2,
       5,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       1,     2,     1,     2,     2,     2,     2,     3,     4,     2,
       1,     1,     2,     3,     4,     7,     8,     7,    11,     3,
       3,     3,     4,     7,     4,     7,     4,     7,     4,     7,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     4,     4,     6,     1,     4,     6,     8,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     4,     4,     4,     7,     0,
       1,     2,     1,     2,     1,     1,     1,     3,     3,     3,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     6,     0,     2,    12,     1,     0,     5,     0,   204,
      13,    14,    15,    16,    20,    21,     0,     0,     0,    31,
      33,     0,     0,     0,     0,   209,     0,    49,    50,     0,
     209,     0,    70,    72,     0,     0,    22,    23,     0,     0,
      58,    62,     0,    81,    55,    65,     0,    80,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     8,     0,     4,     3,   199,   198,     0,   168,   148,
     169,   154,   156,   165,   172,   142,   143,   161,   157,   158,
     189,   180,   179,   155,   170,   150,   181,   186,   182,   163,
     173,   175,   153,   187,   188,   184,   140,   129,   149,   141,
     171,   174,   185,   177,   164,   178,   146,   147,   176,   162,
     183,   144,   145,   159,   166,   151,   160,   167,   152,   190,
     191,   197,   192,   194,   196,   195,   193,     0,   128,    74,
     100,   101,   105,   114,   119,     0,   126,   131,     0,     0,
     136,   130,   201,   200,     0,     0,   216,    24,     0,   220,
      30,     0,   198,    37,   198,    40,     0,   214,   215,   210,
      42,   212,     0,     0,    48,     0,     0,     0,    59,    64,
      71,    73,    82,    17,     0,     0,    63,    75,    56,    66,
      76,    79,    67,    68,    32,    61,    29,    27,    28,    26,
       0,     0,     0,    46,   209,   209,     0,     0,    10,    11,
      12,     0,     0,     0,   103,   104,     0,   110,   111,   112,
     113,   107,   108,   109,     0,   116,   117,   118,     0,   123,
     124,   121,   122,   125,     0,   127,     0,     0,     0,     0,
     216,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,   211,   213,     0,     0,     0,     0,     0,     0,
      54,     0,     0,     0,    77,    90,    89,    91,     0,     0,
       9,    83,     0,   202,   102,   106,   115,   120,   132,     0,
       0,     0,     0,     0,     0,   205,   207,   206,   217,    25,
     221,     0,    38,    41,    44,    43,    45,    78,    47,    53,
      52,    51,   209,    57,    18,    19,   197,   192,   194,   193,
       0,    84,     0,   203,   133,   134,     0,     0,   137,   219,
     218,     0,     0,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
     202,     0,     0,   135,     0,   138,   208,     0,    97,    93,
      99,    95,     0,    85,    87,     0,    35,    86,   139,     0,
       0,    88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    60,    61,   146,   130,   206,   131,
     214,   132,   218,   133,   224,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   160,   161,   147,   232,   150
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -198
static const yytype_int16 yypact[] =
{
       0,  -198,     7,  -198,  1648,  -198,  -145,     0,   920,  -132,
    -198,  -198,  -198,  -198,  -198,  -198,   920,    36,    35,  -198,
    -198,    35,  1027,  1134,   920,   436,    -3,    35,  -198,   559,
     313,    35,   920,   920,   920,   920,  -198,  -198,     2,   920,
    -198,   920,   920,  -198,   920,   920,   920,   920,   706,   920,
     920,    35,    35,    35,    35,    35,    35,  -112,    35,    32,
      71,   -92,   -88,  -198,  -198,  -198,  -198,   -54,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,   920,  -198,  -198,
      -8,   -22,  -136,   -57,  -198,  1348,  -198,   -53,   -52,   -47,
     -46,  -198,  -198,  -198,   920,   920,  -198,   -38,   -36,  -198,
     -30,   -19,   111,   101,   117,   113,    -2,  -198,  -198,  -198,
     436,  -198,   -12,    -9,   -30,   130,    80,   920,   436,   -30,
    -198,  -198,   -38,  -198,   920,    -7,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,   -30,   -30,   -30,   -30,
     114,   116,   920,  -198,   436,   436,    35,  -153,  -198,  -198,
    1648,   920,   920,    -6,  -198,  -198,   920,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,   920,  -198,  -198,  -198,   920,  -198,
    -198,  -198,  -198,  -198,   920,  -198,   813,   920,   920,   920,
     -31,  -150,    -1,  -155,   920,   920,    35,   920,   920,   920,
     158,  1509,  -198,  -198,   920,   920,   920,   920,   920,     4,
    -198,   920,    35,    35,  -198,   436,   436,   -30,  1241,   920,
      71,  -198,  -104,  -198,   -22,  -136,   -57,  -198,  -198,     3,
       5,    10,   -95,   920,   920,     1,  -198,  -198,  -198,  -198,
    -198,   120,   -38,   -38,  -198,  -198,    71,  -198,  -198,   -38,
     -38,   -38,   436,  -198,  -198,  -198,    20,    87,    89,   109,
     920,     9,   -71,  -198,  -198,  -198,   920,   920,  -198,  -198,
    -198,   920,   920,   436,   920,   920,   920,   920,    11,   920,
       8,    12,   -61,   -31,    13,   124,   -39,   -32,   -25,   -24,
      15,   -18,   920,  -198,   920,  -198,  -198,   920,  -198,  -198,
    -198,  -198,    35,  -198,  -198,    17,  -198,    19,  -198,   920,
     -14,  -198
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,   172,  -198,  -197,  -198,    34,  -198,  -198,   -17,
    -198,   -23,  -198,   -20,  -198,   -34,  -198,    58,  -198,  -198,
    -198,  -198,  -198,   178,    -4,   -28,  -159,    -5,  -111,   -21
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -99
static const yytype_int16 yytable[] =
{
      62,   243,   168,   260,     1,     9,   164,     5,     6,   243,
     169,   234,   258,   273,   149,   259,   234,   151,    63,   275,
     -96,   -96,   163,   149,   277,   240,   219,   149,   220,   172,
     186,   187,   188,   189,   -96,   -96,   144,   215,   216,   217,
       9,   241,   129,     9,   286,    67,   145,   149,   149,   149,
     149,   190,   191,   192,   193,   197,   153,   155,   156,   159,
     174,   194,   234,   166,   159,   303,   170,   171,   195,   173,
     196,   307,   200,   175,   308,   176,   177,   201,   178,   179,
     180,   181,   183,   184,   185,   198,   199,   -92,   -92,   -98,
     -98,   207,   208,   209,   210,   234,   243,   243,   320,   204,
     205,   -92,   -92,   -98,   -98,   334,   247,   248,   335,   -94,
     -94,   -36,   -36,   221,   202,   226,   227,   -39,   -39,   222,
     223,   228,   229,   -94,   -94,   -36,   -36,   234,   234,   235,
     338,   -39,   -39,   274,   234,   238,   236,   339,   162,   231,
     233,   234,   234,   211,   340,   341,   237,   239,   234,   212,
     213,   343,   234,   244,   243,   351,   245,   246,   252,   251,
     253,   203,   284,   263,   312,   337,   255,   256,   276,   311,
       7,   292,   304,   332,   305,   257,   306,   319,   230,    64,
     330,   333,   336,   -96,   -96,   342,   348,   349,   314,   264,
     267,   265,   149,   225,   242,   148,    62,   262,   266,     0,
     324,   249,   242,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,   159,   159,
       0,     0,   280,   282,   283,   261,     0,    62,     0,     0,
       0,   289,   290,   291,     0,     0,     0,     0,   294,   295,
     -92,   -92,   -98,   -98,   302,   315,     0,   316,     0,     0,
     269,   270,   271,   272,   313,     0,     0,     0,   278,   279,
       0,   281,   -94,   -94,   -36,   -36,     0,   317,   287,   288,
     -39,   -39,     0,     0,     0,   293,     0,     0,     0,   242,
     242,     0,   301,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   309,   310,   326,
     327,   328,   329,     0,   331,     0,    65,    66,     0,     0,
       0,     9,    67,     0,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,   318,     0,     0,     0,   347,     0,
     321,   322,     0,     0,   350,   323,   325,   242,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   167,     0,
       0,     0,     0,     0,     0,     0,   344,     0,   345,     0,
       0,   346,    68,     0,     0,     0,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    81,     0,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,    97,     0,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,     0,     0,    65,
      66,   105,   106,   107,     9,    67,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,     0,     0,     0,   157,
     158,   127,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    81,
       0,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
       0,     0,    65,    66,   105,   106,   107,     9,    67,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   125,   126,     0,
       0,     0,   157,   158,   127,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,     0,
       0,     0,    81,     0,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,     0,     0,   165,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    65,
      66,     0,     0,     0,     9,    67,   121,   122,   123,   124,
     125,   126,     0,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,   182,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,    81,
       0,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,     0,     0,    97,    65,    66,     0,     0,
       0,     9,    67,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,   121,   122,   123,   124,   125,   126,     0,
       0,     0,    68,     0,   127,     0,     0,     0,     0,     0,
     128,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,     0,     0,     0,    81,     0,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       0,     0,    97,    65,    66,     0,     0,     0,     9,    67,
      98,    99,   100,   101,   102,   103,   104,     0,     0,     0,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,     0,     0,     0,     0,     0,     0,     0,
     121,   122,   123,   124,   125,   126,     0,     0,     0,    68,
       0,   127,   268,     0,     0,     0,     0,   128,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
       0,     0,     0,    81,     0,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,     0,     0,    97,
      65,   152,     0,     0,     0,     9,    67,    98,    99,   100,
     101,   102,   103,   104,     0,     0,     0,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,   121,   122,   123,
     124,   125,   126,     0,     0,     0,    68,     0,   127,     0,
       0,     0,     0,     0,   128,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     0,     0,     0,
      81,     0,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,     0,     0,    97,    65,   154,     0,
       0,     0,     9,    67,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   123,   124,   125,   126,
       0,     0,     0,    68,     0,   127,     0,     0,     0,     0,
       0,   128,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,     0,     0,     0,    81,     0,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,    97,    65,    66,     0,     0,     0,     9,
      67,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,   121,   122,   123,   124,   125,   126,     0,     0,     0,
      68,     0,   127,     0,     0,     0,     0,     0,   128,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,     0,     0,    81,     0,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,     0,     0,
      97,    65,    66,     0,     0,     0,     9,    67,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,     0,     0,     0,     0,     0,     0,     0,   296,   297,
     298,   124,   125,   299,     0,     0,     0,    68,     0,   300,
       0,     0,     0,     0,     0,   128,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,    81,     0,    82,    83,    84,    85,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,     0,     0,     0,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,   121,   122,   123,   124,   125,
     126,     0,     8,   285,     0,     0,   127,     9,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,    22,    23,    24,    25,    26,
       0,    27,    28,     0,    29,    30,     0,    31,    32,     0,
       0,    33,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    35,    36,    37,    38,     0,     0,    39,
      40,    41,    42,    43,    44,     0,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
       0,     0,     0,    47,    48,    49,    50,     0,     0,     0,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
      57,     8,     0,     0,     0,     0,     9,     0,     0,    58,
      59,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,    22,    23,    24,    25,    26,     0,
      27,    28,     0,    29,    30,     0,    31,    32,     0,     0,
      33,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,    35,    36,    37,    38,     0,     0,    39,    40,
      41,    42,    43,    44,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
       0,     0,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59
};

static const yytype_int16 yycheck[] =
{
       4,   160,    30,   200,     4,     8,    27,     0,     1,   168,
      31,   166,   165,    44,    18,   168,   166,    21,   163,   169,
       0,     1,    26,    27,   179,    27,    83,    31,    85,    34,
      51,    52,    53,    54,    14,    15,   168,   173,   174,   175,
       8,    43,     8,     8,   241,     9,   178,    51,    52,    53,
      54,    55,    56,   165,    58,    59,    22,    23,    24,    25,
      58,    29,   166,    29,    30,   169,    32,    33,    36,    35,
      38,   166,   164,    39,   169,    41,    42,   165,    44,    45,
      46,    47,    48,    49,    50,    14,    15,     0,     1,     0,
       1,   113,   114,   115,   116,   166,   255,   256,   169,   107,
     108,    14,    15,    14,    15,   166,    26,    27,   169,     0,
       1,     0,     1,   170,   168,   168,   168,     0,     1,   176,
     177,   168,   168,    14,    15,    14,    15,   166,   166,   165,
     169,    14,    15,   164,   166,    34,   166,   169,   141,   144,
     145,   166,   166,   165,   169,   169,   165,    34,   166,   171,
     172,   169,   166,   165,   313,   169,   165,    27,    44,   166,
      44,   127,     4,   169,    44,    41,   194,   195,   169,   168,
     163,   167,   169,   165,   169,   196,   166,   168,   144,     7,
     169,   169,   169,   163,   164,   170,   169,   168,   168,   206,
     224,   214,   196,   135,   160,    17,   200,   202,   218,    -1,
     311,   167,   168,    -1,    -1,    -1,    -1,    -1,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,
      -1,    -1,   236,   238,   239,   201,    -1,   241,    -1,    -1,
      -1,   246,   247,   248,    -1,    -1,    -1,    -1,   252,   253,
     163,   164,   163,   164,   259,   168,    -1,   168,    -1,    -1,
     226,   227,   228,   229,   292,    -1,    -1,    -1,   234,   235,
      -1,   237,   163,   164,   163,   164,    -1,   168,   244,   245,
     163,   164,    -1,    -1,    -1,   251,    -1,    -1,    -1,   255,
     256,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   273,   274,   314,
     315,   316,   317,    -1,   319,    -1,     3,     4,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,   292,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,   342,    -1,
     306,   307,    -1,    -1,   349,   311,   312,   313,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,   334,    -1,
      -1,   337,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,    -1,    -1,     3,
       4,   128,   129,   130,     8,     9,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,     3,     4,   128,   129,   130,     8,     9,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    -1,
      -1,    -1,    83,    -1,    85,    86,    87,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,    -1,    -1,   126,    -1,   128,   129,   130,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,     3,
       4,    -1,    -1,    -1,     8,     9,   157,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
      -1,    -1,    -1,   174,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,   109,     3,     4,    -1,    -1,
      -1,     8,     9,   117,   118,   119,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    59,    -1,   168,    -1,    -1,    -1,    -1,    -1,
     174,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,    86,
      87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,   109,     3,     4,    -1,    -1,    -1,     8,     9,
     117,   118,   119,   120,   121,   122,   123,    -1,    -1,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    59,
      -1,   168,   169,    -1,    -1,    -1,    -1,   174,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,   109,
       3,     4,    -1,    -1,    -1,     8,     9,   117,   118,   119,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    59,    -1,   168,    -1,
      -1,    -1,    -1,    -1,   174,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    -1,
      83,    -1,    85,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   109,     3,     4,    -1,
      -1,    -1,     8,     9,   117,   118,   119,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    59,    -1,   168,    -1,    -1,    -1,    -1,
      -1,   174,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,    85,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,    -1,    -1,   109,     3,     4,    -1,    -1,    -1,     8,
       9,   117,   118,   119,   120,   121,   122,   123,    -1,    -1,
      -1,    -1,   128,   129,   130,    -1,    -1,    -1,    -1,    -1,
      -1,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      59,    -1,   168,    -1,    -1,    -1,    -1,    -1,   174,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
     109,     3,     4,    -1,    -1,    -1,     8,     9,   117,   118,
     119,   120,   121,   122,   123,    -1,    -1,    -1,    -1,   128,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    59,    -1,   168,
      -1,    -1,    -1,    -1,    -1,   174,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    83,    -1,    85,    86,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,   158,   159,   160,   161,
     162,    -1,     3,     4,    -1,    -1,   168,     8,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    -1,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,
     131,   132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,
     141,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,   150,
     151,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    36,    -1,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,   124,   125,   126,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,   136,    -1,    -1,    -1,    -1,   141,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,   151
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,   181,   182,   183,     0,     1,   163,     3,     8,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    26,    27,    28,    29,    30,    32,    33,    35,
      36,    38,    39,    42,    46,    54,    55,    56,    57,    60,
      61,    62,    63,    64,    65,    67,   120,   124,   125,   126,
     127,   131,   132,   133,   134,   135,   136,   141,   150,   151,
     184,   185,   204,   163,   182,     3,     4,     9,    59,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    83,    85,    86,    87,    88,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   109,   117,   118,
     119,   120,   121,   122,   123,   128,   129,   130,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   157,   158,   159,   160,   161,   162,   168,   174,   186,
     187,   189,   191,   193,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   168,   178,   186,   207,   203,   204,
     209,   204,     4,   186,     4,   186,   186,   166,   167,   186,
     205,   206,   141,   204,   209,   126,   186,    45,   205,   209,
     186,   186,   207,   186,    58,   186,   186,   186,   186,   186,
     186,   186,    32,   186,   186,   186,   209,   209,   209,   209,
     204,   204,   165,   204,    29,    36,    38,   204,    14,    15,
     164,   165,   168,   186,   107,   108,   188,   113,   114,   115,
     116,   165,   171,   172,   190,   173,   174,   175,   192,    83,
      85,   170,   176,   177,   194,   197,   168,   168,   168,   168,
     186,   207,   208,   207,   166,   165,   166,   165,    34,    34,
      27,    43,   186,   206,   165,   165,    27,    26,    27,   186,
     186,   166,    44,    44,   186,   205,   205,   209,   165,   168,
     184,   186,   207,   169,   189,   191,   193,   195,   169,   186,
     186,   186,   186,    44,   164,   169,   169,   179,   186,   186,
     204,   186,   207,   207,     4,     4,   184,   186,   186,   207,
     207,   207,   167,   186,   204,   204,   157,   158,   159,   162,
     168,   186,   207,   169,   169,   169,   166,   166,   169,   186,
     186,   168,    44,   205,   168,   168,   168,   168,   186,   168,
     169,   186,   186,   186,   208,   186,   207,   207,   207,   207,
     169,   207,   165,   169,   166,   169,   169,    41,   169,   169,
     169,   169,   170,   169,   186,   186,   186,   204,   169,   168,
     207,   169
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
#line 258 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
  }
    break;

  case 6:
#line 262 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { errline = (yyvsp[(1) - (1)].d); }
    break;

  case 7:
#line 263 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    interpreter_state.lines[(int)(yyvsp[(1) - (3)].d)] = (yyvsp[(3) - (3)].l);
  }
    break;

  case 8:
#line 270 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].statement));
  }
    break;

  case 9:
#line 275 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].statement));
  }
    break;

  case 10:
#line 280 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(1) - (2)].l), NULL);
  }
    break;

  case 11:
#line 285 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(1) - (2)].l), NULL);
  }
    break;

  case 12:
#line 293 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.statement) = NULL;
  }
    break;

  case 13:
#line 298 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(REM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 14:
#line 305 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(QUOTEREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 15:
#line 312 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(BANGREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 16:
#line 319 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(BYE);
    (yyval.statement) = new;
  }
    break;

  case 17:
#line 325 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CALL);
    (yyval.statement) = new;
  }
    break;

  case 18:
#line 331 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CHANGE);
    new->parms.change.var1 = (yyvsp[(2) - (4)].variable);
    new->parms.change.var2 = (yyvsp[(4) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 19:
#line 339 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CONVERT);
    new->parms.change.var1 = (yyvsp[(2) - (4)].variable);
    new->parms.change.var2 = (yyvsp[(4) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 20:
#line 347 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLEAR);
    (yyval.statement) = new;
  }
    break;

  case 21:
#line 353 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLEAR);
    (yyval.statement) = new;
  }
    break;

  case 22:
#line 359 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLS);
    (yyval.statement) = new;
  }
    break;

  case 23:
#line 365 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CMD);
    (yyval.statement) = new;
  }
    break;

  case 24:
#line 372 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DATA);
    new->parms.data = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 25:
#line 379 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEF);
    new->parms.def.signature = (yyvsp[(2) - (4)].variable);
    new->parms.def.formula = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 26:
#line 387 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = DOUBLE;
    (yyval.statement) = new;
  }
    break;

  case 27:
#line 395 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = INTEGER;
    (yyval.statement) = new;
  }
    break;

  case 28:
#line 403 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = SINGLE;
    (yyval.statement) = new;
  }
    break;

  case 29:
#line 411 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = STRING;
    (yyval.statement) = new;
  }
    break;

  case 30:
#line 419 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DIM);
    new->parms.dim = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 31:
#line 426 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(END);
    (yyval.statement) = new;
  }
    break;

  case 32:
#line 432 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RAISE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 33:
#line 439 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(EXIT);
    (yyval.statement) = new;
  }
    break;

  case 34:
#line 445 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 35:
#line 459 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 36:
#line 472 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 37:
#line 492 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 38:
#line 512 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 39:
#line 524 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 40:
#line 544 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 41:
#line 564 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 42:
#line 576 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(INPUT);
    new->parms.input = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 43:
#line 583 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 44:
#line 606 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 45:
#line 626 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(IF);
    new->parms._if.condition = (yyvsp[(2) - (4)].expression);
    new->parms._if.then_expression = (yyvsp[(4) - (4)].l);
    new->parms._if.then_linenumber = 0;
    (yyval.statement) = new;
  }
    break;

  case 46:
#line 635 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(LABEL);
    new->parms.label.variable = (yyvsp[(2) - (2)].variable);
    new->parms.label.linenumber = errline;
    (yyval.statement) = new;
  }
    break;

  case 47:
#line 643 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 48:
#line 664 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 49:
#line 671 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = NULL;
    (yyval.statement) = new;
  }
    break;

  case 50:
#line 678 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEW);
    new->parms.next = NULL;
    (yyval.statement) = new;
  }
    break;

  case 51:
#line 685 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 52:
#line 697 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 53:
#line 709 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = TRAP;
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
    
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  }
    break;

  case 54:
#line 720 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OPTION);
    new->parms.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  }
    break;

  case 55:
#line 727 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PAUSE);
    (yyval.statement) = new;
  }
    break;

  case 56:
#line 733 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PAUSE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 57:
#line 740 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(POKE);
    new->parms.generic_parameter = (yyvsp[(2) - (4)].expression);
    new->parms.generic_parameter2 = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 58:
#line 748 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(POP);
    (yyval.statement) = new;
  }
    break;

  case 59:
#line 754 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PRINT);
    new->parms.print.format = NULL;
    new->parms.print.item_list = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 60:
#line 762 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(PRINT);
    new->parms.print.format = (yyvsp[(3) - (5)].expression);
    new->parms.print.item_list = (yyvsp[(5) - (5)].l);
    (yyval.statement) = new;
  }
    break;

  case 61:
#line 770 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RAISE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 62:
#line 777 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = NULL;
    (yyval.statement) = new;
  }
    break;

  case 63:
#line 784 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 64:
#line 791 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(READ);
    new->parms.read = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 65:
#line 798 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    (yyval.statement) = new;
  }
    break;

  case 66:
#line 804 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 67:
#line 811 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESUME);
    expression_t *exp = make_expression(number);
    exp->parms.number = -1;
    new->parms.generic_parameter = exp;
    (yyval.statement) = new;
  }
    break;

  case 68:
#line 820 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESUME);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 69:
#line 827 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESUME);
    (yyval.statement) = new;
  }
    break;

  case 70:
#line 833 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RETURN);
    (yyval.statement) = new;
  }
    break;

  case 71:
#line 839 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RETURN);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 72:
#line 846 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(STOP);
    (yyval.statement) = new;
  }
    break;

  case 73:
#line 852 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(STOP);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 74:
#line 859 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(STOP);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 75:
#line 866 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(SYS);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 76:
#line 873 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TAB);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 77:
#line 880 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  }
    break;

  case 78:
#line 887 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic_parameter = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 79:
#line 894 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TRAP);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 80:
#line 901 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(TRAP);
    new->parms.generic_parameter = NULL;
    (yyval.statement) = new;
  }
    break;

  case 81:
#line 908 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(VARLIST);
    (yyval.statement) = new;
  }
    break;

  case 82:
#line 914 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(WAIT);
    (yyval.statement) = new;
  }
    break;

  case 83:
#line 921 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 84:
#line 943 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.let.variable = (yyvsp[(2) - (4)].variable);
    new->parms.let.expression = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 85:
#line 951 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.let.variable = (yyvsp[(2) - (7)].variable);
    new->parms.let.expression = (yyvsp[(4) - (7)].expression);
    new->parms.let.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 86:
#line 960 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.let.variable = (yyvsp[(2) - (8)].variable);
    new->parms.let.expression = (yyvsp[(5) - (8)].expression);
    (yyval.statement) = new;
  }
    break;

  case 87:
#line 968 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.let.variable = (yyvsp[(2) - (7)].variable);
    new->parms.let.expression = (yyvsp[(7) - (7)].expression);
    new->parms.let.variable->subscripts = (yyvsp[(4) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 88:
#line 978 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.let.variable = (yyvsp[(2) - (11)].variable);
    new->parms.let.variable->subscripts = (yyvsp[(10) - (11)].l);
    (yyval.statement) = new;
  }
    break;

  case 89:
#line 986 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATPRINT);
    new->parms.print.item_list = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  }
    break;

  case 90:
#line 993 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATINPUT);
    new->parms.input = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  }
    break;

  case 91:
#line 1000 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATREAD);
    new->parms.read = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  }
    break;

  case 92:
#line 1007 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATCON);
    new->parms.let.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 93:
#line 1014 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATCON);
    new->parms.let.variable = (yyvsp[(2) - (7)].variable);
    new->parms.let.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 94:
#line 1022 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATDET);
    new->parms.let.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 95:
#line 1029 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATDET);
    new->parms.let.variable = (yyvsp[(2) - (7)].variable);
    new->parms.let.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 96:
#line 1037 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATZER);
    new->parms.let.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 97:
#line 1044 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATZER);
    new->parms.let.variable = (yyvsp[(2) - (7)].variable);
    new->parms.let.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 98:
#line 1052 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.let.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  }
    break;

  case 99:
#line 1059 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.let.variable = (yyvsp[(2) - (7)].variable);
    new->parms.let.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  }
    break;

  case 102:
#line 1094 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
  }
    break;

  case 103:
#line 1103 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = AND; }
    break;

  case 104:
#line 1104 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = OR;  }
    break;

  case 106:
#line 1111 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 107:
#line 1152 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '='; }
    break;

  case 108:
#line 1153 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '<'; }
    break;

  case 109:
#line 1154 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '>'; }
    break;

  case 110:
#line 1155 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_LE; }
    break;

  case 111:
#line 1156 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_GE; }
    break;

  case 112:
#line 1157 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_NE; }
    break;

  case 113:
#line 1158 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_HASH; }
    break;

  case 115:
#line 1165 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 116:
#line 1184 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '+'; }
    break;

  case 117:
#line 1185 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 118:
#line 1186 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '&'; }
    break;

  case 120:
#line 1193 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
  }
    break;

  case 121:
#line 1201 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '*'; }
    break;

  case 122:
#line 1202 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '/'; }
    break;

  case 123:
#line 1203 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MOD; }
    break;

  case 124:
#line 1204 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = DIV; }
    break;

  case 125:
#line 1205 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '^'; }
    break;

  case 127:
#line 1211 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (2)].i));
    new->parms.op.p[0] = (yyvsp[(2) - (2)].expression);
    (yyval.expression) = new;
  }
    break;

  case 128:
#line 1219 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 129:
#line 1220 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = NOT; }
    break;

  case 131:
#line 1228 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (1)].i));
    (yyval.expression) = new;
  }
    break;

  case 132:
#line 1235 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (3)].i));
    (yyval.expression) = new;
  }
    break;

  case 133:
#line 1241 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  }
    break;

  case 134:
#line 1248 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  }
    break;

  case 135:
#line 1255 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  }
    break;

  case 136:
#line 1264 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (1)].i));
    (yyval.expression) = new;
  }
    break;

  case 137:
#line 1271 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  }
    break;

  case 138:
#line 1279 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  }
    break;

  case 139:
#line 1288 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(3, (yyvsp[(1) - (8)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (8)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (8)].expression);
    new->parms.op.p[2] = (yyvsp[(7) - (8)].expression);
    (yyval.expression) = new;
  }
    break;

  case 140:
#line 1299 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = INKEY; }
    break;

  case 141:
#line 1300 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = FRE; }
    break;

  case 142:
#line 1301 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = PI; }
    break;

  case 143:
#line 1302 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = RND; }
    break;

  case 144:
#line 1303 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = TIME; }
    break;

  case 145:
#line 1304 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = TIME_STR; }
    break;

  case 146:
#line 1305 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = EL; }
    break;

  case 147:
#line 1306 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ER; }
    break;

  case 148:
#line 1311 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) =  ABS; }
    break;

  case 149:
#line 1312 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ADR; }
    break;

  case 150:
#line 1313 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ATN; }
    break;

  case 151:
#line 1314 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = BIN; }
    break;

  case 152:
#line 1315 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = BINSTR; }
    break;

  case 153:
#line 1316 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CHR; }
    break;

  case 154:
#line 1317 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = CLOG;}
    break;

  case 155:
#line 1318 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = COS; }
    break;

  case 156:
#line 1319 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = EXP; }
    break;

  case 157:
#line 1320 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = FIX; }
    break;

  case 158:
#line 1321 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = FRAC; }
    break;

  case 159:
#line 1322 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = HEX; }
    break;

  case 160:
#line 1323 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = HEXSTR; }
    break;

  case 161:
#line 1324 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = INT; }
    break;

  case 162:
#line 1325 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LCASE; }
    break;

  case 163:
#line 1326 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LEN; }
    break;

  case 164:
#line 1327 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LIN; }
    break;

  case 165:
#line 1328 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LOG; }
    break;

  case 166:
#line 1329 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = OCT; }
    break;

  case 167:
#line 1330 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = OCTSTR; }
    break;

  case 168:
#line 1331 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = PEEK;}
    break;

  case 169:
#line 1332 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SGN; }
    break;

  case 170:
#line 1333 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SIN; }
    break;

  case 171:
#line 1334 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SPC; }
    break;

  case 172:
#line 1335 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SQR; }
    break;

  case 173:
#line 1336 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = STR; }
    break;

  case 174:
#line 1337 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = TAB; }
    break;

  case 175:
#line 1338 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = VAL; }
    break;

  case 176:
#line 1339 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = UCASE; }
    break;

  case 177:
#line 1340 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = USR; }
    break;

  case 178:
#line 1341 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ERR; }
    break;

  case 179:
#line 1346 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = DIV; }
    break;

  case 180:
#line 1347 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MOD; }
    break;

  case 181:
#line 1348 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LEFT; }
    break;

  case 182:
#line 1349 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = RIGHT; }
    break;

  case 183:
#line 1350 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = STRNG; }
    break;

  case 184:
#line 1355 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = INSTR; }
    break;

  case 185:
#line 1356 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = POS; }
    break;

  case 186:
#line 1357 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MID; }
    break;

  case 187:
#line 1358 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SEG; }
    break;

  case 188:
#line 1359 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = SUBSTR; }
    break;

  case 189:
#line 1360 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = ROUND; }
    break;

  case 190:
#line 1361 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = UBOUND; }
    break;

  case 191:
#line 1362 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = LBOUND; }
    break;

  case 192:
#line 1363 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATCON; }
    break;

  case 193:
#line 1364 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATDET; }
    break;

  case 194:
#line 1365 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATIDN; }
    break;

  case 195:
#line 1366 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATINV; }
    break;

  case 196:
#line 1367 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATTRN; }
    break;

  case 197:
#line 1368 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    { (yyval.i) = MATZER; }
    break;

  case 198:
#line 1377 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 199:
#line 1434 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 200:
#line 1453 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(variable);
    new->parms.variable = (yyvsp[(1) - (1)].variable);
    (yyval.expression) = new;
  }
    break;

  case 201:
#line 1460 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(fn);
    new->parms.variable = (yyvsp[(1) - (1)].variable); // use the variable slot here, it has the same signature
    (yyval.expression) = new;
  }
    break;

  case 202:
#line 1467 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.expression) = (yyvsp[(2) - (3)].expression);
  }
    break;

  case 203:
#line 1478 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;
    // do NOT insert it now, the variables are private and will be set up during the DEF
  }
    break;

  case 204:
#line 1488 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 205:
#line 1500 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 206:
#line 1512 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 207:
#line 1526 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 208:
#line 1539 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
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

  case 209:
#line 1553 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = NULL;
  }
    break;

  case 210:
#line 1558 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(1) - (1)].expression);
    new->separator = 0;
    (yyval.l) = lst_append(NULL, new);
  }
    break;

  case 211:
#line 1567 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(2) - (2)].expression);
    new->separator = 0;
    (yyval.l) = lst_append((yyvsp[(1) - (2)].l), new);
  }
    break;

  case 212:
#line 1576 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(1) - (1)].i);
    (yyval.l) = lst_append(NULL, new);
  }
    break;

  case 213:
#line 1584 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(2) - (2)].i);
    (yyval.l) = lst_append((yyvsp[(1) - (2)].l), new);
  }
    break;

  case 214:
#line 1594 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.i) = ',';
  }
    break;

  case 215:
#line 1599 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.i) = ';';
  }
    break;

  case 216:
#line 1607 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].expression));
  }
    break;

  case 217:
#line 1612 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].expression));
  }
    break;

  case 218:
#line 1622 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
      (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (3)].expression));
      (yyval.l) = lst_append((yyval.l), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 219:
#line 1628 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
      (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (3)].expression));
      (yyval.l) = lst_append((yyval.l), (yyvsp[(3) - (3)].expression));
    }
    break;

  case 220:
#line 1652 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].variable));
  }
    break;

  case 221:
#line 1657 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"
    {
    (yyval.l) = lst_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].variable));
  }
    break;


/* Line 1267 of yacc.c.  */
#line 4222 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
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


#line 1662 "/Volumes/Bigger/Users/maury/Desktop/RetroBASIC/src/parse.y"



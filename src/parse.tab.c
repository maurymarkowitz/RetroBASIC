
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parse.y"

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

 /************************************************************************/



/* Line 189 of yacc.c  */
#line 148 "parse.tab.c"

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
     MATFIL = 424
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 80 "parse.y"

  double d;
  int i;
  char *s;
  list_t *l;
  statement_t *statement;
  expression_t *expression;
  variable_reference_t *variable;



/* Line 214 of yacc.c  */
#line 365 "parse.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 377 "parse.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1932

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  187
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  231
/* YYNRULES -- Number of states.  */
#define YYNSTATES  363

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   424

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     170,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   182,     2,
     175,   176,   179,   177,   173,   178,     2,   183,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   171,   174,
     180,   172,   181,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   185,     2,   186,   184,     2,     2,     2,     2,     2,
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
     165,   166,   167,   168,   169
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    15,    19,    21,
      25,    28,    31,    32,    34,    36,    38,    40,    43,    48,
      53,    55,    57,    59,    61,    64,    69,    72,    75,    78,
      81,    84,    86,    89,    91,    98,   107,   110,   113,   116,
     121,   124,   127,   132,   135,   140,   145,   150,   153,   158,
     161,   163,   165,   170,   175,   180,   184,   186,   189,   194,
     196,   199,   205,   208,   211,   213,   216,   219,   222,   224,
     227,   230,   233,   235,   237,   240,   242,   245,   248,   251,
     254,   258,   263,   266,   268,   270,   273,   277,   282,   289,
     296,   303,   312,   319,   323,   327,   331,   336,   344,   349,
     354,   362,   367,   375,   383,   393,   401,   403,   405,   409,
     411,   413,   415,   419,   421,   423,   425,   427,   429,   431,
     433,   435,   439,   441,   443,   445,   447,   451,   453,   455,
     457,   459,   461,   463,   465,   467,   470,   472,   474,   476,
     478,   482,   487,   492,   499,   501,   506,   513,   522,   524,
     526,   528,   530,   532,   534,   536,   538,   540,   542,   544,
     546,   548,   550,   552,   554,   556,   558,   560,   562,   564,
     566,   568,   570,   572,   574,   576,   578,   580,   582,   584,
     586,   588,   590,   592,   594,   596,   598,   600,   602,   604,
     606,   608,   610,   612,   614,   616,   618,   620,   622,   624,
     626,   628,   630,   632,   634,   636,   638,   640,   642,   644,
     646,   648,   650,   654,   659,   661,   666,   671,   676,   684,
     685,   687,   690,   692,   695,   697,   699,   701,   705,   709,
     713,   715
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     188,     0,    -1,   189,    -1,   188,   170,   189,    -1,   188,
       1,   170,    -1,    -1,    -1,     4,   190,   191,    -1,   192,
      -1,   192,   171,   191,    -1,   191,    14,    -1,   191,    15,
      -1,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      54,   193,    -1,   137,   211,    44,   211,    -1,   138,   211,
      44,   211,    -1,    17,    -1,    18,    -1,    55,    -1,    56,
      -1,    19,   214,    -1,    20,   210,   172,   193,    -1,   136,
     216,    -1,   134,   216,    -1,   135,   216,    -1,   133,   216,
      -1,    21,   216,    -1,    22,    -1,   128,   193,    -1,    23,
      -1,    24,   211,   172,   193,    44,   193,    -1,    24,   211,
     172,   193,    44,   193,    41,   193,    -1,    25,   211,    -1,
      26,     4,    -1,    26,   193,    -1,    26,   193,    34,   214,
      -1,    27,     4,    -1,    27,   193,    -1,    27,   193,    34,
     214,    -1,    29,   212,    -1,    28,   193,    43,     4,    -1,
      28,   193,    27,     4,    -1,    28,   193,    43,   191,    -1,
     152,   211,    -1,    30,   211,   172,   193,    -1,    32,   216,
      -1,    32,    -1,    33,    -1,    35,   193,    27,   214,    -1,
      35,   193,    26,   214,    -1,    35,   128,    27,   214,    -1,
      57,    58,   193,    -1,    65,    -1,    65,   193,    -1,    60,
     193,   173,   193,    -1,    61,    -1,    36,   212,    -1,    36,
      45,   193,   174,   212,    -1,    37,   193,    -1,   129,   193,
      -1,    62,    -1,    62,   193,    -1,    62,    62,    -1,    38,
     216,    -1,    67,    -1,    67,   193,    -1,   127,    32,    -1,
     127,   193,    -1,   127,    -1,    39,    -1,    39,   193,    -1,
      42,    -1,    42,   193,    -1,   141,   193,    -1,    63,   193,
      -1,   122,   193,    -1,   143,   172,   193,    -1,    30,   143,
     172,   193,    -1,   126,   193,    -1,   126,    -1,    64,    -1,
      46,   214,    -1,   211,   172,   193,    -1,   153,   211,   172,
     211,    -1,   153,   211,   172,   175,   193,   176,    -1,   153,
     211,   172,   211,   177,   211,    -1,   153,   211,   172,   211,
     178,   211,    -1,   153,   211,   172,   175,   193,   176,   179,
     211,    -1,   153,   211,   172,   211,   179,   211,    -1,   153,
      36,   212,    -1,   153,    29,   212,    -1,   153,    38,   216,
      -1,   153,   211,   172,   160,    -1,   153,   211,   172,   160,
     175,   214,   176,    -1,   153,   211,   172,   164,    -1,   153,
     211,   172,   159,    -1,   153,   211,   172,   159,   175,   214,
     176,    -1,   153,   211,   172,   161,    -1,   153,   211,   172,
     161,   175,   214,   176,    -1,   153,   211,   172,   163,   175,
     211,   176,    -1,   153,   211,   172,   163,   175,   211,   176,
     173,   211,    -1,   153,   211,   172,   162,   175,   211,   176,
      -1,   194,    -1,   196,    -1,   194,   195,   196,    -1,   109,
      -1,   110,    -1,   198,    -1,   196,   197,   198,    -1,   172,
      -1,   180,    -1,   181,    -1,   115,    -1,   116,    -1,   117,
      -1,   118,    -1,   200,    -1,   198,   199,   200,    -1,   177,
      -1,   178,    -1,   182,    -1,   202,    -1,   200,   201,   202,
      -1,   179,    -1,   183,    -1,    83,    -1,    85,    -1,    86,
      -1,    87,    -1,   184,    -1,   204,    -1,   203,   204,    -1,
     178,    -1,   111,    -1,   209,    -1,   205,    -1,   205,   175,
     176,    -1,   205,   175,   193,   176,    -1,   206,   175,   193,
     176,    -1,   207,   175,   193,   173,   193,   176,    -1,   208,
      -1,   208,   175,   193,   176,    -1,   208,   175,   193,   173,
     193,   176,    -1,   208,   175,   193,   173,   193,   173,   193,
     176,    -1,   108,    -1,   120,    -1,    74,    -1,    75,    -1,
     142,    -1,   143,    -1,   131,    -1,   132,    -1,   164,    -1,
      68,    -1,   119,    -1,    90,    -1,   146,    -1,   149,    -1,
     104,    -1,    70,    -1,    88,    -1,    71,    -1,    77,    -1,
      78,    -1,   144,    -1,   147,    -1,    76,    -1,   140,    -1,
     101,    -1,   125,    -1,    72,    -1,   145,    -1,   148,    -1,
      59,    -1,    69,    -1,    89,    -1,   121,    -1,    73,    -1,
     102,    -1,   122,    -1,   103,    -1,   139,    -1,   124,    -1,
     130,    -1,    85,    -1,    83,    -1,    86,    -1,    87,    -1,
      98,    -1,   100,    -1,   141,    -1,   107,    -1,   123,    -1,
      99,    -1,   105,    -1,   106,    -1,    79,    -1,   150,    -1,
     151,    -1,   160,    -1,   161,    -1,   163,    -1,   162,    -1,
     159,    -1,     4,    -1,     3,    -1,   211,    -1,   210,    -1,
     175,   193,   176,    -1,     9,   175,   214,   176,    -1,     8,
      -1,     8,   175,   214,   176,    -1,     8,   185,   214,   186,
      -1,     8,   175,   215,   176,    -1,     8,   175,   214,   176,
     175,   215,   176,    -1,    -1,   193,    -1,   212,   193,    -1,
     213,    -1,   212,   213,    -1,   173,    -1,   174,    -1,   193,
      -1,   214,   173,   193,    -1,   193,   171,   193,    -1,   193,
      44,   193,    -1,   211,    -1,   216,   173,   211,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   254,   254,   256,   258,   264,   268,   268,   275,   280,
     285,   290,   299,   303,   310,   317,   324,   330,   336,   344,
     352,   358,   364,   370,   376,   383,   391,   399,   407,   415,
     423,   430,   436,   443,   449,   463,   476,   483,   503,   523,
     535,   555,   575,   587,   594,   617,   637,   646,   654,   675,
     682,   689,   696,   708,   720,   731,   738,   744,   751,   759,
     765,   773,   781,   788,   795,   802,   809,   817,   824,   830,
     837,   846,   853,   859,   865,   872,   878,   885,   892,   899,
     906,   913,   920,   927,   934,   940,   947,   969,   989,   997,
    1014,  1031,  1045,  1062,  1069,  1076,  1084,  1091,  1099,  1108,
    1115,  1123,  1130,  1138,  1146,  1156,  1168,  1171,  1173,  1183,
    1184,  1188,  1190,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1242,  1244,  1264,  1265,  1266,  1270,  1272,  1281,  1282,  1283,
    1284,  1285,  1286,  1287,  1290,  1292,  1301,  1302,  1306,  1309,
    1316,  1322,  1329,  1336,  1345,  1352,  1360,  1369,  1381,  1382,
    1383,  1384,  1385,  1386,  1387,  1388,  1389,  1394,  1395,  1396,
    1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,  1406,
    1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1429,  1430,
    1431,  1432,  1433,  1434,  1435,  1440,  1441,  1442,  1443,  1444,
    1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1460,  1517,
    1536,  1543,  1550,  1561,  1571,  1583,  1595,  1609,  1622,  1637,
    1641,  1650,  1659,  1667,  1677,  1682,  1690,  1695,  1705,  1711,
    1735,  1740
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
  "ROUND", "CINT", "CSNG", "CDBL", "MOD", "MOD_INT", "DIV", "MAX", "MIN",
  "COS", "SIN", "ATN", "ACS", "ASN", "TAN", "COSH", "SINH", "TANH", "ASC",
  "LEFT", "MID", "RIGHT", "LEN", "STR", "VAL", "CHR", "SEG", "SUBSTR",
  "INSTR", "INKEY", "AND", "OR", "NOT", "XOR", "EQV", "IMP", "CMP_LE",
  "CMP_GE", "CMP_NE", "CMP_HASH", "ADR", "FRE", "SPC", "TAB", "POS", "USR",
  "LIN", "TRAP", "RESUME", "ERROR", "RAISE", "ERR", "EL", "ER", "DEFSTR",
  "DEFINT", "DEFSNG", "DEFDBL", "CHANGE", "CONVERT", "UCASE", "LCASE",
  "STRNG", "TIME", "TIME_STR", "HEX", "OCT", "BIN", "HEXSTR", "OCTSTR",
  "BINSTR", "UBOUND", "LBOUND", "LABEL", "MAT", "MATPRINT", "MATINPUT",
  "MATREAD", "MATGET", "MATPUT", "MATZER", "MATCON", "MATIDN", "MATTRN",
  "MATINV", "MATDET", "MATADD", "MATSUB", "MATMUL", "MATSCA", "MATFIL",
  "'\\n'", "':'", "'='", "','", "';'", "'('", "')'", "'+'", "'-'", "'*'",
  "'<'", "'>'", "'&'", "'/'", "'^'", "'['", "']'", "$accept", "program",
  "line", "$@1", "statements", "statement", "expression", "expression0",
  "binary_op", "expression1", "comparison_op", "expression2", "e2op",
  "expression3", "term", "expression4", "unary_op", "function", "fn_0",
  "fn_1", "fn_2", "fn_x", "factor", "user_function", "variable",
  "printlist", "printsep", "exprlist", "slicelist", "varlist", 0
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
      10,    58,    61,    44,    59,    40,    41,    43,    45,    42,
      60,    62,    38,    47,    94,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   187,   188,   188,   188,   189,   190,   189,   191,   191,
     191,   191,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   193,   194,   194,   195,
     195,   196,   196,   197,   197,   197,   197,   197,   197,   197,
     198,   198,   199,   199,   199,   200,   200,   201,   201,   201,
     201,   201,   201,   201,   202,   202,   203,   203,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   207,   207,
     207,   207,   207,   207,   207,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     209,   209,   209,   210,   211,   211,   211,   211,   211,   212,
     212,   212,   212,   212,   213,   213,   214,   214,   215,   215,
     216,   216
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     0,     3,     1,     3,
       2,     2,     0,     1,     1,     1,     1,     2,     4,     4,
       1,     1,     1,     1,     2,     4,     2,     2,     2,     2,
       2,     1,     2,     1,     6,     8,     2,     2,     2,     4,
       2,     2,     4,     2,     4,     4,     4,     2,     4,     2,
       1,     1,     4,     4,     4,     3,     1,     2,     4,     1,
       2,     5,     2,     2,     1,     2,     2,     2,     1,     2,
       2,     2,     1,     1,     2,     1,     2,     2,     2,     2,
       3,     4,     2,     1,     1,     2,     3,     4,     6,     6,
       6,     8,     6,     3,     3,     3,     4,     7,     4,     4,
       7,     4,     7,     7,     9,     7,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       3,     4,     4,     6,     1,     4,     6,     8,     1,     1,
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
       5,     6,     0,     2,    12,     1,     0,     5,   214,    13,
      14,    15,    16,    20,    21,     0,     0,     0,    31,    33,
       0,     0,     0,     0,     0,   219,     0,    50,    51,     0,
     219,     0,     0,    73,    75,     0,     0,    22,    23,     0,
       0,    59,    64,     0,    84,    56,    68,     0,    83,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     0,     4,     3,     0,     0,   209,
     208,     0,   177,   157,   178,   163,   165,   174,   181,   150,
     151,   170,   166,   167,   200,   189,   188,   190,   191,   164,
     179,   159,   192,   197,   193,   172,   182,   184,   162,   198,
     199,   195,   148,   137,   158,   149,   180,   183,   196,   186,
     173,   187,   154,   155,   185,   171,   194,   152,   153,   168,
     175,   160,   169,   176,   161,   201,   202,   207,   203,   204,
     206,   205,   156,     0,   136,   226,   106,   107,   111,   120,
     125,     0,   134,   139,     0,     0,   144,   138,   211,   210,
      24,     0,   230,    30,     0,    36,   208,    38,   208,    41,
       0,   224,   225,   220,    43,   222,     0,     0,    49,     0,
       0,     0,    60,    62,    67,    74,    76,    85,    17,     0,
       0,    66,    65,    78,    57,    69,    79,    82,    70,    71,
      32,    63,    29,    27,    28,    26,     0,     0,    77,     0,
      47,   219,   219,     0,     0,    10,    11,    12,     0,   226,
       0,     0,     0,     0,     0,   109,   110,     0,   116,   117,
     118,   119,   113,   114,   115,     0,   122,   123,   124,     0,
     129,   130,   131,   132,   127,   128,   133,     0,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,   221,   223,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,    80,    94,    93,    95,     0,     9,    86,
       0,     0,   215,   217,   216,     0,   212,   108,   112,   121,
     126,   140,     0,     0,     0,     0,   227,    25,   231,     0,
      39,    42,    45,    44,    46,    81,    48,    54,    53,    52,
     219,    58,    18,    19,    99,    96,   101,     0,     0,    98,
       0,    87,   229,   228,     0,   213,   141,   142,     0,     0,
     145,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,    88,    89,    90,    92,   218,   143,     0,   146,
       0,   100,    97,   102,   105,   103,     0,     0,    35,     0,
      91,   147,   104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    62,    63,   135,   136,   217,   137,
     225,   138,   229,   139,   237,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   164,   165,   150,   211,   153
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
      10,  -196,     7,  -196,  1779,  -196,  -144,    10,  -156,  -196,
    -196,  -196,  -196,  -196,  -196,  1100,    31,    39,  -196,  -196,
      39,    39,  1225,  1350,  1100,   451,    -2,    39,  -196,   576,
     326,  1100,    39,  1100,  1100,  1100,  1100,  -196,  -196,    12,
    1100,  -196,   725,  1100,  -196,  1100,  1100,  1100,  1100,   850,
    1100,  1100,    39,    39,    39,    39,    39,    39,  1100,  -118,
      39,    33,    49,   -84,   -72,  -196,  -196,  1100,  1100,  -196,
    -196,   -95,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  1100,  -196,  -196,     3,   -57,   -80,   -41,
    -196,  1475,  -196,   -54,   -53,   -50,   -49,  -196,  -196,  -196,
     -66,   -45,  -196,   -44,   -42,  -196,    20,    94,    24,    97,
       0,  -196,  -196,  -196,   451,  -196,   -40,   -39,   -44,   107,
      93,  1100,   451,  -196,   -44,  -196,  -196,   -66,  -196,  1100,
     -38,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   -44,   -44,   -44,   -44,    95,    96,  -196,  1100,
    -196,   451,   451,    39,   -28,  -196,  -196,  1779,  1100,   -35,
    -158,   -30,   -91,  1100,   -27,  -196,  -196,  1100,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  1100,  -196,  -196,  -196,  1100,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  1100,  -196,   975,
    1100,  1100,  1100,  1100,  1100,    39,  1100,  1100,  1100,   133,
    1638,  -196,  -196,  1100,  1100,  1100,  1100,  1100,   -26,  -196,
    1100,    39,    39,  -196,   451,   451,   -44,    -6,    49,  -196,
    1100,  1100,   -25,  -196,  -196,   -98,  -196,   -57,   -80,   -41,
    -196,  -196,   -24,   -17,   -13,   -92,  -196,  -196,  -196,   101,
     -66,   -66,  -196,  -196,    49,  -196,  -196,   -66,   -66,   -66,
     451,  -196,  -196,  -196,   -12,   -11,   -10,    -9,    -8,  -196,
    1100,   -61,  -196,  -196,  1100,  -196,  -196,  -196,  1100,  1100,
    -196,  1100,   451,  1100,  1100,  1100,    39,    39,   -14,    39,
      39,    39,   -35,    -5,    -1,   -77,   106,   -68,   -67,   -62,
       2,     4,     5,  -196,  -196,  -196,  -196,  -196,  1100,  -196,
    1100,  -196,  -196,  -196,  -196,    -3,    39,     9,  -196,    39,
    -196,  -196,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   144,  -196,  -195,  -196,    43,  -196,  -196,   -43,
    -196,   -46,  -196,   -37,  -196,   -69,  -196,    42,  -196,  -196,
    -196,  -196,  -196,   170,    -4,   -29,  -161,   -31,  -127,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -41
static const yytype_int16 yytable[] =
{
      64,   172,     8,   252,   177,   168,     8,     5,     6,   270,
     174,   252,   268,   152,     1,   243,   154,   155,   272,    67,
     -37,   -37,   167,   152,   -40,   -40,    65,   249,   152,    68,
     192,   193,   194,   195,   -37,   -37,   210,   212,   -40,   -40,
      71,     8,   230,   250,   231,   232,   233,     8,   152,   152,
     152,   152,   196,   197,   199,   294,   200,   204,   218,   219,
     220,   221,   201,   205,   206,   157,   159,   160,   163,   202,
     179,   203,   170,   163,   173,   243,   175,   176,   315,   178,
     213,   319,   243,   180,   320,   182,   183,   207,   184,   185,
     186,   187,   189,   190,   191,   274,   348,   226,   227,   349,
     208,   198,   228,   252,   252,   243,   243,   243,   351,   352,
     209,   243,   215,   216,   353,   222,   329,   330,   331,   256,
     257,   239,   240,   223,   224,   241,   242,   244,   247,   245,
     246,   248,   253,   254,   255,   260,   271,   292,   234,   261,
     262,   166,   235,   236,   267,   321,   273,   350,   300,   276,
     314,    66,   316,   304,   305,   306,   307,   308,   309,   317,
     318,   252,   342,   323,   324,   325,   326,   327,   280,   310,
     359,   346,   264,   265,   277,   347,   214,     7,   354,   278,
     355,   266,   275,   238,   356,   361,   151,   333,     0,     0,
     -37,   -37,   279,     0,   -40,   -40,     0,     0,     0,   152,
       0,     0,     0,    64,     0,     0,     0,   251,     0,     0,
       0,     0,     0,     0,   258,   251,   290,   291,     0,     0,
       0,     0,   259,     0,   297,   298,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   288,   263,     0,   163,   163,    64,     0,     0,     0,
       0,   269,     0,     0,     0,     0,     0,   302,   303,     0,
       0,     0,     0,   311,     0,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,   283,   284,   285,   286,   287,     0,   289,
       0,     0,   337,   338,   339,     0,   295,   296,     0,     0,
       0,     0,     0,   301,     0,     0,     0,   251,   251,     0,
       0,     0,     0,   312,   313,     0,     0,     0,     0,     0,
       0,     0,   340,   341,     0,   343,   344,   345,     0,    69,
      70,     0,     0,     0,     8,    71,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,     0,     0,
       0,     0,   360,   328,     0,   362,     0,   332,     0,     0,
       0,   334,   335,     0,   336,   251,     0,     0,     0,     0,
       0,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,   357,     0,   358,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,    85,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,     0,     0,    69,    70,   111,   112,   113,     8,
      71,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,   161,
     162,   133,     0,     0,   134,     0,     0,     0,     0,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,     0,     0,    85,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
     104,   105,   106,   107,   108,   109,   110,     0,     0,    69,
      70,   111,   112,   113,     8,    71,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,     0,
     127,   128,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,   161,   162,   133,     0,     0,   134,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,     0,     0,    85,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,   104,   105,   106,   107,   108,
     109,   110,     0,     0,   169,     0,   111,   112,   113,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    69,    70,
       0,     0,     0,     8,    71,   127,   128,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,     0,     0,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,   181,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,    69,    70,   111,   112,   113,     8,    71,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,   188,     0,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,     0,     0,    69,    70,
     111,   112,   113,     8,    71,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   134,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,    69,    70,   111,   112,   113,     8,    71,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   281,     0,   134,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,     0,     0,    69,   156,
     111,   112,   113,     8,    71,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   134,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,    69,   158,   111,   112,   113,     8,    71,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,    72,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,     0,    85,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,   104,
     105,   106,   107,   108,   109,   110,     0,     0,    69,    70,
     111,   112,   113,     8,    71,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   134,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,    85,     0,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,   127,   128,   129,   130,   131,   132,
       0,     0,   293,     0,     0,     0,     8,     0,     0,     0,
     133,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,     0,    29,    30,    31,    32,    33,     0,     0,
      34,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,    36,    37,    38,    39,     0,     0,    40,    41,
      42,    43,    44,    45,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,    48,    49,    50,    51,     0,     0,
       0,    52,    53,    54,    55,    56,    57,     0,     0,    58,
       0,    59,     0,     0,     0,     0,     0,     8,     0,     0,
      60,    61,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,    27,    28,     0,    29,    30,    31,    32,    33,     0,
       0,    34,     0,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,    39,     0,     0,    40,
      41,    42,    43,    44,    45,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,    48,    49,    50,    51,     0,
       0,     0,    52,    53,    54,    55,    56,    57,     0,     0,
      58,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    61
};

static const yytype_int16 yycheck[] =
{
       4,    30,     8,   164,    35,    27,     8,     0,     1,    44,
      32,   172,   207,    17,     4,   173,    20,    21,   176,   175,
       0,     1,    26,    27,     0,     1,   170,    27,    32,   185,
      52,    53,    54,    55,    14,    15,    67,    68,    14,    15,
       9,     8,    83,    43,    85,    86,    87,     8,    52,    53,
      54,    55,    56,    57,   172,   250,    60,    61,   115,   116,
     117,   118,    29,    14,    15,    22,    23,    24,    25,    36,
      58,    38,    29,    30,    31,   173,    33,    34,   176,    36,
     175,   173,   173,    40,   176,    42,    43,   171,    45,    46,
      47,    48,    49,    50,    51,   186,   173,   177,   178,   176,
     172,    58,   182,   264,   265,   173,   173,   173,   176,   176,
      67,   173,   109,   110,   176,   172,   177,   178,   179,    26,
      27,   175,   175,   180,   181,   175,   175,   172,    34,   173,
     172,    34,   172,   172,    27,   173,   171,     4,   179,    44,
      44,   143,   183,   184,   172,    44,   176,    41,   174,   176,
     175,     7,   176,   159,   160,   161,   162,   163,   164,   176,
     173,   322,   176,   175,   175,   175,   175,   175,   237,   175,
     173,   176,   201,   202,   217,   176,   133,   170,   176,   225,
     176,   203,   213,   141,   179,   176,    16,   314,    -1,    -1,
     170,   171,   229,    -1,   170,   171,    -1,    -1,    -1,   203,
      -1,    -1,    -1,   207,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    -1,    -1,   171,   172,   247,   248,    -1,    -1,
      -1,    -1,   179,    -1,   255,   256,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   199,    -1,   201,   202,   250,    -1,    -1,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,   261,   262,    -1,
      -1,    -1,    -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,   240,   241,   242,   243,   244,    -1,   246,
      -1,    -1,   323,   324,   325,    -1,   253,   254,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,    -1,   264,   265,    -1,
      -1,    -1,    -1,   270,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   326,   327,    -1,   329,   330,   331,    -1,     3,
       4,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,   310,    -1,   359,    -1,   314,    -1,    -1,
      -1,   318,   319,    -1,   321,   322,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,   348,    -1,   350,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,     3,     4,   130,   131,   132,     8,
       9,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   173,
     174,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,    -1,    -1,     3,
       4,   130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   173,   174,   175,    -1,    -1,   178,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    -1,    -1,    -1,    83,
      -1,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,    -1,    -1,   128,    -1,   130,   131,   132,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,     3,     4,
      -1,    -1,    -1,     8,     9,   159,   160,   161,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   175,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,     3,     4,   130,   131,   132,     8,     9,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    32,    -1,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,     3,     4,
     130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,     3,     4,   130,   131,   132,     8,     9,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,   176,    -1,   178,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,     3,     4,
     130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,     3,     4,   130,   131,   132,     8,     9,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     175,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    -1,    83,    -1,    85,    86,    87,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,    -1,    -1,     3,     4,
     130,   131,   132,     8,     9,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,   161,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   175,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    -1,    83,    -1,
      85,    86,    87,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,   161,   162,   163,   164,
      -1,    -1,     4,    -1,    -1,    -1,     8,    -1,    -1,    -1,
     175,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    33,    -1,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    56,    57,    -1,    -1,    60,    61,
      62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,   128,   129,    -1,    -1,
      -1,   133,   134,   135,   136,   137,   138,    -1,    -1,   141,
      -1,   143,    -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,
     152,   153,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    33,    -1,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    56,    57,    -1,    -1,    60,
      61,    62,    63,    64,    65,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,   138,    -1,    -1,
     141,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,   153
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,   188,   189,   190,     0,     1,   170,     8,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    32,    33,    35,
      36,    37,    38,    39,    42,    46,    54,    55,    56,    57,
      60,    61,    62,    63,    64,    65,    67,   122,   126,   127,
     128,   129,   133,   134,   135,   136,   137,   138,   141,   143,
     152,   153,   191,   192,   211,   170,   189,   175,   185,     3,
       4,     9,    59,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    83,    85,    86,    87,    88,
      89,    90,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   111,   119,   120,   121,   122,   123,   124,
     125,   130,   131,   132,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   159,   160,   161,
     162,   163,   164,   175,   178,   193,   194,   196,   198,   200,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     214,   210,   211,   216,   211,   211,     4,   193,     4,   193,
     193,   173,   174,   193,   212,   213,   143,   211,   216,   128,
     193,    45,   212,   193,   216,   193,   193,   214,   193,    58,
     193,    62,   193,   193,   193,   193,   193,   193,    32,   193,
     193,   193,   216,   216,   216,   216,   211,   211,   193,   172,
     211,    29,    36,    38,   211,    14,    15,   171,   172,   193,
     214,   215,   214,   175,   193,   109,   110,   195,   115,   116,
     117,   118,   172,   180,   181,   197,   177,   178,   182,   199,
      83,    85,    86,    87,   179,   183,   184,   201,   204,   175,
     175,   175,   175,   173,   172,   173,   172,    34,    34,    27,
      43,   193,   213,   172,   172,    27,    26,    27,   193,   193,
     173,    44,    44,   193,   212,   212,   216,   172,   191,   193,
      44,   171,   176,   176,   186,   214,   176,   196,   198,   200,
     202,   176,   193,   193,   193,   193,   193,   193,   211,   193,
     214,   214,     4,     4,   191,   193,   193,   214,   214,   214,
     174,   193,   211,   211,   159,   160,   161,   162,   163,   164,
     175,   211,   193,   193,   175,   176,   176,   176,   173,   173,
     176,    44,   212,   175,   175,   175,   175,   175,   193,   177,
     178,   179,   193,   215,   193,   193,   193,   214,   214,   214,
     211,   211,   176,   211,   211,   211,   176,   176,   173,   176,
      41,   176,   176,   176,   176,   176,   179,   193,   193,   173,
     211,   176,   211
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 264 "parse.y"
    {
  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 268 "parse.y"
    { errline = (yyvsp[(1) - (1)].d); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 269 "parse.y"
    {
    interpreter_state.lines[(int)(yyvsp[(1) - (3)].d)] = (yyvsp[(3) - (3)].l);
  ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 276 "parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].statement));
  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 281 "parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].statement));
  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 286 "parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(1) - (2)].l), NULL);
  ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 291 "parse.y"
    {
    (yyval.l) = lst_prepend((yyvsp[(1) - (2)].l), NULL);
  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 299 "parse.y"
    {
    (yyval.statement) = NULL;
  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 304 "parse.y"
    {
    statement_t *new = make_statement(REM);
    new->parms.rem = yylval.s; // the string has been modified in scan to remove the REM
    (yyval.statement) = new;
  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 311 "parse.y"
    {
    statement_t *new = make_statement(QUOTEREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 318 "parse.y"
    {
    statement_t *new = make_statement(BANGREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 325 "parse.y"
    {
    statement_t *new = make_statement(BYE);
    (yyval.statement) = new;
  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 331 "parse.y"
    {
    statement_t *new = make_statement(CALL);
    (yyval.statement) = new;
  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 337 "parse.y"
    {
    statement_t *new = make_statement(CHANGE);
    new->parms.change.var1 = (yyvsp[(2) - (4)].variable);
    new->parms.change.var2 = (yyvsp[(4) - (4)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 345 "parse.y"
    {
    statement_t *new = make_statement(CONVERT);
    new->parms.change.var1 = (yyvsp[(2) - (4)].variable);
    new->parms.change.var2 = (yyvsp[(4) - (4)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 353 "parse.y"
    {
    statement_t *new = make_statement(CLEAR);
    (yyval.statement) = new;
  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 359 "parse.y"
    {
    statement_t *new = make_statement(CLEAR);
    (yyval.statement) = new;
  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 365 "parse.y"
    {
    statement_t *new = make_statement(CLS);
    (yyval.statement) = new;
  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 371 "parse.y"
    {
    statement_t *new = make_statement(CMD);
    (yyval.statement) = new;
  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 377 "parse.y"
    {
    statement_t *new = make_statement(DATA);
    new->parms.data = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 384 "parse.y"
    {
    statement_t *new = make_statement(DEF);
    new->parms.def.signature = (yyvsp[(2) - (4)].variable);
    new->parms.def.formula = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 392 "parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = DOUBLE;
    (yyval.statement) = new;
  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 400 "parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = INTEGER;
    (yyval.statement) = new;
  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 408 "parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = SINGLE;
    (yyval.statement) = new;
  ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 416 "parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = STRING;
    (yyval.statement) = new;
  ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 424 "parse.y"
    {
    statement_t *new = make_statement(DIM);
    new->parms.dim = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 431 "parse.y"
    {
    statement_t *new = make_statement(END);
    (yyval.statement) = new;
  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 437 "parse.y"
    {
    statement_t *new = make_statement(RAISE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 444 "parse.y"
    {
    statement_t *new = make_statement(EXIT);
    (yyval.statement) = new;
  ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 450 "parse.y"
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
  ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 464 "parse.y"
    {
    statement_t *new = make_statement(FOR);
    new->parms._for.variable = (yyvsp[(2) - (8)].variable);
    new->parms._for.begin = (yyvsp[(4) - (8)].expression);
    new->parms._for.end = (yyvsp[(6) - (8)].expression);
    new->parms._for.step = (yyvsp[(8) - (8)].expression);
    (yyval.statement) = new;
  
    /* static analyser - consider anything with a STEP special even if it is a 1 */
    for_loops_total++;
  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 477 "parse.y"
    {
    statement_t *new = make_statement(GET);
    new->parms.generic_variable = (yyvsp[(2) - (2)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 484 "parse.y"
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
  ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 504 "parse.y"
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
  ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 524 "parse.y"
    {
    statement_t *new = make_statement(OF);
    new->parms.on.type = GOSUB;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
      
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 536 "parse.y"
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
  ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 556 "parse.y"
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
  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 576 "parse.y"
    {
    statement_t *new = make_statement(OF);
    new->parms.on.type = GOTO;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
      
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 588 "parse.y"
    {
    statement_t *new = make_statement(INPUT);
    new->parms.input = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 595 "parse.y"
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
  ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 618 "parse.y"
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
  ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 638 "parse.y"
    {
    statement_t *new = make_statement(IF);
    new->parms._if.condition = (yyvsp[(2) - (4)].expression);
    new->parms._if.then_expression = (yyvsp[(4) - (4)].l);
    new->parms._if.then_linenumber = 0;
    (yyval.statement) = new;
  ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 647 "parse.y"
    {
    statement_t *new = make_statement(LABEL);
    new->parms.label.variable = (yyvsp[(2) - (2)].variable);
    new->parms.label.linenumber = errline;
    (yyval.statement) = new;
  ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 655 "parse.y"
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
  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 676 "parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 683 "parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = NULL;
    (yyval.statement) = new;
  ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 690 "parse.y"
    {
    statement_t *new = make_statement(NEW);
    new->parms.next = NULL;
    (yyval.statement) = new;
  ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 697 "parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = GOTO;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
      
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 709 "parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = GOSUB;
    new->parms.on.expression = (yyvsp[(2) - (4)].expression);
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
    
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 721 "parse.y"
    {
    statement_t *new = make_statement(ON);
    new->parms.on.type = TRAP;
    new->parms.on.numbers = (yyvsp[(4) - (4)].l);
    (yyval.statement) = new;
    
    linenum_constants_total += lst_length((yyvsp[(4) - (4)].l));
    linenum_on_totals++;
  ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 732 "parse.y"
    {
    statement_t *new = make_statement(OPTION);
    new->parms.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 739 "parse.y"
    {
    statement_t *new = make_statement(PAUSE);
    (yyval.statement) = new;
  ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 745 "parse.y"
    {
    statement_t *new = make_statement(PAUSE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 752 "parse.y"
    {
    statement_t *new = make_statement(POKE);
    new->parms.generic_parameter = (yyvsp[(2) - (4)].expression);
    new->parms.generic_parameter2 = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 760 "parse.y"
    {
    statement_t *new = make_statement(POP);
    (yyval.statement) = new;
  ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 766 "parse.y"
    {
    statement_t *new = make_statement(PRINT);
    new->parms.print.format = NULL;
    new->parms.print.item_list = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 774 "parse.y"
    {
    statement_t *new = make_statement(PRINT);
    new->parms.print.format = (yyvsp[(3) - (5)].expression);
    new->parms.print.item_list = (yyvsp[(5) - (5)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 782 "parse.y"
    {
    statement_t *new = make_statement(PUT);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 789 "parse.y"
    {
    statement_t *new = make_statement(RAISE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 796 "parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = NULL;
    (yyval.statement) = new;
  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 803 "parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 810 "parse.y"
    {
    // this handles RANDOMIZE TIMER because scan converts TIMER to RANDOMIZE
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = NULL;
    (yyval.statement) = new;
  ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 818 "parse.y"
    {
    statement_t *new = make_statement(READ);
    new->parms.read = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 825 "parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    (yyval.statement) = new;
  ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 831 "parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 838 "parse.y"
    {
    statement_t *new = make_statement(RESUME);
    expression_t *exp = make_expression(number);
    exp->parms.number = -1;
    new->parms.generic_parameter = exp;
    (yyval.statement) = new;
  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 847 "parse.y"
    {
    statement_t *new = make_statement(RESUME);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 854 "parse.y"
    {
    statement_t *new = make_statement(RESUME);
    (yyval.statement) = new;
  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 860 "parse.y"
    {
    statement_t *new = make_statement(RETURN);
    (yyval.statement) = new;
  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 866 "parse.y"
    {
    statement_t *new = make_statement(RETURN);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 873 "parse.y"
    {
    statement_t *new = make_statement(STOP);
    (yyval.statement) = new;
  ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 879 "parse.y"
    {
    statement_t *new = make_statement(STOP);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 886 "parse.y"
    {
    statement_t *new = make_statement(STRNG);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 893 "parse.y"
    {
    statement_t *new = make_statement(SYS);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 900 "parse.y"
    {
    statement_t *new = make_statement(TAB);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 907 "parse.y"
    {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 914 "parse.y"
    {
    statement_t *new = make_statement(TIME_STR);
    new->parms.generic_parameter = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 921 "parse.y"
    {
    statement_t *new = make_statement(TRAP);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 928 "parse.y"
    {
    statement_t *new = make_statement(TRAP);
    new->parms.generic_parameter = NULL;
    (yyval.statement) = new;
  ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 935 "parse.y"
    {
    statement_t *new = make_statement(VARLIST);
    (yyval.statement) = new;
  ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 941 "parse.y"
    {
    statement_t *new = make_statement(WAIT);
    (yyval.statement) = new;
  ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 948 "parse.y"
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
  ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 970 "parse.y"
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
  ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 990 "parse.y"
    {
    statement_t *new = make_statement(MAT);
    new->parms.mat.variable = (yyvsp[(2) - (6)].variable);
    new->parms.mat.expression = (yyvsp[(5) - (6)].expression);
    (yyval.statement) = new;
  ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 998 "parse.y"
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
  ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1015 "parse.y"
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
  ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1032 "parse.y"
    {
    statement_t *new = make_statement(MATSCA);
    new->parms.mat.variable = (yyvsp[(2) - (8)].variable);
    new->parms.mat.expression = (yyvsp[(5) - (8)].expression);
    new->parms.mat.variable3 = (yyvsp[(8) - (8)].variable);

    if (new->parms.mat.variable3->subscripts != NULL) {
      new->parms.mat.variable->subscripts = new->parms.mat.variable3->subscripts;
    }

    (yyval.statement) = new;
  ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1046 "parse.y"
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
  ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1063 "parse.y"
    {
    statement_t *new = make_statement(MATPRINT);
    new->parms.print.item_list = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1070 "parse.y"
    {
    statement_t *new = make_statement(MATINPUT);
    new->parms.input = (yyvsp[(3) - (3)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1077 "parse.y"
    {
    statement_t *new = make_statement(MATREAD);
    new->parms.read = (yyvsp[(3) - (3)].l);
    
    (yyval.statement) = new;
  ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1085 "parse.y"
    {
    statement_t *new = make_statement(MATCON);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1092 "parse.y"
    {
    statement_t *new = make_statement(MATCON);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 1100 "parse.y"
    {
    // there are two ways to get the DET, one is a normal function,
    // the other is the IBM version of INV
    statement_t *new = make_statement(MATDET);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 1109 "parse.y"
    {
    statement_t *new = make_statement(MATZER);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 1116 "parse.y"
    {
    statement_t *new = make_statement(MATZER);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 1124 "parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.mat.variable = (yyvsp[(2) - (4)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 1131 "parse.y"
    {
    statement_t *new = make_statement(MATIDN);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable->subscripts = (yyvsp[(6) - (7)].l);
    (yyval.statement) = new;
  ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 1139 "parse.y"
    {
    statement_t *new = make_statement(MATINV);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable2 = (yyvsp[(6) - (7)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 1147 "parse.y"
    {
    // this is the IBM 5100 version, which returns the determinant
    statement_t *new = make_statement(MATINV);
    new->parms.mat.variable = (yyvsp[(2) - (9)].variable);
    new->parms.mat.variable2 = (yyvsp[(6) - (9)].variable);
    new->parms.mat.variable3 = (yyvsp[(9) - (9)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 1157 "parse.y"
    {
    statement_t *new = make_statement(MATTRN);
    new->parms.mat.variable = (yyvsp[(2) - (7)].variable);
    new->parms.mat.variable2 = (yyvsp[(6) - (7)].variable);
    (yyval.statement) = new;
  ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 1174 "parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 1183 "parse.y"
    { (yyval.i) = AND; ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 1184 "parse.y"
    { (yyval.i) = OR;  ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 1191 "parse.y"
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
  ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 1232 "parse.y"
    { (yyval.i) = '='; ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 1233 "parse.y"
    { (yyval.i) = '<'; ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 1234 "parse.y"
    { (yyval.i) = '>'; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 1235 "parse.y"
    { (yyval.i) = CMP_LE; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 1236 "parse.y"
    { (yyval.i) = CMP_GE; ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 1237 "parse.y"
    { (yyval.i) = CMP_NE; ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 1238 "parse.y"
    { (yyval.i) = CMP_HASH; ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 1245 "parse.y"
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
  ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 1264 "parse.y"
    { (yyval.i) = '+'; ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 1265 "parse.y"
    { (yyval.i) = '-'; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 1266 "parse.y"
    { (yyval.i) = '&'; ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 1273 "parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
    new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
    new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 1281 "parse.y"
    { (yyval.i) = '*'; ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 1282 "parse.y"
    { (yyval.i) = '/'; ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 1283 "parse.y"
    { (yyval.i) = MOD; ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 1284 "parse.y"
    { (yyval.i) = DIV; ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 1285 "parse.y"
    { (yyval.i) = MAX; ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 1286 "parse.y"
    { (yyval.i) = MIN; ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 1287 "parse.y"
    { (yyval.i) = '^'; ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 1293 "parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (2)].i));
    new->parms.op.p[0] = (yyvsp[(2) - (2)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 1301 "parse.y"
    { (yyval.i) = '-'; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 1302 "parse.y"
    { (yyval.i) = NOT; ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 1310 "parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (1)].i));
    (yyval.expression) = new;
  ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 1317 "parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (3)].i));
    (yyval.expression) = new;
  ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 1323 "parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 1330 "parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 1337 "parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 1346 "parse.y"
    {
    expression_t *new = make_operator(0, (yyvsp[(1) - (1)].i));
    (yyval.expression) = new;
  ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 1353 "parse.y"
    {
    expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 1361 "parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 1370 "parse.y"
    {
    expression_t *new = make_operator(3, (yyvsp[(1) - (8)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (8)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (8)].expression);
    new->parms.op.p[2] = (yyvsp[(7) - (8)].expression);
    (yyval.expression) = new;
  ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 1381 "parse.y"
    { (yyval.i) = INKEY; ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 1382 "parse.y"
    { (yyval.i) = FRE; ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 1383 "parse.y"
    { (yyval.i) = PI; ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 1384 "parse.y"
    { (yyval.i) = RND; ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 1385 "parse.y"
    { (yyval.i) = TIME; ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 1386 "parse.y"
    { (yyval.i) = TIME_STR; ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 1387 "parse.y"
    { (yyval.i) = EL; ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 1388 "parse.y"
    { (yyval.i) = ER; ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 1389 "parse.y"
    { (yyval.i) = MATDET; ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1394 "parse.y"
    { (yyval.i) =  ABS; ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1395 "parse.y"
    { (yyval.i) = ADR; ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1396 "parse.y"
    { (yyval.i) = ATN; ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1397 "parse.y"
    { (yyval.i) = BIN; ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 1398 "parse.y"
    { (yyval.i) = BINSTR; ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 1399 "parse.y"
    { (yyval.i) = CHR; ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1400 "parse.y"
    { (yyval.i) = CLOG;;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1401 "parse.y"
    { (yyval.i) = COS; ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1402 "parse.y"
    { (yyval.i) = EXP; ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1403 "parse.y"
    { (yyval.i) = FIX; ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1404 "parse.y"
    { (yyval.i) = FRAC; ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1405 "parse.y"
    { (yyval.i) = HEX; ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1406 "parse.y"
    { (yyval.i) = HEXSTR; ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1407 "parse.y"
    { (yyval.i) = INT; ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1408 "parse.y"
    { (yyval.i) = LCASE; ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1409 "parse.y"
    { (yyval.i) = LEN; ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1410 "parse.y"
    { (yyval.i) = LIN; ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1411 "parse.y"
    { (yyval.i) = LOG; ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1412 "parse.y"
    { (yyval.i) = OCT; ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1413 "parse.y"
    { (yyval.i) = OCTSTR; ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1414 "parse.y"
    { (yyval.i) = PEEK;;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1415 "parse.y"
    { (yyval.i) = SGN; ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1416 "parse.y"
    { (yyval.i) = SIN; ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1417 "parse.y"
    { (yyval.i) = SPC; ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1418 "parse.y"
    { (yyval.i) = SQR; ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1419 "parse.y"
    { (yyval.i) = STR; ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1420 "parse.y"
    { (yyval.i) = TAB; ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1421 "parse.y"
    { (yyval.i) = VAL; ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1422 "parse.y"
    { (yyval.i) = UCASE; ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1423 "parse.y"
    { (yyval.i) = USR; ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1424 "parse.y"
    { (yyval.i) = ERR; ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1429 "parse.y"
    { (yyval.i) = DIV; ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1430 "parse.y"
    { (yyval.i) = MOD; ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1431 "parse.y"
    { (yyval.i) = MAX; ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1432 "parse.y"
    { (yyval.i) = MIN; ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1433 "parse.y"
    { (yyval.i) = LEFT; ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1434 "parse.y"
    { (yyval.i) = RIGHT; ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1435 "parse.y"
    { (yyval.i) = STRNG; ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1440 "parse.y"
    { (yyval.i) = INSTR; ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1441 "parse.y"
    { (yyval.i) = POS; ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1442 "parse.y"
    { (yyval.i) = MID; ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1443 "parse.y"
    { (yyval.i) = SEG; ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 1444 "parse.y"
    { (yyval.i) = SUBSTR; ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 1445 "parse.y"
    { (yyval.i) = ROUND; ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 1446 "parse.y"
    { (yyval.i) = UBOUND; ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 1447 "parse.y"
    { (yyval.i) = LBOUND; ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1448 "parse.y"
    { (yyval.i) = MATCON; ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1449 "parse.y"
    { (yyval.i) = MATIDN; ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 1450 "parse.y"
    { (yyval.i) = MATINV; ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 1451 "parse.y"
    { (yyval.i) = MATTRN; ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1452 "parse.y"
    { (yyval.i) = MATZER; ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1461 "parse.y"
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
  ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1518 "parse.y"
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
  ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1537 "parse.y"
    {
    expression_t *new = make_expression(variable);
    new->parms.variable = (yyvsp[(1) - (1)].variable);
    (yyval.expression) = new;
  ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1544 "parse.y"
    {
    expression_t *new = make_expression(fn);
    new->parms.variable = (yyvsp[(1) - (1)].variable); // use the variable slot here, it has the same signature
    (yyval.expression) = new;
  ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1551 "parse.y"
    {
    (yyval.expression) = (yyvsp[(2) - (3)].expression);
  ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1562 "parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;
    // do NOT insert it now, the variables are private and will be set up during the DEF
  ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1572 "parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (1)].s);
    new->subscripts = NULL;
    new->slicing = NULL;
    (yyval.variable) = new;
    
    /* add it to the interpreter's variable list for the analyizer*/
    insert_variable(new);
  ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1584 "parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    new->slicing = NULL;
    (yyval.variable) = new;
    
    /* this may result in errors about array bounds if you OPTION BASE after the DIM */
    insert_variable(new);
  ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1596 "parse.y"
    {
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    new->slicing = NULL;
    (yyval.variable) = new;
    
    // square brackets tell us we are in the HP dialect, which means...
    string_slicing = true;
    
    insert_variable(new);
  ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1610 "parse.y"
    {
    /* this is the ANSI-style slicing command */
    /* NOTE: this should only ever occur in non-HP dialects, so the []'s would never appear */
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = NULL;
    new->slicing = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;
    
    insert_variable(new);
  ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1623 "parse.y"
    {
    /* and this is ANSI slicing of an entry in a string array */
    variable_reference_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (7)].s);
    new->subscripts = (yyvsp[(3) - (7)].l);
    new->slicing = (yyvsp[(6) - (7)].l);
    (yyval.variable) = new;
    
    insert_variable(new);
  ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 1637 "parse.y"
    {
    (yyval.l) = NULL;
  ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 1642 "parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(1) - (1)].expression);
    new->separator = 0;
    (yyval.l) = lst_append(NULL, new);
  ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 1651 "parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(2) - (2)].expression);
    new->separator = 0;
    (yyval.l) = lst_append((yyvsp[(1) - (2)].l), new);
  ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 1660 "parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(1) - (1)].i);
    (yyval.l) = lst_append(NULL, new);
  ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1668 "parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(2) - (2)].i);
    (yyval.l) = lst_append((yyvsp[(1) - (2)].l), new);
  ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1678 "parse.y"
    {
    (yyval.i) = ',';
  ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1683 "parse.y"
    {
    (yyval.i) = ';';
  ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1691 "parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].expression));
  ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1696 "parse.y"
    {
    (yyval.l) = lst_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].expression));
  ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1706 "parse.y"
    {
      (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (3)].expression));
      (yyval.l) = lst_append((yyval.l), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1712 "parse.y"
    {
      (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (3)].expression));
      (yyval.l) = lst_append((yyval.l), (yyvsp[(3) - (3)].expression));
    ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1736 "parse.y"
    {
    (yyval.l) = lst_prepend(NULL, (yyvsp[(1) - (1)].variable));
  ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1741 "parse.y"
    {
    (yyval.l) = lst_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].variable));
  ;}
    break;



/* Line 1455 of yacc.c  */
#line 4687 "parse.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 1746 "parse.y"



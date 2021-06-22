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
     NUMBER = 258,
     STRING = 259,
     VARIABLE_NAME = 260,
     FUNCTION_NAME = 261,
     BREAK = 262,
     BYE = 263,
     CALL = 264,
     CLEAR = 265,
     CLS = 266,
     DATA = 267,
     DEF = 268,
     DIM = 269,
     END = 270,
     FOR = 271,
     GET = 272,
     GOSUB = 273,
     GOTO = 274,
     IF = 275,
     INPUT = 276,
     LET = 277,
     LIST = 278,
     NEXT = 279,
     NEW = 280,
     ON = 281,
     PEEK = 282,
     POKE = 283,
     PRINT = 284,
     PUT = 285,
     READ = 286,
     REM = 287,
     RESTORE = 288,
     RETURN = 289,
     RUN = 290,
     STEP = 291,
     STOP = 292,
     SYS = 293,
     THEN = 294,
     TO = 295,
     USING = 296,
     VARLIST = 297,
     WAIT = 298,
     OPEN = 299,
     CLOSE = 300,
     STATUS = 301,
     PRINT_FILE = 302,
     INPUT_FILE = 303,
     GET_FILE = 304,
     PUT_FILE = 305,
     _ABS = 306,
     SGN = 307,
     ATN = 308,
     COS = 309,
     SIN = 310,
     TAN = 311,
     CLOG = 312,
     EXP = 313,
     LOG = 314,
     SQR = 315,
     RND = 316,
     INT = 317,
     FIX = 318,
     CINT = 319,
     CSNG = 320,
     CDBL = 321,
     ASC = 322,
     LEFT = 323,
     MID = 324,
     RIGHT = 325,
     LEN = 326,
     STR = 327,
     VAL = 328,
     CHR = 329,
     AND = 330,
     OR = 331,
     NOT = 332,
     XOR = 333,
     CMP_LE = 334,
     CMP_GE = 335,
     CMP_NE = 336,
     CMP_HASH = 337,
     FRE = 338,
     SPC = 339,
     TAB = 340,
     POS = 341,
     USR = 342
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
#define DATA 267
#define DEF 268
#define DIM 269
#define END 270
#define FOR 271
#define GET 272
#define GOSUB 273
#define GOTO 274
#define IF 275
#define INPUT 276
#define LET 277
#define LIST 278
#define NEXT 279
#define NEW 280
#define ON 281
#define PEEK 282
#define POKE 283
#define PRINT 284
#define PUT 285
#define READ 286
#define REM 287
#define RESTORE 288
#define RETURN 289
#define RUN 290
#define STEP 291
#define STOP 292
#define SYS 293
#define THEN 294
#define TO 295
#define USING 296
#define VARLIST 297
#define WAIT 298
#define OPEN 299
#define CLOSE 300
#define STATUS 301
#define PRINT_FILE 302
#define INPUT_FILE 303
#define GET_FILE 304
#define PUT_FILE 305
#define _ABS 306
#define SGN 307
#define ATN 308
#define COS 309
#define SIN 310
#define TAN 311
#define CLOG 312
#define EXP 313
#define LOG 314
#define SQR 315
#define RND 316
#define INT 317
#define FIX 318
#define CINT 319
#define CSNG 320
#define CDBL 321
#define ASC 322
#define LEFT 323
#define MID 324
#define RIGHT 325
#define LEN 326
#define STR 327
#define VAL 328
#define CHR 329
#define AND 330
#define OR 331
#define NOT 332
#define XOR 333
#define CMP_LE 334
#define CMP_GE 335
#define CMP_NE 336
#define CMP_HASH 337
#define FRE 338
#define SPC 339
#define TAB 340
#define POS 341
#define USR 342




/* Copy the first part of user declarations.  */
#line 1 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"

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

#include "retrobasic.h"

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
  new->parms.op.o = o;
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
/* Line 193 of yacc.c.  */
#line 346 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 359 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"

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
#define YYLAST   429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      88,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     100,   101,    97,    95,    91,    96,     2,    98,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,    92,
      93,    90,    94,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    99,     2,     2,     2,     2,     2,
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
      85,    86,    87
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    15,    19,    21,
      25,    26,    28,    30,    32,    34,    37,    42,    45,    47,
      54,    63,    66,    69,    72,    77,    82,    87,    90,    92,
      97,   102,   107,   110,   116,   119,   121,   123,   125,   127,
     130,   132,   135,   139,   141,   143,   147,   149,   151,   153,
     157,   159,   161,   163,   165,   167,   169,   171,   173,   177,
     179,   181,   183,   187,   189,   191,   193,   195,   198,   200,
     202,   204,   209,   216,   223,   232,   234,   236,   238,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   258,   260,
     262,   264,   266,   268,   270,   272,   274,   276,   278,   280,
     282,   284,   288,   293,   295,   300,   301,   303,   306,   310,
     313,   315,   317,   319,   323,   325
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     103,     0,    -1,   104,    -1,   103,    88,   104,    -1,   103,
       1,    88,    -1,    -1,    -1,     3,   105,   106,    -1,   107,
      -1,   107,    89,   106,    -1,    -1,     7,    -1,     8,    -1,
       9,    -1,    11,    -1,    12,   128,    -1,    13,   124,    90,
     108,    -1,    14,   129,    -1,    15,    -1,    16,   125,    90,
     108,    40,   108,    -1,    16,   125,    90,   108,    40,   108,
      36,   108,    -1,    18,   108,    -1,    19,   108,    -1,    21,
     126,    -1,    20,   108,    39,     3,    -1,    20,   108,    39,
     106,    -1,    22,   125,    90,   108,    -1,    24,   125,    -1,
      24,    -1,    26,   108,    19,   128,    -1,    26,   108,    18,
     128,    -1,    28,   108,    91,   108,    -1,    29,   126,    -1,
      29,    41,   108,    92,   126,    -1,    31,   129,    -1,    32,
      -1,    33,    -1,    34,    -1,    37,    -1,    38,   108,    -1,
      42,    -1,    43,   128,    -1,   125,    90,   108,    -1,   109,
      -1,   111,    -1,   109,   110,   111,    -1,    75,    -1,    76,
      -1,   113,    -1,   111,   112,   113,    -1,    90,    -1,    93,
      -1,    94,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,   115,    -1,   113,   114,   115,    -1,    95,    -1,    96,
      -1,   117,    -1,   115,   116,   117,    -1,    97,    -1,    98,
      -1,    99,    -1,   119,    -1,   118,   119,    -1,    96,    -1,
      77,    -1,   123,    -1,   120,   100,   108,   101,    -1,   121,
     100,   108,    91,   108,   101,    -1,   122,   100,   108,    91,
     108,   101,    -1,   122,   100,   108,    91,   108,    91,   108,
     101,    -1,    51,    -1,    53,    -1,    74,    -1,    57,    -1,
      54,    -1,    58,    -1,    83,    -1,    62,    -1,    71,    -1,
      72,    -1,    59,    -1,    61,    -1,    52,    -1,    55,    -1,
      84,    -1,    60,    -1,    85,    -1,    73,    -1,    87,    -1,
      68,    -1,    70,    -1,    69,    -1,     3,    -1,     4,    -1,
     125,    -1,   124,    -1,   100,   108,   101,    -1,     6,   100,
     128,   101,    -1,     5,    -1,     5,   100,   128,   101,    -1,
      -1,   108,    -1,   108,   126,    -1,   108,   127,   126,    -1,
     127,   126,    -1,    91,    -1,    92,    -1,   108,    -1,   128,
      91,   108,    -1,   125,    -1,   129,    91,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   162,   162,   164,   166,   171,   175,   175,   182,   187,
     196,   200,   206,   212,   218,   225,   232,   240,   247,   253,
     263,   273,   291,   311,   318,   341,   350,   358,   365,   372,
     385,   397,   404,   412,   420,   427,   434,   440,   446,   452,
     458,   464,   470,   482,   485,   487,   497,   498,   502,   504,
     514,   515,   516,   517,   518,   519,   520,   524,   526,   535,
     536,   539,   541,   550,   551,   552,   555,   557,   566,   567,
     571,   573,   580,   589,   598,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   633,   634,   639,   646,   712,   736,
     743,   750,   760,   770,   778,   788,   792,   801,   809,   818,
     828,   833,   841,   846,   869,   874
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "STRING", "VARIABLE_NAME",
  "FUNCTION_NAME", "BREAK", "BYE", "CALL", "CLEAR", "CLS", "DATA", "DEF",
  "DIM", "END", "FOR", "GET", "GOSUB", "GOTO", "IF", "INPUT", "LET",
  "LIST", "NEXT", "NEW", "ON", "PEEK", "POKE", "PRINT", "PUT", "READ",
  "REM", "RESTORE", "RETURN", "RUN", "STEP", "STOP", "SYS", "THEN", "TO",
  "USING", "VARLIST", "WAIT", "OPEN", "CLOSE", "STATUS", "PRINT_FILE",
  "INPUT_FILE", "GET_FILE", "PUT_FILE", "_ABS", "SGN", "ATN", "COS", "SIN",
  "TAN", "CLOG", "EXP", "LOG", "SQR", "RND", "INT", "FIX", "CINT", "CSNG",
  "CDBL", "ASC", "LEFT", "MID", "RIGHT", "LEN", "STR", "VAL", "CHR", "AND",
  "OR", "NOT", "XOR", "CMP_LE", "CMP_GE", "CMP_NE", "CMP_HASH", "FRE",
  "SPC", "TAB", "POS", "USR", "'\\n'", "':'", "'='", "','", "';'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'^'", "'('", "')'", "$accept",
  "program", "line", "@1", "statements", "statement", "expression",
  "expression0", "binary_op", "expression1", "comparison_op",
  "expression2", "e2op", "expression3", "term", "expression4", "unary_op",
  "function", "fn_1", "fn_2", "fn_x", "factor", "user_function",
  "variable", "printlist", "printsep", "exprlist", "varlist", 0
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
     335,   336,   337,   338,   339,   340,   341,   342,    10,    58,
      61,    44,    59,    60,    62,    43,    45,    42,    47,    94,
      40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   103,   104,   105,   104,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   109,   109,   110,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   117,   117,   118,   118,
     119,   119,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   122,   123,   123,   123,
     123,   123,   124,   125,   125,   126,   126,   126,   126,   126,
     127,   127,   128,   128,   129,   129
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     0,     3,     1,     3,
       0,     1,     1,     1,     1,     2,     4,     2,     1,     6,
       8,     2,     2,     2,     4,     4,     4,     2,     1,     4,
       4,     4,     2,     5,     2,     1,     1,     1,     1,     2,
       1,     2,     3,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     4,     6,     6,     8,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     1,     4,     0,     1,     2,     3,     2,
       1,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     6,     0,     2,    10,     1,     0,     5,   103,    11,
      12,    13,    14,     0,     0,     0,    18,     0,     0,     0,
       0,   105,     0,    28,     0,     0,   105,     0,    35,    36,
      37,    38,     0,    40,     0,     7,     8,     0,     4,     3,
       0,    97,    98,     0,    75,    87,    76,    79,    88,    78,
      80,    85,    90,    86,    82,    94,    96,    95,    83,    84,
      92,    77,    69,    81,    89,    91,    93,    68,     0,   112,
      43,    44,    48,    57,    61,     0,    66,     0,     0,     0,
      70,   100,    99,    15,     0,   114,    17,     0,    21,    22,
       0,   110,   111,   105,    23,   105,     0,    27,     0,     0,
       0,    32,    34,    39,    41,    10,     0,     0,     0,     0,
      46,    47,     0,    53,    54,    55,    56,    50,    51,    52,
       0,    59,    60,     0,    63,    64,    65,     0,    67,     0,
       0,     0,     0,     0,     0,     0,    10,   107,   105,   109,
       0,     0,     0,     0,     0,     9,    42,   104,     0,   101,
      45,    49,    58,    62,     0,     0,     0,   113,    16,   115,
       0,    24,    25,   108,    26,    30,    29,    31,   105,   102,
      71,     0,     0,     0,    33,     0,     0,    19,    72,     0,
      73,     0,     0,    20,    74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    35,    36,    69,    70,   112,    71,
     120,    72,   123,    73,   127,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    94,    95,    83,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
      28,   -93,     9,   -93,   386,   -93,   -51,    28,   -67,   -93,
     -93,   -93,   -93,   243,    46,    49,   -93,    49,   243,   243,
     243,   183,    49,    49,   243,   243,   123,    49,   -93,   -93,
     -93,   -93,   243,   -93,   243,   -93,   -32,   -16,   -93,   -93,
     243,   -93,   -93,   -28,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   243,   -93,
     -55,    -1,   -69,   -31,   -93,   303,   -93,   -24,   -17,   -14,
     -93,   -93,   -93,    -7,    -3,   -93,     0,     4,   -93,   -93,
      51,   -93,   -93,   183,   -93,   183,     5,   -93,    44,     7,
     243,   -93,     0,   -93,    -7,   386,   243,   -79,   243,    -5,
     -93,   -93,   243,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     243,   -93,   -93,   243,   -93,   -93,   -93,   243,   -93,   243,
     243,   243,   243,   243,    49,   243,    27,   -93,   183,   -93,
     243,   243,   243,   243,     8,   -93,   -93,   -93,   -76,   -93,
      -1,   -69,   -31,   -93,    -2,    10,    11,   -93,   -93,   -93,
      63,   -93,   -93,   -93,   -93,    -7,    -7,   -93,   183,   -93,
     -93,   243,   243,   243,   -93,     3,   -72,    69,   -93,   243,
     -93,   243,     6,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   101,   -93,   -92,   -93,   -18,   -93,   -93,    12,
     -93,   -11,   -93,   -13,   -93,    -6,   -93,    48,   -93,   -93,
     -93,   -93,   116,     1,   -22,    38,   -23,   105
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      88,    89,    90,    93,   101,    37,    98,    99,    93,     5,
       6,   104,   132,   145,   103,   132,    85,   107,    87,   179,
     110,   111,   147,    96,    97,   169,   121,   122,    85,   180,
     161,     1,     8,    40,     9,    10,    11,    38,    12,    13,
      14,    15,    16,    17,   162,    18,    19,    20,    21,    22,
     109,    23,    43,    24,     8,    25,    26,   105,    27,    28,
      29,    30,   141,   142,    31,    32,   124,   125,   126,    33,
      34,   137,   108,   139,   106,    93,   129,    93,   113,   114,
     115,   116,   144,   130,   132,   148,   131,   133,   146,   117,
     136,   134,   118,   119,   135,   140,   149,     7,   143,   170,
     168,   171,   172,   173,   178,   181,    37,   184,    39,   151,
     152,   154,   155,   156,   157,   158,   163,   160,   165,   166,
      93,   153,   164,   128,   150,   167,    41,    42,     8,    43,
      84,   138,   102,     0,     0,   159,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,   174,     0,     0,     0,
      93,     0,     0,   175,   176,   177,     0,     0,     0,     0,
       0,   182,     0,   183,   100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    41,    42,     8,    43,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,     0,     0,     0,     0,     0,    63,    64,    65,     0,
      66,     0,     0,     0,    91,    92,     0,     0,     0,    67,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    41,    42,     8,    43,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,     0,     0,     0,     0,     0,    63,    64,    65,     0,
      66,     0,     0,     0,    91,    92,     0,     0,     0,    67,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    41,    42,     8,    43,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
      62,     0,     0,     0,     0,     0,    63,    64,    65,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,     0,
      66,     8,     0,     9,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    68,    18,    19,    20,    21,    22,     0,
      23,     0,    24,     0,    25,    26,     0,    27,    28,    29,
      30,     0,     0,    31,    32,     0,     0,     0,    33,    34
};

static const yytype_int16 yycheck[] =
{
      18,    19,    20,    21,    26,     4,    24,    25,    26,     0,
       1,    34,    91,   105,    32,    91,    15,    40,    17,    91,
      75,    76,   101,    22,    23,   101,    95,    96,    27,   101,
       3,     3,     5,   100,     7,     8,     9,    88,    11,    12,
      13,    14,    15,    16,   136,    18,    19,    20,    21,    22,
      68,    24,     6,    26,     5,    28,    29,    89,    31,    32,
      33,    34,    18,    19,    37,    38,    97,    98,    99,    42,
      43,    93,   100,    95,    90,    93,   100,    95,    79,    80,
      81,    82,   100,   100,    91,   108,   100,    90,   106,    90,
      39,    91,    93,    94,    90,    90,   101,    88,    91,   101,
      92,    91,    91,    40,   101,    36,   105,   101,     7,   120,
     123,   129,   130,   131,   132,   133,   138,   135,   141,   142,
     138,   127,   140,    75,   112,   143,     3,     4,     5,     6,
      14,    93,    27,    -1,    -1,   134,    -1,   136,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,    -1,
     168,    -1,    -1,   171,   172,   173,    -1,    -1,    -1,    -1,
      -1,   179,    -1,   181,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,     3,     4,     5,     6,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    91,    92,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,     3,     4,     5,     6,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    91,    92,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,     3,     4,     5,     6,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,
      87,     5,    -1,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    16,   100,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    -1,    28,    29,    -1,    31,    32,    33,
      34,    -1,    -1,    37,    38,    -1,    -1,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   103,   104,   105,     0,     1,    88,     5,     7,
       8,     9,    11,    12,    13,    14,    15,    16,    18,    19,
      20,    21,    22,    24,    26,    28,    29,    31,    32,    33,
      34,    37,    38,    42,    43,   106,   107,   125,    88,   104,
     100,     3,     4,     6,    51,    52,    53,    54,    55,    57,
      58,    59,    60,    61,    62,    68,    69,    70,    71,    72,
      73,    74,    77,    83,    84,    85,    87,    96,   100,   108,
     109,   111,   113,   115,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   128,   124,   125,   129,   125,   108,   108,
     108,    91,    92,   108,   126,   127,   125,   125,   108,   108,
      41,   126,   129,   108,   128,    89,    90,   128,   100,   108,
      75,    76,   110,    79,    80,    81,    82,    90,    93,    94,
     112,    95,    96,   114,    97,    98,    99,   116,   119,   100,
     100,   100,    91,    90,    91,    90,    39,   126,   127,   126,
      90,    18,    19,    91,   108,   106,   108,   101,   128,   101,
     111,   113,   115,   117,   108,   108,   108,   108,   108,   125,
     108,     3,   106,   126,   108,   128,   128,   108,    92,   101,
     101,    91,    91,    40,   126,   108,   108,   108,   101,    91,
     101,    36,   108,   108,   101
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
#line 171 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	}
    break;

  case 6:
#line 175 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { errline = (yyvsp[(1) - (1)].d); }
    break;

  case 7:
#line 176 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  interpreter_state.lines[(int)(yyvsp[(1) - (3)].d)] = (yyvsp[(3) - (3)].l);
	}
    break;

  case 8:
#line 183 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].statement));
	}
    break;

  case 9:
#line 188 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend((yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].statement));
    }
    break;

  case 10:
#line 196 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.statement) = NULL;
	}
    break;

  case 11:
#line 201 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      statement_t *new = make_statement(BREAK);
      (yyval.statement) = new;
    }
    break;

  case 12:
#line 207 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(BYE);
	  (yyval.statement) = new;
	}
    break;

  case 13:
#line 213 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      statement_t *new = make_statement(CALL);
      (yyval.statement) = new;
    }
    break;

  case 14:
#line 219 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      statement_t *new = make_statement(CLS);
      (yyval.statement) = new;
    }
    break;

  case 15:
#line 226 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(DATA);
	  new->parms.data = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 16:
#line 233 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(DEF);
      new->parms.def.function = (yyvsp[(2) - (4)].variable);
      new->parms.def.expression = (yyvsp[(4) - (4)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 17:
#line 241 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(DIM);
	  new->parms.dim = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 18:
#line 248 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(END);
	  (yyval.statement) = new;
	}
    break;

  case 19:
#line 254 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(FOR);
	  new->parms._for.variable = (yyvsp[(2) - (6)].variable);
	  new->parms._for.begin = (yyvsp[(4) - (6)].expression);
	  new->parms._for.end = (yyvsp[(6) - (6)].expression);
	  new->parms._for.step = NULL;
	  (yyval.statement) = new;
	}
    break;

  case 20:
#line 264 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(FOR);
	  new->parms._for.variable = (yyvsp[(2) - (8)].variable);
	  new->parms._for.begin = (yyvsp[(4) - (8)].expression);
	  new->parms._for.end = (yyvsp[(6) - (8)].expression);
	  new->parms._for.step = (yyvsp[(8) - (8)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 21:
#line 274 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(GOSUB);
	  new->parms.gosub = (yyvsp[(2) - (2)].expression);
	  (yyval.statement) = new;
      
      /* static analyzer */
      linenum_constants_total++;
      linenum_gosub_totals++;
      if ((yyvsp[(2) - (2)].expression)->parms.number) {
          if ((yyvsp[(2) - (2)].expression)->parms.number > errline) {
              linenum_forwards++;
          } else {
              linenum_backwards++;
          }
      }
    }
    break;

  case 22:
#line 292 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(GOTO);
	  new->parms._goto = (yyvsp[(2) - (2)].expression);
	  (yyval.statement) = new;
      
      /* static analyzer */
      linenum_constants_total++;
      linenum_goto_totals++;
      if ((yyvsp[(2) - (2)].expression)->parms.number) {
          if ((yyvsp[(2) - (2)].expression)->parms.number > errline) {
              linenum_forwards++;
          } else {
              linenum_backwards++;
          }
      } else {
          // formula case?
      }
	}
    break;

  case 23:
#line 312 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(INPUT);
	  new->parms.input = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 24:
#line 319 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(IF);
	  new->parms._if.condition = (yyvsp[(2) - (4)].expression);
	  new->parms._if.then_expression = NULL;
	  new->parms._if.then_linenumber = (yyvsp[(4) - (4)].d);
	  (yyval.statement) = new;
      
      /* static analyzer */
      // this handles the implicit GOTO case, GOSUBs are always explicit so they are caught in the next rule
      linenum_constants_total++;
      linenum_then_goto_totals++;
      if ((yyvsp[(2) - (4)].expression)->parms.number) {
          if ((yyvsp[(2) - (4)].expression)->parms.number > errline) {
              linenum_forwards++;
          } else {
              linenum_backwards++;
          }
      } else {
          // formula case?
      }
	}
    break;

  case 25:
#line 342 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(IF);
	  new->parms._if.condition = (yyvsp[(2) - (4)].expression);
	  new->parms._if.then_expression = (yyvsp[(4) - (4)].l);
	  new->parms._if.then_linenumber = 0;
	  (yyval.statement) = new;
	}
    break;

  case 26:
#line 351 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(LET);
	  new->parms.let.variable = (yyvsp[(2) - (4)].variable);
	  new->parms.let.expression = (yyvsp[(4) - (4)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 27:
#line 359 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(NEXT);
	  new->parms.next = (yyvsp[(2) - (2)].variable);
	  (yyval.statement) = new;
	}
    break;

  case 28:
#line 366 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      statement_t *new = make_statement(NEXT);
      new->parms.next = NULL;
      (yyval.statement) = new;
    }
    break;

  case 29:
#line 373 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(ON);
	  new->parms.on.type = GOTO;
	  new->parms.on.expression = (yyvsp[(2) - (4)].expression);
	  new->parms.on.numbers = (yyvsp[(4) - (4)].l);
	  (yyval.statement) = new;
      
      linenum_constants_total++;
      linenum_on_totals++;

	}
    break;

  case 30:
#line 386 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(ON);
	  new->parms.on.type = GOSUB;
	  new->parms.on.expression = (yyvsp[(2) - (4)].expression);
	  new->parms.on.numbers = (yyvsp[(4) - (4)].l);
	  (yyval.statement) = new;
      
      linenum_constants_total++;
      linenum_on_totals++;
    }
    break;

  case 31:
#line 398 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      // since we don't actually perform the poke, we toss the parameters
      statement_t *new = make_statement(POKE);
      (yyval.statement) = new;
    }
    break;

  case 32:
#line 405 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(PRINT);
	  new->parms.print.format = NULL;
	  new->parms.print.item_list = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 33:
#line 413 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(PRINT);
	  new->parms.print.format = (yyvsp[(3) - (5)].expression);
	  new->parms.print.item_list = (yyvsp[(5) - (5)].l);
	  (yyval.statement) = new;
	}
    break;

  case 34:
#line 421 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(READ);
	  new->parms.read = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 35:
#line 428 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(REM);
	  new->parms.rem = yylval.s;
	  (yyval.statement) = new;
	}
    break;

  case 36:
#line 435 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(RESTORE);
	  (yyval.statement) = new;
	}
    break;

  case 37:
#line 441 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(RETURN);
	  (yyval.statement) = new;
	}
    break;

  case 38:
#line 447 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(STOP);
	  (yyval.statement) = new;
	}
    break;

  case 39:
#line 453 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      statement_t *new = make_statement(SYS);
      (yyval.statement) = new;
    }
    break;

  case 40:
#line 459 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(VARLIST);
	  (yyval.statement) = new;
	}
    break;

  case 41:
#line 465 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      statement_t *new = make_statement(WAIT);
      (yyval.statement) = new;
    }
    break;

  case 42:
#line 471 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(LET);
	  new->parms.let.variable = (yyvsp[(1) - (3)].variable);
	  new->parms.let.expression = (yyvsp[(3) - (3)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 45:
#line 488 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 46:
#line 497 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = AND; }
    break;

  case 47:
#line 498 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = OR;  }
    break;

  case 49:
#line 505 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 50:
#line 514 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '='; }
    break;

  case 51:
#line 515 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '<'; }
    break;

  case 52:
#line 516 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '>'; }
    break;

  case 53:
#line 517 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_LE; }
    break;

  case 54:
#line 518 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_GE; }
    break;

  case 55:
#line 519 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_NE; }
    break;

  case 56:
#line 520 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_HASH; }
    break;

  case 58:
#line 527 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 59:
#line 535 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '+'; }
    break;

  case 60:
#line 536 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 62:
#line 542 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 63:
#line 550 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '*'; }
    break;

  case 64:
#line 551 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '/'; }
    break;

  case 65:
#line 552 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '^'; }
    break;

  case 67:
#line 558 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(1, (yyvsp[(1) - (2)].i));
	  new->parms.op.p[0] = (yyvsp[(2) - (2)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 68:
#line 566 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 69:
#line 567 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = NOT; }
    break;

  case 71:
#line 574 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
	  new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 72:
#line 581 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
	  new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
	  new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 73:
#line 590 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
      new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
      new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
      (yyval.expression) = new;
    }
    break;

  case 74:
#line 599 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(3, (yyvsp[(1) - (8)].i));
	  new->parms.op.p[0] = (yyvsp[(3) - (8)].expression);
	  new->parms.op.p[1] = (yyvsp[(5) - (8)].expression);
      new->parms.op.p[2] = (yyvsp[(7) - (8)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 75:
#line 610 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = _ABS; }
    break;

  case 76:
#line 611 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = ATN; }
    break;

  case 77:
#line 612 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CHR; }
    break;

  case 78:
#line 613 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CLOG;}
    break;

  case 79:
#line 614 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = COS; }
    break;

  case 80:
#line 615 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = EXP; }
    break;

  case 81:
#line 616 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = FRE; }
    break;

  case 82:
#line 617 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = INT; }
    break;

  case 83:
#line 618 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = LEN; }
    break;

  case 84:
#line 619 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = STR; }
    break;

  case 85:
#line 620 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = LOG; }
    break;

  case 86:
#line 621 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = RND; }
    break;

  case 87:
#line 622 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SGN; }
    break;

  case 88:
#line 623 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SIN; }
    break;

  case 89:
#line 624 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SPC; }
    break;

  case 90:
#line 625 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SQR; }
    break;

  case 91:
#line 626 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = TAB; }
    break;

  case 92:
#line 627 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = VAL; }
    break;

  case 93:
#line 628 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = USR; }
    break;

  case 94:
#line 633 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = LEFT; }
    break;

  case 95:
#line 634 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = RIGHT; }
    break;

  case 96:
#line 639 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = MID; }
    break;

  case 97:
#line 647 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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
          
          // and look for a few other key ones
          if (num == 10) {
              numeric_constants_10++;
          } else if (num == 16) {
              numeric_constants_16++;
          } else if (num == 256) {
              numeric_constants_256++;
          }
      }
      /* everything else is a float */
      else {
          numeric_constants_float++;
      }
	}
    break;

  case 98:
#line 713 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_expression(string);
	  new->parms.string = (yyvsp[(1) - (1)].s);
	  (yyval.expression) = new;
      
      /* static analyzer code */
      string_constants_total++;
      if ((yyvsp[(1) - (1)].s)->len == 1) {
          string_constants_one_byte++;
      } else if ((yyvsp[(1) - (1)].s)->len == 2) {
        string_constants_two_byte++;
      } else if ((yyvsp[(1) - (1)].s)->len <= 4) {
        string_constants_four_byte++;
      } else if ((yyvsp[(1) - (1)].s)->len <= 8) {
        string_constants_eight_byte++;
      } else if ((yyvsp[(1) - (1)].s)->len <= 16) {
        string_constants_sixteen_byte++;
      } else {
          string_constants_big++;
      }
      if ((yyvsp[(1) - (1)].s)->len > string_constants_max) string_constants_max = (int)(yyvsp[(1) - (1)].s)->len;
	}
    break;

  case 99:
#line 737 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_expression(variable);
	  new->parms.variable = (yyvsp[(1) - (1)].variable);
	  (yyval.expression) = new;
	}
    break;

  case 100:
#line 744 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      expression_t *new = make_expression(fn);
      new->parms.variable = (yyvsp[(1) - (1)].variable);
      (yyval.expression) = new;
    }
    break;

  case 101:
#line 751 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.expression) = (yyvsp[(2) - (3)].expression);
	}
    break;

  case 102:
#line 761 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      variable_t *new = malloc(sizeof(*new));
      new->name = (yyvsp[(1) - (4)].s);
      new->sub = (yyvsp[(3) - (4)].l);
      (yyval.variable) = new;
    }
    break;

  case 103:
#line 771 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  variable_t *new = malloc(sizeof(*new));
	  new->name = (yyvsp[(1) - (1)].s);
	  new->sub = NULL;
	  (yyval.variable) = new;
	}
    break;

  case 104:
#line 779 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  variable_t *new = malloc(sizeof(*new));
	  new->name = (yyvsp[(1) - (4)].s);
	  new->sub = (yyvsp[(3) - (4)].l);
	  (yyval.variable) = new;
	}
    break;

  case 105:
#line 788 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = NULL;
    }
    break;

  case 106:
#line 793 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  printitem_t *new = malloc(sizeof(*new));
	  new->expression = (yyvsp[(1) - (1)].expression);
	  new->separator = 0;
	  (yyval.l) = g_list_prepend(NULL, new);
	}
    break;

  case 107:
#line 802 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      printitem_t *new = malloc(sizeof(*new));
      new->expression = (yyvsp[(1) - (2)].expression);
      new->separator = 0;
      (yyval.l) = g_list_prepend((yyvsp[(2) - (2)].l), new);
    }
    break;

  case 108:
#line 810 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  printitem_t *new = malloc(sizeof(*new));
	  new->expression = (yyvsp[(1) - (3)].expression);
	  new->separator = (yyvsp[(2) - (3)].i);
	  (yyval.l) = g_list_prepend((yyvsp[(3) - (3)].l), new);
	}
    break;

  case 109:
#line 819 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
      printitem_t *new = malloc(sizeof(*new));
      new->expression = NULL;
      new->separator = (yyvsp[(1) - (2)].i);
      (yyval.l) = g_list_prepend((yyvsp[(2) - (2)].l), new);
    }
    break;

  case 110:
#line 829 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.i) = ',';
	}
    break;

  case 111:
#line 834 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.i) = ';';
	}
    break;

  case 112:
#line 842 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].expression));
	}
    break;

  case 113:
#line 847 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 114:
#line 870 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].variable));
	}
    break;

  case 115:
#line 875 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].variable));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2687 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/Build/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
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


#line 897 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"



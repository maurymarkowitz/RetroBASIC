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
     REM = 265,
     QUOTEREM = 266,
     BANGREM = 267,
     BYE = 268,
     CLEAR = 269,
     DATA = 270,
     DEF = 271,
     DIM = 272,
     END = 273,
     EXIT = 274,
     FOR = 275,
     GET = 276,
     GOSUB = 277,
     GOTO = 278,
     IF = 279,
     INPUT = 280,
     LET = 281,
     LIST = 282,
     NEXT = 283,
     NEW = 284,
     ON = 285,
     PRINT = 286,
     PUT = 287,
     READ = 288,
     RESTORE = 289,
     RETURN = 290,
     RUN = 291,
     STEP = 292,
     STOP = 293,
     THEN = 294,
     TO = 295,
     USING = 296,
     WAIT = 297,
     OPEN = 298,
     CLOSE = 299,
     STATUS = 300,
     PRINT_FILE = 301,
     INPUT_FILE = 302,
     GET_FILE = 303,
     PUT_FILE = 304,
     CALL = 305,
     CLS = 306,
     CMD = 307,
     OPTION = 308,
     BASE = 309,
     PEEK = 310,
     POKE = 311,
     POP = 312,
     RANDOMIZE = 313,
     SYS = 314,
     VARLIST = 315,
     _ABS = 316,
     SGN = 317,
     ATN = 318,
     COS = 319,
     SIN = 320,
     TAN = 321,
     CLOG = 322,
     EXP = 323,
     LOG = 324,
     SQR = 325,
     RND = 326,
     INT = 327,
     FIX = 328,
     CINT = 329,
     CSNG = 330,
     CDBL = 331,
     ASC = 332,
     LEFT = 333,
     MID = 334,
     RIGHT = 335,
     LEN = 336,
     STR = 337,
     VAL = 338,
     CHR = 339,
     AND = 340,
     OR = 341,
     NOT = 342,
     XOR = 343,
     CMP_LE = 344,
     CMP_GE = 345,
     CMP_NE = 346,
     CMP_HASH = 347,
     FRE = 348,
     SPC = 349,
     TAB = 350,
     POS = 351,
     USR = 352,
     DEFSTR = 353,
     DEFINT = 354,
     DEFSNG = 355,
     DEFDBL = 356
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
#define DATA 270
#define DEF 271
#define DIM 272
#define END 273
#define EXIT 274
#define FOR 275
#define GET 276
#define GOSUB 277
#define GOTO 278
#define IF 279
#define INPUT 280
#define LET 281
#define LIST 282
#define NEXT 283
#define NEW 284
#define ON 285
#define PRINT 286
#define PUT 287
#define READ 288
#define RESTORE 289
#define RETURN 290
#define RUN 291
#define STEP 292
#define STOP 293
#define THEN 294
#define TO 295
#define USING 296
#define WAIT 297
#define OPEN 298
#define CLOSE 299
#define STATUS 300
#define PRINT_FILE 301
#define INPUT_FILE 302
#define GET_FILE 303
#define PUT_FILE 304
#define CALL 305
#define CLS 306
#define CMD 307
#define OPTION 308
#define BASE 309
#define PEEK 310
#define POKE 311
#define POP 312
#define RANDOMIZE 313
#define SYS 314
#define VARLIST 315
#define _ABS 316
#define SGN 317
#define ATN 318
#define COS 319
#define SIN 320
#define TAN 321
#define CLOG 322
#define EXP 323
#define LOG 324
#define SQR 325
#define RND 326
#define INT 327
#define FIX 328
#define CINT 329
#define CSNG 330
#define CDBL 331
#define ASC 332
#define LEFT 333
#define MID 334
#define RIGHT 335
#define LEN 336
#define STR 337
#define VAL 338
#define CHR 339
#define AND 340
#define OR 341
#define NOT 342
#define XOR 343
#define CMP_LE 344
#define CMP_GE 345
#define CMP_NE 346
#define CMP_HASH 347
#define FRE 348
#define SPC 349
#define TAB 350
#define POS 351
#define USR 352
#define DEFSTR 353
#define DEFINT 354
#define DEFSNG 355
#define DEFDBL 356




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
#line 374 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 387 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"

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
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  118
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNRULES -- Number of states.  */
#define YYNSTATES  216

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   356

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     102,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     114,   115,   111,   109,   105,   110,     2,   112,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   103,   106,
     107,   104,   108,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   116,     2,   117,   113,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    13,    14,    15,    19,    21,
      25,    28,    31,    32,    34,    36,    38,    40,    43,    45,
      47,    50,    55,    58,    61,    64,    67,    70,    72,    74,
      81,    90,    93,    96,    99,   104,   109,   114,   119,   122,
     124,   126,   131,   136,   140,   143,   148,   150,   153,   159,
     161,   164,   167,   169,   172,   174,   176,   179,   181,   184,
     188,   190,   192,   196,   198,   200,   202,   206,   208,   210,
     212,   214,   216,   218,   220,   222,   226,   228,   230,   232,
     236,   238,   240,   242,   244,   247,   249,   251,   253,   258,
     265,   272,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   303,   305,   307,   309,   311,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     339,   344,   346,   348,   350,   352,   354,   359,   360,   362,
     365,   369,   372,   374,   376,   378,   382,   384
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     119,     0,    -1,   120,    -1,   119,   102,   120,    -1,   119,
       1,   102,    -1,    -1,    -1,     4,   121,   122,    -1,   123,
      -1,   123,   103,   122,    -1,   122,    11,    -1,   122,    12,
      -1,    -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,
      50,   124,    -1,    51,    -1,    52,    -1,    15,   146,    -1,
      16,   140,   104,   124,    -1,    17,   147,    -1,    98,   147,
      -1,    99,   147,    -1,   100,   147,    -1,   101,   147,    -1,
      18,    -1,    19,    -1,    20,   143,   104,   124,    40,   124,
      -1,    20,   143,   104,   124,    40,   124,    37,   124,    -1,
      22,   124,    -1,    23,   124,    -1,    25,   144,    -1,    24,
     124,    39,     4,    -1,    24,   124,    23,     4,    -1,    24,
     124,    39,   122,    -1,    26,   143,   104,   124,    -1,    28,
     143,    -1,    28,    -1,    29,    -1,    30,   124,    23,   146,
      -1,    30,   124,    22,   146,    -1,    53,    54,   124,    -1,
      55,   124,    -1,    56,   124,   105,   124,    -1,    57,    -1,
      31,   144,    -1,    31,    41,   124,   106,   144,    -1,    58,
      -1,    58,   124,    -1,    33,   147,    -1,    34,    -1,    34,
     124,    -1,    35,    -1,    38,    -1,    59,   124,    -1,    60,
      -1,    42,   146,    -1,   143,   104,   124,    -1,   125,    -1,
     127,    -1,   125,   126,   127,    -1,    85,    -1,    86,    -1,
     129,    -1,   127,   128,   129,    -1,   104,    -1,   107,    -1,
     108,    -1,    89,    -1,    90,    -1,    91,    -1,    92,    -1,
     131,    -1,   129,   130,   131,    -1,   109,    -1,   110,    -1,
     133,    -1,   131,   132,   133,    -1,   111,    -1,   112,    -1,
     113,    -1,   135,    -1,   134,   135,    -1,   110,    -1,    87,
      -1,   139,    -1,   136,   114,   124,   115,    -1,   137,   114,
     124,   105,   124,   115,    -1,   138,   114,   124,   105,   124,
     115,    -1,   138,   114,   124,   105,   124,   105,   124,   115,
      -1,    61,    -1,    63,    -1,    84,    -1,    67,    -1,    64,
      -1,    68,    -1,    73,    -1,    93,    -1,    72,    -1,    81,
      -1,    82,    -1,    69,    -1,    71,    -1,    62,    -1,    65,
      -1,    94,    -1,    70,    -1,    95,    -1,    83,    -1,    97,
      -1,    78,    -1,    80,    -1,    79,    -1,     4,    -1,     3,
      -1,   143,    -1,   140,    -1,   114,   124,   115,    -1,     9,
     114,   146,   115,    -1,   114,    -1,   116,    -1,   115,    -1,
     117,    -1,     8,    -1,     8,   141,   146,   142,    -1,    -1,
     124,    -1,   124,   144,    -1,   124,   145,   144,    -1,   145,
     144,    -1,   105,    -1,   106,    -1,   124,    -1,   146,   105,
     124,    -1,   143,    -1,   147,   105,   143,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   183,   185,   190,   194,   194,   201,   206,
     211,   216,   225,   229,   236,   243,   250,   256,   262,   268,
     275,   282,   290,   298,   306,   314,   322,   330,   336,   342,
     352,   362,   380,   398,   405,   426,   447,   456,   464,   471,
     478,   485,   497,   509,   516,   523,   530,   536,   544,   552,
     559,   566,   573,   579,   586,   592,   598,   605,   611,   617,
     629,   632,   634,   644,   645,   649,   651,   661,   662,   663,
     664,   665,   666,   667,   671,   673,   694,   695,   698,   700,
     709,   710,   711,   714,   716,   725,   726,   730,   732,   739,
     748,   757,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   780,   781,   782,   783,   784,   785,   786,
     787,   788,   793,   794,   799,   806,   872,   896,   903,   910,
     921,   933,   933,   935,   935,   938,   949,   962,   966,   975,
     983,   992,  1002,  1007,  1015,  1020,  1043,  1048
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NUMBER", "DOUBLE", "SINGLE",
  "INTEGER", "VARIABLE_NAME", "FUNCTION_NAME", "REM", "QUOTEREM",
  "BANGREM", "BYE", "CLEAR", "DATA", "DEF", "DIM", "END", "EXIT", "FOR",
  "GET", "GOSUB", "GOTO", "IF", "INPUT", "LET", "LIST", "NEXT", "NEW",
  "ON", "PRINT", "PUT", "READ", "RESTORE", "RETURN", "RUN", "STEP", "STOP",
  "THEN", "TO", "USING", "WAIT", "OPEN", "CLOSE", "STATUS", "PRINT_FILE",
  "INPUT_FILE", "GET_FILE", "PUT_FILE", "CALL", "CLS", "CMD", "OPTION",
  "BASE", "PEEK", "POKE", "POP", "RANDOMIZE", "SYS", "VARLIST", "_ABS",
  "SGN", "ATN", "COS", "SIN", "TAN", "CLOG", "EXP", "LOG", "SQR", "RND",
  "INT", "FIX", "CINT", "CSNG", "CDBL", "ASC", "LEFT", "MID", "RIGHT",
  "LEN", "STR", "VAL", "CHR", "AND", "OR", "NOT", "XOR", "CMP_LE",
  "CMP_GE", "CMP_NE", "CMP_HASH", "FRE", "SPC", "TAB", "POS", "USR",
  "DEFSTR", "DEFINT", "DEFSNG", "DEFDBL", "'\\n'", "':'", "'='", "','",
  "';'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'^'", "'('", "')'",
  "'['", "']'", "$accept", "program", "line", "@1", "statements",
  "statement", "expression", "expression0", "binary_op", "expression1",
  "comparison_op", "expression2", "e2op", "expression3", "term",
  "expression4", "unary_op", "function", "fn_1", "fn_2", "fn_x", "factor",
  "user_function", "array_open_braket", "array_close_braket", "variable",
  "printlist", "printsep", "exprlist", "varlist", 0
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
     355,   356,    10,    58,    61,    44,    59,    60,    62,    43,
      45,    42,    47,    94,    40,    41,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   118,   119,   119,   119,   120,   121,   120,   122,   122,
     122,   122,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   135,   135,   135,
     135,   135,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   137,   137,   138,   139,   139,   139,   139,   139,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     144,   144,   145,   145,   146,   146,   147,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     0,     0,     3,     1,     3,
       2,     2,     0,     1,     1,     1,     1,     2,     1,     1,
       2,     4,     2,     2,     2,     2,     2,     1,     1,     6,
       8,     2,     2,     2,     4,     4,     4,     4,     2,     1,
       1,     4,     4,     3,     2,     4,     1,     2,     5,     1,
       2,     2,     1,     2,     1,     1,     2,     1,     2,     3,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     4,     6,
       6,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     1,     1,     1,     1,     4,     0,     1,     2,
       3,     2,     1,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     6,     0,     2,    12,     1,     0,     5,   125,    13,
      14,    15,    16,     0,     0,     0,    27,    28,     0,     0,
       0,     0,   127,     0,    39,    40,     0,   127,     0,    52,
      54,    55,     0,     0,    18,    19,     0,     0,     0,    46,
      49,     0,    57,     0,     0,     0,     0,     7,     8,     0,
       4,     3,   121,   122,     0,   116,   115,     0,    92,   105,
      93,    96,   106,    95,    97,   103,   108,   104,   100,    98,
     112,   114,   113,   101,   102,   110,    94,    86,    99,   107,
     109,   111,    85,     0,   134,    60,    61,    65,    74,    78,
       0,    83,     0,     0,     0,    87,   118,   117,    20,     0,
     136,    22,     0,    31,    32,     0,   132,   133,   127,    33,
     127,     0,    38,     0,     0,    47,    51,    53,    58,    17,
       0,    44,     0,    50,    56,    23,    24,    25,    26,    10,
      11,    12,     0,     0,     0,     0,    63,    64,     0,    70,
      71,    72,    73,    67,    68,    69,     0,    76,    77,     0,
      80,    81,    82,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    12,   129,   127,   131,     0,     0,     0,
       0,    43,     0,     9,    59,   123,   124,   126,     0,   119,
      62,    66,    75,    79,     0,     0,     0,   135,    21,   137,
       0,    35,    34,    36,   130,    37,    42,    41,   127,    45,
     120,    88,     0,     0,     0,    48,     0,     0,    29,    89,
       0,    90,     0,     0,    30,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    47,    48,    84,    85,   138,    86,
     146,    87,   149,    88,   153,    89,    90,    91,    92,    93,
      94,    95,    96,    54,   177,    97,   109,   110,    98,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -128
static const yytype_int16 yypact[] =
{
      31,  -128,    12,  -128,   540,  -128,   -58,    31,  -105,  -128,
    -128,  -128,  -128,   305,    42,    47,  -128,  -128,    47,   305,
     305,   305,   223,    47,    47,  -128,   305,   141,    47,   305,
    -128,  -128,   305,   305,  -128,  -128,    15,   305,   305,  -128,
     305,   305,  -128,    47,    47,    47,    47,    17,   -45,   -34,
    -128,  -128,  -128,  -128,   305,  -128,  -128,   -43,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,  -128,
    -128,  -128,  -128,   305,  -128,   -62,   -51,   -44,   -50,  -128,
     387,  -128,   -42,   -41,   -40,  -128,  -128,  -128,   -30,   -28,
    -128,   -27,   -25,  -128,  -128,     4,  -128,  -128,   223,  -128,
     223,   -24,  -128,    45,   305,  -128,   -27,  -128,   -30,  -128,
     305,  -128,   -23,  -128,  -128,   -27,   -27,   -27,   -27,  -128,
    -128,   540,   305,   -63,   305,   -38,  -128,  -128,   305,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,   305,  -128,  -128,   305,
    -128,  -128,  -128,   305,  -128,   305,   305,   305,   305,   305,
      47,   305,    77,   487,  -128,   223,  -128,   305,   305,   305,
     -21,  -128,   305,    17,  -128,  -128,  -128,  -128,   -56,  -128,
     -51,   -44,   -50,  -128,   -32,   -18,   -15,  -128,  -128,  -128,
      44,  -128,  -128,    17,  -128,  -128,   -30,   -30,   223,  -128,
    -128,  -128,   305,   305,   305,  -128,   -16,   -55,    55,  -128,
     305,  -128,   305,   -13,  -128,  -128
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -128,  -128,    86,  -128,  -127,  -128,   -19,  -128,  -128,   -35,
    -128,   -52,  -128,   -53,  -128,   -49,  -128,     7,  -128,  -128,
    -128,  -128,    84,  -128,  -128,     2,   -22,    -8,   -17,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     103,   104,   105,   108,   173,   115,    49,   113,   108,    52,
     117,    53,     5,     6,   119,   118,   116,   100,   121,   122,
     102,   123,   124,   136,   137,   111,   112,   162,   129,   130,
     100,   125,   126,   127,   128,     1,   193,   133,   139,   140,
     141,   142,   158,   163,    50,   100,   100,   100,   100,   158,
     210,    57,   175,   143,   176,     8,   144,   145,   131,   200,
     211,   150,   151,   152,   135,   147,   148,   168,   169,   120,
     132,   134,   155,   156,   157,   158,   159,   179,   160,   161,
     167,   191,   172,   201,   204,   198,   164,   202,   166,   108,
     203,   108,   212,    51,   181,   170,   182,   154,    99,   209,
     165,   171,   215,   180,   183,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     7,     0,     0,   178,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   184,   185,   186,   187,
     188,     0,   190,   194,    55,    56,   108,     0,   195,     8,
      57,   196,   197,   199,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,     0,     0,   108,
       0,     0,   114,   206,   207,   208,     0,     0,     0,     0,
       0,   213,     0,   214,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,     0,    70,
      71,    72,    73,    74,    75,    76,    55,    56,    77,     0,
       0,     8,    57,     0,    78,    79,    80,     0,    81,     0,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,    82,     0,     0,     0,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,    70,    71,    72,    73,    74,    75,    76,    55,    56,
      77,     0,     0,     8,    57,     0,    78,    79,    80,     0,
      81,     0,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,    82,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,    70,    71,    72,    73,    74,    75,    76,
      55,    56,    77,     0,     0,     8,    57,     0,    78,    79,
      80,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,    70,    71,    72,    73,    74,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,     0,    81,     0,     0,     0,     0,     0,
       0,   192,     0,     0,     0,     8,     0,     9,    10,    11,
      12,    83,    13,    14,    15,    16,    17,    18,     0,    19,
      20,    21,    22,    23,     0,    24,    25,    26,    27,     0,
      28,    29,    30,     0,     0,    31,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    33,    34,    35,
      36,     0,    37,    38,    39,    40,    41,    42,     8,     0,
       9,    10,    11,    12,     0,    13,    14,    15,    16,    17,
      18,     0,    19,    20,    21,    22,    23,     0,    24,    25,
      26,    27,     0,    28,    29,    30,     0,     0,    31,     0,
       0,     0,    32,     0,     0,    43,    44,    45,    46,     0,
      33,    34,    35,    36,     0,    37,    38,    39,    40,    41,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    44,
      45,    46
};

static const yytype_int16 yycheck[] =
{
      19,    20,    21,    22,   131,    27,     4,    26,    27,   114,
      29,   116,     0,     1,    33,    32,    28,    15,    37,    38,
      18,    40,    41,    85,    86,    23,    24,    23,    11,    12,
      28,    43,    44,    45,    46,     4,   163,    54,    89,    90,
      91,    92,   105,    39,   102,    43,    44,    45,    46,   105,
     105,     9,   115,   104,   117,     8,   107,   108,   103,   115,
     115,   111,   112,   113,    83,   109,   110,    22,    23,    54,
     104,   114,   114,   114,   114,   105,   104,   115,   105,   104,
     104,     4,   105,   115,    40,   106,   108,   105,   110,   108,
     105,   110,    37,     7,   146,   114,   149,    90,    14,   115,
     108,   120,   115,   138,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,   102,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   131,    -1,    -1,   155,   156,   157,   158,
     159,    -1,   161,   165,     3,     4,   165,    -1,   167,     8,
       9,   168,   169,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   160,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,   198,
      -1,    -1,    41,   202,   203,   204,    -1,    -1,    -1,    -1,
      -1,   210,    -1,   212,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,     3,     4,    87,    -1,
      -1,     8,     9,    -1,    93,    94,    95,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,    -1,    -1,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    -1,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    84,     3,     4,
      87,    -1,    -1,     8,     9,    -1,    93,    94,    95,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,    -1,    -1,    -1,   114,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
       3,     4,    87,    -1,    -1,     8,     9,    -1,    93,    94,
      95,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,   114,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    -1,     8,    -1,    10,    11,    12,
      13,   114,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    25,    26,    -1,    28,    29,    30,    31,    -1,
      33,    34,    35,    -1,    -1,    38,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,     8,    -1,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    25,    26,    -1,    28,    29,
      30,    31,    -1,    33,    34,    35,    -1,    -1,    38,    -1,
      -1,    -1,    42,    -1,    -1,    98,    99,   100,   101,    -1,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,    99,
     100,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,   119,   120,   121,     0,     1,   102,     8,    10,
      11,    12,    13,    15,    16,    17,    18,    19,    20,    22,
      23,    24,    25,    26,    28,    29,    30,    31,    33,    34,
      35,    38,    42,    50,    51,    52,    53,    55,    56,    57,
      58,    59,    60,    98,    99,   100,   101,   122,   123,   143,
     102,   120,   114,   116,   141,     3,     4,     9,    61,    62,
      63,    64,    65,    67,    68,    69,    70,    71,    72,    73,
      78,    79,    80,    81,    82,    83,    84,    87,    93,    94,
      95,    97,   110,   114,   124,   125,   127,   129,   131,   133,
     134,   135,   136,   137,   138,   139,   140,   143,   146,   140,
     143,   147,   143,   124,   124,   124,   105,   106,   124,   144,
     145,   143,   143,   124,    41,   144,   147,   124,   146,   124,
      54,   124,   124,   124,   124,   147,   147,   147,   147,    11,
      12,   103,   104,   146,   114,   124,    85,    86,   126,    89,
      90,    91,    92,   104,   107,   108,   128,   109,   110,   130,
     111,   112,   113,   132,   135,   114,   114,   114,   105,   104,
     105,   104,    23,    39,   144,   145,   144,   104,    22,    23,
     124,   124,   105,   122,   124,   115,   117,   142,   146,   115,
     127,   129,   131,   133,   124,   124,   124,   124,   124,   143,
     124,     4,     4,   122,   144,   124,   146,   146,   106,   124,
     115,   115,   105,   105,    40,   144,   124,   124,   124,   115,
     105,   115,    37,   124,   124,   115
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
#line 190 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	}
    break;

  case 6:
#line 194 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { errline = (yyvsp[(1) - (1)].d); }
    break;

  case 7:
#line 195 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  interpreter_state.lines[(int)(yyvsp[(1) - (3)].d)] = (yyvsp[(3) - (3)].l);
	}
    break;

  case 8:
#line 202 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].statement));
  }
    break;

  case 9:
#line 207 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
  (yyval.l) = g_list_prepend((yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].statement));
  }
    break;

  case 10:
#line 212 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    (yyval.l) = g_list_prepend((yyvsp[(1) - (2)].l), NULL);
  }
    break;

  case 11:
#line 217 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    (yyval.l) = g_list_prepend((yyvsp[(1) - (2)].l), NULL);
  }
    break;

  case 12:
#line 225 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.statement) = NULL;
	}
    break;

  case 13:
#line 230 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(REM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 14:
#line 237 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(QUOTEREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 15:
#line 244 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(BANGREM);
    new->parms.rem = yylval.s;
    (yyval.statement) = new;
  }
    break;

  case 16:
#line 251 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(BYE);
	  (yyval.statement) = new;
	}
    break;

  case 17:
#line 257 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CALL);
    (yyval.statement) = new;
  }
    break;

  case 18:
#line 263 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CLS);
    (yyval.statement) = new;
  }
    break;

  case 19:
#line 269 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(CMD);
    (yyval.statement) = new;
  }
    break;

  case 20:
#line 276 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
  statement_t *new = make_statement(DATA);
  new->parms.data = (yyvsp[(2) - (2)].l);
  (yyval.statement) = new;
  }
    break;

  case 21:
#line 283 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEF);
    new->parms.def.signature = (yyvsp[(2) - (4)].variable);
    new->parms.def.formula = (yyvsp[(4) - (4)].expression);
    (yyval.statement) = new;
  }
    break;

  case 22:
#line 291 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DIM);
    new->parms.dim = (yyvsp[(2) - (2)].l);
    (yyval.statement) = new;
  }
    break;

  case 23:
#line 299 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = STRING;
    (yyval.statement) = new;
  }
    break;

  case 24:
#line 307 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = INTEGER;
    (yyval.statement) = new;
  }
    break;

  case 25:
#line 315 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = SINGLE;
    (yyval.statement) = new;
  }
    break;

  case 26:
#line 323 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(DEFSTR);
    new->parms.deftype.vars = (yyvsp[(2) - (2)].l);
    new->parms.deftype.type = DOUBLE;
    (yyval.statement) = new;
  }
    break;

  case 27:
#line 331 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(END);
	  (yyval.statement) = new;
	}
    break;

  case 28:
#line 337 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(EXIT);
    (yyval.statement) = new;
  }
    break;

  case 29:
#line 343 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(FOR);
	  new->parms._for.variable = (yyvsp[(2) - (6)].variable);
	  new->parms._for.begin = (yyvsp[(4) - (6)].expression);
	  new->parms._for.end = (yyvsp[(6) - (6)].expression);
	  new->parms._for.step = NULL;
	  (yyval.statement) = new;
	}
    break;

  case 30:
#line 353 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(FOR);
	  new->parms._for.variable = (yyvsp[(2) - (8)].variable);
	  new->parms._for.begin = (yyvsp[(4) - (8)].expression);
	  new->parms._for.end = (yyvsp[(6) - (8)].expression);
	  new->parms._for.step = (yyvsp[(8) - (8)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 31:
#line 363 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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

  case 32:
#line 381 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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
    }
	}
    break;

  case 33:
#line 399 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(INPUT);
	  new->parms.input = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 34:
#line 406 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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
    }
	}
    break;

  case 35:
#line 427 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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
    }
  }
    break;

  case 36:
#line 448 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(IF);
	  new->parms._if.condition = (yyvsp[(2) - (4)].expression);
	  new->parms._if.then_expression = (yyvsp[(4) - (4)].l);
	  new->parms._if.then_linenumber = 0;
	  (yyval.statement) = new;
	}
    break;

  case 37:
#line 457 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(LET);
	  new->parms.let.variable = (yyvsp[(2) - (4)].variable);
	  new->parms.let.expression = (yyvsp[(4) - (4)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 38:
#line 465 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(NEXT);
	  new->parms.next = (yyvsp[(2) - (2)].variable);
	  (yyval.statement) = new;
	}
    break;

  case 39:
#line 472 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEXT);
    new->parms.next = NULL;
    (yyval.statement) = new;
  }
    break;

  case 40:
#line 479 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(NEW);
    new->parms.next = NULL;
    (yyval.statement) = new;
  }
    break;

  case 41:
#line 486 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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

  case 42:
#line 498 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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

  case 43:
#line 510 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(OPTION);
    new->parms.generic_parameter = (yyvsp[(3) - (3)].expression);
    (yyval.statement) = new;
  }
    break;

  case 44:
#line 517 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    // since we don't actually perform the peek, we toss the parameters
    statement_t *new = make_statement(PEEK);
    (yyval.statement) = new;
  }
    break;

  case 45:
#line 524 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    // since we don't actually perform the poke, we toss the parameters
    statement_t *new = make_statement(POKE);
    (yyval.statement) = new;
  }
    break;

  case 46:
#line 531 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(POP);
    (yyval.statement) = new;
  }
    break;

  case 47:
#line 537 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(PRINT);
	  new->parms.print.format = NULL;
	  new->parms.print.item_list = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 48:
#line 545 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(PRINT);
	  new->parms.print.format = (yyvsp[(3) - (5)].expression);
	  new->parms.print.item_list = (yyvsp[(5) - (5)].l);
	  (yyval.statement) = new;
	}
    break;

  case 49:
#line 553 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = NULL;
    (yyval.statement) = new;
  }
    break;

  case 50:
#line 560 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RANDOMIZE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 51:
#line 567 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(READ);
	  new->parms.read = (yyvsp[(2) - (2)].l);
	  (yyval.statement) = new;
	}
    break;

  case 52:
#line 574 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(RESTORE);
	  (yyval.statement) = new;
	}
    break;

  case 53:
#line 580 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(RESTORE);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 54:
#line 587 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(RETURN);
	  (yyval.statement) = new;
	}
    break;

  case 55:
#line 593 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(STOP);
	  (yyval.statement) = new;
	}
    break;

  case 56:
#line 599 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(SYS);
    new->parms.generic_parameter = (yyvsp[(2) - (2)].expression);
    (yyval.statement) = new;
  }
    break;

  case 57:
#line 606 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(VARLIST);
	  (yyval.statement) = new;
	}
    break;

  case 58:
#line 612 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    statement_t *new = make_statement(WAIT);
    (yyval.statement) = new;
  }
    break;

  case 59:
#line 618 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  statement_t *new = make_statement(LET);
	  new->parms.let.variable = (yyvsp[(1) - (3)].variable);
	  new->parms.let.expression = (yyvsp[(3) - (3)].expression);
	  (yyval.statement) = new;
	}
    break;

  case 62:
#line 635 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 63:
#line 644 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = AND; }
    break;

  case 64:
#line 645 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = OR;  }
    break;

  case 66:
#line 652 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 67:
#line 661 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '='; }
    break;

  case 68:
#line 662 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '<'; }
    break;

  case 69:
#line 663 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '>'; }
    break;

  case 70:
#line 664 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_LE; }
    break;

  case 71:
#line 665 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_GE; }
    break;

  case 72:
#line 666 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_NE; }
    break;

  case 73:
#line 667 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CMP_HASH; }
    break;

  case 75:
#line 674 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    
    //printf("%s\n",$3);
    
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
    
    /* static analyser - if it's + or - 1, record it as an increment */
    if (new->parms.op.p[1]->type == number  && (int)new->parms.op.p[1]->parms.number == 1 && (int)new->parms.op.p[1]->parms.number == new->parms.op.p[1]->parms.number) {
      if (new->parms.op.opcode == '+') {
        increments++;
      } else {
        decrements++;
      }
    }
	}
    break;

  case 76:
#line 694 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '+'; }
    break;

  case 77:
#line 695 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 79:
#line 701 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(2) - (3)].i));
	  new->parms.op.p[0] = (yyvsp[(1) - (3)].expression);
	  new->parms.op.p[1] = (yyvsp[(3) - (3)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 80:
#line 709 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '*'; }
    break;

  case 81:
#line 710 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '/'; }
    break;

  case 82:
#line 711 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '^'; }
    break;

  case 84:
#line 717 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(1, (yyvsp[(1) - (2)].i));
	  new->parms.op.p[0] = (yyvsp[(2) - (2)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 85:
#line 725 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = '-'; }
    break;

  case 86:
#line 726 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = NOT; }
    break;

  case 88:
#line 733 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(1, (yyvsp[(1) - (4)].i));
	  new->parms.op.p[0] = (yyvsp[(3) - (4)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 89:
#line 740 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
	  new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
	  new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 90:
#line 749 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_operator(2, (yyvsp[(1) - (6)].i));
    new->parms.op.p[0] = (yyvsp[(3) - (6)].expression);
    new->parms.op.p[1] = (yyvsp[(5) - (6)].expression);
    (yyval.expression) = new;
  }
    break;

  case 91:
#line 758 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  expression_t *new = make_operator(3, (yyvsp[(1) - (8)].i));
	  new->parms.op.p[0] = (yyvsp[(3) - (8)].expression);
	  new->parms.op.p[1] = (yyvsp[(5) - (8)].expression);
      new->parms.op.p[2] = (yyvsp[(7) - (8)].expression);
	  (yyval.expression) = new;
	}
    break;

  case 92:
#line 769 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = _ABS; }
    break;

  case 93:
#line 770 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = ATN; }
    break;

  case 94:
#line 771 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CHR; }
    break;

  case 95:
#line 772 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = CLOG;}
    break;

  case 96:
#line 773 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = COS; }
    break;

  case 97:
#line 774 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = EXP; }
    break;

  case 98:
#line 775 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = FIX; }
    break;

  case 99:
#line 776 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = FRE; }
    break;

  case 100:
#line 777 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = INT; }
    break;

  case 101:
#line 778 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = LEN; }
    break;

  case 102:
#line 779 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = STR; }
    break;

  case 103:
#line 780 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = LOG; }
    break;

  case 104:
#line 781 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = RND; }
    break;

  case 105:
#line 782 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SGN; }
    break;

  case 106:
#line 783 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SIN; }
    break;

  case 107:
#line 784 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SPC; }
    break;

  case 108:
#line 785 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = SQR; }
    break;

  case 109:
#line 786 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = TAB; }
    break;

  case 110:
#line 787 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = VAL; }
    break;

  case 111:
#line 788 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = USR; }
    break;

  case 112:
#line 793 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = LEFT; }
    break;

  case 113:
#line 794 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = RIGHT; }
    break;

  case 114:
#line 799 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    { (yyval.i) = MID; }
    break;

  case 115:
#line 807 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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

  case 116:
#line 873 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
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

  case 117:
#line 897 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(variable);
    new->parms.variable = (yyvsp[(1) - (1)].variable);
    (yyval.expression) = new;
  }
    break;

  case 118:
#line 904 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    expression_t *new = make_expression(fn);
    new->parms.variable = (yyvsp[(1) - (1)].variable); // use the variable slot here, it has the same signature
    (yyval.expression) = new;
  }
    break;

  case 119:
#line 911 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    (yyval.expression) = (yyvsp[(2) - (3)].expression);
  }
    break;

  case 120:
#line 922 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    variable_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;
    // do NOT insert it now, the variables are private and will be set up during the DEF
  }
    break;

  case 125:
#line 939 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  variable_t *new = malloc(sizeof(*new));
	  new->name = (yyvsp[(1) - (1)].s);
	  new->subscripts = NULL;
	  (yyval.variable) = new;
    
    /* add it to the interpreter's variable list for the analyizer*/
    insert_variable(new);
	}
    break;

  case 126:
#line 950 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    variable_t *new = malloc(sizeof(*new));
    new->name = (yyvsp[(1) - (4)].s);
    new->subscripts = (yyvsp[(3) - (4)].l);
    (yyval.variable) = new;

    /* this may result in errors about array bounds if you need to OPTION BASE but do so after the DIM */
    insert_variable(new);
  }
    break;

  case 127:
#line 962 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = NULL;
  }
    break;

  case 128:
#line 967 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  printitem_t *new = malloc(sizeof(*new));
	  new->expression = (yyvsp[(1) - (1)].expression);
	  new->separator = 0;
	  (yyval.l) = g_list_prepend(NULL, new);
	}
    break;

  case 129:
#line 976 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = (yyvsp[(1) - (2)].expression);
    new->separator = 0;
    (yyval.l) = g_list_prepend((yyvsp[(2) - (2)].l), new);
  }
    break;

  case 130:
#line 984 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  printitem_t *new = malloc(sizeof(*new));
	  new->expression = (yyvsp[(1) - (3)].expression);
	  new->separator = (yyvsp[(2) - (3)].i);
	  (yyval.l) = g_list_prepend((yyvsp[(3) - (3)].l), new);
	}
    break;

  case 131:
#line 993 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
    printitem_t *new = malloc(sizeof(*new));
    new->expression = NULL;
    new->separator = (yyvsp[(1) - (2)].i);
    (yyval.l) = g_list_prepend((yyvsp[(2) - (2)].l), new);
  }
    break;

  case 132:
#line 1003 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.i) = ',';
	}
    break;

  case 133:
#line 1008 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.i) = ';';
	}
    break;

  case 134:
#line 1016 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].expression));
	}
    break;

  case 135:
#line 1021 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].expression));
	}
    break;

  case 136:
#line 1044 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_prepend(NULL, (yyvsp[(1) - (1)].variable));
	}
    break;

  case 137:
#line 1049 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"
    {
	  (yyval.l) = g_list_append((yyvsp[(1) - (3)].l), (yyvsp[(3) - (3)].variable));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2972 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/obj/Intermediates.noindex/RetroBASIC.build/Debug/retrobasic.build/DerivedSources/y.tab.c"
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


#line 1071 "/Volumes/Bigger/Users/maury/Library/Mobile Documents/com~apple~CloudDocs/RetroBASIC/src/parse.y"



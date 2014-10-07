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
     IDENTIFIER = 258,
     INTEGER = 259,
     FLOATING = 260,
     CHARACTER = 261,
     STRING = 262,
     TYPEDEF_NAME = 263,
     NAMESPACE_NAME = 264,
     CLASS_NAME = 265,
     ENUM_NAME = 266,
     TEMPLATE_NAME = 267,
     ELLIPSIS = 268,
     COLONCOLON = 269,
     DOTSTAR = 270,
     ADDEQ = 271,
     SUBEQ = 272,
     MULEQ = 273,
     DIVEQ = 274,
     MODEQ = 275,
     XOREQ = 276,
     ANDEQ = 277,
     OREQ = 278,
     SL = 279,
     SR = 280,
     SREQ = 281,
     SLEQ = 282,
     EQ = 283,
     NOTEQ = 284,
     LTEQ = 285,
     GTEQ = 286,
     ANDAND = 287,
     OROR = 288,
     PLUSPLUS = 289,
     MINUSMINUS = 290,
     ARROWSTAR = 291,
     ARROW = 292,
     ASM = 293,
     AUTO = 294,
     BOOL = 295,
     BREAK = 296,
     CASE = 297,
     CATCH = 298,
     CHAR = 299,
     CLASS = 300,
     CONST = 301,
     CONST_CAST = 302,
     CONTINUE = 303,
     DEFAULT = 304,
     DELETE = 305,
     DO = 306,
     DOUBLE = 307,
     DYNAMIC_CAST = 308,
     ELSE = 309,
     ENUM = 310,
     EXPLICIT = 311,
     EXPORT = 312,
     EXTERN = 313,
     FALSE = 314,
     FLOAT = 315,
     FOR = 316,
     FRIEND = 317,
     GOTO = 318,
     IF = 319,
     INLINE = 320,
     INT = 321,
     LONG = 322,
     MUTABLE = 323,
     NAMESPACE = 324,
     NEW = 325,
     OPERATOR = 326,
     PRIVATE = 327,
     PROTECTED = 328,
     PUBLIC = 329,
     REGISTER = 330,
     REINTERPRET_CAST = 331,
     RETURN = 332,
     SHORT = 333,
     SIGNED = 334,
     SIZEOF = 335,
     STATIC = 336,
     STATIC_CAST = 337,
     STRUCT = 338,
     SWITCH = 339,
     TEMPLATE = 340,
     THIS = 341,
     THROW = 342,
     TRUE = 343,
     TRY = 344,
     TYPEDEF = 345,
     TYPEID = 346,
     TYPENAME = 347,
     UNION = 348,
     UNSIGNED = 349,
     USING = 350,
     VIRTUAL = 351,
     VOID = 352,
     VOLATILE = 353,
     WCHAR_T = 354,
     WHILE = 355
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER 259
#define FLOATING 260
#define CHARACTER 261
#define STRING 262
#define TYPEDEF_NAME 263
#define NAMESPACE_NAME 264
#define CLASS_NAME 265
#define ENUM_NAME 266
#define TEMPLATE_NAME 267
#define ELLIPSIS 268
#define COLONCOLON 269
#define DOTSTAR 270
#define ADDEQ 271
#define SUBEQ 272
#define MULEQ 273
#define DIVEQ 274
#define MODEQ 275
#define XOREQ 276
#define ANDEQ 277
#define OREQ 278
#define SL 279
#define SR 280
#define SREQ 281
#define SLEQ 282
#define EQ 283
#define NOTEQ 284
#define LTEQ 285
#define GTEQ 286
#define ANDAND 287
#define OROR 288
#define PLUSPLUS 289
#define MINUSMINUS 290
#define ARROWSTAR 291
#define ARROW 292
#define ASM 293
#define AUTO 294
#define BOOL 295
#define BREAK 296
#define CASE 297
#define CATCH 298
#define CHAR 299
#define CLASS 300
#define CONST 301
#define CONST_CAST 302
#define CONTINUE 303
#define DEFAULT 304
#define DELETE 305
#define DO 306
#define DOUBLE 307
#define DYNAMIC_CAST 308
#define ELSE 309
#define ENUM 310
#define EXPLICIT 311
#define EXPORT 312
#define EXTERN 313
#define FALSE 314
#define FLOAT 315
#define FOR 316
#define FRIEND 317
#define GOTO 318
#define IF 319
#define INLINE 320
#define INT 321
#define LONG 322
#define MUTABLE 323
#define NAMESPACE 324
#define NEW 325
#define OPERATOR 326
#define PRIVATE 327
#define PROTECTED 328
#define PUBLIC 329
#define REGISTER 330
#define REINTERPRET_CAST 331
#define RETURN 332
#define SHORT 333
#define SIGNED 334
#define SIZEOF 335
#define STATIC 336
#define STATIC_CAST 337
#define STRUCT 338
#define SWITCH 339
#define TEMPLATE 340
#define THIS 341
#define THROW 342
#define TRUE 343
#define TRY 344
#define TYPEDEF 345
#define TYPEID 346
#define TYPENAME 347
#define UNION 348
#define UNSIGNED 349
#define USING 350
#define VIRTUAL 351
#define VOID 352
#define VOLATILE 353
#define WCHAR_T 354
#define WHILE 355




/* Copy the first part of user declarations.  */
#line 44 "120gram.y"

#include <stdio.h>
#include <string.h>

#include "tree.h"
#include "120lex.h"

extern int lineno;
extern char *yytext;
int yydebug=0;

static void yyerror(char *s);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 60 "120gram.y"
{
  struct node *np;
  }
/* Line 193 of yacc.c.  */
#line 315 "120gram.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 328 "120gram.tab.c"

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
#define YYFINAL  178
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4043

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  171
/* YYNRULES -- Number of rules.  */
#define YYNRULES  503
/* YYNRULES -- Number of states.  */
#define YYNSTATES  858

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   355

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,     2,     2,     2,   116,   111,     2,
     101,   102,   110,   112,   109,   113,   106,   115,   125,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   120,   122,
     107,   121,   108,   119,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   104,     2,   105,   117,   126,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   123,   118,   124,   103,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    51,    53,    55,    57,    59,
      61,    63,    66,    69,    73,    80,    83,    86,    88,    93,
      98,   104,   109,   114,   118,   124,   129,   134,   138,   141,
     144,   152,   160,   168,   176,   181,   186,   188,   192,   194,
     197,   200,   203,   206,   209,   212,   217,   219,   221,   223,
     225,   227,   229,   234,   240,   247,   255,   259,   262,   265,
     267,   271,   276,   280,   283,   287,   292,   298,   300,   305,
     307,   311,   315,   317,   321,   325,   329,   331,   335,   339,
     341,   345,   349,   351,   355,   359,   363,   367,   369,   373,
     377,   379,   383,   385,   389,   391,   395,   397,   401,   403,
     407,   409,   415,   417,   421,   423,   425,   427,   429,   431,
     433,   435,   437,   439,   441,   443,   445,   447,   451,   453,
     455,   457,   459,   461,   463,   465,   467,   469,   473,   478,
     482,   485,   489,   491,   494,   500,   508,   514,   516,   521,
     527,   535,   544,   546,   548,   551,   554,   558,   562,   564,
     566,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   591,   593,   597,   600,   602,   604,   606,   608,
     610,   612,   615,   617,   619,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   639,   641,   643,   646,   650,   652,
     654,   656,   658,   660,   662,   664,   666,   668,   670,   672,
     674,   676,   678,   683,   687,   692,   696,   700,   705,   713,
     719,   721,   725,   727,   731,   733,   735,   737,   739,   741,
     747,   753,   758,   760,   766,   770,   773,   776,   778,   785,
     791,   797,   802,   807,   814,   820,   826,   831,   837,   843,
     847,   849,   853,   856,   858,   861,   863,   870,   876,   882,
     887,   892,   899,   906,   911,   915,   917,   920,   922,   925,
     929,   933,   938,   940,   943,   945,   947,   949,   952,   956,
     959,   962,   965,   968,   970,   977,   983,   989,   994,   999,
    1003,  1006,  1008,  1010,  1011,  1015,  1017,  1021,  1024,  1029,
    1032,  1037,  1041,  1046,  1049,  1053,  1055,  1058,  1062,  1064,
    1069,  1072,  1074,  1078,  1083,  1086,  1090,  1094,  1099,  1101,
    1103,  1105,  1108,  1112,  1116,  1119,  1122,  1124,  1127,  1130,
    1132,  1134,  1136,  1140,  1141,  1143,  1146,  1149,  1153,  1156,
    1159,  1162,  1164,  1168,  1172,  1175,  1178,  1180,  1186,  1191,
    1196,  1200,  1206,  1211,  1216,  1220,  1222,  1224,  1226,  1229,
    1232,  1235,  1238,  1240,  1244,  1249,  1253,  1256,  1259,  1261,
    1263,  1266,  1268,  1270,  1274,  1278,  1280,  1282,  1284,  1286,
    1288,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,
    1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,  1326,
    1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,
    1348,  1350,  1353,  1356,  1363,  1365,  1369,  1371,  1373,  1376,
    1381,  1384,  1389,  1396,  1405,  1410,  1412,  1416,  1418,  1420,
    1422,  1425,  1430,  1434,  1439,  1442,  1448,  1451,  1454,  1456,
    1458,  1461,  1466,  1468,  1472,  1473,  1475,  1476,  1478,  1479,
    1481,  1482,  1484,  1485,  1487,  1488,  1490,  1491,  1493,  1494,
    1496,  1497,  1499,  1500,  1502,  1503,  1505,  1506,  1508,  1509,
    1511,  1512,  1514,  1515,  1517,  1518,  1520,  1521,  1523,  1524,
    1526,  1527,  1529,  1530,  1532,  1533,  1535,  1536,  1538,  1539,
    1541,  1542,  1544,  1545
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     141,     0,    -1,     8,    -1,   130,    -1,     9,    -1,    10,
      -1,   260,    -1,    11,    -1,    12,    -1,     3,    -1,   136,
      -1,   137,    -1,   138,    -1,   139,    -1,   140,    -1,     4,
      -1,     6,    -1,     5,    -1,     7,    -1,    88,    -1,    59,
      -1,   273,    -1,   135,    -1,    86,    -1,   101,   173,   102,
      -1,   143,    -1,   144,    -1,   145,    -1,   134,    -1,   254,
      -1,   247,    -1,   103,   131,    -1,   146,   144,    -1,   146,
      85,   144,    -1,   131,    14,   146,   129,    14,   146,    -1,
     131,    14,    -1,   129,    14,    -1,   142,    -1,   147,   104,
     173,   105,    -1,   147,   101,   275,   102,    -1,   147,   106,
      85,    14,   143,    -1,   147,   106,    85,   143,    -1,   147,
     106,    14,   143,    -1,   147,   106,   143,    -1,   147,    37,
      85,    14,   143,    -1,   147,    37,    85,   143,    -1,   147,
      37,    14,   143,    -1,   147,    37,   143,    -1,   147,    34,
      -1,   147,    35,    -1,    53,   107,   222,   108,   101,   173,
     102,    -1,    82,   107,   222,   108,   101,   173,   102,    -1,
      76,   107,   222,   108,   101,   173,   102,    -1,    47,   107,
     222,   108,   101,   173,   102,    -1,    91,   101,   173,   102,
      -1,    91,   101,   222,   102,    -1,   171,    -1,   148,   109,
     171,    -1,   147,    -1,    34,   158,    -1,    35,   158,    -1,
     110,   158,    -1,   111,   158,    -1,   150,   158,    -1,    80,
     149,    -1,    80,   101,   222,   102,    -1,   151,    -1,   157,
      -1,   112,    -1,   113,    -1,   114,    -1,   103,    -1,    70,
     277,   153,   278,    -1,    14,    70,   277,   153,   278,    -1,
      70,   277,   101,   222,   102,   278,    -1,    14,    70,   277,
     101,   222,   102,   278,    -1,   101,   148,   102,    -1,   223,
     279,    -1,   218,   279,    -1,   155,    -1,   104,   173,   105,
      -1,   155,   104,   174,   105,    -1,   101,   275,   102,    -1,
      50,   158,    -1,    14,    50,   158,    -1,    50,   104,   105,
     158,    -1,    14,    50,   104,   105,   158,    -1,   149,    -1,
     101,   222,   102,   158,    -1,   158,    -1,   159,    15,   158,
      -1,   159,    36,   158,    -1,   159,    -1,   160,   110,   159,
      -1,   160,   115,   159,    -1,   160,   116,   159,    -1,   160,
      -1,   161,   112,   160,    -1,   161,   113,   160,    -1,   161,
      -1,   162,    24,   161,    -1,   162,    25,   161,    -1,   162,
      -1,   163,   107,   162,    -1,   163,   108,   162,    -1,   163,
      30,   162,    -1,   163,    31,   162,    -1,   163,    -1,   164,
      28,   163,    -1,   164,    29,   163,    -1,   164,    -1,   165,
     111,   164,    -1,   165,    -1,   166,   117,   165,    -1,   166,
      -1,   167,   118,   166,    -1,   167,    -1,   168,    32,   167,
      -1,   168,    -1,   169,    33,   168,    -1,   169,    -1,   169,
     119,   173,   120,   171,    -1,   170,    -1,   169,   172,   171,
      -1,   270,    -1,   121,    -1,    18,    -1,    19,    -1,    20,
      -1,    16,    -1,    17,    -1,    26,    -1,    27,    -1,    22,
      -1,    21,    -1,    23,    -1,   171,    -1,   173,   109,   171,
      -1,   170,    -1,   176,    -1,   177,    -1,   178,    -1,   180,
      -1,   182,    -1,   184,    -1,   185,    -1,   265,    -1,   134,
     120,   175,    -1,    42,   174,   120,   175,    -1,    49,   120,
     175,    -1,   280,   122,    -1,   123,   281,   124,    -1,   175,
      -1,   179,   175,    -1,    64,   101,   181,   102,   175,    -1,
      64,   101,   181,   102,   175,    54,   175,    -1,    84,   101,
     181,   102,   175,    -1,   173,    -1,   223,   216,   121,   171,
      -1,   100,   101,   181,   102,   175,    -1,    51,   175,   100,
     101,   173,   102,   122,    -1,    61,   101,   183,   282,   122,
     280,   102,   175,    -1,   177,    -1,   189,    -1,    41,   122,
      -1,    48,   122,    -1,    77,   280,   122,    -1,    63,   134,
     122,    -1,   188,    -1,   187,    -1,   186,   187,    -1,   188,
      -1,   229,    -1,   256,    -1,   263,    -1,   264,    -1,   213,
      -1,   202,    -1,   189,    -1,   212,    -1,   208,    -1,   210,
      -1,   211,    -1,   191,   214,   122,    -1,   191,   122,    -1,
     192,    -1,   194,    -1,   193,    -1,    62,    -1,    90,    -1,
     190,    -1,   191,   190,    -1,    39,    -1,    75,    -1,    81,
      -1,    58,    -1,    68,    -1,    65,    -1,    96,    -1,    56,
      -1,   195,    -1,   234,    -1,   198,    -1,   197,    -1,   220,
      -1,   196,    -1,   146,   196,    -1,    14,   274,   196,    -1,
      44,    -1,    99,    -1,    40,    -1,    78,    -1,    66,    -1,
      67,    -1,    79,    -1,    94,    -1,    60,    -1,    52,    -1,
      97,    -1,   131,    -1,   132,    -1,   128,    -1,   236,    14,
     146,   134,    -1,   236,    14,   134,    -1,    55,    14,   146,
     134,    -1,    55,    14,   134,    -1,    55,   146,   134,    -1,
      92,   276,   146,   134,    -1,    92,   276,   146,   134,   107,
     261,   108,    -1,    55,   134,   123,   283,   124,    -1,   200,
      -1,   199,   109,   200,    -1,   201,    -1,   201,   121,   174,
      -1,   134,    -1,   203,    -1,   206,    -1,   204,    -1,   205,
      -1,    69,   134,   123,   207,   124,    -1,    69,   130,   123,
     207,   124,    -1,    69,   123,   207,   124,    -1,   273,    -1,
      69,   134,   121,   209,   122,    -1,    14,   146,   129,    -1,
      14,   129,    -1,   146,   129,    -1,   129,    -1,    95,    92,
      14,   146,   144,   122,    -1,    95,    92,   146,   144,   122,
      -1,    95,    14,   146,   144,   122,    -1,    95,   146,   144,
     122,    -1,    95,    14,   144,   122,    -1,    95,    69,    14,
     146,   129,   122,    -1,    95,    69,    14,   129,   122,    -1,
      95,    69,   146,   129,   122,    -1,    95,    69,   129,   122,
      -1,    38,   101,   139,   102,   122,    -1,    58,   139,   123,
     273,   124,    -1,    58,   139,   187,    -1,   215,    -1,   214,
     109,   215,    -1,   216,   284,    -1,   217,    -1,   218,   216,
      -1,   221,    -1,   217,   101,   226,   102,   219,   271,    -1,
     217,   101,   226,   102,   219,    -1,   217,   101,   226,   102,
     271,    -1,   217,   101,   226,   102,    -1,    10,   101,   226,
     102,    -1,    10,    14,   221,   101,   226,   102,    -1,    10,
      14,    10,   101,   226,   102,    -1,   217,   104,   285,   105,
      -1,   101,   216,   102,    -1,   110,    -1,   110,   219,    -1,
     111,    -1,   146,   110,    -1,   146,   110,   219,    -1,    14,
     146,   110,    -1,    14,   146,   110,   219,    -1,   220,    -1,
     220,   219,    -1,    46,    -1,    98,    -1,   143,    -1,    14,
     143,    -1,    14,   146,   196,    -1,    14,   196,    -1,   223,
     286,    -1,   194,   287,    -1,   218,   286,    -1,   225,    -1,
     288,   101,   226,   102,   219,   271,    -1,   288,   101,   226,
     102,   219,    -1,   288,   101,   226,   102,   271,    -1,   288,
     101,   226,   102,    -1,   288,   104,   285,   105,    -1,   101,
     224,   102,    -1,   227,    13,    -1,   227,    -1,    13,    -1,
      -1,   227,   109,    13,    -1,   228,    -1,   227,   109,   228,
      -1,   191,   216,    -1,   191,   216,   121,   171,    -1,   191,
     286,    -1,   191,   286,   121,   171,    -1,   216,   289,   230,
      -1,   191,   216,   289,   230,    -1,   216,   266,    -1,   191,
     216,   266,    -1,   178,    -1,   121,   232,    -1,   101,   148,
     102,    -1,   171,    -1,   123,   233,   290,   124,    -1,   123,
     124,    -1,   232,    -1,   233,   109,   232,    -1,   235,   123,
     291,   124,    -1,   236,   134,    -1,   236,   134,   243,    -1,
     236,   146,   134,    -1,   236,   146,   134,   243,    -1,    45,
      -1,    83,    -1,    93,    -1,   238,   291,    -1,   246,   120,
     291,    -1,   191,   239,   122,    -1,   191,   122,    -1,   239,
     122,    -1,   122,    -1,   229,   292,    -1,   145,   122,    -1,
     210,    -1,   256,    -1,   240,    -1,   239,   109,   240,    -1,
      -1,   216,    -1,   216,   241,    -1,   216,   242,    -1,   134,
     120,   174,    -1,   121,   125,    -1,   121,   174,    -1,   120,
     244,    -1,   245,    -1,   244,   109,   245,    -1,    14,   146,
     131,    -1,    14,   131,    -1,   146,   131,    -1,   131,    -1,
      96,   246,    14,   274,   131,    -1,    96,   246,   274,   131,
      -1,    96,    14,   274,   131,    -1,    96,   274,   131,    -1,
     246,    96,    14,   274,   131,    -1,   246,    96,   274,   131,
      -1,   246,    14,   274,   131,    -1,   246,   274,   131,    -1,
      72,    -1,    73,    -1,    74,    -1,    71,   248,    -1,   223,
     293,    -1,   218,   293,    -1,   120,   251,    -1,   252,    -1,
     252,   109,   251,    -1,   253,   101,   275,   102,    -1,    14,
     146,   131,    -1,    14,   131,    -1,   146,   131,    -1,   131,
      -1,   134,    -1,    71,   255,    -1,    70,    -1,    50,    -1,
      70,   104,   105,    -1,    50,   104,   105,    -1,   112,    -1,
     126,    -1,   110,    -1,   115,    -1,   116,    -1,   117,    -1,
     111,    -1,   118,    -1,   103,    -1,   114,    -1,   121,    -1,
     107,    -1,   108,    -1,    16,    -1,    17,    -1,    18,    -1,
      19,    -1,    20,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    25,    -1,    26,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,   109,    -1,    36,    -1,    37,    -1,
     101,   102,    -1,   104,   105,    -1,   294,    85,   107,   257,
     108,   187,    -1,   258,    -1,   257,   109,   258,    -1,   259,
      -1,   228,    -1,    45,   134,    -1,    45,   134,   121,   222,
      -1,    92,   134,    -1,    92,   134,   121,   222,    -1,    85,
     107,   257,   108,    45,   134,    -1,    85,   107,   257,   108,
      45,   134,   121,   133,    -1,   133,   107,   261,   108,    -1,
     262,    -1,   261,   109,   262,    -1,   171,    -1,   222,    -1,
     133,    -1,    85,   187,    -1,    85,   107,   108,   187,    -1,
      89,   178,   267,    -1,    89,   289,   230,   267,    -1,   268,
     295,    -1,    43,   101,   269,   102,   178,    -1,   223,   216,
      -1,   223,   224,    -1,   223,    -1,    13,    -1,    87,   296,
      -1,    87,   101,   297,   102,    -1,   222,    -1,   272,   109,
     222,    -1,    -1,   186,    -1,    -1,   146,    -1,    -1,   148,
      -1,    -1,    14,    -1,    -1,   152,    -1,    -1,   156,    -1,
      -1,   154,    -1,    -1,   173,    -1,    -1,   179,    -1,    -1,
     181,    -1,    -1,   199,    -1,    -1,   231,    -1,    -1,   174,
      -1,    -1,   224,    -1,    -1,   223,    -1,    -1,   225,    -1,
      -1,   250,    -1,    -1,   109,    -1,    -1,   237,    -1,    -1,
     122,    -1,    -1,   249,    -1,    -1,    57,    -1,    -1,   267,
      -1,    -1,   171,    -1,    -1,   272,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    98,   103,   108,   109,   114,   119,   127,
     131,   132,   133,   134,   135,   139,   143,   147,   151,   155,
     156,   164,   172,   173,   174,   175,   179,   180,   184,   185,
     186,   187,   191,   192,   196,   198,   199,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   225,   226,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   243,   244,
     245,   246,   250,   251,   252,   253,   257,   261,   265,   266,
     270,   271,   275,   279,   280,   281,   282,   286,   287,   291,
     292,   293,   297,   298,   299,   300,   304,   305,   306,   310,
     311,   312,   316,   317,   318,   319,   320,   324,   325,   326,
     330,   331,   335,   336,   340,   341,   345,   346,   350,   351,
     355,   356,   360,   361,   362,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   380,   381,   385,   393,
     394,   395,   396,   397,   398,   399,   400,   404,   405,   406,
     410,   414,   418,   419,   423,   424,   425,   429,   430,   434,
     435,   436,   440,   441,   445,   446,   447,   448,   452,   460,
     461,   465,   466,   467,   468,   469,   470,   471,   475,   476,
     477,   478,   479,   483,   484,   488,   489,   490,   491,   492,
     496,   497,   501,   502,   503,   504,   505,   509,   510,   511,
     515,   516,   517,   518,   519,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   540,
     541,   542,   546,   547,   548,   549,   550,   551,   552,   562,
     566,   567,   571,   572,   576,   591,   592,   596,   597,   601,
     605,   609,   613,   623,   627,   628,   629,   630,   634,   635,
     636,   637,   638,   642,   643,   644,   645,   649,   653,   654,
     662,   663,   667,   671,   672,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   689,   690,   691,   692,   693,
     694,   695,   699,   700,   704,   705,   709,   710,   711,   712,
     716,   720,   724,   725,   729,   730,   731,   732,   733,   734,
     738,   739,   740,   741,   742,   746,   747,   751,   752,   753,
     754,   758,   759,   760,   761,   765,   769,   770,   774,   775,
     776,   780,   781,   789,   793,   794,   795,   796,   800,   801,
     802,   806,   807,   811,   812,   813,   814,   815,   816,   817,
     818,   822,   823,   826,   827,   828,   829,   830,   839,   843,
     851,   855,   856,   860,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,   871,   875,   876,   877,   885,   889,
     893,   897,   901,   902,   906,   910,   911,   912,   913,   914,
     922,   926,   927,   928,   929,   930,   931,   932,   933,   934,
     935,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   975,   979,   980,   984,   985,   989,   990,
     991,   992,   993,   994,   998,  1002,  1003,  1007,  1008,  1009,
    1013,  1017,  1025,  1029,  1033,  1037,  1041,  1042,  1043,  1044,
    1048,  1052,  1056,  1057,  1064,  1066,  1069,  1071,  1074,  1076,
    1079,  1081,  1084,  1086,  1089,  1091,  1094,  1096,  1099,  1101,
    1104,  1106,  1109,  1111,  1114,  1116,  1119,  1121,  1124,  1126,
    1129,  1131,  1134,  1136,  1139,  1141,  1144,  1146,  1149,  1151,
    1154,  1156,  1159,  1161,  1164,  1166,  1169,  1171,  1174,  1176,
    1179,  1181,  1184,  1186
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER", "FLOATING",
  "CHARACTER", "STRING", "TYPEDEF_NAME", "NAMESPACE_NAME", "CLASS_NAME",
  "ENUM_NAME", "TEMPLATE_NAME", "ELLIPSIS", "COLONCOLON", "DOTSTAR",
  "ADDEQ", "SUBEQ", "MULEQ", "DIVEQ", "MODEQ", "XOREQ", "ANDEQ", "OREQ",
  "SL", "SR", "SREQ", "SLEQ", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND",
  "OROR", "PLUSPLUS", "MINUSMINUS", "ARROWSTAR", "ARROW", "ASM", "AUTO",
  "BOOL", "BREAK", "CASE", "CATCH", "CHAR", "CLASS", "CONST", "CONST_CAST",
  "CONTINUE", "DEFAULT", "DELETE", "DO", "DOUBLE", "DYNAMIC_CAST", "ELSE",
  "ENUM", "EXPLICIT", "EXPORT", "EXTERN", "FALSE", "FLOAT", "FOR",
  "FRIEND", "GOTO", "IF", "INLINE", "INT", "LONG", "MUTABLE", "NAMESPACE",
  "NEW", "OPERATOR", "PRIVATE", "PROTECTED", "PUBLIC", "REGISTER",
  "REINTERPRET_CAST", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STATIC_CAST", "STRUCT", "SWITCH", "TEMPLATE", "THIS", "THROW", "TRUE",
  "TRY", "TYPEDEF", "TYPEID", "TYPENAME", "UNION", "UNSIGNED", "USING",
  "VIRTUAL", "VOID", "VOLATILE", "WCHAR_T", "WHILE", "'('", "')'", "'~'",
  "'['", "']'", "'.'", "'<'", "'>'", "','", "'*'", "'&'", "'+'", "'-'",
  "'!'", "'/'", "'%'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "'0'", "'_'", "$accept", "typedef_name", "namespace_name",
  "original_namespace_name", "class_name", "enum_name", "template_name",
  "identifier", "literal", "integer_literal", "character_literal",
  "floating_literal", "string_literal", "boolean_literal",
  "translation_unit", "primary_expression", "id_expression",
  "unqualified_id", "qualified_id", "nested_name_specifier",
  "postfix_expression", "expression_list", "unary_expression",
  "unary_operator", "new_expression", "new_placement", "new_type_id",
  "new_declarator", "direct_new_declarator", "new_initializer",
  "delete_expression", "cast_expression", "pm_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "statement", "labeled_statement",
  "expression_statement", "compound_statement", "statement_seq",
  "selection_statement", "condition", "iteration_statement",
  "for_init_statement", "jump_statement", "declaration_statement",
  "declaration_seq", "declaration", "block_declaration",
  "simple_declaration", "decl_specifier", "decl_specifier_seq",
  "storage_class_specifier", "function_specifier", "type_specifier",
  "simple_type_specifier", "type_name", "elaborated_type_specifier",
  "enum_specifier", "enumerator_list", "enumerator_definition",
  "enumerator", "namespace_definition", "named_namespace_definition",
  "original_namespace_definition", "extension_namespace_definition",
  "unnamed_namespace_definition", "namespace_body",
  "namespace_alias_definition", "qualified_namespace_specifier",
  "using_declaration", "using_directive", "asm_definition",
  "linkage_specification", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "ptr_operator", "cv_qualifier_seq",
  "cv_qualifier", "declarator_id", "type_id", "type_specifier_seq",
  "abstract_declarator", "direct_abstract_declarator",
  "parameter_declaration_clause", "parameter_declaration_list",
  "parameter_declaration", "function_definition", "function_body",
  "initializer", "initializer_clause", "initializer_list",
  "class_specifier", "class_head", "class_key", "member_specification",
  "member_declaration", "member_declarator_list", "member_declarator",
  "pure_specifier", "constant_initializer", "base_clause",
  "base_specifier_list", "base_specifier", "access_specifier",
  "conversion_function_id", "conversion_type_id", "conversion_declarator",
  "ctor_initializer", "mem_initializer_list", "mem_initializer",
  "mem_initializer_id", "operator_function_id", "operator",
  "template_declaration", "template_parameter_list", "template_parameter",
  "type_parameter", "template_id", "template_argument_list",
  "template_argument", "explicit_instantiation", "explicit_specialization",
  "try_block", "function_try_block", "handler_seq", "handler",
  "exception_declaration", "throw_expression", "exception_specification",
  "type_id_list", "declaration_seq_opt", "nested_name_specifier_opt",
  "expression_list_opt", "COLONCOLON_opt", "new_placement_opt",
  "new_initializer_opt", "new_declarator_opt", "expression_opt",
  "statement_seq_opt", "condition_opt", "enumerator_list_opt",
  "initializer_opt", "constant_expression_opt", "abstract_declarator_opt",
  "type_specifier_seq_opt", "direct_abstract_declarator_opt",
  "ctor_initializer_opt", "COMMA_opt", "member_specification_opt",
  "SEMICOLON_opt", "conversion_declarator_opt", "EXPORT_opt",
  "handler_seq_opt", "assignment_expression_opt", "type_id_list_opt", 0
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
     355,    40,    41,   126,    91,    93,    46,    60,    62,    44,
      42,    38,    43,    45,    33,    47,    37,    94,   124,    63,
      58,    61,    59,   123,   125,    48,    95
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   127,   128,   129,   130,   131,   131,   132,   133,   134,
     135,   135,   135,   135,   135,   136,   137,   138,   139,   140,
     140,   141,   142,   142,   142,   142,   143,   143,   144,   144,
     144,   144,   145,   145,   146,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   150,   150,
     150,   150,   151,   151,   151,   151,   152,   153,   154,   154,
     155,   155,   156,   157,   157,   157,   157,   158,   158,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   161,   162,
     162,   162,   163,   163,   163,   163,   163,   164,   164,   164,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   171,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   173,   173,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   176,   176,   176,
     177,   178,   179,   179,   180,   180,   180,   181,   181,   182,
     182,   182,   183,   183,   184,   184,   184,   184,   185,   186,
     186,   187,   187,   187,   187,   187,   187,   187,   188,   188,
     188,   188,   188,   189,   189,   190,   190,   190,   190,   190,
     191,   191,   192,   192,   192,   192,   192,   193,   193,   193,
     194,   194,   194,   194,   194,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   196,
     196,   196,   197,   197,   197,   197,   197,   197,   197,   198,
     199,   199,   200,   200,   201,   202,   202,   203,   203,   204,
     205,   206,   207,   208,   209,   209,   209,   209,   210,   210,
     210,   210,   210,   211,   211,   211,   211,   212,   213,   213,
     214,   214,   215,   216,   216,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   218,   218,   218,   218,   218,
     218,   218,   219,   219,   220,   220,   221,   221,   221,   221,
     222,   223,   224,   224,   225,   225,   225,   225,   225,   225,
     226,   226,   226,   226,   226,   227,   227,   228,   228,   228,
     228,   229,   229,   229,   229,   230,   231,   231,   232,   232,
     232,   233,   233,   234,   235,   235,   235,   235,   236,   236,
     236,   237,   237,   238,   238,   238,   238,   238,   238,   238,
     238,   239,   239,   240,   240,   240,   240,   240,   241,   242,
     243,   244,   244,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   246,   246,   246,   247,   248,
     249,   250,   251,   251,   252,   253,   253,   253,   253,   253,
     254,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   256,   257,   257,   258,   258,   259,   259,
     259,   259,   259,   259,   260,   261,   261,   262,   262,   262,
     263,   264,   265,   266,   267,   268,   269,   269,   269,   269,
     270,   271,   272,   272,   273,   273,   274,   274,   275,   275,
     276,   276,   277,   277,   278,   278,   279,   279,   280,   280,
     281,   281,   282,   282,   283,   283,   284,   284,   285,   285,
     286,   286,   287,   287,   288,   288,   289,   289,   290,   290,
     291,   291,   292,   292,   293,   293,   294,   294,   295,   295,
     296,   296,   297,   297
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     3,     6,     2,     2,     1,     4,     4,
       5,     4,     4,     3,     5,     4,     4,     3,     2,     2,
       7,     7,     7,     7,     4,     4,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     4,     5,     6,     7,     3,     2,     2,     1,
       3,     4,     3,     2,     3,     4,     5,     1,     4,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       2,     3,     1,     2,     5,     7,     5,     1,     4,     5,
       7,     8,     1,     1,     2,     2,     3,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     4,     7,     5,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     5,
       5,     4,     1,     5,     3,     2,     2,     1,     6,     5,
       5,     4,     4,     6,     5,     5,     4,     5,     5,     3,
       1,     3,     2,     1,     2,     1,     6,     5,     5,     4,
       4,     6,     6,     4,     3,     1,     2,     1,     2,     3,
       3,     4,     1,     2,     1,     1,     1,     2,     3,     2,
       2,     2,     2,     1,     6,     5,     5,     4,     4,     3,
       2,     1,     1,     0,     3,     1,     3,     2,     4,     2,
       4,     3,     4,     2,     3,     1,     2,     3,     1,     4,
       2,     1,     3,     4,     2,     3,     3,     4,     1,     1,
       1,     2,     3,     3,     2,     2,     1,     2,     2,     1,
       1,     1,     3,     0,     1,     2,     2,     3,     2,     2,
       2,     1,     3,     3,     2,     2,     1,     5,     4,     4,
       3,     5,     4,     4,     3,     1,     1,     1,     2,     2,
       2,     2,     1,     3,     4,     3,     2,     2,     1,     1,
       2,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     6,     1,     3,     1,     1,     2,     4,
       2,     4,     6,     8,     4,     1,     3,     1,     1,     1,
       2,     4,     3,     4,     2,     5,     2,     2,     1,     1,
       2,     4,     1,     3,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1,     0,     1,     0,     1,     0,     1,
       0,     1,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     454,     9,     2,     4,     5,     7,     8,     0,     0,   192,
     210,   208,   328,   284,   217,     0,   199,   497,   195,   216,
     188,   197,   212,   213,   196,     0,     0,   193,   211,   214,
     194,   329,     0,   189,   460,   330,   215,     0,   198,   218,
     285,   209,     0,     0,   275,   277,   221,     0,     3,   219,
     220,     0,    28,     0,   286,    26,    27,     0,   455,   169,
     171,   178,   190,     0,   185,   187,   186,   200,   205,   203,
     202,   177,   235,   237,   238,   236,   180,   181,   182,   179,
     176,   486,   263,     0,   204,   265,   172,   201,     0,     0,
      30,    29,   173,     6,   174,   175,    21,     0,     0,   303,
       5,   287,     0,   289,     0,     0,     0,     0,     0,     0,
      18,     0,   454,     0,     0,   456,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   419,   420,   382,   381,
       0,   393,     0,   396,   397,   418,   387,   391,   385,   394,
     388,   389,   390,   392,   395,   386,     0,   482,   494,   368,
     380,     0,   440,   461,     0,     0,     0,     0,     0,     0,
       0,     0,    31,   276,   282,    36,    35,     0,     1,     0,
     278,   219,    32,   206,   170,   195,   184,   191,     0,   260,
     476,   486,     0,   487,   313,     0,   303,   478,   264,   343,
       0,   324,     0,     0,     5,     0,     0,     0,   302,   480,
       0,   301,   305,   280,   288,   207,     0,   225,     0,   474,
     226,   454,   259,     0,   242,   454,     0,   454,   457,     0,
       0,   421,   422,   483,   291,     0,     0,   494,   495,   369,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,   283,     0,    15,    17,    16,   456,     0,     0,
       0,     0,     0,    20,   462,     0,     0,     0,    23,   500,
      19,     0,     0,    71,     0,     0,    68,    69,    70,   439,
      22,    10,    11,    12,    13,    14,    37,    25,     0,    58,
      87,     0,    66,    67,    89,    92,    96,    99,   102,   107,
     110,   112,   114,   116,   118,   120,   122,   437,   438,   480,
       0,   435,   124,    33,   279,     0,   183,     0,     0,   477,
     314,   262,     0,     0,     0,   378,   379,     0,   371,   372,
       0,   468,   315,   311,     0,     0,   120,   138,   479,     0,
     365,   366,   367,     0,   336,    28,    27,   343,   339,   344,
     492,   491,   343,     0,   341,     0,   340,     0,   223,     0,
       0,   325,   326,     0,   303,     0,   303,   484,   307,   480,
     481,   293,   309,     0,   270,   300,     0,   281,     0,   224,
     234,   475,   230,   232,     0,     0,   241,     0,     0,   247,
       0,     0,     0,   384,   383,     0,   370,   441,   227,   252,
       0,     0,     0,   256,     0,     0,     0,   251,     0,     0,
     462,    59,    60,     0,     0,    83,     0,     0,   463,     0,
       0,     0,    64,     0,   501,   450,     0,   136,     0,     0,
      61,    62,    48,    49,     0,   458,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     126,   127,   128,   134,   133,   135,   131,   132,     0,     0,
     125,     0,   484,   480,   290,   434,     0,   261,   476,     0,
      56,     0,   318,   316,   312,     0,   376,     0,   377,     0,
     458,     0,     0,     0,     0,   468,     0,     0,     0,     0,
     468,     0,     0,     0,    28,   469,   152,   139,   140,   141,
     468,   142,   143,   144,   145,   168,     0,   146,     0,     0,
     269,   273,     0,   338,   334,   344,     0,     0,   345,   346,
     493,   337,   331,   343,   335,   343,   323,   222,     0,     0,
     356,     0,   350,   351,     0,   327,   328,     0,   460,   427,
       0,   424,   426,     0,     0,     0,     0,   292,     0,   303,
     478,   304,   306,   257,     0,     0,   229,   258,   240,   245,
       0,   246,   243,   239,     0,   250,   254,     0,   255,     0,
     249,     0,     0,    84,     0,     0,     0,     0,     0,     0,
     464,   466,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,    47,   459,     0,     0,     0,     0,    43,    90,
      91,    93,    94,    95,    97,    98,   100,   101,   105,   106,
     103,   104,   108,   109,   111,   113,   115,   117,   119,     0,
     123,   436,   317,     0,   320,   321,   488,     0,   443,   498,
     375,   373,     0,   164,     0,   165,   468,     0,   468,     0,
       0,     0,     0,     0,     0,     0,   468,   153,   150,   151,
       0,   267,   268,   347,   333,   348,   349,   344,   342,   332,
     354,     0,     0,     0,     0,   355,     0,     0,     0,     0,
     428,     0,   430,     0,     0,   272,   271,   299,   308,   310,
       0,     0,   231,   233,   244,     0,   253,   248,    34,     0,
       0,   464,     0,    85,     0,    76,     0,   458,   465,    72,
       0,   467,    79,   466,    77,     0,    65,     0,    54,    55,
     137,    88,    46,     0,    45,    39,    38,    42,     0,    41,
       0,    57,   489,     0,     0,   499,   444,   374,   468,   149,
       0,   162,   472,   163,   167,   157,     0,     0,   166,     0,
     442,     0,   147,   502,   266,   353,     0,     0,     0,   360,
     352,     0,     0,     0,   364,     0,     0,     0,   423,   425,
     297,   298,   228,    86,     0,    73,     0,     0,   464,     0,
       0,     0,    78,     0,     0,    44,    40,   121,   322,   319,
     449,   448,     0,   148,     0,   473,     0,   468,     0,   468,
     468,   452,   503,     0,   359,     0,   358,   363,     0,   362,
     429,     0,   431,   295,   296,   464,     0,     0,    74,    82,
      80,     0,     0,     0,   446,   447,     0,     0,   468,   154,
       0,   156,   159,     0,   451,   357,   361,     0,   294,    75,
      53,    50,    81,    52,    51,   445,     0,     0,   468,   158,
     453,   432,   160,   468,   155,     0,   161,   433
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    46,    47,    48,   107,    50,    51,    52,   280,   281,
     282,   283,   284,   285,    53,   286,   287,    55,    56,   206,
     289,   603,   290,   291,   292,   418,   590,   711,   712,   708,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   427,   471,   505,   338,   506,   507,
     508,   509,   510,   511,   746,   512,   742,   513,   514,    58,
      59,   515,    61,    62,   516,    64,    65,    66,    67,    68,
      69,    70,   381,   382,   383,    71,    72,    73,    74,    75,
     223,    76,   391,    77,    78,    79,    80,   188,   189,    81,
      82,    83,   173,    84,    85,   308,   309,   370,   371,   210,
     211,   212,    86,   333,   319,   483,   636,    87,    88,    89,
     351,   352,   353,   354,   528,   529,   361,   542,   543,   355,
      90,   159,   238,   193,   328,   329,   330,    91,   160,    92,
     550,   551,   552,    93,   310,   311,    94,    95,   517,   194,
     638,   639,   792,   312,   662,   802,   224,   104,   604,   164,
     419,   709,   714,   518,   519,   796,   384,   321,   339,   557,
     234,   373,   195,   733,   357,   531,   239,    97,   736,   425,
     803
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -672
static const yytype_int16 yypact[] =
{
    3334,  -672,  -672,  -672,    30,  -672,  -672,   567,    -1,  -672,
    -672,  -672,  -672,  -672,  -672,   684,  -672,  -672,    66,  -672,
    -672,  -672,  -672,  -672,  -672,    37,  2517,  -672,  -672,  -672,
    -672,  -672,  3229,  -672,    96,  -672,  -672,   727,  -672,  -672,
    -672,  -672,   482,   112,    10,  -672,  -672,   115,  -672,   135,
    -672,    47,  -672,   173,  -672,  -672,  -672,   419,  3334,  -672,
    -672,  -672,  -672,  2306,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,   -36,   236,   482,  -672,  -672,  -672,  -672,    65,   812,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,   128,   279,  3638,
    -672,  -672,   957,  -672,   424,    66,   374,   135,   120,   228,
    -672,  2110,  3334,   154,   144,   347,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   200,   209,
     183,  -672,   231,  -672,  -672,  -672,  -672,  -672,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,   424,  3944,   104,  -672,
    -672,   262,  -672,  -672,   347,   130,   518,   587,    48,   567,
      20,   285,  -672,  -672,    10,  -672,   347,  2753,  -672,    48,
      10,  -672,  -672,  -672,  -672,  -672,  -672,  -672,   -43,  -672,
     651,   274,   993,  -672,  -672,   284,  3638,  3103,  -672,  1763,
     374,   325,   228,   343,   313,   567,   147,   356,  -672,  3438,
     358,    62,  -672,    10,  -672,  -672,   362,  -672,   228,   228,
    -672,  3334,  -672,   342,  -672,  3334,   635,  3334,  -672,   381,
     388,  -672,  -672,  -672,  -672,   347,   387,   104,  -672,  -672,
    3334,   228,   349,    48,   347,    21,   494,   347,    48,   385,
     957,  -672,  -672,   494,  -672,  -672,  -672,   429,  3103,  3103,
     416,  2865,   427,  -672,   440,   436,  3117,   444,  -672,  2977,
    -672,   446,  2753,   112,  3103,  3103,  -672,  -672,  -672,    47,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  1019,   229,
    -672,  3103,  -672,  -672,  -672,    46,   113,   233,   303,    72,
     294,   447,   443,   439,   532,  1197,  -672,  -672,  -672,   614,
     316,  -672,  -672,  -672,  -672,   482,  -672,  2977,  2220,  -672,
    -672,  -672,   284,   284,   347,   135,  -672,   112,  -672,   457,
     468,  1486,  -672,  -672,   478,    18,    17,  -672,  -672,   477,
    -672,  -672,  -672,   298,  -672,   467,   466,  2410,  -672,   326,
     476,  -672,  1763,   -37,  -672,   480,  -672,   479,  -672,   228,
     499,  -672,   325,  3700,  3638,  1019,  3638,   879,   484,   835,
    -672,   277,   498,   307,  -672,  -672,  3792,  -672,   493,  -672,
    -672,   516,  -672,   508,   507,   510,  -672,   512,   347,   115,
     494,   515,   519,  -672,  -672,   530,  -672,  -672,   544,  -672,
     536,    40,   494,  -672,   538,    48,   541,  -672,   638,  2991,
     440,  -672,  -672,  3944,   549,  -672,  3944,  2977,  -672,  3515,
    3944,  2753,  -672,  3944,  -672,  -672,  2753,  -672,   -31,   564,
    -672,  -672,  -672,  -672,   863,  2977,  2977,  1035,  -672,  3103,
    3103,  3103,  3103,  3103,  3103,  3103,  3103,  3103,  3103,  3103,
    3103,  3103,  3103,  3103,  3103,  3103,  3103,  3103,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,  -672,  -672,  3103,  2977,
    -672,  2977,    83,   614,  -672,  -672,  2753,  -672,   -25,    23,
    -672,  1872,  -672,  -672,  -672,   628,   135,   112,  -672,   993,
    2977,   547,  3103,   553,   565,  1994,   585,   228,   588,   228,
    2977,   589,   284,   590,   575,   594,  -672,  -672,  -672,  -672,
    1646,  -672,  -672,  -672,  -672,  -672,  2306,  -672,   577,   582,
      99,  -672,  3103,  -672,  -672,   326,   -28,  1330,  -672,  -672,
    -672,  -672,  -672,   482,  -672,  1763,  -672,  -672,   347,   540,
     135,   112,   599,  -672,   289,  -672,   228,   605,    87,  -672,
     345,  -672,  -672,   615,   618,   621,  2977,  -672,  2977,  3638,
    3103,  -672,  -672,  -672,   228,  3103,  -672,  -672,  -672,   115,
     494,  -672,  -672,  -672,  2753,  -672,  -672,   606,  -672,   611,
    -672,   347,   622,  -672,  3575,   627,  3103,   636,    81,  3944,
     645,   210,   642,   649,   652,   108,   657,  -672,  2977,  3103,
     130,   453,  -672,   661,   659,   136,   130,  1132,  -672,  -672,
    -672,    46,    46,    46,   113,   113,   233,   233,   303,   303,
     303,   303,    72,    72,   294,   447,   443,   439,   532,     8,
    -672,  -672,  -672,  2977,  -672,  -672,   666,   680,  -672,   628,
    -672,  -672,   686,  -672,   670,  -672,  1994,   695,  2641,   676,
    2753,   681,   679,  2753,   628,  2753,  1994,  -672,  -672,  -672,
     702,   717,  -672,  -672,  -672,  -672,  -672,   691,  -672,  -672,
     135,   112,   347,   754,   112,  -672,   499,   347,   804,   112,
     696,  3700,   699,  3334,  3700,  -672,  -672,  -672,  -672,  -672,
     725,   723,  -672,  -672,  -672,   361,  -672,  -672,  -672,  3103,
    3944,   645,   729,  -672,   733,  -672,   738,  2977,  -672,  -672,
    2977,  -672,   737,   210,  -672,   741,  -672,   742,  -672,  -672,
    -672,  -672,  -672,   130,  -672,  -672,  -672,  -672,   130,  -672,
    2977,  -672,  2220,   722,  3884,  -672,  -672,  -672,  1994,  -672,
     750,  -672,  2753,  -672,  -672,   594,   752,   482,  -672,   753,
    -672,   756,  -672,  3944,  -672,  -672,   112,   347,   112,  -672,
    -672,   112,   347,   112,  -672,  3944,   366,  3944,  -672,  -672,
      99,  -672,  -672,  -672,   758,  -672,  2977,  2977,   645,   759,
     150,  3103,  -672,  2977,  2977,  -672,  -672,  -672,  -672,  -672,
    -672,   835,   760,  -672,  2977,  -672,   734,  1994,   746,  1994,
    1994,  -672,   765,   761,  -672,   112,  -672,  -672,   112,  -672,
    -672,   831,  -672,   717,  -672,   645,   137,   152,  -672,  -672,
    -672,   773,   171,   181,  -672,  -672,   284,   217,  2977,   825,
    2977,  -672,  -672,  3944,  -672,  -672,  -672,   228,  -672,  -672,
    -672,  -672,  -672,  -672,  -672,  -672,   764,   778,  1994,  -672,
    -672,   762,  -672,  1994,  -672,   878,  -672,  -672
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -672,  -672,    16,   867,   505,  -672,  -176,   259,  -672,  -672,
    -672,  -672,    42,  -672,  -672,  -672,   912,   537,  -193,     0,
    -672,  -262,   629,  -672,  -672,  -672,   310,  -672,  -672,  -672,
    -672,   626,  -147,    38,    41,   -48,    49,   442,   448,   441,
     450,   430,  -148,  -117,  -165,  -672,  -258,  -479,    11,  -672,
     251,  -185,  -672,  -672,  -596,  -672,  -672,  -672,  -672,  -672,
     -24,     9,   256,   -61,   610,  -672,  -672,   363,  -672,   149,
    -672,  -672,  -672,   344,  -672,  -672,  -672,  -672,  -672,  -672,
     215,  -672,  -672,  -180,  -672,  -672,  -672,  -672,   595,   -18,
    -672,  -111,  -149,   -39,   811,  -145,   -23,  -363,  -672,  -179,
    -672,  -343,  -177,   223,  -672,  -453,  -672,  -672,  -672,  -672,
    -672,  -672,   566,   378,  -672,  -672,   552,  -672,   240,  -344,
    -672,  -672,  -672,  -672,   431,  -672,  -672,  -672,  -672,  -163,
     241,   239,  -672,  -672,   353,   454,  -672,  -672,  -672,  -172,
    -577,  -672,  -672,  -672,  -609,  -672,    27,  -470,  -469,  -672,
     522,  -671,   216,  -489,  -672,  -672,  -672,  -672,   373,  -139,
    -672,  -672,  -152,  -672,  -323,  -672,   698,  -672,  -672,  -672,
    -672
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -497
static const yytype_int16 yytable[] =
{
      57,   279,   187,   158,   555,   174,   346,   102,   162,    60,
     332,   652,   307,   644,   428,   109,   544,   334,   320,   348,
     549,   642,   350,     1,   171,   252,   156,    96,   635,   532,
     775,   314,    57,   562,   184,   175,   356,   168,   322,   323,
       1,    60,   170,   663,    98,   190,     3,   237,   666,   336,
     468,     1,   754,   191,   175,   479,    13,   749,    57,   751,
     111,   439,   735,    57,   377,   198,   315,    60,   409,   674,
     372,   597,   533,   110,   679,   375,   317,   750,   598,   316,
     337,   533,   440,   170,   192,   534,   693,   222,   410,   202,
       1,    26,     3,   100,   664,     6,   318,   235,   369,   156,
     105,   163,   448,   449,   424,   179,   218,   818,    40,   555,
     163,    57,    57,     3,   100,   228,     6,   598,   235,    26,
      60,    60,   100,    43,     6,   632,   237,   429,   730,   175,
     180,    99,   633,     1,   233,   174,   469,   332,   332,     3,
     100,   174,     6,   403,   839,    13,   795,   216,   187,   176,
       1,    43,   480,   482,   177,   588,   103,   156,   236,   346,
     112,   814,   576,   428,   241,   243,   246,   248,   595,   250,
     474,   376,   348,   178,   174,   350,   253,   288,   605,   450,
     451,   349,   245,   705,   472,   553,   660,   554,   199,   356,
     633,   368,   327,    44,    45,   673,   156,    40,   473,    57,
     359,    26,   756,   758,   838,   365,   183,   761,   763,    57,
     718,   629,   669,   203,    44,    45,   397,   598,    26,     3,
     100,    57,     6,   441,   235,    57,   390,    57,   442,   443,
      60,     1,   179,    43,    60,   395,    60,   236,   779,   840,
      57,   726,   389,   219,   402,   598,   598,   405,   385,    60,
      43,   214,   480,   215,   841,   820,   369,   228,   369,   598,
     401,   598,   404,   432,   433,   226,   434,   227,   585,   408,
     480,   587,   288,   843,   108,   592,   593,   225,   594,   788,
     598,   596,     1,   844,   114,   231,   187,   805,     3,   204,
     598,     6,   808,   205,   611,   612,   613,   478,     3,   100,
     279,     6,   821,   677,   229,   183,   630,     3,   100,   236,
       6,   307,   165,   230,   710,   170,   482,   654,   103,   846,
      44,    45,   452,   453,   487,   480,   598,   446,   447,   525,
     435,   288,   544,   436,   349,   437,   232,   196,   549,   847,
     197,   549,   346,   168,   336,   444,   445,    57,   201,   171,
      26,   198,    57,   320,   103,   348,     3,   100,   350,     6,
     541,   473,   473,   156,   156,   217,   156,   170,   220,   170,
     240,   661,   356,   322,   336,   337,   156,     1,  -485,   336,
     690,  -485,    43,     3,   100,   678,     6,   251,   570,   157,
     167,   688,   745,   689,   192,   745,   591,   745,   279,   214,
     618,   619,   620,   621,   569,   337,   571,   331,   559,   307,
     337,   560,   336,   156,   364,   191,   156,   336,   577,   156,
     156,   288,     1,   156,   475,   476,   288,     2,   825,   100,
       5,     6,     2,   720,   100,     5,     6,   183,     3,   100,
     387,     6,   392,   337,   706,   360,   192,   527,   337,  -486,
     363,   326,   780,   683,   684,   187,     1,   366,   345,   358,
     374,   362,     3,   100,   378,     6,   386,   723,   731,   772,
     476,   399,   236,   236,   811,   684,   288,   379,   380,   409,
     713,   174,   614,   615,   745,     1,   393,   616,   617,   327,
      26,     3,     4,   394,     6,   288,   169,   180,   478,   410,
     398,   622,   623,     3,   179,    49,   647,   407,     3,   100,
     288,     6,    49,   538,   214,   667,    57,   349,   816,   817,
     157,   657,    43,   413,    26,   822,   823,     3,   100,   180,
       6,    49,   244,   170,   416,    57,   827,    49,   671,   228,
     157,   417,   480,   420,   228,   484,   485,   426,   172,     3,
     100,   423,     6,    26,   672,   774,    43,   456,   454,   156,
     455,   591,   181,    49,   457,   787,   489,   482,    49,   490,
       1,   340,   341,   342,   288,     2,     3,   100,     5,     6,
     520,   698,   521,    42,   156,    43,   694,   522,   523,   156,
     504,   236,    44,    45,   182,   539,     3,   100,   530,     6,
     535,   247,   713,   536,    49,   556,   345,   181,   801,   181,
      63,   345,   340,   341,   342,   563,    49,    49,   537,   558,
     810,   813,   812,     3,   100,   564,     6,   747,   235,   565,
     747,   566,   747,   336,   567,   157,   568,   572,    26,   182,
     213,   845,    63,   573,     3,   100,   288,     6,   288,   388,
     288,   574,   581,   288,   586,   288,   288,   739,   575,   768,
     578,   181,    49,   580,   337,   849,   599,   752,    63,   643,
      43,   637,   228,   228,    49,   645,   541,   228,   228,   857,
     369,   156,    49,    57,   156,   646,   648,     1,   850,   650,
     653,   655,    60,     3,   100,   656,     6,   325,   106,   658,
     156,    49,   242,   598,    49,   249,   659,   182,   676,   209,
      49,   791,   681,   236,    49,   472,   313,   685,  -484,   747,
     686,    63,    63,   687,    44,    45,    49,   699,   696,   798,
      49,   174,    49,   697,   156,   702,     3,   100,   288,     6,
     191,   165,   288,   182,   704,    49,   707,   170,   326,   793,
     715,   716,   317,   156,   504,   181,   649,   228,   651,   719,
     717,   725,   228,     3,   100,   156,     6,   156,   757,   504,
     633,   192,   318,   824,  -486,   732,   157,    49,   172,   157,
     400,   734,   157,   157,   157,   406,   157,   182,   737,   157,
     738,   170,   345,   181,   345,   740,   166,   288,   744,   288,
     288,   748,   226,   753,   660,   680,   209,   682,   829,   347,
     831,   832,   527,     3,   100,     1,     6,   765,   762,   167,
     767,     3,   100,   380,     6,   182,   200,   770,   771,   486,
     776,    63,   488,   156,   777,    63,    49,    63,     1,   157,
     778,   781,   783,   784,     3,     4,   789,     6,   288,   169,
      63,   794,    49,   288,   797,   799,   828,    49,   800,   854,
     815,   819,   826,   834,   856,   540,     1,   830,    49,    49,
     181,    49,     3,   100,   833,     6,   837,   600,   842,   848,
     853,    49,     1,   855,   411,   412,   852,   415,     3,     4,
       6,     6,   113,   169,   701,   422,   624,   626,   628,   741,
     430,   431,   182,   625,   743,   504,    26,   627,   692,   207,
     477,   668,    54,   526,   545,   504,   760,   438,    49,   101,
     641,    49,   766,   769,    49,    49,    49,   695,    49,   782,
     631,    49,   584,   691,    26,   396,   367,   157,    43,  -484,
       0,     0,   579,     0,    54,    44,    45,   157,   601,     0,
      26,     0,   157,     0,    54,     0,     0,     0,     0,     0,
       1,     0,   347,     0,     0,     2,    43,   100,     5,     6,
      54,     0,     0,   209,   209,    54,   209,     0,     0,     0,
     367,    49,    43,     0,     0,     0,   209,     0,     0,    44,
      45,     0,   640,     0,   325,    54,     1,   504,     0,     0,
      49,     0,     3,   100,     0,     6,     0,   324,     0,     0,
      54,     0,     0,   157,     0,    49,   157,     0,   157,     0,
       0,    49,     1,    54,    54,     0,     0,     2,    26,   100,
       5,     6,     0,     0,     0,   583,     0,     0,     1,     0,
      49,     0,   179,   670,     3,   100,   675,     6,     0,   606,
       0,     0,     0,     0,     0,     0,   504,     0,   504,   504,
      43,     0,     0,   157,    49,   609,   610,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,   101,     0,     0,     0,     0,     0,     0,     0,    49,
      26,     0,     0,     0,    49,     0,   851,   157,     0,     0,
       0,     0,     0,     0,   179,   157,    26,   504,     0,     0,
       0,    54,   504,     0,     0,     0,   157,   101,     0,     0,
     607,    54,    43,     0,     0,     0,     0,     0,   157,     0,
     157,     0,     0,    54,     0,     1,     0,    54,    43,    54,
       0,     3,   100,     0,     6,   347,   728,     0,     0,     0,
       0,    49,    54,    49,     0,    49,     0,     0,    49,     0,
      49,    49,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,     0,     0,     0,     0,   755,     0,     0,   759,
       0,   540,     0,     0,   764,     0,    49,     0,    49,    49,
       0,     0,     0,     0,     0,     0,   157,     0,     0,     0,
       0,     0,     0,    26,     0,    49,     0,     0,     0,     0,
       0,     0,   703,   458,   459,   460,   461,   462,   463,   464,
     465,     0,     0,   466,   467,   721,     0,    54,     0,     0,
     468,     0,     0,     0,     0,    43,     0,     0,     0,    49,
       0,     0,     0,    49,     0,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    54,
       0,   804,     0,   806,    54,     0,   807,     0,   809,     0,
      49,     0,    49,     0,     0,     0,     0,     0,     0,    54,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,    63,   209,     0,     0,     0,     0,     0,
       0,     0,    49,     0,    49,    49,     0,     0,     0,     0,
     835,     0,     0,   836,     0,     0,   469,     0,   470,     0,
       0,     0,     0,     0,     0,   773,     0,     0,     0,     0,
       0,     0,     0,     1,   254,   255,   256,   110,    49,     3,
     100,     0,     6,     0,   335,     0,   602,     0,     0,   608,
       0,     0,     0,    49,     0,     0,     0,     0,    49,     0,
       0,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,     0,
     261,     0,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,    26,     0,     0,     0,     0,   265,     0,     0,     0,
     266,     0,   267,     0,     0,     0,   268,     0,   270,     0,
       0,   271,     0,     0,     0,     0,     0,     0,    54,     0,
       0,   272,     0,   273,     0,     0,     0,     0,     0,     0,
     274,   275,   276,   277,   278,    54,     0,    54,     0,     0,
       0,     0,     0,     0,     0,   665,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
     254,   255,   256,   110,     2,     3,   100,     5,     6,     0,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   722,   724,     0,     0,     0,     0,   727,   729,
     258,   259,     0,     0,     8,     9,    10,   491,   492,     0,
      11,    12,    13,   260,   493,   494,   261,   495,    14,   262,
       0,    15,    16,     0,   185,   263,    19,   496,    20,   497,
     498,    21,    22,    23,    24,   499,   264,    26,     0,     0,
       0,    27,   265,   500,    28,    29,   266,    30,   267,    31,
     501,     0,   268,   269,   270,   502,    33,   271,    34,    35,
      36,    37,    38,    39,    40,    41,   503,   272,     0,   273,
       0,     0,     0,     0,     0,    54,   274,   275,   276,   277,
     278,     0,     0,     0,     0,     0,     0,     0,     0,   331,
    -470,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   785,     0,     0,     0,     0,
     786,     0,     0,     0,     0,     0,     0,     0,     0,     1,
     254,   255,   256,   110,     2,     3,   100,     5,     6,    54,
     257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     258,   259,     0,     0,     8,     9,    10,   491,   492,     0,
      11,    12,    13,   260,   493,   494,   261,   495,    14,   262,
       0,    15,    16,    54,   185,   263,    19,   496,    20,   497,
     498,    21,    22,    23,    24,   499,   264,    26,     0,     0,
       0,    27,   265,   500,    28,    29,   266,    30,   267,    31,
     501,     0,   268,   269,   270,   502,    33,   271,    34,    35,
      36,    37,    38,    39,    40,    41,   503,   272,     0,   273,
       0,     0,     0,     0,     0,     0,   274,   275,   276,   277,
     278,     0,     0,     0,     0,     0,     1,     0,     0,   331,
    -471,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,     0,     0,     0,    11,    12,    13,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
      17,   185,     0,    19,     0,    20,     0,     0,    21,    22,
      23,    24,     0,     0,    26,   340,   341,   342,    27,     0,
       0,    28,    29,     0,    30,     0,    31,     0,  -496,     0,
       0,     0,     0,    33,     0,    34,    35,    36,   343,    38,
      39,    40,    41,     0,    42,     0,    43,     0,     0,     0,
       0,     0,     0,    44,    45,     1,   254,   255,   256,   110,
       0,     3,   100,     0,     6,   344,   335,  -490,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   258,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   260,
       0,     0,   261,     0,     0,   262,     0,     0,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,    26,     0,     0,     0,     0,   265,     0,
       0,     0,   266,     0,   267,     0,     0,     0,   268,   269,
     270,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   272,     0,   273,     0,     0,     0,     0,
       0,     0,   274,   275,   276,   277,   278,     0,     0,     0,
       0,     0,     0,     0,     0,   481,   634,     1,   254,   255,
     256,   110,     2,     3,   100,     5,     6,     0,   257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   258,   259,
       0,     0,     8,     9,    10,   491,   492,     0,    11,    12,
      13,   260,   493,   494,   261,   495,    14,   262,     0,    15,
      16,     0,   185,   263,    19,   496,    20,   497,   498,    21,
      22,    23,    24,   499,   264,    26,     0,     0,     0,    27,
     265,   500,    28,    29,   266,    30,   267,    31,   501,     0,
     268,   269,   270,   502,    33,   271,    34,    35,    36,    37,
      38,    39,    40,    41,   503,   272,     0,   273,     0,     0,
       0,     0,     0,     0,   274,   275,   276,   277,   278,     0,
       0,     0,     0,     1,     0,     0,     0,   331,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,    17,    18,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,    25,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,    32,     0,     0,     0,     0,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
       0,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,    45,     0,     1,   254,   255,   256,   110,     0,     3,
     100,     0,     6,   221,   335,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260,     0,     0,
     261,     0,     0,   262,     0,     0,     0,     0,     0,   263,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     264,    26,     0,     0,     0,     0,   265,     0,     0,     0,
     266,     0,   267,     0,     0,     0,   268,   269,   270,     1,
       0,   271,     0,     0,     2,     3,     4,     5,     6,     0,
       7,   272,     0,   273,     0,     0,     0,     0,     0,     0,
     274,   275,   276,   277,   278,     0,     0,     0,     0,     0,
       0,     0,     0,   481,     0,     9,    10,     0,     0,     0,
      11,    12,    13,     0,     0,     0,     0,     0,    14,     0,
       0,    15,    16,     0,   185,     0,    19,     0,    20,     0,
       0,    21,    22,    23,    24,     0,     0,    26,     0,     0,
       0,    27,     0,     0,    28,    29,     0,    30,     0,    31,
       0,     0,     0,     0,     0,     0,    33,     0,    34,    35,
      36,     0,    38,    39,    40,    41,     0,    42,     0,    43,
       0,     0,     0,     1,     0,     0,    44,    45,     2,     3,
       4,     5,     6,     0,     7,     0,     0,     0,   186,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,     0,     0,     0,    11,    12,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,   185,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,     0,
       0,    26,     0,     0,     0,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,     0,     0,     0,     0,     0,
      33,     0,    34,    35,    36,     0,    38,    39,    40,    41,
       0,    42,     0,    43,     0,     0,     0,     0,     0,     0,
      44,    45,     0,     0,     0,     2,     3,   100,     5,     6,
       0,   115,   524,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,    10,     0,     0,
       0,    11,    12,    13,     0,     0,     0,   138,     0,    14,
       0,     0,    15,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,    22,    23,     0,     0,   139,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      35,    36,     0,     0,    39,    40,    41,     0,   140,     0,
     141,   142,     0,     0,   143,   144,   145,   146,   147,   148,
       0,   149,   150,   151,   152,   153,     0,     0,   154,     0,
       0,     0,     0,   155,     1,   254,   255,   256,   110,     2,
       3,   100,     5,     6,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,     0,     0,     0,
       9,    10,     0,     0,     0,    11,    12,    13,   260,     0,
       0,   261,     0,    14,   262,     0,    15,    16,     0,   185,
     263,    19,     0,    20,     0,     0,    21,    22,    23,    24,
       0,   264,    26,     0,     0,     0,    27,   265,     0,    28,
      29,   266,    30,   267,    31,     0,     0,   268,   269,   270,
       0,    33,   271,    34,    35,    36,     0,    38,    39,    40,
      41,     0,   272,     0,   273,     0,     0,     0,     0,     0,
       0,   274,   275,   276,   277,   278,     1,   254,   255,   256,
     110,     2,     3,   100,     5,     6,     0,   257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,    10,     0,     0,     0,    11,    12,    13,
     260,     0,     0,   261,     0,    14,   262,     0,    15,     0,
       0,     0,   263,    19,     0,     0,     0,     0,     0,    22,
      23,     0,     0,   264,    26,     0,     0,     0,     0,   265,
       0,    28,    29,   266,     0,   267,    31,     0,     0,   268,
     269,   270,     0,     0,   271,    34,    35,    36,     0,     0,
      39,    40,    41,     0,   272,     0,   273,     0,     0,     0,
       0,     0,     0,   274,   275,   276,   277,   278,     1,   254,
     255,   256,   110,     0,     3,   100,     0,     6,     0,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   258,
     259,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   260,     0,     0,   261,     0,     0,   262,     0,
       0,     0,     0,     0,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   264,    26,     0,     0,     0,
       0,   265,     0,     0,     0,   266,     0,   267,     0,     0,
       0,   268,     0,   270,     0,     0,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,     0,   273,   414,
       0,     0,     0,     0,     0,   274,   275,   276,   277,   278,
       1,   254,   255,   256,   110,     0,     3,   100,     0,     6,
       0,   335,     0,     0,     1,   254,   255,   256,   110,     0,
       3,   100,     0,     6,     0,   335,     0,     0,     0,     0,
       0,   258,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   260,   258,   259,   261,     0,     0,
     262,     0,     0,     0,     0,     0,   263,     0,   260,     0,
       0,   261,     0,     0,   262,     0,     0,   264,    26,     0,
     263,     0,     0,   265,     0,     0,     0,   266,     0,   267,
       0,   264,    26,   268,   269,   270,     0,   265,   271,     0,
       0,   266,     0,   267,     0,     0,     0,   268,   272,   270,
     273,     0,   271,     0,     0,     0,     0,   274,   275,   276,
     277,   278,   272,     0,   273,   582,     0,     0,     0,     0,
       0,   274,   275,   276,   277,   278,     1,   254,   255,   256,
     110,     0,     3,   100,     0,     6,     0,   335,     0,     0,
       1,   254,   255,   256,   110,     0,     3,   100,     0,     6,
       0,   335,     0,     0,     0,     0,     0,   258,   259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     260,   258,   259,   261,     0,     0,   262,     0,     0,     0,
       0,     0,   263,     0,   260,     0,     0,   261,     0,     0,
     262,     0,     0,   264,    26,     0,   263,     0,     0,   265,
       0,     0,     0,   266,     0,   267,     0,   264,    26,   268,
       0,   270,     0,   265,   271,     0,     0,   266,     0,   267,
       0,     0,     0,   268,   272,   270,   273,     0,   271,     0,
       0,     0,     0,   274,   275,   276,   277,   278,   421,     0,
     273,     0,     0,     0,     0,     0,     0,   274,   275,   276,
     277,   278,     1,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     9,    10,
       0,     0,     0,    11,    12,    13,     0,     0,     0,     0,
       0,    14,     0,     0,    15,    16,    17,    18,     0,    19,
       0,    20,     0,     0,    21,    22,    23,    24,    25,     0,
      26,     0,     0,     0,    27,     0,     0,    28,    29,     0,
      30,     0,    31,     0,    32,     0,     0,     0,     0,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,     0,    43,     0,     0,     0,   161,     1,     0,    44,
      45,     0,     2,     3,     4,     5,     6,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     9,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
      16,    17,    18,     0,    19,     0,    20,     0,     0,    21,
      22,    23,    24,    25,     0,    26,     0,     0,     0,    27,
       0,     0,    28,    29,     0,    30,     0,    31,     0,    32,
       0,     0,     0,     0,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,     0,    42,     0,    43,     0,     0,
       0,     1,     0,     0,    44,    45,     2,     3,     4,     5,
       6,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,     0,   185,     0,    19,     0,
      20,     0,     0,    21,    22,    23,    24,     0,     0,    26,
       0,     0,     0,    27,     0,     0,    28,    29,     0,    30,
       0,    31,     0,     2,     3,   100,     5,     6,    33,   115,
      34,    35,    36,     0,    38,    39,    40,    41,     0,   367,
       0,    43,  -484,     0,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,    10,     0,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
      15,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    22,    23,     2,     3,   100,     5,     6,     0,   115,
       0,     0,     0,    28,    29,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,    39,    40,    41,    10,   589,     0,     0,    11,
      12,    13,     0,     0,     0,     0,     0,    14,     0,     0,
      15,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,    22,    23,     0,     0,     0,     2,     3,   100,     5,
       6,   208,   115,    28,    29,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,    39,    40,    41,     0,   700,     9,    10,     0,
       0,     0,    11,    12,    13,     0,     0,     0,     0,     0,
      14,     0,     0,    15,    16,     0,   185,     0,    19,     0,
      20,     0,     0,    21,    22,    23,    24,     0,     2,     3,
     100,     5,     6,    27,   115,     0,    28,    29,     0,    30,
       0,    31,     0,     0,     0,     0,     0,     0,    33,     0,
      34,    35,    36,     0,    38,    39,    40,    41,     0,     9,
      10,     0,     0,     0,    11,   546,    13,     0,     0,     0,
       0,     0,    14,     0,     0,    15,    16,     0,   185,     0,
      19,     0,    20,     0,     0,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,    27,     0,     0,    28,    29,
       0,    30,     0,    31,     0,   547,     0,     0,     0,     0,
      33,     0,   548,    35,    36,     0,    38,    39,    40,    41,
       2,     3,   100,     5,     6,   561,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    10,     0,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,    14,     0,     0,    15,    16,     0,
     185,     0,    19,     0,    20,     0,     0,    21,    22,    23,
      24,     0,     0,     0,     0,     0,     0,    27,     0,     0,
      28,    29,     0,    30,     0,    31,     0,     0,     0,     0,
       0,     0,    33,     0,    34,    35,    36,     0,    38,    39,
      40,    41,     2,     3,   100,     5,     6,   790,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
      22,    23,     2,     3,   100,     5,     6,     0,   115,     0,
       0,     0,    28,    29,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,    36,     0,
       0,    39,    40,    41,    10,     0,     0,     0,    11,    12,
      13,     0,     0,     0,     0,     0,    14,     0,     0,    15,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,    36,     0,
       0,    39,    40,    41
};

static const yytype_int16 yycheck[] =
{
       0,   177,    63,    26,   367,    44,   199,     7,    32,     0,
     195,   500,   177,   492,   272,    15,   360,   196,   190,   199,
     363,   490,   199,     3,    42,   174,    26,     0,   481,   352,
     701,   180,    32,   376,    58,    14,   199,    37,   190,   191,
       3,    32,    42,   522,    14,    63,     9,   158,   527,   197,
      33,     3,   661,    89,    14,   317,    46,   653,    58,   655,
      18,    15,   639,    63,   213,    83,   109,    58,    50,   539,
     209,   102,   109,     7,   544,    13,   101,   654,   109,   122,
     197,   109,    36,    83,   120,   122,   565,   111,    70,    89,
       3,    71,     9,    10,   122,    12,   121,    14,   209,    99,
     101,    14,    30,    31,   269,    85,   106,   778,    98,   472,
      14,   111,   112,     9,    10,   115,    12,   109,    14,    71,
     111,   112,    10,   103,    12,   102,   237,   272,   120,    14,
     110,   101,   109,     3,   157,   174,   119,   322,   323,     9,
      10,   180,    12,   122,   815,    46,   742,   105,   209,    14,
       3,   103,   317,   318,   107,   417,     7,   157,   158,   352,
     123,   770,   122,   421,   164,   165,   166,   167,   426,   169,
     309,   109,   352,     0,   213,   352,   176,   177,   436,   107,
     108,   199,   166,   102,   101,   364,    87,   366,   123,   352,
     109,   209,   192,   110,   111,   539,   196,    98,   309,   199,
     200,    71,   672,   673,   813,   205,    57,   677,   678,   209,
     102,   469,   535,    85,   110,   111,   240,   109,    71,     9,
      10,   221,    12,   110,    14,   225,   226,   227,   115,   116,
     221,     3,    85,   103,   225,   235,   227,   237,   707,   102,
     240,   105,   226,   123,   244,   109,   109,   247,   221,   240,
     103,   102,   417,   104,   102,   105,   367,   257,   369,   109,
     244,   109,   246,    34,    35,   121,    37,   123,   413,   253,
     435,   416,   272,   102,    15,   420,   421,   123,   423,   732,
     109,   426,     3,   102,    25,   102,   347,   757,     9,    10,
     109,    12,   762,    14,   441,   442,   443,   315,     9,    10,
     476,    12,   781,    14,   104,   156,   471,     9,    10,   309,
      12,   476,    14,   104,   104,   315,   481,   502,   169,   102,
     110,   111,    28,    29,   324,   490,   109,    24,    25,   347,
     101,   331,   676,   104,   352,   106,   105,   101,   681,   828,
     104,   684,   535,   343,   492,   112,   113,   347,    89,   367,
      71,   369,   352,   525,   205,   535,     9,    10,   535,    12,
     360,   472,   473,   363,   364,   106,   366,   367,   109,   369,
     108,   520,   535,   525,   522,   492,   376,     3,   101,   527,
     559,   104,   103,     9,    10,    96,    12,   102,   388,    26,
      92,   556,   650,   558,   120,   653,   419,   655,   574,   250,
     448,   449,   450,   451,   388,   522,   390,   123,   101,   574,
     527,   104,   560,   413,   101,    89,   416,   565,   402,   419,
     420,   421,     3,   423,   108,   109,   426,     8,   791,    10,
      11,    12,     8,   598,    10,    11,    12,   288,     9,    10,
     225,    12,   227,   560,   589,   120,   120,   121,   565,   123,
     107,   192,   710,   108,   109,   516,     3,   101,   199,   200,
     102,   202,     9,    10,   102,    12,   124,    14,   633,   108,
     109,   122,   472,   473,   108,   109,   476,   218,   219,    50,
     591,   520,   444,   445,   742,     3,   105,   446,   447,   489,
      71,     9,    10,   105,    12,   495,    14,   110,   516,    70,
     241,   452,   453,     9,    85,     0,   495,   122,     9,    10,
     510,    12,     7,    14,   365,   533,   516,   535,   776,   777,
     157,   510,   103,   107,    71,   783,   784,     9,    10,   110,
      12,    26,    14,   533,   107,   535,   794,    32,   538,   539,
     177,   101,   707,   107,   544,   322,   323,   101,    43,     9,
      10,   107,    12,    71,    14,   700,   103,   118,   111,   559,
     117,   584,    57,    58,    32,   730,   109,   732,    63,   101,
       3,    72,    73,    74,   574,     8,     9,    10,    11,    12,
     102,   581,   105,   101,   584,   103,   570,   120,   122,   589,
     331,   591,   110,   111,    57,    96,     9,    10,   122,    12,
     120,    14,   713,   124,    99,   121,   347,   102,   753,   104,
       0,   352,    72,    73,    74,   122,   111,   112,   359,   121,
     765,   770,   767,     9,    10,   109,    12,   650,    14,   121,
     653,   124,   655,   781,   124,   272,   124,   122,    71,   102,
     110,   826,    32,   124,     9,    10,   646,    12,   648,    14,
     650,   107,    14,   653,   105,   655,   656,   646,   122,   683,
     122,   156,   157,   122,   781,   830,   102,   656,    58,   122,
     103,    43,   672,   673,   169,   122,   676,   677,   678,   855,
     791,   681,   177,   683,   684,   120,   101,     3,   833,   101,
     101,   101,   683,     9,    10,   120,    12,   192,    14,   122,
     700,   196,   165,   109,   199,   168,   124,   170,   109,    99,
     205,   734,   107,   713,   209,   101,   179,   102,   104,   742,
     102,   111,   112,   102,   110,   111,   221,   105,   122,   747,
     225,   770,   227,   122,   734,   108,     9,    10,   738,    12,
      89,    14,   742,   206,   108,   240,   101,   747,   489,   738,
     108,   102,   101,   753,   495,   250,   497,   757,   499,   102,
     108,   102,   762,     9,    10,   765,    12,   767,    14,   510,
     109,   120,   121,   791,   123,   109,   413,   272,   273,   416,
     243,   101,   419,   420,   421,   248,   423,   250,   102,   426,
     120,   791,   533,   288,   535,   100,    69,   797,   122,   799,
     800,   122,   121,   101,    87,   546,   196,   548,   797,   199,
     799,   800,   121,     9,    10,     3,    12,   121,    14,    92,
     121,     9,    10,   564,    12,   288,    14,   102,   105,   324,
     101,   221,   327,   833,   101,   225,   331,   227,     3,   476,
     102,   104,   101,   101,     9,    10,   124,    12,   848,    14,
     240,   101,   347,   853,   102,   102,   122,   352,   102,   848,
     102,   102,   102,   102,   853,   360,     3,   121,   363,   364,
     365,   366,     9,    10,   109,    12,    45,    14,   105,    54,
     102,   376,     3,   121,   258,   259,   122,   261,     9,    10,
      12,    12,    25,    14,   584,   266,   454,   456,   468,   648,
     274,   275,   365,   455,   648,   646,    71,   457,   564,    98,
     315,   533,     0,   347,   362,   656,   676,   291,   413,     7,
     489,   416,   681,   684,   419,   420,   421,   574,   423,   713,
     476,   426,   410,   560,    71,   237,   101,   574,   103,   104,
      -1,    -1,   405,    -1,    32,   110,   111,   584,    85,    -1,
      71,    -1,   589,    -1,    42,    -1,    -1,    -1,    -1,    -1,
       3,    -1,   352,    -1,    -1,     8,   103,    10,    11,    12,
      58,    -1,    -1,   363,   364,    63,   366,    -1,    -1,    -1,
     101,   476,   103,    -1,    -1,    -1,   376,    -1,    -1,   110,
     111,    -1,   487,    -1,   489,    83,     3,   738,    -1,    -1,
     495,    -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,
      98,    -1,    -1,   650,    -1,   510,   653,    -1,   655,    -1,
      -1,   516,     3,   111,   112,    -1,    -1,     8,    71,    10,
      11,    12,    -1,    -1,    -1,   409,    -1,    -1,     3,    -1,
     535,    -1,    85,   538,     9,    10,   541,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,   797,    -1,   799,   800,
     103,    -1,    -1,   700,   559,   439,   440,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   584,
      71,    -1,    -1,    -1,   589,    -1,   837,   734,    -1,    -1,
      -1,    -1,    -1,    -1,    85,   742,    71,   848,    -1,    -1,
      -1,   199,   853,    -1,    -1,    -1,   753,   205,    -1,    -1,
      85,   209,   103,    -1,    -1,    -1,    -1,    -1,   765,    -1,
     767,    -1,    -1,   221,    -1,     3,    -1,   225,   103,   227,
      -1,     9,    10,    -1,    12,   535,    14,    -1,    -1,    -1,
      -1,   646,   240,   648,    -1,   650,    -1,    -1,   653,    -1,
     655,   656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   559,
      -1,    -1,    -1,    -1,    -1,    -1,   671,    -1,    -1,   674,
      -1,   676,    -1,    -1,   679,    -1,   681,    -1,   683,   684,
      -1,    -1,    -1,    -1,    -1,    -1,   833,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    -1,   700,    -1,    -1,    -1,    -1,
      -1,    -1,   586,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,   599,    -1,   315,    -1,    -1,
      33,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,   734,
      -1,    -1,    -1,   738,    -1,    -1,    -1,   742,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   753,   347,
      -1,   756,    -1,   758,   352,    -1,   761,    -1,   763,    -1,
     765,    -1,   767,    -1,    -1,    -1,    -1,    -1,    -1,   367,
      -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   681,    -1,   683,   684,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   797,    -1,   799,   800,    -1,    -1,    -1,    -1,
     805,    -1,    -1,   808,    -1,    -1,   119,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   699,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,   833,     9,
      10,    -1,    12,    -1,    14,    -1,   434,    -1,    -1,   437,
      -1,    -1,    -1,   848,    -1,    -1,    -1,    -1,   853,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    86,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,
      -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   533,    -1,   535,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   600,   601,    -1,    -1,    -1,    -1,   606,   607,
      34,    35,    -1,    -1,    38,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,   683,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   723,    -1,    -1,    -1,    -1,
     728,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,   747,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    38,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,   791,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,    -1,   103,
      -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,
     114,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,   123,
     124,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,
      57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,    75,    -1,
      -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,    -1,
      -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,    -1,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,   122,    14,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,    -1,
      -1,    -1,    80,    -1,    82,    -1,    -1,    -1,    86,    87,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   101,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   123,   124,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    -1,    38,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,   123,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    95,    96,    97,    98,    99,
      -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,   123,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      80,    -1,    82,    -1,    -1,    -1,    86,    87,    88,     3,
      -1,    91,    -1,    -1,     8,     9,    10,    11,    12,    -1,
      14,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   123,    -1,    39,    40,    -1,    -1,    -1,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    55,    56,    -1,    58,    -1,    60,    -1,    62,    -1,
      -1,    65,    66,    67,    68,    -1,    -1,    71,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    -1,    81,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,   101,    -1,   103,
      -1,    -1,    -1,     3,    -1,    -1,   110,   111,     8,     9,
      10,    11,    12,    -1,    14,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      -1,    14,   122,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    40,    -1,    -1,
      -1,    44,    45,    46,    -1,    -1,    -1,    50,    -1,    52,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    94,    -1,    -1,    97,    98,    99,    -1,   101,    -1,
     103,   104,    -1,    -1,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,    -1,    -1,   121,    -1,
      -1,    -1,    -1,   126,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      39,    40,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      -1,    50,    -1,    52,    53,    -1,    55,    56,    -1,    58,
      59,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      -1,    70,    71,    -1,    -1,    -1,    75,    76,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    86,    87,    88,
      -1,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,   101,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,    46,
      47,    -1,    -1,    50,    -1,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    66,
      67,    -1,    -1,    70,    71,    -1,    -1,    -1,    -1,    76,
      -1,    78,    79,    80,    -1,    82,    83,    -1,    -1,    86,
      87,    88,    -1,    -1,    91,    92,    93,    94,    -1,    -1,
      97,    98,    99,    -1,   101,    -1,   103,    -1,    -1,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,     3,     4,
       5,     6,     7,    -1,     9,    10,    -1,    12,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      -1,    86,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,   103,   104,
      -1,    -1,    -1,    -1,    -1,   110,   111,   112,   113,   114,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    34,    35,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    -1,    47,    -1,
      -1,    50,    -1,    -1,    53,    -1,    -1,    70,    71,    -1,
      59,    -1,    -1,    76,    -1,    -1,    -1,    80,    -1,    82,
      -1,    70,    71,    86,    87,    88,    -1,    76,    91,    -1,
      -1,    80,    -1,    82,    -1,    -1,    -1,    86,   101,    88,
     103,    -1,    91,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   101,    -1,   103,   104,    -1,    -1,    -1,    -1,
      -1,   110,   111,   112,   113,   114,     3,     4,     5,     6,
       7,    -1,     9,    10,    -1,    12,    -1,    14,    -1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    -1,    12,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    34,    35,    50,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    47,    -1,    -1,    50,    -1,    -1,
      53,    -1,    -1,    70,    71,    -1,    59,    -1,    -1,    76,
      -1,    -1,    -1,    80,    -1,    82,    -1,    70,    71,    86,
      -1,    88,    -1,    76,    91,    -1,    -1,    80,    -1,    82,
      -1,    -1,    -1,    86,   101,    88,   103,    -1,    91,    -1,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   101,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,
     113,   114,     3,    -1,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,
      -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    62,    -1,    -1,    65,    66,    67,    68,    69,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,
      81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,    -1,
     101,    -1,   103,    -1,    -1,    -1,   107,     3,    -1,   110,
     111,    -1,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    39,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      56,    57,    58,    -1,    60,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    79,    -1,    81,    -1,    83,    -1,    85,
      -1,    -1,    -1,    -1,    90,    -1,    92,    93,    94,    95,
      96,    97,    98,    99,    -1,   101,    -1,   103,    -1,    -1,
      -1,     3,    -1,    -1,   110,   111,     8,     9,    10,    11,
      12,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    56,    -1,    58,    -1,    60,    -1,
      62,    -1,    -1,    65,    66,    67,    68,    -1,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,    -1,    81,
      -1,    83,    -1,     8,     9,    10,    11,    12,    90,    14,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,   101,
      -1,   103,   104,    -1,    -1,    -1,    -1,    -1,   110,   111,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,     8,     9,    10,    11,    12,    -1,    14,
      -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      -1,    -1,    97,    98,    99,    40,   101,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    -1,    -1,    -1,     8,     9,    10,    11,
      12,    13,    14,    78,    79,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      -1,    -1,    97,    98,    99,    -1,   101,    39,    40,    -1,
      -1,    -1,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    55,    56,    -1,    58,    -1,    60,    -1,
      62,    -1,    -1,    65,    66,    67,    68,    -1,     8,     9,
      10,    11,    12,    75,    14,    -1,    78,    79,    -1,    81,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    39,
      40,    -1,    -1,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    55,    56,    -1,    58,    -1,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    79,
      -1,    81,    -1,    83,    -1,    85,    -1,    -1,    -1,    -1,
      90,    -1,    92,    93,    94,    -1,    96,    97,    98,    99,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    55,    56,    -1,
      58,    -1,    60,    -1,    62,    -1,    -1,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    90,    -1,    92,    93,    94,    -1,    96,    97,
      98,    99,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,     8,     9,    10,    11,    12,    -1,    14,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    97,    98,    99,    40,    -1,    -1,    -1,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    -1,
      -1,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     3,     8,     9,    10,    11,    12,    14,    38,    39,
      40,    44,    45,    46,    52,    55,    56,    57,    58,    60,
      62,    65,    66,    67,    68,    69,    71,    75,    78,    79,
      81,    83,    85,    90,    92,    93,    94,    95,    96,    97,
      98,    99,   101,   103,   110,   111,   128,   129,   130,   131,
     132,   133,   134,   141,   143,   144,   145,   146,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   202,   203,   204,   205,   206,   208,   210,   211,   212,
     213,   216,   217,   218,   220,   221,   229,   234,   235,   236,
     247,   254,   256,   260,   263,   264,   273,   294,    14,   101,
      10,   143,   146,   196,   274,   101,    14,   131,   134,   146,
       7,   139,   123,   130,   134,    14,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    50,    70,
     101,   103,   104,   107,   108,   109,   110,   111,   112,   114,
     115,   116,   117,   118,   121,   126,   146,   194,   223,   248,
     255,   107,   187,    14,   276,    14,    69,    92,   146,    14,
     146,   216,   131,   219,   220,    14,    14,   107,     0,    85,
     110,   131,   144,   196,   187,    58,   122,   190,   214,   215,
     216,    89,   120,   250,   266,   289,   101,   104,   216,   123,
      14,   134,   146,    85,    10,    14,   146,   221,    13,   191,
     226,   227,   228,   110,   196,   196,   139,   134,   146,   123,
     134,   123,   187,   207,   273,   123,   121,   123,   146,   104,
     104,   102,   105,   223,   287,    14,   146,   218,   249,   293,
     108,   146,   144,   146,    14,   129,   146,    14,   146,   144,
     146,   102,   219,   146,     4,     5,     6,    14,    34,    35,
      47,    50,    53,    59,    70,    76,    80,    82,    86,    87,
      88,    91,   101,   103,   110,   111,   112,   113,   114,   133,
     135,   136,   137,   138,   139,   140,   142,   143,   146,   147,
     149,   150,   151,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   222,   223,
     261,   262,   270,   144,   219,   109,   122,   101,   121,   231,
     266,   284,   289,   289,    14,   131,   134,   146,   251,   252,
     253,   123,   178,   230,   226,    14,   169,   170,   174,   285,
      72,    73,    74,    95,   122,   134,   145,   191,   210,   216,
     229,   237,   238,   239,   240,   246,   256,   291,   134,   146,
     120,   243,   134,   107,   101,   146,   101,   101,   216,   218,
     224,   225,   286,   288,   102,    13,   109,   219,   102,   134,
     134,   199,   200,   201,   283,   273,   124,   207,    14,   129,
     146,   209,   207,   105,   105,   146,   293,   187,   134,   122,
     144,   129,   146,   122,   129,   146,   144,   122,   129,    50,
      70,   158,   158,   107,   104,   158,   107,   101,   152,   277,
     107,   101,   149,   107,   171,   296,   101,   171,   173,   222,
     158,   158,    34,    35,    37,   101,   104,   106,   158,    15,
      36,   110,   115,   116,   112,   113,    24,    25,    30,    31,
     107,   108,    28,    29,   111,   117,   118,    32,    16,    17,
      18,    19,    20,    21,    22,    23,    26,    27,    33,   119,
     121,   172,   101,   218,   286,   108,   109,   215,   216,   148,
     171,   123,   171,   232,   230,   230,   131,   146,   131,   109,
     101,    41,    42,    48,    49,    51,    61,    63,    64,    69,
      77,    84,    89,   100,   134,   173,   175,   176,   177,   178,
     179,   180,   182,   184,   185,   188,   191,   265,   280,   281,
     102,   105,   120,   122,   122,   216,   239,   121,   241,   242,
     122,   292,   291,   109,   122,   120,   124,   134,    14,    96,
     131,   146,   244,   245,   246,   243,    45,    85,    92,   228,
     257,   258,   259,   226,   226,   224,   121,   286,   121,   101,
     104,    13,   228,   122,   109,   121,   124,   124,   124,   129,
     146,   129,   122,   124,   107,   122,   122,   129,   122,   144,
     122,    14,   104,   158,   277,   222,   105,   222,   148,   101,
     153,   223,   222,   222,   222,   173,   222,   102,   109,   102,
      14,    85,   143,   148,   275,   173,    14,    85,   143,   158,
     158,   159,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   163,   163,   164,   165,   166,   167,   168,   173,
     171,   262,   102,   109,   124,   232,   233,    43,   267,   268,
     131,   251,   275,   122,   174,   122,   120,   175,   101,   134,
     101,   134,   280,   101,   178,   101,   120,   175,   122,   124,
      87,   219,   271,   174,   122,   125,   174,   216,   240,   291,
     131,   146,    14,   246,   274,   131,   109,    14,    96,   274,
     134,   107,   134,   108,   109,   102,   102,   102,   171,   171,
     226,   285,   200,   174,   129,   261,   122,   122,   146,   105,
     101,   153,   108,   158,   108,   102,   222,   101,   156,   278,
     104,   154,   155,   218,   279,   108,   102,   108,   102,   102,
     171,   158,   143,    14,   143,   102,   105,   143,    14,   143,
     120,   171,   109,   290,   101,   267,   295,   102,   120,   175,
     100,   177,   183,   189,   122,   173,   181,   223,   122,   181,
     267,   181,   175,   101,   271,   131,   274,    14,   274,   131,
     245,   274,    14,   274,   131,   121,   257,   121,   187,   258,
     102,   105,   108,   158,   222,   278,   101,   101,   102,   275,
     173,   104,   279,   101,   101,   143,   143,   171,   232,   124,
      13,   223,   269,   175,   101,   181,   282,   102,   216,   102,
     102,   222,   272,   297,   131,   274,   131,   131,   274,   131,
     222,   108,   222,   219,   271,   102,   173,   173,   278,   102,
     105,   174,   173,   173,   216,   224,   102,   173,   122,   175,
     121,   175,   175,   109,   102,   131,   131,    45,   271,   278,
     102,   102,   105,   102,   102,   178,   102,   280,    54,   171,
     222,   134,   122,   102,   175,   121,   175,   133
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
        case 9:
#line 127 "120gram.y"
    { (yyval. text ) = strdup(yylval.np->lexeme); ;}
    break;

  case 324:
#line 793 "120gram.y"
    { typenametable_insert((yyvsp[(2) - (2)]. text ), CLASS_NAME); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3062 "120gram.tab.c"
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


#line 1189 "120gram.y"


static void
yyerror(char *s)
{
	fprintf(stderr, "%d: %s\n", lineno, s);
}


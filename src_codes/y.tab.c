/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdlib.h>

	#include "func.c"

	#define inttype 0
	#define boolean 1
	#define strtype 2
	#define leaf 	3
	#define div 	4
	#define mul 	5
	#define sub	6
	#define plus    7
	#define assgn	8
	#define write 	9
	#define read	10
	#define connect 11
	#define greater_than	12
	#define less_than	13
	#define not_equal	14
	#define equal		15
	#define greater_equal	16
	#define less_equal	17
	#define if_part 	18
	#define else_part	19
	#define while_do	20
	#define cont_stmt 	21
	#define brk_stmt 	22
	#define leaf_arr	23
	#define mod		24	
	#define function	25
	#define func_call	26
	#define ret_stmt	27
	#define heap_init_stmt  28
	#define heap_alloc_stmt 29
	#define heap_free_stmt	30
	#define leaf_tf		31	
	#define leaf_cf		32	
	#define cf_func_call	33
	#define brk_point	34
	#define vr_tbl_alloc	35	
	#define class_func_call	36	

	extern FILE* yyin;
	extern int yylex();

	int yyerror(char*);
	
	int gv_pointer=4095;
	int lv_pointer=0;
	int arg_pointer=0;
	int field_index=0;
	int current_block=-1;
	int main_flag=0;
	int class_flag=0;		
	int saved_block_no=0;		
	int extend_size=0;		
	int rand_no=1;		
	int extend_flag=0;	

#line 132 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DECLARE = 258,
    INT = 259,
    STR = 260,
    ENDDECL = 261,
    COMMA = 262,
    SQ_LBRAC = 263,
    SQ_RBRAC = 264,
    CL_LBRAC = 265,
    CL_RBRAC = 266,
    MOD = 267,
    MAIN = 268,
    STRING = 269,
    ID = 270,
    NUM = 271,
    ASSIGN = 272,
    PLUS = 273,
    MINUS = 274,
    MUL = 275,
    DIV = 276,
    GT = 277,
    LT = 278,
    EQ = 279,
    NEQ = 280,
    GEQ = 281,
    LEQ = 282,
    LBRAC = 283,
    RBRAC = 284,
    SEMIC = 285,
    NL = 286,
    BEG = 287,
    END = 288,
    READ = 289,
    WRITE = 290,
    WHILE = 291,
    DO = 292,
    ENDWHILE = 293,
    IF = 294,
    THEN = 295,
    ELSE = 296,
    ENDIF = 297,
    CONTINUE = 298,
    BREAK = 299,
    RETURN = 300,
    TYPE = 301,
    ENDTYPE = 302,
    INIT = 303,
    ALLOC = 304,
    FREE = 305,
    DOT = 306,
    NUL = 307,
    CLASS = 308,
    ENDCLASS = 309,
    SELF = 310,
    NEW = 311,
    DELETE = 312,
    BRKP = 313,
    EXTENDS = 314
  };
#endif
/* Tokens.  */
#define DECLARE 258
#define INT 259
#define STR 260
#define ENDDECL 261
#define COMMA 262
#define SQ_LBRAC 263
#define SQ_RBRAC 264
#define CL_LBRAC 265
#define CL_RBRAC 266
#define MOD 267
#define MAIN 268
#define STRING 269
#define ID 270
#define NUM 271
#define ASSIGN 272
#define PLUS 273
#define MINUS 274
#define MUL 275
#define DIV 276
#define GT 277
#define LT 278
#define EQ 279
#define NEQ 280
#define GEQ 281
#define LEQ 282
#define LBRAC 283
#define RBRAC 284
#define SEMIC 285
#define NL 286
#define BEG 287
#define END 288
#define READ 289
#define WRITE 290
#define WHILE 291
#define DO 292
#define ENDWHILE 293
#define IF 294
#define THEN 295
#define ELSE 296
#define ENDIF 297
#define CONTINUE 298
#define BREAK 299
#define RETURN 300
#define TYPE 301
#define ENDTYPE 302
#define INIT 303
#define ALLOC 304
#define FREE 305
#define DOT 306
#define NUL 307
#define CLASS 308
#define ENDCLASS 309
#define SELF 310
#define NEW 311
#define DELETE 312
#define BRKP 313
#define EXTENDS 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "parser.y"

	int integer;
	char* string;
	struct t_node* tree_node;
	struct symbol* gs_node;
	struct param_struct* param_node;
	struct field_list* field_node;
	struct type_table* table_node;
	struct class* class_node;

#line 313 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   716

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  320

#define YYUNDEFTOK  2
#define YYMAXUTOK   314


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   107,   112,   117,   123,   128,   133,   138,
     142,   146,   151,   156,   163,   173,   183,   191,   206,   216,
     224,   237,   239,   241,   246,   258,   268,   276,   296,   313,
     342,   370,   383,   387,   393,   449,   467,   490,   508,   523,
     525,   527,   543,   566,   581,   606,   626,   660,   686,   690,
     695,   730,   767,   777,   782,   789,   796,   810,   824,   830,
     839,   850,   860,   869,   878,   896,   898,   900,   914,   935,
     952,   956,   961,   963,   965,   967,   969,   971,   973,   975,
     977,   979,   981,   983,   985,   987,   993,   999,  1019,  1040,
    1053,  1059,  1064,  1071,  1082,  1098,  1111,  1125,  1139,  1156,
    1169,  1171,  1191,  1196,  1201,  1230,  1263,  1290,  1300,  1310,
    1320,  1331,  1342,  1353,  1364,  1387,  1410,  1421,  1432,  1434,
    1436,  1438,  1440,  1442,  1463,  1468,  1473,  1475,  1480,  1492,
    1504,  1512,  1519,  1526,  1543,  1550,  1557,  1561
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECLARE", "INT", "STR", "ENDDECL",
  "COMMA", "SQ_LBRAC", "SQ_RBRAC", "CL_LBRAC", "CL_RBRAC", "MOD", "MAIN",
  "STRING", "ID", "NUM", "ASSIGN", "PLUS", "MINUS", "MUL", "DIV", "GT",
  "LT", "EQ", "NEQ", "GEQ", "LEQ", "LBRAC", "RBRAC", "SEMIC", "NL", "BEG",
  "END", "READ", "WRITE", "WHILE", "DO", "ENDWHILE", "IF", "THEN", "ELSE",
  "ENDIF", "CONTINUE", "BREAK", "RETURN", "TYPE", "ENDTYPE", "INIT",
  "ALLOC", "FREE", "DOT", "NUL", "CLASS", "ENDCLASS", "SELF", "NEW",
  "DELETE", "BRKP", "EXTENDS", "$accept", "program", "type_def_block",
  "type_def_list", "type_def", "field_decl_list", "field_decl",
  "field_type", "class_def_block", "class_def_list", "class_def",
  "ID_extends_ID", "method_def", "gl_declarations", "gl_decllist",
  "gl_decl", "gl_type", "gl_varlist", "fdef_block", "fdef", "param_list",
  "param", "mainblock", "l_declarations", "l_decllist", "l_decl", "l_type",
  "l_varlist", "slist", "stmt", "brkp_stmt", "new_stmt", "delete_stmt",
  "continue_stmt", "break_stmt", "return_stmt", "init_stmt", "alloc_stmt",
  "free_stmt", "if_stmt", "while_stmt", "input_stmt", "output_stmt",
  "assgn_stmt", "expr", "arg_list", "field", "field_func", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   174,    -1,     8,    12,    83,    17,   160,   221,  -141,
    -141,  -141,  -141,  -141,   205,  -141,    26,    -6,    76,    22,
    -141,    -8,     9,  -141,    80,  -141,   160,   221,  -141,   221,
    -141,    -1,    77,   221,  -141,  -141,  -141,  -141,    63,    19,
      67,   247,  -141,  -141,    98,   112,  -141,  -141,    98,   221,
    -141,   221,  -141,   221,  -141,   117,  -141,  -141,   124,   288,
     136,  -141,   143,  -141,  -141,  -141,    24,  -141,   145,   380,
    -141,   696,   221,  -141,  -141,  -141,   288,   162,   168,    68,
    -141,   142,    40,  -141,  -141,   154,  -141,   698,  -141,  -141,
     701,  -141,    73,  -141,  -141,   288,  -141,   159,   288,   213,
     188,   156,  -141,  -141,  -141,  -141,   176,  -141,   181,    75,
    -141,  -141,  -141,  -141,   262,  -141,   182,     1,   193,   177,
     178,   185,   202,   204,   207,    94,   211,   184,   216,   212,
     214,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,    -9,   240,    41,  -141,
    -141,  -141,  -141,  -141,    58,   304,   405,   239,  -141,    -5,
     304,   304,   304,  -141,  -141,  -141,    -3,  -141,   304,  -141,
    -141,   210,   471,   219,  -141,   241,   248,     2,  -141,   254,
    -141,    79,   265,   275,   266,   393,   255,   273,  -141,   490,
     261,   263,   268,   506,  -141,     3,   -13,   592,   608,   624,
     304,   430,   279,   640,   289,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,  -141,   291,   283,  -141,
     257,    97,  -141,   285,   522,  -141,  -141,   303,   292,   393,
    -141,   298,   293,   300,   302,  -141,   304,   308,   309,   310,
     297,   290,   541,  -141,   656,   123,   313,  -141,   315,  -141,
     161,   161,  -141,  -141,   672,   672,   672,   672,   672,   672,
     316,   325,   330,   331,  -141,  -141,   334,   318,   304,   335,
     336,   319,   560,  -141,  -141,  -141,   393,   393,  -141,   304,
    -141,   448,   452,   304,  -141,  -141,   338,  -141,   353,   576,
    -141,  -141,   339,   341,   343,   157,   656,  -141,   125,  -141,
     126,   132,   342,  -141,  -141,  -141,   344,   350,   393,   359,
    -141,  -141,  -141,  -141,  -141,  -141,   368,  -141,   360,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      39,    40,    35,    41,     0,    37,     0,     0,     0,     0,
      16,     0,     0,    26,     0,     1,     0,     0,    10,     0,
       7,    39,     0,     0,    49,    12,    34,    36,    43,     0,
       0,     0,    14,    15,     0,     0,    24,    25,     0,     0,
       4,     0,     9,     0,     6,     0,    48,    11,     0,    55,
       0,    38,     0,    21,    22,    23,     0,    19,     0,     0,
      31,     0,     0,     3,     8,     5,    55,     0,     0,     0,
      53,    42,     0,    17,    18,     0,    28,     0,    33,    30,
       0,     2,     0,    45,    54,    55,    47,     0,    55,     0,
       0,     0,    20,    27,    32,    29,     0,    52,     0,     0,
      65,    66,    61,    67,     0,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    71,    85,    83,    84,    77,    78,    79,    80,    81,
      82,    75,    76,    72,    73,    74,     0,     0,     0,    44,
      46,    60,    62,    69,     0,     0,     0,     0,    59,     0,
       0,     0,     0,    90,    91,   127,   126,   119,     0,    93,
     120,     0,     0,   121,   122,     0,     0,     0,    86,     0,
      70,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,     0,   132,
       0,     0,    57,     0,     0,   130,    58,     0,     0,     0,
      68,     0,     0,     0,     0,   104,     0,     0,     0,     0,
       0,     0,     0,   125,   129,     0,   131,   118,   132,   111,
     107,   108,   109,   110,   112,   113,   115,   114,   116,   117,
     130,     0,     0,     0,   106,    56,     0,     0,     0,     0,
       0,     0,     0,   100,   102,   103,     0,     0,   123,     0,
     124,     0,     0,     0,    96,    89,     0,    51,     0,     0,
      94,    95,     0,     0,     0,     0,   128,   135,     0,   137,
       0,     0,     0,    50,   105,    87,     0,     0,     0,     0,
     134,   136,   133,    88,   101,    99,     0,    98,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   352,  -141,   326,  -141,   388,  -141,
     374,  -141,   328,   234,  -141,   383,     5,  -141,    49,    72,
      71,   311,     7,   267,  -141,   295,  -141,  -141,  -140,  -129,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   -94,  -125,  -100,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    19,    20,    66,    67,    68,     7,    22,
      23,    24,    87,     8,    14,    15,    32,    39,    33,    34,
      79,    80,     9,   101,   114,   115,   116,   154,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   244,   245,   173,   174
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     146,   180,    44,     1,     2,   200,    16,   184,   181,   155,
     195,   236,    17,    28,    30,    35,   238,   220,   156,    16,
       1,     2,    40,    18,    21,   201,    60,    21,    63,    64,
     146,   172,   237,    50,    52,    83,    54,    18,   182,    65,
      57,    38,   182,    99,    99,   228,     3,   146,   202,    61,
     127,    45,   157,     4,   157,   180,    73,   127,    74,   196,
      75,   189,   193,    46,    78,   187,   197,   198,   199,    42,
       4,    58,   100,   185,   203,    95,    51,   221,    53,    91,
      95,    78,    95,    25,   146,   146,    41,   224,   188,   267,
      48,    59,    55,   165,   166,   167,    62,    96,    72,   180,
      78,     1,   106,    78,   150,    56,   242,   168,   165,   166,
     167,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   168,    56,   169,    56,   262,    70,   146,   146,
     279,   170,   279,   279,   171,   223,   294,   295,   180,   279,
      77,    88,   272,    88,    56,    76,   170,    92,   182,   171,
      97,    81,   280,    82,   310,   311,   298,   300,   301,   104,
      85,   312,   104,     1,     2,   180,   180,   146,   316,   109,
      98,    93,   117,   205,   289,   108,   146,   146,    10,    11,
      12,   208,   209,    94,   102,   296,   148,   180,   147,    13,
     149,   119,   120,   121,   146,   146,   122,   153,   308,   309,
     123,   124,   125,   117,   158,   159,   160,   126,   146,    10,
      11,    36,   127,   161,   128,   129,   146,   110,   111,   112,
      13,   118,   119,   120,   121,    31,    11,   122,   113,   117,
     162,   123,   124,   125,   163,   176,    13,   164,   126,   175,
      27,    29,   178,   127,   177,   128,   129,   179,   119,   120,
     121,    63,    64,   122,   194,   117,   218,   123,   124,   125,
      49,   204,    65,   219,   126,   222,   110,   111,   151,   127,
     217,   128,   129,   183,   119,   120,   121,   113,    69,   122,
     225,   117,    71,   123,   124,   125,   226,   229,   230,   232,
     126,   233,    10,    11,   246,   127,   234,   128,   129,   227,
     119,   120,   121,    13,   248,   122,   260,   117,   157,   123,
     124,   125,   261,   263,   265,   268,   126,   271,   165,   166,
     167,   127,   269,   128,   129,   266,   119,   120,   121,   270,
     277,   122,   168,   117,   276,   123,   124,   125,   273,   274,
     275,   281,   126,   282,   283,   287,   286,   127,   292,   128,
     129,   288,   119,   120,   121,   284,   170,   122,   117,   171,
     285,   123,   124,   125,   303,   290,   291,   302,   126,   305,
     306,    43,   313,   127,   314,   128,   129,   119,   120,   121,
     315,   307,   122,   117,    10,    11,   123,   124,   125,   317,
     319,    86,    84,   126,    26,    13,    47,    37,   127,    90,
     128,   129,   119,   120,   121,     0,   107,   122,   117,   152,
     318,   123,   124,   125,     0,   186,     0,     0,   126,   165,
     166,   167,     0,   127,     0,   128,   129,   119,   120,   121,
       0,     0,   122,   168,     0,     0,   123,   124,   125,     0,
       0,     0,     0,   126,   165,   166,   167,     0,   127,     0,
     128,   129,     0,   190,   191,     0,     0,   170,   168,   243,
     171,   192,   165,   166,   167,     0,   165,   166,   167,     0,
       0,     0,     0,     0,     0,     0,   168,   297,     0,     0,
     168,   299,   170,   205,     0,   171,     0,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   231,
     170,   216,   205,   171,   170,     0,     0,   171,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   205,     0,
       0,     0,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   205,     0,   235,     0,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     278,     0,   264,   205,     0,     0,     0,     0,     0,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   293,
       0,     0,   205,     0,     0,     0,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   205,     0,
       0,     0,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   205,     0,   304,     0,     0,     0,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     205,   239,     0,     0,     0,     0,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   205,   240,     0,     0,
       0,     0,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   205,   241,     0,     0,     0,     0,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   205,   247,
       0,     0,     0,     0,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   205,     0,     0,     0,     0,     0,
     206,   207,   208,   209,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    10,    11,     0,    10,    11,    89,     0,   103,
       0,    13,   105,    13,     0,     0,    13
};

static const yytype_int16 yycheck[] =
{
     100,   130,    10,     3,     4,     8,     1,   147,    17,     8,
      15,     8,    13,     6,     7,     8,    29,    15,    17,    14,
       3,     4,    28,    15,    15,    28,     7,    15,     4,     5,
     130,   125,    29,    26,    27,    11,    29,    15,    51,    15,
      33,    15,    51,     3,     3,   185,    46,   147,    51,    30,
      55,    59,    51,    53,    51,   184,    49,    55,    51,   159,
      53,   155,   156,    54,    59,     7,   160,   161,   162,    47,
      53,     8,    32,    32,   168,     7,    27,   177,    29,    72,
       7,    76,     7,     0,   184,   185,    10,   181,    30,   229,
      10,    28,    15,    14,    15,    16,    29,    29,    49,   228,
      95,     3,    29,    98,    29,    33,   200,    28,    14,    15,
      16,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    28,    51,    30,    53,    29,    15,   228,   229,
       7,    52,     7,     7,    55,    56,   276,   277,   267,     7,
      16,    69,   236,    71,    72,    28,    52,    76,    51,    55,
       8,    15,    29,    10,    29,    29,   281,   282,   283,    87,
      15,    29,    90,     3,     4,   294,   295,   267,   308,    98,
      28,     9,    15,    12,   268,    16,   276,   277,     4,     5,
       6,    20,    21,    15,    30,   279,    10,   316,    32,    15,
       9,    34,    35,    36,   294,   295,    39,    15,    41,    42,
      43,    44,    45,    15,    11,    28,    28,    50,   308,     4,
       5,     6,    55,    28,    57,    58,   316,     4,     5,     6,
      15,    33,    34,    35,    36,     4,     5,    39,    15,    15,
      28,    43,    44,    45,    30,    51,    15,    30,    50,    28,
       6,     7,    30,    55,    28,    57,    58,    33,    34,    35,
      36,     4,     5,    39,    15,    15,    15,    43,    44,    45,
      26,    51,    15,    15,    50,    11,     4,     5,     6,    55,
      51,    57,    58,    33,    34,    35,    36,    15,    44,    39,
      15,    15,    48,    43,    44,    45,    11,    32,    15,    28,
      50,    28,     4,     5,    15,    55,    28,    57,    58,    33,
      34,    35,    36,    15,    15,    39,    15,    15,    51,    43,
      44,    45,    29,    28,    11,    17,    50,    15,    14,    15,
      16,    55,    29,    57,    58,    33,    34,    35,    36,    29,
      40,    39,    28,    15,    37,    43,    44,    45,    30,    30,
      30,    28,    50,    28,    28,    11,    15,    55,    29,    57,
      58,    33,    34,    35,    36,    30,    52,    39,    15,    55,
      30,    43,    44,    45,    11,    30,    30,    29,    50,    30,
      29,    19,    30,    55,    30,    57,    58,    34,    35,    36,
      30,    38,    39,    15,     4,     5,    43,    44,    45,    30,
      30,    11,    66,    50,     6,    15,    22,    14,    55,    71,
      57,    58,    34,    35,    36,    -1,    95,    39,    15,   114,
      42,    43,    44,    45,    -1,   148,    -1,    -1,    50,    14,
      15,    16,    -1,    55,    -1,    57,    58,    34,    35,    36,
      -1,    -1,    39,    28,    -1,    -1,    43,    44,    45,    -1,
      -1,    -1,    -1,    50,    14,    15,    16,    -1,    55,    -1,
      57,    58,    -1,    48,    49,    -1,    -1,    52,    28,    29,
      55,    56,    14,    15,    16,    -1,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      28,    29,    52,    12,    -1,    55,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     9,
      52,    30,    12,    55,    52,    -1,    -1,    55,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    12,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    12,    -1,    30,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       9,    -1,    30,    12,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     9,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    12,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    12,    -1,    30,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      12,    29,    -1,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    12,    29,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    12,    29,    -1,    -1,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    12,    29,
      -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    12,    -1,    -1,    -1,    -1,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       4,     5,     4,     5,    -1,     4,     5,    11,    -1,    11,
      -1,    15,    11,    15,    -1,    -1,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    46,    53,    61,    62,    68,    73,    82,
       4,     5,     6,    15,    74,    75,    76,    13,    15,    63,
      64,    15,    69,    70,    71,     0,    68,    73,    82,    73,
      82,     4,    76,    78,    79,    82,     6,    75,    15,    77,
      28,    10,    47,    64,    10,    59,    54,    70,    10,    73,
      82,    78,    82,    78,    82,    15,    79,    82,     8,    28,
       7,    30,    29,     4,     5,    15,    65,    66,    67,    73,
      15,    73,    78,    82,    82,    82,    28,    16,    76,    80,
      81,    15,    10,    11,    66,    15,    11,    72,    79,    11,
      72,    82,    80,     9,    15,     7,    29,     8,    28,     3,
      32,    83,    30,    11,    79,    11,    29,    81,    16,    80,
       4,     5,     6,    15,    84,    85,    86,    15,    33,    34,
      35,    36,    39,    43,    44,    45,    50,    55,    57,    58,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   106,    32,    10,     9,
      29,     6,    85,    15,    87,     8,    17,    51,    11,    28,
      28,    28,    28,    30,    30,    14,    15,    16,    28,    30,
      52,    55,   104,   106,   107,    28,    51,    28,    30,    33,
      89,    17,    51,    33,    88,    32,    83,     7,    30,   104,
      48,    49,    56,   104,    15,    15,   106,   104,   104,   104,
       8,    28,    51,   104,    51,    12,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    30,    51,    15,    15,
      15,   106,    11,    56,   104,    15,    11,    33,    88,    32,
      15,     9,    28,    28,    28,    30,     8,    29,    29,    29,
      29,    29,   104,    29,   104,   105,    15,    29,    15,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
      15,    29,    29,    28,    30,    11,    33,    88,    17,    29,
      29,    15,   104,    30,    30,    30,    37,    40,     9,     7,
      29,    28,    28,    28,    30,    30,    15,    11,    33,   104,
      30,    30,    29,     9,    88,    88,   104,    29,   105,    29,
     105,   105,    29,    11,    30,    30,    29,    38,    41,    42,
      29,    29,    29,    30,    30,    30,    88,    30,    42,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    62,    63,    63,    64,    65,    65,
      66,    67,    67,    67,    68,    69,    69,    70,    70,    70,
      70,    71,    72,    72,    73,    73,    74,    74,    75,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      83,    83,    84,    84,    85,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    91,    91,    92,
      93,    94,    95,    95,    96,    97,    98,    99,    99,   100,
     101,   101,   101,   102,   103,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   105,   105,
     106,   106,   106,   107,   107,   107,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     4,     3,     2,     4,     3,
       2,     3,     2,     1,     3,     2,     1,     4,     2,     1,
       3,     1,     1,     1,     3,     2,     1,     5,     4,     5,
       4,     3,     2,     1,     3,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     6,     4,     6,     4,     2,     1,
      11,    10,     3,     1,     2,     0,    10,     9,     9,     8,
       3,     2,     2,     1,     3,     1,     1,     1,     3,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     7,     7,     5,
       2,     2,     3,     2,     6,     6,     5,    10,     8,     8,
       5,     8,     5,     5,     4,     7,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     4,     4,     3,     1,     1,     3,     1,
       3,     3,     3,     6,     6,     5,     6,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 102 "parser.y"
                        {
				class_func_code_gen((yyvsp[-3].class_node));	
				func_code_gen((yyvsp[-1].tree_node));
				return 0;
			}
#line 1787 "y.tab.c"
    break;

  case 3:
#line 108 "parser.y"
                        {
				class_func_code_gen((yyvsp[-2].class_node));
				return 0;
			}
#line 1796 "y.tab.c"
    break;

  case 4:
#line 113 "parser.y"
                        {
				class_func_code_gen((yyvsp[-1].class_node));
				return 0;
			}
#line 1805 "y.tab.c"
    break;

  case 5:
#line 118 "parser.y"
                        {
				class_func_code_gen((yyvsp[-3].class_node));
				func_code_gen((yyvsp[-1].tree_node));
				return 0;
			}
#line 1815 "y.tab.c"
    break;

  case 6:
#line 124 "parser.y"
                        {	
				class_func_code_gen((yyvsp[-2].class_node));
				return 0;
			}
#line 1824 "y.tab.c"
    break;

  case 7:
#line 129 "parser.y"
                        {
				class_func_code_gen((yyvsp[-1].class_node));
				return 0;
			}
#line 1833 "y.tab.c"
    break;

  case 8:
#line 134 "parser.y"
                        {
				func_code_gen((yyvsp[-1].tree_node));
				return 0;
			}
#line 1842 "y.tab.c"
    break;

  case 9:
#line 139 "parser.y"
                        {
				return 0;
			}
#line 1850 "y.tab.c"
    break;

  case 10:
#line 143 "parser.y"
                        {
				return 0;
			}
#line 1858 "y.tab.c"
    break;

  case 11:
#line 147 "parser.y"
                        {
				func_code_gen((yyvsp[-1].tree_node));
				return 0;
			}
#line 1867 "y.tab.c"
    break;

  case 12:
#line 152 "parser.y"
                        {	
				return 0;
			}
#line 1875 "y.tab.c"
    break;

  case 13:
#line 157 "parser.y"
                        {
				return 0;
			}
#line 1883 "y.tab.c"
    break;

  case 14:
#line 164 "parser.y"
                        {
				type_head=(yyvsp[-1].table_node);	
	
				printf("\n");
                                print_type_table(type_head);
			}
#line 1894 "y.tab.c"
    break;

  case 15:
#line 174 "parser.y"
                        {
				struct type_table* temp=(yyvsp[-1].table_node);
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=(yyvsp[0].table_node);
					
				(yyval.table_node)=(yyvsp[-1].table_node);
				type_head=(yyval.table_node);
			}
#line 1908 "y.tab.c"
    break;

  case 16:
#line 184 "parser.y"
                        {
				(yyval.table_node)=(yyvsp[0].table_node);
				type_head=(yyval.table_node);
			}
#line 1917 "y.tab.c"
    break;

  case 17:
#line 192 "parser.y"
                        {			
				(yyval.table_node)=create_t_entry_node((yyvsp[-3].tree_node)->varname,field_index,69+(rand_no++));  

				set_field_type(type_head,(yyvsp[-1].field_node));
				set_field_type((yyval.table_node),(yyvsp[-1].field_node));	
				(yyval.table_node)->f_list=(yyvsp[-1].field_node);	

				field_index=0;
				
				f_list_head=NULL;
			}
#line 1933 "y.tab.c"
    break;

  case 18:
#line 207 "parser.y"
                        {	
				struct field_list* temp=(yyvsp[-1].field_node);
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=(yyvsp[0].field_node);
				
				(yyval.field_node)=(yyvsp[-1].field_node);
				f_list_head=(yyval.field_node);
			}
#line 1947 "y.tab.c"
    break;

  case 19:
#line 217 "parser.y"
                        {	
				(yyval.field_node)=(yyvsp[0].field_node);
				f_list_head=(yyval.field_node);			
			}
#line 1956 "y.tab.c"
    break;

  case 20:
#line 225 "parser.y"
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}
				else
					(yyval.field_node)=create_field_entry((yyvsp[-1].tree_node)->varname,field_index++,(yyvsp[-2].string));	
			}
#line 1970 "y.tab.c"
    break;

  case 21:
#line 238 "parser.y"
                        {(yyval.string)="inttype";}
#line 1976 "y.tab.c"
    break;

  case 22:
#line 240 "parser.y"
                        {(yyval.string)="strtype";}
#line 1982 "y.tab.c"
    break;

  case 23:
#line 242 "parser.y"
                        {(yyval.string)=(yyvsp[0].tree_node)->varname;}
#line 1988 "y.tab.c"
    break;

  case 24:
#line 247 "parser.y"
                        {
                                class_head=(yyvsp[-1].class_node);
				(yyval.class_node)=class_head;	

    				printf("\n------------------\n");
             			print_class_list(class_head);
				printf("------------------\n");
                        }
#line 2001 "y.tab.c"
    break;

  case 25:
#line 259 "parser.y"
                        {
                                struct class* temp=(yyvsp[-1].class_node);
                                while(temp->next!=NULL)
                                        temp=temp->next;
                                temp->next=(yyvsp[0].class_node);

                                (yyval.class_node)=(yyvsp[-1].class_node);
                                class_head=(yyval.class_node);
                        }
#line 2015 "y.tab.c"
    break;

  case 26:
#line 269 "parser.y"
                        {
                                (yyval.class_node)=(yyvsp[0].class_node);
                                class_head=(yyval.class_node);
                        }
#line 2024 "y.tab.c"
    break;

  case 27:
#line 277 "parser.y"
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}

				set_class_name((yyvsp[-1].tree_node),(yyvsp[-4].tree_node)->varname);		

				(yyval.class_node)=create_c_node((yyvsp[-4].tree_node)->varname,field_index,420+(rand_no++));   
                                (yyval.class_node)->decl_list=(yyvsp[-2].gs_node);	
				(yyval.class_node)->func_list=(yyvsp[-1].tree_node);				
				
				field_index=0;
                        
				cst_head=NULL;					
				line_var=NULL;
				decl_flag=1;
                        }
#line 2048 "y.tab.c"
    break;

  case 28:
#line 297 "parser.y"
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}

				(yyval.class_node)=create_c_node((yyvsp[-3].tree_node)->varname,field_index,420+(rand_no++));	
                                (yyval.class_node)->decl_list=(yyvsp[-1].gs_node);

				field_index=0;
    
				cst_head=NULL;					
				line_var=NULL;
				decl_flag=1;	
                        }
#line 2069 "y.tab.c"
    break;

  case 29:
#line 314 "parser.y"
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}

				set_class_name((yyvsp[-1].tree_node),(yyvsp[-4].tree_node)->varname);
				
				(yyval.class_node)=create_c_node((yyvsp[-4].tree_node)->varname,extend_size+field_index,420+(rand_no++));					
				(yyval.class_node)->decl_list=(yyvsp[-2].gs_node);

				if(extend_func_list!=NULL)
				{
					(yyval.class_node)->func_list=create_t_node(-1,"-",-1,"+C",connect,current_block,(yyvsp[-1].tree_node),extend_func_list);
					fix_func_list((yyval.class_node)->func_list);	
					extend_func_list=NULL;
				}
				else
					(yyval.class_node)->func_list=(yyvsp[-1].tree_node);
			
				field_index=0;
				extend_size=0;
				
				cst_head=NULL;
				line_var=NULL;
				decl_flag=1;
			}
#line 2102 "y.tab.c"
    break;

  case 30:
#line 343 "parser.y"
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}
				
				(yyval.class_node)=create_c_node((yyvsp[-3].tree_node)->varname,extend_size+field_index,420+(rand_no++));						
				(yyval.class_node)->decl_list=(yyvsp[-1].gs_node);

				if(extend_func_list!=NULL)
				{
					(yyval.class_node)->func_list=extend_func_list;
					fix_func_list((yyval.class_node)->func_list);
					extend_func_list=NULL;
				}
			
				field_index=0;
				extend_size=0;
			
				cst_head=NULL;
				line_var=NULL;
				decl_flag=1;
			}
#line 2131 "y.tab.c"
    break;

  case 31:
#line 371 "parser.y"
                        {
				extend_head=get_class_decl_list(class_head,(yyvsp[0].tree_node)->varname);
				extend_size=get_class_field_size(class_head,(yyvsp[0].tree_node)->varname);
				extend_func_list=copy_t_node(get_class_func_list(class_head,(yyvsp[0].tree_node)->varname));	
				update_func_list(extend_func_list,(yyvsp[-2].tree_node)->varname,(yyvsp[0].tree_node)->varname);
				extend_flag=1;

				(yyval.tree_node)=(yyvsp[-2].tree_node);
			}
#line 2145 "y.tab.c"
    break;

  case 32:
#line 384 "parser.y"
                        {
				(yyval.tree_node)=create_t_node(-1,"-",-1,"+C",connect,current_block,(yyvsp[-1].tree_node),(yyvsp[0].tree_node));
                        }
#line 2153 "y.tab.c"
    break;

  case 33:
#line 388 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2159 "y.tab.c"
    break;

  case 34:
#line 394 "parser.y"
                        {
				if(class_flag==0)				
                                {
					gv_pointer++;			
					struct symbol* temp=(yyvsp[-1].gs_node);		
					while(temp->next!=NULL)		
						temp=temp->next;				
					temp->next=create_s_node("self",420,9,gv_pointer,NULL,0);
					gv_pointer+=8;

					gst_head=(yyvsp[-1].gs_node);
				
					printf("\n\n|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");	
                                	print_table((yyvsp[-1].gs_node));
					printf("|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");
		
					current_block=saved_block_no;		
				}
				if(class_flag==1)				
				{
					if(extend_head!=NULL)
					{
						if(extend_size+field_index>8)
						{
							printf("MAX FIELD ENTRIES : 8\n");
							exit(0);
						}
		
						struct symbol* temp_1=change_f_label(extend_head);
						struct symbol* temp_2=temp_1;
						while(temp_2->next!=NULL)
							temp_2=temp_2->next;
						temp_2->next=copy_extend_head((yyvsp[-1].gs_node),field_index);

						fix_decl_list(temp_1);

						cst_head=temp_1;
						(yyval.gs_node)=temp_1;
						
						extend_head=NULL;
					}
					else
					{
						cst_head=(yyvsp[-1].gs_node);
						(yyval.gs_node)=(yyvsp[-1].gs_node);
					}
					
					printf("\n\n|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");
                        		print_table((yyval.gs_node));
                          		printf("|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");

                              		current_block++;
					
				}				
                        }
#line 2219 "y.tab.c"
    break;

  case 35:
#line 450 "parser.y"
                        {
				if(class_flag==0)				
                                {
					gst_head=NULL;
			
					current_block=saved_block_no;		
				}
				if(class_flag==0)				
				{
					cst_head=NULL;				
					(yyval.gs_node)=NULL;
					current_block++;
				}
                        }
#line 2238 "y.tab.c"
    break;

  case 36:
#line 468 "parser.y"
                        {
				if(class_flag==0)				
                                {
					struct symbol* temp=(yyvsp[-1].gs_node);
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                                	temp->next=(yyvsp[0].gs_node);
                                	(yyval.gs_node)=(yyvsp[-1].gs_node);
                                	gst_head=(yyval.gs_node);
					line_var=NULL;
				}
				if(class_flag==1)				
				{
					struct symbol* temp=(yyvsp[-1].gs_node);
					while(temp->next!=NULL)
						temp=temp->next;
					temp->next=(yyvsp[0].gs_node);
					(yyval.gs_node)=(yyvsp[-1].gs_node);
					cst_head=(yyval.gs_node);				
					line_var=NULL;
				}
                        }
#line 2265 "y.tab.c"
    break;

  case 37:
#line 491 "parser.y"
                        {
                                if(class_flag==0)				
				{
					(yyval.gs_node)=(yyvsp[0].gs_node);
                                	gst_head=(yyval.gs_node);
					line_var=NULL;
				}
				if(class_flag==1)				
				{
					(yyval.gs_node)=(yyvsp[0].gs_node);
					cst_head=(yyval.gs_node);				
					line_var=NULL;
				}
                        }
#line 2284 "y.tab.c"
    break;

  case 38:
#line 509 "parser.y"
                        {
                                set_type((yyvsp[-1].gs_node),(yyvsp[-2].integer));

				if((yyvsp[-2].integer)>420)		
				{
					set_size_to((yyvsp[-1].gs_node),9);
					gv_pointer+=8;
				}

                                (yyval.gs_node)=(yyvsp[-1].gs_node);
                        }
#line 2300 "y.tab.c"
    break;

  case 39:
#line 524 "parser.y"
                        {(yyval.integer)=inttype;}
#line 2306 "y.tab.c"
    break;

  case 40:
#line 526 "parser.y"
                        {(yyval.integer)=strtype;}
#line 2312 "y.tab.c"
    break;

  case 41:
#line 528 "parser.y"
                        {	
				int type=find_type_type(type_head,(yyvsp[0].tree_node)->varname);
				if(type==-1)
					type=find_class_type(class_head,(yyvsp[0].tree_node)->varname);
				if(type==-1)
				{
					printf("NO TYPE/CLASS DEF FOUND\n");
					exit(0);
				}
				else 
					(yyval.integer)=type;				
			}
#line 2329 "y.tab.c"
    break;

  case 42:
#line 544 "parser.y"
                        {
				if(class_flag==0)				
                                {
					gv_pointer++;
                                	struct symbol* temp=(yyvsp[-2].gs_node);
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                               		temp->next=create_s_node((yyvsp[0].tree_node)->varname,-2,1,gv_pointer,NULL,0);
                                
					(yyval.gs_node)=(yyvsp[-2].gs_node);
                                	line_var=(yyval.gs_node);
				}
				if(class_flag==1)				
				{
					struct symbol* temp=(yyvsp[-2].gs_node);
					while(temp->next!=NULL)
						temp=temp->next;		
					temp->next=create_s_node((yyvsp[0].tree_node)->varname,-2,1,field_index++,NULL,0);
					(yyval.gs_node)=(yyvsp[-2].gs_node);
					line_var=(yyval.gs_node);
				}
                        }
#line 2356 "y.tab.c"
    break;

  case 43:
#line 567 "parser.y"
                        {
				if(class_flag==0)				
                                {
					gv_pointer++;
                                	(yyval.gs_node)=create_s_node((yyvsp[0].tree_node)->varname,-2,1,gv_pointer,NULL,0);
                                	line_var=(yyval.gs_node);
				}
				if(class_flag==1)				
				{
					(yyval.gs_node)=create_s_node((yyvsp[0].tree_node)->varname,-2,1,field_index++,NULL,0);
					line_var=(yyval.gs_node);
				}
  		      	}
#line 2374 "y.tab.c"
    break;

  case 44:
#line 582 "parser.y"
                        {
				if(class_flag==0)				
                                {
					int size=(yyvsp[-1].tree_node)->val;
                                	int start_addrs=gv_pointer+1;
                                	int j=(yyvsp[-1].tree_node)->val;

                                	struct symbol* temp=(yyvsp[-5].gs_node);
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                                	temp->next=create_s_node((yyvsp[-3].tree_node)->varname,-2,size,start_addrs,NULL,j);

                                	gv_pointer+=size;
				
					(yyval.gs_node)=(yyvsp[-5].gs_node);
                                	line_var=(yyval.gs_node);
				}
				if(class_flag==1)				
				{
					printf("ARRAY FIELD IN CLASS NOT ALLOWED\n");
					exit(0);
				}
                        }
#line 2402 "y.tab.c"
    break;

  case 45:
#line 607 "parser.y"
                        {
				if(class_flag==0)				
                                {
					int size=(yyvsp[-1].tree_node)->val;
                                	int start_addrs=gv_pointer+1;
                                	int j=(yyvsp[-1].tree_node)->val;
                                	(yyval.gs_node)=create_s_node((yyvsp[-3].tree_node)->varname,-2,size,start_addrs,NULL,j);

                                	gv_pointer+=size;
				
                                	line_var=(yyval.gs_node);
				}
				if(class_flag==1)				
				{
					printf("ARRAY FIELD IN CLASS NOT ALLOWED\n");
					exit(0);
				}
                        }
#line 2425 "y.tab.c"
    break;

  case 46:
#line 627 "parser.y"
                        {
				if(class_flag==0)				
				{
					struct symbol* temp=(yyvsp[-5].gs_node);
                                	while(temp->next!=NULL)
                                        	temp=temp->next;

					temp->next=create_s_node((yyvsp[-3].tree_node)->varname,-2,0,-1,(yyvsp[-1].param_node),0);	
					temp->next->f_label=getlabel();
			
                                	arg_pointer=0;

					(yyval.gs_node)=(yyvsp[-5].gs_node);
                                	line_var=(yyval.gs_node);
					param_head=NULL;
				}
				if(class_flag==1)				
				{				
					struct symbol* temp=(yyvsp[-5].gs_node);
					while(temp->next!=NULL)
						temp=temp->next;
		
					temp->next=create_s_node((yyvsp[-3].tree_node)->varname,-2,0,-1,(yyvsp[-1].param_node),0);	
					temp->next->f_label=getlabel();

					arg_pointer=0;

					(yyval.gs_node)=(yyvsp[-5].gs_node);
					line_var=(yyval.gs_node);
					param_head=NULL;
				}
			
			}
#line 2463 "y.tab.c"
    break;

  case 47:
#line 661 "parser.y"
                        {
				if(class_flag==0)				
				{
					(yyval.gs_node)=create_s_node((yyvsp[-3].tree_node)->varname,-2,0,-1,(yyvsp[-1].param_node),0);	
					(yyval.gs_node)->f_label=getlabel();

					arg_pointer=0;

                                	line_var=(yyval.gs_node);
					param_head=NULL;
				}
				if(class_flag==1)				
				{
					(yyval.gs_node)=create_s_node((yyvsp[-3].tree_node)->varname,-2,0,-1,(yyvsp[-1].param_node),0);
					(yyval.gs_node)->f_label=getlabel();
				
					arg_pointer=0;
				
					line_var=(yyval.gs_node);
					param_head=NULL;
				}
                        }
#line 2490 "y.tab.c"
    break;

  case 48:
#line 687 "parser.y"
                        {
				(yyval.tree_node)=create_t_node(-1,"-",-1,"+C",connect,current_block,(yyvsp[-1].tree_node),(yyvsp[0].tree_node));
			}
#line 2498 "y.tab.c"
    break;

  case 49:
#line 691 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2504 "y.tab.c"
    break;

  case 50:
#line 696 "parser.y"
                        {
				if(find_type(cst_head,(yyvsp[-9].tree_node)->varname)!=(yyvsp[-10].integer))		
				{
					if(find_type(gst_head,(yyvsp[-9].tree_node)->varname)!=(yyvsp[-10].integer))		
					{
						printf("FUNCTION DECLARATION NOT FOUND\n");
						exit(0);
					}
				}
				if(check_arg_list(find_func_arg_list(cst_head),(yyvsp[-7].param_node))==0)
				{
					if(check_arg_list(find_func_arg_list(gst_head),(yyvsp[-7].param_node))==0)
                        		{
						printf("PARAM_DECL INCORRECT\n");
                                      		exit(0);
					}
                              	}

				printf("\n---------------------------------\n");
				print_tree((yyvsp[-2].tree_node));	
				printf("\n---------------------------------");

				if(class_flag==1)		
					(yyval.tree_node)=create_t_node(-1,"-CHANGE-",-1,(yyvsp[-9].tree_node)->varname,function,current_block,(yyvsp[-2].tree_node),NULL);
				if(class_flag==0)		
					(yyval.tree_node)=create_t_node(-1,"-",-1,(yyvsp[-9].tree_node)->varname,function,current_block,(yyvsp[-2].tree_node),NULL);
					
				(yyval.tree_node)->l_var_list=(yyvsp[-4].gs_node);

				current_block++;
				line_head=NULL;
				line_var=NULL;			
				param_head=NULL;			
			}
#line 2543 "y.tab.c"
    break;

  case 51:
#line 731 "parser.y"
                        {
				if(find_type(cst_head,(yyvsp[-8].tree_node)->varname)!=(yyvsp[-9].integer))		
                               	{
					if(find_type(gst_head,(yyvsp[-8].tree_node)->varname)!=(yyvsp[-9].integer))		
					{
                                        	printf("FUNCTION DECLARATION NOT FOUND\n");
                                        	exit(0);
					}
                                }
				if(check_arg_list(find_func_arg_list(cst_head),(yyvsp[-6].param_node))==0)
				{
					if(check_arg_list(find_func_arg_list(gst_head),(yyvsp[-6].param_node))==0)
					{
                                        	printf("PARAM_DECL INCORRECT\n");
                                        	exit(0);
					}
                                }
                              
                        	printf("\n---------------------------------\n");
                        	print_tree((yyvsp[-2].tree_node));
                         	printf("\n---------------------------------");
			
				if(class_flag==1)		
					(yyval.tree_node)=create_t_node(-1,"-CHANGE-",-1,(yyvsp[-8].tree_node)->varname,function,current_block,(yyvsp[-2].tree_node),NULL);
				if(class_flag==0)		
					(yyval.tree_node)=create_t_node(-1,"-",-1,(yyvsp[-8].tree_node)->varname,function,current_block,(yyvsp[-2].tree_node),NULL);

                            	current_block++;
                           	line_head=NULL;
				line_var=NULL;       
				param_head=NULL;					 
                        }
#line 2580 "y.tab.c"
    break;

  case 52:
#line 768 "parser.y"
                        {
				struct param_struct* temp=(yyvsp[-2].param_node);
				while(temp->next!=NULL)
                                        temp=temp->next;
				temp->next=(yyvsp[0].param_node);
				
				(yyval.param_node)=(yyvsp[-2].param_node);
				param_head=(yyval.param_node);
			}
#line 2594 "y.tab.c"
    break;

  case 53:
#line 778 "parser.y"
                        {(yyval.param_node)=(yyvsp[0].param_node);}
#line 2600 "y.tab.c"
    break;

  case 54:
#line 783 "parser.y"
                        {
				arg_pointer--;
				(yyval.param_node)=create_param_node((yyvsp[0].tree_node)->varname,arg_pointer,(yyvsp[-1].integer));
				param_head=(yyval.param_node);
			}
#line 2610 "y.tab.c"
    break;

  case 55:
#line 789 "parser.y"
                        {
				(yyval.param_node)=NULL;
			}
#line 2618 "y.tab.c"
    break;

  case 56:
#line 797 "parser.y"
                        {
				printf("\n---------------------------------\n");
                                print_tree((yyvsp[-2].tree_node));
				printf("\n---------------------------------\n");

				main_code_gen((yyvsp[-2].tree_node),gv_pointer);
		
				current_block++;
	
				line_head=NULL;
				line_var=NULL;

                        }
#line 2636 "y.tab.c"
    break;

  case 57:
#line 811 "parser.y"
                        {
                                printf("\n---------------------------------\n");
                                print_tree((yyvsp[-2].tree_node));
                                printf("\n---------------------------------\n");

                                main_code_gen((yyvsp[-2].tree_node),gv_pointer);
			
				current_block++;
				
				line_head=NULL;
				line_var=NULL;

                        }
#line 2654 "y.tab.c"
    break;

  case 58:
#line 825 "parser.y"
                        {
				current_block++;
				line_head=NULL;
				line_var=NULL;
			}
#line 2664 "y.tab.c"
    break;

  case 59:
#line 831 "parser.y"
                        {
				current_block++;
				line_head=NULL;
				line_var=NULL;
			}
#line 2674 "y.tab.c"
    break;

  case 60:
#line 840 "parser.y"
                        {
                                list[current_block].lst_head=(yyvsp[-1].gs_node);
				lv_pointer=0;				

                                printf("\n\n|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");
                                print_table((yyvsp[-1].gs_node));
				printf("|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");

				(yyval.gs_node)=(yyvsp[-1].gs_node);
		        }
#line 2689 "y.tab.c"
    break;

  case 61:
#line 851 "parser.y"
                        {
                                list[current_block].lst_head=NULL;
				lv_pointer=0;
				
				(yyval.gs_node)=NULL;
                        }
#line 2700 "y.tab.c"
    break;

  case 62:
#line 861 "parser.y"
                        {
                                struct symbol* temp=(yyvsp[-1].gs_node);
                                while(temp->next!=NULL)
                                        temp=temp->next;
                                temp->next=(yyvsp[0].gs_node);
                                (yyval.gs_node)=(yyvsp[-1].gs_node);
                                line_head=(yyval.gs_node);
                        }
#line 2713 "y.tab.c"
    break;

  case 63:
#line 870 "parser.y"
                        {
                                (yyval.gs_node)=(yyvsp[0].gs_node);
                                line_head=(yyval.gs_node);

                        }
#line 2723 "y.tab.c"
    break;

  case 64:
#line 879 "parser.y"
                        {
                                set_type((yyvsp[-1].gs_node),(yyvsp[-2].integer));
				
				if((yyvsp[-2].integer)>420)			
				{
					set_size_to((yyvsp[-1].gs_node),9);
					if(main_flag==1)
						gv_pointer+=8;
					else
						lv_pointer+=8;
				}
	
				(yyval.gs_node)=(yyvsp[-1].gs_node);
                        }
#line 2742 "y.tab.c"
    break;

  case 65:
#line 897 "parser.y"
                        {(yyval.integer)=inttype;}
#line 2748 "y.tab.c"
    break;

  case 66:
#line 899 "parser.y"
                        {(yyval.integer)=strtype;}
#line 2754 "y.tab.c"
    break;

  case 67:
#line 901 "parser.y"
                        {
				int type=find_type_type(type_head,(yyvsp[0].tree_node)->varname);
				if(type==-1)
				{
					printf("TYPE/CLASS DEF NOT FOUND\n");
					exit(0);
				}
				else
					(yyval.integer)=type;
			}
#line 2769 "y.tab.c"
    break;

  case 68:
#line 915 "parser.y"
                        {
				if(main_flag==1)
                                {
					gv_pointer++;
                                	struct symbol* temp=(yyvsp[-2].gs_node);
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                                	temp->next=create_s_node((yyvsp[0].tree_node)->varname,-2,1,gv_pointer,NULL,0);
                                }
				else 
				{	
					lv_pointer++;
                                        struct symbol* temp=(yyvsp[-2].gs_node);
                                        while(temp->next!=NULL)
                                                temp=temp->next;
                                        temp->next=create_s_node((yyvsp[0].tree_node)->varname,-2,1,lv_pointer,NULL,0);
                                }
				(yyval.gs_node)=(yyvsp[-2].gs_node);
                                line_var=(yyval.gs_node);
                        }
#line 2794 "y.tab.c"
    break;

  case 69:
#line 936 "parser.y"
                        {
				if(main_flag==1)
                                {
					gv_pointer++;
                                	(yyval.gs_node)=create_s_node((yyvsp[0].tree_node)->varname,-2,1,gv_pointer,NULL,0);
                                }
				else 
				{
					lv_pointer++;
                                        (yyval.gs_node)=create_s_node((yyvsp[0].tree_node)->varname,-2,1,lv_pointer,NULL,0);
				}
				line_var=(yyval.gs_node);
                      	}
#line 2812 "y.tab.c"
    break;

  case 70:
#line 953 "parser.y"
                        {	
				(yyval.tree_node)=create_t_node(-1,"-",-1,"+C",connect,current_block,(yyvsp[-1].tree_node),(yyvsp[0].tree_node));
			}
#line 2820 "y.tab.c"
    break;

  case 71:
#line 957 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2826 "y.tab.c"
    break;

  case 72:
#line 962 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2832 "y.tab.c"
    break;

  case 73:
#line 964 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2838 "y.tab.c"
    break;

  case 74:
#line 966 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2844 "y.tab.c"
    break;

  case 75:
#line 968 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2850 "y.tab.c"
    break;

  case 76:
#line 970 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2856 "y.tab.c"
    break;

  case 77:
#line 972 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2862 "y.tab.c"
    break;

  case 78:
#line 974 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2868 "y.tab.c"
    break;

  case 79:
#line 976 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2874 "y.tab.c"
    break;

  case 80:
#line 978 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2880 "y.tab.c"
    break;

  case 81:
#line 980 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2886 "y.tab.c"
    break;

  case 82:
#line 982 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2892 "y.tab.c"
    break;

  case 83:
#line 984 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2898 "y.tab.c"
    break;

  case 84:
#line 986 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2904 "y.tab.c"
    break;

  case 85:
#line 988 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 2910 "y.tab.c"
    break;

  case 86:
#line 994 "parser.y"
                        {
				(yyval.tree_node)=create_t_node(-1,"-",-1,"+BRKP",brk_point,current_block,NULL,NULL);
			}
#line 2918 "y.tab.c"
    break;

  case 87:
#line 1000 "parser.y"
                        {
				
				int type=find_class_type(class_head,(yyvsp[-2].tree_node)->varname);
				if((yyvsp[-6].tree_node)->type!=type)
				{
					if((yyvsp[-6].tree_node)->type<=420 || type<=420)
					{
						printf("TYPE MISMATCH\n");
						exit(0);
					}
					else
						(yyvsp[-6].tree_node)->type=type;
				}					

				struct t_node* t1=create_t_node(-1,"-",-1,"+ALLOC",heap_alloc_stmt,current_block,(yyvsp[-6].tree_node),NULL);
				struct t_node* t2=create_t_node(-1,"-",-1,"+VRTBL",vr_tbl_alloc,current_block,(yyvsp[-6].tree_node),(yyvsp[-2].tree_node));

				(yyval.tree_node)=create_t_node(-1,"-",-1,"+C",connect,current_block,t1,t2);
			}
#line 2942 "y.tab.c"
    break;

  case 88:
#line 1020 "parser.y"
                        {
				int type=find_class_type(class_head,(yyvsp[-2].tree_node)->varname);
				if((yyvsp[-6].tree_node)->type!=type)
				{
					if((yyvsp[-6].tree_node)->type<=420 || type<=420)
					{
						printf("TYPE MISMATCH\n");
						exit(0);
					}
					else
						(yyvsp[-6].tree_node)->type=type;
				}
				
				struct t_node* t1=create_t_node(-1,"-",-1,"+ALLOC",heap_alloc_stmt,current_block,(yyvsp[-6].tree_node),NULL);
				struct t_node* t2=create_t_node(-1,"-",-1,"+VRTBL",vr_tbl_alloc,current_block,(yyvsp[-6].tree_node),(yyvsp[-2].tree_node));
				(yyval.tree_node)=create_t_node(-1,"-",-1,"+C",connect,current_block,t1,t2);
			}
#line 2964 "y.tab.c"
    break;

  case 89:
#line 1041 "parser.y"
                        {
				if((yyvsp[-2].tree_node)->type<=420)
				{
					printf("NOT USER DEF CLASS\n");
					exit(0);
				}
				else
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+FREE",heap_free_stmt,current_block,(yyvsp[-2].tree_node),NULL);
			}
#line 2978 "y.tab.c"
    break;

  case 90:
#line 1054 "parser.y"
                        {(yyval.tree_node)=create_t_node(-1,"-",-1,"+CONT",cont_stmt,current_block,NULL,NULL);}
#line 2984 "y.tab.c"
    break;

  case 91:
#line 1060 "parser.y"
                        {(yyval.tree_node)=create_t_node(-1,"-",-1,"+BRK",brk_stmt,current_block,NULL,NULL);}
#line 2990 "y.tab.c"
    break;

  case 92:
#line 1065 "parser.y"
                        {
				if(main_flag==0)
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+RET",ret_stmt,current_block,(yyvsp[-1].tree_node),NULL);
				else
					(yyval.tree_node)=NULL;
			}
#line 3001 "y.tab.c"
    break;

  case 93:
#line 1072 "parser.y"
                        {
				if(main_flag==0)
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+RET",ret_stmt,current_block,NULL,NULL);
				else 
					(yyval.tree_node)=NULL;
			}
#line 3012 "y.tab.c"
    break;

  case 94:
#line 1083 "parser.y"
                        {
				if((yyvsp[-5].tree_node)->type != inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+INIT",heap_init_stmt,current_block,(yyvsp[-5].tree_node),NULL);
			}
#line 3026 "y.tab.c"
    break;

  case 95:
#line 1099 "parser.y"
                        {
				if((yyvsp[-5].tree_node)->type<=69 || (yyvsp[-5].tree_node)->type>=420)	
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+ALLOC",heap_alloc_stmt,current_block,(yyvsp[-5].tree_node),NULL);	
			}
#line 3040 "y.tab.c"
    break;

  case 96:
#line 1112 "parser.y"
                        {
				if((yyvsp[-2].tree_node)->type<=69 || (yyvsp[-2].tree_node)->type>=420)
                                {
                                        printf("NOT USER DEFINED TYPE\n");
                                        exit(0);
                                }
                                else
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+FREE",heap_free_stmt,current_block,(yyvsp[-2].tree_node),NULL);
			}
#line 3054 "y.tab.c"
    break;

  case 97:
#line 1126 "parser.y"
                        { 
				if((yyvsp[-7].tree_node)->type != boolean)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else
				{
					struct t_node* temp;
					temp=create_t_node(-1,"-",-1,"+EL",else_part,current_block,(yyvsp[-4].tree_node),(yyvsp[-2].tree_node));
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+IF",if_part,current_block,(yyvsp[-7].tree_node),temp);
				}
			}
#line 3072 "y.tab.c"
    break;

  case 98:
#line 1140 "parser.y"
                        {
				if((yyvsp[-5].tree_node)->type != boolean)
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
				{
					struct t_node* temp;
					temp=create_t_node(-1,"-",-1,"+EL",else_part,current_block,(yyvsp[-2].tree_node),NULL);
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+IF",if_part,current_block,(yyvsp[-5].tree_node),temp);
				}
			}
#line 3090 "y.tab.c"
    break;

  case 99:
#line 1157 "parser.y"
                        {
				if((yyvsp[-5].tree_node)->type != boolean)
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+WHILE",while_do,current_block,(yyvsp[-5].tree_node),(yyvsp[-2].tree_node));
			}
#line 3104 "y.tab.c"
    break;

  case 100:
#line 1170 "parser.y"
                        {(yyval.tree_node)=create_t_node(-1,"-",-1,"+R",read,current_block,(yyvsp[-2].tree_node),NULL);}
#line 3110 "y.tab.c"
    break;

  case 101:
#line 1172 "parser.y"
                        {
				if((yyvsp[-3].tree_node)->type != inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else if(find_array_size(gst_head,(yyvsp[-5].tree_node)->varname)==0)
                                {
                                        printf("ARRAY DECLARATION NOT FOUND\n");
                                        exit(0);
                                }
				else
				{
					(yyvsp[-5].tree_node)->node_type=leaf_arr;
                                	(yyvsp[-5].tree_node)->right=(yyvsp[-3].tree_node);
				
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+R",read,current_block,(yyvsp[-5].tree_node),NULL);
				}
			}
#line 3134 "y.tab.c"
    break;

  case 102:
#line 1192 "parser.y"
                        {(yyval.tree_node)=create_t_node(-1,"-",-1,"+R",read,current_block,(yyvsp[-2].tree_node),NULL);}
#line 3140 "y.tab.c"
    break;

  case 103:
#line 1197 "parser.y"
                        {(yyval.tree_node)=create_t_node(-1,"-",-1,"+W",write,current_block,(yyvsp[-2].tree_node),NULL);}
#line 3146 "y.tab.c"
    break;

  case 104:
#line 1202 "parser.y"
                        {
				if(((yyvsp[-3].tree_node)->type==inttype) && ((yyvsp[-1].tree_node)->type==inttype))
				{
					(yyval.tree_node)=create_t_node(-1,"-",inttype,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node)); 
				}
				else if(((yyvsp[-3].tree_node)->type==strtype) && ((yyvsp[-1].tree_node)->type==strtype))
				{
                                        (yyval.tree_node)=create_t_node(-1,"-",strtype,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
                                }
				else if((yyvsp[-3].tree_node)->type==(yyvsp[-1].tree_node)->type)	
				{
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
				}
				else if(((yyvsp[-3].tree_node)->type>69)&&((yyvsp[-3].tree_node)->type<420)&&((yyvsp[-1].tree_node)->type==420))	
				{
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
				}
				else if(((yyvsp[-3].tree_node)->type>420) && ((yyvsp[-1].tree_node)->type>420))
				{
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
				}
				else 
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
			}
#line 3178 "y.tab.c"
    break;

  case 105:
#line 1231 "parser.y"
                        {
				if((yyvsp[-4].tree_node)->type!=inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else if(find_array_size(gst_head,(yyvsp[-6].tree_node)->varname)==0)
                                {
                                        printf("ARRAY DECLARATION NOT FOUND\n");
                                        exit(0);
                                }
				else
					if(((yyvsp[-6].tree_node)->type==inttype) && ((yyvsp[-1].tree_node)->type==inttype))
                                	{
						(yyvsp[-6].tree_node)->node_type=leaf_arr;
                                		(yyvsp[-6].tree_node)->right=(yyvsp[-4].tree_node);
					
						(yyval.tree_node)=create_t_node(-1,"-",inttype,"+A",assgn,current_block,(yyvsp[-6].tree_node),(yyvsp[-1].tree_node));
					}
					else if(((yyvsp[-6].tree_node)->type==strtype) && ((yyvsp[-1].tree_node)->type==strtype))
                                	{
						(yyvsp[-6].tree_node)->node_type=leaf_arr;
                                        	(yyvsp[-6].tree_node)->right=(yyvsp[-4].tree_node);

                                        	(yyval.tree_node)=create_t_node(-1,"-",strtype,"+A",assgn,current_block,(yyvsp[-6].tree_node),(yyvsp[-1].tree_node));
                                	}
					else
                                	{
                                        	printf("TYPE MISMATCH\n");
                                        	exit(0);
                                	}
                     	}
#line 3215 "y.tab.c"
    break;

  case 106:
#line 1264 "parser.y"
                        {
				if(((yyvsp[-3].tree_node)->type==inttype) && ((yyvsp[-1].tree_node)->type==inttype))
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",inttype,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
                                }
                                else if(((yyvsp[-3].tree_node)->type==strtype) && ((yyvsp[-1].tree_node)->type==strtype))
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",strtype,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
                                }
				else if((yyvsp[-3].tree_node)->type==(yyvsp[-1].tree_node)->type)
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
                                }
				else if(((yyvsp[-3].tree_node)->type>69)&&((yyvsp[-3].tree_node)->type<420)&&((yyvsp[-1].tree_node)->type==420))		
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,"+A",assgn,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
                                }
                                else
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
			}
#line 3243 "y.tab.c"
    break;

  case 107:
#line 1291 "parser.y"
                        {
				if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
				{
					printf("TYPE MISMATCH\n");		
					exit(0);
				}
				else
					(yyval.tree_node)=create_t_node(-1,"-",inttype,"+OP",plus,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
			}
#line 3257 "y.tab.c"
    break;

  case 108:
#line 1301 "parser.y"
                        {
                                if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",inttype,"+OP",sub,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
			}
#line 3271 "y.tab.c"
    break;

  case 109:
#line 1311 "parser.y"
                        {
                                if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("--TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                       	(yyval.tree_node)=create_t_node(-1,"-",inttype,"+OP",mul,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
			}
#line 3285 "y.tab.c"
    break;

  case 110:
#line 1321 "parser.y"
                        {
                                if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",inttype,"+OP",div,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
			}
#line 3299 "y.tab.c"
    break;

  case 111:
#line 1332 "parser.y"
                        {
                                if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",inttype,"+OP",mod,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                        }
#line 3313 "y.tab.c"
    break;

  case 112:
#line 1343 "parser.y"
                        {
				if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",greater_than,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
			}
#line 3327 "y.tab.c"
    break;

  case 113:
#line 1354 "parser.y"
                        {
				if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",less_than,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                        }
#line 3341 "y.tab.c"
    break;

  case 114:
#line 1365 "parser.y"
                        {

				if(((yyvsp[-2].tree_node)->type==inttype) && ((yyvsp[0].tree_node)->type==inttype))
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",not_equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                                }
                                else if(((yyvsp[-2].tree_node)->type==strtype) && ((yyvsp[0].tree_node)->type==strtype))
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",not_equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                                }
				else if(((yyvsp[-2].tree_node)->type==(yyvsp[0].tree_node)->type) || (((yyvsp[-2].tree_node)->type>69)&&((yyvsp[-2].tree_node)->type<420)&&((yyvsp[0].tree_node)->type==420))) 
                                {
					(yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",not_equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                                }
                                else
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }

                        }
#line 3367 "y.tab.c"
    break;

  case 115:
#line 1388 "parser.y"
                        {
				
				if(((yyvsp[-2].tree_node)->type==inttype) && ((yyvsp[0].tree_node)->type==inttype))
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                                }
                                else if(((yyvsp[-2].tree_node)->type==strtype) && ((yyvsp[0].tree_node)->type==strtype))
                                {
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                                }
				else if(((yyvsp[-2].tree_node)->type==(yyvsp[0].tree_node)->type) || (((yyvsp[-2].tree_node)->type>69)&&((yyvsp[-2].tree_node)->type<420)&&((yyvsp[0].tree_node)->type==420))) 
				{
					(yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
				}
                                else
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }

                        }
#line 3393 "y.tab.c"
    break;

  case 116:
#line 1411 "parser.y"
                        {
                                if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",greater_equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                        }
#line 3407 "y.tab.c"
    break;

  case 117:
#line 1422 "parser.y"
                        {
                                if(((yyvsp[-2].tree_node)->type!=inttype) || ((yyvsp[0].tree_node)->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        (yyval.tree_node)=create_t_node(-1,"-",boolean,"+BOP",less_equal,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
                        }
#line 3421 "y.tab.c"
    break;

  case 118:
#line 1433 "parser.y"
                        {(yyval.tree_node)=(yyvsp[-1].tree_node);}
#line 3427 "y.tab.c"
    break;

  case 119:
#line 1435 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 3433 "y.tab.c"
    break;

  case 120:
#line 1437 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 3439 "y.tab.c"
    break;

  case 121:
#line 1439 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 3445 "y.tab.c"
    break;

  case 122:
#line 1441 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 3451 "y.tab.c"
    break;

  case 123:
#line 1443 "parser.y"
                        {
				if((yyvsp[-1].tree_node)->type!=inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else if(find_array_size(gst_head,(yyvsp[-3].tree_node)->varname)==0)
				{
					printf("ARRAY DECLARATION NOT FOUND\n");
					exit(0);
				}
				else					
				{	
					(yyvsp[-3].tree_node)->node_type=leaf_arr;
					(yyvsp[-3].tree_node)->right=(yyvsp[-1].tree_node);
				
					(yyval.tree_node)=(yyvsp[-3].tree_node);
				}
			}
#line 3475 "y.tab.c"
    break;

  case 124:
#line 1464 "parser.y"
                        {
				int type=find_type(gst_head,(yyvsp[-3].tree_node)->varname);	
                                (yyval.tree_node)=create_t_node(-1,"-",type,"+FOP",func_call,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
			}
#line 3484 "y.tab.c"
    break;

  case 125:
#line 1469 "parser.y"
                        {
				int type=find_type(gst_head,(yyvsp[-2].tree_node)->varname);
				(yyval.tree_node)=create_t_node(-1,"-",type,"+FOP",func_call,current_block,(yyvsp[-2].tree_node),NULL);
			}
#line 3493 "y.tab.c"
    break;

  case 126:
#line 1474 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 3499 "y.tab.c"
    break;

  case 127:
#line 1476 "parser.y"
                        {(yyval.tree_node)=(yyvsp[0].tree_node);}
#line 3505 "y.tab.c"
    break;

  case 128:
#line 1481 "parser.y"
                        {
				if((yyvsp[0].tree_node)->type<0)
                                {
                                        printf("ARGUMENTS TYPE ERROR\n");
                                        exit(0);
                                }
				else
				{
					(yyval.tree_node)=create_t_node(-1,"-",-1,"+C",connect,current_block,(yyvsp[-2].tree_node),(yyvsp[0].tree_node));
				}			
			}
#line 3521 "y.tab.c"
    break;

  case 129:
#line 1493 "parser.y"
                        {
				if((yyvsp[0].tree_node)->type<0)
				{
					printf("ARGUMENTS TYPE ERROR\n");
					exit(0);
				}
				else
					(yyval.tree_node)=(yyvsp[0].tree_node);
			}
#line 3535 "y.tab.c"
    break;

  case 130:
#line 1505 "parser.y"
                        {
				(yyvsp[-2].tree_node)->type=(yyvsp[0].tree_node)->type;
				struct t_node* temp=(yyvsp[-2].tree_node);
				while(temp->left!=NULL)
					temp=temp->left;
				temp->left=(yyvsp[0].tree_node);			
			}
#line 3547 "y.tab.c"
    break;

  case 131:
#line 1513 "parser.y"
                        {
				if(check_type_type(type_head,(yyvsp[-2].tree_node)->type)>69)	
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[0].tree_node)->type,(yyvsp[-2].tree_node)->varname,leaf_tf,current_block,(yyvsp[0].tree_node),NULL);
				if(check_class_type(class_head,(yyvsp[-2].tree_node)->type)>420)		
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[0].tree_node)->type,(yyvsp[-2].tree_node)->varname,leaf_cf,current_block,(yyvsp[0].tree_node),NULL); 	
			}
#line 3558 "y.tab.c"
    break;

  case 132:
#line 1520 "parser.y"
                        {
				(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[0].tree_node)->type,"self",leaf_cf,current_block,(yyvsp[0].tree_node),NULL);
			}
#line 3566 "y.tab.c"
    break;

  case 133:
#line 1527 "parser.y"
                        {
					if((yyvsp[-5].tree_node)->node_type==leaf_cf)		
					{
						printf("NOT ALLOWED\n");
						exit(0);
					}
					(yyvsp[-5].tree_node)->type=(yyvsp[-3].tree_node)->type;
					(yyvsp[-5].tree_node)->node_type=cf_func_call;
					struct t_node* temp=(yyvsp[-5].tree_node);
					while(temp->left!=NULL)
						temp=temp->left;
					temp->left=(yyvsp[-3].tree_node);				
					temp->right=(yyvsp[-1].tree_node);
				
					(yyval.tree_node)=(yyvsp[-5].tree_node);
			}
#line 3587 "y.tab.c"
    break;

  case 134:
#line 1544 "parser.y"
                        {
				if(main_flag==1 && extend_flag==1)
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,(yyvsp[-5].tree_node)->varname,class_func_call,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
				else
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,(yyvsp[-5].tree_node)->varname,cf_func_call,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));
			}
#line 3598 "y.tab.c"
    break;

  case 135:
#line 1551 "parser.y"
                        {
				if(main_flag==1 && extend_flag==1)
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-2].tree_node)->type,(yyvsp[-4].tree_node)->varname,class_func_call,current_block,(yyvsp[-2].tree_node),NULL);
				else
					(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-2].tree_node)->type,(yyvsp[-4].tree_node)->varname,cf_func_call,current_block,(yyvsp[-2].tree_node),NULL);
			}
#line 3609 "y.tab.c"
    break;

  case 136:
#line 1558 "parser.y"
                        {
                        	(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-3].tree_node)->type,"self",cf_func_call,current_block,(yyvsp[-3].tree_node),(yyvsp[-1].tree_node));		
			}
#line 3617 "y.tab.c"
    break;

  case 137:
#line 1562 "parser.y"
                        {
				(yyval.tree_node)=create_t_node(-1,"-",(yyvsp[-2].tree_node)->type,"self",cf_func_call,current_block,(yyvsp[-2].tree_node),NULL);
			}
#line 3625 "y.tab.c"
    break;


#line 3629 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 1568 "parser.y"


int yyerror(char *msg)
{
	printf("Error:%s\n",msg);
	exit(0);
}

int main(int argc,char *argv[])
{	
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	target_file=fopen("test.o","w");
	
	for(int i=0;i<100;i++)
		list[i].lst_head=NULL;
	
	yyparse();
	return 0;
}

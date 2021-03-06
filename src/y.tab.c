/* A Bison parser, made by GNU Bison 3.7.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "asCodeGen.h"

FILE *targetOut;
int varsCount = 0;
int ifCount = 0;
int loopCount = 0;
float expr1;
float expr2;
char *logicOp;
int yylex();
char *type;
void yyerror (char const *);
void declarationCheck(char *s);
int returnIndex(char *s);
extern void symlook(char *);
void printTable();


#line 96 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_MAINCLASS = 258,             /* T_MAINCLASS  */
    T_PUBLIC = 259,                /* T_PUBLIC  */
    T_STATIC = 260,                /* T_STATIC  */
    T_VOID = 261,                  /* T_VOID  */
    T_MAIN = 262,                  /* T_MAIN  */
    T_PRINTLN = 263,               /* T_PRINTLN  */
    T_INT = 264,                   /* T_INT  */
    T_FLOAT = 265,                 /* T_FLOAT  */
    T_FOR = 266,                   /* T_FOR  */
    T_WHILE = 267,                 /* T_WHILE  */
    T_IF = 268,                    /* T_IF  */
    T_EQUAL = 269,                 /* T_EQUAL  */
    T_ID = 270,                    /* T_ID  */
    T_NUM = 271,                   /* T_NUM  */
    T_SMALLER = 272,               /* T_SMALLER  */
    T_BIGGER = 273,                /* T_BIGGER  */
    T_NOTEQUAL = 274,              /* T_NOTEQUAL  */
    T_ELSE = 275                   /* T_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define T_MAINCLASS 258
#define T_PUBLIC 259
#define T_STATIC 260
#define T_VOID 261
#define T_MAIN 262
#define T_PRINTLN 263
#define T_INT 264
#define T_FLOAT 265
#define T_FOR 266
#define T_WHILE 267
#define T_IF 268
#define T_EQUAL 269
#define T_ID 270
#define T_NUM 271
#define T_SMALLER 272
#define T_BIGGER 273
#define T_NOTEQUAL 274
#define T_ELSE 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "parser.y"
 double dval; struct symtab *symp; 

#line 191 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_MAINCLASS = 3,                /* T_MAINCLASS  */
  YYSYMBOL_T_PUBLIC = 4,                   /* T_PUBLIC  */
  YYSYMBOL_T_STATIC = 5,                   /* T_STATIC  */
  YYSYMBOL_T_VOID = 6,                     /* T_VOID  */
  YYSYMBOL_T_MAIN = 7,                     /* T_MAIN  */
  YYSYMBOL_T_PRINTLN = 8,                  /* T_PRINTLN  */
  YYSYMBOL_T_INT = 9,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 10,                   /* T_FLOAT  */
  YYSYMBOL_T_FOR = 11,                     /* T_FOR  */
  YYSYMBOL_T_WHILE = 12,                   /* T_WHILE  */
  YYSYMBOL_T_IF = 13,                      /* T_IF  */
  YYSYMBOL_T_EQUAL = 14,                   /* T_EQUAL  */
  YYSYMBOL_T_ID = 15,                      /* T_ID  */
  YYSYMBOL_T_NUM = 16,                     /* T_NUM  */
  YYSYMBOL_T_SMALLER = 17,                 /* T_SMALLER  */
  YYSYMBOL_T_BIGGER = 18,                  /* T_BIGGER  */
  YYSYMBOL_T_NOTEQUAL = 19,                /* T_NOTEQUAL  */
  YYSYMBOL_T_ELSE = 20,                    /* T_ELSE  */
  YYSYMBOL_21_ = 21,                       /* '='  */
  YYSYMBOL_22_ = 22,                       /* '<'  */
  YYSYMBOL_23_ = 23,                       /* '>'  */
  YYSYMBOL_24_ = 24,                       /* '+'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '('  */
  YYSYMBOL_29_ = 29,                       /* ')'  */
  YYSYMBOL_30_ = 30,                       /* '{'  */
  YYSYMBOL_31_ = 31,                       /* '}'  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* ','  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_PROGRAM = 35,                   /* PROGRAM  */
  YYSYMBOL_COMP_STMT = 36,                 /* COMP_STMT  */
  YYSYMBOL_STMT_LIST = 37,                 /* STMT_LIST  */
  YYSYMBOL_STMT = 38,                      /* STMT  */
  YYSYMBOL_DECLARATION = 39,               /* DECLARATION  */
  YYSYMBOL_TYPE = 40,                      /* TYPE  */
  YYSYMBOL_ID_LIST = 41,                   /* ID_LIST  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_NULL_STMT = 43,                 /* NULL_STMT  */
  YYSYMBOL_ASSIGN_STMT = 44,               /* ASSIGN_STMT  */
  YYSYMBOL_ASSIGN_EXPR = 45,               /* ASSIGN_EXPR  */
  YYSYMBOL_EXPR = 46,                      /* EXPR  */
  YYSYMBOL_FOR_STMT = 47,                  /* FOR_STMT  */
  YYSYMBOL_48_2 = 48,                      /* $@2  */
  YYSYMBOL_49_3 = 49,                      /* $@3  */
  YYSYMBOL_OPASSIGN_EXPR = 50,             /* OPASSIGN_EXPR  */
  YYSYMBOL_OPBOOL_EXPR = 51,               /* OPBOOL_EXPR  */
  YYSYMBOL_WHILE_STMT = 52,                /* WHILE_STMT  */
  YYSYMBOL_53_4 = 53,                      /* $@4  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_IF_STMT = 55,                   /* IF_STMT  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_58_8 = 58,                      /* $@8  */
  YYSYMBOL_ELSE_PART = 59,                 /* ELSE_PART  */
  YYSYMBOL_BOOL_EXPR = 60,                 /* BOOL_EXPR  */
  YYSYMBOL_C_OP = 61,                      /* C_OP  */
  YYSYMBOL_RVAL = 62,                      /* RVAL  */
  YYSYMBOL_TERM = 63,                      /* TERM  */
  YYSYMBOL_FACTOR = 64                     /* FACTOR  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   94

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,    26,    24,    33,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      22,    21,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    57,    60,    61,    64,    65,    66,    67,
      68,    69,    70,    71,    74,    77,    78,    81,    81,    82,
      85,    88,    91,   104,   105,   108,   109,   108,   115,   116,
     119,   120,   123,   123,   123,   130,   131,   131,   130,   134,
     135,   138,   141,   142,   143,   144,   145,   146,   149,   150,
     151,   154,   155,   160,   163,   164,   165,   166
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_MAINCLASS",
  "T_PUBLIC", "T_STATIC", "T_VOID", "T_MAIN", "T_PRINTLN", "T_INT",
  "T_FLOAT", "T_FOR", "T_WHILE", "T_IF", "T_EQUAL", "T_ID", "T_NUM",
  "T_SMALLER", "T_BIGGER", "T_NOTEQUAL", "T_ELSE", "'='", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "','",
  "$accept", "PROGRAM", "COMP_STMT", "STMT_LIST", "STMT", "DECLARATION",
  "TYPE", "ID_LIST", "$@1", "NULL_STMT", "ASSIGN_STMT", "ASSIGN_EXPR",
  "EXPR", "FOR_STMT", "$@2", "$@3", "OPASSIGN_EXPR", "OPBOOL_EXPR",
  "WHILE_STMT", "$@4", "$@5", "IF_STMT", "$@6", "$@7", "$@8", "ELSE_PART",
  "BOOL_EXPR", "C_OP", "RVAL", "TERM", "FACTOR", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    61,    60,    62,    43,    45,    42,    47,    40,    41,
     123,   125,    59,    44
};
#endif

#define YYPACT_NINF (-54)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,     5,    35,     7,   -54,    38,    40,    43,    47,    22,
      29,    32,   -54,    36,    -2,   -54,    41,   -54,   -54,    44,
     -54,   -54,    45,   -54,   -54,   -54,   -54,   -54,    48,   -54,
     -54,    39,   -54,   -54,   -54,    16,    53,    46,    49,    16,
      50,    52,   -54,    45,   -54,    18,    16,   -54,    51,     2,
      13,   -54,   -54,    55,    16,    16,   -54,    37,   -54,   -54,
     -54,    56,    57,    18,    18,    18,    18,   -54,    42,    61,
      62,    48,   -54,   -54,    13,    13,   -54,   -54,    16,   -54,
     -54,   -54,   -54,   -54,   -54,    16,   -54,   -54,   -54,   -54,
     -54,   -54,     6,     6,    60,   -54,   -54,    53,    73,    65,
       6,   -54,     6,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     2,     0,    15,    16,     0,
      32,    35,     0,     3,    20,    10,     5,    11,     0,    12,
       6,     0,     7,     8,     9,     0,    28,     0,     0,     0,
      17,     0,    21,    56,    57,     0,     0,    23,     0,    24,
      50,    53,    29,     0,     0,     0,    22,     0,    14,    56,
      55,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,    54,    13,    48,    49,    51,    52,    30,    42,
      45,    46,    47,    43,    44,     0,    33,    36,    18,    26,
      31,    41,     0,     0,     0,    34,    37,    28,    39,     0,
       0,    38,     0,    40,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,    64,   -54,   -45,   -54,   -54,    10,   -54,   -54,
     -54,   -14,   -34,   -54,   -54,   -54,   -24,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -53,   -54,   -54,   -11,
     -42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    25,    14,    26,    27,    28,    41,    57,    29,
      30,    47,    68,    32,    78,    94,    53,    89,    33,    37,
      92,    34,    38,    93,    98,   101,    69,    85,    49,    50,
      51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    48,    70,    60,     1,    56,    16,    17,    18,    19,
      20,    21,    61,    22,    16,    17,    18,    19,    20,    21,
       3,    22,    52,    76,    77,    90,    63,    64,    12,    23,
      24,    43,    44,    59,    44,     4,    12,     5,    24,    65,
      66,    45,     6,    45,    46,     7,    46,    95,    96,     8,
      10,    91,    74,    75,     9,   103,    79,   104,    11,    80,
      81,    82,    12,    40,    83,    84,    39,    15,    22,    35,
      71,    42,    36,    99,    54,    13,     0,    55,    31,    31,
      62,    88,   -19,    52,    58,    72,    31,    67,    31,    73,
      86,    87,    97,   100,   102
};

static const yytype_int8 yycheck[] =
{
      14,    35,    55,    45,     3,    39,     8,     9,    10,    11,
      12,    13,    46,    15,     8,     9,    10,    11,    12,    13,
      15,    15,    36,    65,    66,    78,    24,    25,    30,    31,
      32,    15,    16,    15,    16,     0,    30,    30,    32,    26,
      27,    25,     4,    25,    28,     5,    28,    92,    93,     6,
      28,    85,    63,    64,     7,   100,    14,   102,    29,    17,
      18,    19,    30,    15,    22,    23,    21,    31,    15,    28,
      33,    32,    28,    97,    28,    11,    -1,    28,    92,    93,
      29,    71,    32,    97,    32,    29,   100,    32,   102,    32,
      29,    29,    32,    20,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    35,    15,     0,    30,     4,     5,     6,     7,
      28,    29,    30,    36,    37,    31,     8,     9,    10,    11,
      12,    13,    15,    31,    32,    36,    38,    39,    40,    43,
      44,    45,    47,    52,    55,    28,    28,    53,    56,    21,
      15,    41,    32,    15,    16,    25,    28,    45,    46,    62,
      63,    64,    45,    50,    28,    28,    46,    42,    32,    15,
      64,    46,    29,    24,    25,    26,    27,    32,    46,    60,
      60,    33,    29,    32,    63,    63,    64,    64,    48,    14,
      17,    18,    19,    22,    23,    61,    29,    29,    41,    51,
      60,    46,    54,    57,    49,    38,    38,    32,    58,    50,
      20,    59,    29,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    37,    37,    38,    38,    38,    38,
      38,    38,    38,    38,    39,    40,    40,    42,    41,    41,
      43,    44,    45,    46,    46,    48,    49,    47,    50,    50,
      51,    51,    53,    54,    52,    56,    57,    58,    55,    59,
      59,    60,    61,    61,    61,    61,    61,    61,    62,    62,
      62,    63,    63,    63,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    11,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     5,     3,     1,     1,     0,     4,     1,
       1,     2,     3,     1,     1,     0,     0,    11,     0,     1,
       0,     1,     0,     0,     7,     0,     0,     0,     9,     0,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     1,     3,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 13: /* STMT: T_PRINTLN '(' EXPR ')' ';'  */
#line 71 "parser.y"
                                                                             {printOut(ids);}
#line 1295 "y.tab.c"
    break;

  case 15: /* TYPE: T_INT  */
#line 77 "parser.y"
                                        {char *s="int" ; type =  strdup(s);}
#line 1301 "y.tab.c"
    break;

  case 16: /* TYPE: T_FLOAT  */
#line 78 "parser.y"
                                                          {char *s="flt" ; type =  strdup(s);}
#line 1307 "y.tab.c"
    break;

  case 17: /* $@1: %empty  */
#line 81 "parser.y"
                               { symlook(ids); declarationOut(ids); }
#line 1313 "y.tab.c"
    break;

  case 19: /* ID_LIST: T_ID  */
#line 82 "parser.y"
                                                       { symlook(ids); declarationOut(ids); }
#line 1319 "y.tab.c"
    break;

  case 22: /* ASSIGN_EXPR: T_ID '=' EXPR  */
#line 91 "parser.y"
                                {	declarationCheck(ids);
															char *tp = "int";
														  if (!strcmp((yyvsp[-2].symp)->type, tp)){
																	 (yyvsp[-2].symp)->valueD = (yyvsp[0].dval) ;
																	 (yyvsp[-2].symp)->valueI = (int)((yyvsp[0].dval)+0.01);
															}
														  else	{
																	(yyvsp[-2].symp)->valueD = (yyvsp[0].dval) ;
															}
															assignOut((yyvsp[-2].symp)->name);							//ASSIGN
														}
#line 1335 "y.tab.c"
    break;

  case 25: /* $@2: %empty  */
#line 108 "parser.y"
                                                      { fprintf(targetOut,"\n\tWhile%d:", loopCount); }
#line 1341 "y.tab.c"
    break;

  case 26: /* $@3: %empty  */
#line 109 "parser.y"
                                                                                                             { forBoolOut((int)(expr1), (int)(expr2)); }
#line 1347 "y.tab.c"
    break;

  case 27: /* FOR_STMT: T_FOR '(' OPASSIGN_EXPR ';' $@2 OPBOOL_EXPR $@3 ';' OPASSIGN_EXPR ')' STMT  */
#line 110 "parser.y"
                                                                                                                      {	fprintf(targetOut, "\n\n\tj While%d\n", loopCount);
												/*ASSIGN*/							fprintf(targetOut, "\n\nExit%d:\n", loopCount);
																								loopCount++;}
#line 1355 "y.tab.c"
    break;

  case 32: /* $@4: %empty  */
#line 123 "parser.y"
                                  { fprintf(targetOut,"\n\tWhile%d:", loopCount); }
#line 1361 "y.tab.c"
    break;

  case 33: /* $@5: %empty  */
#line 123 "parser.y"
                                                                                                      {	whileBoolOut((int)(expr1), (int)(expr2));
																																														}
#line 1368 "y.tab.c"
    break;

  case 34: /* WHILE_STMT: T_WHILE $@4 '(' BOOL_EXPR ')' $@5 STMT  */
#line 125 "parser.y"
                                                                                                                                                                                                                                                                                                                                                                                     {	fprintf(targetOut, "\n\n\tj While%d\n", loopCount);
																																														fprintf(targetOut, "\n\nExit%d:\n", loopCount);
																																														loopCount++;}
#line 1376 "y.tab.c"
    break;

  case 35: /* $@6: %empty  */
#line 130 "parser.y"
                                       {instructionsOut("\n\t#If statement");}
#line 1382 "y.tab.c"
    break;

  case 36: /* $@7: %empty  */
#line 131 "parser.y"
                                                                                                  { ifBoolOut((int)(expr1), (int)(expr2)); }
#line 1388 "y.tab.c"
    break;

  case 37: /* $@8: %empty  */
#line 131 "parser.y"
                                                                                                                                                  {fprintf(targetOut, "\n\tj EndIf%d\n", ifCount); elseOut();}
#line 1394 "y.tab.c"
    break;

  case 38: /* IF_STMT: T_IF $@6 '(' BOOL_EXPR ')' $@7 STMT $@8 ELSE_PART  */
#line 131 "parser.y"
                                                                                                                                                                                                                         { endif(); ifCount++;}
#line 1400 "y.tab.c"
    break;

  case 41: /* BOOL_EXPR: EXPR C_OP EXPR  */
#line 138 "parser.y"
                                                 {expr1 = (yyvsp[-2].dval); expr2 = (yyvsp[0].dval);}
#line 1406 "y.tab.c"
    break;

  case 42: /* C_OP: T_EQUAL  */
#line 141 "parser.y"
                                                  { logicOp = strdup("bne"); }
#line 1412 "y.tab.c"
    break;

  case 43: /* C_OP: '<'  */
#line 142 "parser.y"
                                                              { logicOp = strdup("bgt");}
#line 1418 "y.tab.c"
    break;

  case 44: /* C_OP: '>'  */
#line 143 "parser.y"
                                                              { logicOp = strdup("blt");}
#line 1424 "y.tab.c"
    break;

  case 45: /* C_OP: T_SMALLER  */
#line 144 "parser.y"
                                                                    { logicOp = strdup("bge");}
#line 1430 "y.tab.c"
    break;

  case 46: /* C_OP: T_BIGGER  */
#line 145 "parser.y"
                                                                   { logicOp = strdup("ble");}
#line 1436 "y.tab.c"
    break;

  case 47: /* C_OP: T_NOTEQUAL  */
#line 146 "parser.y"
                                                                     { logicOp = strdup("beq");}
#line 1442 "y.tab.c"
    break;

  case 48: /* RVAL: RVAL '+' TERM  */
#line 149 "parser.y"
                                                        { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); addOut(); }
#line 1448 "y.tab.c"
    break;

  case 49: /* RVAL: RVAL '-' TERM  */
#line 150 "parser.y"
                                                                        { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); substractOut(); }
#line 1454 "y.tab.c"
    break;

  case 51: /* TERM: TERM '*' FACTOR  */
#line 154 "parser.y"
                                                          { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); multOut(); }
#line 1460 "y.tab.c"
    break;

  case 52: /* TERM: TERM '/' FACTOR  */
#line 155 "parser.y"
                                                                          { if ((yyvsp[0].dval) == 0)
																		yyerror("divide by zero");
							    								else
																		(yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval); divOut();
							 									}
#line 1470 "y.tab.c"
    break;

  case 54: /* FACTOR: '(' EXPR ')'  */
#line 163 "parser.y"
                                                { (yyval.dval) = (yyvsp[-1].dval); }
#line 1476 "y.tab.c"
    break;

  case 55: /* FACTOR: '-' FACTOR  */
#line 164 "parser.y"
                                                                        { (yyval.dval) = -(yyvsp[0].dval); negative(); }
#line 1482 "y.tab.c"
    break;

  case 56: /* FACTOR: T_ID  */
#line 165 "parser.y"
                                                                        { (yyval.dval) = (yyvsp[0].symp)->valueD; factorOutId((yyvsp[0].symp)->name, (int)((yyvsp[0].symp)->valueD)); varsCount++; }
#line 1488 "y.tab.c"
    break;

  case 57: /* FACTOR: T_NUM  */
#line 166 "parser.y"
                                                                        { (yyval.dval) = (yyvsp[0].dval); factorOutNum((int)((yyvsp[0].dval))); varsCount++; }
#line 1494 "y.tab.c"
    break;


#line 1498 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 167 "parser.y"


#include "asCodeGen.c"

void scopeHandle(char *c){
	if (!strcmp(c,"}")){
		struct symtab *st;
		for (st = &symtab[NSYMS-1]; st > symtab-1; st--) {
			if (!st->name){
				continue;
			}
			if (strcmp(st->name, "{")){
				st->name = '\0';
				st->valueI = 0;
				st->valueD = 0;
				st->type = '\0';
			}
			else{
				st->name = '\0';
				st->valueI = 0;
				st->valueD = 0;
				st->type = '\0';
				break;
			}
		}
	}
	else if(!strcmp(c,"{")){
		struct symtab *st;
		for(st = symtab; st < &symtab[NSYMS]; st++){
			if(!st->name){
				st->name = strdup("{" );
				break;
			}
		}
	}
	//printTable();
}

void printTable()
{
    printf("Print out the symbol table:\n\n");

    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++)
    {
        	printf("name: %s\t"
                "valueD: %f\t"
								"ValueI: %d\t"
		 						"Type: %s\t\n",
                sp->name,
                sp->valueD,
	        			sp->valueI,
								sp->type);
    }
}

int returnIndex(char *s){
    int counter = 0;
		int abstrctForSymbol=0;
		char *st = "{";
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            return counter-abstrctForSymbol;
        }
				if(sp->name && !strcmp(sp->name, st))
					abstrctForSymbol++;
				counter ++;
    }
}

void declarationCheck(char *s){
    int flag = 0;
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            flag = 1;
        }
    }
    if(!flag)
		yyerror("Variable has not be declared\n");
}

void symlook(char *s) {
    printf("Putting %s into the symbol table\n", s);
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            yyerror("already in symbol table\n");
            exit(1);
        }
        if(!sp->name) { /* is it free ? */
            sp->name = strdup(s);
	    			sp->valueI = 0;
	    			sp->valueD = 0;
	    			sp->type = strdup(type);
						break;
        }
        /* otherwise continue to next */
    }
		printTable();
}


void yyerror (const char * msg)
{
  	fprintf(stderr, "C-like : %s\n", msg);
  	exit(1);
}

struct symtab *returnStrucktPointer(char *n){
		struct symtab *sp;
		//sp = symtab;
		for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        if(sp->name && !strcmp(sp->name, n))
        {
            return sp;
        }
				if(!sp->name) {
      			break;
        }
    }
}


int main ()
{
	/*DEBUG TOOL*/
	#if YYDEBUG ==0
	extern int yydebug;
	yydebug=1;
	#endif


	/*TARGET CODE GENERATION*/
	targetOut = fopen("target.asm", "w");

	dataOut();

  if(!yyparse())
		printf("Parsed Successfully !!!\n");

	instructionsOut("\n\nli	$v0 10\n\tsyscall\n");
	instructionsOut("\nprintl:\n");
  instructionsOut("li $v0, 1\n \tmove $a0, $s0\n \tsyscall\n\n \tli $v0, 4\n \tla $a0, newLine\n \tsyscall\n\n \tjr $ra\n");

	fclose(targetOut);
}

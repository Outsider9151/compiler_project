/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"

<<<<<<< HEAD
extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}


#line 86 "y.tab.cpp"
=======
extern A_program root;
extern int yylex(void);

void yyerror(const char *s);

#line 81 "y.tab.cpp"
>>>>>>> 57849de (新尝试，有bug)

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

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
<<<<<<< HEAD
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUB = 4,                        /* SUB  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_LPAREN = 8,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 9,                     /* RPAREN  */
  YYSYMBOL_AND = 10,                       /* AND  */
  YYSYMBOL_OR = 11,                        /* OR  */
  YYSYMBOL_NOT = 12,                       /* NOT  */
  YYSYMBOL_GREATER = 13,                   /* GREATER  */
  YYSYMBOL_LESS = 14,                      /* LESS  */
  YYSYMBOL_GREATER_EQ = 15,                /* GREATER_EQ  */
  YYSYMBOL_LESS_EQ = 16,                   /* LESS_EQ  */
  YYSYMBOL_EQUAL = 17,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 18,                 /* NOT_EQUAL  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_FN_CALL = 20,                   /* FN_CALL  */
  YYSYMBOL_LET = 21,                       /* LET  */
  YYSYMBOL_COLON = 22,                     /* COLON  */
  YYSYMBOL_COMMA = 23,                     /* COMMA  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_STRUCT = 28,                    /* STRUCT  */
  YYSYMBOL_FN = 29,                        /* FN  */
  YYSYMBOL_ARROW = 30,                     /* ARROW  */
  YYSYMBOL_RET = 31,                       /* RET  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_CONTINUE = 33,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_IF = 35,                        /* IF  */
  YYSYMBOL_ELSE = 36,                      /* ELSE  */
  YYSYMBOL_WHILE = 37,                     /* WHILE  */
  YYSYMBOL_INT = 38,                       /* INT  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_NUM = 40,                       /* NUM  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_ProgramElementList = 43,        /* ProgramElementList  */
  YYSYMBOL_ProgramElement = 44,            /* ProgramElement  */
  YYSYMBOL_FnDeclStmt = 45,                /* FnDeclStmt  */
  YYSYMBOL_CodeBlockStmt = 46,             /* CodeBlockStmt  */
  YYSYMBOL_ReturnStmt = 47,                /* ReturnStmt  */
  YYSYMBOL_CallStmt = 48,                  /* CallStmt  */
  YYSYMBOL_WhileStmt = 49,                 /* WhileStmt  */
  YYSYMBOL_IfStmt = 50,                    /* IfStmt  */
  YYSYMBOL_FnDef = 51,                     /* FnDef  */
  YYSYMBOL_CodeBlockStmtList = 52,         /* CodeBlockStmtList  */
  YYSYMBOL_ParamDecl = 53,                 /* ParamDecl  */
  YYSYMBOL_FnDecl = 54,                    /* FnDecl  */
  YYSYMBOL_StructDef = 55,                 /* StructDef  */
  YYSYMBOL_VarDeclList = 56,               /* VarDeclList  */
  YYSYMBOL_VarDeclStmt = 57,               /* VarDeclStmt  */
  YYSYMBOL_VarDef = 58,                    /* VarDef  */
  YYSYMBOL_VarDefArray = 59,               /* VarDefArray  */
  YYSYMBOL_VarDefScalar = 60,              /* VarDefScalar  */
  YYSYMBOL_VarDecl = 61,                   /* VarDecl  */
  YYSYMBOL_VarDeclArray = 62,              /* VarDeclArray  */
  YYSYMBOL_VarDeclScalar = 63,             /* VarDeclScalar  */
  YYSYMBOL_AssignStmt = 64,                /* AssignStmt  */
  YYSYMBOL_LeftVal = 65,                   /* LeftVal  */
  YYSYMBOL_RightVal = 66,                  /* RightVal  */
  YYSYMBOL_BoolUnit = 67,                  /* BoolUnit  */
  YYSYMBOL_ComExpr = 68,                   /* ComExpr  */
  YYSYMBOL_BoolExpr = 69,                  /* BoolExpr  */
  YYSYMBOL_BoolUOpExpr = 70,               /* BoolUOpExpr  */
  YYSYMBOL_BoolBiOpExpr = 71,              /* BoolBiOpExpr  */
  YYSYMBOL_ArithExpr = 72,                 /* ArithExpr  */
  YYSYMBOL_ArithUExpr = 73,                /* ArithUExpr  */
  YYSYMBOL_ArithBiOpExpr = 74,             /* ArithBiOpExpr  */
  YYSYMBOL_ExprUnit = 75,                  /* ExprUnit  */
  YYSYMBOL_MemberExpr = 76,                /* MemberExpr  */
  YYSYMBOL_ArrayExpr = 77,                 /* ArrayExpr  */
  YYSYMBOL_IndexExpr = 78,                 /* IndexExpr  */
  YYSYMBOL_FnCall = 79,                    /* FnCall  */
  YYSYMBOL_RightValList = 80,              /* RightValList  */
  YYSYMBOL_Type = 81                       /* Type  */
=======
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_NUMBER = 4,                     /* NUMBER  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_FN = 7,                         /* FN  */
  YYSYMBOL_STRUCT = 8,                     /* STRUCT  */
  YYSYMBOL_OPEN_BRACE = 9,                 /* OPEN_BRACE  */
  YYSYMBOL_CLOSE_BRACE = 10,               /* CLOSE_BRACE  */
  YYSYMBOL_OPEN_PAREN = 11,                /* OPEN_PAREN  */
  YYSYMBOL_CLOSE_PAREN = 12,               /* CLOSE_PAREN  */
  YYSYMBOL_COLON = 13,                     /* COLON  */
  YYSYMBOL_COMMA = 14,                     /* COMMA  */
  YYSYMBOL_ADD = 15,                       /* ADD  */
  YYSYMBOL_SUB = 16,                       /* SUB  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_DIV = 18,                       /* DIV  */
  YYSYMBOL_YYACCEPT = 19,                  /* $accept  */
  YYSYMBOL_Program = 20,                   /* Program  */
  YYSYMBOL_ProgramElement = 21,            /* ProgramElement  */
  YYSYMBOL_VarDeclStmt = 22,               /* VarDeclStmt  */
  YYSYMBOL_FnDeclStmt = 23,                /* FnDeclStmt  */
  YYSYMBOL_FnDef = 24,                     /* FnDef  */
  YYSYMBOL_VarDecl = 25,                   /* VarDecl  */
  YYSYMBOL_ExprUnitList = 26,              /* ExprUnitList  */
  YYSYMBOL_ParamDecl = 27,                 /* ParamDecl  */
  YYSYMBOL_CodeBlock = 28,                 /* CodeBlock  */
  YYSYMBOL_ExprUnit = 29,                  /* ExprUnit  */
  YYSYMBOL_StructDef = 30                  /* StructDef  */
>>>>>>> 57849de (新尝试，有bug)
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
<<<<<<< HEAD
typedef yytype_uint8 yy_state_t;
=======
typedef yytype_int8 yy_state_t;
>>>>>>> 57849de (新尝试，有bug)

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
<<<<<<< HEAD
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295
=======
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   50

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  19
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  24
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  46

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273
>>>>>>> 57849de (新尝试，有bug)


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
<<<<<<< HEAD
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
=======
      15,    16,    17,    18
>>>>>>> 57849de (新尝试，有bug)
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
<<<<<<< HEAD
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   157,   162,   167,   171,   175,   179,   183,
     189,   195,   199,   203,   207,   211,   215,   219,   223,   227,
     233,   239,   245,   251,   255,   261,   267,   271,   277,   283,
     287,   293,   299,   303,   308,   313,   317,   323,   327,   333,
     339,   345,   349,   355,   361,   367,   373,   377,   381,   387,
     391,   397,   401,   405,   411,   415,   419,   423,   427,   431,
     437,   441,   447,   453,   457,   463,   467,   473,   479,   483,
     487,   491,   497,   501,   505,   509,   513,   517,   521,   527,
     533,   539,   543,   549,   555,   559,   564,   569,   573
=======
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    67,    71,    75,    79,    83,    90,    96,
     102,   108,   113,   118,   125,   126,   131,   137,   144,   148,
     155,   160,   183,   188,   195
>>>>>>> 57849de (新尝试，有bug)
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
<<<<<<< HEAD
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "MUL",
  "DIV", "SEMICOLON", "LPAREN", "RPAREN", "AND", "OR", "NOT", "GREATER",
  "LESS", "GREATER_EQ", "LESS_EQ", "EQUAL", "NOT_EQUAL", "ASSIGN",
  "FN_CALL", "LET", "COLON", "COMMA", "LBRACKET", "RBRACKET", "LBRACE",
  "RBRACE", "STRUCT", "FN", "ARROW", "RET", "DOT", "CONTINUE", "BREAK",
  "IF", "ELSE", "WHILE", "INT", "ID", "NUM", "$accept", "Program",
  "ProgramElementList", "ProgramElement", "FnDeclStmt", "CodeBlockStmt",
  "ReturnStmt", "CallStmt", "WhileStmt", "IfStmt", "FnDef",
  "CodeBlockStmtList", "ParamDecl", "FnDecl", "StructDef", "VarDeclList",
  "VarDeclStmt", "VarDef", "VarDefArray", "VarDefScalar", "VarDecl",
  "VarDeclArray", "VarDeclScalar", "AssignStmt", "LeftVal", "RightVal",
  "BoolUnit", "ComExpr", "BoolExpr", "BoolUOpExpr", "BoolBiOpExpr",
  "ArithExpr", "ArithUExpr", "ArithBiOpExpr", "ExprUnit", "MemberExpr",
  "ArrayExpr", "IndexExpr", "FnCall", "RightValList", "Type", YY_NULLPTR
=======
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "NUMBER",
  "SEMICOLON", "LET", "FN", "STRUCT", "OPEN_BRACE", "CLOSE_BRACE",
  "OPEN_PAREN", "CLOSE_PAREN", "COLON", "COMMA", "ADD", "SUB", "MUL",
  "DIV", "$accept", "Program", "ProgramElement", "VarDeclStmt",
  "FnDeclStmt", "FnDef", "VarDecl", "ExprUnitList", "ParamDecl",
  "CodeBlock", "ExprUnit", "StructDef", YY_NULLPTR
>>>>>>> 57849de (新尝试，有bug)
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

<<<<<<< HEAD
#define YYPACT_NINF (-137)
=======
#define YYPACT_NINF (-20)
>>>>>>> 57849de (新尝试，有bug)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
<<<<<<< HEAD
static const yytype_int16 yypact[] =
{
       1,  -137,   -29,   -12,     9,    64,  -137,     1,  -137,  -137,
       8,  -137,  -137,    -3,    83,  -137,  -137,    85,  -137,  -137,
      70,    78,  -137,  -137,  -137,    60,    -6,    58,  -137,  -137,
      80,    80,  -137,     5,   111,   113,   115,   116,    33,    60,
    -137,  -137,  -137,  -137,    98,  -137,  -137,   107,  -137,  -137,
     120,  -137,  -137,   109,   112,    65,   114,   117,   127,  -137,
      16,     5,     5,    33,  -137,   131,  -137,  -137,    26,  -137,
    -137,   103,  -137,  -137,    87,  -137,  -137,  -137,  -137,  -137,
       5,     5,     5,    77,   100,  -137,  -137,     5,  -137,     5,
     122,    -6,   102,  -137,    80,   118,    16,  -137,    49,    79,
    -137,    87,  -137,     5,     5,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    16,   101,   104,   123,   140,  -137,
    -137,   125,  -137,   144,  -137,    -6,  -137,   128,  -137,    -6,
    -137,  -137,  -137,  -137,  -137,   103,   103,   103,   103,  -137,
    -137,  -137,  -137,  -137,  -137,   126,   129,     5,  -137,  -137,
    -137,   135,   134,  -137,    60,    60,  -137,   132,    -6,   130,
     133,     5,  -137,   136,  -137,   137,   139,  -137,    60,   141,
    -137
=======
static const yytype_int8 yypact[] =
{
      10,   -20,     2,    17,    21,    13,   -20,   -20,   -20,   -20,
     -20,    -2,    20,    15,    18,   -20,    24,    26,   -20,     2,
      25,    22,   -20,   -20,     7,    23,    27,     3,     2,    29,
      19,   -20,    -4,   -20,   -20,   -20,   -20,   -20,     0,   -20,
     -20,    28,   -20,    19,   -20,   -20
>>>>>>> 57849de (新尝试，有bug)
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
<<<<<<< HEAD
       4,     9,     0,     0,     0,     0,     2,     4,     7,     8,
       0,     6,     5,     0,     0,    38,    37,     0,    42,    41,
       0,     0,     1,     3,    10,     0,     0,     0,    36,    35,
      34,    34,    19,     0,     0,     0,     0,     0,    46,    27,
      16,    13,    15,    14,     0,    11,    12,     0,    48,    47,
       0,    87,    88,    44,     0,     0,     0,    33,     0,    28,
       0,     0,     0,    73,    72,     0,    61,    51,    50,    53,
      60,    49,    78,    65,    66,    77,    76,    75,    17,    18,
       0,     0,    86,     0,     0,    26,    25,     0,    21,     0,
       0,     0,     0,    31,    34,    29,     0,    67,     0,     0,
      62,     0,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,    82,
      81,     0,    79,     0,    40,     0,    44,     0,    32,     0,
      66,    52,    74,    64,    63,    68,    69,    70,    71,    54,
      56,    55,    57,    59,    58,     0,     0,    86,    83,    80,
      45,    43,     0,    30,     0,     0,    84,     0,     0,     0,
       0,    86,    43,    23,    22,     0,     0,    39,     0,     0,
      24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -137,  -137,   152,  -137,  -137,  -137,  -137,  -137,  -137,  -137,
    -137,   -33,  -137,  -137,  -137,   -28,    31,  -137,  -137,  -137,
     159,  -137,  -137,  -137,  -137,   -26,   -50,  -137,   -38,  -137,
    -137,   -56,  -137,  -137,   -34,   -25,   -23,  -137,   -21,  -136,
     -90
=======
       0,     7,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     0,     0,     0,     0,     1,     0,     0,     8,     0,
       0,     0,    11,    18,     0,     0,    12,     0,     0,     0,
      14,     9,     0,    10,    19,    24,    22,    23,     0,    15,
      20,     0,    13,     0,    21,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,     5,    30,   -20,   -20,   -19,   -20,   -20,   -20,
     -13,   -20
>>>>>>> 57849de (新尝试，有bug)
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
<<<<<<< HEAD
       0,     5,     6,     7,     8,    39,    40,    41,    42,    43,
       9,    44,    58,    10,    11,    56,    45,    14,    15,    16,
      57,    18,    19,    46,    47,   117,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,   121,    77,   118,
      53
=======
       0,     5,     6,     7,     8,     9,    12,    38,    24,    33,
      39,    10
>>>>>>> 57849de (新尝试，有bug)
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
<<<<<<< HEAD
static const yytype_uint8 yytable[] =
{
      48,   126,    49,    59,    50,    99,    85,    65,     1,    60,
      13,   156,   100,    61,    48,    24,    49,    62,    50,    26,
      60,    27,     2,    98,    96,   165,    97,    20,   101,     3,
       4,    12,    51,    52,    25,   151,   103,   104,    12,   153,
      99,    82,   115,   116,    63,    64,   101,   101,    21,   135,
     136,   137,   138,   133,   134,    63,    64,    83,   131,   103,
     104,   123,   130,   124,    22,    84,   128,    32,   162,   101,
     101,   130,   130,   130,   130,   139,   140,   141,   142,   143,
     144,     2,   105,   106,   107,   108,    31,    91,   132,    92,
      28,    33,    29,    34,    35,    36,    30,    37,    54,    38,
     109,   110,   111,   112,   113,   114,   105,   106,   107,   108,
     145,   103,   104,   146,   103,   104,   119,   120,    78,    55,
      79,   159,   160,    80,    81,    86,    87,    88,    89,    48,
      48,    49,    49,    50,    50,   169,    95,    90,   102,   122,
      94,    93,   127,    48,   125,    49,   147,    50,   129,   148,
     149,   150,   154,   152,   157,   155,   158,   163,   161,    23,
     164,    17,     0,     0,   167,   168,     0,     0,   170,     0,
       0,     0,   166
};

static const yytype_int16 yycheck[] =
{
      25,    91,    25,    31,    25,    61,    39,    33,     7,     4,
      39,   147,    62,     8,    39,     7,    39,    12,    39,    22,
       4,    24,    21,    61,     8,   161,    60,    39,    62,    28,
      29,     0,    38,    39,    26,   125,    10,    11,     7,   129,
      96,     8,    80,    81,    39,    40,    80,    81,    39,   105,
     106,   107,   108,   103,   104,    39,    40,    24,     9,    10,
      11,    87,    96,    89,     0,    32,    94,     7,   158,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    21,     3,     4,     5,     6,     8,    22,     9,    24,
       7,    31,     7,    33,    34,    35,    26,    37,    40,    39,
      13,    14,    15,    16,    17,    18,     3,     4,     5,     6,
       9,    10,    11,     9,    10,    11,    39,    40,     7,    39,
       7,   154,   155,     8,     8,    27,    19,     7,    19,   154,
     155,   154,   155,   154,   155,   168,     9,    25,     7,    39,
      23,    27,    40,   168,    22,   168,    23,   168,    30,     9,
      25,     7,    26,    25,    19,    26,    22,    27,    26,     7,
      27,     2,    -1,    -1,    27,    26,    -1,    -1,    27,    -1,
      -1,    -1,    36
=======
static const yytype_int8 yytable[] =
{
      23,     1,     2,     3,     4,    11,    40,    16,    31,    34,
      42,    17,    32,    15,    43,     1,     2,     3,     4,    27,
      13,    28,    36,    37,    14,    18,    19,    20,    21,    22,
      45,     2,    26,    29,    35,     0,    30,    41,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25
};

static const yytype_int8 yycheck[] =
{
      19,     5,     6,     7,     8,     3,    10,     9,     5,    28,
      10,    13,     9,     0,    14,     5,     6,     7,     8,    12,
       3,    14,     3,     4,     3,     5,    11,     9,     4,     3,
      43,     6,    10,    10,     5,    -1,     9,    32,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20
>>>>>>> 57849de (新尝试，有bug)
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
<<<<<<< HEAD
       0,     7,    21,    28,    29,    42,    43,    44,    45,    51,
      54,    55,    57,    39,    58,    59,    60,    61,    62,    63,
      39,    39,     0,    43,     7,    26,    22,    24,     7,     7,
      26,     8,     7,    31,    33,    34,    35,    37,    39,    46,
      47,    48,    49,    50,    52,    57,    64,    65,    76,    77,
      79,    38,    39,    81,    40,    39,    56,    61,    53,    56,
       4,     8,    12,    39,    40,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    79,     7,     7,
       8,     8,     8,    24,    32,    52,    27,    19,     7,    19,
      25,    22,    24,    27,    23,     9,     8,    75,    69,    72,
      67,    75,     7,    10,    11,     3,     4,     5,     6,    13,
      14,    15,    16,    17,    18,    69,    69,    66,    80,    39,
      40,    78,    39,    66,    66,    22,    81,    40,    56,    30,
      75,     9,     9,    67,    67,    72,    72,    72,    72,    75,
      75,    75,    75,    75,    75,     9,     9,    23,     9,    25,
       7,    81,    25,    81,    26,    26,    80,    19,    22,    52,
      52,    26,    81,    27,    27,    80,    36,    27,    26,    52,
      27
=======
       0,     5,     6,     7,     8,    20,    21,    22,    23,    24,
      30,     3,    25,     3,     3,     0,     9,    13,     5,    11,
       9,     4,     3,    25,    27,    22,    10,    12,    14,    10,
       9,     5,     9,    28,    25,     5,     3,     4,    26,    29,
      10,    21,    10,    14,    10,    29
>>>>>>> 57849de (新尝试，有bug)
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
<<<<<<< HEAD
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    48,    49,    50,    50,    51,    52,    52,    53,    54,
      54,    55,    56,    56,    56,    57,    57,    58,    58,    59,
      60,    61,    61,    62,    63,    64,    65,    65,    65,    66,
      66,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    73,    74,    74,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    76,
      77,    78,    78,    79,    80,    80,    80,    81,    81
=======
       0,    19,    20,    21,    21,    21,    21,    21,    22,    23,
      24,    25,    25,    25,    26,    26,    26,    26,    27,    27,
      28,    28,    29,    29,    30
>>>>>>> 57849de (新尝试，有bug)
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
<<<<<<< HEAD
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       3,     2,     7,     7,    11,     4,     2,     1,     1,     5,
       7,     5,     3,     1,     0,     3,     3,     1,     1,    10,
       5,     1,     1,     6,     3,     4,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     3,     3,     1,     1,     2,     3,     3,
       3,     3,     1,     1,     3,     1,     1,     1,     1,     3,
       4,     1,     1,     4,     3,     1,     0,     1,     1
=======
       0,     2,     1,     1,     1,     1,     1,     1,     3,     6,
       6,     3,     4,     7,     0,     1,     3,     0,     1,     3,
       2,     3,     1,     1,     6
>>>>>>> 57849de (新尝试，有bug)
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
<<<<<<< HEAD
  case 2: /* Program: ProgramElementList  */
#line 151 "parser.yacc"
{  
  root = A_Program((yyvsp[0].programElementList));
  (yyval.program) = A_Program((yyvsp[0].programElementList));
=======
  case 2: /* Program: ProgramElement  */
#line 61 "parser.yacc"
{
  root = A_Program((yyvsp[0].programElement)->pos, (yyvsp[0].programElement));
  (yyval.program) = root;
}
#line 1123 "y.tab.cpp"
    break;

  case 3: /* ProgramElement: VarDeclStmt  */
#line 68 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1131 "y.tab.cpp"
    break;

  case 4: /* ProgramElement: FnDeclStmt  */
#line 72 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1139 "y.tab.cpp"
    break;

  case 5: /* ProgramElement: FnDef  */
#line 76 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1147 "y.tab.cpp"
    break;

  case 6: /* ProgramElement: StructDef  */
#line 80 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1155 "y.tab.cpp"
    break;

  case 7: /* ProgramElement: SEMICOLON  */
#line 84 "parser.yacc"
{
  // Handle empty statement
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos)->pos);
}
#line 1164 "y.tab.cpp"
    break;

  case 8: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 91 "parser.yacc"
{
  (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-1].varDecl)->pos, (yyvsp[-1].varDecl));
}
#line 1172 "y.tab.cpp"
    break;

  case 9: /* FnDeclStmt: FN IDENTIFIER OPEN_PAREN ParamDecl CLOSE_PAREN SEMICOLON  */
#line 97 "parser.yacc"
{
  (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-4].pos)->pos, (yyvsp[-4].pos), (yyvsp[-2].paramDecl));
}
#line 1180 "y.tab.cpp"
    break;

  case 10: /* FnDef: FN IDENTIFIER OPEN_PAREN ParamDecl CLOSE_PAREN CodeBlock  */
#line 103 "parser.yacc"
{
  (yyval.fnDef) = A_FnDef((yyvsp[-4].pos)->pos, (yyvsp[-4].pos), (yyvsp[-2].paramDecl), (yyvsp[0].codeBlock));
}
#line 1188 "y.tab.cpp"
    break;

  case 11: /* VarDecl: IDENTIFIER COLON IDENTIFIER  */
#line 109 "parser.yacc"
{
  // 处理 VarDecl 产生式的操作
  (yyval.varDecl) = A_VarDecl((yyvsp[-2].pos)->pos, (yyvsp[-2].pos)->name, (yyvsp[0].pos)); // 修改以适应您的数据结构
}
#line 1197 "y.tab.cpp"
    break;

  case 12: /* VarDecl: IDENTIFIER OPEN_BRACE NUMBER CLOSE_BRACE  */
#line 114 "parser.yacc"
{
  // 处理带有数组长度的 VarDecl 产生式的操作
  (yyval.varDecl) = A_VarDecl((yyvsp[-3].pos)->pos, (yyvsp[-3].pos)->name, (yyvsp[-1].pos), NULL); // 修改以适应您的数据结构
}
#line 1206 "y.tab.cpp"
    break;

  case 13: /* VarDecl: IDENTIFIER OPEN_BRACE NUMBER CLOSE_BRACE OPEN_BRACE ExprUnitList CLOSE_BRACE  */
#line 119 "parser.yacc"
{
  // 处理带有数组长度和初始值的 VarDecl 产生式的操作
  (yyval.varDecl) = A_VarDecl((yyvsp[-6].pos)->pos, (yyvsp[-6].pos)->name, (yyvsp[-4].pos), (yyvsp[0].pos)); // 修改以适应您的数据结构
}
#line 1215 "y.tab.cpp"
    break;

  case 15: /* ExprUnitList: ExprUnit  */
#line 127 "parser.yacc"
  {
    A_exprUnitList list = A_ExprUnitList((yyvsp[0].exprUnit));
    (yyval.exprUnitList) = list;
  }
#line 1224 "y.tab.cpp"
    break;

  case 16: /* ExprUnitList: ExprUnitList COMMA ExprUnit  */
#line 132 "parser.yacc"
  {
    A_exprUnitList list = A_ExprUnitListAppend((yyvsp[-2].exprUnitList), (yyvsp[0].exprUnit));
    (yyval.exprUnitList) = list;
  }
#line 1233 "y.tab.cpp"
    break;

  case 17: /* ExprUnitList: %empty  */
#line 137 "parser.yacc"
  {
    A_exprUnitList list = NULL; // 或者使用您的数据结构中的空列表
    (yyval.exprUnitList) = list;
  }
#line 1242 "y.tab.cpp"
    break;

  case 18: /* ParamDecl: VarDecl  */
#line 145 "parser.yacc"
{
  (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDecl)->pos, A_VarDeclScalar((yyvsp[0].varDecl)->pos, (yyvsp[0].varDecl)->name, (yyvsp[0].varDecl)->u.structType));
}
#line 1250 "y.tab.cpp"
    break;

  case 19: /* ParamDecl: ParamDecl COMMA VarDecl  */
#line 149 "parser.yacc"
{
  // Handle multiple parameters separated by COMMA here
  (yyval.paramDecl) = A_ParamDeclList((yyvsp[-2].paramDecl)->pos, (yyvsp[-2].paramDecl), (yyvsp[0].varDecl));
}
#line 1259 "y.tab.cpp"
    break;

  case 20: /* CodeBlock: OPEN_BRACE CLOSE_BRACE  */
#line 156 "parser.yacc"
{
  // Handle empty code block
  (yyval.codeBlock) = A_CodeBlock((yyvsp[-1].pos)->pos, NULL);
}
#line 1268 "y.tab.cpp"
    break;

  case 21: /* CodeBlock: OPEN_BRACE ProgramElement CLOSE_BRACE  */
#line 161 "parser.yacc"
{
  (yyval.codeBlock) = A_CodeBlock((yyvsp[-2].pos)->pos, (yyvsp[-1].programElement));
>>>>>>> 57849de (新尝试，有bug)
}
#line 1276 "y.tab.cpp"
    break;

<<<<<<< HEAD
  case 3: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 158 "parser.yacc"
{
  (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
}
#line 1284 "y.tab.cpp"
    break;

  case 4: /* ProgramElementList: %empty  */
#line 162 "parser.yacc"
{
  (yyval.programElementList) = NULL;
}
#line 1292 "y.tab.cpp"
    break;

  case 5: /* ProgramElement: VarDeclStmt  */
#line 168 "parser.yacc"
{
  (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1300 "y.tab.cpp"
    break;

  case 6: /* ProgramElement: StructDef  */
#line 172 "parser.yacc"
{
  (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
}
#line 1308 "y.tab.cpp"
    break;

  case 7: /* ProgramElement: FnDeclStmt  */
#line 176 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
}
#line 1316 "y.tab.cpp"
    break;

  case 8: /* ProgramElement: FnDef  */
#line 180 "parser.yacc"
{
  (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
}
#line 1324 "y.tab.cpp"
    break;

  case 9: /* ProgramElement: SEMICOLON  */
#line 184 "parser.yacc"
{
  (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
}
#line 1332 "y.tab.cpp"
    break;

  case 10: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 190 "parser.yacc"
{
    (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
}
#line 1340 "y.tab.cpp"
    break;

  case 11: /* CodeBlockStmt: VarDeclStmt  */
#line 196 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
}
#line 1348 "y.tab.cpp"
    break;

  case 12: /* CodeBlockStmt: AssignStmt  */
#line 200 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
}
#line 1356 "y.tab.cpp"
    break;

  case 13: /* CodeBlockStmt: CallStmt  */
#line 204 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
}
#line 1364 "y.tab.cpp"
    break;

  case 14: /* CodeBlockStmt: IfStmt  */
#line 208 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
}
#line 1372 "y.tab.cpp"
    break;

  case 15: /* CodeBlockStmt: WhileStmt  */
#line 212 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
}
#line 1380 "y.tab.cpp"
    break;

  case 16: /* CodeBlockStmt: ReturnStmt  */
#line 216 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
}
#line 1388 "y.tab.cpp"
    break;

  case 17: /* CodeBlockStmt: CONTINUE SEMICOLON  */
#line 220 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[-1].pos));
}
#line 1396 "y.tab.cpp"
    break;

  case 18: /* CodeBlockStmt: BREAK SEMICOLON  */
#line 224 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[-1].pos));
}
#line 1404 "y.tab.cpp"
    break;

  case 19: /* CodeBlockStmt: SEMICOLON  */
#line 228 "parser.yacc"
{
  (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
}
#line 1412 "y.tab.cpp"
    break;

  case 20: /* ReturnStmt: RET RightVal SEMICOLON  */
#line 234 "parser.yacc"
{
  (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
}
#line 1420 "y.tab.cpp"
    break;

  case 21: /* CallStmt: FnCall SEMICOLON  */
#line 240 "parser.yacc"
{
  (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
}
#line 1428 "y.tab.cpp"
    break;

  case 22: /* WhileStmt: WHILE LPAREN BoolExpr RPAREN LBRACE CodeBlockStmtList RBRACE  */
#line 246 "parser.yacc"
{
  (yyval.whileStmt) = A_WhileStmt((yyvsp[-6].pos), (yyvsp[-4].boolExpr), (yyvsp[-1].codeBlockStmtList));
}
#line 1436 "y.tab.cpp"
    break;

  case 23: /* IfStmt: IF LPAREN BoolExpr RPAREN LBRACE CodeBlockStmtList RBRACE  */
#line 252 "parser.yacc"
{
  (yyval.ifStmt) = A_IfStmt((yyvsp[-6].pos), (yyvsp[-4].boolExpr), (yyvsp[-1].codeBlockStmtList), NULL);
}
#line 1444 "y.tab.cpp"
    break;

  case 24: /* IfStmt: IF LPAREN BoolExpr RPAREN LBRACE CodeBlockStmtList RBRACE ELSE LBRACE CodeBlockStmtList RBRACE  */
#line 256 "parser.yacc"
{
  (yyval.ifStmt) = A_IfStmt((yyvsp[-10].pos), (yyvsp[-8].boolExpr), (yyvsp[-5].codeBlockStmtList), (yyvsp[-1].codeBlockStmtList));
}
#line 1452 "y.tab.cpp"
    break;

  case 25: /* FnDef: FnDecl LBRACE CodeBlockStmtList RBRACE  */
#line 262 "parser.yacc"
{
    (yyval.fnDef) = A_FnDef((yyvsp[-3].fnDecl)->pos, (yyvsp[-3].fnDecl), (yyvsp[-1].codeBlockStmtList));
}
#line 1460 "y.tab.cpp"
    break;

  case 26: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 268 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
}
#line 1468 "y.tab.cpp"
    break;

  case 27: /* CodeBlockStmtList: CodeBlockStmt  */
#line 272 "parser.yacc"
{
  (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), NULL);
}
#line 1476 "y.tab.cpp"
    break;

  case 28: /* ParamDecl: VarDeclList  */
#line 278 "parser.yacc"
{
  (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
}
#line 1484 "y.tab.cpp"
    break;

  case 29: /* FnDecl: FN ID LPAREN ParamDecl RPAREN  */
#line 284 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), NULL);
}
#line 1492 "y.tab.cpp"
    break;

  case 30: /* FnDecl: FN ID LPAREN ParamDecl RPAREN ARROW Type  */
#line 288 "parser.yacc"
{
  (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
}
#line 1500 "y.tab.cpp"
    break;

  case 31: /* StructDef: STRUCT ID LBRACE VarDeclList RBRACE  */
#line 294 "parser.yacc"
{
    (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
}
#line 1508 "y.tab.cpp"
    break;

  case 32: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 300 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
}
#line 1516 "y.tab.cpp"
    break;

  case 33: /* VarDeclList: VarDecl  */
#line 304 "parser.yacc"
{
    (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), NULL);
}
#line 1524 "y.tab.cpp"
    break;

  case 34: /* VarDeclList: %empty  */
#line 308 "parser.yacc"
{
    (yyval.varDeclList) = NULL;
}
#line 1532 "y.tab.cpp"
    break;

  case 35: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 314 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-2].pos), (yyvsp[-1].varDecl));
}
#line 1540 "y.tab.cpp"
    break;

  case 36: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 318 "parser.yacc"
{
    (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-2].pos), (yyvsp[-1].varDef));
}
#line 1548 "y.tab.cpp"
    break;

  case 37: /* VarDef: VarDefScalar  */
#line 324 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[0].varDefScalar)->pos, (yyvsp[0].varDefScalar));
}
#line 1556 "y.tab.cpp"
    break;

  case 38: /* VarDef: VarDefArray  */
#line 328 "parser.yacc"
{
    (yyval.varDef) = A_VarDef_Array((yyvsp[0].varDefArray)->pos, (yyvsp[0].varDefArray));
}
#line 1564 "y.tab.cpp"
    break;

  case 39: /* VarDefArray: ID LBRACKET NUM RBRACKET COLON Type ASSIGN LBRACE RightValList RBRACE  */
#line 334 "parser.yacc"
{
    (yyval.varDefArray) = A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList));
}
#line 1572 "y.tab.cpp"
    break;

  case 40: /* VarDefScalar: ID COLON Type ASSIGN RightVal  */
#line 340 "parser.yacc"
{
    (yyval.varDefScalar) = A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal));
}
#line 1580 "y.tab.cpp"
    break;

  case 41: /* VarDecl: VarDeclScalar  */
#line 346 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].varDeclScalar)->pos, (yyvsp[0].varDeclScalar));
}
#line 1588 "y.tab.cpp"
    break;

  case 42: /* VarDecl: VarDeclArray  */
#line 350 "parser.yacc"
{
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].varDeclArray)->pos, (yyvsp[0].varDeclArray));
}
#line 1596 "y.tab.cpp"
    break;

  case 43: /* VarDeclArray: ID LBRACKET NUM RBRACKET COLON Type  */
#line 356 "parser.yacc"
{
    (yyval.varDeclArray) = A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type));
}
#line 1604 "y.tab.cpp"
    break;

  case 44: /* VarDeclScalar: ID COLON Type  */
#line 362 "parser.yacc"
{
    (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type));
}
#line 1612 "y.tab.cpp"
    break;

  case 45: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 368 "parser.yacc"
{
    (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
}
#line 1620 "y.tab.cpp"
    break;

  case 46: /* LeftVal: ID  */
#line 374 "parser.yacc"
{
    (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1628 "y.tab.cpp"
    break;

  case 47: /* LeftVal: ArrayExpr  */
#line 378 "parser.yacc"
{
    (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1636 "y.tab.cpp"
    break;

  case 48: /* LeftVal: MemberExpr  */
#line 382 "parser.yacc"
{
    (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1644 "y.tab.cpp"
    break;

  case 49: /* RightVal: ArithExpr  */
#line 388 "parser.yacc"
{
    (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
}
#line 1652 "y.tab.cpp"
    break;

  case 50: /* RightVal: BoolExpr  */
#line 392 "parser.yacc"
{
    (yyval.rightVal) = A_BoolExprRVal((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
}
#line 1660 "y.tab.cpp"
    break;

  case 51: /* BoolUnit: ComExpr  */
#line 398 "parser.yacc"
{
    (yyval.boolUnit) = A_ComExprUnit((yyvsp[0].comExpr)->pos, (yyvsp[0].comExpr));
}
#line 1668 "y.tab.cpp"
    break;

  case 52: /* BoolUnit: LPAREN BoolExpr RPAREN  */
#line 402 "parser.yacc"
{
    (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
}
#line 1676 "y.tab.cpp"
    break;

  case 53: /* BoolUnit: BoolUOpExpr  */
#line 406 "parser.yacc"
{
    (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
}
#line 1684 "y.tab.cpp"
    break;

  case 54: /* ComExpr: ExprUnit GREATER ExprUnit  */
#line 412 "parser.yacc"
{
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1692 "y.tab.cpp"
    break;

  case 55: /* ComExpr: ExprUnit GREATER_EQ ExprUnit  */
#line 416 "parser.yacc"
{
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1700 "y.tab.cpp"
    break;

  case 56: /* ComExpr: ExprUnit LESS ExprUnit  */
#line 420 "parser.yacc"
{
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1708 "y.tab.cpp"
    break;

  case 57: /* ComExpr: ExprUnit LESS_EQ ExprUnit  */
#line 424 "parser.yacc"
{
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1716 "y.tab.cpp"
    break;

  case 58: /* ComExpr: ExprUnit NOT_EQUAL ExprUnit  */
#line 428 "parser.yacc"
{
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1724 "y.tab.cpp"
    break;

  case 59: /* ComExpr: ExprUnit EQUAL ExprUnit  */
#line 432 "parser.yacc"
{
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
}
#line 1732 "y.tab.cpp"
    break;

  case 60: /* BoolExpr: BoolBiOpExpr  */
#line 438 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
}
#line 1740 "y.tab.cpp"
    break;

  case 61: /* BoolExpr: BoolUnit  */
#line 442 "parser.yacc"
{
    (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
}
#line 1748 "y.tab.cpp"
    break;

  case 62: /* BoolUOpExpr: NOT BoolUnit  */
#line 448 "parser.yacc"
{
    (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit));
}
#line 1756 "y.tab.cpp"
    break;

  case 63: /* BoolBiOpExpr: BoolExpr OR BoolUnit  */
#line 454 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolUnit));
}
#line 1764 "y.tab.cpp"
    break;

  case 64: /* BoolBiOpExpr: BoolExpr AND BoolUnit  */
#line 458 "parser.yacc"
{
    (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolUnit));
}
#line 1772 "y.tab.cpp"
    break;

  case 65: /* ArithExpr: ArithBiOpExpr  */
#line 464 "parser.yacc"
{
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[0].arithBiOpExpr)->pos, (yyvsp[0].arithBiOpExpr));
}
#line 1780 "y.tab.cpp"
    break;

  case 66: /* ArithExpr: ExprUnit  */
#line 468 "parser.yacc"
{
  (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
}
#line 1788 "y.tab.cpp"
    break;

  case 67: /* ArithUExpr: SUB ExprUnit  */
#line 474 "parser.yacc"
{
    (yyval.arithUExpr) = A_ArithUExpr((yyvsp[-1].pos), A_neg, (yyvsp[0].exprUnit));
}
#line 1796 "y.tab.cpp"
    break;

  case 68: /* ArithBiOpExpr: ArithExpr ADD ArithExpr  */
#line 480 "parser.yacc"
{
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
}
#line 1804 "y.tab.cpp"
    break;

  case 69: /* ArithBiOpExpr: ArithExpr SUB ArithExpr  */
#line 484 "parser.yacc"
{
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
}
#line 1812 "y.tab.cpp"
    break;

  case 70: /* ArithBiOpExpr: ArithExpr MUL ArithExpr  */
#line 488 "parser.yacc"
{
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
}
#line 1820 "y.tab.cpp"
    break;

  case 71: /* ArithBiOpExpr: ArithExpr DIV ArithExpr  */
#line 492 "parser.yacc"
{
  (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
}
#line 1828 "y.tab.cpp"
    break;

  case 72: /* ExprUnit: NUM  */
#line 498 "parser.yacc"
{
    (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1836 "y.tab.cpp"
    break;

  case 73: /* ExprUnit: ID  */
#line 502 "parser.yacc"
{
    (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1844 "y.tab.cpp"
    break;

  case 74: /* ExprUnit: LPAREN ArithExpr RPAREN  */
#line 506 "parser.yacc"
{
    (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos), (yyvsp[-1].arithExpr));
}
#line 1852 "y.tab.cpp"
    break;

  case 75: /* ExprUnit: FnCall  */
#line 510 "parser.yacc"
{
    (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
}
#line 1860 "y.tab.cpp"
    break;

  case 76: /* ExprUnit: ArrayExpr  */
#line 514 "parser.yacc"
{
    (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
}
#line 1868 "y.tab.cpp"
    break;

  case 77: /* ExprUnit: MemberExpr  */
#line 518 "parser.yacc"
{
    (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
}
#line 1876 "y.tab.cpp"
    break;

  case 78: /* ExprUnit: ArithUExpr  */
#line 522 "parser.yacc"
{
    (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[0].arithUExpr)->pos, (yyvsp[0].arithUExpr));
}
#line 1884 "y.tab.cpp"
    break;

  case 79: /* MemberExpr: ID DOT ID  */
#line 528 "parser.yacc"
{
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].tokenId)->id);
}
#line 1892 "y.tab.cpp"
    break;

  case 80: /* ArrayExpr: ID LBRACKET IndexExpr RBRACKET  */
#line 534 "parser.yacc"
{
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].indexExpr));
}
#line 1900 "y.tab.cpp"
    break;

  case 81: /* IndexExpr: NUM  */
#line 540 "parser.yacc"
{
    (yyval.indexExpr) = A_NumIndexExpr((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
}
#line 1908 "y.tab.cpp"
    break;

  case 82: /* IndexExpr: ID  */
#line 544 "parser.yacc"
{
    (yyval.indexExpr) = A_IdIndexExpr((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1916 "y.tab.cpp"
    break;

  case 83: /* FnCall: ID LPAREN RightValList RPAREN  */
#line 550 "parser.yacc"
{
    (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
}
#line 1924 "y.tab.cpp"
    break;

  case 84: /* RightValList: RightVal COMMA RightValList  */
#line 556 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
}
#line 1932 "y.tab.cpp"
    break;

  case 85: /* RightValList: RightVal  */
#line 560 "parser.yacc"
{
    (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), NULL);
}
#line 1940 "y.tab.cpp"
    break;

  case 86: /* RightValList: %empty  */
#line 564 "parser.yacc"
{
    (yyval.rightValList) = NULL;
}
#line 1948 "y.tab.cpp"
    break;

  case 87: /* Type: INT  */
#line 570 "parser.yacc"
{
    (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
}
#line 1956 "y.tab.cpp"
    break;

  case 88: /* Type: ID  */
#line 574 "parser.yacc"
{
    (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
}
#line 1964 "y.tab.cpp"
    break;


#line 1968 "y.tab.cpp"
=======
  case 22: /* ExprUnit: IDENTIFIER  */
#line 184 "parser.yacc"
{
  // Handle identifier expression unit
  (yyval.exprUnit) = A_IdentExpr((yyvsp[0].pos)->pos, (yyvsp[0].pos)->name);
}
#line 1285 "y.tab.cpp"
    break;

  case 23: /* ExprUnit: NUMBER  */
#line 189 "parser.yacc"
{
  // Handle numeric expression unit
  (yyval.exprUnit) = A_ArithNumExpr((yyvsp[0].pos)->pos, (yyvsp[0].pos)->val);
}
#line 1294 "y.tab.cpp"
    break;

  case 24: /* StructDef: STRUCT IDENTIFIER OPEN_BRACE VarDeclStmt CLOSE_BRACE SEMICOLON  */
#line 196 "parser.yacc"
{
  // Handle struct definition
  (yyval.structDef) = A_StructDef((yyvsp[-4].pos)->pos, (yyvsp[-4].pos), (yyvsp[-2].varDeclStmt));
}
#line 1303 "y.tab.cpp"
    break;


#line 1307 "y.tab.cpp"
>>>>>>> 57849de (新尝试，有bug)

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

<<<<<<< HEAD
#line 581 "parser.yacc"


extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
=======
#line 202 "parser.yacc"


void yyerror(const char *s)
{
  fprintf(stderr, "Syntax error: %s\n", s);
}

int main()
{
  yyparse();
  // Now you can use the 'root' variable to access the generated AST.
  return 0;
>>>>>>> 57849de (新尝试，有bug)
}

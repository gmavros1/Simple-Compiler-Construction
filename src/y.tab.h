/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 22 "parser.y"
 double dval; struct symtab *symp; 

#line 109 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

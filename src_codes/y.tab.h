/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 186 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

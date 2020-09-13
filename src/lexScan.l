/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


extern struct symtab *returnStrucktPointer(char *n);
extern char ids[25];
void printTable();
void scopeHandle(char *c);

int typeBool;
int yylex();
void yyerror(const char *s);

#include "y.tab.h"
#define T_eof	0
%}


%option noyywrap

letter 	[[:alpha:]]
digit	[[:digit:]]
id	[A-Za-z][A-Za-z0-9_]*
num	[0-9]+"."[0-9]+|[0-9]+
Empty 	[[:space:]]
punct	[[:punct:]]

%%

{Empty}+	{  /* nothing */ }

{punct}  		{	scopeHandle(yytext);
							return yytext[0] ; }

"mainclass"	{ return  T_MAINCLASS ; }

"public"		{ return T_PUBLIC; }

"static"		{ return T_STATIC ; }

"void"			{ return T_VOID ; }

"main"			{ return T_MAIN ; }

"println"		{ return T_PRINTLN ; }

"int"				{ typeBool = 1; return T_INT ; }

"float"			{ typeBool = 0; return T_FLOAT ; }

"for"				{ return T_FOR ; }

"while"			{ return T_WHILE ; }

"if"				{ return T_IF ; }

"else"			{ return T_ELSE ; }

"=="				{ return T_EQUAL ; }

"<="				{ return T_SMALLER ; }

">="				{ return T_BIGGER ; }

"!="				{ return T_NOTEQUAL ; }

{num}				{  yylval.dval = atof(yytext);
		  				return T_NUM ; } /* return number in float */

							/* return symbol struct pointer */
{id}				{ strcpy(ids, yytext);
							yylval.symp = returnStrucktPointer(yytext);
		  				return T_ID ; }

. 					{ yyerror("lexical error"); exit(1); }

<<EOF>>			{ printf("\nEOF\n") ; printTable(); return T_eof;; }

%%

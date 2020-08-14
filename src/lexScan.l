/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>

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
string 	'(digit|letter)*'
Empty 	[[:space:]]
punct	[[:punct:]]

%%

{Empty}+	{  /* nothing */ }

{punct}  	{ printf("\n %s \n", yytext) ; return yytext[0] ; }

"mainclass"	{ return  T_MAINCLASS ; }

"public"	{ return T_PUBLIC; }
	
"static"	{ return T_STATIC ; }

"void"		{ return T_VOID ; }

"main"		{ return T_MAIN ; }

"println"	{ return T_PRINTLN ; }

"int"		{ return T_INT ; }

"float"		{ return T_FLOAT ; }

"for"		{ return T_FOR ; }

"while"		{ return T_WHILE ; }

"if"		{ return T_IF ; }

"else"		{ return T_ELSE ; }

"=="		{ return T_EQUAL ; }

"<="		{ return T_SMALLER ; }

">="		{ return T_BIGGER ; }

"!="		{ return T_NOTEQUAL ; }

{num}		{  return T_NUM ; }

{string}	{ return T_STRING ; }

{id}		{ return T_ID ; }

. 		{ yyerror("lexical error"); exit(1); }

<<EOF>>		{ printf("\nEOF\n") ; return T_eof;; }

%%

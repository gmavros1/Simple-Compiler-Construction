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
num	[1-9]digit*(.digit*)?|0(.digit*)?|1
string 	'(digit|letter)*'
Empty 	[[:space:]]
punct	[[:punct:]]

%%


"mainclass"	{ printf("MAINCLASS ") ; return  MAINCLASS ; }

"public"	{ printf("PUBLIC ") ; return PUBLIC; }
	
"static"	{ printf("STATIC ") ; return STATIC ; }

"void"		{ printf("VOID ") ; return VOID ; }

"main"		{ printf("MAIN ") ; return MAIN ; }

"println"	{ printf("PRINTLN ") ; return PRINTLN ; }

"int"		{ printf("INT ") ; return INT ; }

"float"		{ printf("FLOAT ") ; return FLOAT ; }

"for"		{ printf("FOR ") ; return FOR ; }

"while"		{ printf("WHILE ") ; return WHILE ; }

"if"		{ printf("IF ") ; return IF ; }

"else"		{ printf("ELSE ") ; return ELSE ; }

"=="		{ printf("EQUAL ") ; return EQUAL ; }

"<="		{ printf("SMALLER ") ; return SMALLER ; }

">="		{ printf("BIGGER ") ; return BIGGER ; }

"!="		{ printf("NOTEQUAL ") ; return NOTEQUAL ; }

{Empty}+	{ printf("EMPTY ") ; /* nothing */ }

{id}		{ printf("ID ") ; return ID ; }

{num}		{ printf("NUM ") ; return NUM ; }

{string}	{ printf("STRING ") ; return STRING ; }

{punct}  	{ printf("PUNCT ") ; return yytext[0] ; }

<<EOF>>		{ printf("EOF ") ; return EOF; }

. 		{ yyerror("lexical error"); exit(1); }

%%

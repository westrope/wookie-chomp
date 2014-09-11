%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "y.tab.h"
#include "token.h"
%}

%x comment
%x include
%x string

%%
[ \t]*
[ \n]*

"if"        { return IF; }
"return"    { return RETURN; }
"while"     { return WHILE; }
"do"        { return DO; }
"case"      { return CASE; }
"break"     { return BREAK; }
"switch"    { return SWITCH; }
"for"       { return FOR; }
"class"     { return CLASS; }
"private"   { return PRIVATE; }
"public"    { return PUBLIC; }
";"         { return SEMI; }
"cout"      { return COUT; }
"cin"       { return CIN; }
"<<"        { return OARROW; }
">>"        { return IARROW; }
"endl"      { return ENDL; }
"cin.ignore()"    {return CINGNORE; }
"string"    { return STRING; }
"ifstream"  { return IFSTREAM; }
"fstream"   { return FSTREAM; }
"int"       { return INT; }
"void"      { return VOID; }
"double"    { return DOUBLE; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"boole"     { return BOOLE; }

"("         { return LP; }
")"         { return RP; }
"{"         { return LC; }
"}"         { return RC; }
"["         { return LB; }
"]"         { return RB; }

"::"        { return DBLCOLON; }
":"         { return COLON; }
"."         { return DOT; }
"->"        { return ARROW; }
"++"        { return PLUSPLUS; }
"+="        { return PLUSASSIGN; }
"=="        { return EQUAL; }
"-="        { return MINUSEQUALS; }
"--"        { return MINUSMINUS; }
"!="        { return NEQ; }
"<="        { return LTE; }
">="        { return GTE; }
"<"         { return LT; }
">"         { return GT; }
"%"         { return MOD; }
"/"         { return DIV; }
"*"         { return MUL; }
"!"         { return BANG; }
"||"        { return OR; }
"&&"        { return AND; }
"="         { return ASSIGN; }
"+"         { return PLUS; }
"-"         { return MINUS; }

.           { /* Eat up all bad tokens */ }

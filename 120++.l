%{
#include <stdio.h>
#include <string.h>
#incldue <stdlib.h>
#include <ctype.h>

#include "120++.tab.h"
#include "token.h"
%}

%x comment
%x include
%x string

$$

"/*"                    { BEGIN(comment); }
<comment>[^*\n]*        { /* will eat up anything not a star or newline */ }
<comment>"*"+[^*/\n]*   { /* eat up all stars not followed by '/' or newline */ }
<comment>\n             { linenum++; }
<comment>"*"+"/"        { BEGIN(INITIAL); }





"#include"              { BEGIN(include); }
<include>[ \t]*         { // clean up whitespace }
"<iostream>"
"<cstlib>"
"<ctime>"
"<string>"
"<fstream>"
<include>(\")/.
<include>([^ "]*)       { // match the file name with quotes
                          // open file and parse}
<include>\"             {BEGIN(INITIAL); }


\"                      { BEGIN(string); }
<string>"\n"            { // c-code to deal with escapes goes here }
<string>"\t"
<string>"\'"
<string>"\\"
<string>"\0"
<string>[\\]["]
<string>\\.             /* catch all bad escapes and error */
<string>([^\\"])* 
\"                      { BEGIN(INITIAL); }

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


"("         { return O_PAREN; }
")"         { return C_PAREN; }
"{"         { return O_CURLY; }
"}"         { return C_CURLY; }
"["         { return O_SQRE; }
"]"         { return C_SQRE; }

"::"        { return DBLCOLON; }
":"         { return :; }
"."         { return .; }
"->"        { return ->; }
"++"        { return ++; }
"+="        { return +=; }
"=="        { return ==; }
"-="        { return -=; }
"--"        { return --; }
"!="        { return !=; }
"<="        { return <=; }
">="        { return >=; }
"<"         { return <; }
">"         { return >; }
"%"         { return %; }
"/"         { return /; }
"*"         { return *; }
"!"         { return !; }
"||"        { return ||; }
"&&"        { return &&; }
"="         { return ASSIGN; }
"+"         { return ADD; }
"-"         { return MINUS; }

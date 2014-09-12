%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "y.tab.h"
#include "token.h"
%}

%option yylineno

%x comment
%x include
%x string

%%
[ \t]*
[ \n]*


"/*"        { BEGIN (comment); }
<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>\n
<comment>"*"+"/"        { BEGIN (INITIAL); }


"//"[^\n]*\n



"#include"    { BEGIN (include); }
<include>[ /t]*
<include>"<iostream>"  { printf("found iostream\n"); 
                         BEGIN (INITIAL); }
<include>"<cstdlib>"   { printf("found cstdlib\n");
                         BEGIN (INITIAL); }
<include>"<ctime>"     { printf("found ctime\n");
                         BEGIN (INITIAL); }
<include>"<string>"    { printf("found string\n");
                         BEGIN (INITIAL); }
<include>"<fstream>"   { printf("found fstream\n");
                         BEGIN (INITIAL); }
<include>\"([^ \n\t])+\"    { printf("found user include\n");
                              
                              int len = strlen(yytext) - 2;
                              char *filename = calloc(len, sizeof(char));
                              strncpy(filename, yytext+1, len);
                              filename[len] = '\0';
                              printf("%s\n", filename);

                              yyin = fopen( filename, "r");
                              if( !yyin ){
                                printf("couldn't open include file\n");
                              }
                              yypush_buffer_state(yy_create_buffer( yyin, YY_BUF_SIZE ));
                              free(filename);
                              BEGIN(INITIAL); }


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
"using"     { return USING; }
"namespace"   {return NAMESPC; }
"std"       {return STD; }
"."         { return DOT; }

[a-zA-Z_]([a-zA-Z_]|[0-9])*   { return LIT; }

[0-9]*    {return INTLIT; }

[0-9]*"."[0-9]?   {return FLLIT; }
[0-9]+"."[0-9]*   {return FLLIT; }


\"          { BEGIN (string); }
<string>[^\\\"\n]* 
<string>"\n"
<string>\\t
<string>\\'
<string>"\\"
<string>\\0
<string>\\["]
<string>\"         {printf("found string\n");  BEGIN (INITIAL); }

"("         { return LP; }
")"         { return RP; }
"{"         { return LC; }
"}"         { return RC; }
"["         { return LB; }
"]"         { return RB; }

"::"        { return DBLCOLON; }
":"         { return COLON; }

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
","         { return COMMA; }

<<EOF>>     { yypop_buffer_state();
              if( !YY_CURRENT_BUFFER ){
                 yyterminate();
              }
            }

.           { printf("found bad token\n"); }



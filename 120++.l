%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "y.tab.h"

#include "list.h"

int I = 1;

YY_BUFFER_STATE include_stack[30];
int include_stack_ptr = 0;


%}



%x comment
%x include
%x string

%%
[ \t]*
[ \n]         {  }


"/*"        { BEGIN (comment); }
<comment>[^*\n]*
<comment>"*"+[^*/\n]*
<comment>\n             {  }
<comment>"*"+"/"        { BEGIN (INITIAL); }


"//"[^\n]*\n            {  }



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
                              char *filename = (char *)calloc(len, sizeof(char));
                              strncpy(filename, yytext+1, len);
                              filename[len] = '\0';
                              printf("%s\n", filename);

                              include_stack[include_stack_ptr++] = YY_CURRENT_BUFFER;
                          
                              yyin = fopen( filename, "r");
                              t_filename = filename;
                              if( !yyin ){
                                printf("couldn't open include file\n");
                              }              
               
                              yy_switch_to_buffer(yy_create_buffer(yyin, YY_BUF_SIZE));
                              BEGIN(INITIAL); }


"if"        {  return IF; }
"return"    {  return RETURN; }
"while"     {  return WHILE; }
"do"        {  return DO; }
"case"      {  return CASE; }
"break"     {  return BREAK; }
"switch"    {  return SWITCH; }
"for"       {  return FOR; }
"class"     { return CLASS; }
"private"   { return PRIVATE; }
"public"    {  return PUBLIC; }
";"         {  return SEMI; }
"cout"      {  return COUT; }
"cin"       {  return CIN; }
"<<"        { return OARROW; }
">>"        {  return IARROW; }
"endl"      { return ENDL; }
"cin.ignore()"    { return CINGNORE; }
"string"    {  return STRING; }
"ifstream"  {  return IFSTREAM; }
"fstream"   {  return FSTREAM; }
"int"       {  return INT; }
"void"      {  return VOID; }
"double"    {  return DOUBLE; }
"float"     {  return FLOAT; }
"char"      {  return CHAR; }
"boole"     {  return BOOLE; }
"using"     {  return USING; }
"namespace"   { return NAMESPC; }
"std"       { return STD; }
"."         {  return DOT; }

[a-zA-Z_]([a-zA-Z_]|[0-9])*   {  return LIT; }

[0-9]*    { return INTLIT; }

[0-9]*"."[0-9]?   { return FLLIT; }
[0-9]+"."[0-9]*   { return FLLIT; }


\"          { BEGIN (string); }
<string>(\\.|[^\\\"\n])*     { int len = strlen(yytext)+1;
                               printf("len:%d\n", len);
                               t_sval =(char*)calloc((strlen(yytext)+1), sizeof(char));
                               int i; 
                               int j;
                               i = 0; 
                               j = 0;
                               while( yytext[i] != '\0' && i != '\\' ){
                                 if( yytext[i] == '\\' && yytext[i+1] == 'n' ) { t_sval[j++] = '\n'; i++; i++; }
                                 if( yytext[i] == '\\' && yytext[i+1] == 't' ) {t_sval[j++] = '\t'; i++; i++; }
                                 if( yytext[i] == '\\' && yytext[i+1] == '\'' ) {t_sval[j++] = '\''; i++; i++; }
                                 if( yytext[i] == '\\' && yytext[i+1] == '\\' ) {t_sval[j++] = '\\'; i++; i++; }
                                 if( yytext[i] == '\\' && yytext[i+1] == '\"' ) { t_sval[j++] = '\"'; i++; i++; }
                                 if( yytext[i] == '\\' && yytext[i+1] == '0' ) { t_sval[j++] = '\0'; i++; i++; }
                                 else  t_sval[j++] = yytext[i++];
                               }
                               t_sval = realloc(t_sval, strlen(t_sval)+1);
                                return SLIT; }
<string>\"         {printf("found string\n");  BEGIN (INITIAL); }

"("         {  return LP; }
")"         {  return RP; }
"{"         {  return LC; }
"}"         {  return RC; }
"["         {  return LB; }
"]"         {  return RB; }

"::"        {  return DBLCOLON; }
":"         {  return COLON; }

"->"        {  return ARROW; }
"++"        {  return PLUSPLUS; }
"+="        {  return PLUSASSIGN; }
"=="        {  return EQUAL; }
"-="        {  return MINUSEQUALS; }
"--"        {  return MINUSMINUS; }
"!="        {  return NEQ; }
"<="        {  return LTE; }
">="        {  return GTE; }
"<"         {  return LT; }
">"         {  return GT; }
"%"         {  return MOD; }
"/"         {  return DIV; }
"*"         {  return MUL; }
"!"         {  return BANG; }
"||"        {  return OR; }
"&&"        {  return AND; }
"="         {  return ASSIGN; }
"+"         {  return PLUS; }
"-"         {  return MINUS; }
","         {  return COMMA; }

<<EOF>>     {
              if( (--include_stack_ptr) <= 0){
              yyterminate();}
              else{
             
             //   yy_delete_buffer( YY_CURRENT_BUFFER);
                yy_switch_to_buffer(include_stack[include_stack_ptr]);
              }

            }



.           { printf("found bad token\n"); }


%%

int yywrap(){
     I++;
     printf("%d\n", g_argc);
     if( I < g_argc ){
       yyin = fopen( g_argv[I], "r");
       return 0;
     }
     return 1;
}

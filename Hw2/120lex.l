/*     120gram.l
       
       Ian Westrope
       CS 445


      The code for handling multiple input files aka includes I found in the
      flex manual.
*/

/*	$Id: lexer.l,v 1.2 1997/11/19 15:13:15 sandro Exp $	*/

/*
 * Copyright (c) 1997 Sandro Sigala <ssigala@globalnet.it>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * ISO C++ lexical analyzer.
 *
 * Based on the ISO C++ draft standard of December '96.
 */

%{
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "120gram.h"
#include "tree.h"

int lineno;

static int yywrap(void);
static void skip_until_eol(void);
static void skip_comment(void);
static int check_identifier(char *);
%}

/* headerfile to use yypush_buffer in main.c */
%option header-file="120lex.h" 

intsuffix				([uU][lL]?)|([lL][uU]?)
fracconst				([0-9]*\.[0-9]+)|([0-9]+\.)
exppart					[eE][-+]?[0-9]+
floatsuffix				[fFlL]
chartext				([^'])|(\\.)
stringtext				([^"])|(\\.)

%x include

%%

"\n"					{ ++lineno; }
[\t\f\v\r ]+				{ /* Ignore whitespace. */ }

"/*"					{ skip_comment(); }
"//"					{ skip_until_eol(); }


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

                              yyin = fopen( filename, "r");
                              if( !yyin ){
                                printf("couldn't open include file\n");
                              }              
               
                              yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));
                              BEGIN(INITIAL); }

"{"					{yylval.np = alcleaf('{', yytext); return '{'; }
"<%"					{ return '{'; }
"}"					{ return '}'; }
"%>"					{ return '}'; }
"["					{ return '['; }
"<:"					{ return '['; }
"]"					{ return ']'; }
":>"					{ return ']'; }
"("					{ return '('; }
")"					{ return ')'; }
";"					{ return ';'; }
":"					{ return ':'; }
"..."					{ return ELLIPSIS; }
"?"					{ return '?'; }
"::"					{ return COLONCOLON; }
"."					{ return '.'; }
".*"					{ return DOTSTAR; }
"+"					{ return '+'; }
"-"					{ return '-'; }
"*"					{ return '*'; }
"/"					{ return '/'; }
"%"					{ return '%'; }
"^"					{ return '^'; }
"xor"					{ return '^'; }
"&"					{ return '&'; }
"bitand"				{ return '&'; }
"|"					{ return '|'; }
"bitor"					{ return '|'; }
"~"					{ return '~'; }
"compl"					{ return '~'; }
"!"					{ return '!'; }
"not"					{ return '!'; }
"="					{ return '='; }
"<"					{ return '<'; }
">"					{ return '>'; }
"+="					{ return ADDEQ; }
"-="					{ return SUBEQ; }
"*="					{ return MULEQ; }
"/="					{ return DIVEQ; }
"%="					{ return MODEQ; }
"^="					{ return XOREQ; }
"xor_eq"				{ return XOREQ; }
"&="					{ return ANDEQ; }
"and_eq"				{ return ANDEQ; }
"|="					{ return OREQ; }
"or_eq"					{ return OREQ; }
"<<"					{ return SL; }
">>"					{ return SR; }
"<<="					{ return SLEQ; }
">>="					{ return SREQ; }
"=="					{ return EQ; }
"!="					{ return NOTEQ; }
"not_eq"				{ return NOTEQ; }
"<="					{ return LTEQ; }
">="					{ return GTEQ; }
"&&"					{ return ANDAND; }
"and"					{ return ANDAND; }
"||"					{ return OROR; }
"or"					{ return OROR; }
"++"					{ return PLUSPLUS; }
"--"					{ return MINUSMINUS; }
","					{ return ','; }
"->*"					{ return ARROWSTAR; }
"->"					{ return ARROW; }

"asm"					{ return ASM; }
"auto"					{ return AUTO; }
"bool"					{ return BOOL; }
"break"					{ return BREAK; }
"case"					{ return CASE; }
"catch"					{ return CATCH; }
"char"					{ return CHAR; }
"class"					{ return CLASS; }
"const"					{ return CONST; }
"const_cast"				{ return CONST_CAST; }
"continue"				{ return CONTINUE; }
"default"				{ return DEFAULT; }
"delete"				{ return DELETE; }
"do"					{ return DO; }
"double"				{ return DOUBLE; }
"dynamic_cast"				{ return DYNAMIC_CAST; }
"else"					{ return ELSE; }
"enum"					{ return ENUM; }
"explicit"				{ return EXPLICIT; }
"export"				{ return EXPORT; }
"extern"				{ return EXTERN; }
"false"					{ return FALSE; }
"float"					{ return FLOAT; }
"for"					{ return FOR; }
"friend"				{ return FRIEND; }
"goto"					{ return GOTO; }
"if"					{ return IF; }
"inline"				{ return INLINE; }
"int"					{ return INT; }
"long"					{ return LONG; }
"mutable"				{ return MUTABLE; }
"namespace"				{ return NAMESPACE; }
"new"					{ return NEW; }
"operator"				{ return OPERATOR; }
"private"				{ return PRIVATE; }
"protected"				{ return PROTECTED; }
"public"				{ return PUBLIC; }
"register"				{ return REGISTER; }
"reinterpret_cast"			{ return REINTERPRET_CAST; }
"return"				{ return RETURN; }
"short"					{ return SHORT; }
"signed"				{ return SIGNED; }
"sizeof"				{ return SIZEOF; }
"static"				{ return STATIC; }
"static_cast"				{ return STATIC_CAST; }
"struct"				{ return STRUCT; }
"switch"				{ return SWITCH; }
"template"				{ return TEMPLATE; }
"this"					{ return THIS; }
"throw"					{ return THROW; }
"true"					{ return TRUE; }
"try"					{ return TRY; }
"typedef"				{ return TYPEDEF; }
"typeid"				{ return TYPEID; }
"typename"				{ return TYPENAME; }
"union"					{ return UNION; }
"unsigned"				{ return UNSIGNED; }
"using"					{ return USING; }
"virtual"				{ return VIRTUAL; }
"void"					{ return VOID; }
"volatile"				{ return VOLATILE; }
"wchar_t"				{ return WCHAR_T; }
"while"					{ return WHILE; }

[a-zA-Z_][a-zA-Z_0-9]*			{ return check_identifier(yytext); }

"0"[xX][0-9a-fA-F]+{intsuffix}?		{ return INTEGER; }
"0"[0-7]+{intsuffix}?			{ return INTEGER; }
[0-9]+{intsuffix}?			{ return INTEGER; }

{fracconst}{exppart}?{floatsuffix}?	{ return FLOATING; }
[0-9]+{exppart}{floatsuffix}?		{ return FLOATING; }

"'"{chartext}*"'"			{ return CHARACTER; }
"L'"{chartext}*"'"			{ return CHARACTER; }

"\""{stringtext}*"\""			{ return STRING; }
"L\""{stringtext}*"\""			{ return STRING; }

.					{ fprintf(stderr, "%d: unexpected character `%c'\n", lineno, yytext[0]); }

<<EOF>> {
     	  yypop_buffer_state();
     
          if ( !YY_CURRENT_BUFFER )
          {
            yyterminate();
          }
        }


%%

static int
yywrap(void)
{
	return 1;
}

/*
 * We use this routine instead a lex pattern because we don't need
 * to save the matched comment in the `yytext' buffer.
 */
static void
skip_comment(void)
{
	int c1, c2;

	c1 = input();
	c2 = input();

	while (c2 != EOF && !(c1 == '*' && c2 == '/')) {
		if (c1 == '\n')
			++lineno;
		c1 = c2;
		c2 = input();
	}
}

/*
 * See the previous comment for an explanation.
 */
static void
skip_until_eol(void)
{
	int c;

	while ((c = input()) != EOF && c != '\n')
		;
	++lineno;
}

/*
 * Type name table.
 * Replace this with a hash table, when you get a chance.
 */
struct typenametable_entry {
   char *name;
   int category;
   struct typenametable_entry *next;
   } *head;

int typenametable_lookup(char *s)
{
   struct typenametable_entry *tmp = head;
   while (tmp) {
      if (!strcmp(s, tmp->name)) return tmp->category;
      tmp = tmp->next;
   }
   return IDENTIFIER;
}

int typenametable_insert(char *s, int cat)
{
   struct typenametable_entry *tmp = head;
   while (tmp) {
      if (!strcmp(s, tmp->name)) {
         fprintf(stderr,
	    "warning, %s is already in the typename table as a %d\n",
	    s, tmp->category );
         return tmp->category;
         }
      tmp = tmp->next;
   }
   tmp = calloc(1, sizeof (struct typenametable_entry));
   if(!tmp) { fprintf(stderr, "tnti out of memory\n"); return -1; }
   tmp->name = strdup(s);
   tmp->category = cat;
   tmp->next = head;
   head = tmp;
}

static int
check_identifier(char *s)
{
	return typenametable_lookup(s);
}

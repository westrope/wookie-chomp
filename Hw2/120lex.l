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

"{"					{ yylval.np = alcleaf('{', yytext); 
                                         return '{'; }
"<%"					{ yylval.np = alcleaf('{', yytext); 
                                          return '{'; }
"}"					{ yylval.np = alcleaf('}', yytext); 
                                          return '}'; }
"%>"					{ yylval.np = alcleaf('}', yytext); 
                                          return '}'; }
"["					{ yylval.np = alcleaf('[', yytext); 
                                          return '['; }
"<:"					{ yylval.np = alcleaf('[', yytext); 
                                          return '['; }
"]"					{ yylval.np = alcleaf(']', yytext); 
                                          return ']'; }
":>"					{ yylval.np = alcleaf(']', yytext); 
                                          return ']'; }
"("					{ yylval.np = alcleaf('(', yytext); 
                                          return '('; }
")"					{ yylval.np = alcleaf(')', yytext); 
                                          return ')'; }
";"					{ yylval.np = alcleaf(';', yytext); 
                                          return ';'; }
":"					{ yylval.np = alcleaf(':', yytext); 
                                          return ':'; }
"..."					{ yylval.np = alcleaf(ELLIPSIS, yytext); 
                                          return ELLIPSIS; }
"?"					{ yylval.np = alcleaf('?', yytext); 
                                          return '?'; }
"::"					{ yylval.np = alcleaf(COLONCOLON, yytext); 
                                          return COLONCOLON; }
"."					{ yylval.np = alcleaf('.', yytext); 
                                          return '.'; }
".*"					{ yylval.np = alcleaf(DOTSTAR, yytext); 
                                          return DOTSTAR; }
"+"					{ yylval.np = alcleaf('+', yytext); 
                                          return '+'; }
"-"					{ yylval.np = alcleaf('-', yytext); 
                                          return '-'; }
"*"					{ yylval.np = alcleaf('*', yytext); 
                                          return '*'; }
"/"					{ yylval.np = alcleaf('/', yytext); 
                                          return '/'; }
"%"					{ yylval.np = alcleaf('%', yytext); 
                                          return '%'; }
"^"					{ yylval.np = alcleaf('^', yytext); 
                                          return '^'; }
"xor"					{ yylval.np = alcleaf('^', yytext); 
                                          return '^'; }
"&"					{ yylval.np = alcleaf('&', yytext); 
                                          return '&'; }
"bitand"				{ yylval.np = alcleaf('&', yytext); 
                                          return '&'; }
"|"					{ yylval.np = alcleaf('|', yytext); 
                                          return '|'; }
"bitor"					{ yylval.np = alcleaf('|', yytext); 
                                          return '|'; }
"~"					{ yylval.np = alcleaf('~', yytext); 
                                          return '~'; }
"compl"					{ yylval.np = alcleaf('~', yytext); 
                                          return '~'; }
"!"					{ yylval.np = alcleaf('!', yytext); 
                                          return '!'; }
"not"					{ yylval.np = alcleaf('!', yytext); 
                                          return '!'; }
"="					{ yylval.np = alcleaf('=', yytext); 
                                          return '='; }
"<"					{ yylval.np = alcleaf('<', yytext); 
                                          return '<'; }
">"					{ yylval.np = alcleaf('>', yytext); 
                                          return '>'; }
"+="					{ yylval.np = alcleaf(ADDEQ, yytext); 
                                          return ADDEQ; }
"-="					{ yylval.np = alcleaf(SUBEQ, yytext); 
                                          return SUBEQ; }
"*="					{ yylval.np = alcleaf(MULEQ, yytext); 
                                          return MULEQ; }
"/="					{ yylval.np = alcleaf(DIVEQ, yytext); 
                                          return DIVEQ; }
"%="					{ yylval.np = alcleaf(MODEQ, yytext); 
                                          return MODEQ; }
"^="					{ yylval.np = alcleaf(XOREQ, yytext); 
                                          return XOREQ; }
"xor_eq"				{ yylval.np = alcleaf(XOREQ, yytext); 
                                          return XOREQ; }
"&="					{ yylval.np = alcleaf(ANDEQ, yytext); 
                                          return ANDEQ; }
"and_eq"				{ yylval.np = alcleaf(ANDEQ, yytext); 
                                          return ANDEQ; }
"|="					{ yylval.np = alcleaf(OREQ, yytext); 
                                          return OREQ; }
"or_eq"					{ yylval.np = alcleaf(OREQ, yytext); 
                                          return OREQ; }
"<<"					{ yylval.np = alcleaf(SL, yytext); 
                                          return SL; }
">>"					{ yylval.np = alcleaf(SR, yytext); 
                                          return SR; }
"<<="					{ yylval.np = alcleaf(SLEQ, yytext); 
                                          return SLEQ; }
">>="					{ yylval.np = alcleaf(SREQ, yytext); 
                                          return SREQ; }
"=="					{ yylval.np = alcleaf(EQ, yytext); 
                                          return EQ; }
"!="					{ yylval.np = alcleaf(NOTEQ, yytext); 
                                          return NOTEQ; }
"not_eq"				{ yylval.np = alcleaf(NOTEQ, yytext); 
                                          return NOTEQ; }
"<="					{ yylval.np = alcleaf(LTEQ, yytext); 
                                          return LTEQ; }
">="					{ yylval.np = alcleaf(GTEQ, yytext); 
                                          return GTEQ; }
"&&"					{ yylval.np = alcleaf(ANDAND, yytext); 
                                          return ANDAND; }
"and"					{ yylval.np = alcleaf(ANDAND, yytext); 
                                          return ANDAND; }
"||"					{ yylval.np = alcleaf(OROR, yytext); 
                                          return OROR; }
"or"					{ yylval.np = alcleaf(OROR, yytext); 
                                          return OROR; }
"++"					{ yylval.np = alcleaf(PLUSPLUS, yytext); 
                                          return PLUSPLUS; }
"--"					{ yylval.np = alcleaf(MINUSMINUS, yytext); 
                                          return MINUSMINUS; }
","					{ yylval.np = alcleaf(',', yytext); 
                                          return ','; }
"->*"					{ yylval.np = alcleaf(ARROWSTAR, yytext); 
                                          return ARROWSTAR; }
"->"					{ yylval.np = alcleaf(ARROW, yytext); 
                                          return ARROW; }

"asm"					{ yylval.np = alcleaf(ASM, yytext); 
                                          return ASM; }
"auto"					{ yylval.np = alcleaf(AUTO, yytext); 
                                          return AUTO; }
"bool"					{ yylval.np = alcleaf(BOOL, yytext); 
                                          return BOOL; }
"break"					{ yylval.np = alcleaf(BREAK, yytext); 
                                          return BREAK; }
"case"					{ yylval.np = alcleaf(CASE, yytext); 
                                          return CASE; }
"catch"					{ yylval.np = alcleaf(CATCH, yytext); 
                                          return CATCH; }
"char"					{ yylval.np = alcleaf(CHAR, yytext); 
                                          return CHAR; }
"class"					{ yylval.np = alcleaf(CLASS, yytext); 
                                          return CLASS; }
"const"					{ yylval.np = alcleaf(CONST, yytext); 
                                          return CONST; }
"const_cast"				{ yylval.np = alcleaf(CONST_CAST, yytext); 
                                          return CONST_CAST; }
"continue"				{ yylval.np = alcleaf(CONTINUE, yytext); 
                                          return CONTINUE; }
"default"				{ yylval.np = alcleaf(DEFAULT, yytext); 
                                          return DEFAULT; }
"delete"				{ yylval.np = alcleaf(DELETE, yytext); 
                                          return DELETE; }
"do"					{ yylval.np = alcleaf(DO, yytext); 
                                          return DO; }
"double"				{ yylval.np = alcleaf(DOUBLE, yytext); 
                                          return DOUBLE; }
"dynamic_cast"				{ yylval.np = alcleaf(DYNAMIC_CAST, yytext); 
                                          return DYNAMIC_CAST; }
"else"					{ yylval.np = alcleaf(ELSE, yytext); 
                                          return ELSE; }
"enum"					{ yylval.np = alcleaf(ENUM, yytext); 
                                          return ENUM; }
"explicit"				{ yylval.np = alcleaf(EXPLICIT, yytext); 
                                          return EXPLICIT; }
"export"				{ yylval.np = alcleaf(EXPORT, yytext); 
                                          return EXPORT; }
"extern"				{ yylval.np = alcleaf(EXTERN, yytext); 
                                          return EXTERN; }
"false"					{ yylval.np = alcleaf(FALSE, yytext); 
                                          return FALSE; }
"float"					{ yylval.np = alcleaf(FLOAT, yytext); 
                                          return FLOAT; }
"for"					{ yylval.np = alcleaf(FOR, yytext); 
                                          return FOR; }
"friend"				{ yylval.np = alcleaf(FRIEND, yytext); 
                                          return FRIEND; }
"goto"					{ yylval.np = alcleaf(GOTO, yytext); 
                                          return GOTO; }
"if"					{ yylval.np = alcleaf(IF, yytext); 
                                          return IF; }
"inline"				{ yylval.np = alcleaf(INLINE, yytext); 
                                          return INLINE; }
"int"					{ yylval.np = alcleaf(INT, yytext); 
                                          return INT; }
"long"					{ yylval.np = alcleaf(LONG, yytext); 
                                          return LONG; }
"mutable"				{ yylval.np = alcleaf(MUTABLE, yytext); 
                                          return MUTABLE; }
"namespace"				{ yylval.np = alcleaf(NAMESPACE, yytext); 
                                          return NAMESPACE; }
"new"					{ yylval.np = alcleaf(NEW, yytext); 
                                          return NEW; }
"operator"				{ yylval.np = alcleaf(OPERATOR, yytext); 
                                          return OPERATOR; }
"private"				{ yylval.np = alcleaf(PRIVATE, yytext); 
                                          return PRIVATE; }
"protected"				{ yylval.np = alcleaf(PROTECTED, yytext); 
                                          return PROTECTED; }
"public"				{ yylval.np = alcleaf(PUBLIC, yytext); 
                                          return PUBLIC; }
"register"				{ yylval.np = alcleaf(REGISTER, yytext); 
                                          return REGISTER; }
"reinterpret_cast"			{ yylval.np = alcleaf(REINTERPRET_CAST, yytext); 
                                          return REINTERPRET_CAST; }
"return"				{ yylval.np = alcleaf(RETURN, yytext); 
                                          return RETURN; }
"short"					{ yylval.np = alcleaf(SHORT, yytext); 
                                          return SHORT; }
"signed"				{ yylval.np = alcleaf(SIGNED, yytext); 
                                          return SIGNED; }
"sizeof"				{ yylval.np = alcleaf(SIZEOF, yytext); 
                                          return SIZEOF; }
"static"				{ yylval.np = alcleaf(STATIC, yytext); 
                                          return STATIC; }
"static_cast"				{ yylval.np = alcleaf(STATIC_CAST, yytext); 
                                          return STATIC_CAST; }
"struct"				{ yylval.np = alcleaf(STRUCT, yytext); 
                                          return STRUCT; }
"switch"				{ yylval.np = alcleaf(SWITCH, yytext); 
                                          return SWITCH; }
"template"				{ yylval.np = alcleaf(TEMPLATE, yytext); 
                                          return TEMPLATE; }
"this"					{ yylval.np = alcleaf(THIS, yytext); 
                                          return THIS; }
"throw"					{ yylval.np = alcleaf(THROW, yytext); 
                                          return THROW; }
"true"					{ yylval.np = alcleaf(TRUE, yytext); 
                                          return TRUE; }
"try"					{ yylval.np = alcleaf(TRY, yytext); 
                                          return TRY; }
"typedef"				{ yylval.np = alcleaf(TYPEDEF, yytext); 
                                          return TYPEDEF; }
"typeid"				{ yylval.np = alcleaf(TYPEID, yytext); 
                                          return TYPEID; }
"typename"				{ yylval.np = alcleaf(TYPENAME, yytext); 
                                          return TYPENAME; }
"union"					{ yylval.np = alcleaf(UNION, yytext); 
                                          return UNION; }
"unsigned"				{ yylval.np = alcleaf(UNSIGNED, yytext); 
                                          return UNSIGNED; }
"using"					{ yylval.np = alcleaf(USING, yytext); 
                                          return USING; }
"virtual"				{ yylval.np = alcleaf(VIRTUAL, yytext); 
                                          return VIRTUAL; }
"void"					{ yylval.np = alcleaf(VOID, yytext); 
                                          return VOID; }
"volatile"				{ yylval.np = alcleaf(VOLATILE, yytext); 
                                          return VOLATILE; }
"wchar_t"				{ yylval.np = alcleaf(WCHAR_T, yytext); 
                                          return WCHAR_T; }
"while"					{ yylval.np = alcleaf(WHILE, yytext); 
                                          return WHILE; }

[a-zA-Z_][a-zA-Z_0-9]*			{ yylval.np = alcleaf(IDENTIFIER, yytext); 
                                          return check_identifier(yytext); }

"0"[xX][0-9a-fA-F]+{intsuffix}?		{ yylval.np = alcleaf(INTEGER, yytext); 
                                          return INTEGER; }
"0"[0-7]+{intsuffix}?			{ yylval.np = alcleaf(INTEGE, yytext); 
                                          return INTEGER; }
[0-9]+{intsuffix}?			{ yylval.np = alcleaf(INTEGER, yytext); 
                                          return INTEGER; }

{fracconst}{exppart}?{floatsuffix}?	{ yylval.np = alcleaf(FLOATING, yytext); 
                                          return FLOATING; }
[0-9]+{exppart}{floatsuffix}?		{ yylval.np = alcleaf(FLOATING, yytext); 
                                          return FLOATING; }

"'"{chartext}*"'"			{ yylval.np = alcleaf(CHARACTER, yytext); 
                                          return CHARACTER; }
"L'"{chartext}*"'"			{ yylval.np = alcleaf(CHARACTER, yytext); 
                                          return CHARACTER; }

"\""{stringtext}*"\""			{ yylval.np = alcleaf(STRING, yytext); 
                                          return STRING; }
"L\""{stringtext}*"\""			{ yylval.np = alcleaf(STRING, yytext); 
                                          return STRING; }

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

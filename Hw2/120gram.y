/*
 * Grammar for 120++, a subset of C++ used in CS 120 at University of Idaho
 *
 * Adaptation by Clinton Jeffery, with help from Matthew Brown, Ranger
 * Adams, and Shea Newton.
 *
 * Based on Sandro Sigala's transcription of the ISO C++ 1996 draft standard.
 * 
 */

/*	$Id: parser.y,v 1.3 1997/11/19 15:13:16 sandro Exp $	*/

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
 * ISO C++ parser.
 *
 * Based on the ISO C++ draft standard of December '96.
 */

%{
#include <stdio.h>
#include <string.h>


#include "120lex.h"
#include "prodrules.h"

#include "symbol.h"

extern int lineno;
extern char *yytext;
int yydebug=0;

static void yyerror(char *s);
node *yyroot;
List * table; 
int scope = 0;
%}

// union of a tree node pointer
%union {
  struct node *np;
  }


%token <np> IDENTIFIER INTEGER FLOATING CHARACTER STRING
%token <np> NAMESPACE_NAME CLASS_NAME ENUM_NAME TEMPLATE_NAME

%token <np> ELLIPSIS COLONCOLON DOTSTAR ADDEQ SUBEQ MULEQ DIVEQ MODEQ
%token <np> XOREQ ANDEQ OREQ SL SR SREQ SLEQ EQ NOTEQ LTEQ GTEQ ANDAND OROR
%token <np> PLUSPLUS MINUSMINUS ARROWSTAR ARROW

%token <np> ASM AUTO BOOL BREAK CASE CATCH CHAR CLASS CONST CONST_CAST CONTINUE
%token <np> DEFAULT DELETE DO DOUBLE DYNAMIC_CAST ELSE ENUM EXPLICIT EXPORT EXTERN
%token <np> FALSE FLOAT FOR FRIEND GOTO IF INLINE INT LONG MUTABLE NAMESPACE NEW
%token <np> OPERATOR PRIVATE PROTECTED PUBLIC REGISTER REINTERPRET_CAST RETURN
%token <np> SHORT SIGNED SIZEOF STATIC STATIC_CAST STRUCT SWITCH TEMPLATE THIS
%token <np> THROW TRUE TRY TYPEDEF TYPEID TYPENAME UNION UNSIGNED USING VIRTUAL
%token <np> VOID VOLATILE WCHAR_T WHILE '{' '}' '[' ']' '(' ')'
%token <np> ';' ':' '?' '.' '+' '-' '*' '/' '%' '^' '&' '|' '~' '!' '=' '<'
%token <np> '>' ','


 // %type goes here
%type <np> literal
%type <np> boolean_literal primary_expression unqualified_id
%type <np> qualified_id nested_name_specifier postfix_expression expression_list unary_expression
%type <np> unary_operator new_expression new_placement new_type_id new_declarator 
%type <np> direct_new_declarator new_initializer delete_expression
%type <np> pm_expression multiplicative_expression additive_expression shift_expression
%type <np> relational_expression equality_expression and_expression exclusive_or_expression
%type <np> inclusive_or_expression logical_and_expression logical_or_expression 
%type <np> conditional_expression assignment_expression assignment_operator expression
%type <np> constant_expression statement labeled_statement compound_statement
%type <np> statement_seq selection_statement condition iteration_statement for_init_statement
%type <np> jump_statement declaration_statement declaration_seq declaration block_declaration
%type <np> simple_declaration decl_specifier decl_specifier_seq
%type <np> type_specifier simple_type_specifier 
%type <np> elaborated_type_specifier
%type <np> init_declarator_list init_declarator declarator direct_declarator ptr_operator
%type <np> declarator_id type_id type_specifier_seq 
%type <np> abstract_declarator direct_abstract_declarator parameter_declaration_clause
%type <np> parameter_declaration_list parameter_declaration function_body
%type <np> initializer initializer_clause initializer_list class_specifier class_head
%type <np> class_key member_specification member_declaration member_declarator_list
%type <np> member_declarator constant_initializer
%type <np> access_specifier
%type <np> mem_initializer_list
%type <np> mem_initializer mem_initializer_id
%type <np> declaration_seq_opt expression_list_opt
%type <np> new_placement_opt new_initializer_opt new_declarator_opt expression_opt
%type <np> statement_seq_opt condition_opt initializer_opt 
%type <np> constant_expression_opt abstract_declarator_opt type_specifier_seq_opt
%type <np> ctor_initializer_opt COMMA_opt member_specification_opt
%type <np> SEMICOLON_opt
%type <np> id_expression expression_statement
%type <np> function_definition
%type <np> ctor_initializer program

%start program

%%


/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/



literal:
	INTEGER { $$ = alcnary(LITERAL1, 1, $1); }
	| CHARACTER { $$ = alcnary(LITERAL2, 1, $1); }
	| FLOATING { $$ = alcnary(LITERAL3, 1, $1); }
	| STRING { $$ = alcnary(LITERAL4, 1, $1); }
	| boolean_literal { $$ = alcnary(LITERAL5, 1, $1); }
	;

boolean_literal:
	TRUE { $$ = alcnary(BOOLEAN_LITERAL1, 1, $1); }
        | FALSE { $$ = alcnary(BOOLEAN_LITERAL2, 1, $1); }
	;

program:
        declaration_seq_opt {yyroot = $1; printf("assigning root \n"); treeprint(yyroot, 0);
	  table = create_list();
	  pop_table(table, yyroot, scope);
	  type_check(table, yyroot, scope);
	  print(table);}
        ;



/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal { $$ = alcnary(PRIMARY_EXPRESSION1, 1, $1); }
| '(' expression ')' { $$ = alcnary(PRIMARY_EXPRESSION3, 1, $2); }
	| id_expression { $$ = alcnary(PRIMARY_EXPRESSION2, 1, $1); }
	;

id_expression:
	unqualified_id { $$ = alcnary(ID_EXPRESSION1, 1, $1); }
	| qualified_id { $$ = alcnary(ID_EXPRESSION2, 1, $1); }
	;

unqualified_id:
	IDENTIFIER { $$ = alcnary(UNQUALIFIED_ID1, 1, $1); }
	;

qualified_id:
	nested_name_specifier unqualified_id { $$ = alcnary(QUALIFIED_ID1, 2, $1, $2); }
	;

nested_name_specifier:
        CLASS_NAME COLONCOLON nested_name_specifier
	| CLASS_NAME COLONCOLON { $$ = alcnary(NESTED_NAME_SPECIFIER2, 2, $1, $2); }
	;

postfix_expression:
	primary_expression { $$ = alcnary(POSTFIX_EXPRESSION1, 1, $1); }
        | postfix_expression '[' expression ']' { $$ = alcnary(POSTFIX_EXPRESSION2, 4, $1, $2, $3, $4); }
	| postfix_expression '(' expression_list_opt ')' { $$ = alcnary(POSTFIX_EXPRESSION3, 4, $1, $2, $3, $4); }
        | simple_type_specifier '(' expression_list_opt ')' { $$ = alcnary(POSTFIX_EXPRESSION4, 4, $1, $2, $3, $4); }
	| postfix_expression '.' id_expression { $$ = alcnary(POSTFIX_EXPRESSION7, 3, $1, $2, $3); }
	| postfix_expression ARROW id_expression { $$ = alcnary(POSTFIX_EXPRESSION11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS { $$ = alcnary(POSTFIX_EXPRESSION12, 2, $1, $2); }
	| postfix_expression MINUSMINUS { $$ = alcnary(POSTFIX_EXPRESSION13, 2, $1, $2); }
	;

expression_list:
	assignment_expression { $$ = alcnary(ASSIGNMENT_EXPRESSION1, 1, $1); }
	| expression_list ',' assignment_expression { $$ = alcnary(EXPRESSION_LIST2, 3, $1, $2, $3); }
	;

unary_expression:
	postfix_expression { $$ = alcnary(UNARY_EXPRESSION1, 1, $1); }
	| PLUSPLUS unary_expression { $$ = alcnary(UNARY_EXPRESSION2, 2, $1, $2); }
	| MINUSMINUS unary_expression { $$ = alcnary(UNARY_EXPRESSION3, 2, $1, $2); }
	| '*' unary_expression { $$ = alcnary(UNARY_EXPRESSION4, 2, $1, $2); }
	| '&' unary_expression { $$ = alcnary(UNARY_EXPRESSION5, 2, $1, $2); }
	| unary_operator unary_expression { $$ = alcnary(UNARY_EXPRESSION6, 2, $1, $2); }
	| SIZEOF unary_expression { $$ = alcnary(UNARY_EXPRESSION7, 2, $1, $2); }
	| SIZEOF '(' type_id ')' { $$ = alcnary(UNARY_EXPRESSION8, 4, $1, $2, $3, $4); }
	| new_expression { $$ = alcnary(UNARY_EXPRESSION9, 1, $1); }
	| delete_expression { $$ = alcnary(UNARY_EXPRESSION10, 1, $1); }
	;

unary_operator:
	  '+' { $$ = alcnary(UNARY_OPERATOR1, 1, $1); }
	| '-' { $$ = alcnary(UNARY_OPERATOR2, 1, $1); }
	| '!' { $$ = alcnary(UNARY_OPERATOR3, 1, $1); }
	| '~' { $$ = alcnary(UNARY_OPERATOR4, 1, $1); }
	;

new_expression:
	  NEW new_placement_opt new_type_id new_initializer_opt { $$ = alcnary(NEW_EXPRESSION1, 4, $1, $2, $3, $4); }
	;

new_placement:
	'(' expression_list ')' { $$ = alcnary(NEW_PLACEMENT1, 3, $1, $2, $3); }
	;

new_type_id:
	type_specifier_seq new_declarator_opt { $$ = alcnary(NEW_TYPE_ID1, 2, $1, $2); }
	;

new_declarator:
	ptr_operator new_declarator_opt { $$ = alcnary(NEW_DECLARATOR1, 2, $1, $2); }
	| direct_new_declarator { $$ = alcnary(NEW_DECLARATOR2, 1, $1); }
	;

direct_new_declarator:
	'[' expression ']' { $$ = alcnary(DIRECT_NEW_DECLARATOR1, 3, $1, $2, $3); }
	| direct_new_declarator '[' constant_expression ']' { $$ = alcnary(DIRECT_NEW_DECLARATOR2, 4, $1, $2, $3, $4); }
	;

new_initializer:
	'(' expression_list_opt ')' { $$ = alcnary(NEW_INITIALIZER1, 3, $1, $2, $3); }
	;

delete_expression:
        DELETE unary_expression                      { $$ = alcnary(DELETE_EXPRESSION1, 2, $1, $2); }
        | DELETE '[' ']' unary_expression            { $$ = alcnary(DELETE_EXPRESSION2, 4, $1, $2, $3, $4); }
	;


pm_expression:
	unary_expression { $$ = alcnary(PM_EXPRESSION1, 1, $1); }
	| pm_expression DOTSTAR unary_expression { $$ = alcnary(PM_EXPRESSION2, 3, $1, $2, $3); }
	| pm_expression ARROWSTAR unary_expression { $$ = alcnary(PM_EXPRESSION3, 3, $1, $2, $3); }
	;

multiplicative_expression:
        pm_expression  { $$ = alcnary(MULTIPLICATIVE_EXPRESSION1, 1, $1); }
	| multiplicative_expression '*' pm_expression { $$ = alcnary(MULTIPLICATIVE_EXPRESSION2, 2, $1, $3); }
	| multiplicative_expression '/' pm_expression { $$ = alcnary(MULTIPLICATIVE_EXPRESSION3, 2, $1, $3); }
	| multiplicative_expression '%' pm_expression { $$ = alcnary(MULTIPLICATIVE_EXPRESSION4, 3, $1, $2, $3); }
	;

additive_expression:
	multiplicative_expression { $$ = alcnary(ADDITIVE_EXPRESSION1, 1, $1); }
	| additive_expression '+' multiplicative_expression { $$ = alcnary(ADDITIVE_EXPRESSION2, 2, $1, $3); }
	| additive_expression '-' multiplicative_expression { $$ = alcnary(ADDITIVE_EXPRESSION3, 2, $1, $3); }
	;

shift_expression:
	additive_expression { $$ = alcnary(SHIFT_EXPRESSION1, 1, $1); }
	| shift_expression SL additive_expression { $$ = alcnary(SHIFT_EXPRESSION2, 3, $1, $2, $3); }
	| shift_expression SR additive_expression { $$ = alcnary(SHIFT_EXPRESSION3, 3, $1, $2, $3); }
	;

relational_expression:
	shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION1, 1, $1); }
	| relational_expression '<' shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION2, 3, $1, $2, $3); }
	| relational_expression '>' shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION3, 3, $1, $2, $3); }
	| relational_expression LTEQ shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION4, 3, $1, $2, $3); }
	| relational_expression GTEQ shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION5, 3, $1, $2, $3); }
	;

equality_expression:
	relational_expression { $$ = alcnary(EQUALITY_EXPRESSION1, 1, $1); }
| equality_expression EQ relational_expression { $$ = alcnary(EQUALITY_EXPRESSION2, 2, $1, $3); }
	| equality_expression NOTEQ relational_expression { $$ = alcnary(EQUALITY_EXPRESSION3, 3, $1, $2, $3); }
	;

and_expression:
	equality_expression { $$ = alcnary(AND_EXPRESSION1, 1, $1); }
	| and_expression '&' equality_expression { $$ = alcnary(AND_EXPRESSION2, 2, $1, $3); }
	;

exclusive_or_expression:
	and_expression { $$ = alcnary(EXCLUSIVE_OR_EXPRESSION1, 1, $1); }
	| exclusive_or_expression '^' and_expression { $$ = alcnary(EXCLUSIVE_OR_EXPRESSION2, 2, $1, $3); }
	;

inclusive_or_expression:
	exclusive_or_expression { $$ = alcnary(INCLUSIVE_OR_EXPRESSION1, 1, $1); }
	| inclusive_or_expression '|' exclusive_or_expression { $$ = alcnary(INCLUSIVE_OR_EXPRESSION2, 2, $1, $3); }
	;

logical_and_expression:
	inclusive_or_expression { $$ = alcnary(LOGICAL_AND_EXPRESSION1, 1, $1); }
	| logical_and_expression ANDAND inclusive_or_expression { $$ = alcnary(LOGICAL_AND_EXPRESSION2, 2, $1, $3); }
	;

logical_or_expression:
	logical_and_expression { $$ = alcnary(LOGICAL_OR_EXPRESSION1, 1, $1); }
	| logical_or_expression OROR logical_and_expression { $$ = alcnary(LOGICAL_OR_EXPRESSION2, 2, $1, $3); }
	;

conditional_expression:
	logical_or_expression { $$ = alcnary(CONDITIONAL_EXPRESSION1, 1, $1); }
	| logical_or_expression  '?' expression ':' assignment_expression { $$ = alcnary(CONDITIONAL_EXPRESSION2, 5, $1, $2, $3, $4, $5); }
	;

assignment_expression:
	conditional_expression { $$ = alcnary(ASSIGNMENT_EXPRESSION1, 1, $1); }
	| logical_or_expression assignment_operator assignment_expression { $$ = alcnary(ASSIGNMENT_EXPRESSION2, 2, $1, $3); }
	;

assignment_operator:
        '='  { $$ = alcnary(ASSIGNMENT_OPERATOR1, 1, $1); }
	| MULEQ  { $$ = alcnary(ASSIGNMENT_OPERATOR2, 1, $1); }
	| DIVEQ { $$ = alcnary(ASSIGNMENT_OPERATOR3, 1, $1); }
	| MODEQ { $$ = alcnary(ASSIGNMENT_OPERATOR4, 1, $1); }
	| ADDEQ { $$ = alcnary(ASSIGNMENT_OPERATOR5, 1, $1); }
	| SUBEQ { $$ = alcnary(ASSIGNMENT_OPERATOR6, 1, $1); }
	| SREQ { $$ = alcnary(ASSIGNMENT_OPERATOR7, 1, $1); }
	| SLEQ { $$ = alcnary(ASSIGNMENT_OPERATOR8, 1, $1); }
	| ANDEQ { $$ = alcnary(ASSIGNMENT_OPERATOR9, 1, $1); }
	| XOREQ { $$ = alcnary(ASSIGNMENT_OPERATOR10, 1, $1); }
	| OREQ { $$ = alcnary(ASSIGNMENT_OPERATOR11, 1, $1); }
	;

expression:
	assignment_expression { $$ = alcnary(EXPRESSION1, 1, $1); }
	| expression ',' assignment_expression { $$ = alcnary(EXPRESSION2, 3, $1, $2, $3); }
	;

constant_expression:
	conditional_expression { $$ = alcnary(CONSTANT_EXPRESSION1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

statement:
	labeled_statement { $$ = alcnary(STATEMENT1, 1, $1); }
	| expression_statement { $$ = alcnary(STATEMENT2, 1, $1); }
	| compound_statement { $$ = alcnary(STATEMENT3, 1, $1); }
	| selection_statement { $$ = alcnary(STATEMENT4, 1, $1); }
	| iteration_statement { $$ = alcnary(STATEMENT5, 1, $1); }
	| jump_statement { $$ = alcnary(STATEMENT6, 1, $1); }
	| declaration_statement { $$ = alcnary(STATEMENT7, 1, $1); }
	;

labeled_statement:
	CASE constant_expression ':' statement { $$ = alcnary(LABELED_STATEMENT2, 4, $1, $2, $3, $4); }
	| DEFAULT ':' statement { $$ = alcnary(LABELED_STATEMENT3, 3, $1, $2, $3); }
	;

expression_statement:
	expression_opt ';' { $$ = alcnary(EXPRESSION_STATEMENT1, 2, $1, $2); }
	;

compound_statement:
	'{' statement_seq_opt '}' { $$ = alcnary(COMPOUND_STATEMENT1, 3, $1, $2, $3); }
	;

statement_seq:
	statement { $$ = alcnary(STATEMENT_SEQ1, 1, $1); }
	| statement_seq statement { $$ = alcnary(STATEMENT_SEQ2, 2, $1, $2); }
	;

selection_statement:
	IF '(' condition ')' statement { $$ = alcnary(SELECTION_STATEMENT1, 5, $1, $2, $3, $4, $5); }
        | IF '(' condition ')' statement ELSE statement { $$ = alcnary(SELECTION_STATEMENT2, 7, $1, $2, $3, $4, $5, $6, $7); }
	| SWITCH '(' condition ')' statement { $$ = alcnary(SELECTION_STATEMENT3, 5, $1, $2, $3, $4, $5); }
	;

condition:
	expression { $$ = alcnary(CONDITION1, 1, $1); }
	| type_specifier_seq declarator '=' assignment_expression { $$ = alcnary(CONDITION2, 3, $1, $2, $3); }
	;

iteration_statement:
	WHILE '(' condition ')' statement { $$ = alcnary(ITERATION_STATEMENT1, 5, $1, $2, $3, $4, $5); }
        | DO statement WHILE '(' expression ')' ';' { $$ = alcnary(ITERATION_STATEMENT2, 7, $1, $2, $3, $4, $5, $6, $7); }
        | FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement { $$ = alcnary(ITERATION_STATEMENT3, 8, $1, $2, $3, $4, $5, $6, $7, $8); }
	;

for_init_statement:
	expression_statement { $$ = alcnary(FOR_INIT_STATEMENT1, 1, $1); }
	| simple_declaration { $$ = alcnary(FOR_INIT_STATEMENT2, 1, $1); }
	;

jump_statement:
	BREAK ';' { $$ = alcnary(JUMP_STATEMENT1, 2, $1, $2); }
	| CONTINUE ';' { $$ = alcnary(JUMP_STATEMENT2, 2, $1, $2); }
	| RETURN expression_opt ';' { $$ = alcnary(JUMP_STATEMENT3, 3, $1, $2, $3); }
	;

declaration_statement:
	block_declaration { $$ = alcnary(DECLARATION_STATEMENT1, 1, $1); }
	;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

declaration_seq:
	declaration { $$ = alcnary(DECLARATION_SEQ1, 1, $1); }
        | declaration_seq declaration { $$ = alcnary(DECLARATION_SEQ2, 2, $1, $2); }
	;

declaration:
        block_declaration { $$ = alcnary(DECLARATION1, 1, $1); }
	| function_definition { $$ = alcnary(DECLARATION2, 1, $1); }
	;

block_declaration:
	simple_declaration { $$ = alcnary(BLOCK_DECLARATION1, 1, $1); }
	;

simple_declaration:
	  decl_specifier_seq init_declarator_list ';' { $$ = alcnary(SIMPLE_DECLARATION1, 3, $1, $2, $3); }
	|  decl_specifier_seq ';' { $$ = alcnary(SIMPLE_DECLARATION2, 2, $1, $2); }
	;

decl_specifier:
	type_specifier  { $$ = alcnary(DECL_SPECIFIER1, 1, $1); }
	;

decl_specifier_seq:
	  decl_specifier { $$ = alcnary(DECL_SPECIFIER_SEQ1, 1, $1); }
	| decl_specifier_seq decl_specifier { $$ = alcnary(DECL_SPECIFIER_SEQ2, 2, $1, $2); }
	;

type_specifier:
	simple_type_specifier { $$ = alcnary(TYPE_SPECIFIER1, 1, $1); }
	| class_specifier { $$ = alcnary(TYPE_SPECIFIER2, 1, $1); }
	| elaborated_type_specifier { $$ = alcnary(TYPE_SPECIFIER3, 1, $1); }
	;

simple_type_specifier:
	  CLASS_NAME { $$ = alcnary(SIMPLE_TYPE_SPECIFIER1, 1, $1); }
	| nested_name_specifier CLASS_NAME { $$ = alcnary(SIMPLE_TYPE_SPECIFIER2, 2, $1, $2); }
	| CHAR { $$ = alcnary(SIMPLE_TYPE_SPECIFIER3, 1, $1); }
	| BOOL { $$ = alcnary(SIMPLE_TYPE_SPECIFIER4, 1, $1); }
	| SHORT { $$ = alcnary(SIMPLE_TYPE_SPECIFIER5, 1, $1); }
	| INT { $$ = alcnary(SIMPLE_TYPE_SPECIFIER6, 1, $1); }
	| LONG { $$ = alcnary(SIMPLE_TYPE_SPECIFIER7, 1, $1); }
	| SIGNED { $$ = alcnary(SIMPLE_TYPE_SPECIFIER8, 1, $1); }
	| UNSIGNED  { $$ = alcnary(SIMPLE_TYPE_SPECIFIER9, 1, $1); }
	| FLOAT { $$ = alcnary(SIMPLE_TYPE_SPECIFIER10, 1, $1); }
	| DOUBLE { $$ = alcnary(SIMPLE_TYPE_SPECIFIER11, 1, $1); }
	| VOID { $$ = alcnary(SIMPLE_TYPE_SPECIFIER12, 1, $1); }
	;



elaborated_type_specifier:
	  class_key COLONCOLON nested_name_specifier IDENTIFIER { $$ = alcnary(ELABORATED_TYPE_SPECIFIER1, 4, $1, $2, $3, $4); }
	| class_key COLONCOLON IDENTIFIER { $$ = alcnary(ELABORATED_TYPE_SPECIFIER2, 3, $1, $2, $3); }
	;


/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

init_declarator_list:
	init_declarator { $$ = alcnary(INIT_DECLARATOR_LIST1, 1, $1); }
	| init_declarator_list ',' init_declarator { $$ = alcnary(INIT_DECLARATOR_LIST2, 2, $1, $3); }
	;

init_declarator:
	declarator initializer_opt { $$ = alcnary(INIT_DECLARATOR1, 2, $1, $2); }
	;

declarator:
	direct_declarator { $$ = alcnary(DECLARATOR1, 1, $1); }
	| ptr_operator declarator { $$ = alcnary(DECLARATOR2, 2, $1, $2); }
	;

direct_declarator:
	  declarator_id { $$ = alcnary(DIRECT_DECLARATOR1, 1, $1); }
	| direct_declarator '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR5, 4, $1, $2, $3, $4); }
	| CLASS_NAME '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR6, 4, $1, $2, $3, $4); }
        | CLASS_NAME COLONCOLON declarator_id '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR7, 6, $1, $2, $3, $4, $5, $6); }
	| CLASS_NAME COLONCOLON CLASS_NAME '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR8, 6, $1, $2, $3, $4, $5, $6); }
	| direct_declarator '[' constant_expression_opt ']' { $$ = alcnary(DIRECT_DECLARATOR9, 4, $1, $2, $3, $4); }
	| '(' declarator ')' { $$ = alcnary(DIRECT_DECLARATOR10, 3, $1, $2, $3); }
	;

ptr_operator:
	'*' { $$ = alcnary(PTR_OPERATOR1, 1, $1); }
	| '&' { $$ = alcnary(PTR_OPERATOR2, 1, $1); }
	| nested_name_specifier '*' { $$ = alcnary(PTR_OPERATOR4, 2, $1, $2); }
	| COLONCOLON nested_name_specifier '*' { $$ = alcnary(PTR_OPERATOR6, 3, $1, $2, $3); }
	;

declarator_id:
	  id_expression { $$ = alcnary(DECLARATOR_ID1, 1, $1); }
	| COLONCOLON id_expression { $$ = alcnary(DECLARATOR_ID2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier CLASS_NAME { $$ = alcnary(DECLARATOR_ID3, 3, $1, $2, $3); }
	| COLONCOLON CLASS_NAME { $$ = alcnary(DECLARATOR_ID4, 2, $1, $2); }
	;

type_id:
	type_specifier_seq abstract_declarator_opt { $$ = alcnary(TYPE_ID1, 2, $1, $2); }
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt { $$ = alcnary(TYPE_SPECIFIER_SEQ1, 2, $1, $2); }
	;

abstract_declarator:
	ptr_operator abstract_declarator_opt { $$ = alcnary(ABSTRACT_DECLARATOR1, 2, $1, $2); }
        | direct_abstract_declarator { $$ = alcnary(ABSTRACT_DECLARATOR2, 1, $1); }
	;

direct_abstract_declarator:
direct_abstract_declarator '(' parameter_declaration_clause ')'{ $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR1, 4, $1, $2, $3, $4); }
        | '(' parameter_declaration_clause ')' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR2, 3, $1, $2, $3); }
        | direct_abstract_declarator '[' constant_expression_opt ']'{ $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR3, 4, $1, $2, $3, $4); }
        | '[' constant_expression_opt ']' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR4, 3, $1, $2, $3); }
       	| '(' abstract_declarator ')' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR6, 3, $1, $2, $3); }
	;

parameter_declaration_clause:
        parameter_declaration_list { $$ = alcnary(PARAMETER_DECLARATION_CLAUSE1, 1, $1); }
        | { $$ = NULL; }
	;

parameter_declaration_list:
	parameter_declaration { $$ = alcnary(PARAMETER_DECLARATION_LIST1, 1, $1); }
	| parameter_declaration_list ',' parameter_declaration { $$ = alcnary(PARAMETER_DECLARATION_LIST2, 3, $1, $2, $3); }
	;

parameter_declaration:
	decl_specifier_seq declarator  { $$ = alcnary(PARAMETER_DECLARATION1, 2, $1, $2); }
	| decl_specifier_seq declarator '=' assignment_expression { $$ = alcnary(PARAMETER_DECLARATION2, 3, $1, $2, $3); }
	| decl_specifier_seq abstract_declarator_opt { $$ = alcnary(PARAMETER_DECLARATION3, 2, $1, $2); }
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression { $$ = alcnary(PARAMETER_DECLARATION4, 4, $1, $2, $3, $4); }
	;

function_definition:
	declarator ctor_initializer_opt function_body { $$ = alcnary(FUNCTION_DEFINITION1, 3, $1, $2, $3); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body { $$ = alcnary(FUNCTION_DEFINITION2, 4, $1, $2, $3, $4); }
	;

function_body:
	compound_statement { $$ = alcnary(FUNCTION_BODY1, 1, $1); }
	;

initializer:
	'=' initializer_clause { $$ = alcnary(INITIALIZER1, 2, $1, $2); }
	| '(' expression_list ')' { $$ = alcnary(INITIALIZER2, 3, $1, $2, $3); }
	;

initializer_clause:
	assignment_expression { $$ = alcnary(INITIALIZER_CLAUSE1, 1, $1); }
	| '{' initializer_list COMMA_opt '}' { $$ = alcnary(INITIALIZER_CLAUSE2, 4, $1, $2, $3, $4); }
	| '{' '}' { $$ = alcnary(INITIALIZER_CLAUSE3, 2, $1, $2); }
	;

initializer_list:
	initializer_clause { $$ = alcnary(INITIALIZER_LIST1, 1, $1); }
	| initializer_list ',' initializer_clause { $$ = alcnary(INITIALIZER_LIST2, 3, $1, $2, $3); }
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

class_specifier:
	class_head '{' member_specification_opt '}' { $$ = alcnary(CLASS_SPECIFIER1, 4, $1, $2, $3, $4); }
	;

class_head:
	class_key IDENTIFIER  { $$ = alcnary(CLASS_HEAD1, 2, $1, $2); } 
	| class_key nested_name_specifier IDENTIFIER { $$ = alcnary(CLASS_HEAD3, 3, $1, $2, $3); }
	;

class_key:
	CLASS { $$ = alcnary(CLASS_KEY1, 1, $1); }
	| STRUCT { $$ = alcnary(CLASS_KEY1, 1, $1); }
	;

member_specification:
	member_declaration member_specification_opt { $$ = alcnary(MEMBER_SPECIFICATION1, 2, $1, $2); }
	| access_specifier ':' member_specification_opt { $$ = alcnary(MEMBER_SPECIFICATION2, 3, $1, $2, $3); }
	;

member_declaration:
	  decl_specifier_seq member_declarator_list ';' { $$ = alcnary(MEMBER_DECLARATION1, 3, $1, $2, $3); }
	| decl_specifier_seq ';' { $$ = alcnary(MEMBER_DECLARATION2, 2, $1, $2); }
	| member_declarator_list ';' { $$ = alcnary(MEMBER_DECLARATION3, 2, $1, $2); }
	| ';'  { $$ = alcnary(MEMBER_DECLARATION4, 1, $1); }
	| function_definition SEMICOLON_opt { $$ = alcnary(MEMBER_DECLARATION5, 2, $1, $2); }
	| qualified_id ';' { $$ = alcnary(MEMBER_DECLARATION6, 2, $1, $2); }
	;

member_declarator_list:
	member_declarator { $$ = alcnary(MEMBER_DECLARATOR_LIST1, 1, $1); }
	| member_declarator_list ',' member_declarator { $$ = alcnary(MEMBER_DECLARATOR_LIST2, 3, $1, $2, $3); }
	;

member_declarator:
	  declarator { $$ = alcnary(MEMBER_DECLARATOR1, 1, $1); }
	| declarator constant_initializer { $$ = alcnary(MEMBER_DECLARATOR3, 2, $1, $2); }
	| IDENTIFIER ':' constant_expression { $$ = alcnary(MEMBER_DECLARATOR4, 3, $1, $2, $3); }
	;

/*
 * This rule need a hack for working around the ``= 0'' pure specifier.
 * 0 is returned as an ``INTEGER'' by the lexical analyzer but in this
 * context is different.
 */

constant_initializer:
	'=' constant_expression { $$ = alcnary(CONSTANT_INITIALIZER1, 2, $1, $2); }
	;

access_specifier:
	PRIVATE { $$ = alcnary(ACCESS_SPECIFIER1, 1, $1); }
	| PROTECTED { $$ = alcnary(ACCESS_SPECIFIER2, 1, $1); }
	| PUBLIC  { $$ = alcnary(ACCESS_SPECIFIER3, 1, $1); }
	;
/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/


ctor_initializer:
	':' mem_initializer_list { $$ = alcnary(CTOR_INITIALIZER1, 2, $1, $2); }
	;

mem_initializer_list:
	mem_initializer { $$ = alcnary(MEM_INITIALIZER_LIST1, 1, $1); }
	| mem_initializer ',' mem_initializer_list { $$ = alcnary(MEM_INITIALIZER_LIST2, 3, $1, $2, $3); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')' { $$ = alcnary(MEM_INITIALIZER1, 4, $1, $2, $3, $4); }
	;

mem_initializer_id:
         COLONCOLON nested_name_specifier CLASS_NAME { $$ = alcnary(MEM_INITIALIZER_ID1, 3, $1, $2, $3); }
	| COLONCOLON CLASS_NAME { $$ = alcnary(MEM_INITIALIZER_ID2, 2, $1, $2); }
	| nested_name_specifier CLASS_NAME { $$ = alcnary(MEM_INITIALIZER_ID3, 2, $1, $2); }
	| CLASS_NAME { $$ = alcnary(MEM_INITIALIZER_ID4, 1, $1); }
	| IDENTIFIER { $$ = alcnary(MEM_INITIALIZER_ID5, 1, $1); }
	;
/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */ { $$ = alcnary(DECLARATION_SEQ_OPT1, 0); }
	| declaration_seq { $$ = alcnary(DECLARATION_SEQ_OPT2, 1, $1); }
	;

expression_list_opt:
	/* epsilon */ { $$ = NULL; }
	| expression_list { $$ = alcnary(EXPRESSION_LIST_OPT2, 1, $1); }
	;


new_placement_opt:
	/* epsilon */ { $$ = NULL; }
	| new_placement { $$ = alcnary(NEW_PLACEMENT_OPT2, 1, $1); }
	;

new_initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| new_initializer { $$ = alcnary(NEW_INITIALIZER_OPT2, 1, $1); }
	;

new_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| new_declarator { $$ = alcnary(NEW_DECLARATOR_OPT2, 1, $1); }
	;

expression_opt:
	/* epsilon */ { $$ = NULL; }
	| expression { $$ = alcnary(EXPRESSION_OPT2, 1, $1); }
	;

statement_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| statement_seq { $$ = alcnary(STATEMENT_SEQ_OPT2, 1, $1); }
	;

condition_opt:
	/* epsilon */ { $$ = NULL; }
	| condition { $$ = alcnary(CONDITION_OPT2, 1, $1); }
	;

initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| initializer { $$ = alcnary(INITIALIZER_OPT2, 1, $1); }
	;

constant_expression_opt:
	/* epsilon */ { $$ = NULL; }
	| constant_expression  { $$ = alcnary(CONSTANT_EXPRESSION_OPT2, 1, $1); }
	;

abstract_declarator_opt:
	/* epsilon */ { $$ = NULL; }
| abstract_declarator  { $$ = alcnary(ABSTRACT_DECLARATOR_OPT2, 1, $1); }
	;

type_specifier_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| type_specifier_seq  { $$ = alcnary(TYPE_SPECIFIER_OPT2, 1, $1); }
	;

ctor_initializer_opt:
	/* epsilon */ { $$ = alcnary(CTOR_INITIALIZER_OPT1, 0); }
	| ctor_initializer { $$ = alcnary(CTOR_INITIALIZER_OPT2, 1, $1); }
	;

COMMA_opt:
	/* epsilon */ { $$ = NULL; }
	| ',' { $$ = alcnary(COMMA_OPT2, 1, $1); }
	;

member_specification_opt:
	/* epsilon */ { $$ = NULL; }
	| member_specification { $$ = alcnary(MEMBER_SPECIFICATION_OPT2, 1, $1); }
	;

SEMICOLON_opt:
	/* epsilon */ { $$ = NULL; }
	| ';' { $$ = alcnary(SEMICOLON_OPT2, 1, $1); }
	;


%%

static void
yyerror(char *s)
{
	fprintf(stderr, "%d: %s\n", lineno, s);
	exit(2);
}

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

#include "tree.h"
#include "120lex.h"
#include "prodrules.h"

extern int lineno;
extern char *yytext;
int yydebug=0;

static void yyerror(char *s);
 struct node *yyroot;
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
%type <np> class_name
%type <np> identifier literal integer_literal character_literal floating_literal
%type <np> string_literal boolean_literal primary_expression unqualified_id
%type <np> qualified_id nested_name_specifier postfix_expression expression_list unary_expression
%type <np> unary_operator new_expression new_placement new_type_id new_declarator 
%type <np> direct_new_declarator new_initializer delete_expression cast_expression 
%type <np> pm_expression multiplicative_expression additive_expression shift_expression
%type <np> relational_expression equality_expression and_expression exclusive_or_expression
%type <np> inclusive_or_expression logical_and_expression logical_or_expression 
%type <np> conditional_expression assignment_expression assignment_operator expression
%type <np> constant_expression statement labeled_statement compound_statement
%type <np> statement_seq selection_statement condition iteration_statement for_init_statement
%type <np> jump_statement declaration_statement declaration_seq declaration block_declaration
%type <np> simple_declaration decl_specifier decl_specifier_seq
%type <np> type_specifier simple_type_specifier type_name 
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

program:
        declaration_seq_opt {yyroot = $1; printf("assigning root \n"); treeprint(yyroot);}
        ;

/*----------------------------------------------------------------------
 * Context-dependent identifiers.
 *----------------------------------------------------------------------*/

class_name:
	/* identifier */
	CLASS_NAME { $$ = $1; }
	;


/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/

identifier:
IDENTIFIER { $$ = $1; }

	;

literal:
	integer_literal { $$ = $1; }
	| character_literal { $$ = $1; }
	| floating_literal { $$ = $1; }
	| string_literal { $$ = $1; }
	| boolean_literal { $$ = $1; }
	;

integer_literal:
	INTEGER { $$ = $1; }
	;

character_literal:
	CHARACTER { $$ = $1; }
	;

floating_literal:
	FLOATING { $$ = $1; }
	;

string_literal:
	STRING { $$ = $1; }
	;

boolean_literal:
	TRUE { $$ = $1; }
	| FALSE { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Translation unit.
 *----------------------------------------------------------------------*/



/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal { $$ = $1; }
        | '(' expression ')' { $$ = alcnary(PRIMARY_EXPRESSION3, 3, $1, $2, $3); }
	| id_expression { $$ = $1; }
	;

id_expression:
	unqualified_id { $$ = $1; }
	| qualified_id { $$ = $1; }
	;

unqualified_id:
	identifier { $$ = $1; }
	;

qualified_id:
	nested_name_specifier unqualified_id { $$ = alcnary(QUALIFIED_ID1, 2, $1, $2); }
	;

nested_name_specifier:
        class_name COLONCOLON nested_name_specifier
	| class_name COLONCOLON { $$ = alcnary(NESTED_NAME_SPECIFIER2, 2, $1, $2); }
	;

postfix_expression:
	primary_expression { $$ = $1; }
        | postfix_expression '[' expression ']' { $$ = alcnary(POSTFIX_EXPRESSION2, 4, $1, $2, $3, $4); }
	| postfix_expression '(' expression_list_opt ')' { $$ = alcnary(POSTFIX_EXPRESSION3, 4, $1, $2, $3, $4); }
        | simple_type_specifier '(' expression_list_opt ')' { $$ = alcnary(POSTFIX_EXPRESSION4, 4, $1, $2, $3, $4); }
	| postfix_expression '.' id_expression { $$ = alcnary(POSTFIX_EXPRESSION7, 3, $1, $2, $3); }
	| postfix_expression ARROW id_expression { $$ = alcnary(POSTFIX_EXPRESSION11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS { $$ = alcnary(POSTFIX_EXPRESSION12, 2, $1, $2); }
	| postfix_expression MINUSMINUS { $$ = alcnary(POSTFIX_EXPRESSION13, 2, $1, $2); }
	;

expression_list:
	assignment_expression { $$ = $1; }
	| expression_list ',' assignment_expression { $$ = alcnary(EXPRESSION_LIST2, 3, $1, $2, $3); }
	;

unary_expression:
	postfix_expression { $$ = $1; }
	| PLUSPLUS cast_expression { $$ = alcnary(UNARY_EXPRESSION2, 2, $1, $2); }
	| MINUSMINUS cast_expression { $$ = alcnary(UNARY_EXPRESSION3, 2, $1, $2); }
	| '*' cast_expression { $$ = alcnary(UNARY_EXPRESSION4, 2, $1, $2); }
	| '&' cast_expression { $$ = alcnary(UNARY_EXPRESSION5, 2, $1, $2); }
	| unary_operator cast_expression { $$ = alcnary(UNARY_EXPRESSION6, 2, $1, $2); }
	| SIZEOF unary_expression { $$ = alcnary(UNARY_EXPRESSION7, 2, $1, $2); }
	| SIZEOF '(' type_id ')' { $$ = alcnary(UNARY_EXPRESSION8, 4, $1, $2, $3, $4); }
	| new_expression { $$ = $1; }
	| delete_expression { $$ = $1; }
	;

unary_operator:
	  '+' { $$ = $1; }
	| '-' { $$ = $1; }
	| '!' { $$ = $1; }
	| '~' { $$ = $1; }
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
	| direct_new_declarator { $$ = $1; }
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

cast_expression:
	unary_expression { $$ = $1; }
	;

pm_expression:
	cast_expression { $$ = $1; }
	| pm_expression DOTSTAR cast_expression { $$ = alcnary(PM_EXPRESSION2, 3, $1, $2, $3); }
	| pm_expression ARROWSTAR cast_expression { $$ = alcnary(PM_EXPRESSION3, 3, $1, $2, $3); }
	;

multiplicative_expression:
	pm_expression { $$ = $1; }
	| multiplicative_expression '*' pm_expression { $$ = alcnary(MULTIPLICATIVE_EXPRESSION2, 3, $1, $2, $3); }
	| multiplicative_expression '/' pm_expression { $$ = alcnary(MULTIPLICATIVE_EXPRESSION3, 3, $1, $2, $3); }
	| multiplicative_expression '%' pm_expression { $$ = alcnary(MULTIPLICATIVE_EXPRESSION4, 3, $1, $2, $3); }
	;

additive_expression:
	multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { $$ = alcnary(ADDITIVE_EXPRESSION2, 3, $1, $2, $3); }
	| additive_expression '-' multiplicative_expression { $$ = alcnary(ADDITIVE_EXPRESSION3, 3, $1, $2, $3); }
	;

shift_expression:
	additive_expression { $$ = $1; }
	| shift_expression SL additive_expression { $$ = alcnary(SHIFT_EXPRESSION2, 3, $1, $2, $3); }
	| shift_expression SR additive_expression { $$ = alcnary(SHIFT_EXPRESSION3, 3, $1, $2, $3); }
	;

relational_expression:
	shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION2, 3, $1, $2, $3); }
	| relational_expression '>' shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION3, 3, $1, $2, $3); }
	| relational_expression LTEQ shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION4, 3, $1, $2, $3); }
	| relational_expression GTEQ shift_expression { $$ = alcnary(RELATIONAL_EXPRESSION5, 3, $1, $2, $3); }
	;

equality_expression:
	relational_expression { $$ = $1; }
	| equality_expression EQ relational_expression { $$ = alcnary(EQUALITY_EXPRESSION2, 3, $1, $2, $3); }
	| equality_expression NOTEQ relational_expression { $$ = alcnary(EQUALITY_EXPRESSION3, 3, $1, $2, $3); }
	;

and_expression:
	equality_expression { $$ = $1; }
	| and_expression '&' equality_expression { $$ = alcnary(AND_EXPRESSION2, 3, $1, $2, $3); }
	;

exclusive_or_expression:
	and_expression { $$ = $1; }
	| exclusive_or_expression '^' and_expression { $$ = alcnary(EXCLUSIVE_OR_EXPRESSION2, 3, $1, $2, $3); }
	;

inclusive_or_expression:
	exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression { $$ = alcnary(INCLUSIVE_OR_EXPRESSION2, 3, $1, $2, $3); }
	;

logical_and_expression:
	inclusive_or_expression { $$ = $1; }
	| logical_and_expression ANDAND inclusive_or_expression { $$ = alcnary(LOGICAL_AND_EXPRESSION2, 3, $1, $2, $3); }
	;

logical_or_expression:
	logical_and_expression { $$ = $1; }
	| logical_or_expression OROR logical_and_expression { $$ = alcnary(LOGICAL_OR_EXPRESSION2, 3, $1, $2, $3); }
	;

conditional_expression:
	logical_or_expression { $$ = $1; }
	| logical_or_expression  '?' expression ':' assignment_expression { $$ = alcnary(CONDITIONAL_EXPRESSION2, 5, $1, $2, $3, $4, $5); }
	;

assignment_expression:
	conditional_expression { $$ = $1; }
	| logical_or_expression assignment_operator assignment_expression { $$ = alcnary(ASSIGNMENT_EXPRESSION2, 3, $1, $2, $3); }
	;

assignment_operator:
	'=' { $$ = $1; }
	| MULEQ { $$ = $1; }
	| DIVEQ { $$ = $1; }
	| MODEQ { $$ = $1; }
	| ADDEQ { $$ = $1; }
	| SUBEQ { $$ = $1; }
	| SREQ { $$ = $1; }
	| SLEQ { $$ = $1; }
	| ANDEQ { $$ = $1; }
	| XOREQ { $$ = $1; }
	| OREQ { $$ = $1; }
	;

expression:
	assignment_expression { $$ = $1; }
	| expression ',' assignment_expression { $$ = alcnary(EXPRESSION2, 3, $1, $2, $3); }
	;

constant_expression:
	conditional_expression { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

statement:
	labeled_statement { $$ = $1; }
	| expression_statement { $$ = $1; }
	| compound_statement { $$ = $1; }
	| selection_statement { $$ = $1; }
	| iteration_statement { $$ = $1; }
	| jump_statement { $$ = $1; }
	| declaration_statement { $$ = $1; }
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
	statement { $$ = $1; }
	| statement_seq statement { $$ = alcnary(STATEMENT_SEQ1, 2, $1, $2); }
	;

selection_statement:
	IF '(' condition ')' statement { $$ = alcnary(SELECTION_STATEMENT1, 5, $1, $2, $3, $4, $5); }
        | IF '(' condition ')' statement ELSE statement { $$ = alcnary(SELECTION_STATEMENT2, 7, $1, $2, $3, $4, $5, $6, $7); }
	| SWITCH '(' condition ')' statement { $$ = alcnary(SELECTION_STATEMENT3, 5, $1, $2, $3, $4, $5); }
	;

condition:
	expression { $$ = $1; }
	| type_specifier_seq declarator '=' assignment_expression { $$ = alcnary(CONDITION2, 3, $1, $2, $3); }
	;

iteration_statement:
	WHILE '(' condition ')' statement { $$ = alcnary(ITERATION_STATEMENT1, 5, $1, $2, $3, $4, $5); }
        | DO statement WHILE '(' expression ')' ';' { $$ = alcnary(ITERATION_STATEMENT2, 7, $1, $2, $3, $4, $5, $6, $7); }
        | FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement { $$ = alcnary(ITERATION_STATEMENT3, 8, $1, $2, $3, $4, $5, $6, $7, $8); }
	;

for_init_statement:
	expression_statement { $$ = $1; }
	| simple_declaration { $$ = $1; }
	;

jump_statement:
	BREAK ';' { $$ = alcnary(JUMP_STATEMENT1, 2, $1, $2); }
	| CONTINUE ';' { $$ = alcnary(JUMP_STATEMENT2, 2, $1, $2); }
	| RETURN expression_opt ';' { $$ = alcnary(JUMP_STATEMENT3, 3, $1, $2, $3); }
	;

declaration_statement:
	block_declaration { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

declaration_seq:
	declaration { $$ = $1; }
	| declaration_seq declaration { $$ = alcnary(DECLARATION_SEQ2, 2, $1, $2); }
	;

declaration:
	block_declaration { $$ = $1; }
	| function_definition { $$ = $1; }
	;

block_declaration:
	simple_declaration { $$ = $1; }
	;

simple_declaration:
	  decl_specifier_seq init_declarator_list ';' { $$ = alcnary(SIMPLE_DECLARATION1, 3, $1, $2, $3); }
	|  decl_specifier_seq ';' { $$ = alcnary(SIMPLE_DECLARATION2, 2, $1, $2); }
	;

decl_specifier:
	type_specifier { $$ = $1; }
	;

decl_specifier_seq:
	  decl_specifier { $$ = $1; }
	| decl_specifier_seq decl_specifier { $$ = alcnary(DECL_SPECIFIER_SEQ2, 2, $1, $2); }
	;

/*
storage_class_specifier:
	AUTO { $$ = $1; }
	| REGISTER { $$ = $1; }
	| STATIC { $$ = $1; }
	| EXTERN { $$ = $1; }
	| MUTABLE { $$ = $1; }
	;


function_specifier:
	INLINE { $$ = $1; }
	| VIRTUAL { $$ = $1; }
	| EXPLICIT { $$ = $1; }
	;
*/

type_specifier:
	simple_type_specifier { $$ = $1; }
	| class_specifier { $$ = $1; }
	| elaborated_type_specifier { $$ = $1; }
	;

simple_type_specifier:
	  type_name { $$ = $1; }
	| nested_name_specifier type_name { $$ = alcnary(SIMPLE_TYPE_SPECIFIER2, 2, $1, $2); }
	| CHAR { $$ = $1; }
	| BOOL { $$ = $1; }
	| SHORT { $$ = $1; }
	| INT { $$ = $1; }
	| LONG { $$ = $1; }
	| SIGNED { $$ = $1; }
	| UNSIGNED { $$ = $1; }
	| FLOAT { $$ = $1; }
	| DOUBLE { $$ = $1; }
	| VOID { $$ = $1; }
	;

type_name:
	class_name { $$ = $1; }
	;

elaborated_type_specifier:
	  class_key COLONCOLON nested_name_specifier identifier { $$ = alcnary(ELABORATED_TYPE_SPECIFIER1, 4, $1, $2, $3, $4); }
	| class_key COLONCOLON identifier { $$ = alcnary(ELABORATED_TYPE_SPECIFIER2, 3, $1, $2, $3); }
	;


/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

init_declarator_list:
	init_declarator { $$ = $1; }
	| init_declarator_list ',' init_declarator { $$ = alcnary(INIT_DECLARATOR_LIST2, 3, $1, $2, $3); }
	;

init_declarator:
	declarator initializer_opt { $$ = alcnary(INIT_DECLARATOR1, 2, $1, $2); }
	;

declarator:
	direct_declarator { $$ = $1; }
	| ptr_operator declarator { $$ = alcnary(DECLARATOR2, 2, $1, $2); }
	;

direct_declarator:
	  declarator_id { $$ = $1; }
	| direct_declarator '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR5, 4, $1, $2, $3, $4); }
	| CLASS_NAME '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR6, 4, $1, $2, $3, $4); }
        | CLASS_NAME COLONCOLON declarator_id '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR7, 6, $1, $2, $3, $4, $5, $6); }
	| CLASS_NAME COLONCOLON CLASS_NAME '('parameter_declaration_clause ')' { $$ = alcnary(DIRECT_DECLARATOR8, 6, $1, $2, $3, $4, $5, $6); }
	| direct_declarator '[' constant_expression_opt ']' { $$ = alcnary(DIRECT_DECLARATOR9, 4, $1, $2, $3, $4); }
	| '(' declarator ')' { $$ = alcnary(DIRECT_DECLARATOR10, 3, $1, $2, $3); }
	;

ptr_operator:
	'*' { $$ = $1; }
	| '&' { $$ = $1; }
	| nested_name_specifier '*' { $$ = alcnary(PTR_OPERATOR4, 2, $1, $2); }
	| COLONCOLON nested_name_specifier '*' { $$ = alcnary(PTR_OPERATOR6, 3, $1, $2, $3); }
	;

declarator_id:
	  id_expression { $$ = $1; }
	| COLONCOLON id_expression { $$ = alcnary(DECLARATOR_ID2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier type_name { $$ = alcnary(DECLARATOR_ID3, 3, $1, $2, $3); }
	| COLONCOLON type_name { $$ = alcnary(DECLARATOR_ID4, 2, $1, $2); }
	;

type_id:
	type_specifier_seq abstract_declarator_opt { $$ = alcnary(TYPE_ID1, 2, $1, $2); }
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt { $$ = alcnary(TYPE_SPECIFIER_SEQ1, 2, $1, $2); }
	;

abstract_declarator:
	ptr_operator abstract_declarator_opt { $$ = alcnary(ABSTRACT_DECLARATOR1, 2, $1, $2); }
        | direct_abstract_declarator { $$ = $1; }
	;

direct_abstract_declarator:
direct_abstract_declarator '(' parameter_declaration_clause ')'{ $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR1, 4, $1, $2, $3, $4); }
        | '(' parameter_declaration_clause ')' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR2, 3, $1, $2, $3); }
        | direct_abstract_declarator '[' constant_expression_opt ']'{ $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR3, 4, $1, $2, $3, $4); }
        | '[' constant_expression_opt ']' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR4, 3, $1, $2, $3); }
       	| '(' abstract_declarator ')' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR6, 3, $1, $2, $3); }
	;

parameter_declaration_clause:
        parameter_declaration_list { $$ = $1; }
        | { $$ = NULL; }
	;

parameter_declaration_list:
	parameter_declaration { $$ = $1; }
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
	compound_statement { $$ = $1; }
	;

initializer:
	'=' initializer_clause { $$ = alcnary(INITIALIZER1, 2, $1, $2); }
	| '(' expression_list ')' { $$ = alcnary(INITIALIZER2, 3, $1, $2, $3); }
	;

initializer_clause:
	assignment_expression { $$ = $1; }
	| '{' initializer_list COMMA_opt '}' { $$ = alcnary(INITIALIZER_CLAUSE2, 4, $1, $2, $3, $4); }
	| '{' '}' { $$ = alcnary(INITIALIZER_CLAUSE3, 2, $1, $2); }
	;

initializer_list:
	initializer_clause { $$ = $1; }
	| initializer_list ',' initializer_clause { $$ = alcnary(INITIALIZER_LIST2, 3, $1, $2, $3); }
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

class_specifier:
	class_head '{' member_specification_opt '}' { $$ = alcnary(CLASS_SPECIFIER1, 4, $1, $2, $3, $4); }
	;

class_head:
	class_key identifier  { $$ = alcnary(CLASS_HEAD1, 2, $1, $2); } 
	| class_key nested_name_specifier identifier { $$ = alcnary(CLASS_HEAD3, 3, $1, $2, $3); }
	;

class_key:
	CLASS { $$ = $1; }
	| STRUCT { $$ = $1; }
	;

member_specification:
	member_declaration member_specification_opt { $$ = alcnary(MEMBER_SPECIFICATION1, 2, $1, $2); }
	| access_specifier ':' member_specification_opt { $$ = alcnary(MEMBER_SPECIFICATION2, 3, $1, $2, $3); }
	;

member_declaration:
	  decl_specifier_seq member_declarator_list ';' { $$ = alcnary(MEMBER_DECLARATION1, 3, $1, $2, $3); }
	| decl_specifier_seq ';' { $$ = alcnary(MEMBER_DECLARATION2, 2, $1, $2); }
	| member_declarator_list ';' { $$ = alcnary(MEMBER_DECLARATION3, 2, $1, $2); }
	| ';' { $$ = $1; }
	| function_definition SEMICOLON_opt { $$ = alcnary(MEMBER_DECLARATION5, 2, $1, $2); }
	| qualified_id ';' { $$ = alcnary(MEMBER_DECLARATION6, 2, $1, $2); }
	;

member_declarator_list:
	member_declarator { $$ = $1; }
	| member_declarator_list ',' member_declarator { $$ = alcnary(MEMBER_DECLARATOR_LIST2, 3, $1, $2, $3); }
	;

member_declarator:
	  declarator { $$ = $1; }
	| declarator constant_initializer { $$ = alcnary(MEMBER_DECLARATOR3, 2, $1, $2); }
	| identifier ':' constant_expression { $$ = alcnary(MEMBER_DECLARATOR4, 3, $1, $2, $3); }
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
	PRIVATE { $$ = $1; }
	| PROTECTED { $$ = $1; }
	| PUBLIC { $$ = $1; }
	;
/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/


ctor_initializer:
	':' mem_initializer_list { $$ = alcnary(CTOR_INITIALIZER1, 2, $1, $2); }
	;

mem_initializer_list:
	mem_initializer { $$ = $1; }
	| mem_initializer ',' mem_initializer_list { $$ = alcnary(MEM_INITIALIZER_LIST2, 3, $1, $2, $3); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')' { $$ = alcnary(MEM_INITIALIZER1, 4, $1, $2, $3, $4); }
	;

mem_initializer_id:
         COLONCOLON nested_name_specifier class_name { $$ = alcnary(MEM_INITIALIZER_ID1, 3, $1, $2, $3); }
	| COLONCOLON class_name { $$ = alcnary(MEM_INITIALIZER_ID2, 2, $1, $2); }
	| nested_name_specifier class_name { $$ = alcnary(MEM_INITIALIZER_ID3, 2, $1, $2); }
	| class_name { $$ = $1; }
	| identifier { $$ = $1; }
	;
/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| declaration_seq { $$ = $1; }
	;

expression_list_opt:
	/* epsilon */ { $$ = NULL; }
	| expression_list { $$ = $1; }
	;


new_placement_opt:
	/* epsilon */ { $$ = NULL; }
	| new_placement { $$ = $1; }
	;

new_initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| new_initializer { $$ = $1; }
	;

new_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| new_declarator { $$ = $1; }
	;

expression_opt:
	/* epsilon */ { $$ = NULL; }
	| expression { $$ = $1; }
	;

statement_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| statement_seq { $$ = $1; }
	;

condition_opt:
	/* epsilon */ { $$ = NULL; }
	| condition { $$ = $1; }
	;

initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| initializer { $$ = $1; }
	;

constant_expression_opt:
	/* epsilon */ { $$ = NULL; }
	| constant_expression { $$ = $1; }
	;

abstract_declarator_opt:
	/* epsilon */ { $$ = NULL; }
| abstract_declarator { $$ = $1; }
	;

type_specifier_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| type_specifier_seq { $$ = $1; }
	;

ctor_initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| ctor_initializer { $$ = $1; }
	;

COMMA_opt:
	/* epsilon */ { $$ = NULL; }
	| ',' { $$ = $1; }
	;

member_specification_opt:
	/* epsilon */ { $$ = NULL; }
	| member_specification { $$ = $1; }
	;

SEMICOLON_opt:
	/* epsilon */ { $$ = NULL; }
	| ';' { $$ = $1; }
	;


%%

static void
yyerror(char *s)
{
	fprintf(stderr, "%d: %s\n", lineno, s);
	exit(2);
}

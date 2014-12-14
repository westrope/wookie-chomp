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
%type <np> translation_unit namespace_name original_namespace_name class_name enum_name
%type <np> template_name identifier literal integer_literal character_literal floating_literal
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
%type <np> simple_declaration decl_specifier decl_specifier_seq storage_class_specifier
%type <np> function_specifier type_specifier simple_type_specifier type_name 
%type <np> elaborated_type_specifier enum_specifier enumerator_list enumerator_definition
%type <np> enumerator namespace_definition
%type <np> namespace_body
%type <np> qualified_namespace_specifier using_declaration
%type <np> using_directive linkage_specification
%type <np> init_declarator_list init_declarator declarator direct_declarator ptr_operator
%type <np> cv_qualifier_seq cv_qualifier declarator_id type_id type_specifier_seq 
%type <np> abstract_declarator direct_abstract_declarator parameter_declaration_clause
%type <np> parameter_declaration_list parameter_declaration function_body
%type <np> initializer initializer_clause initializer_list class_specifier class_head
%type <np> class_key member_specification member_declaration member_declarator_list
%type <np> member_declarator constant_initializer base_clause
%type <np> base_specifier_list base_specifier access_specifier conversion_function_id
%type <np> conversion_type_id conversion_declarator mem_initializer_list
%type <np> mem_initializer mem_initializer_id operator_function_id operator
%type <np> template_declaration template_parameter_list template_parameter type_parameter
%type <np> template_id template_argument_list template_argument explicit_instantiation
%type <np> explicit_specialization try_block function_try_block handler_seq handler
%type <np> exception_declaration throw_expression exception_specification type_id_list
%type <np> declaration_seq_opt nested_name_specifier_opt expression_list_opt COLONCOLON_opt
%type <np> new_placement_opt new_initializer_opt new_declarator_opt expression_opt
%type <np> statement_seq_opt condition_opt enumerator_list_opt initializer_opt 
%type <np> constant_expression_opt abstract_declarator_opt type_specifier_seq_opt
%type <np> direct_abstract_declarator_opt ctor_initializer_opt COMMA_opt member_specification_opt
%type <np> SEMICOLON_opt conversion_declarator_opt EXPORT_opt handler_seq_opt
%type <np> assignment_expression_opt type_id_list_opt id_expression typedef_name expression_statement
%type <np> function_definition asm_definition namespace_alias_definition named_namespace_definition
%type <np> unnamed_namespace_definition original_namespace_definition extension_namespace_definition
%type <np> ctor_initializer

%start translation_unit 

%%

/*----------------------------------------------------------------------
 * Context-dependent identifiers.
 *----------------------------------------------------------------------*/

typedef_name:
	/* identifier */
TYPEDEF { $$ = $1; }
	;

namespace_name:
	original_namespace_name { $$ = $1; }
	;

original_namespace_name:
	/* identifier */
	NAMESPACE_NAME { $$ = $1; }
	;

class_name:
	/* identifier */
	CLASS_NAME { $$ = $1; }
	| template_id { $$ = $1; }
	;

enum_name:
	/* identifier */
	ENUM_NAME { $$ = $1; }
	;

template_name:
	/* identifier */
	TEMPLATE_NAME { $$ = $1; }
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

translation_unit:
	declaration_seq_opt { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal { $$ = $1; }
	| THIS { $$ = $1; }
| '(' expression ')' { $$ = alcnary(PRIMARY_EXPRESSION3, 3, $1, $2, $3); }
	| id_expression { $$ = $1; }
	;

id_expression:
	unqualified_id { $$ = $1; }
	| qualified_id { $$ = $1; }
	;

unqualified_id:
	identifier { $$ = $1; }
	| operator_function_id { $$ = $1; }
	| conversion_function_id { $$ = $1; }
	| '~' class_name { $$ = alcnary(UNQUALIFIED_ID3, 2, $1, $2); }
	;

qualified_id:
	nested_name_specifier unqualified_id { $$ = alcnary(QUALIFIED_ID1, 2, $1, $2); }
| nested_name_specifier TEMPLATE unqualified_id { $$ = alcnary(QUALIFIED_ID2, 3, $1, $2, $3); }
	;

nested_name_specifier:
	class_name COLONCOLON nested_name_specifier
	namespace_name COLONCOLON nested_name_specifier { $$ = alcnary(NESTED_NAME_SPECIFIER1, 6, $1, $2, $3, $4, $5, $6); }
	| class_name COLONCOLON { $$ = alcnary(NESTED_NAME_SPECIFIER2, 2, $1, $2); }
	| namespace_name COLONCOLON { $$ = alcnary(NESTED_NAME_SPECIFIER3, 2, $1, $2); }
	;

postfix_expression:
	primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']'
	| postfix_expression '(' expression_list_opt ')'
	| postfix_expression '.' TEMPLATE COLONCOLON id_expression
	| postfix_expression '.' TEMPLATE id_expression
	| postfix_expression '.' COLONCOLON id_expression
	| postfix_expression '.' id_expression { $$ = alcnary(POSTFIX_EXPRESSION7, 3, $1, $2, $3); }
	| postfix_expression ARROW TEMPLATE COLONCOLON id_expression
	| postfix_expression ARROW TEMPLATE id_expression
	| postfix_expression ARROW COLONCOLON id_expression
	| postfix_expression ARROW id_expression { $$ = alcnary(POSTFIX_EXPRESSION11, 3, $1, $2, $3); }
	| postfix_expression PLUSPLUS { $$ = alcnary(POSTFIX_EXPRESSION12, 2, $1, $2); }
	| postfix_expression MINUSMINUS { $$ = alcnary(POSTFIX_EXPRESSION13, 2, $1, $2); }
	| DYNAMIC_CAST '<' type_id '>' '(' expression ')'
	| STATIC_CAST '<' type_id '>' '(' expression ')'
	| REINTERPRET_CAST '<' type_id '>' '(' expression ')'
	| CONST_CAST '<' type_id '>' '(' expression ')'
	| TYPEID '(' expression ')'
	| TYPEID '(' type_id ')'
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
	| SIZEOF '(' type_id ')'
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
	  NEW new_placement_opt new_type_id new_initializer_opt
	| COLONCOLON NEW new_placement_opt new_type_id new_initializer_opt
	| NEW new_placement_opt '(' type_id ')' new_initializer_opt
	| COLONCOLON NEW new_placement_opt '(' type_id ')' new_initializer_opt
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
	| direct_new_declarator '[' constant_expression ']'
	;

new_initializer:
	'(' expression_list_opt ')' { $$ = alcnary(NEW_INITIALIZER1, 3, $1, $2, $3); }
	;

delete_expression:
DELETE cast_expression { $$ = alcnary(DELETE_EXPRESSION1, 2, $1, $2); }
	| COLONCOLON DELETE cast_expression { $$ = alcnary(DELETE_EXPRESSION2, 3, $1, $2, $3); }
	| DELETE '[' ']' cast_expression
	| COLONCOLON DELETE '[' ']' cast_expression
	;

cast_expression:
	unary_expression { $$ = $1; }
	| '(' type_id ')' cast_expression
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
	| logical_or_expression  '?' expression ':' assignment_expression
	;

assignment_expression:
	conditional_expression { $$ = $1; }
	| logical_or_expression assignment_operator assignment_expression { $$ = alcnary(ASSIGNMENT_EXPRESSION2, 3, $1, $2, $3); }
	| throw_expression { $$ = $1; }
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
	| try_block { $$ = $1; }
	;

labeled_statement:
	identifier ':' statement { $$ = alcnary(LABELED_STATEMENT1, 3, $1, $2, $3); }
	| CASE constant_expression ':' statement
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
	IF '(' condition ')' statement
	| IF '(' condition ')' statement ELSE statement
	| SWITCH '(' condition ')' statement
	;

condition:
	expression { $$ = $1; }
	| type_specifier_seq declarator '=' assignment_expression { $$ = alcnary(CONDITION2, 3, $1, $2, $3); }
	;

iteration_statement:
	WHILE '(' condition ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' for_init_statement condition_opt ';' expression_opt ')' statement
	;

for_init_statement:
	expression_statement { $$ = $1; }
	| simple_declaration { $$ = $1; }
	;

jump_statement:
	BREAK ';' { $$ = alcnary(JUMP_STATEMENT1, 2, $1, $2); }
	| CONTINUE ';' { $$ = alcnary(JUMP_STATEMENT2, 2, $1, $2); }
	| RETURN expression_opt ';' { $$ = alcnary(JUMP_STATEMENT3, 3, $1, $2, $3); }
	| GOTO identifier ';' { $$ = alcnary(JUMP_STATEMENT4, 3, $1, $2, $3); }
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
	| template_declaration { $$ = $1; }
	| explicit_instantiation { $$ = $1; }
	| explicit_specialization { $$ = $1; }
	| linkage_specification { $$ = $1; }
	| namespace_definition { $$ = $1; }
	;

block_declaration:
	simple_declaration { $$ = $1; }
	| asm_definition { $$ = $1; }
	| namespace_alias_definition { $$ = $1; }
	| using_declaration { $$ = $1; }
	| using_directive { $$ = $1; }
	;

simple_declaration:
	  decl_specifier_seq init_declarator_list ';' { $$ = alcnary(SIMPLE_DECLARATION1, 3, $1, $2, $3); }
	|  decl_specifier_seq ';' { $$ = alcnary(SIMPLE_DECLARATION2, 2, $1, $2); }
	;

decl_specifier:
	storage_class_specifier { $$ = $1; }
	| type_specifier { $$ = $1; }
	| function_specifier { $$ = $1; }
	| FRIEND { $$ = $1; }
	| TYPEDEF { $$ = $1; }
	;

decl_specifier_seq:
	  decl_specifier { $$ = $1; }
	| decl_specifier_seq decl_specifier { $$ = alcnary(DECL_SPECIFIER_SEQ2, 2, $1, $2); }
	;

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

type_specifier:
	simple_type_specifier { $$ = $1; }
	| class_specifier { $$ = $1; }
	| enum_specifier { $$ = $1; }
	| elaborated_type_specifier { $$ = $1; }
	| cv_qualifier { $$ = $1; }
	;

simple_type_specifier:
	  type_name { $$ = $1; }
	| nested_name_specifier type_name { $$ = alcnary(SIMPLE_TYPE_SPECIFIER2, 2, $1, $2); }
	| COLONCOLON nested_name_specifier_opt type_name { $$ = alcnary(SIMPLE_TYPE_SPECIFIER3, 3, $1, $2, $3); }
	| CHAR { $$ = $1; }
	| WCHAR_T { $$ = $1; }
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
	| enum_name { $$ = $1; }
	| typedef_name { $$ = $1; }
	;

elaborated_type_specifier:
	  class_key COLONCOLON nested_name_specifier identifier
	| class_key COLONCOLON identifier { $$ = alcnary(ELABORATED_TYPE_SPECIFIER2, 3, $1, $2, $3); }
	| ENUM COLONCOLON nested_name_specifier identifier
	| ENUM COLONCOLON identifier { $$ = alcnary(ELABORATED_TYPE_SPECIFIER4, 3, $1, $2, $3); }
	| ENUM nested_name_specifier identifier { $$ = alcnary(ELABORATED_TYPE_SPECIFIER5, 3, $1, $2, $3); }
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier '<' template_argument_list '>'
	;

/*
enum_name:
	identifier
	;
*/

enum_specifier:
	ENUM identifier '{' enumerator_list_opt '}'
	;

enumerator_list:
	enumerator_definition { $$ = $1; }
	| enumerator_list ',' enumerator_definition { $$ = alcnary(ENUMERATOR_LIST2, 3, $1, $2, $3); }
	;

enumerator_definition:
	enumerator { $$ = $1; }
	| enumerator '=' constant_expression { $$ = alcnary(ENUMERATOR_DEFINTION2, 3, $1, $2, $3); }
	;

enumerator:
	identifier { $$ = $1; }
	;

/*
namespace_name:
	original_namespace_name
	| namespace_alias
	;

original_namespace_name:
	identifier
	;
*/

namespace_definition:
	named_namespace_definition { $$ = $1; }
	| unnamed_namespace_definition { $$ = $1; }
	;

named_namespace_definition:
	original_namespace_definition { $$ = $1; }
	| extension_namespace_definition { $$ = $1; }
	;

original_namespace_definition:
	NAMESPACE identifier '{' namespace_body '}'
	;

extension_namespace_definition:
	NAMESPACE original_namespace_name '{' namespace_body '}'
	;

unnamed_namespace_definition:
	NAMESPACE '{' namespace_body '}'
	;

namespace_body:
	declaration_seq_opt { $$ = $1; }
	;

/*
namespace_alias:
	identifier
	;
*/

namespace_alias_definition:
	NAMESPACE identifier '=' qualified_namespace_specifier ';'
	;

qualified_namespace_specifier:
	  COLONCOLON nested_name_specifier namespace_name { $$ = alcnary(QUALIFED_NAMESPACE_SPECIFIER1, 3, $1, $2, $3); }
	| COLONCOLON namespace_name { $$ = alcnary(QUALIFED_NAMESPACE_SPECIFIER2, 2, $1, $2); }
	| nested_name_specifier namespace_name { $$ = alcnary(QUALIFED_NAMESPACE_SPECIFIER3, 2, $1, $2); }
	| namespace_name { $$ = $1; }
	;

using_declaration:
	  USING TYPENAME COLONCOLON nested_name_specifier unqualified_id ';'
	| USING TYPENAME nested_name_specifier unqualified_id ';'
	| USING COLONCOLON nested_name_specifier unqualified_id ';'
	| USING nested_name_specifier unqualified_id ';'
	| USING COLONCOLON unqualified_id ';'
	;

using_directive:
	USING NAMESPACE COLONCOLON nested_name_specifier namespace_name ';'
	| USING NAMESPACE COLONCOLON namespace_name ';'
	| USING NAMESPACE nested_name_specifier namespace_name ';'
	| USING NAMESPACE namespace_name ';'
	;

asm_definition:
	ASM '(' string_literal ')' ';'
	;

linkage_specification:
	EXTERN string_literal '{' declaration_seq_opt '}'
	| EXTERN string_literal declaration { $$ = alcnary(LINKAGE_SPECIFICATION1, 3, $1, $2, $3); }
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
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| direct_declarator '('parameter_declaration_clause ')' cv_qualifier_seq
	| direct_declarator '('parameter_declaration_clause ')' exception_specification
	| direct_declarator '('parameter_declaration_clause ')'
	| CLASS_NAME '('parameter_declaration_clause ')'
	| CLASS_NAME COLONCOLON declarator_id '('parameter_declaration_clause ')'
	| CLASS_NAME COLONCOLON CLASS_NAME '('parameter_declaration_clause ')'
	| direct_declarator '[' constant_expression_opt ']'
	| '(' declarator ')' { $$ = alcnary(DIRECT_DECLARATOR10, 3, $1, $2, $3); }
	;

ptr_operator:
	'*' { $$ = $1; }
	| '*' cv_qualifier_seq { $$ = alcnary(PTR_OPERATOR2, 2, $1, $2); }
	| '&' { $$ = $1; }
	| nested_name_specifier '*' { $$ = alcnary(PTR_OPERATOR4, 2, $1, $2); }
	| nested_name_specifier '*' cv_qualifier_seq { $$ = alcnary(PTR_OPERATOR5, 3, $1, $2, $3); }
	| COLONCOLON nested_name_specifier '*' { $$ = alcnary(PTR_OPERATOR6, 3, $1, $2, $3); }
	| COLONCOLON nested_name_specifier '*' cv_qualifier_seq
	;

cv_qualifier_seq:
	cv_qualifier { $$ = $1; }
	| cv_qualifier cv_qualifier_seq { $$ = alcnary(CV_QUALIFIER_SEQ2, 2, $1, $2); }
	;

cv_qualifier:
	CONST { $$ = $1; }
	| VOLATILE { $$ = $1; }
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
	  direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' cv_qualifier_seq
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')' exception_specification
	| direct_abstract_declarator_opt '(' parameter_declaration_clause ')'
	| direct_abstract_declarator_opt '[' constant_expression_opt ']'
	| '(' abstract_declarator ')' { $$ = alcnary(DIRECT_ABSTRACT_DECLARATOR6, 3, $1, $2, $3); }
	;

parameter_declaration_clause:
	  parameter_declaration_list ELLIPSIS { $$ = alcnary(PARAMETER_DECLARATION_CLAUSE1, 2, $1, $2); }
| parameter_declaration_list { $$ = $1; }
	| ELLIPSIS { $$ = $1; }
| { $$ = NULL; }
	| parameter_declaration_list ',' ELLIPSIS  { $$ = alcnary(PARAMETER_DECLARATION_CLAUSE5, 3, $1, $2, $3); }
	;

parameter_declaration_list:
	parameter_declaration { $$ = $1; }
	| parameter_declaration_list ',' parameter_declaration { $$ = alcnary(PARAMETER_DECLARATION_LIST2, 3, $1, $2, $3); }
	;

parameter_declaration:
	decl_specifier_seq declarator  { $$ = alcnary(PARAMETER_DECLARATION1, 2, $1, $2); }
	| decl_specifier_seq declarator '=' assignment_expression { $$ = alcnary(PARAMETER_DECLARATION2, 3, $1, $2, $3); }
	| decl_specifier_seq abstract_declarator_opt { $$ = alcnary(PARAMETER_DECLARATION3, 2, $1, $2); }
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression
	;

function_definition:
	  declarator ctor_initializer_opt function_body { $$ = alcnary(FUNCTION_DEFINITION1, 3, $1, $2, $3); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body
	| declarator function_try_block { $$ = alcnary(FUNCTION_DEFINITION3, 2, $1, $2); }
	| decl_specifier_seq declarator function_try_block { $$ = alcnary(FUNCTION_DEFINITION4, 3, $1, $2, $3); }
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
	| '{' initializer_list COMMA_opt '}'
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
	class_head '{' member_specification_opt '}'
	;

class_head:
	class_key identifier  { $$ = alcnary(CLASS_HEAD1, 2, $1, $2); } 
	                     
	| class_key identifier base_clause { $$ = alcnary(CLASS_HEAD2, 3, $1, $2, $3); }
	| class_key nested_name_specifier identifier { $$ = alcnary(CLASS_HEAD3, 3, $1, $2, $3); }
	| class_key nested_name_specifier identifier base_clause
	;

class_key:
	CLASS { $$ = $1; }
	| STRUCT { $$ = $1; }
	| UNION { $$ = $1; }
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
	| using_declaration { $$ = $1; }
	| template_declaration { $$ = $1; }
	;

member_declarator_list:
	member_declarator { $$ = $1; }
	| member_declarator_list ',' member_declarator { $$ = alcnary(MEMBER_DECLARATOR_LIST2, 3, $1, $2, $3); }
	;

member_declarator:
{ $$ = NULL; }
	| declarator { $$ = $1; }
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

/*----------------------------------------------------------------------
 * Derived classes.
 *----------------------------------------------------------------------*/

base_clause:
	':' base_specifier_list { $$ = alcnary(BASE_CLAUSE1, 2, $1, $2); }
	;

base_specifier_list:
	base_specifier { $$ = $1; }
	| base_specifier_list ',' base_specifier { $$ = alcnary(BASE_SPECIFIER_LIST2, 3, $1, $2, $3); }
	;

base_specifier:
	  COLONCOLON nested_name_specifier class_name { $$ = alcnary(BASE_SPECIFIER1, 3, $1, $2, $3); }
	| COLONCOLON class_name { $$ = alcnary(BASE_SPECIFIER2, 2, $1, $2); }
	| nested_name_specifier class_name { $$ = alcnary(BASE_SPECIFIER3, 2, $1, $2); }
	| class_name { $$ = $1; }
	| VIRTUAL access_specifier COLONCOLON nested_name_specifier_opt class_name
	| VIRTUAL access_specifier nested_name_specifier_opt class_name
	| VIRTUAL COLONCOLON nested_name_specifier_opt class_name
	| VIRTUAL nested_name_specifier_opt class_name { $$ = alcnary(BASE_SPECIFIER8, 3, $1, $2, $3); }
	| access_specifier VIRTUAL COLONCOLON nested_name_specifier_opt class_name
	| access_specifier VIRTUAL nested_name_specifier_opt class_name
	| access_specifier COLONCOLON nested_name_specifier_opt class_name
	| access_specifier nested_name_specifier_opt class_name { $$ = alcnary(BASE_SPECIFIER12, 3, $1, $2, $3); }
	;

access_specifier:
	PRIVATE { $$ = $1; }
	| PROTECTED { $$ = $1; }
	| PUBLIC { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/

conversion_function_id:
	OPERATOR conversion_type_id { $$ = alcnary(CONVERSION_FUNCTION_ID1, 2, $1, $2); }
	;

conversion_type_id:
	type_specifier_seq conversion_declarator_opt { $$ = alcnary(CONVERSION_TYPE_ID1, 2, $1, $2); }
	;

conversion_declarator:
	ptr_operator conversion_declarator_opt { $$ = alcnary(CONVERSION_DECLARATOR1, 2, $1, $2); }
	;

ctor_initializer:
	':' mem_initializer_list { $$ = alcnary(CTOR_INITIALIZER1, 2, $1, $2); }
	;

mem_initializer_list:
	mem_initializer { $$ = $1; }
	| mem_initializer ',' mem_initializer_list { $$ = alcnary(MEM_INITIALIZER_LIST2, 3, $1, $2, $3); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')'
	;

mem_initializer_id:
COLONCOLON nested_name_specifier class_name { $$ = alcnary(MEM_INITIALIZER_ID1, 3, $1, $2, $3); }
	| COLONCOLON class_name { $$ = alcnary(MEM_INITIALIZER_ID2, 2, $1, $2); }
	| nested_name_specifier class_name { $$ = alcnary(MEM_INITIALIZER_ID3, 2, $1, $2); }
	| class_name { $$ = $1; }
	| identifier { $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Overloading.
 *----------------------------------------------------------------------*/

operator_function_id:
	OPERATOR operator { $$ = alcnary(OPERATOR_FUNCTION_ID1, 2, $1, $2); }
	;

operator:
	NEW { $$ = $1; }
	| DELETE { $$ = $1; }
	| NEW '[' ']' { $$ = alcnary(OPERATOR3, 3, $1, $2, $3); }
	| DELETE '[' ']' { $$ = alcnary(OPERATOR4, 3, $1, $2, $3); }
	| '+' { $$ = $1; }
	| '-' { $$ = $1; }
	| '*' { $$ = $1; }
	| '/' { $$ = $1; }
	| '%' { $$ = $1; }
	| '^' { $$ = $1; }
	| '&' { $$ = $1; }
	| '|' { $$ = $1; }
	| '~' { $$ = $1; }
	| '!' { $$ = $1; }
	| '=' { $$ = $1; }
	| '<' { $$ = $1; }
	| '>' { $$ = $1; }
	| ADDEQ { $$ = $1; }
	| SUBEQ { $$ = $1; }
	| MULEQ { $$ = $1; }
	| DIVEQ { $$ = $1; }
	| MODEQ { $$ = $1; }
	| XOREQ { $$ = $1; }
	| ANDEQ { $$ = $1; }
	| OREQ { $$ = $1; }
	| SL { $$ = $1; }
	| SR { $$ = $1; }
	| SREQ { $$ = $1; }
	| SLEQ { $$ = $1; }
	| EQ { $$ = $1; }
	| NOTEQ { $$ = $1; }
	| LTEQ { $$ = $1; }
	| GTEQ { $$ = $1; }
	| ANDAND { $$ = $1; }
	| OROR { $$ = $1; }
	| PLUSPLUS { $$ = $1; }
	| MINUSMINUS { $$ = $1; }
	| ',' { $$ = $1; }
	| ARROWSTAR { $$ = $1; }
	| ARROW { $$ = $1; }
	| '(' ')'  { $$ = alcnary(OPERATOR41, 2, $1, $2); }
	| '[' ']' { $$ = alcnary(OPERATOR42, 2, $1, $2); }
	;

/*----------------------------------------------------------------------
 * Templates.
 *----------------------------------------------------------------------*/

template_declaration:
	EXPORT_opt TEMPLATE '<' template_parameter_list '>' declaration
	;

template_parameter_list:
	template_parameter { $$ = $1; }
	| template_parameter_list ',' template_parameter { $$ = alcnary(TEMPLATE_PARAMETER_LIST2, 3, $1, $2, $3); }
	;

template_parameter:
	type_parameter { $$ = $1; }
	| parameter_declaration { $$ = $1; }
	;

type_parameter:
	  CLASS identifier { $$ = alcnary(TYPE_PARAMETER1, 2, $1, $2); }
	| CLASS identifier '=' type_id
	| TYPENAME identifier { $$ = alcnary(TYPE_PARAMETER3, 2, $1, $2); }
	| TYPENAME identifier '=' type_id
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier '=' template_name
	;

template_id:
	template_name '<' template_argument_list '>'
	;

template_argument_list:
	template_argument { $$ = $1; }
	| template_argument_list ',' template_argument { $$ = alcnary(TEMPLATE_ARGUMENT_LIST2, 3, $1, $2, $3); }
	;

template_argument:
	assignment_expression { $$ = $1; }
	| type_id { $$ = $1; }
	| template_name { $$ = $1; }
	;

explicit_instantiation:
	TEMPLATE declaration { $$ = alcnary(EXPLICIT_INSTANTIATION1, 2, $1, $2); }
	;

explicit_specialization:
	TEMPLATE '<' '>' declaration
	;

/*----------------------------------------------------------------------
 * Exception handling.
 *----------------------------------------------------------------------*/

try_block:
	TRY compound_statement handler_seq { $$ = alcnary(TRY_BLOCK1, 3, $1, $2, $3); }
	;

function_try_block:
	TRY ctor_initializer_opt function_body handler_seq
	;

handler_seq:
	handler handler_seq_opt { $$ = alcnary(HANDLER_SEQ1, 2, $1, $2); }
	;

handler:
	CATCH '(' exception_declaration ')' compound_statement
	;

exception_declaration:
	type_specifier_seq declarator { $$ = alcnary(EXCEPTION_DECLARATION1, 2, $1, $2); }
	| type_specifier_seq abstract_declarator { $$ = alcnary(EXCEPTION_DECLARATION2, 2, $1, $2); }
	| type_specifier_seq { $$ = $1; }
	| ELLIPSIS { $$ = $1; }
	;

throw_expression:
	THROW assignment_expression_opt { $$ = alcnary(THROW_EXPRESSION1, 2, $1, $2); }
	;

exception_specification:
	THROW '(' type_id_list_opt ')'
	;

type_id_list:
	type_id { $$ = $1; }
	| type_id_list ',' type_id { $$ = alcnary(TYPE_ID_LIST2, 3, $1, $2, $3); }
	;

/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| declaration_seq { $$ = $1; }
	;

nested_name_specifier_opt:
	/* epsilon */ { $$ = NULL; }
	| nested_name_specifier { $$ = $1; }
	;

expression_list_opt:
	/* epsilon */ { $$ = NULL; }
	| expression_list { $$ = $1; }
	;

COLONCOLON_opt:
	/* epsilon */ { $$ = NULL; }
	| COLONCOLON { $$ = $1; }
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

enumerator_list_opt:
	/* epsilon */ { $$ = NULL; }
	| enumerator_list { $$ = $1; }
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

direct_abstract_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| direct_abstract_declarator { $$ = $1; }
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

conversion_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| conversion_declarator { $$ = $1; }
	;

EXPORT_opt:
	/* epsilon */ { $$ = NULL; }
	| EXPORT { $$ = $1; }
	;

handler_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| handler_seq { $$ = $1; }
	;

assignment_expression_opt:
	/* epsilon */ { $$ = NULL; }
	| assignment_expression { $$ = $1; }
	;

type_id_list_opt:
	/* epsilon */ { $$ = NULL; }
	| type_id_list { $$ = $1; }
	;

%%

static void
yyerror(char *s)
{
	fprintf(stderr, "%d: %s\n", lineno, s);
}

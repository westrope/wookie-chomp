/* symbol.c

   Ian Westrope
   CS 445

*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "symbol.h"

#include "prodrules.h"
#include "120gram.h"



void pop_table(List * table, node *t, int scope){
  if(t == NULL || t->symbol == NULL){
    printf("tree is null\n");
    exit(3);
  }

  //to do
  // init_declarator is ident = literal
  // simple_declaration is decl_specifier_seq init_declarator_list
  switch(t->symbol){
  case SIMPLE_DECLARATION1:{
    int type;
    char *lexeme;
    type = gettype(t->u.nt.child[0]);
    lexeme = getsymbol(t->u.nt.child[1]);
    list_push(table, type, scope, lexeme);
    // put stuff into table
    // increment scope if needed
    break;
  }
  default:
    break;
  }
  if(t->symbol >= 1000){
    int i;
    for(i = 0; t->u.nt.child[i] != NULL; i++){
      pop_table(table, t->u.nt.child[i], scope);
    }
}
}

char * getsymbol(node *t){
  if(t == NULL){
    printf("tree is null\n");
    exit(3);
  }
  char * lexeme;
  switch(t->symbol){
  case INIT_DECLARATOR_LIST1:{
    while(t->u.nt.child[0]->symbol != 258){
 
      t = t->u.nt.child[0];
    }
    if(t->u.nt.child[0] != NULL){
      t = t->u.nt.child[0];
      lexeme = strdup(t->u.t.lexeme);
      return lexeme;
    }
  }
  }
}

int gettype( node *t){
  if(t == NULL){
    printf("tree is null\n");
    exit(3);
  }
  switch(t->symbol){
  case DECL_SPECIFIER_SEQ1:{
    while(t->u.nt.child[0]->symbol != 320){ 
 
     t = t->u.nt.child[0];
    }
    if(t->u.nt.child[0]->symbol == INT) return 1;
    else return 0;
  }
  }
  return 0;
}

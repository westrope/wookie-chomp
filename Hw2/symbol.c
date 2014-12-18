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
  // int x; done
  // float x; done
  // char x; done
  // int x = 1;
  // class x {}; needs new scope
  switch(t->symbol){
  case SIMPLE_DECLARATION1:{
    int type;
    char *lexeme;
    type = gettype(t->u.nt.child[0]);
    lexeme = getsymbol(t->u.nt.child[1]);
    int z = search(table, type, lexeme);
     if(z == 1){
	printf("semantic error\n");
	exit(3);
      }
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
    while((t->u.nt.child[0]->symbol != 320) &&
	  (t->u.nt.child[0]->symbol != 314) &&
	  (t->u.nt.child[0]->symbol != 298)){ 
     t = t->u.nt.child[0];
    }
    if(t->u.nt.child[0]->symbol == INT) return 1;
    if(t->u.nt.child[0]->symbol == FLOAT) return 2;
    if(t->u.nt.child[0]->symbol == CHAR) return 3;
    else return 0;
  }
  }
  return 0;
}

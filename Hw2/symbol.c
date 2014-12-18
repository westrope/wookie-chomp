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
  // class x {}; needs new scope done
  // member variables
  // functions
  switch(t->symbol){
  case FUNCTION_DEFINITION2:
  case SIMPLE_DECLARATION1:{
    int type;
    char *lexeme;
    type = gettype(t->u.nt.child[0]);
    lexeme = getsymbol(t->u.nt.child[1], type, scope, table);
    if(lexeme == NULL) break;
    int z = search(table, scope, lexeme);
     if(z == 1){
	printf("semantic error\n");
	exit(3);
      }
    list_push(table, type, scope, lexeme);
    // put stuff into table
    // increment scope if needed
    break;
  }
  case CLASS_HEAD1:{
    int type;
    char *lexeme;
    type = gettype(t->u.nt.child[0]);
    lexeme = getsymbol(t->u.nt.child[1], type, scope, table);
    int z = search(table, scope, lexeme);
    if(z == 1){
      printf("semantic error\n");
      exit(3);
    }
    list_push(table, type, scope, lexeme);
    break;
  }
  case FUNCTION_BODY1:{
    scope++;
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

char * getsymbol(node *t, int type, int scope, List * table){
  if(t == NULL){
    printf("tree is null\n");
    exit(3);
  }
  char * lexeme;
  switch(t->symbol){
  case INIT_DECLARATOR1:
  case DECLARATOR1:
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
  case 258:{
     lexeme = strdup(t->u.t.lexeme);
     return lexeme;
  }


  case INIT_DECLARATOR_LIST2:{
    node *tmp = calloc(1, sizeof(node));
    tmp = t;
    int count = 1;
    while(tmp->u.nt.child[0]->symbol == INIT_DECLARATOR_LIST2){
      tmp = tmp->u.nt.child[0];
      count++;
    }
    printf("count %d\n", count);
    int i;
    for(i = 0; i < count; i++){
      tmp = t->u.nt.child[i];
      if(tmp->u.nt.child[0] == NULL) break;
      lexeme = getsymbol(tmp->u.nt.child[0], type, scope, table);
      printf("lex %s, type %d\n", lexeme, type);
      list_push(table, type, scope, lexeme);
      if(tmp->u.nt.child[1] == NULL) break;
      lexeme = getsymbol(tmp->u.nt.child[1], type, scope, table);
      printf("lex %s, type %d\n", lexeme, type);
      list_push(table, type, scope, lexeme); 
    }
    return NULL;

  }
  }
}

int gettype( node *t){
  if(t == NULL){
    printf("tree is null lalala\n");
    exit(3);
  }
  switch(t->symbol){
  case CLASS_KEY1:
  case DECL_SPECIFIER_SEQ1:{
    while((t->u.nt.child[0]->symbol != 320) &&
	  (t->u.nt.child[0]->symbol != 299) &&
	  (t->u.nt.child[0]->symbol != 314) &&
	  (t->u.nt.child[0]->symbol != 298)){ 
     t = t->u.nt.child[0];
    }
    if(t->u.nt.child[0]->symbol == INT) return 1;
    if(t->u.nt.child[0]->symbol == FLOAT) return 2;
    if(t->u.nt.child[0]->symbol == CHAR) return 3;
    if(t->u.nt.child[0]->symbol == CLASS) return 4;
    else return 0;
  }
  }
  return 0;
}

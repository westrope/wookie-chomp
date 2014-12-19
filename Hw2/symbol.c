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

extern int namespace;
extern int iostream;
int ptr;

void insert_iostream(List * table){
  if( namespace == 1 && iostream == 1){
    int type = 4;
    int scope = 0;
    char *lexeme = calloc(1, sizeof("string"));
    lexeme = "string";
    int z = search(table, scope, lexeme);
    if(z == 1){
      printf("semantic error, %s has already been declared\n", lexeme);
      exit(3);
    }
    list_push(table, type, scope, lexeme);
    char *lexeme2 = calloc(1, sizeof("fstream"));    
    lexeme2 = "fstream";
    z = search(table, scope, lexeme2);
    if(z == 1){
      printf("semantic error, %s has already been declared\n", lexeme);
      exit(3);
    }
    list_push(table, type, scope, lexeme2);			  
}
}

void type_check(List * table, node *t, int scope){
  if(t == NULL || t->symbol == NULL){
    printf("tree is null\n");
    exit(3);
  }

  switch(t->symbol){
  case EQUALITY_EXPRESSION2:
  case ASSIGNMENT_EXPRESSION2:
  case MULTIPLICATIVE_EXPRESSION2:
  case MULTIPLICATIVE_EXPRESSION3:
  case ADDITIVE_EXPRESSION3:
  case ADDITIVE_EXPRESSION2:{
    int y;
    y = express_type(t->u.nt.child[0], t->u.nt.child[1], table, scope);
    if( y == 0){
      printf("semantic error, incorrect types in %d expression\n", t->symbol);
      exit(3);
    }
    break;
  }
  case FUNCTION_BODY1:{
    scope++;
    break;
  }
  case AND_EXPRESSION2:    
  case EXCLUSIVE_OR_EXPRESSION2:
  case INCLUSIVE_OR_EXPRESSION2:
  case LOGICAL_AND_EXPRESSION2:
  case LOGICAL_OR_EXPRESSION2:{
    int y = express_bool(t->u.nt.child[0], t->u.nt.child[1], table, scope);
    if( y == 0 ){
      printf("semantic error, incorrect types in %d expression\n", t->symbol);
      exit(3);
    }
    break;
  }



  default:{
    break;
  }
  }
  if(t->symbol >= 1000){
    int i;
    for(i = 0; t->u.nt.child[i] != NULL; i++){
      type_check(table, t->u.nt.child[i], scope);
    }
  }
}

int express_bool(node *t1, node *t2, List * table, int scope){
  char *lex1;
  char *lex2;
  node *node1 = calloc(1, sizeof(lnode));
  node *node2 = calloc(1, sizeof(lnode));
  while( t1 != NULL && t1->symbol != 258)t1 = t1->u.nt.child[0];
  while( t2 != NULL && t2->symbol != 258)t2 = t2->u.nt.child[0];
  lex1 = strdup(t1->u.t.lexeme);
  lex2 = strdup(t2->u.t.lexeme);
  int x;
  x = bool_search(table, scope, lex1, lex2);
  if( x != 1) return 0;
  else return 1;
}

int express_type(node *t1, node *t2, List * table, int scope){
  char *lex1;
  char *lex2;
  node *node1 = calloc(1, sizeof(lnode));
  node *node2 = calloc(1, sizeof(lnode));
  while( t1 != NULL && t1->symbol != 258)t1 = t1->u.nt.child[0];
  while( t2 != NULL && t2->symbol != 258)t2 = t2->u.nt.child[0];
  lex1 = strdup(t1->u.t.lexeme);
  lex2 = strdup(t2->u.t.lexeme);
  int x;
  x = type_search(table, scope, lex1, lex2);
  if( x != 1) return 0;
  else return 1;
} 



void pop_table(List * table, node *t, int scope){
  ptr = 0;
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
    if(ptr == 1){
      type = 6;
      ptr = 0;
    }
    if(lexeme == NULL) break;
    int z = search(table, scope, lexeme);
     if(z == 1){
       printf("semantic error, %s has already been declared\n", lexeme);
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
      printf("semantic error, %s has already been declared\n", lexeme);
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
       if(t->u.nt.child[0]->symbol == 9900){
	t = t->u.nt.child[1];
	ptr = 1;
	continue;
      }else t = t->u.nt.child[0];
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
     int i;
    for(i = 0; i < count; i++){
      tmp = t->u.nt.child[i];
      if(tmp->u.nt.child[0] == NULL) break;
      lexeme = getsymbol(tmp->u.nt.child[0], type, scope, table);
       int z = search(table, scope, lexeme);
      if(z == 1){
        printf("semantic error, %s has already been declared\n", lexeme);
        exit(3);
      }
      list_push(table, type, scope, lexeme);
      if(tmp->u.nt.child[1] == NULL) break;
      lexeme = getsymbol(tmp->u.nt.child[1], type, scope, table);
       z = search(table, scope, lexeme);
      if(z == 1){
        printf("semantic error, %s has already been declared\n", lexeme);
        exit(3);
      }
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
	  (t->u.nt.child[0]->symbol != 351) &&
	  (t->u.nt.child[0]->symbol != 298)){ 
     t = t->u.nt.child[0];
    }
    if(t->u.nt.child[0]->symbol == INT) return 1;
    if(t->u.nt.child[0]->symbol == FLOAT) return 2;
    if(t->u.nt.child[0]->symbol == CHAR) return 3;
    if(t->u.nt.child[0]->symbol == CLASS) return 4;
    if(t->u.nt.child[0]->symbol == VOID) return 5;
    else return 0;
  }
  }
  return 0;
}

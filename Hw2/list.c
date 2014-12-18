/* list.c

   Ian Westrope
   CS 445

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

// set list count = to 0 after call of this
List * create_list() {
  return calloc(1, sizeof(List));
}

// add to back
void list_push(List * list, int btype, int scope, char *lexeme){
  lnode * node = calloc(1, sizeof(lnode));
  
  if(node == NULL) { 
    printf("Error allocating node\n");
    exit(3);
  }

  node->base_type = btype;
  node->scope = scope;
  
  node->lexeme = strdup(lexeme);

  if(list->last == NULL){
    list->first = node;
    list->last = node;
  } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count++;
}

// returns 1 for true 0 for false
int search(List *list, int scope, char *lexeme){
  if(list == NULL){
    printf("List to search is null\n");
    exit(3);
  }
  lnode *node = calloc(1, sizeof(lnode));
  node = list->first;
  while(node != NULL){
    if ((strcmp(node->lexeme,lexeme) == 0) 
	&& (node->scope == scope)){
        return 1;
    } else {
      node = node->next;
    }
  }
  return 0;
}

int bool_search(List *list, int scope, char *lex1, char *lex2){
  int type1;
  int type2;
  lnode *node1 = calloc(1, sizeof(lnode));
  lnode *node2 = calloc(1, sizeof(lnode));
  node1 = list->first;
  while( node1 != NULL && (node1->scope != scope)){
    node1 = node1->next;
  }

  node2 = node1;
  while( node2 != NULL){
     if(strcmp(node2->lexeme,lex2) == 0)break;
    node2 = node2->next;
  }
  while( node1 != NULL){
    if(strcmp(node1->lexeme,lex1) == 0)break;
    node1 = node1->next;
  }
  if(node1->base_type != 4 && 
     node1->base_type != 5 &&
     node2->base_type != 4 &&
     node2->base_type != 5) return 1;
  else return 0;
}

int type_search(List *list, int scope, char *lex1, char *lex2){
  int type1;
  int type2;
  lnode *node1 = calloc(1, sizeof(lnode));
  lnode *node2 = calloc(1, sizeof(lnode));
  node1 = list->first;
  while( node1 != NULL && (node1->scope != scope)){
    node1 = node1->next;
  }

  node2 = node1;
  while( node2 != NULL){
     if(strcmp(node2->lexeme,lex2) == 0)break;
    node2 = node2->next;
  }
  while( node1 != NULL){
    if(strcmp(node1->lexeme,lex1) == 0)break;
    node1 = node1->next;
  }
  if(node1 == NULL || node2 == NULL) return 0;
  if(node1->base_type == node2->base_type) return 1;
  else return 0;
}

void print(List * list){
  if(list->first == NULL){
    printf("NULL list\n");
    exit(3);
  }
  lnode *node = calloc(1,sizeof(lnode));
  node = list->first;
  while(node != NULL){
    printf("Base type: %d, lexeme %s\n", node->base_type, node->lexeme);
    node = node->next;
  }
  
}

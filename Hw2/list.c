/* list.c

   Ian Westrope
   CS 445

*/
#include <stdlib.h>
#include <stdio.h>
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
  node->lexeme = lexeme;

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
int search(List *list, int btype, char *lexeme){
  if(list == NULL){
    printf("List to search is null\n");
    exit(3);
  }
  lnode *node = calloc(1, sizeof(lnode));
  node = list->first;
  while(node != NULL){
    if ( (node->base_type == btype) && (node->lexeme=lexeme)){
      return 1;
    } else {
      node = node->next;
    }
  }
  return 0;
}

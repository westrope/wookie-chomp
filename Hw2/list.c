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
int search(List *list, int btype, char *lexeme){
  if(list == NULL){
    printf("List to search is null\n");
    exit(3);
  }
  lnode *node = calloc(1, sizeof(lnode));
  node = list->first;
  while(node != NULL){
     if (strcmp(node->lexeme,lexeme) == 0){
        return 1;
    } else {
      node = node->next;
    }
  }
  return 0;
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

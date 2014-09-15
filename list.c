#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void Init(){
  start = NULL;
  finish = NULL;
  count = 0;
}

void Add(nodeptr p, struct token* t){
  nodeptr curr;

  curr = (struct node*)malloc(sizeof(struct node));
  curr->token = t;
  curr->next = start;
  start = curr;

  /*
  n =(struct node*)malloc(sizeof(struct node));
  n->token = t;
  count++;

  if( start == NULL){
    start = n;
    finish = n;
    n->next = NULL;
    n->prev = NULL;
  }
  else {
    n->next = NULL;
    n->prev = start;
    p->next = n;
    start = n;
  }
  */
}

void Print(){
  nodeptr l = NULL;
  nodeptr n;
  do {
    n = start->next;
    start->next = l;
    l = start;
    start = n;
  }
  while( start != NULL);

  while( l != NULL){
    PrintToken(l->token);
    l = l->next;
  }
}

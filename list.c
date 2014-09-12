#include <stdio.h>
#include <stdlib.h>

#include "list.h"


void Init(){
  start = NULL;
  finish = NULL;
  count = 0;
}

void Add(nodeptr p, token* t){
  nodeptr n;

  n =(struct node *)malloc(sizeof(struct node));
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
}

void Print(){
  nodeptr p = finish;

  while( p != NULL){
    PrintToken(p->token);
    p = p->next;
  }
}

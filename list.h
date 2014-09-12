#include "token.h"

struct node {
  token *token;
  struct node *next;
  struct node *prev;
};

typedef node* nodeptr;
nodeptr start;
nodeptr finish;
int count;

void Init();
void Add(nodeptr p, token* t);
void Print();


    
    

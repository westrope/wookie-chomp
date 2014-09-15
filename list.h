#include "token.h"

struct node {
  struct token *token;
  struct node *next;
  struct node *prev;
};

typedef struct  node* nodeptr;
nodeptr start;
nodeptr finish;
int count;

void Init();
void Add(nodeptr p, struct token* t);
void Print();


    
    

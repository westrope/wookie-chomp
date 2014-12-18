/* tree.h

   Ian Westrope
   CS 445

*/

int iostream;
int namespace;

typedef struct node{
  int symbol;
  union {
    struct leaf {
      char *lexeme;
      int val;
    } t;
    struct nonleaf {
      struct node *child[9];
    } nt;
  } u;
} node;

struct node * treenode(int symbol);
struct node * alcleaf( int symbol, char *lexeme);
struct node * alcnary(int symbol, int nkids, ...);
void treeprint(struct node *np, int j);

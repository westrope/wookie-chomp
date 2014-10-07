/* tree.h

   Ian Westrope
   CS 445

*/

struct node{
  int symbol;
  union {
    struct leaf {
      char *lexeme;
      int val;
    } t;
    struct nonleaf {
      int rule;
      struct node *child[9];
    } nt;
  } u;
};

struct node * treenode(int symbol);
struct node * alcleaf( int symbol, char *lexeme);
struct node * alcnary(int symbol, int prodrule, int nkids, ...);
void treeprint(struct node *np);

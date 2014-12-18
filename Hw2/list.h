/* list.h

   Ian Westrope
   CS 445

   found code for linked list from here:
   http://c.learncodethehardway.org/book/ex32.html

*/


typedef struct lnode {
  int base_type; //int code
  int scope;
  char *lexeme;
  int ival;
  float fval;
  char *sval;
  int parameter;
  
  // union of array, function, class
  union {
    struct array {
      int size;
    } array;
    struct function {
      struct lnode *flist;
    } function;
    struct class {
      struct lnode *clist;
    } class;
  } u;

  struct lnode *next;
  struct lnode *prev;

} lnode;

typedef struct list {
  int scope;
  int count;
  lnode *first;
  lnode *last;
} List;

List * create_list();
// add to back
void list_push(List * list, int btype, int scope, char *lexeme);
int search(List * list, int btype, char *lexeme);
void print(List * list);

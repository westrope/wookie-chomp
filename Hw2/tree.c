/* tree.c

   Ian Westrope
   CS 445

   tree structure adapted from my flex/bison assignment of CS210
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"


struct node * treenode(int symbol){
  struct node *p = (struct node*)calloc(1, sizeof(struct node));
  if (p == NULL) {
    printf("out of memory in treenode constructor");
    exit(-1);
  }
  p->symbol = symbol;
  return p;
}

struct node * alcleaf(int symbol, char *lexeme)
{
   struct node * ret = treenode(symbol);
   ret->u.t.lexeme = strdup(lexeme);
   return ret;
}


struct node * alcnary(int symbol, int prodrule, int nkids, ...)
{
   int i;
   va_list mylist;
   struct node *rv = treenode(symbol);
   rv->u.nt.rule = prodrule;
   va_start(mylist, nkids);
   for(i=0; i<nkids; i++) {
      rv->u.nt.child[i] = va_arg(mylist, struct node *);
//      printf("set child %d to %p\n", rv->u.nt.child[i]);
      }
   va_end(mylist);
   return rv;
}

void treeprint(struct node *np)
{
/* printf("treeprint %p\n", np); */
   /*
 *     * avoid segfault if something horrible went wrong.
 *         */
   if (np == NULL) { warn("NULL tree pointer"); return; }

   if (np->symbol < 1000) {
      printf("%s", np->u.t.lexeme);  
			fflush(stdout);
      }
   else {
      int i;
      for (i=0; np->u.nt.child[i] != NULL; i++ ) {
      	treeprint(np->u.nt.child[i]);
       	if( np->u.nt.rule == 5001 || np->u.nt.rule == 4001
	    || np->u.nt.rule == 4002) {
	  
	  printf("\n");
	}
      }
   }
}

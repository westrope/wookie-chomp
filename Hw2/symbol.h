/* symbol.h

   Ian Westrope
   CS 445
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "tree.h"

void pop_table(List * table, node *t, int scope);
char * getsymbol( node *t, int type, int scope, List * table);
int gettype( node *t);

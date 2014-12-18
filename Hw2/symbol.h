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
void type_check(List * table, node *t, int scope);
int express_type(node *t1, node *t2, List *table, int scope);
int express_bool(node *t1, node *t2, List *table, int scope);
void insert_iostream(List *table);

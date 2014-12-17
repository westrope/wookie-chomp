/* symbol.h

   Ian Westrope
   CS 445
*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct table {
  int count;
  List *beg;
  List *end;
} Table;

Table * create_table();
void table_push(Table * table);

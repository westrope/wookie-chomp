/* symbol.c

   Ian Westrope
   CS 445

*/

#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"
#include "tree.h"

List table[100]; //could this a variable that counts the number of scopes before declaring

void pop_table(List table[], struct node *tree, int scope){
  if(tree == NULL){
    printf("tree is null\n");
    exit(3);
  }
  switch(tree->symbol){
  case #DEFINE HERE:{
    // put stuff into table
    // increment scope if needed
    break;
  }
  default:
    break;
  }
  if(tree->symbol >= 1000){
    // recurse
}

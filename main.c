/*
  main.c
  
  Ian Westrope
  CS 445
*/

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

extern FILE *yyin;
extern char *yytext;

int main( int argc, char *argv[] )
{
  int t;

  if( argc < 2 ) // check if filename is given
  {
    printf( "Useage: 120++ filename.cpp\n");
    exit(-1);
  }

  yyin = fopen( argv[1], "r"); // open file
  if( yyin == NULL) // check if file opened
  {
    printf("Can't open file '%s' \n", argv[1]);
    exit(-1);
  }

  while( (t = yylex()) > 0)
  {
    printf( "token '%d' text '%s'\n", t, yytext);
  }

  return 0;
}

/*
  main.c
  
  Ian Westrope
  CS 445
*/

#include <stdio.h>
#include <stdlib.h>

#include "y.tab.h"
#include "token.h"
#include "list.h"

extern FILE *yyin;
extern char *yytext;

int main( int argc, char *argv[] )
{
  int t;
  g_argc = argc;
  g_argv = argv;

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
    // initialize linked list set to NULL
    nodeptr p;
    Init();
    p = start;
    while( (t = yylex()) > 0)
    {
      tok = CreateToken(t, yytext, t_filename, yylineno); 
      if( t = SLIT){
	SetSval(tok, t_sval);
	free(t_sval);
      }
      Add( p, tok);
      printf( "token '%d' text '%s'\n", t, yytext);
    }
    // traverse to end of linked list
    // print linked list
    Print();
  return 0;
}



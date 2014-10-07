/* main.c

   Ian Westrope
   CS 445

*/

#include <stdlib.h>
#include <stdio.h>

#include "120gram.h"
#include "120lex.h"
#include "tree.h"

extern FILE *yyin;
extern char *yytext;


int main( int argc, char *argv[] ){
  int t;

  if( argc < 2 ) // check for filename
    {
      printf( "Useage: 120++ filename.cpp\n");
      exit(-1);
    }

  int i;
  for( i = 1; i < argc; i++)  // loop over all files from command line
    {    
      printf("In file %s\n", argv[i]);
    yyin = fopen( argv[i], "r"); // open file
    if( yyin == NULL) // check if file opened
      {
	printf("Can't open file '%s'\n", argv[i]);
	exit(-1);
      }
    yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE)); // push file onto buffer
    /*
    while( (t = yylex()) > 0)
      {
	printf( "found token '%d'\n", t);
      }
    */
    int x;
    x = yyparse();
    printf("result equals: '%d'\n", x);
    fclose(yyin);
    }
} 

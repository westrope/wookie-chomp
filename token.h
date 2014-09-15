#include <stdlib.h>

int g_argc;
char **g_argv;

char *t_sval;
char *t_filename;


struct token {
  int code;   /* the integer code returned by yylex */
  char *text;     /* the actual string (lexeme) matched */
  int lineno;     /* the line number on which the token occurs */
  char *filename; /* the source file in which the token occurs */
  int ival;       /* if you had an integer constant, store its value here */
  float fval;       // float value
  char *sval;      /* if you had a string constant, malloc space and store */
};               /*    the string (less quotes and after escapes) here */


struct token* CreateToken( int code, char *text, char *filename, int line);
void SetSval(struct token* t, char *sval);
void PrintToken(struct token *t);

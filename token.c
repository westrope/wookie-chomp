#include <stdio.h>
#include <string.h>

#include "token.h"
#include "y.tab.h"

struct token* CreateToken( int code, char *text, char *filename, int lineno){
  struct token* t = malloc(sizeof(struct token*));

  t->code = code;
  t->lineno = lineno;
  t->ival = -1;
  t->fval = -1;

  int len;

  len = (strlen(text) + 1);
  t->text = (char*)calloc(len, sizeof(char));
  strcpy(t->text, text);

  len = (strlen(filename) +1);
  t->filename = calloc(len, sizeof(char));
  strcpy(t->filename, filename);

  if( code == INTLIT ) t->ival = atoi(text);
  if( code == FLLIT ) t->fval = atof(text);

  return t;
}

void SetSval(struct token* t, char *sval){
  int len;
  len = (strlen(sval) +1);
  t->sval = calloc(len, sizeof(char));
  strcpy(t->sval, sval);
}

void PrintToken(struct token *t){
  if(t->ival != -1)
    printf("Code:%d\t Text:%s\t Line:%d\t File:%s\t Lit:%d\n", t->code, t->text, t->lineno, t->filename, t->ival);
  else if(t->fval != -1)
    printf("Code:%d\t Text:%s\t Line:%d\t File:%s\t Lit:%f\n", t->code, t->text, t->lineno, t->filename, t->fval);
  else if(t->sval != NULL)
    printf("Code:%d\t Text:%s\t Line:%d\t File:%s\t Lit:%s\n", t->code, t->text, t->lineno, t->filename, t->sval);
  else printf("could not print \n");
}

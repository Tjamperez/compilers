%union {
  double valor;
  asd_tree_t *arvore;
}
%code requires { #include "asd.h" }

%{
#include <math.h>
#include <stdio.h>
int yyerror (char const *s);
extern int yylex (void);
%}

%token<valor> NUMBER
%token<valor> PLUS TIMES
%token<valor> LEFT RIGHT
%token<valor> END
%token<valor> END_OF_FILE

%type<arvore> E
%type<arvore> T
%type<arvore> F


%define parse.error verbose
%start Input

%%

Input: /* A entrada vazia é válida */;
Input: Input Line

Line: END
Line: END_OF_FILE { return EOF; }
Line: E END { fprintf(stdout, "Expressão aritmética reconhecida com sucesso.\n"); }

E: E PLUS T
E: T

T: T TIMES F
T: F

F: LEFT E RIGHT
F: NUMBER { $$->result = $1; }

%%

extern void yylex_destroy(void);
int yyerror(char const *s) {
  printf("%s\n", s);
  return 1;
}

int main() {
  int ret;
  do {
     ret = yyparse();
  } while(ret != EOF);
  printf("Fim.\n");
  yylex_destroy();
  return 0;
}

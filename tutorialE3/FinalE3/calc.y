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
Line: E END { printf("Expressão aritmética reconhecida com sucesso.\n"); asd_print_graphviz($1); asd_free($1); }

E: E PLUS T { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); $$->result = $1->result + $3->result; }
E: T { $$ = $1; }

T: T TIMES F { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3);  $$->result = $1->result * $3->result; }
T: F { $$ = $1; }

F: LEFT E RIGHT { $$ = $2; }
F: NUMBER { char num_str[20]; sprintf(num_str, "%.6g", $1);  $$ = asd_new(num_str); $$->result = $1; }

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

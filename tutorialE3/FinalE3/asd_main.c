#include <stddef.h>
#include <stdio.h>
#include "asd.h"
int main() {
  asd_tree_t *asd_mult = NULL, *asd_soma = NULL;
  asd_mult = asd_new("*");
  asd_add_child(asd_mult, asd_new("3"));
  asd_add_child(asd_mult, asd_new("4"));
  
  asd_soma = asd_new("+");
  asd_add_child(asd_soma, asd_new("5"));
  asd_add_child(asd_soma, asd_mult);

  double result = evaluate_ast(asd_soma);
  printf("Result of expression: %.2f\n", result);
  
  asd_print(asd_soma);
  asd_print_graphviz(asd_soma);
  asd_free(asd_soma);
  return 0;
}

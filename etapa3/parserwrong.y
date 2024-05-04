/* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 00302162 */

%define parse.error verbose

%code requires { #include "tree.h" }

%union {
  val_lex_t *valor_lexico;
  tree_node_t *tree;
}

%{

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);
extern char *yytext;
extern void *arvore;

%}

// Definição dos tokens
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token <valor_lexico> TK_IDENTIFICADOR
%token <valor_lexico> TK_LIT_INT
%token <valor_lexico> TK_LIT_FLOAT
%token <valor_lexico> TK_LIT_FALSE
%token <valor_lexico> TK_LIT_TRUE
%token TK_ERRO


%type <tree> LITINT
%type <tree> LITFLOAT
%type <tree> LITTRUE
%type <tree> LITFALSE


%type <tree> identificador
%type <tree> programa
%type <tree> lista_de_elementos
%type <tree> elemento
%type <tree> declaracao_global
%type <tree> tipo
%type <tree> lista_identificador
%type <tree> definicao_de_funcao
%type <tree> cabecalho
%type <tree> lista_de_parametros
%type <tree> parametro
%type <tree> corpo
%type <tree> bloco_de_comandos
%type <tree> lista_de_comandos
%type <tree> comando_simples
%type <tree> declaracao_variavel
%type <tree> comando_atribuicao
%type <tree> comando_retorno
%type <tree> condicional
%type <tree> loop
%type <tree> expressao
%type <tree> operando
%type <tree> operador
%type <tree> comparacao
%type <tree> op_comparacao
%type <tree> adicaousub
%type <tree> op_adicaousub
%type <tree> multoudivoures
%type <tree> op_multoudivoures
%type <tree> lista_expressao
%type <tree> unario
%type <tree> primario
%type <tree> literais
%type <tree> chamada_funcao
%type <tree> nome_func


%%

//##########################
// Definição de programa
programa: lista_de_elementos
        {
            arvore = $1;
        }
        | /* vazio */
		{
			arvore = NULL;
		}
        ;

//##########################
// Lista de elementos
lista_de_elementos: lista_de_elementos elemento
                  {
					  $$ = $1;
                  }
                  | elemento
                  {
                      $$ = ast_new(NULL); // Criando nó com valor nulo
                  }
                  ;

//##########################
// Elemento do programa
elemento: declaracao_global
        | definicao_de_funcao
        ;

//##########################
// Declaração global de variável
declaracao_global: tipo lista_identificador ','
                 ;

//##########################
// Identificador
identificador: TK_IDENTIFICADOR
             {
                $$ = ast_new($1);
             }
             ;

//##########################
// Tipos de dados
tipo: INT
	{
		$$ = NULL;
	}
    | FLOAT
	{
		$$ = NULL;
	}
    | BOOL
	{
		$$ = NULL;
	}
    ;

//##########################
// Token INT
INT: TK_PR_INT 
   ;

//##########################
// Token FLOAT
FLOAT: TK_PR_FLOAT 
	 ;

//##########################
// Token BOOL
BOOL: TK_PR_BOOL 
	;

//##########################
// Lista de identificadores
lista_identificador: lista_identificador ';' identificador
					{
					   $$ = ast_new(NULL); // Criar nó genérico
                       ast_add_child($$, $1);
                       ast_add_child($$,$3);
					}
                   | identificador
				   {
						$$ = ast_new(NULL);
						$$ = $1;
				   }
                   ;

//##########################
// Definição de função
definicao_de_funcao: cabecalho corpo
                   {
                       $$ = ast_new(NULL); // Criar nó genérico
                       ast_add_child($$, $1);
                       ast_add_child($$, $2);
                       if (arvore == NULL) {
                           arvore = $$;
                       }
                   }
                   ;

//##########################
// Cabeçalho da função
cabecalho: '(' lista_de_parametros ')' OR tipo '/' identificador
         {
             $$ = ast_new(NULL); // Criar nó genérico
             ast_add_child($$, $2);
             $$ = $7;
         }
         ;

//##########################
// Token OR
OR: TK_OC_OR 
  ;

//##########################
// Lista de parâmetros
lista_de_parametros: lista_de_parametros ';' parametro
				   {
						 $$ = ast_new(NULL);
						 ast_add_child($$, $1);
             			 ast_add_child($$, $3);
				   }
                   | parametro
				   {
					 $$ = $1;
				   }
                   | /* vazio */
				   {
					 $$ = NULL;
				   }
                   ;

//##########################
// Parâmetro da função
parametro: tipo identificador
         {
             $$ = ast_new(NULL); // Criar nó genérico
             $$ = $2;
         }
         ;

// Corpo da função
corpo: '{' bloco_de_comandos '}'
	 {
	     $$ = ast_new(NULL); // Criar nó genérico
	 }
	 |  corpo '{' bloco_de_comandos '}'
     {
         $$ = $1;
     }
     ;

//##########################
// Bloco de Comandos que aceita vazio
bloco_de_comandos: /* vazio */
				 {
					 $$ = NULL;
				 }
                 | lista_de_comandos
                 ;

//##########################
// Definição de lista de comandos simples
lista_de_comandos: lista_de_comandos comando_simples ','
                 {
                     ast_add_child($1, $2);
                     $$ = $1;
                 }
                 | comando_simples ','
                 {
                     $$ = ast_new(NULL); // Criar nó genérico
                     ast_add_child($$, $1);
                 }
                 ;

//##########################
// Definição de comando simples
comando_simples: declaracao_variavel
               | comando_atribuicao 
               | comando_retorno
               | condicional
               | loop
               | corpo
               ;

//##########################
// Declaração de variável
declaracao_variavel: tipo lista_identificador
                   ;

//##########################
// Comando de atribuição
comando_atribuicao: identificador '=' expressao
                  {
                      $$ = ast_new(NULL); // Criar nó genérico
                      ast_add_child($$, $1);
                      ast_add_child($$, $3);
                  }
                  ;

//##########################
// Comando de retorno
RETURN: TK_PR_RETURN
      ;
comando_retorno: RETURN expressao
               {
                   $$ = ast_new(NULL); // Criar nó genérico
                   ast_add_child($$, $2);
               }
               ;

//##########################
// Comando de controle de fluxo
IF: TK_PR_IF
  ;

ELSE: TK_PR_ELSE
	;


condicional: IF '(' expressao ')' corpo
		   {
			   $$ = ast_new(NULL); // Criar nó genérico
               ast_add_child($$, $3);
               ast_add_child($$, $5);
		   }
           | IF '(' expressao ')' corpo ELSE corpo 
           {
               $$ = ast_new(NULL); // Criar nó genérico
               ast_add_child($$, $3);
               ast_add_child($$, $5);
               if ($7) {
                   ast_add_child($$, $7);
               }
           }
           ;

//##########################
// Comando de loop
WHILE: TK_PR_WHILE 
     ;
loop: WHILE '(' expressao ')' corpo
    {
        $$ = ast_new(NULL); // Criar nó genérico
        ast_add_child($$, $3);
        ast_add_child($$, $5);
    }
    ;

//##########################
// Definição expressões, compostas de operando e operador

expressao: operando 
         {
             $$ = $1;
         }
         ;

operando: operador
         | operando OR operador
         {
             $$ = ast_new(NULL); // Criar nó genérico
             ast_add_child($$, $1);
             ast_add_child($$, $3);
         }
         ;

//##########################
// Definição de termos
operador: comparacao
        | operador AND comparacao
        {
            $$ = ast_new(NULL); // Criar nó genérico
            ast_add_child($$, $1);
            ast_add_child($$, $3);
        }
        ;

//##########################
// Comparações
comparacao: adicaousub
          | comparacao op_comparacao adicaousub
          {
              $$ = ast_new(NULL); // Criar nó genérico
              ast_add_child($$, $1);
              ast_add_child($$, $3);
          }
          ;

//##########################
// Operadores de comparação
op_comparacao: LESSTHAN
			{
				 $$ = NULL;
			}
             | GREATERTHAN
			{
				 $$ = NULL;
			}
             | LESSEQUAL
			{
				 $$ = NULL;
			}
             | GREATEREQUAL
			{
				 $$ = NULL;
			}
             | EQUAL
			{
				 $$ = NULL;
			}
             | NOTEQUAL
			{
				 $$ = NULL;
			}
             ;

//##########################
// Adição ou subtração
adicaousub: multoudivoures
          | adicaousub op_adicaousub multoudivoures
          {
              $$ = ast_new(NULL); // Criar nó genérico
              ast_add_child($$, $1);
              ast_add_child($$, $3);
          }
          ;

//##########################
// Operação de adição e subtração
op_adicaousub: ADD
			 {
				$$ = NULL;
			 }
             | SUBTRACT
			 {
				$$ = NULL;
			 }
             ;

//##########################
// Multiplicação, divisão ou resto
multoudivoures: unario
              | multoudivoures op_multoudivoures unario
              {
                  $$ = ast_new(NULL); // Criar nó genérico
                  ast_add_child($$, $1);
                  ast_add_child($$, $3);
              }
              ;

//##########################
// Operação de multiplicação,divisão ou resto
op_multoudivoures: MULTIPLY
				 {
					 $$ = NULL;
			 	 }
                 | DIVIDE
				 {
					 $$ = NULL;
			 	 }
                 | REMAINDER
				 {
					 $$ = NULL;
			 	 }
                 ;

//##########################
// Operações unárias
unario: primario
      | INVERTSIG unario
	  {
		$$ = ast_new(NULL); // Criar nó genérico
        ast_add_child($$, $2);
	  }
      | NEGATE unario
      {
          $$ = ast_new(NULL); // Criar nó genérico
          ast_add_child($$, $2);
      }
      ;

//##########################
// Expressões primarias
primario: identificador
		{
			$$ = $1;
		}
        | literais
		{
			$$ = $1;
		}
        | chamada_funcao
		{
			$$ = $1;
		}
        | '(' expressao ')'
        {
            $$ = ast_new(NULL); // Criar nó genérico
            ast_add_child($$, $2);
        }
        ;

//##########################
// Chamada de função
chamada_funcao: nome_func '(' lista_expressao ')'
              {
                  $$ = ast_new(NULL); // Criar nó genérico
                  ast_add_child($$, $1);
                  ast_add_child($$, $3);
              }
              | nome_func '('/*vazio*/')'
              {
                  $$ = ast_new(NULL); // Criar nó genérico
                  ast_add_child($$, $1);
              }
              ;

//##########################
// Lista de expressões
lista_expressao: expressao
			   {
				 $$ = ast_new(NULL);
                 ast_add_child($$, $1);
			   }
               | lista_expressao ';' expressao
               {
                   $$ = $1;
                   ast_add_child($$, $3);
               }
               ;

//##########################
// Nome da função
nome_func: identificador
		 {
			$$ = $1;
		 }
         ;

//##########################
// Literais (tokens)
literais: LITINT 
        {
            $$ = $1;
        }
        | LITFLOAT 
        {
            $$ = $1;
        }
        | LITFALSE 
        {
            $$ = $1;
        }
        | LITTRUE 
        {
            $$ = $1;
        }
        ;

//##########################
// Token LITINT
LITINT: TK_LIT_INT
	  {
      		 $$ = ast_new($1);
      } 
      ;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT
		{
             $$ = ast_new($1);
        }
        ;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE 
		{
             $$ = ast_new($1);
        }
        ;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE 
	   {
        	 $$ = ast_new($1);
       }
       ;

//##########################
// Tokens de operadores
INVERTSIG: '-' 
         ;
NEGATE: '!' 
      ;
MULTIPLY: '*' 
        ;
DIVIDE: '/' 
      ;
REMAINDER: '%' 
         ;
ADD: '+' 
   ;
SUBTRACT: '-' 
        ;
GREATERTHAN: '>' 
           ;
LESSTHAN: '<' 
        ;
LESSEQUAL: TK_OC_LE 
         ;
GREATEREQUAL: TK_OC_GE 
            ;
EQUAL: TK_OC_EQ 
     ;
NOTEQUAL: TK_OC_NE 
        ;
AND: TK_OC_AND 
   ;

%%

//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d \n", s, get_line_number());
    return 1;
}

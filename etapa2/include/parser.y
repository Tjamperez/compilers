    /* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 000000 */

%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *mensagem);
%}

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
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO

%%

programa: lista_de_elementos | ;
lista_de_elementos: lista_de_elementos elemento | elemento ;
elemento: declaracao_global | /*definicao_de_funcao*/ ;
declaracao_global: tipo lista_identificador ',' ;
identificador: TK_IDENTIFICADOR ;
tipo: INT | FLOAT | BOOL ;
INT: TK_PR_INT ;
FLOAT: TK_PR_FLOAT ;
BOOL: TK_PR_BOOL ;
lista_identificador: lista_identificador ';' identificador | identificador ;
//definicao_de_funcao: cabecalho corpo ;
//cabecalho: '(' lista_de_parametros ')' OR tipo BARRA identificador ;
//lista_de_parametros: parametro ;
//lista_de_parametros:  lista_de_parametros ';' parametro  | ;
//parametro: tipo identificador ;
// corpo: bloco_de_comandos ;
// bloco_de_comandos: bloco_de_comandos comando_simples ',' | '{' '}' ;
// comando_simples: 
%%

void yyerror (char const *mensagem)
{
    printf("Erro: %s\n", mensagem);
}

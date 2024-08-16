    /* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 00302162 */

    /* Bozhe, spasi menya, potomu chto nikto drugoy ne mozhet. */

%define parse.error verbose

%code requires { #include "tree.h" }

%union {
  val_lex_t *valor_lexico;
  tree_node_t *tree;
}

%{
#include <stdlib.h>
#include <stdio.h>
#include "sym_stack.h"
#include "sym_table.h"
#include "tree.h"
#include "gen_code.h"
#include "gen_assembly.h"


// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);

int symbol_type_now; // Mantemos conta de quem é o tipo do símbolo no momento

extern char *yytext;
extern void *arvore;
stack_of_tables_t *stack_of_tables;
char* current_function_label;
int args_counter = 0;
int initial_space = 0;
int final_space = 0;
int current_opcode = 0;
char* main_label;
char assembly_code[OPCODE_SIZE_OF_BUFFER];

%}

%token  TK_PR_INT
%token  TK_PR_FLOAT
%token  TK_PR_BOOL
%token  TK_PR_IF
%token  TK_PR_ELSE
%token  TK_PR_WHILE
%token  TK_PR_RETURN
%token  TK_OC_LE
%token  TK_OC_GE
%token  TK_OC_EQ
%token  TK_OC_NE
%token  TK_OC_AND
%token  TK_OC_OR
%token  TK_ERRO

%token '='
%token '<'
%token '>'
%token '+'
%token '*'
%token '/'
%token '%'
%token '!'
%token '-'

%token <valor_lexico> TK_IDENTIFICADOR
%token <valor_lexico> TK_LIT_INT
%token <valor_lexico> TK_LIT_FLOAT
%token <valor_lexico> TK_LIT_FALSE
%token <valor_lexico> TK_LIT_TRUE

%type <tree> identificador_func
%type <tree> identificador
%type <tree> call_identificador
%type <tree> LITINT
%type <tree> LITFLOAT
%type <tree> LITTRUE
%type <tree> LITFALSE


%type <tree> criar_pilha
%type <tree> fechar_pilha
%type <tree> criar_escopo
%type <tree> criar_escopo_global
%type <tree> fechar_escopo

%type <tree> raiz
%type <tree> programa
%type <tree> lista_de_elementos
%type <tree> elemento
%type <tree> declaracao_global
%type <tree> definicao_de_funcao
%type <tree> lista_identificador
%type <tree> lista_identificador_local
%type <tree> tipo
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
%type <tree> comando_controle_fluxo
%type <tree> condicional
%type <tree> loop
%type <tree> expressao
%type <tree> operando
%type <tree> operador
%type <tree> greater_or_less
%type <tree> equal_or_not
%type <tree> adicaousub
%type <tree> op_adicaousub
%type <tree> multoudivoures
%type <tree> op_multoudivoures
%type <tree> unario
%type <tree> primario
%type <tree> chamada_funcao
%type <tree> lista_de_argumentos
%type <tree> nome_func
%type <tree> literais
%type <tree> comparacao_1
%type <tree> comparacao_2
%type <tree> INVERTSIG
%type <tree> NEGATE
%type <tree> MULTIPLY
%type <tree> DIVIDE
%type <tree> REMAINDER
%type <tree> ADD
%type <tree> SUBTRACT
%type <tree> GREATERTHAN
%type <tree> LESSTHAN
%type <tree> LESSEQUAL
%type <tree> GREATEREQUAL
%type <tree> EQUAL
%type <tree> NOTEQUAL
%type <tree> AND
%type <tree> OR
%type <tree> INT
%type <tree> FLOAT
%type <tree> BOOL
%type <tree> RETURN
%type <tree> IF
%type <tree> WHILE
%type <tree> ELSE

%%
//##########################
raiz: criar_pilha criar_escopo_global programa fechar_escopo fechar_pilha
{
    fprintf(stderr, "Debug: Entrou em raiz\n");
    $$ = $3;
    if ($3 != NULL) {
        char* reg = allocate_register();
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg);  // Use movq for 64-bit registers
        append_assembly_code(global_code_list, assembly_code);
        free_register(reg); // Remember to free the register after use
    }
    print_all_assembly(global_code_list);
    arvore = $$;
    fprintf(stderr, "Debug: Saindo de raiz\n");
}
;

//##########################
// Definição de programa
programa: lista_de_elementos
{
    fprintf(stderr, "Debug: Entrou em programa com lista_de_elementos\n");
    $$ = $1;
    if ($1 != NULL) {
        char* reg = allocate_register();
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
        append_assembly_code(global_code_list, assembly_code);
        free_register(reg); // Free the register after use
    }
    fprintf(stderr, "Debug: Saindo de programa com lista_de_elementos\n");
}
| /* vazio */
{
    fprintf(stderr, "Debug: Entrou em programa vazio\n");
    $$ = NULL; // Se não houver elementos, o programa é nulo
    arvore = NULL;
    fprintf(stderr, "Debug: Saindo de programa vazio\n");
}
;

//##########################
// Lista de elementos
lista_de_elementos: elemento lista_de_elementos
{
    fprintf(stderr, "Debug: Entrou em lista_de_elementos com 2 elementos\n");
    if ($1 == NULL) {
        $$ = $2;
    } else {
        if ($2 == NULL) {
            $$ = $1;
        } else {
            $$ = $1;
            ast_add_child($$, $2);
        }
    }

    if ($$ != NULL) {
        if ($1 != NULL && $1->temp != NULL) {

            char* reg = allocate_register();
            snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
            append_assembly_code(global_code_list, assembly_code);
            free_register(reg);
        }
        if ($2 != NULL && $2->temp != NULL) {
            char* reg = allocate_register();
            snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg);  // Use movq for 64-bit registers
            append_assembly_code(global_code_list, assembly_code);
            free_register(reg);
        }
    }
    fprintf(stderr, "Debug: Saindo de lista_de_elementos com 2 elementos\n");
}
| elemento
{
    fprintf(stderr, "Debug: Entrou em lista_de_elementos com 1 elemento\n");
    $$ = $1;
    if ($$ != NULL && $1->temp != NULL) {
        char* reg = allocate_register();
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
        append_assembly_code(global_code_list, assembly_code);
        free_register(reg);
    }
    fprintf(stderr, "Debug: Saindo de lista_de_elementos com 1 elemento\n");
}
;

//##########################
// Elemento do programa
elemento: declaracao_global
{
    fprintf(stderr, "Debug: Entrou em elemento declaracao_global\n");
    $$ = $1;
    if ($$ != NULL) {
        char* reg = allocate_register();
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
        append_assembly_code(global_code_list, assembly_code);
        free_register(reg);
    }
    fprintf(stderr, "Debug: Saindo de elemento declaracao_global\n");
}
| definicao_de_funcao
{
    fprintf(stderr, "Debug: Entrou em elemento definicao_de_funcao\n");
    $$ = $1;
    if ($$ != NULL) {
        char* reg = allocate_register();
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
        append_assembly_code(global_code_list, assembly_code);
        free_register(reg);
    }
    fprintf(stderr, "Debug: Saindo de elemento definicao_de_funcao\n");
}
;

//##########################
// Declaração global de variável
declaracao_global: tipo lista_identificador ','
{
    fprintf(stderr, "Debug: Entrou em declaracao_global\n");
    $$ = NULL; // Não há ações associadas à declaração global
    fprintf(stderr, "Debug: Saindo de declaracao_global\n");
}
;

//##########################
// Identificador
identificador: TK_IDENTIFICADOR
{
    fprintf(stderr, "Debug: Entrou em identificador\n");
    $$ = ast_new($1); // Cria um novo nó na árvore com o identificador
    fprintf(stderr, "Debug: Saindo de identificador\n");
}
;

//##########################
// Identificador para pegar nome da função e inserir na tabela global
identificador_func: TK_IDENTIFICADOR
{
    fprintf(stderr, "Debug: Entrou em identificador_func\n");
    $$ = ast_new($1); // Cria um novo nó na árvore com o identificador

    char *new_key = strdup($$->valor_lexico->token_value);

    if(find_symbol(stack_of_tables->tables[0], new_key) != NULL) {
        printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }

    current_function_label = generate_label();

    insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($$,TOKEN_NATURE_FUNCTION, symbol_type_now, strdup(current_function_label)));
    
    if (!strcmp(new_key, "main")) {
        initial_space = 0;
        final_space = 0;
    } else {
        initial_space = 12;
        final_space = 4;
    }
    fprintf(stderr, "Debug: Saindo de identificador_func\n");
}
;

call_identificador: TK_IDENTIFICADOR
{
    fprintf(stderr, "Debug: Entrou em call_identificador\n");
    $$ = ast_new_call_func($1); // Cria um novo nó representando uma chamada de função com o identificador
    fprintf(stderr, "Debug: Saindo de call_identificador\n");
}
;

//##########################
// Tipos de dados
tipo: INT
{
    fprintf(stderr, "Debug: Entrou em tipo INT\n");
    $$ = $1;
    symbol_type_now = TYPE_INT;
    fprintf(stderr, "Debug: Saindo de tipo INT\n");
}
| FLOAT
{
    fprintf(stderr, "Debug: Entrou em tipo FLOAT\n");
    $$ = $1;
    symbol_type_now = TYPE_FLOAT;
    fprintf(stderr, "Debug: Saindo de tipo FLOAT\n");
}
| BOOL
{
    fprintf(stderr, "Debug: Entrou em tipo BOOL\n");
    $$ = $1;
    symbol_type_now = TYPE_BOOL;
    fprintf(stderr, "Debug: Saindo de tipo BOOL\n");
}
;

//##########################
// Token INT
INT: TK_PR_INT
{
    fprintf(stderr, "Debug: Entrou em INT\n");
    $$ = NULL; // Espero que seja null mesmo.
    fprintf(stderr, "Debug: Saindo de INT\n");
}
;

//##########################
// Token FLOAT
FLOAT: TK_PR_FLOAT
{
    fprintf(stderr, "Debug: Entrou em FLOAT\n");
    $$ = NULL; // Espero que seja null mesmo.
    fprintf(stderr, "Debug: Saindo de FLOAT\n");
}
;

//##########################
// Token BOOL
BOOL: TK_PR_BOOL
{
    fprintf(stderr, "Debug: Entrou em BOOL\n");
    $$ = NULL; // Espero que seja null mesmo.
    fprintf(stderr, "Debug: Saindo de BOOL\n");
}
;

//##########################
// Lista de identificadores
lista_identificador: lista_identificador ';' identificador
{
    fprintf(stderr, "Debug: Entrou em lista_identificador com 2 elementos\n");
    $$ = $1; // Se houver uma lista de identificadores existente nós as mantemos
    char* new_key = strdup($3->valor_lexico->token_value);
    if(find_symbol(stack_of_tables->top, new_key) != NULL) {
        printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }
    insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($3,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
    fprintf(stderr, "Debug: Saindo de lista_identificador com 2 elementos\n");
}
| identificador
{
    fprintf(stderr, "Debug: Entrou em lista_identificador com 1 elemento\n");
    $$ = $1;
    char* new_key = strdup($1->valor_lexico->token_value);
    if(find_symbol(stack_of_tables->top, new_key) != NULL) {
        printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }
    insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($1,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
    fprintf(stderr, "Debug: Saindo de lista_identificador com 1 elemento\n");
}
;

//##########################
// Definição de função
definicao_de_funcao: cabecalho corpo fechar_escopo
{
    fprintf(stderr, "Debug: Entrou em definicao_de_funcao\n");
    $$ = $1; // Define a definição de função como o cabeçalho
    if ($2 != NULL) {
        ast_add_child($$, $2); // Se houver corpo, adiciona o corpo como filho da definição de função

        char *reg1 = allocate_register();
        char *reg2 = allocate_register();

        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
        append_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg2);
        append_assembly_code(global_code_list, assembly_code);

        $$->temp = strdup(reg1);
        
        free_register(reg1);
        free_register(reg2);
    } else {
        char *reg1 = allocate_register();

        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
        append_assembly_code(global_code_list, assembly_code);

        $$->temp = strdup(reg1);

        free_register(reg1);
    }
    fprintf(stderr, "Debug: Saindo de definicao_de_funcao\n");
}
;


//##########################
// Cabeçalho da função
cabecalho:   criar_escopo '(' lista_de_parametros ')' OR tipo '/' identificador_func
{
    fprintf(stderr, "Debug: Entrou em cabecalho\n");
    $$ = $8; // Define o cabeçalho como o identificador

    char* identifier_key = strdup($8->valor_lexico->token_value);
    char* function_label = current_function_label;

    if (strcmp(identifier_key, "main") == 0) {
        main_label = strdup(function_label);
    }

    snprintf(assembly_code, sizeof(assembly_code), "%s:", function_label);
    append_assembly_code(global_code_list, assembly_code);

    // Function prologue for non-main functions
    if (strcmp(identifier_key, "main") != 0) {
        snprintf(assembly_code, sizeof(assembly_code), "push %%rbp");
        append_assembly_code(global_code_list, assembly_code);
        snprintf(assembly_code, sizeof(assembly_code), "mov %%rsp, %%rbp");
        append_assembly_code(global_code_list, assembly_code);
    }

    // Adjust stack space for local variables
    snprintf(assembly_code, sizeof(assembly_code), "sub $%d, %%rsp", initial_space + stack_of_tables->top->current_address_displacement + final_space);
    append_assembly_code(global_code_list, assembly_code);
    fprintf(stderr, "Debug: Saindo de cabecalho\n");
}
;

//##########################
// Criar novo scope
criar_escopo_global: 
{
    fprintf(stderr, "Debug: Entrou em criar_escopo_global\n");
    $$ = NULL;
    table_of_symbols_t *new_scope = create_table_of_symbols_global(stack_of_tables->top,true);
    push_scope(stack_of_tables,new_scope);
    assembly_code_list_t* global_code_list = create_assembly_code_list();
    init_register_pool();

    table_of_symbols_t* global_table = stack_of_tables->tables[0];

    char* function_name = "main";

    if (function_name == NULL) {
    fprintf(stderr, "Error: function_name is NULL\n");
    exit(EXIT_FAILURE);
    }

    snprintf(assembly_code, sizeof(assembly_code), ".globl %s", function_name);

    if (global_code_list == NULL) {
    fprintf(stderr, "Error: global_code_list is NULL\n");
    exit(EXIT_FAILURE);
    }

    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), ".type %s, @function", function_name);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "%s:", function_name);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "push %%rbp");
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "mov %%rsp, %%rbp");
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "sub $16, %%rsp");
    append_assembly_code(global_code_list, assembly_code);


    for (int i = 0; i < global_table->size; i++) {
        symbol_t* symbol = global_table->items[i]->content;

        if (symbol->nature == 1) {

            snprintf(assembly_code, sizeof(assembly_code), ".globl %s", symbol->label);
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), ".data");
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), ".align 4");
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), ".type %s, @object", symbol->label);
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), ".size %s, %d", symbol->label, 4);
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), "%s:", symbol->label);
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), ".zero 4");
        }
    }
    fprintf(stderr, "Debug: Saindo de criar_escopo_global\n");

}
;

criar_escopo: 
{
    fprintf(stderr, "Debug: Entrou em criar_escopo\n");
    $$ = NULL;
    table_of_symbols_t *new_scope = create_table_of_symbols(stack_of_tables->top,false);
    push_scope(stack_of_tables,new_scope);
    fprintf(stderr, "Debug: Saindo de criar_escopo\n");
}
;

//##########################
// Fechar Escopo
fechar_escopo: 
{
    fprintf(stderr, "Debug: Entrou em fechar_escopo\n");
    $$ = NULL;
    pop_scope(stack_of_tables);
    fprintf(stderr, "Debug: Saindo de fechar_escopo\n");
}
;		   

//##########################
// Criar primeira pilha
criar_pilha:
{   
    fprintf(stderr, "Debug: Entrou em criar_pilha\n");
    $$ = NULL;
    stack_of_tables = create_stack_of_tables();
    fprintf(stderr, "Debug: Saindo de criar_pilha\n");
}
;

//##########################
// Fechar primeira pilha
fechar_pilha:
{   
    fprintf(stderr, "Debug: Entrou em fechar_pilha\n");
    $$ = NULL;
    generate_epilogue();
    free_stack_of_tables(stack_of_tables);
    fprintf(stderr, "Debug: Saindo de fechar_pilha\n");
}
;

//##########################
// Token OR
OR: TK_OC_OR
{
    fprintf(stderr, "Debug: Entrou em OR\n");
    $$ = ast_new_label_only("|");
    fprintf(stderr, "Debug: Saindo de OR\n");
}
;

//##########################
// Lista de parâmetros
lista_de_parametros: lista_de_parametros ';' parametro
{
    fprintf(stderr, "Debug: Entrou em lista_de_parametros com 2 parâmetros\n");
    if ($1 == NULL){ // Se não houver parâmetros existentes
        $$ = $3; // O resultado é o parâmetro atual
    }
    else 
    {
        if ($3 == NULL) // Se não houver mais parâmetros
        {
            $$ = $1; // O resultado é a lista de parâmetros existentes
        }
        else 
        {
             $$ = $1; // O resultado é a lista de parâmetros existentes
        }
    }
    fprintf(stderr, "Debug: Saindo de lista_de_parametros com 2 parâmetros\n");
}
| parametro
{
    fprintf(stderr, "Debug: Entrou em lista_de_parametros com 1 parâmetro\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de lista_de_parametros com 1 parâmetro\n");
}
| /* vazio */ // Se não houver parâmetros
{
    fprintf(stderr, "Debug: Entrou em lista_de_parametros vazio\n");
    $$ = NULL;
    fprintf(stderr, "Debug: Saindo de lista_de_parametros vazio\n");
}
;
                   

//##########################
// Parâmetro da função
parametro: tipo identificador // Define o parâmetro como um tipo e um identificador
{
    fprintf(stderr, "Debug: Entrou em parametro\n");
    $$ = $1;
    ast_add_child($$, $2);
    char *new_key = strdup($2->valor_lexico->token_value);
    if(find_symbol(stack_of_tables->top, new_key) != NULL)
    {
        printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }
    insert_symbol(stack_of_tables->top, new_key, create_symbol($2,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
    fprintf(stderr, "Debug: Saindo de parametro\n");
}
;

//##########################
// Corpo da função
corpo: '{' bloco_de_comandos '}' // Define o corpo como um bloco de comandos dentro de chaves
{
    fprintf(stderr, "Debug: Entrou em corpo\n");
    $$ = $2;
    fprintf(stderr, "Debug: Saindo de corpo\n");
}
| corpo'{' bloco_de_comandos '}'
{
    fprintf(stderr, "Debug: Entrou em corpo com bloco de comandos\n");
    $$ = $1;
    ast_add_child($$, $3);
    fprintf(stderr, "Debug: Saindo de corpo com bloco de comandos\n");
}
;
	 
//##########################
// Bloco de Comandos que aceita vazio
bloco_de_comandos: /* vazio */ // Se o bloco de comandos estiver vazio
{
    fprintf(stderr, "Debug: Entrou em bloco_de_comandos vazio\n");
    $$ = NULL;
    fprintf(stderr, "Debug: Saindo de bloco_de_comandos vazio\n");
}
| lista_de_comandos // Se houver uma lista de comandos
{
    fprintf(stderr, "Debug: Entrou em bloco_de_comandos com lista_de_comandos\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de bloco_de_comandos com lista_de_comandos\n");
}
;

//##########################
// Definição de lista de comandos simples
lista_de_comandos: comando_simples ','  // Se houver apenas um comando simples
{
    fprintf(stderr, "Debug: Entrou em lista_de_comandos com 1 comando\n");
    $$ = $1; // O resultado é o comando simples
    fprintf(stderr, "Debug: Saindo de lista_de_comandos com 1 comando\n");
}
| comando_simples ',' lista_de_comandos // Se houver mais de um comando simples
{
    fprintf(stderr, "Debug: Entrou em lista_de_comandos com mais de 1 comando\n");
    if ($3 == NULL)  // Se não houver mais comandos na lista
    {
        $$ = $1; // O resultado é o primeiro comando simples
    }
    else
    {
        if ($1 == NULL)  // Se não houver mais comandos na lista
        {
            $$ = $3;  // O resultado é a lista restante de comandos
        }
        else
        {
            $$ = $1; // O resultado é o primeiro comando simples
            ast_add_child($1, $3); // Adiciona a lista restante de comandos como filho do primeiro comando simples

            char* reg1 = allocate_register();
            char* reg2 = allocate_register();

            snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
            append_assembly_code(global_code_list, assembly_code);

            snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
            append_assembly_code(global_code_list, assembly_code);

            free_register(reg1);
            free_register(reg2);
        }
    } 	
    fprintf(stderr, "Debug: Saindo de lista_de_comandos com mais de 1 comando\n");
}
;

//##########################
// Definição de comando simples
comando_simples: declaracao_variavel
{
    fprintf(stderr, "Debug: Entrou em comando_simples declaracao_variavel\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de comando_simples declaracao_variavel\n");
}
| comando_atribuicao
{
    fprintf(stderr, "Debug: Entrou em comando_simples comando_atribuicao\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de comando_simples comando_atribuicao\n");
}
| chamada_funcao
{
    fprintf(stderr, "Debug: Entrou em comando_simples chamada_funcao\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de comando_simples chamada_funcao\n");
}
| comando_retorno
{
    fprintf(stderr, "Debug: Entrou em comando_simples comando_retorno\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de comando_simples comando_retorno\n");
}
| comando_controle_fluxo
{
    fprintf(stderr, "Debug: Entrou em comando_simples comando_controle_fluxo\n");
    $$ = $1;
    fprintf(stderr, "Debug: Saindo de comando_simples comando_controle_fluxo\n");
}
| criar_escopo corpo fechar_escopo
{
    fprintf(stderr, "Debug: Entrou em comando_simples criar_escopo corpo fechar_escopo\n");
    $$ = $2;
    fprintf(stderr, "Debug: Saindo de comando_simples criar_escopo corpo fechar_escopo\n");
}
;

//##########################
// Declaração de variável
declaracao_variavel: tipo lista_identificador_local
{
    fprintf(stderr, "Debug: Entrou em declaracao_variavel\n");
    $$ = NULL;
    fprintf(stderr, "Debug: Saindo de declaracao_variavel\n");
}
;

//##########################
// Lista de identificadores locais
lista_identificador_local: lista_identificador_local ';' identificador
{
    fprintf(stderr, "Debug: Entrou em lista_identificador_local com 2 elementos\n");
    $$ = $1; // Se houver uma lista de identificadores existente nós as mantemos
    char* new_key = strdup($3->valor_lexico->token_value);
    if(find_symbol(stack_of_tables->top, new_key) != NULL){
        printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
        exit(ERR_DECLARED);
     }
    insert_symbol(stack_of_tables->top, new_key, create_symbol($3,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
    fprintf(stderr, "Debug: Saindo de lista_identificador_local com 2 elementos\n");
}
| identificador
{
    fprintf(stderr, "Debug: Entrou em lista_identificador_local com 1 elemento\n");
    $$ = $1;
    char* new_key = strdup($1->valor_lexico->token_value);
  
    if(find_symbol(stack_of_tables->top, new_key) != NULL){
        printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }
    insert_symbol(stack_of_tables->top, new_key, create_symbol($1,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
    fprintf(stderr, "Debug: Saindo de lista_identificador_local com 1 elemento\n");
}
;

//##########################
// Comando de atribuição
comando_atribuicao: identificador '=' expressao 
{
    $$ = ast_new_label_only("=");
    ast_add_child($$, $1); // Add the identifier as a child of the node
    ast_add_child($$, $3); // Add the expression as a child of the node

    char* new_key = $1->valor_lexico->token_value;
    symbol_t* result = search_symbol_stack(stack_of_tables, new_key);
    table_of_symbols_t* current_scope = search_stack_for_address(stack_of_tables, new_key);

    if (result == NULL) {
        printf("[ERR_UNDECLARED] Var [%s] na linha %d nao foi declarada\n", new_key, get_line_number());
        exit(ERR_UNDECLARED);
    } else {
        int nature = result->nature;
        $$->node_type = result->data_type;

        if (nature == TOKEN_NATURE_FUNCTION) {
            printf("[ERR_VARIABLE] Funcao [%s] na linha %d esta sendo usada como variavel\n", new_key, get_line_number());
            exit(ERR_FUNCTION);
        }

        int address = result->address_displacement;
        char* reg = allocate_register();
        char* base_reg;

        // Different handling for global and local variables
        if (current_scope->is_global) {
            base_reg = "rip";
            snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s(%%%s)", $3->temp, new_key, base_reg);
        } else {
            base_reg = "rbp";
            snprintf(assembly_code, sizeof(assembly_code), "movq %s, %d(%%rbp)", $3->temp, address + initial_space);
        }

        append_assembly_code(global_code_list, assembly_code);
        $$->temp = strdup(reg);

        free_register(reg);
    }
}
;

//##########################
// Comando de retorno
RETURN: TK_PR_RETURN
{
    $$ = ast_new_label_only("return"); // Cria um novo nó com o rótulo "return"
}
;
comando_retorno: RETURN expressao
{
    fprintf(stderr, "Debug: Entrou em comando_retorno\n");

    char* reg1 = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %%rax", reg1);
    append_assembly_code(global_code_list, assembly_code);

    generate_epilogue();

    free_register(reg1);

    $$->temp = strdup(reg1);

    fprintf(stderr, "Debug: Saindo de comando_retorno\n");
}
;

//##########################
// Comando de controle de fluxo
comando_controle_fluxo: condicional
{
    $$ = $1;
}
| loop
{
    $$ = $1;
}
;
//##########################
// Comando de if e else
IF: TK_PR_IF
{
    $$ = ast_new_label_only("if"); // Cria um novo nó com o rótulo "if"
}
;
ELSE: TK_PR_ELSE
{
    $$ = NULL; // Cria um novo nó com o rótulo "else"
}
;
condicional: IF '(' expressao ')' criar_escopo corpo fechar_escopo
{

    fprintf(stderr, "Debug: Entrou em condicional\n");

    $$ = $1; // Define a condicional como o nó "if"
    ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
    ast_add_child($$, $5); // Adiciona o corpo como filho do nó "if"
    $$->node_type = $3->node_type;

    char* true_label = generate_label();
    char* false_label = generate_label();

    char *reg1 = allocate_register();
    char *reg2 = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);
    snprintf(assembly_code, sizeof(assembly_code), "movq $0, %s", reg2);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "cmpq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "je %s", false_label);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "%s:", true_label);
    append_assembly_code(global_code_list, assembly_code);

    if ($6 != NULL) {
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $6->temp, reg1);
        append_assembly_code(global_code_list, assembly_code);
    }

    snprintf(assembly_code, sizeof(assembly_code), "%s:", false_label);
    append_assembly_code(global_code_list, assembly_code);

    free_register(reg1);
    free_register(reg2);
    $$->temp = strdup(reg1);

    fprintf(stderr, "Debug: Saindo de condicional\n");

}
| IF '(' expressao ')' criar_escopo corpo fechar_escopo ELSE criar_escopo corpo fechar_escopo
{
    fprintf(stderr, "Debug: Entrando em condicional\n");


    $$ = $1;
    ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
    ast_add_child($$, $5); // Adiciona o corpo do "if" como filho do nó "if"
    ast_add_child($$, $7); // Adiciona o nó "else" como filho do nó "if"
    $$->node_type = $3->node_type;

    char* true_label = generate_label();
    char* false_label = generate_label();
    char* after_label = generate_label();

    char *reg1 = allocate_register();
    char *reg2 = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);
    snprintf(assembly_code, sizeof(assembly_code), "movq $0, %s", reg2);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "cmpq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "je %s", false_label);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "%s:", true_label);
    append_assembly_code(global_code_list, assembly_code);

    if ($6 != NULL) {
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $6->temp, reg1);
        append_assembly_code(global_code_list, assembly_code);
    }

    snprintf(assembly_code, sizeof(assembly_code), "jmp %s", after_label);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "%s:", false_label);
    append_assembly_code(global_code_list, assembly_code);

    if ($10 != NULL) {
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $10->temp, reg1);
        append_assembly_code(global_code_list, assembly_code);
    }

    snprintf(assembly_code, sizeof(assembly_code), "%s:", after_label);
    append_assembly_code(global_code_list, assembly_code);

    free_register(reg1);
    free_register(reg2);
    $$->temp = strdup(reg1);

    fprintf(stderr, "Debug: Saindo de condicional\n");

}
;

//##########################
// Comando de loop
WHILE: TK_PR_WHILE 
{
    $$ = ast_new_label_only("while"); // Cria um novo nó com o rótulo "while"
}
;
loop: WHILE '(' expressao ')' criar_escopo corpo fechar_escopo
{
    fprintf(stderr, "Debug: Entrando em loop\n");


    $$ = $1;
    ast_add_child($$, $3); // Adiciona a expressão como filho do nó "while"
    ast_add_child($$, $5); // Adiciona o corpo como filho do nó "while"
    $$->node_type = $3->node_type;

    char* loop_label = generate_label();
    char* true_label = generate_label();
    char* false_label = generate_label();

    char* reg1 = allocate_register(); 
    char* reg2 = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "%s:", loop_label);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);
    snprintf(assembly_code, sizeof(assembly_code), "movq $0, %s", reg2);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "cmpq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "je %s", false_label);
    append_assembly_code(global_code_list, assembly_code);
   
    snprintf(assembly_code, sizeof(assembly_code), "%s:", true_label);
    append_assembly_code(global_code_list, assembly_code);

    if ($6 != NULL) {
        snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $6->temp, reg1);
        append_assembly_code(global_code_list, assembly_code);
    }

    snprintf(assembly_code, sizeof(assembly_code), "jmp %s", loop_label);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "%s:", false_label);
    append_assembly_code(global_code_list, assembly_code);

    free_register(reg1);
    free_register(reg2);
    $$->temp = strdup(reg1);

    fprintf(stderr, "Debug: Saindo de loop\n");


}
;

//##########################
// Expressões

expressao: operando
{
    $$ = $1;
    //printf("Added operando to expressao\n"); // Debug print
}
;

//##########################
// Operandos

operando: operador
{
    $$ = $1;
    //printf("Added operador to operando\n"); // Debug print
}
| operando OR operador
{
    fprintf(stderr, "Debug: Entrou em OP\n");
    $$ = $2;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);
    //printf("Added operando and operador to operando\n"); // Debug print

    char* assembly_code = (char*)malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
    char* reg1 = allocate_register();
    char* reg2 = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "orq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(reg1);

    free_register(reg2);
}
;

//##########################
// Operadores

operador: comparacao_1
{
    $$ = $1;
    //printf("Added comparacao to operador\n"); // Debug print
}
| operador AND comparacao_1
{

    fprintf(stderr, "Debug: Entrou em comp1\n");
    $$ = $2;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);
    //printf("Added operador and comparacao to operador\n"); // Debug print

    char* assembly_code = (char*)malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
    char* reg1 = allocate_register();
    char* reg2 = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "andq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(reg1);

    free_register(reg2);
}
;

//##########################
// Comparações NOTEQUAL e EQUAL

comparacao_1: comparacao_2
{
    $$ = $1;
    //printf("Added comparacao_1 to comparacao_2\n"); // Debug print
}
| comparacao_1 equal_or_not comparacao_2
{
    fprintf(stderr, "Debug: Entrou em comp2\n");
    $$ = $2;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    char* reg1 = allocate_register();
    char* reg2 = allocate_register();
    char* result_reg = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);
    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
    append_assembly_code(global_code_list, assembly_code);

    char* current_opcode = $2->valor_lexico->token_value;

    snprintf(assembly_code, sizeof(assembly_code), "cmpq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    if (strcmp(current_opcode, "CMP_EQ") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "sete %%al");
    } else if (strcmp(current_opcode, "CMP_NE") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "setne %%al");
    }
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movzbq %%al, %s", result_reg);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(result_reg);

    free_register(reg1);
    free_register(reg2);
    // result_reg is still in use in $$->temp, so don't free it
}
;

equal_or_not:  EQUAL
{
    $$ = $1;
    //printf("Added EQUAL to op_adicaousub\n"); // Debug print
}
| NOTEQUAL
{
    $$ = $1;
    //printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
}
;

//##########################
// Comparações de GREATEREQUAL, LESSEQUAL, GREATERTHAN, LESSTHAN

comparacao_2: adicaousub
{
    $$ = $1;
    //printf("Added adicaousub to comparacao_2\n"); // Debug print
}
| comparacao_2 greater_or_less adicaousub
{
    $$ = $2;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    char* reg1 = allocate_register();
    char* reg2 = allocate_register();
    char* result_reg = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);
    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "cmpq %s, %s", reg2, reg1);
    append_assembly_code(global_code_list, assembly_code);

    char* current_opcode = $2->valor_lexico->token_value;

    if (strcmp(current_opcode, "CMP_GE") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "setge %%al");
    } else if (strcmp(current_opcode, "CMP_LE") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "setle %%al");
    } else if (strcmp(current_opcode, "CMP_GT") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "setg %%al");
    } else if (strcmp(current_opcode, "CMP_LT") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "setl %%al");
    }
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movzbq %%al, %s", result_reg);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(result_reg);

    free_register(reg1);
    free_register(reg2);
    // result_reg is still in use in $$->temp, so don't free it
}
;

greater_or_less:  GREATEREQUAL
{
    $$ = $1;
    //printf("Added EQUAL to op_adicaousub\n"); // Debug print
}
| 	LESSEQUAL
{
$$ = $1;
    //printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
}
|  GREATERTHAN
{
$$ = $1;
    //printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
}
|  LESSTHAN
{
$$ = $1;
    //printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
}
;

//##########################
// Adição ou subtração

adicaousub: multoudivoures
{
    $$ = $1;
    //printf("Added multoudivoures to adicaousub\n"); // Debug print
}
| adicaousub op_adicaousub multoudivoures
{
    $$ = $2;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    char* reg1 = allocate_register();
    char* reg2 = allocate_register();
    char* result_reg = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
    append_assembly_code(global_code_list, assembly_code);

    char* current_opcode = $2->valor_lexico->token_value;

    if (strcmp(current_opcode, "+") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "addq %s, %s", reg2, reg1);
    } else if (strcmp(current_opcode, "-") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "subq %s, %s", reg2, reg1);
    }
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(reg1);

    free_register(reg2);
}
;

//##########################
// Operação de adição e subtração
op_adicaousub: ADD
{
    $$ = $1;;
    //printf("Added ADD to op_adicaousub\n"); // Debug print
}
| SUBTRACT
{
    $$ = $1;
    //printf("Added SUBTRACT to op_adicaousub\n"); // Debug print
}
;

//##########################
// Multiplicação, divisão ou resto

multoudivoures: unario
{
    $$ = $1;
    //printf("Added unario to multoudivoures\n"); // Debug print
}
| multoudivoures op_multoudivoures unario
{
    $$ = $2;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    char* reg1 = allocate_register();
    char* reg2 = allocate_register();
    char* result_reg = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
    append_assembly_code(global_code_list, assembly_code);

    char* current_opcode = $2->valor_lexico->token_value;

    if (strcmp(current_opcode, "*") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "imulq %s, %s", reg2, reg1);
    } else if (strcmp(current_opcode, "/") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "cqto");
        append_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "idivq %s", reg2);
    }
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(reg1);

    free_register(reg2);
}
;

//##########################
// Operação de multiplicação,divisão ou resto
op_multoudivoures: MULTIPLY
{
    $$ = $1;
    //printf("Added MULTIPLY to op_multoudivoures\n"); // Debug print
}
| DIVIDE
{
    $$ = $1;
    //printf("Added DIVIDE to op_multoudivoures\n"); // Debug print
}
| REMAINDER
{
    $$ = $1;
    //printf("Added REMAINDER to op_multoudivoures\n"); // Debug print
}
;

//##########################
// Operações unárias

unario: primario
{
    $$ = $1;
    //printf("Added primario to unario\n"); // Debug print
}
| INVERTSIG unario
{
    $$ = $1;
    ast_add_child($$, $2);
    $$->node_type = $2->node_type;

    char* reg = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "negq %s", reg);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(reg);

}
| NEGATE unario
{
    $$ = $1;
    ast_add_child($$, $2);
    $$->node_type = $2->node_type;

    char* reg = allocate_register();

    snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "xorq $1, %s", reg);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = strdup(reg);
}
;

//##########################
// Expressões primárias

primario: identificador
{
    $$ = $1;
    
    char* new_key = $1->valor_lexico->token_value;
    symbol_t* result = search_symbol_stack(stack_of_tables, new_key);
    table_of_symbols_t* current_scope = search_stack_for_address(stack_of_tables, new_key);

    if (result) {
        int address = result->address_displacement;

        char* reg = allocate_register();
        char* base_reg = current_scope->is_global ? "%rbss" : "%rbp";

        snprintf(assembly_code, sizeof(assembly_code), "movq %d(%s), %s", address + initial_space, base_reg, reg);
        append_assembly_code(global_code_list, assembly_code);

        $$->temp = strdup(reg);
    }

    if (result == NULL) {
        printf("[ERR_UNDECLARED] Var [%s] na linha %d nao foi declarada\n", new_key, get_line_number());
        exit(ERR_UNDECLARED);
    } else {
        int nature = result->nature;
        $$->node_type = result->data_type;

        if (nature == TOKEN_NATURE_FUNCTION) {
            printf("[ERR_VARIABLE] Funcao [%s] na linha %d esta sendo usada como variavel\n", new_key, get_line_number());
            exit(ERR_FUNCTION);
        }
    }
}
| literais
{
    $$ = $1;
    //printf("Added literais to primario\n"); // Debug print
}
| chamada_funcao
{
    $$ = $1;
    //printf("Added chamada_funcao to primario\n"); // Debug print
}
| '(' expressao ')' 
{
    $$ = $2;
    $$->node_type = $2->node_type;
    //printf("Added expressao to primario\n"); // Debug print
}
;

//##########################
// Chamada de função
chamada_funcao: nome_func '(' lista_de_argumentos ')'
{
    //fprintf(stderr, "Debug message chamada_funcao: nome_func '(' lista_de_argumentos ')'\n");
    $$ = $1;
    ast_add_child($$, $3);
    char *new_key = $1->valor_lexico->token_value;

    char *parsed_key = ast_parse_function_call(new_key);

    symbol_t* result = search_symbol_stack(stack_of_tables, parsed_key);
    if(result == NULL)
    {
        printf("[ERR_UNDECLARED] Funcao [%s] na linha %d nao foi declarada\n", parsed_key, get_line_number());
        exit(ERR_UNDECLARED);
    }
    //printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
    else
    {
        int nature = result->nature;
        //printf("Nature: [%d]\n\n", nature);
        $$->node_type = result->data_type;
        if(nature == TOKEN_NATURE_IDENTIFIER){
            printf("[ERR_FUNCTION] Variavel [%s] na linha %d esta sendo usada como funcao\n", parsed_key, get_line_number());
            exit(ERR_VARIABLE);
        }
    }
    }
    | nome_func '('/*vazio*/')'
    {
    //fprintf(stderr, "Debug message chamada_funcao:  nome_func '('/*vazio*/')'\n");
    $$ = $1;
    //printf("Added nome_func to chamada_funcao\n"); // Debug print
    char *new_key = $1->valor_lexico->token_value;

    char *parsed_key = ast_parse_function_call(new_key);

    symbol_t* result = search_symbol_stack(stack_of_tables, parsed_key);
    if(result == NULL)
    {
        printf("[ERR_UNDECLARED] Funcao [%s] na linha %d nao foi declarada\n", parsed_key, get_line_number());
        exit(ERR_UNDECLARED);
    }
    //printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
    else
    {
        int nature = result->nature;
        //printf("Nature: [%d]\n\n", nature);
        $$->node_type = result->data_type;
        if(nature == TOKEN_NATURE_IDENTIFIER){
            printf("[ERR_FUNCTION] Variavel [%s] na linha %d esta sendo usada como funcao\n", parsed_key, get_line_number());
            exit(ERR_VARIABLE);
        }
    }
}
;

//##########################
// Lista de expressões
lista_de_argumentos: expressao
{
    //fprintf(stderr, "Before appending express: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
    //fprintf(stderr, "Debug message lista_de_argumentos: expressao\n");
    $$ = $1;
    //fprintf(stderr, "After appending express: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
    //printf("Added expressao to lista_de_argumentos\n"); // Debug print
}
|  expressao ';'  lista_de_argumentos
{
    if ($3 == NULL)
    {
        //fprintf(stderr, "Debug lista_de_argumentos: expressao ';'  lista_de_argumentos;\n");
        $$ = $1; 
    }
    else
    {
        if ($1 == NULL)
        {
            //fprintf(stderr, "Else 1 Debug lista_de_argumentos: expressao ';'  lista_de_argumentos;\n");
            $$ = $3;
        }
        else
        {
            //fprintf(stderr, "Else 2 Debug lista_de_argumentos: expressao ';'  lista_de_argumentos;\n");
            $$ = $1;
            ast_add_child($1, $3);
        }

    }
    //printf("Added lista_de_argumentos and expressao to lista_de_argumentos\n"); // Debug print
}
;

//##########################
// Nome da função
nome_func: call_identificador
{
    $$ = $1;
    //printf("Added identificador to nome_func\n"); // Debug print
}
;

//##########################
// Literais
literais: LITINT
{
    $$ = $1;
    $$->node_type = NODE_TYPE_INT;
    
    char* reg = allocate_register();
    
    sprintf(assembly_code, "movq $%s, %s", $$->valor_lexico->token_value, reg);
    append_assembly_code(global_code_list, assembly_code);

    $$->temp = reg;
}
| LITFLOAT
{
    $$ = $1;
    //printf("Added LITFLOAT to literais\n"); // Debug print
} 
| LITFALSE
{
    $$ = $1;
    //printf("Added LITFALSE to literais\n"); // Debug print
} 
| LITTRUE
{
    $$ = $1;
    //printf("Added LITTRUE to literais\n"); // Debug print
} 
;

//##########################
// Token LITINT
LITINT: TK_LIT_INT
{
    //fprintf(stderr, "Debug message LITINT: TK_LIT_INT\n");
    $$ = ast_new($1);
    $$->node_type = NODE_TYPE_INT;
    
    char* reg = allocate_register();
    
    sprintf(assembly_code, "movq %s, %s", reg, $$->valor_lexico->token_value);

    append_assembly_code(global_code_list, assembly_code);

    $$->temp = reg;

    free_register(reg);
    //printf("Added TK_LIT_INT to LITINT\n"); // Debug print
}
;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT
{
    $$ = ast_new($1);
    $$->node_type = NODE_TYPE_FLOAT;
    //printf("Added TK_LIT_FLOAT to LITFLOAT\n"); // Debug print
}
;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE
{
    $$ = ast_new($1);
    $$->node_type = NODE_TYPE_BOOL;
    //printf("Added TK_LIT_FALSE to LITFALSE\n"); // Debug print
}
;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE
{
    $$ = ast_new($1);
    $$->node_type = NODE_TYPE_BOOL;
    //printf("Added TK_LIT_TRUE to LITTRUE\n"); // Debug print
}
;

//##########################
// Tokens de operadores
INVERTSIG: '-'
{
    $$ = ast_new_label_only("-");
    //printf("Label INVERTSIG\n"); // Debug print
}
;
NEGATE: '!'
{
    $$ = ast_new_label_only("!");
    //printf("Label NEGATE\n"); // Debug print
}
;
MULTIPLY: '*'
{
    $$ = ast_new_label_only("*");
    //printf("Label MULTIPLY\n"); // Debug print
}
;
DIVIDE: '/'
{
    $$ = ast_new_label_only("/");
    //printf("Label DIVIDE\n"); // Debug print
}
;
REMAINDER: '%'
{
    $$ = ast_new_label_only("%");
    //printf("Label REMAINDER\n"); // Debug print
}
;
ADD: '+'
{
    $$ = ast_new_label_only("+");
    //printf("Label ADD\n"); // Debug print
}
;
SUBTRACT: '-'
{
    $$ = ast_new_label_only("-");
    //printf("Label SUBTRACT\n"); // Debug print
}
;
GREATERTHAN: '>'
{
    $$ = ast_new_label_only(">");
    //printf("Label GREATERTHAN\n"); // Debug print
}
;
LESSTHAN: '<'
{
    $$ = ast_new_label_only("<");
    //printf("Label LESSTHAN\n"); // Debug print
}
;
LESSEQUAL: TK_OC_LE 
{
    $$ = ast_new_label_only("<=");
    //printf("Label 'LESSEQUAL'\n"); // Debug print
}
;
GREATEREQUAL: TK_OC_GE 
{
    $$ = ast_new_label_only(">=");
    //printf("Label 'GREATEREQUAL'\n"); // Debug print
}
;
EQUAL: TK_OC_EQ 
{
    $$ = ast_new_label_only("==");
    //printf("Label 'EQUAL'\n"); // Debug print
}
;
NOTEQUAL: TK_OC_NE 
{
    $$ = ast_new_label_only("!=");
    //printf("Label 'NOTEQUAL'\n"); // Debug print
}
;
AND: TK_OC_AND 
{
    $$ = ast_new_label_only("&");
    //printf("Label 'AND'\n"); // Debug print
}
;
%%

//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d \n", s, get_line_number());
    return 1;
}
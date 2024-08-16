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
#include <string.h>
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
extern const char* global_filename;

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
char assembly_code[OPCODE_SIZE_OF_BUFFER] = {0};
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
    $$ = $3;
    if ($3 != NULL) {
        //char* reg = allocate_register();
        //generate_movq($3->temp, reg,global_code_list);
        //free_register(reg);
    }
    print_all_assembly(global_code_list);
    arvore = $$;
}

//##########################
// Definição de programa
programa: lista_de_elementos
{
    $$ = $1;
    if ($1 != NULL) {
        //char* reg = allocate_register();
        //generate_movq($1->temp, reg,global_code_list);
        //free_register(reg);
    }
}
| /* vazio */
{
    $$ = NULL; // Se não houver elementos, o programa é nulo
    arvore = NULL;
}
;

//##########################
// Lista de elementos
lista_de_elementos: elemento lista_de_elementos
{
    if ($1 == NULL) {
        $$ = $2;
    } else if ($2 == NULL) {
        $$ = $1;
    } else {
        $$ = $1;
        ast_add_child($$, $2);
    }
    //char* temps[] = { $1->temp, $2->temp };
    //for (int i = 0; i < 2; i++) {
    //    if (temps[i] != NULL) {
    //        //char* reg = allocate_register();
    //        generate_movq(temps[i], reg,global_code_list);
    //        //free_register(reg);
    //    }
    //}
}
| elemento
{
    $$ = $1;
    if ($$ != NULL && $1->temp != NULL) {
        //char* reg = allocate_register();
        //generate_movq($1->temp, reg, global_code_list);
        //free_register(reg);
    }
}
;

//##########################
// Elemento do programa
elemento: declaracao_global
{
    $$ = $1;
    if ($$ != NULL) {
        //char* reg = allocate_register();
       //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
        //append_assembly_code(global_code_list, assembly_code);
        //free_register(reg);
    }
    generate_global_variables(stack_of_tables, global_code_list); // globals that need appended at the top
    generate_assembly_prologue(global_filename);
}
| definicao_de_funcao
{
    $$ = $1;
    if ($$ != NULL) {
        //char* reg = allocate_register();
        //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg);  // Use movq for 64-bit registers
        //append_assembly_code(global_code_list, assembly_code);
        //free_register(reg);
    }
}
;

//##########################
// Declaração global de variável
declaracao_global: tipo lista_identificador ','
{
    $$ = NULL; // Não há ações associadas à declaração global
}
;

//##########################
// Identificador
identificador: TK_IDENTIFICADOR
{
    $$ = ast_new($1); // Cria um novo nó na árvore com o identificador
}
;

//##########################
// Identificador para pegar nome da função e inserir na tabela global
identificador_func: TK_IDENTIFICADOR
{
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
}
;

call_identificador: TK_IDENTIFICADOR
{
    $$ = ast_new_call_func($1); // Cria um novo nó representando uma chamada de função com o identificador
}
;

//##########################
// Tipos de dados
tipo: INT
{
    $$ = $1;
    symbol_type_now = TYPE_INT;
}
| FLOAT
{
    $$ = $1;
    symbol_type_now = TYPE_FLOAT;
}
| BOOL
{
    $$ = $1;
    symbol_type_now = TYPE_BOOL;
}
;

//##########################
// Token INT
INT: TK_PR_INT
{
    $$ = NULL; // Espero que seja null mesmo.
}
;

//##########################
// Token FLOAT
FLOAT: TK_PR_FLOAT
{
    $$ = NULL; // Espero que seja null mesmo.
}
;

//##########################
// Token BOOL
BOOL: TK_PR_BOOL
{
    $$ = NULL; // Espero que seja null mesmo.
}
;

//##########################
// Lista de identificadores
lista_identificador: lista_identificador ';' identificador
{
    $$ = $1; // Se houver uma lista de identificadores existente nós as mantemos
    char* new_key = strdup($3->valor_lexico->token_value);

    if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
    }

    insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($3,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
}
| identificador
{
    $$ = $1;
    char* new_key = strdup($1->valor_lexico->token_value);

    if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
    }

    insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($1,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));

}
;

//##########################
// Definição de função
definicao_de_funcao: cabecalho corpo fechar_escopo //////Somewhere here creates the null
{

    $$ = $1; // Define a definição de função como o cabeçalho
    if ($2 != NULL) {
        ast_add_child($$, $2); // Se houver corpo, adiciona o corpo como filho da definição de função

        //char *reg1 = allocate_register();
        //char *reg2 = allocate_register();

        //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
        //append_assembly_code(global_code_list, assembly_code);

        //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg2);
        //append_assembly_code(global_code_list, assembly_code);

        //$$->temp = strdup(reg2);
        
        //free_register(reg1);
        //free_register(reg2);

    } else {
        //char *reg1 = allocate_register();

        //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
        //append_assembly_code(global_code_list, assembly_code);

        //$$->temp = strdup(reg1);

        //free_register(reg1);
    }
}
;


//##########################
// Cabeçalho da função
cabecalho:   criar_escopo '(' lista_de_parametros ')' OR tipo '/' identificador_func
{
    $$ = $8; // Define o cabeçalho como o identificador

    char* identifier_key = strdup($8->valor_lexico->token_value);
    char* function_label = current_function_label;

    if (strcmp(identifier_key, "main") == 0) {
        main_label = strdup(function_label);
    }

    //print_assembly_code_list(global_code_list);

    //append_assembly_code(global_code_list, assembly_code);
    if (strcmp(identifier_key, "main") != 0) {
        //snprintf(assembly_code, sizeof(assembly_code), "push %%rbp");
        //append_assembly_code(global_code_list, assembly_code);
        //snprintf(assembly_code, sizeof(assembly_code), "mov %%rsp, %%rbp");
        //append_assembly_code(global_code_list, assembly_code);
    }
    //snprintf(assembly_code, sizeof(assembly_code), "subq $%d, %%rsp", initial_space + stack_of_tables->top->current_address_displacement + final_space);
    //append_assembly_code(global_code_list, assembly_code);
}
;

//##########################
// Criar novo scope
criar_escopo_global: 
{
    //fprintf(stderr, "Debug: Entrou em criar_escopo_global\n");
    $$ = NULL;
    table_of_symbols_t *new_scope = create_table_of_symbols_global(stack_of_tables->top,true);
    push_scope(stack_of_tables,new_scope);
    init_register_pool();

    global_code_list = create_assembly_code_list();

    char* function_name = "main";
    generate_prologue("main");
    
    //fprintf(stderr, "Debug: Saindo de criar_escopo_global\n");

}
;

criar_escopo: 
{
    //print_assembly_code_list(global_code_list);
    //fprintf(stderr, "Debug: Entrou em criar_escopo\n");
    $$ = NULL;
    table_of_symbols_t *new_scope = create_table_of_symbols(stack_of_tables->top,false);
    push_scope(stack_of_tables,new_scope);
}
;

//##########################
// Fechar Escopo
fechar_escopo: 
{
    $$ = NULL;
    pop_scope(stack_of_tables);
}
;		   

//##########################
// Criar primeira pilha
criar_pilha:
{   
    $$ = NULL;
    stack_of_tables = create_stack_of_tables();
}
;

//##########################
// Fechar primeira pilha
fechar_pilha:
{   
    $$ = NULL;
    generate_epilogue();
    free_stack_of_tables(stack_of_tables);
}
;

//##########################
// Token OR
OR: TK_OC_OR
{
    $$ = ast_new_label_only("|");
}
;

//##########################
// Lista de parâmetros
lista_de_parametros: lista_de_parametros ';' parametro
{
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
}
| parametro
{
    $$ = $1;
}
| /* vazio */ // Se não houver parâmetros
{
    $$ = NULL;
}
;
                   

//##########################
// Parâmetro da função
parametro: tipo identificador // Define o parâmetro como um tipo e um identificador
{
    $$ = $1;
    ast_add_child($$, $2);
    char *new_key = strdup($2->valor_lexico->token_value);
    if(find_symbol(stack_of_tables->top, new_key) != NULL)
    {
        printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }
    insert_symbol(stack_of_tables->top, new_key, create_symbol($2,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
}
;

//##########################
// Corpo da função
corpo: '{' bloco_de_comandos '}' // Define o corpo como um bloco de comandos dentro de chaves
{
    $$ = $2;
}
| corpo'{' bloco_de_comandos '}'
{
    $$ = $1;
    ast_add_child($$, $3);
}
;
	 
//##########################
// Bloco de Comandos que aceita vazio
bloco_de_comandos: /* vazio */ // Se o bloco de comandos estiver vazio
{
    $$ = NULL;
}
| lista_de_comandos // Se houver uma lista de comandos
{
    $$ = $1;
}
;

//##########################
// Definição de lista de comandos simples
lista_de_comandos: comando_simples ','  // Se houver apenas um comando simples ////// Aqui estava criando repetição do código...
{
    $$ = $1; // O resultado é o comando simples
}
| comando_simples ',' lista_de_comandos // Se houver mais de um comando simples
{
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

            //char* reg1 = allocate_register();
            //char* reg2 = allocate_register();

            //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $1->temp, reg1);
            //append_assembly_code(global_code_list, assembly_code);

            //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $3->temp, reg2);
            //append_assembly_code(global_code_list, assembly_code);

            //free_register(reg1);
            //free_register(reg2);
        }
    } 	
}
;

//##########################
// Definição de comando simples
comando_simples: declaracao_variavel
{
    $$ = $1;
}
| comando_atribuicao
{
    $$ = $1;
    //append_assembly_code(global_code_list, assembly_code); //THIS HERE IS REALLY POWERFUL, IT WILL DOUBLE APPEND MOST OPERATIONS!!!
}
| chamada_funcao
{
    $$ = $1;
}
| comando_retorno
{
    $$ = $1;
}
| comando_controle_fluxo
{
    $$ = $1;
}
| criar_escopo corpo fechar_escopo
{
    $$ = $2;
}
;

//##########################
// Declaração de variável
declaracao_variavel: tipo lista_identificador_local
{
    $$ = NULL;
}
;

//##########################
// Lista de identificadores locais
lista_identificador_local: lista_identificador_local ';' identificador
{
    $$ = $1; // Se houver uma lista de identificadores existente nós as mantemos
    char* new_key = strdup($3->valor_lexico->token_value);
    if(find_symbol(stack_of_tables->top, new_key) != NULL){
        printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
        exit(ERR_DECLARED);
     }
    insert_symbol(stack_of_tables->top, new_key, create_symbol($3,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
}
| identificador
{
    $$ = $1;
    char* new_key = strdup($1->valor_lexico->token_value);
  
    if(find_symbol(stack_of_tables->top, new_key) != NULL){
        printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
        exit(ERR_DECLARED);
    }
    insert_symbol(stack_of_tables->top, new_key, create_symbol($1,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
}
;

//##########################
// Comando de atribuição
comando_atribuicao: identificador '=' expressao // Recursion of expressao is causing all kinds of issues with the assembly generation.
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
        char* base_reg;

        //generate_movq($3->temp, reg, global_code_list); //Causes code duplication

        // Different handling for global and local variables
        if (!(address == 0 || $3->temp == NULL)){
            if (current_scope->is_global) {
                base_reg = "rip";

                //snprintf(assembly_code, sizeof(assembly_code), "Fuck You"); // WATCH OUT WITH APPENDS HERE
                //append_assembly_code(global_code_list, assembly_code);

                snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %s, %s(%%%s)", $3->temp, new_key, base_reg);
            } else {
                base_reg = "rbp";

                snprintf(assembly_code, sizeof(assembly_code), "Fuck You"); // WATCH OUT WITH APPENDS HERE
                //append_assembly_code(global_code_list, assembly_code);

                //snprintf(assembly_code, sizeof(assembly_code), "Address: %d\n", address); // WATCH OUT WITH APPENDS HERE
                //append_assembly_code(global_code_list, assembly_code);

                //snprintf(assembly_code, sizeof(assembly_code), "$3->temp: %s\n", $3->temp); // WATCH OUT WITH APPENDS HERE
                //append_assembly_code(global_code_list, assembly_code);

                snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %s, %d(%%rbp)", $3->temp, address);
            }
        }

        //append_assembly_code(global_code_list, assembly_code); //THIS HERE IS REALLY POWERFUL, IT WILL DOUBLE APPEND MOST OPERATIONS!!!
        //$$->temp = strdup(reg);

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
comando_retorno: RETURN TK_LIT_INT // Probably causing most of the errors...
{
    //char* reg1 = allocate_register();

    //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %s", $2->temp, reg1);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "movq %s, %%rax", reg1);
    //append_assembly_code(global_code_list, assembly_code);

    //generate_epilogue();
    //$$->temp = strdup(reg1);
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
    $$ = $3; // Define a condicional como o nó "if"
    ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
    ast_add_child($$, $5); // Adiciona o corpo como filho do nó "if"
    $$->node_type = $3->node_type;

    char* true_label = generate_label();
    char* false_label = generate_label();

    char *reg1 = allocate_register();
    char *reg2 = allocate_register();

    //generate_movq($3->temp, reg1, global_code_list);
    
    //generate_movq("$0", reg2, global_code_list);

    //snprintf(assembly_code, sizeof(assembly_code), "\tcmpq\t %s, %s", reg2, reg1);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "\tje\t %s", false_label);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", true_label);
    //append_assembly_code(global_code_list, assembly_code);

    if ($6 != NULL) {
        //generate_movq($6->temp, reg1, global_code_list);
    }

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", false_label);
    //append_assembly_code(global_code_list, assembly_code);

    //free_register(reg2);
    //$$->temp = strdup(reg1);
}
| IF '(' expressao ')' criar_escopo corpo fechar_escopo ELSE criar_escopo corpo fechar_escopo
{
    $$ = $3;
    ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
    ast_add_child($$, $5); // Adiciona o corpo do "if" como filho do nó "if"
    ast_add_child($$, $7); // Adiciona o nó "else" como filho do nó "if"
    $$->node_type = $3->node_type;

    char* true_label = generate_label();
    char* false_label = generate_label();
    char* after_label = generate_label();

    char *reg1 = allocate_register();
    char *reg2 = allocate_register();

    //generate_movq($3->temp, reg1, global_code_list);
    //generate_movq("$0", reg2, global_code_list);

    //snprintf(assembly_code, sizeof(assembly_code), "\tcmpq\t %s, %s", reg2, reg1);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "\tje\t %s", false_label);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", true_label);
    //append_assembly_code(global_code_list, assembly_code);

    if ($6 != NULL) {
        //generate_movq($6->temp, reg1, global_code_list);
    }

    //snprintf(assembly_code, sizeof(assembly_code), "\tjmp\t %s", after_label);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", false_label);
    //append_assembly_code(global_code_list, assembly_code);

    if ($10 != NULL) {
        //generate_movq($10->temp, reg1, global_code_list);
    }

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", after_label);
    //append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(reg1);
    //free_register(reg2);
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
    $$ = $3;
    ast_add_child($$, $3); // Adiciona a expressão como filho do nó "while"
    ast_add_child($$, $5); // Adiciona o corpo como filho do nó "while"
    $$->node_type = $3->node_type;

    char* loop_label = generate_label();
    char* true_label = generate_label();
    char* false_label = generate_label();

    //char* reg1 = allocate_register(); 
    //char* reg2 = allocate_register();

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", loop_label);
    //append_assembly_code(global_code_list, assembly_code);

    //generate_movq($3->temp, reg1, global_code_list);

    //generate_movq("$0", reg2, global_code_list);

    //snprintf(assembly_code, sizeof(assembly_code), "\tcmpq\t %s, %s", reg2, reg1);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "\tje\t %s", false_label);
    //append_assembly_code(global_code_list, assembly_code);
   
    //snprintf(assembly_code, sizeof(assembly_code), "%s\t:", true_label);
    //append_assembly_code(global_code_list, assembly_code);

    if ($6 != NULL) {
        //snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %s, %s", $6->temp, reg1);
        //append_assembly_code(global_code_list, assembly_code);
    }

    //snprintf(assembly_code, sizeof(assembly_code), "\tjmp\t %s", loop_label);
    //append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "%s:\t", false_label);
    //append_assembly_code(global_code_list, assembly_code);

    //free_register(reg2);

    //$$->temp = strdup(reg1);
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
    $$ = $3;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);
    //printf("Added operando and operador to operando\n"); // Debug print

    //char* reg1 = allocate_register();
    //char* reg2 = allocate_register();

    //generate_movq($1->temp, reg1, global_code_list);

    //generate_movq($3->temp, reg2, global_code_list);

    snprintf(assembly_code, sizeof(assembly_code), "\torq\t %s, %s", $1->temp, $3->temp);
    append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(reg1);

    //free_register(reg2);
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
    $$ = $3;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);
    //printf("Added operador and comparacao to operador\n"); // Debug print

    //char* reg1 = allocate_register();
    //char* reg2 = allocate_register();

    //generate_movq($1->temp, reg1, global_code_list);

    //generate_movq($3->temp, reg2, global_code_list);

    snprintf(assembly_code, sizeof(assembly_code), "\tandq\t %s, %s", $1->temp, $3->temp);
    append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(reg1);

    //free_register(reg2);
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
    $$ = $3;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    //char* reg1 = allocate_register();
    //char* reg2 = allocate_register();
    char* result_reg = allocate_register();

    //generate_movq($1->temp, reg1, global_code_list);

    //generate_movq($3->temp, reg2, global_code_list);

    char* current_opcode = $2->valor_lexico->token_value;

    snprintf(assembly_code, sizeof(assembly_code), "\tcmpq\t %s, %s", $1->temp, $3->temp);
    append_assembly_code(global_code_list, assembly_code);

    if (strcmp(current_opcode, "CMP_EQ") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsete\t %%al");
    } else if (strcmp(current_opcode, "CMP_NE") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsetne\t %%al");
    }
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\tmovzbq\t %%al, %s", result_reg);
    append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(result_reg);

    //free_register(reg1);
    //free_register(reg2);
    // result_reg is still in use in //$$->temp, so don't free it
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
    $$ = $3;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    //char* reg1 = allocate_register();
    //char* reg2 = allocate_register();
    char* result_reg = allocate_register();

    //generate_movq($1->temp, reg1, global_code_list);

    //generate_movq($3->temp, reg2, global_code_list);

    snprintf(assembly_code, sizeof(assembly_code), "\tcmpq\t %s, %s", $1->temp, $3->temp);
    append_assembly_code(global_code_list, assembly_code);

    char* current_opcode = $2->valor_lexico->token_value;

    if (strcmp(current_opcode, "CMP_GE") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsetge\t %%al");
    } else if (strcmp(current_opcode, "CMP_LE") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsetle\t %%al");
    } else if (strcmp(current_opcode, "CMP_GT") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsetg\t %%al");
    } else if (strcmp(current_opcode, "CMP_LT") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsetl\t %%al");
    }
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\tmovzbq %%al, %s", result_reg);
    append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(result_reg);

    //free_register(reg1);
    //free_register(reg2);
    // result_reg is still in use in //$$->temp, so don't free it
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
    $$ = $3;
    ast_add_child($$, $1);
    ast_add_child($$, $3);
    $$->node_type = new_type($1, $3);

    //char* reg1 = allocate_register();
    //char* reg2 = allocate_register();

    //generate_movq($1->temp, reg1, global_code_list);

    //generate_movq($3->temp, reg2, global_code_list);

    char* current_opcode = $2->valor_lexico->token_value;

    if (strcmp(current_opcode, "+") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\taddq\t %s, %s",$1->temp, $3->temp);
    } else if (strcmp(current_opcode, "-") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\tsubq\t %s, %s", $1->temp, $3->temp);
    }
    append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(reg1);

    //free_register(reg2);
}
;

//##########################
// Operação de adição e subtração
op_adicaousub: ADD
{
    $$ = $1;
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

    //char* reg1 = allocate_register();
    //char* reg2 = allocate_register();
    //char* result_reg = allocate_register();

    //generate_movq($1->temp, reg1, global_code_list);

    //generate_movq($3->temp, reg2, global_code_list);

    char* current_opcode = $2->valor_lexico->token_value;

    if (strcmp(current_opcode, "*") == 0) {
        snprintf(assembly_code, sizeof(assembly_code), "\timulq\t %s, %s", $1->temp, $3->temp);
    } else if (strcmp(current_opcode, "/") == 0) {
        
        snprintf(assembly_code, sizeof(assembly_code), "\tcqto\t");
        append_assembly_code(global_code_list, assembly_code);
        snprintf(assembly_code, sizeof(assembly_code), "\tidivq\t %s", $1->temp);
    }
    append_assembly_code(global_code_list, assembly_code);

    //$$->temp = strdup(reg1);

    //free_register(reg2);
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
    $$ = $2;
    ast_add_child($$, $2);
    $$->node_type = $2->node_type;

    int count = 0;

    //generate_movq($2->temp, reg, global_code_list);

    //fprintf(stderr, "Debug message Invert %s:\n",$2->temp); // $2 due to ascendancy $2 is the one that contains reg

    snprintf(assembly_code, sizeof(assembly_code), "\tnegq\t %s", $2->temp);
    append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "\t%d", count++); // Debug contador para descobrir recursão
    //append_assembly_code(global_code_list, assembly_code);

}
| NEGATE unario
{
    $$ = $2;
    ast_add_child($$, $2);
    $$->node_type = $2->node_type;

    //generate_movq($2->temp, reg, global_code_list);

    //snprintf(assembly_code, sizeof(assembly_code), "\txorq\t $1, %s", $2->temp);
    append_assembly_code(global_code_list, assembly_code);
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

        char* base_reg = current_scope->is_global ? "%rbp" : "%rsp";

        snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %d(%s), %s", address, base_reg, $1->temp);
        append_assembly_code(global_code_list, assembly_code);

        //$$->temp = strdup(reg); // NECESSARY TO PASS UPWARDS THE REGISTERS
        //fprintf(stderr, "Debug message identificador %s:\n",//$$->temp);
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
    
    //char* reg = allocate_register();
    //fprintf(stderr,"%s\n",reg);

    char* int_assembly = strdup($$->valor_lexico->token_value);

    char* dollar = malloc(strlen(int_assembly) + 2);

    strcpy(dollar, "$");
    strcat(dollar,int_assembly);

    snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %s, %s", src, dest);  
    append_assembly_code(global_code_list, assembly_code);
}

    generate_movq(dollar, reg, global_code_list); // PARA TESTE IJK15 ESSE É o
    //	movq	 $393, %rax // PRIMEIRA ATRIBUICAO
	//  movq	 $0, %rcx // ISSO É O RETURN DA MAIN
    
    //$$->temp = reg;


    //fprintf(stderr, "Debug message LITINT %s:\n",//$$->temp);
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
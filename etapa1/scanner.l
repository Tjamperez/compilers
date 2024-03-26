%{
#include "tokens.h"
%}

%option noyywrap
%option yylineno

%%

"int" { return TK_PR_INT; }
"bool" {return TK_PR_BOOL; }
"if" {return TK_PR_IF; }
"else" {return TK_PR_ELSE; }
"while" {return TK_PR_WHILE; }
"return" {return TK_PR_RETURN; }

"-" {return '-'; }
"!" {return '!'; }
"*" {return '*'; }
"/" {return '/'; }
"%" {return '%'; }
"+" {return '+'; }
"_" {return '_'; }
"<" {return '<'; }
">" {return '>'; }
"{" {return '{'; }
"}" {return '}'; }
"(" {return '('; }
")" {return ')'; }
"=" {return '='; }
"," {return ','; }
";" {return ';'; }

"<=" {return TK_OC_LE}
">=" {return TK_OC_GE}
"==" {return TK_OC_EQ}
"!=" {return TK_OC_NE}
"&" {return TK_OC_AND}
"|" {return TK_OC_OR}

"((_?[a-z]*)*[0-9]*(_?[a-z]*)*)*" {return TK_IDENTIFICADOR}





.     { return TK_ERRO; }

%%

int get_line_number(void) {
    return yylineno;
}

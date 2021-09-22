//
// Analisador sintático para MiniCalc
//

// Analisador descendente recursivo

#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "lexer.h"

Token *t;

// Analisador sintático do programa
// Assume que o analisador léxico foi inicializado com o código-fonte
Programa* AnalisePrograma() {
    Programa *res = (Programa*) malloc(sizeof(Programa));

    if (res == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria.");
        exit(1);
    }

    // verifica se o programa começa com palavra-chave 'print'
    t = ProximoToken();

    if (t->tipo != TOKEN_PRINT) {
        fprintf(stderr, "Erro sintatico: palavra-chave 'print' esperada no inicio do programa.");
        exit(2);
    }

    // analisa a expressao seguinte
    res->e = AnaliseExpressao();

    return res;
}

Expressao* AnaliseExpressao() {
    // analisa a expressao
    Expressao *res = (Expressao*) malloc(sizeof(Expressao));

    // parentese abrindo
    t = ProximoToken();

    if (t->tipo != TOKEN_ABREPAR) {
        fprintf(stderr, "Erro sintatico: '(' esperado");
        exit(2);
    }

    // inteiro
    t = ProximoToken();

    if (t->tipo != TOKEN_INT) {
        fprintf(stderr, "Erro sintatico: constante inteira esperada");
        exit(2);
    }

    res->valor1 = t->valor;

    // operador
    t = ProximoToken();

    if (t->tipo != TOKEN_SOMA && t->tipo != TOKEN_MULT) {
        fprintf(stderr, "Erro sintatico: operador esperado");
        exit(2);
    }

    res->oper = (t->tipo == TOKEN_SOMA ? OPER_SOMA : OPER_MULT);

    // inteiro
    t = ProximoToken();

    if (t->tipo != TOKEN_INT) {
        fprintf(stderr, "Erro sintatico: constante inteira esperada");
        exit(2);
    }

    res->valor2 = t->valor;

    // parentese fechando
    t = ProximoToken();

    if (t->tipo != TOKEN_FECHAPAR) {
        fprintf(stderr, "Erro sintatico: ')' esperado");
        exit(2);
    }

    return res;
}

void DestroiPrograma(Programa *p) {
    free(p->e);
    p->e = NULL;
    free(p);
}

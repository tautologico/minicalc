#include <stdio.h>
#include <stdlib.h>

#include "arq.h"
#include "lexer.h"
#include "parser.h"

int AvaliaExpressao(Expressao* e) {
    int res = 0;
    int v1, v2;

    switch (e->oper) {
        case OPER_VAR:
            // TODO: consulta a tabela de variaveis para obter o valor
            // res = ConsultaTabela(e->nomeIdent);
            printf("Variaveis nao estao implementadas\n");
            break;
        case OPER_CONST:
            res = e->valor;
            break;
        case OPER_SOMA:
            v1 = AvaliaExpressao(e->op1);
            v2 = AvaliaExpressao(e->op2);
            res = v1 + v2;
            break;
        case OPER_MULT:
            v1 = AvaliaExpressao(e->op1);
            v2 = AvaliaExpressao(e->op2);
            res = v1 * v2;
            break;
        default:
            printf("Operador nao reconhecido.\n");
    }

    return res;
}

void ImprimeDeclaracoes(Declaracao *d) {
    while (d != NULL) {
        printf("Declaracao - ident: %s\n", d->nomeIdent);
        d = d->next;
    }
}

int main() {
    InicializaLexer("../test/var1.mc");

    // arvore sintatica do programa
    Programa *p = AnalisePrograma();

    ImprimeDeclaracoes(p->decls);

    // TODO: Processa declaracoes de variaveis e cria tabela de variaveis
    // ProcessaDeclaracoes(p->decls);

    int resultado = AvaliaExpressao(p->e);

    printf("%d\n", resultado);

    DestroiPrograma(p);
    FinalizaLexer();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "arq.h"
#include "lexer.h"
#include "parser.h"

void AvaliaExpressao(Expressao* e) {
    switch (e->oper) {
        case OPER_SOMA:
            printf("%d\n", e->valor1 + e->valor2);
            break;
        case OPER_MULT:
            printf("%d\n", e->valor1 * e->valor2);
            break;
        default:
            printf("Operador nao reconhecido.\n");
    }
}

int main() {
    InicializaLexer("../test/literal.mc");

    Programa *p = AnalisePrograma();

    AvaliaExpressao(p->e);

    DestroiPrograma(p);
    FinalizaLexer();
    return 0;
}

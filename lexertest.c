#include <stdio.h>
#include <stdlib.h>

#include "arq.h"
#include "lexer.h"

void ImpBuffer(Buffer *b) {
    for (long c = 0; c < b->tam; ++c)
        putchar(b->cont[c]);
}

void ImprimeTipoToken(TipoToken tipo) {
    switch(tipo) {
        case TOKEN_INT:
            printf("TOKEN_INT");
            break;
        case TOKEN_PRINT:
            printf("TOKEN_PRINT");
            break;
        case TOKEN_VAR:
            printf("TOKEN_VAR");
            break;
        case TOKEN_EOF:
            printf("TOKEN_EOF");
            break;
        case TOKEN_ABREPAR:
            printf("TOKEN_ABREPAR");
            break;
        case TOKEN_FECHAPAR:
            printf("TOKEN_FECHAPAR");
            break;
        case TOKEN_SOMA:
            printf("TOKEN_SOMA");
            break;
        case TOKEN_MULT:
            printf("TOKEN_MULT");
            break;
        case TOKEN_ERRO:
            printf("TOKEN_ERRO");
            break;
        case TOKEN_IGUAL:
            printf("TOKEN_IGUAL");
            break;
        case TOKEN_PONTOVIRG:
            printf("TOKEN_PONTOVIRG");
            break;
        case TOKEN_IDENT:
            printf("TOKEN_IDENT");
            break;
        default:
            printf("Tipo desconhecido");
    }
}

int main() {
    InicializaLexer("../test/expsimples.mc");

    Token *t = ProximoToken();
    while (t->tipo != TOKEN_EOF && t->tipo != TOKEN_ERRO) {
        printf("Tipo do token: ");
        ImprimeTipoToken(t->tipo);
        if (t->tipo == TOKEN_INT) {
            printf(" - Valor do token: %d\n", t->valor);
        } else if (t->tipo == TOKEN_IDENT) {
            printf(" - Nome do identificador: %s\n", t->nome);
        } else
            printf("\n");

        t = ProximoToken();
    }

    if (t->tipo == TOKEN_ERRO) {
        fprintf(stderr, "Erro lexico\n");
    }

    FinalizaLexer();
    return 0;
}

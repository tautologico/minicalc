//
// Analisador sintático para MiniCalc
//

#ifndef MINICALC_PARSER_H
#define MINICALC_PARSER_H

typedef enum tagTipoOper {
    OPER_SOMA,
    OPER_MULT
} TipoOper;

typedef struct tagExpressao {
    int valor1;
    int valor2;
    TipoOper oper;
} Expressao;

typedef struct tagPrograma {
    Expressao *e;
} Programa;

Programa* AnalisePrograma();
Expressao* AnaliseExpressao();
void DestroiPrograma(Programa *p);

#endif //MINICALC_PARSER_H

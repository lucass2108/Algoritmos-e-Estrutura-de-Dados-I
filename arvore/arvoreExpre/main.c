#include <stdio.h>
#include "arvExpressao.h"

int main() {
    //DECLARAÇÃO DE VARIÁVEIS
    char expressao[30];
    fila *f;
    pC *pC;
    arv *arvExpressao;
    float res, a, b; 

    //printf("Digite a expressao aritmetica:");
    scanf("%s", expressao);

    //printf("Digite o valor de a:");
    scanf("%f", &a);

    //printf("Digite o valor de b (se não houver, digite 9999):");
    scanf("%f", &b);

    f = criaFila();
    pC = criaPilha();

    converteExpressao(expressao, pC, f);

    destroiPilha(pC);

    arvExpressao = criaArvoreExpressao();

    geraArvoreExpressao(f, arvExpressao);

    destroiFila(f);

    res = avaliaExpressao(retornaRaiz(arvExpressao), a, b);

    printf("O resultado da expressao e: %0.2f", res);

    return 1;
}

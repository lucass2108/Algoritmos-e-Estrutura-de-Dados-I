#include <stdio.h>
#include "TAD_ARVORE.h"

int main()
{
    abp *arv = criaArv();
    carregaArv(arv, "testearv.txt");
    percorreOrdem(getRaiz(arv));

    printf("\nMaior: %d", maiorValor(getRaiz(arv)));
    printf("\nMenor: %d", menorValor(getRaiz(arv)));
    printf("\nAltura: %d", altura(getRaiz(arv)));
    printf("\nQuant: %d", quant(getRaiz(arv)));
    printf("\nQuant Folhas: %d", quantFolhas(getRaiz(arv)));
    printf("\nQuant No Interno: %d", quantNoInterno(getRaiz(arv)));
    printf("\nArv Estritamente Bin: %d", arvEstBin(getRaiz(arv)));

    return 0;
}
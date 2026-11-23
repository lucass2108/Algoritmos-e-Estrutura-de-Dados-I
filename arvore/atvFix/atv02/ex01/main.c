#include <stdio.h>
#include "tad_abp.h"

int main()
{
    abp *arv = criaArvore();

    carregarArv(arv, "arv.txt");

    imprimeArv(getRaix(arv), 1);
    printf("\n");
    imprimeArv(getRaix(arv), 2);
    printf("\n");
    imprimeArv(getRaix(arv), 3);
    printf("\n");
    mostraSArvDir(getRaix(arv), 12);
    printf("\n");
    mostraSArvEsq(getRaix(arv), 10);
    printf("\n");
    mostraPaifilho(getRaix(arv), 89);
    Remover(arv, 10);
    Remover(arv, 5);
    Remover(arv, 89);
    imprimeArv(getRaix(arv), 2);

    return 0;
}
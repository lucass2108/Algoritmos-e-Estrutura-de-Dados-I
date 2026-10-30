#include <stdio.h>
#include "arvore.h"

int main()
{
    abp *arv = alocaArvore();
    if(!arv)
    return -1;

    char nomeAqr[] = "num.txt";

    carregaArv(arv, nomeAqr);
    percorre(getRaiz(arv));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "tadLista.h"

int main()
{
    lista *l = criaLista();
    char nomeAqr[] = "teste.txt";
    FILE *arq = fopen(nomeAqr, "r");
    if (arq == NULL)
    {
        printf("ERRO");
        return -1;
    }

    while (!feof(arq))
    {
        int i, q;
        float p;
        fscanf(arq, "%d %f %d", &i, &p, &q);

        inserirLista(l, i, p, q);
    }

    printf("Qual vai ser o desconto?");
    float desc;
    scanf("%f", &desc);

    desconto(l, desc);

    imprimeLista(l);

    relatorio(l);

    return 0;
}
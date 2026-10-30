#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main()
{
    int vet[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43};

    arvore *a = criaArvore();

    for (int i = 0; i < sizeof(vet) / sizeof(vet[0]); i++)
    {
        insere(a, criaNo(vet[i]));
    }

    imprimeArvore(a);

    return 0;
}
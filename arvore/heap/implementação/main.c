#include <stdio.h>
#include "heap.h"
#include <stdlib.h>


int main()
{
    char nomeArq[] = "heap.txt";

    heap *h = criaHeap(10);
    if(!h)
    {
        printf("ERRO, falha ao criar heap");
        return 1;
    }

    carregarElementos(nomeArq, h);

    printf("Ocupacao: %d \n", retornaOcupacao(h));
    printf("Priridade: %d \n", retornaMaiorPrioridade(h));
    imprimeVetor(h);

    insereElemento(h, 89);
    imprimeVetor(h);


    while (retornaOcupacao(h) > 0)
    {
        int removido = removeElemento(h);

        printf("Removido %d | Restante: ", removido);
        imprimeVetor(h);
    }
    

    return 0;
}
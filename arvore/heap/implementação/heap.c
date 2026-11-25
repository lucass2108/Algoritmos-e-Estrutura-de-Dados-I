#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

typedef struct heap heap;

struct heap
{
    int *vet;
    int tail;
    int tam;
};

heap *criaHeap(int tam)
{
    if (tam <= 0)
        return NULL;

    heap *h = (heap *)malloc(sizeof(heap));
    if (!h)
        return NULL;

    h->vet = (int *)malloc(sizeof(int) * (1 + tam));
    if (h->vet == NULL)
        return NULL;

    h->tail = 0;
    h->tam = tam;
    return h;
}

int insereElemento(heap *h, int elemento)
{
    if (h == NULL || h->tail >= h->tam)
        return 0;

    h->tail++;
    int i = h->tail;
    h->vet[i] = elemento;

    while (i > 1 && h->vet[i] >= h->vet[i / 2])
    {
        int aux = h->vet[i];
        h->vet[i] = h->vet[i / 2];
        h->vet[i / 2] = aux;

        i = i / 2;
    }

    return 1;
}

int carregarElementos(char nomeArquivo[], heap *h)
{
    if (h == NULL)
        return -1;

    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq)
        return -1;

    int valor;
    while (!feof(arq))
    {
        fscanf(arq, "%d", &valor);
        insereElemento(h, valor);
    }

    fclose(arq);

    return 1;
}

int retornaOcupacao(heap *h)
{
    if (!h)
        return -1;

    return h->tail;
}

int retornaMaiorPrioridade(heap *h)
{
    if (!h || h->tail < 1)
        return -1;

    return h->vet[1];
}

void imprimeVetor(heap *h)
{
    if (!h || h->tail < 1)
    {
        printf("Vazio");
        return;
    }

    for (int i = 1; i <= h->tail; i++)
    {
        printf("%d ", h->vet[i]);
    }

    printf("\n");
}

int removeElemento(heap *h)
{
    if (!h || h->tail < 1)
        return -1;

    int maiorPrioridade = h->vet[1];
    h->vet[1] = h->vet[h->tail];
    h->tail--;

    if (h->tail >= 1)
        MaxHeapify(h, 1);

    return maiorPrioridade;
}

void MaxHeapify(heap *h, int pos)
{
    if (!h || pos < 1 || pos > h->tail)
    {
        return;
    }

    int maior = pos;
    int esq = 2 * pos;
    int dir = 2 * pos + 1;

    if (esq <= h->tail && h->vet[esq] > h->vet[maior])
    {
        maior = esq;
    }

    if (dir <= h->tail && h->vet[dir] > h->vet[maior])
    {
        maior = dir;
    }

    if (maior != pos)
    {
        int aux = h->vet[pos];
        h->vet[pos] = h->vet[maior];
        h->vet[maior] = aux;

        MaxHeapify(h, maior);
    }
}
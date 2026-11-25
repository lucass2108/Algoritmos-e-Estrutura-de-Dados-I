#ifndef HEAP_H
#define HEAP_H

typedef struct heap heap;

heap *criaHeap(int tam);

int insereElemento(heap *h, int elemento);

int carregarElementos(char nomeArquivo[], heap *h);

int retornaOcupacao(heap *h);

int retornaMaiorPrioridade(heap *h);

void imprimeVetor(heap *h);

int removeElemento(heap *h);

void MaxHeapify(heap *h, int pos);


#endif
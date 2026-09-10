#include <stdlib.h>
#include <stdio.h>
#include "tadFila.h"

typedef struct fila filaInt;
typedef struct no noFila;

struct no
{
    int valor;
    noFila *prox;
};

struct fila
{
    noFila *inicio;
    noFila *fim;
    int tamFila;
};

// cria estrutura de fila vazia
filaInt *criaFila()
{
    filaInt *f = (filaInt *)malloc(sizeof(filaInt));
    if (f == NULL)
        return NULL;

    f->fim = NULL;
    f->inicio = NULL;
    f->tamFila = 0;

    return f;
}

// insere elemento no fim da fila
void enqueue(filaInt *f, int valor)
{
    // ALoca o novo no
    noFila *novo = (filaInt *)malloc(sizeof(filaInt));
    if (novo == NULL)
        return;

    // determina o valor do nó e q nn há um próximo por ser o último da fila
    novo->valor = valor;
    novo->prox = NULL;

    // verifica se o inicio esta vazio(se tiver quer dizer q a fila está vazia)
    if (f->inicio == NULL)
    {
        // se vazio, determina o inicio sendo o novo no
        f->inicio = novo;
    }
    else
    {
        // se nn, determina q o prox do antigo fim seja o novo no
        f->fim->prox = novo;
    }

    // determina o fim da fila sendo o novo no
    f->fim = novo;

    // tamanho da fila
    f->tamFila++;
}

// tira elemento do inicio da fila
int dequeue(filaInt *f)
{
    // verifica se tem algo na fila
    if (f->inicio == NULL)
        return -1;

    // guarda os dados do inicio
    noFila *inicio = f->inicio;
    int aux = inicio->valor;

    // faz com q o inicio de f seja o prox de inicio
    f->inicio = f->inicio->prox;

    // libera inicio
    free(inicio);

    // tamanho da fila
    f->tamFila--;

    // retorna o valor do antigo inicio
    return aux;
}

// mostra o começo da fila
void comecoFila(filaInt *f);

// esvazia a fila
void esvazia(filaInt *f);

// verifica se a fila está vazia
int filaVazia(filaInt *f);

// retorna tamanho da fila
int tamanhoFila(filaInt *f);

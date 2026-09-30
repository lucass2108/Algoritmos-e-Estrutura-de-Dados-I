#include "TAD_LISTA.h"
#include <stdio.h>
#include <stdlib.h>

// Simplesmente encadeada

typedef struct listaSE TListaSE;

typedef struct no TNo;

struct listaSE
{
    TNo *inicio;
    int tam;
};

struct no
{
    int valor;
    TNo *prox;
};

TListaSE *alocaLista()
{
    TListaSE *lista = (TListaSE *)malloc(sizeof(TListaSE));
    if (lista == NULL)
        return NULL;

    lista->inicio = NULL;
    lista->tam = 0;

    return lista;
}

TNo *alocaNo(int valor)
{
    TNo *no = (TNo *)malloc(sizeof(TNo));
    if (no == NULL)
        return NULL;

    no->valor = valor;
    no->prox = NULL;

    return no;
}

int insereComecoLista(TListaSE *l, int valor)
{
    if (!l)
        return -1;

    TNo *novoNo = alocaNo(valor);

    if (l->inicio == NULL)
    {
        l->inicio = novoNo;
        l->tam++;
        return 1;
    }

    novoNo->prox = l->inicio;
    l->inicio = novoNo;
    l->tam++;
    return 1;
}

int insereOrdenadoLista(TListaSE *l, int valor)
{

    if (!l)
        return -1;

    TNo *novoNo = alocaNo(valor);

    if (l->inicio == NULL)
    {
        l->inicio = novoNo;
        l->tam++;
        return 1;
    }

    if (valor < l->inicio->valor)
    {
        novoNo->prox = l->inicio;
        l->inicio = novoNo;
        l->tam++;
        return 1;
    }

    TNo *aux = l->inicio;
    while (aux->prox != NULL && aux->prox->valor <= valor)
    {
        aux = aux->prox;
    }

    novoNo->prox = aux->prox;
    aux->prox = novoNo;
    l->tam++;
    return 1;
}

void imprimeListaSE(TListaSE *l)
{
    if (!l)
        return;

    TNo *aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }

    printf("\n");
}

//**LISTA DUPLAMENTE ENCADEADA***//
typedef struct listaDE TListaDE;

typedef struct noDE TNoDE;

TListaDE *alocaListaDE();

TNoDE *alocaNoDE(int valor);

int insereComecoListaDE(TListaDE *l, int valor);

int insereOrdenadoListaDE(TListaDE *l, int valor);

void imprimeListaDE(TListaDE *l);

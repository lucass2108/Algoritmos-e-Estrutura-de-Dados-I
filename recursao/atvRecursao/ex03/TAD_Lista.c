#include <stdio.h>
#include <stdlib.h>
#include "TAD_Lista.h"

typedef struct lista TLista;
typedef struct no TNo;

struct lista
{
    int tam;
    TNo *inicio;
};

struct no
{
    int cod;
    float valor;
    TNo *prox;
};

// Cria uma nova lista
TLista *criaLista()
{
    TLista *aux = (TLista *)malloc(sizeof(TLista));

    if (aux == NULL)
        return NULL;

    aux->tam = 0;
    aux->inicio = NULL;

    return aux;
}

// Cria um novo nó
TNo *criaNo(int cod, float valor)
{
    TNo *aux = (TNo *)malloc(sizeof(TNo));

    if (aux == NULL)
        return NULL;

    aux->cod = cod;
    aux->valor = valor;
    aux->prox = NULL;

    return aux;
}

// Insere no início da lista
void insereInicioLista(TLista *lista, TNo *elemento)
{
    if (lista == NULL || elemento == NULL)
        return;

    elemento->prox = lista->inicio;
    lista->inicio = elemento;
    lista->tam++;
}

// Função recursiva que insere o pedido no final da lista ao qual o no pertence
void insereFinalRec(TLista *lista, TNo *noAtual, TNo *pedido)
{
    if (lista == NULL || pedido == NULL)
        return;

    if (noAtual == NULL)
    {
        insereInicioLista(lista, pedido);
        return;
    }

    if (noAtual->prox == NULL)
    {
        noAtual->prox = pedido;
        lista->tam++;
        return;
    }

    insereFinalRec(lista, noAtual->prox, pedido);
}

// Retorna o nó inicial da lista
TNo *getLInicio(TLista *lista)
{
    if (lista == NULL || lista->inicio == NULL)
        return NULL;

    return lista->inicio;
}

// Imprime os códigos dos pedidos da lista
// printf("%d\t", aux->cod);
void imprimeLista(TLista *lista)
{
    if (lista == NULL || lista->inicio == NULL)
        return;

    TNo *aux = lista->inicio;

    while (aux != NULL)
    {
        printf("%d\t", aux->cod);
        aux = aux->prox;
    }
}

// Esvazia a lista
void esvaziaLista(TLista *lista)
{
    if (lista == NULL)
        return;

    TNo *aux = lista->inicio;

    while (aux != NULL)
    {
        TNo *auxaux = aux;
        aux = aux->prox;

        free(auxaux);
    }

    lista->inicio = NULL;
    lista->tam = 0;
}

// Desaloca lista
// Caso haja elementos na lista, as mesmas devem ser excluídas primeiro
void desalocaLista(TLista *lista)
{
    if (lista == NULL)
        return;

    esvaziaLista(lista);

    free(lista);
}

// Média dos elementos
// Função que calcula a média dos elementos de uma lista simplesmente encadeada
float somaPedidos(TNo *inicio)
{
    if (inicio == NULL)
        return 0;

    return inicio->valor + somaPedidos(inicio->prox);
}

float calculaMedia(TLista *lista)
{
    if (lista == NULL || lista->tam == 0)
        return 0;

    return somaPedidos(lista->inicio) / lista->tam;
}

// Função recursiva que lê dados de uma lista e insere em uma nova lista os nós cujos códigos são positivos.
// A inserção acontece no final da lista e usa a função insereFinalRec.
void pedidos(TLista *novaLista, TNo *inicio)
{
    if (novaLista == NULL || inicio == NULL)
        return;

    if (inicio->cod > 0)
    {
        TNo *aux = criaNo(inicio->cod, inicio->valor);

        if (novaLista->inicio == NULL)
        {
            insereInicioLista(novaLista, aux);
        }
        else
        {
            insereFinalRec(novaLista, novaLista->inicio, aux);
        }
    }

    pedidos(novaLista, inicio->prox);
}

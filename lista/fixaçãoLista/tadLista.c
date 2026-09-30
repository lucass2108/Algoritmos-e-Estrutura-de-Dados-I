#include <stdlib.h>
#include <stdio.h>
#include "tadLista.h"

typedef struct lista lista;
typedef struct No produto;

struct lista
{
    produto *inicio;
    int tam;
};

struct No
{
    int id;
    float preco;
    int quant;

    produto *prox;
};

lista *criaLista()
{
    lista *l = (lista *)malloc(sizeof(lista));

    if (l == NULL)
        return NULL;

    l->inicio = NULL;
    l->tam = 0;

    return l;
}

void inserirLista(lista *l, int id, float valor, int quant)
{
    produto *p = (produto *)malloc(sizeof(produto));
    if (p == NULL)
        return;

    p->id = id;
    p->preco = valor;
    p->quant = quant;

    p->prox = l->inicio;

    l->inicio = p;
}

produto *retirarFila(lista *l);

void desconto(lista *l, float desc)
{
    produto *aux = l->inicio;
    if (aux == NULL)
        return;

    while (aux != NULL)
    {
        aux->preco = aux->preco - (aux->preco * (desc / 100));
        aux = aux->prox;
    }
}

void imprimeLista(lista *l)
{
    produto *aux = l->inicio;
    if (aux == NULL)
        return;

    while(aux != NULL)
    {
        printf("%d\t%.2f\n", aux->id, aux->preco);
        aux = aux->prox;
    }
}

void relatorio(lista *l)
{
    produto *aux = l->inicio;
    if (aux == NULL)
        return;

    int mais500 = 0;

    printf("Relatório\n");

    while(aux != NULL)
    {
        if(aux->quant > 500)
        {
            mais500++;
        }
        aux = aux->prox;
    }

    printf("Temos %d produtos com mais de 500 unidades estodcadas", mais500);
}
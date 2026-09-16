#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tadFila.h"

typedef struct fila canal;
typedef struct no pedido;

struct no
{
    int id;
    char nomeCliente[30];
    char canalOrigem; // s-site, a-app, m-mkp
    float valor;
    time_t horario;

    pedido *prox;
};

struct fila
{
    pedido *inicio;
    pedido *fim;
    int tamFila;
};

canal *criarFila()
{
    canal *f = (canal *)malloc(sizeof(canal));
    if (f == NULL)
        return NULL;

    f->inicio = NULL;
    f->fim = NULL;
    f->tamFila = 0;

    return f;
}

pedido *criaPedido(int id, char *nome, char canal, float valor)
{
    pedido *novo = (pedido *)malloc(sizeof(pedido));
    if (novo == NULL)
        return NULL;

    novo->id = id;
    strcpy(novo->nomeCliente, nome);
    novo->canalOrigem = canal;
    novo->valor = valor;
    time(&novo->horario);
    novo->prox = NULL;

    return novo;
}

void enqueue(canal *f, pedido *novo)
{
    if (f == NULL)
        return;

    if (f->inicio == NULL)
    {
        f->inicio = novo;
    }
    else
    {
        f->fim->prox = novo;
    }

    f->fim = novo;

    f->tamFila++;
}

void listaFila(canal *f)
{
    pedido *inicio = f->inicio;

    while (inicio != NULL)
    {

        printf("===Produtos==\n");
        printf("ID: %d\n", inicio->id);
        printf("Nome clinte: %s\n", inicio->nomeCliente);
        printf("Canal de Origem: %c\n", inicio->canalOrigem);
        printf("Valor total : R$%.2f\n", inicio->valor);

        inicio =  inicio->prox;
    }
}

canal *concatenaFila(canal *f_site, canal *f_app, canal *f_mkp)
{
    canal *armazem = criarFila();

    while (f_site->inicio != NULL ||
           f_app->inicio != NULL ||
           f_mkp->inicio != NULL)
    {
        pedido *menor = NULL;
        canal *origem = NULL;

        if (f_site->inicio != NULL)
        {
            menor = f_site->inicio;
            origem = f_site;
        }

        if (f_app->inicio != NULL &&
            (menor == NULL || f_app->inicio->horario < menor->horario))
        {
            menor = f_app->inicio;
            origem = f_app;
        }

        if (f_mkp->inicio != NULL &&
            (menor == NULL || f_mkp->inicio->horario < menor->horario))
        {
            menor = f_mkp->inicio;
            origem = f_mkp;
        }

        origem->inicio = menor->prox;
        origem->tamFila--;

        if (origem->inicio == NULL)
            origem->fim = NULL;

        menor->prox = NULL;

        enqueue(armazem, menor);
    }

    return armazem;
}

int totalPedidosCanal(canal *f)
{
    return f->tamFila;
}

int totalPedidosEnvio(canal *f_armazem)
{
    return f_armazem->tamFila;
}
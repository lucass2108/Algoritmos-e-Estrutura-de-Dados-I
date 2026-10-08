#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tad_pedidos.h"
#include <time.h>

typedef struct Pedido Pedido;

typedef struct Fila Fila;

struct Pedido
{
    int id;
    char nome[30];
    char canal[30];
    float valor;
    time_t hora;
    Pedido *prox;
};

struct Fila
{
    Pedido *inicio;
    Pedido *fim;
    int tam;
};

//*********TAD FILA BÁSICO************//
// Aloca uma fila vazia
Fila *aloca_fila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL)
        return NULL;

    f->tam = 0;
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

// Verifica se a fila está vazia
// Retorna 1 para vazia e 0 para não vazia
int fila_vazia(Fila *f)
{
    if (f->inicio == NULL)
        return 1;

    return 0;
}

// Insere um pedido na fila (enqueue)
void fila_inserir(Fila *f, Pedido *p)
{
    if (p == NULL)
        return;

    if (f->inicio == NULL)
    {
        f->inicio = p;
    }
    else
    {
        f->fim->prox = p;
    }

    f->fim = p;

    f->tam++;
}

// Remove um pedido da fila (dequeue)
Pedido *fila_remover(Fila *f)
{

    if (f == NULL || f->inicio == NULL)
        return NULL;

    Pedido *aux = f->inicio;

    f->inicio = f->inicio->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    f->tam--;

    aux->prox = NULL;

    return aux;
}

// Remove todos os elementos da fila e libera memória
void fila_liberar(Fila *f)
{
    if (f == NULL)
        return;

    while (f->inicio != NULL)
    {
        Pedido *p = fila_remover(f);
        liberaPedido(p);
    }

    free(f);
}

//******PROCESSAR OS PEDIDOS**********//
// Lista os pedidos de uma fila, sem removê-los da mesma
// printf("%d\t%s\t%s\t%f\t%%lld\n", ...);
void listaFila(Fila *f)
{
    if (f->inicio == NULL)
        return;

    Pedido *aux = f->inicio;

    while (aux != NULL)
    {
        imprimePedido(aux);
        aux = aux->prox;
    }
}

void imprimePedido(Pedido *p)
{
    printf("%d\t%s\t%s\t%.2f\t\n", p->id, p->nome, p->canal, p->valor);
}

// Aloca pedido
// Usar static time_t contador = 1790778920;
// E setar o p->horario = contador++; //o moodle aloca os pedidos ao mesmo tempo
// por isso não dá diferença entre os tempos e dá erro na lógica de concatenação depois
Pedido *alocaPedido(int id, char *cliente, char *canal, float valor)
{

    static time_t contador = 1790778920; // Preserva o valor entre chamadas

    Pedido *p = (Pedido *)malloc(sizeof(Pedido));
    if (!p)
    {
        return NULL;
    }

    p->id = id;
    strcpy(p->nome, cliente);
    strcpy(p->canal, canal);
    p->valor = valor;
    p->hora = contador++; // Incrementa a cada pedido alocado
    p->prox = NULL;

    return p;
}

// Libera a memória do pedido
void liberaPedido(Pedido *p)
{
    free(p);
}

// Concatena as filas dos três canais e retorna a fila do depósito
Fila *fila_concatenar(Fila *site, Fila *app, Fila *mkt)
{
    Fila *deposito = aloca_fila();
    if (deposito == NULL)
        return NULL;

    Pedido *pSite, *pApp, *pMkt, *menor;

    while (!fila_vazia(site) || !fila_vazia(app) || !fila_vazia(mkt))
    {
        pSite = NULL;
        pApp = NULL;
        pMkt = NULL;
        menor = NULL;

        if (!fila_vazia(site))
            pSite = site->inicio;

        if (!fila_vazia(app))
            pApp = app->inicio;

        if (!fila_vazia(mkt))
            pMkt = mkt->inicio;

        if (pSite != NULL)
            menor = pSite;

        if (pApp != NULL)
            if (menor == NULL || pApp->hora < menor->hora)
                menor = pApp;

        if (pMkt != NULL)
            if (menor == NULL || pMkt->hora < menor->hora)
                menor = pMkt;

        if (menor == pSite)
        {
            menor = fila_remover(site);
        }
        else if (menor == pApp)
        {
            menor = fila_remover(app);
        }
        else
        {
            menor = fila_remover(mkt);
        }

        fila_inserir(deposito, menor);
    }

    return deposito;
}

// Imprime o total de pedidos por canal
//  printf("Site: %d\n" ...
void relatorios_canal(Fila *site, Fila *app, Fila *mkt)
{
    printf("Site: %d\nApp: %d\nMarketplace: %d\n", site->tam, app->tam, mkt->tam);
}

// Imprime o total de pedidos na fila de processamento do depósito
//  printf("Fila de Processamento: %d\n", ...
void relatorios_deposito(Fila *f)
{
    printf("Fila de Processamento: %d", f->tam);
}
#include <stdio.h>
#include <stdlib.h>
#include "tad_abp.h"

typedef struct arvore abp;
typedef struct no noAbp;

struct arvore
{
    noAbp *raiz;
};

struct no
{
    int chave;
    noAbp *esq;
    noAbp *dir;
};

abp *criaArvore()
{
    abp *novo = (abp *)malloc(sizeof(abp));
    if (novo == NULL)
        return NULL;

    novo->raiz = NULL;

    return novo;
}

int insereNo(abp *arv, int valor)
{
    if (!arv)
        return -1;

    noAbp *novo = (noAbp *)malloc(sizeof(noAbp));
    if (novo == NULL)
        return -1;

    novo->chave = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if (arv->raiz == NULL)
    {
        arv->raiz = novo;
        return 1;
    }

    noAbp *aux = arv->raiz;
    noAbp *ant = NULL;

    while (aux != NULL)
    {
        ant = aux;

        if (valor < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (valor < ant->chave)
        ant->esq = novo;
    else
        ant->dir = novo;

    return 1;
}

int carregarArv(abp *arv, char *nomeArq)
{
    if (!arv)
        return -1;

    FILE *arq = fopen(nomeArq, "r");
    if (!arq)
        return -1;

    int a;

    while (!feof(arq))
    {
        fscanf(arq, "%d", &a);
        insereNo(arv, a);
    }

    return 1;
}

void imprimeArv(noAbp *no, int tipo)
{
    if (no == NULL)
        return;

    // 1 - ordem, 2- pre ordem, 3- pos ordem
    if (tipo == 1)
    {
        imprimeArv(no->esq, tipo);
        printf("%d --", no->chave);
        imprimeArv(no->dir, tipo);
    }
    else if (tipo == 2)
    {
        printf("%d --", no->chave);
        imprimeArv(no->esq, tipo);
        imprimeArv(no->dir, tipo);
    }
    else if (tipo == 3)
    {
        imprimeArv(no->esq, tipo);
        imprimeArv(no->dir, tipo);
        printf("%d --", no->chave);
    }
    else
    {
        return;
    }
}

void mostraSArvDir(noAbp *no, int valor)
{
    if (!no)
        return;

    noAbp *aux = no;

    while (aux->chave != valor && aux != NULL)
    {
        if (valor < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (aux->dir == NULL)
    {
        printf("sem arvore a direita");
        return;
    }

    printf("%d --", aux->chave);

    aux = aux->dir;

    imprimeArv(aux, 2);
}

void mostraSArvEsq(noAbp *no, int valor)
{
    if (!no)
        return;

    noAbp *aux = no;

    while (aux->chave != valor && aux != NULL)
    {
        if (valor < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (aux->esq == NULL)
    {
        printf("sem arvore a direita");
        return;
    }

    printf("%d --", aux->chave);

    aux = aux->esq;

    imprimeArv(aux, 2);
}

void mostraPaifilho(noAbp *no, int valor)
{
    if (!no)
        return;

    noAbp *ant = NULL;
    noAbp *aux = no;

    while (aux->chave != valor && aux != NULL)
    {
        ant = aux;
        if (valor < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (ant != NULL)
        printf("Pai: %d ", ant->chave);

    if (aux->dir != NULL)
        printf("Filho Dir: %d ", aux->dir->chave);

    if (aux->esq != NULL)
        printf("filho Esq: %d ", aux->esq->chave);

    printf("\n");
}

noAbp *getRaix(abp *arv)
{
    if (!arv)
        return NULL;

    return arv->raiz;
}

int isomorfas(noAbp *a, noAbp *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return isomorfas(a->esq, b->esq) && isomorfas(a->dir, b->dir);
}

int igual(noAbp *a, noAbp *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    if (a->chave != b->chave)
        return 0;

    return isomorfas(a->esq, b->esq) && isomorfas(a->dir, b->dir);
}
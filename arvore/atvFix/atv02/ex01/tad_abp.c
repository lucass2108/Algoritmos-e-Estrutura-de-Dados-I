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

int remover(abp *arv, int valor)
{
    if (!arv || arv->raiz == NULL)
        return -1;

    noAbp *aux = arv->raiz;
    noAbp *pai = NULL;
    // busca
    while (aux != NULL && aux->chave != valor)
    {
        pai = aux;

        if (valor < aux->chave)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (aux == NULL)
        return -1;

    // GRAU 2
    if (aux->dir != NULL && aux->esq != NULL)
    {
        // PREDECESSOR
        noAbp *prede = aux->esq;
        pai = aux;

        while (prede->dir != NULL)
        {
            pai = prede;
            prede = prede->dir;
        }

        aux->chave = prede->chave;
        aux = prede;
    }

    // GRAU 1
    if (aux->esq != NULL || aux->dir != NULL)
    {
        if (aux == arv->raiz)
        {
            if (aux->esq != NULL)
                arv->raiz = aux->esq;
            else
                arv->raiz = aux->dir;
        }

        if (aux == pai->esq)
        {
            if (aux->esq != NULL)
                pai->esq = aux->esq;
            else
                pai->esq = aux->dir;
        }
        else
        {
            if (aux->esq != NULL)
                pai->dir = aux->esq;
            else
                pai->dir = aux->dir;
        }
    }

    // GRAU 0
    if (aux->dir == NULL && aux->esq == NULL)
    {
        if (aux == arv->raiz)
        {
            arv->raiz = NULL;
        }

        if (aux == pai->esq)
            pai->esq = NULL;
        else
            pai->dir = NULL;
    }

    free(aux);

    return 1;
}
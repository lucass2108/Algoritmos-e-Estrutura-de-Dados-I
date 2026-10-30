#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct noArvore noArvore;
typedef struct arvore arvore;

struct noArvore
{
    int chave;
    struct noArvore *esq;
    struct noArvore *dir;
};

struct arvore
{
    struct noArvore *raiz;
};

arvore *criaArvore()
{
    arvore *aux = (arvore *)malloc(sizeof(arvore));
    if (aux == NULL)
        return NULL;

    aux->raiz = NULL;

    return aux;
}

noArvore *criaNo(int valor)
{
    noArvore *novo = (noArvore *)malloc(sizeof(noArvore));
    if (novo == NULL)
        return NULL;

    novo->chave = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

void insereRec(noArvore **raiz, noArvore *novo)
{
    if (novo == NULL)
        return;

    if (*raiz == NULL)
    {
        *raiz = novo;
        return;
    }

    if (novo->chave < (*raiz)->chave)
    {
        insereRec(&(*raiz)->esq, novo);
    }
    else if (novo->chave > (*raiz)->chave)
    {
        insereRec(&(*raiz)->dir, novo);
    }
}

void insere(arvore *a, noArvore *novo)
{
    if (a == NULL || novo == NULL)
        return;

    insereRec(&a->raiz, novo);
}

void imprimeRec(noArvore *raiz, int nivel)
{
    if (raiz == NULL)
        return;

    imprimeRec(raiz->dir, nivel + 1);

    for (int i = 0; i < nivel; i++)
        printf("    ");

    printf("%d\n", raiz->chave);

    imprimeRec(raiz->esq, nivel + 1);
}

void imprimeArvore(arvore *a)
{
    if (a == NULL)
        return;

    imprimeRec(a->raiz, 0);
}

noArvore *buscaRec(noArvore *raiz, int valor)
{
    if (raiz == NULL)
        return NULL;

    if (raiz->chave == valor)
        return raiz;

    if (valor < raiz->chave)
        return buscaRec(raiz->esq, valor);

    return buscaRec(raiz->dir, valor);
}

int busca(arvore *a, int valor)
{
    if (a == NULL)
        return 0;

    return buscaRec(a->raiz, valor) != NULL;
}
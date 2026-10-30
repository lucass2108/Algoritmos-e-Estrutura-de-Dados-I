#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
    int chave;
    noABP *fEsq;
    noABP *fDir;
};

struct arvore
{
    noABP *raiz;
};

abp *alocaArvore()
{
    abp *aux = (abp *)malloc(sizeof(abp));
    if (aux == NULL)
        return NULL;

    aux->raiz = NULL;

    return aux;
}

noABP *alocaNo(int chave)
{
    noABP *aux = (noABP *)malloc(sizeof(noABP));
    if (aux == NULL)
        return NULL;

    aux->fDir = NULL;
    aux->fEsq = NULL;
    aux->chave = chave;

    return aux;
}

int insereNo(abp *arv, noABP *novoNo)
{
    if (!arv || !novoNo)
        return -1;

    if (arv->raiz == NULL)
    {
        arv->raiz = novoNo;
        return 1;
    }

    noABP *ant = NULL;
    noABP *aux = arv->raiz;

    while (aux != NULL)
    {
        ant = aux;
        if (novoNo->chave < aux->chave)
        {
            aux = aux->fEsq;
        }
        else
        {
            aux = aux->fDir;
        }
    }

    if (novoNo->chave < ant->chave)

        ant->fEsq = novoNo;
    else
        ant->fDir = novoNo;

    return 1;
}

noABP *getRaiz(abp *arv)
{
    if(arv  == NULL)
    return NULL;

    return arv->raiz;
}

void percorre(noABP *no)
{
    if (no == NULL)
        return;

    printf("%d -- ", no->chave);
    percorre(no->fEsq);
    percorre(no->fDir);
}

int carregaArv(abp *arv, char *nomeArq)
{
    if (!arv)
        return -1;

    FILE *arq = fopen(nomeArq, "r");
    if (!arq)
        return -1;

    int valor, res;
    noABP *aux = NULL;

    while (!feof(arq))
    {
        fscanf(arq, "%d", &valor);
        aux = alocaNo(valor);
        if (!aux)
            return -1;

        res = insereNo(arv, aux);
        if (res == -1)
            return -1;
    }

    return 1;
}
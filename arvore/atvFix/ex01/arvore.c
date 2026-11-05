#include <stdio.h>
#include <stdlib.h>

typedef struct no noABP;
typedef struct arvore abp;

struct no
{
    int chave;
    noABP *esq;
    noABP *dir;
};

struct arvore
{
    noABP *raiz;
};

abp *criaArv()
{
    abp *arv = (abp *)malloc(sizeof(abp));
    if (!arv)
        return NULL;

    arv->raiz = NULL;

    return arv;
}

int insereNo(abp *arv, int valor)
{
    if (!arv)
        return -1;

    noABP *novo = (noABP *)malloc(sizeof(noABP));
    if (!novo)
        return -1;

    novo->chave = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (arv->raiz == NULL)
    {
        arv->raiz = novo;
        novo->esq = NULL;
        novo->dir = NULL;
        return -1;
    }

    noABP *ant = NULL;
    noABP *aux = arv->raiz;

    while (aux != NULL)
    {
        ant = aux;
        if (novo->chave < aux->chave)
        {
            aux = aux->esq;
        }
        else
        {
            aux = aux->dir;
        }
    }

    if (novo->chave < ant->chave)
    {
        ant->esq = novo;
    }
    else
    {
        ant->dir = novo;
    }

    return 1;
}

int carregaArv(abp *arv, char *nomeArq)
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

void percorreOrdem(noABP *no)
{
    // esp -> raiz -> dir
    if (no == NULL)
        return;

    percorreOrdem(no->dir);
    printf("%d --", no->chave);
    percorreOrdem(no->esq);
}

void percorrepreOrdem(noABP *no)
{
    if (no == NULL)
        return;

    printf("%d --", no->chave);
    percorrepreOrdem(no->esq);
    percorrepreOrdem(no->dir);
}

noABP *getRaiz(abp *arv)
{
    if (!arv)
        return NULL;

    return arv->raiz;
}

int maiorValor(noABP *no)
{
    if (no == NULL)
        return -1;

    if (no->dir == NULL)
        return no->chave;

    return maiorValor(no->dir);
}

int menorValor(noABP *no)
{
    if (no == NULL)
        return -1;

    if (no->esq == NULL)
        return no->chave;

    return menorValor(no->esq);
}

int altura(noABP *no)
{
    if (no == NULL)
        return -1;

    int altEsq = altura(no->esq);
    int altDir = altura(no->dir);

    if (altEsq > altDir)
        return 1 + altEsq;
    else
        return 1 + altDir;
}

int quant(noABP *no)
{
    if (!no)
        return 0;

    return 1 + quant(no->dir) + quant(no->esq);
}

int quantFolhas(noABP *no)
{
    if (!no)
        return 0;

    if (no->dir == NULL && no->esq == NULL)
        return 1;

    int res = quantFolhas(no->dir);
    int res2 = quantFolhas(no->esq);

    return res + res2;
}

int quantNoInterno(noABP *no)
{
    if (!no)
        return 0;

    if (no->esq == NULL && no->dir == NULL)
        return 0;

    return quant(no) - quantFolhas(no);
}

int arvEstBin(noABP *no)
{
    if (!no)
        return -1;

    int a = 0;
    if (no->dir == NULL || no->esq == NULL)
    {
        if (no->dir == NULL)
            a++;

        if (no->esq == NULL)
            a++;
    }

    if (a == 1)
        return 0;

    if(arvEstBin(no->dir) != 0 && arvEstBin(no->esq) != 0)
    {
        return 0;
    }

    return 1;
}
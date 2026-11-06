#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_DIC.h"

typedef struct abp dic;
typedef struct no pal;

struct abp
{
    pal *raiz;
};

struct no
{
    char pal[10];
    char desc[40];
    pal *esq;
    pal *dir;
};

dic *criaDic()
{
    dic *novoDic = (dic *)malloc(sizeof(dic));
    if (novoDic == NULL)
        return NULL;

    novoDic->raiz = NULL;

    return novoDic;
}

pal *criaNo(char palavra[10], char significado[30])
{
    pal *novoPal = (pal *)malloc(sizeof(pal));
    if (novoPal == NULL)
        return NULL;

    novoPal->dir = NULL;
    novoPal->esq = NULL;
    strcpy(novoPal->pal, palavra);
    strcpy(novoPal->desc, significado);

    return novoPal;
}

// lê uma lista de palavras de um arquivo e a insere no dicionário
void carregaDicionario(dic *dicionario, char nomeArquivo[20])
{
    if (!dicionario)
        return;

    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq)
        return;

    char pal[11];
    char desc[40];

    while (!feof(arq))
    {
        fgets(pal, 11, arq);
        fgets(desc, 40, arq);

        pal[strcspn(pal, "\r\n")] = '\0';
        desc[strcspn(desc, "\r\n")] = '\0';

        inserePalavra(dicionario, criaNo(pal, desc));
    }

    fclose(arq);
}

// Insere uma palavra no dicionário
void inserePalavra(dic *dicionario, pal *novaPalavra)
{
    if (!dicionario || !novaPalavra)
        return;

    if (dicionario->raiz == NULL)
    {
        dicionario->raiz = novaPalavra;
        return;
    }

    pal *aux = getRaiz(dicionario);
    pal *ant = NULL;

    while (aux != NULL)
    {
        ant = aux;
        if (strcmp(novaPalavra->pal, aux->pal) < 0)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    if (strcmp(novaPalavra->pal, ant->pal) < 0)
        ant->esq = novaPalavra;
    else
        ant->dir = novaPalavra;
}

// Busca a palavra no dicionário e imprime na tela o significado
// Se não encontrar a palavra, chama a função que busca por palavras com o
// mesmo prefixo (4 caracteres) para sugerir outras palavras
void buscaPalavra(dic *dicionario, char palavra[11])
{
    if (!dicionario)
        return;

    pal *aux = dicionario->raiz;

    while (aux != NULL)
    {
        if (strcmp(aux->pal, palavra) == 0)
        {
            printf("%s : %s\n", palavra, aux->desc);
            return;
        }

        if (strcmp(palavra, aux->pal) < 0)
            aux = aux->esq;
        else
            aux = aux->dir;
    }

    char str[4];
    for (int i = 0; i < 3; i++)
    {
        str[i] = palavra[i];
    }

    str[3] = '\0';

    printf("Palavra não encontrada - Sugestões:\n");
    sugerePalavras(getRaiz(dicionario), str);
}

// busca por palavras que tem o mesmo prefixo da palavra solicitada
// Retorna um vetor com essas palavras
void sugerePalavras(pal *no, char *prefixo)
{
    if (!no)
        return;

    char str[4];
    for (int i = 0; i < 3; i++)
    {
        str[i] = no->pal[i];
    }

    str[3] = '\0';

    if (strcmp(str, prefixo) == 0)
        printf("%s\n", no->pal);

    sugerePalavras(no->esq, prefixo);
    sugerePalavras(no->dir, prefixo);
}

// Mostra palavras do dicionário em pré-ordem
void percorrePreOrdem(pal *palavra)
{
    if (!palavra)
        return;

    printf("%s\n", palavra->pal);
    percorrePreOrdem(palavra->esq);
    percorrePreOrdem(palavra->dir);
}

// Mostra palavras do dicionário em ordem alfabética
void percorreEmOrdem(pal *palavra)
{
    if (!palavra)
        return;

    percorreEmOrdem(palavra->esq);
    printf("%s\n", palavra->pal);
    percorreEmOrdem(palavra->dir);
}

// Mostra palavras do dicionário em ordem alfabética
void percorrePosOrdem(pal *palavra)
{
    if (!palavra)
        return;

    percorrePosOrdem(palavra->dir);
    printf("%s\n", palavra->pal);
    percorrePosOrdem(palavra->esq);
}

// Retorna a raiz da árvore
pal *getRaiz(dic *dicionario)
{
    if (!dicionario)
        return NULL;

    return dicionario->raiz;
}
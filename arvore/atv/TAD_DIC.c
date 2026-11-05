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
void carregaDicionario(dic *dicionario, char nomeArquivo[20]);

// Insere uma palavra no dicionário
void inserePalavra(dic *dicionario, pal *novaPalavra);

// Busca a palavra no dicionário e imprime na tela o significado
// Se não encontrar a palavra, chama a função que busca por palavras com o
// mesmo prefixo (4 caracteres) para sugerir outras palavras
void buscaPalavra(dic *dicionario, char palavra[11]);

// busca por palavras que tem o mesmo prefixo da palavra solicitada
// Retorna um vetor com essas palavras
void sugerePalavras(pal *no, char *prefixo);

// Mostra palavras do dicionário em pré-ordem
void percorrePreOrdem(pal *palavra);

// Mostra palavras do dicionário em ordem alfabética
void percorreEmOrdem(pal *palavra);

// Mostra palavras do dicionário em ordem alfabética
void percorrePosOrdem(pal *palavra);

// Retorna a raiz da árvore
pal *getRaiz(dic *dicionario);
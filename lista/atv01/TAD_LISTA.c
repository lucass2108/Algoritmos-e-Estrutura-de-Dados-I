#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA.h"

typedef struct lista TLista;
typedef struct no TProduto;

struct lista
{
    int tam;
    TProduto *inicio;
};

struct no
{
    int id;
    float valor;
    int quant;
    TProduto *prox;
};

// aloca uma lista vazia
TLista *alocaLista()
{
    TLista *l = (TLista *)malloc(sizeof(TLista));
    if (l == NULL)
        return NULL;

    l->tam = 0;
    l->inicio = NULL;

    return l;
}

// aloca e inicializa um produto
TProduto *alocaProduto(int codigo, float preco, int qtdEstoque)
{
    TProduto *p = (TProduto *)malloc(sizeof(TProduto));
    if (p == NULL)
        return NULL;

    p->id = codigo;
    p->quant = qtdEstoque;
    p->valor = preco;
    p->prox = NULL;

    return p;
}

// insere um produto na lista não ordenada -> inserir no começo da lista
// retorna 1 se inseriu corretamente e -1 se houver erro de qualquer natureza
int cadastraProduto(TLista *l, TProduto *novoProduto)
{
    if (l == NULL || novoProduto == NULL)
        return -1;

    if (l->inicio == NULL)
    {
        l->inicio = novoProduto;
        return 1;
    }

    novoProduto->prox = l->inicio;
    l->inicio = novoProduto;

    return 1;
}

// atualiza o preço de todos os produtos com base na taxa
// taxa é um inteiro que representa a % de desconto e deve ser maior que 0 e menor ou igual 100
int atualizaPreco(TLista *l, int taxa)
{
    if (l->inicio == NULL)
        return -1;

    if (taxa < 0 || taxa > 100)
        return -1;

    TProduto *aux = l->inicio;

    while (aux != NULL)
    {
        aux->valor = aux->valor - (aux->valor * (taxa / 100.0));
        aux->valor = (int)(aux->valor * 100 + 0.01) / 100.0;

        aux = aux->prox;
    }

    return 1;
}

// imprime os produtos na tela
// printf("%d\t%0.2f\t%d\n", ...
void imprimeProdutos(TLista *l)
{
    if (l->inicio == NULL)
        return;

    TProduto *aux = l->inicio;
    while (aux != NULL)
    {
        printf("%d\t%.2f\t%d\n", aux->id, aux->valor, aux->quant);
        aux = aux->prox;
    }
}

// imprime o total de produtos que tenham quantidade maior que 500 unidades no estoque
// printf("Total de Produtos com quantidade maior que 500 : %d\n", ...
void imprimeTotal(TLista *l)
{
    if (l->inicio == NULL)
        return;

    TProduto *aux = l->inicio;
    int mais500 = 0;

    while (aux != NULL)
    {
        if (aux->quant > 500)
            mais500++;

        aux = aux->prox;
    }

    printf("Total de Produtos com quantidade maior que 500 : %d\n", mais500);
}

// esvazia e libera a lista
void liberaLista(TLista *l)
{
    if (l->inicio == NULL)
        return;

    TProduto *aux = l->inicio;
    TProduto *auxAux;

    while (aux != NULL)
    {
        auxAux = aux->prox;
        free(aux);
        aux = auxAux;
    }

    free(l);
}

// Lê os dados do arquivo e insere na lista
int carregaProdutos(TLista *l, char *nomeArquivo)
{
    FILE *arq = fopen(nomeArquivo, "r");
    if (!arq)
        return -1;

    int id, quant;
    float valor;

    while (!feof(arq))
    {
        fscanf(arq, "%d %f %d", &id, &valor, &quant);
        TProduto *p = alocaProduto(id, valor, quant);
        cadastraProduto(l, p);
    }

    return 1;
}

#ifndef TAD_ARVORE_H
#define TAD_ARVORE_H

typedef struct no noABP;
typedef struct arvore abp;

abp *criaArv();

int insereNo(abp *arv, int valor);

int carregaArv(abp *arv, char *nomeArq);

void percorreOrdem(noABP *no);

void percorrepreOrdem(noABP *no);

noABP *getRaiz(abp *arv);

int maiorValor(noABP *no);

int menorValor(noABP *no);

int altura(noABP *no);

int quant(noABP *no);

int quantFolhas(noABP *no);

int quantNoInterno(noABP *no);

int arvEstBin(noABP *no);

#endif
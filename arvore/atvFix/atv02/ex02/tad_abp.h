#ifndef TAD_ABP_H
#define TAD_ABP_H

typedef struct arvore abp;
typedef struct no noAbp;

abp *criaArvore();

int insereNo(abp *arv, int valor);

int carregarArv(abp *arv, char *nomeArq);

void imprimeArv(noAbp *no, int tipo);

void mostraSArvDir(noAbp *no, int valor);

void mostraSArvEsq(noAbp *no, int valor);

void mostraPaifilho(noAbp *no, int valor);

noAbp *getRaix(abp *arv);

int isomorfas(noAbp *a, noAbp *b);

int igual(noAbp *a, noAbp *b);

#endif
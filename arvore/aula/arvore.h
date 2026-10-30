#ifndef ARVORE_H
#define ARVORE_H

typedef struct no noABP;
typedef struct arvore abp;

abp *alocaArvore();

noABP *alocaNo(int chave);

int insereNo(abp *arv, noABP *novoNo);

noABP *getRaiz(abp *arv);

void percorre(noABP *no);


int carregaArv(abp *arv, char *nomeArq);

#endif
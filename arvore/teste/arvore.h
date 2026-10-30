#ifndef ARVORE_H
#define ARVORE_H

typedef struct noArvore noArvore;
typedef struct arvore arvore;

arvore *criaArvore();

noArvore *criaNo(int valor);

void insereRec(noArvore **raiz, noArvore *novo);

void insere(arvore *a, noArvore *novo);

void imprimeRec(noArvore *raiz, int nivel);

void imprimeArvore(arvore *a);

noArvore *buscaRec(noArvore *raiz, int valor);

int busca(arvore *a, int valor);

#endif
#ifndef TAD_PILHA_H
#define TAD_PILHA_H

typedef struct pilha pilha;
typedef struct no noPilha;

pilha *criaPilha();

void push(pilha *p, int valor);

int pop(pilha *p);

int contaMaiores(pilha *p, int x);


#endif
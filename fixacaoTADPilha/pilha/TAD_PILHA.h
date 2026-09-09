#ifndef TAD_PILHA_H
#define TAD_PILHA_H

typedef struct Pilha pilha;
typedef struct No noPilha;

pilha *criaPilha();

void push(pilha *p, int valor);

int pop(pilha *p);

void esvazia(pilha *p);

int pilhaVazia(pilha *p);

void liberaPilha(pilha *p);

void TPilha(pilha *p, int num[]);

#endif
#ifndef TADPILHA_H
#define TADPILHA_H

typedef struct pilha *Pilha;

Pilha criaPilha();

void push(Pilha p, int valor);

int pop(Pilha p);

int top(Pilha p);

void esvazia(Pilha p);

int pilhaVazia(Pilha p);

#endif
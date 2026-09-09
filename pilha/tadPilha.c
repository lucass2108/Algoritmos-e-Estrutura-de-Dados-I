#include "tadPilha.h"
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;

struct pilha {
    No *topo;
};

Pilha criaPilha() {
    Pilha p = malloc(sizeof(struct pilha));

    if (p != NULL) {
        p->topo = NULL;
    }

    return p;
}

int pilhaVazia(Pilha p) {
    return p->topo == NULL;
}

void push(Pilha p, int valor) {
    No *novo = malloc(sizeof(No));

    novo->dado = valor;
    novo->prox = p->topo;

    p->topo = novo;
}

int pop(Pilha p) {
    No *aux = p->topo;
    int valor = aux->dado;

    p->topo = aux->prox;

    free(aux);

    return valor;
}

int top(Pilha p) {
    return p->topo->dado;
}

void esvazia(Pilha p) {
    while (!pilhaVazia(p)) {
        pop(p);
    }
}
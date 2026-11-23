//
// Created by Vanessa on 19/11/2025.
//

#include "pilhaC.h"
#include <stdlib.h>


struct pilhaC{
    noC *topo;
};
 
struct noC{
    char elemento;
    noC *prox;
};

pC *criaPilha()
{
    pC *novaPilha = (pC*)malloc(sizeof (pC));
    if (!novaPilha)
        return NULL;

    novaPilha->topo = NULL;

    return novaPilha;
}

noC *criaNo(char valor)
{    noC *novoNo = (noC*)malloc(sizeof (noC));
    if (!novoNo)
        return NULL;

    novoNo->elemento = valor;
    novoNo->prox = NULL;

    return novoNo;
}

void empilha(pC *p, noC *novoNo)
{
    if(p->topo == NULL) //pilha vazia
    {
        p->topo = novoNo;
        return;
    }

    novoNo->prox = p->topo;
    p->topo = novoNo;
}

noC *desempilha(pC *p)
{
    if(p->topo == NULL)
        return NULL;

    noC *aux = p->topo;
    p->topo = p->topo->prox;

    return aux;
}

char retornaElemento(pC *p)
{
    if(!p || p->topo == NULL)
        return ' ';
    return p->topo->elemento;
}

void destroiPilha(pC *p)
{
    while(p->topo != NULL)
        desempilha(p);

    free(p);
}

//**********FILA*****************//
struct fila{
    noC *cabeca;
    noC *fim;
};

fila *criaFila()
{
    fila *novaFila = (fila*)malloc(sizeof (fila));
    if (!novaFila)
        return NULL;

    novaFila->cabeca = NULL;
    novaFila->fim = NULL;

    return novaFila;
}

void enfileirar(fila *f, noC *novoNo)
{
    novoNo->prox = NULL;
    if(f->cabeca == NULL)
    {
        f->cabeca = novoNo;
        f->fim = novoNo;
        return;
    }

    f->fim->prox = novoNo;
    f->fim = novoNo;
}

void destroiFila(fila *f)
{
    while(f->cabeca != NULL)
    {
        noC *aux = f->cabeca;
        f->cabeca = aux->prox;
        free(aux);
    }
    free(f);
}

noC *retornaCabeca(fila *f)
{
    return f->cabeca;
}

noC *retornaProx(noC *aux)
{
    return aux->prox;
}

char retornaToken(noC *aux)
{
    return aux->elemento;
}



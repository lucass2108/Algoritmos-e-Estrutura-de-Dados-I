#include <stdlib.h>
#include <stdio.h>
#include "TAD_PILHA.h"

typedef struct Pilha pilha;
typedef struct No noPilha;

struct Pilha
{
    noPilha *topo;
};

struct No
{
    int valor;
    noPilha *prox;
};

pilha *criaPilha()
{
    // aloca para p o espaço da struct pilha
    pilha *p = (pilha *)malloc(sizeof(pilha));

    // senn houver memória disponivel devolve NULL
    if (p == NULL)
        return NULL;

    // deixa o topo vazio
    p->topo = NULL;

    return p;
}

void push(pilha *p, int valor)
{
    // cria um novo no
    noPilha *novo = (noPilha *)malloc(sizeof(noPilha));

    // se nn der retorna
    if (novo == NULL)
        return;

    // define o valor do novo nó
    novo->valor = valor;

    // como smp entra por cima definimos o proximo como o topo
    novo->prox = p->topo;

    // define o topo como o novo no
    p->topo = novo;
}

int pop(pilha *p)
{
    // se o topo estiver vazio cancela
    if (p->topo == NULL)
        return 0;

    // guarda o topo
    noPilha *aux = p->topo;

    // guarda o valor do topo
    int valor = aux->valor;

    // define o topo como o prox do antigo topo
    p->topo = aux->prox;

    // libera a aux
    free(aux);

    // retorna o valor
    return valor;
}

int pilhaVazia(pilha *p)
{
    // retorna 1se vazio e 0 se nn
    return p->topo == NULL;
}

void esvazia(pilha *p)
{
    while (!pilhaVazia(p))
        pop(p);
}

void liberaPilha(pilha *p)
{
    esvazia(p);
    free(p);
}

void TPilha(pilha *p, int num[])
{
    for(int i = 0; i < 15; i++)
    {
        if(num[i] % 2 == 0)
        {
            push(p, num[i]);
        }
        else
        {
            pop(p);
        }
    }

    while (!pilhaVazia(p))
    {
        printf("%d\t", pop(p));
    }
    
}
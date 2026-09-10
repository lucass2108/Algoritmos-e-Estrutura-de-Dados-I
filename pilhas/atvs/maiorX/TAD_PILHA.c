#include <stdlib.h>
#include <stdio.h>

typedef struct pilha pilha;
typedef struct no noPilha;

struct pilha
{
    noPilha *topo;
    int tam;
};

struct no
{
    int valor;
    noPilha *prox;
};

pilha *criaPilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    
    if(p == NULL)
        return NULL;

    p->topo = NULL;
    p->tam = 0;

    return p;
}

void push(pilha *p, int valor)
{
    noPilha *novo = (noPilha *)malloc(sizeof(noPilha));
    if(novo == NULL)
        return;

    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;

    p->tam++;
}

int pop(pilha *p)
{
    if(p->topo == NULL)
        return 0;

    noPilha *antigo = p->topo;
    int aux = antigo->valor;

    p->topo = p->topo->prox;

    free(antigo);

    p->tam--;

    return aux;
}

int contaMaiores(pilha *p, int x)
{
    int tam = p->tam, maior = 0;
    int array[tam]; 

    for(int i = 0; i < tam; i++)
    {
        array[i] = pop(p);
        if(array[i] > x)
            maior++;
    }

    for(int i = tam -1; i >=0; i--)
    {
        push(p, array[i]);
    }

    return maior;
}
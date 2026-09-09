#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "TAD_PILHA_CHAR.h"

typedef struct pilha pChar;
typedef struct no noChar;

struct pilha
{
    noChar *topo;
};

struct no
{
    char caracter;
    noChar *prox;
};

// Função que aloca uma pilha vazia
pChar *criaPilha()
{
    pChar *novaPilha = (pChar *)malloc(sizeof(pChar));

    if (novaPilha == NULL)
    {
        return NULL;
    }

    novaPilha->topo = NULL;

    return novaPilha;
}

// Função que aloca um novo nó e o insere na pilha
void push(pChar *p, char valor)
{
    noChar *novoNo = (noChar *)malloc(sizeof(noChar));

    if (novoNo == NULL)
        return;

    novoNo->caracter = valor;
    novoNo->prox = p->topo;

    p->topo = novoNo;
}

// Função que retorna o elemento do topo da pilha
char pop(pChar *p)
{
    if (p->topo == NULL)
        return '\0';

    noChar *aux = p->topo;
    char valor = aux->caracter;

    p->topo = aux->prox;

    free(aux);

    return valor;
}

// Função que remove todos os elementos da pilha
void esvazia(pChar *p){
    while(!pilhaVazia(p))
        pop(p);
}

// Função que verifica se uma pilha está vazia
// Retorna 1 se estiver vazia e 0 se não estiver
int pilhaVazia(pChar *p)
{
    return p->topo == NULL;
}

// Função que verifica se a expressão matemática passada está balanceada
// Retorna 1 se estiver balanceada : todos os símbolos de abertura e fechamento estão balanceados
// Retorna 0 caso contrário
int verificarExpressao(pChar *p, char *expressao)
{
    for (int i = 0; expressao[i] != '\0'; i++)
    {
        char c = expressao[i];

        // Símbolos de abertura
        if (c == '(' || c == '[' || c == '{')
        {
            push(p, c);
        }

        // Símbolos de fechamento
        else if (c == ')' || c == ']' || c == '}')
        {
            if (pilhaVazia(p))
                return 0;

            char topo = pop(p);

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{'))
            {
                return 0;
            }
        }
    }

    // Se ainda tem abertura na pilha, está desbalanceada
    if (!pilhaVazia(p))
        return 0;
 
    return 1;
}

// Função que esvazia e desaloca uma pilha
void liberaPilha(pChar *p)
{
    esvazia(p);
    free(p);
}

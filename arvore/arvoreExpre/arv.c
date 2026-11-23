#include <stdio.h>
#include <stdlib.h>
#include "arvExpressao.h"

typedef struct arvExpr arv;
typedef struct noArv noArvore;
typedef struct pilhaArv pArvore;
typedef struct NopilhaArv noPArvore;

struct arvExpr
{
    noArvore *raiz;
};

struct noArv
{
    char token;
    noArvore *esq;
    noArvore *dir;
};

struct pilhaArv
{
    noPArvore *topo;
};

struct NopilhaArv
{
    noArvore *no;
    noPArvore *prox;
};

// Cria a árvore de expressão aritmética
arv *criaArvoreExpressao()
{
    arv *nova = (arv *)malloc(sizeof(arv));
    if (!nova)
        return NULL;

    nova->raiz = NULL;

    return nova;
}

// Cria o nó da árvore de expressão aritmética
noArvore *criaNoArvore(char token)
{
    noArvore *novo = (noArvore *)malloc(sizeof(noArvore));
    if (!novo)
        return NULL;

    novo->token = token;
    novo->dir = NULL;
    novo->esq = NULL;

    return novo;
}

// Cria uma pilha cujos nós contém um nó de árvore (noArvore)
pArvore *criaPilhaArvore()
{
    pArvore *novo = (pArvore *)malloc(sizeof(pArvore));
    if (!novo)
        return NULL;

    novo->topo = NULL;

    return novo;
}

// Cria nó da pArvore
noPArvore *criaNoPArvore(noArvore *novoNo)
{
    noPArvore *novo = (noPArvore *)malloc(sizeof(noPArvore));
    if (!novo)
        return NULL;

    novo->no = novoNo;
    novo->prox = NULL;

    return novo;
}

// Função que define a prioridade dos operadores:
// Se + ou - => prioridade 1
// Se * ou / => prioridade 2
// Qualquer outro símbolo tem prioridade 0
int prioridade(char token)
{
    if (token == '+' || token == '-')
        return 1;
    else if (token == '*' || token == '/')
        return 2;
    else
        return 0;
}

// Implementa o Shunting Yard Algorithm
// Para cada token da expressão segue os passos do algoritmo
// No final da função, a expressão posfix está armazenada na fila e a pilha estará vazia
void converteExpressao(char *expressao, pC *p, fila *f)
{
    if (!p || !f)
        return;

    int i = 0;
    char token;
    while (expressao[i] != '\0')
    {
        token = expressao[i];

        if (token == ' ')
        {
            i++;
            continue;
        }

        if ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z'))
        {
            enfileirar(f, criaNo(token));
        }
        else if (token == '(')
        {
            empilha(p, criaNo(token));
        }
        else if (token == ')')
        {
            while (retornaElemento(p) != '(' && retornaElemento(p) != ' ')
            {
                enfileirar(f, desempilha(p));
            }

            if (retornaElemento(p) == '(')
                desempilha(p);
        }
        else
        {
            while (retornaElemento(p) != ' ' && prioridade(retornaElemento(p)) >= prioridade(token))
            {
                enfileirar(f, desempilha(p));
            }

            empilha(p, criaNo(token));
        }

        i++;
    }

    while (retornaElemento(p) != ' ')
    {
        enfileirar(f, desempilha(p));
    }
}

// Implementa a Stack-Based Expression Tree Construction
// Avalia cada posição da fila para gerar a árvore
// Usa uma pilha (pArvore) como auxiliar
// Após processar todos os elementos da fila, a raiz da árvore deve ser o nó que está no topo da pilha
void geraArvoreExpressao(fila *f, arv *a)
{
    if (!a || !f)
        return;

    pArvore *p = criaPilhaArvore();
    noC *aux = retornaCabeca(f);
    noArvore *no = NULL;

    char token;

    while (aux != NULL)
    {
        token = retornaToken(aux);
        no = criaNoArvore(token);

        processaToken(p, no);

        aux = retornaProx(aux);
    }

    a->raiz = desempilhaNoArvore(p);
}

// Função chamada pela geraArvoreExpressao para empilhar o novoNo na pilha (pArvore)
// Considera as regras do algoritmo. Ou seja, se é operando ou operador
void processaToken(pArvore *pArv, noArvore *novoNo)
{
    if (!pArv || !novoNo)
        return;

    if (prioridade(novoNo->token) > 0)
    {
        novoNo->dir = desempilhaNoArvore(pArv);
        novoNo->esq = desempilhaNoArvore(pArv);
    }

    empilhaNoArvore(pArv, criaNoPArvore(novoNo));
}

// Empilha o novoNo na pilha
// Função chamada pela função processaToken
void empilhaNoArvore(pArvore *pArv, noPArvore *novoNo)
{
    if (!pArv || !novoNo)
        return;

    if (pArv->topo == NULL)
    {
        pArv->topo = novoNo;
        return;
    }

    noPArvore *aux = pArv->topo;
    novoNo->prox = aux;
    pArv->topo = novoNo;
}

// Desempilha e retorna o topo da pilha
// Função chamada pela função processaToken
noArvore *desempilhaNoArvore(pArvore *pArv)
{
    if (!pArv || pArv->topo == NULL)
        return NULL;

    noPArvore *aux = pArv->topo;
    pArv->topo = aux->prox;

    return aux->no;
}

// Função recursiva que faz o percorrimento em pós-ordem (esq-dir-raiz)
// Retorna o resultado numérico da expressão avaliada
float avaliaExpressao(noArvore *no, float a, float b)
{
    if (no == NULL)
        return 0;

    if (no->esq == NULL && no->dir == NULL)
    {
        if (no->token == 'a')
            return a;

        if (no->token == 'b')
            return b;

        if (no->token >= '0' && no->token <= '9')
            return no->token - '0';
    }

    float esq = avaliaExpressao(no->esq, a, b);
    float dir = avaliaExpressao(no->dir, a, b);

    switch (no->token)
    {
    case '+':
        return esq + dir;

    case '-':
        return esq - dir;

    case '*':
        return esq * dir;

    case '/':
        if (dir == 0)
            return 0;
        return esq / dir;
    }

    return 0;
}

// Retorna a raiz da árvore de expressão
noArvore *retornaRaiz(arv *arvExpr)
{
    if (!arvExpr)
        return NULL;

    return arvExpr->raiz;
}

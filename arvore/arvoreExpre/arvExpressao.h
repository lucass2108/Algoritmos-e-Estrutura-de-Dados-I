//
// Created by Vanessa on 19/11/2025.
//

#ifndef ARVEXPRESSAO_ARVEXPRESSAO_H
#define ARVEXPRESSAO_ARVEXPRESSAO_H

#include "pilhaC.h"

typedef struct arvExpr arv;
typedef struct noArv noArvore;
typedef struct pilhaArv pArvore;
typedef struct NopilhaArv noPArvore;

//Cria a árvore de expressão aritmética
arv *criaArvoreExpressao();

//Cria o nó da árvore de expressão aritmética
noArvore *criaNoArvore(char token);

//Cria uma pilha cujos nós contém um nó de árvore (noArvore)
pArvore *criaPilhaArvore();

//Cria nó da pArvore
noPArvore *criaNoPArvore(noArvore *novoNo);

//Função que define a prioridade dos operadores:
//Se + ou - => prioridade 1
//Se * ou / => prioridade 2
//Qualquer outro símbolo tem prioridade 0
int prioridade(char token);

//Implementa o Shunting Yard Algorithm
//Para cada token da expressão segue os passos do algoritmo
//No final da função, a expressão posfix está armazenada na fila e a pilha estará vazia
void converteExpressao(char *expressao, pC *p, fila *f);

//Implementa a Stack-Based Expression Tree Construction
//Avalia cada posição da fila para gerar a árvore
//Usa uma pilha (pArvore) como auxiliar
//Após processar todos os elementos da fila, a raiz da árvore deve ser o nó que está no topo da pilha
void geraArvoreExpressao(fila *f, arv *a);

//Função chamada pela geraArvoreExpressao para empilhar o novoNo na pilha (pArvore)
//Considera as regras do algoritmo. Ou seja, se é operando ou operador
void processaToken(pArvore *pArv, noArvore *novoNo);

//Empilha o novoNo na pilha
//Função chamada pela função processaToken
void empilhaNoArvore(pArvore *pArv, noPArvore *novoNo);

//Desempilha e retorna o topo da pilha
//Função chamada pela função processaToken
noArvore *desempilhaNoArvore(pArvore *pArv);

//Função recursiva que faz o percorrimento em pós-ordem (esq-dir-raiz)
//Retorna o resultado numérico da expressão avaliada
float avaliaExpressao(noArvore *no, float a, float b);

//Retorna a raiz da árvore de expressão
noArvore *retornaRaiz(arv *arvExpr);

#endif //ARVEXPRESSAO_ARVEXPRESSAO_H

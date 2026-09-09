//
// Created by Vanessa on 27/08/2026.
//

#ifndef Q3_TAD_PILHA_CHAR_H
#define Q3_TAD_PILHA_CHAR_H

typedef struct pilha pChar;
typedef struct no noChar; 

//Função que aloca uma pilha vazia
pChar *criaPilha();

//Função que aloca um novo nó e o insere na pilha
void push(pChar *p, char valor);

//Função que retorna o elemento do topo da pilha
char pop(pChar *p);  

//Função que remove todos os elementos da pilha
void esvazia(pChar *p);

//Função que verifica se uma pilha está vazia
//Retorna 1 se estiver vazia e 0 se não estiver
int pilhaVazia(pChar *p);

//Função que verifica se a expressão matemática passada está balanceada
//Retorna 1 se estiver balanceada : todos os símbolos de abertura e fechamento estão balanceados
//Retorna 0 caso contrário
int verificarExpressao(pChar *p, char *expressao);

//Função que esvazia e desaloca uma pilha
void liberaPilha(pChar *p);

#endif //Q3_TAD_PILHA_CHAR_H

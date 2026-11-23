//
// Created by Vanessa on 19/11/2025.
//

#ifndef ARVEXPRESSAO_PILHAC_H
#define ARVEXPRESSAO_PILHAC_H

typedef struct pilhaC pC;
typedef struct noC noC;
typedef struct fila fila;
 

//************PILHA DE CARACTERE***************//
//Cria uma pilha
pC *criaPilha();

//cria um nó de caractere
noC *criaNo(char valor);

//Insere o novoNo na pilha
void empilha(pC *p, noC *novoNo);

//Desempilha o topo da pilha
//Retorna o nó que está no topo
noC *desempilha(pC *p);

//Retorna o elemento (token) do topo da pilha
char retornaElemento(pC *p);

//Remove todos os elementos da pilha
void destroiPilha(pC *p);

//*******FILA DE CARACTERE *********************//
//Cria uma fila de caracteres
fila *criaFila();

//Insere o novoNo no início da fila
//Em alguns momentos, o novoNo vem da pilha, por isso, nessa função, é preciso setar o
//prox do novoNo para NULL
void enfileirar(fila *f, noC *novoNo);

//Retorna o nó que está na cabeça da fila
noC *retornaCabeca(fila *f);

//Retorna o prox nó da cabeça da fila
noC *retornaProx(noC *aux);

//Retorna o token do nó
char retornaToken(noC *aux);

//Remove todos os elementos da fila
void destroiFila(fila *f);

#endif //ARVEXPRESSAO_PILHAC_H

#ifndef TADFILA_H
#define TADFILA_H

typedef struct fila filaInt;
typedef struct no noFila;

// cria estrutura de fila vazia
filaInt *criaFila();

// insere elemento no fim da fila
void enqueue(filaInt *f, int valor);

// tira elemento do inicio da fila
int dequeue(filaInt *f);

// mostra o começo da fila
void comecoFila(filaInt *f);

// esvazia a fila
void esvazia(filaInt *f);

// verifica se a fila está vazia
int filaVazia(filaInt *f);

// retorna tamanho da fila
int tamanhoFila(filaInt *f);

#endif
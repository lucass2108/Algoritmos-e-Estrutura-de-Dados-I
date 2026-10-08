//
// Created by Vanessa on 30/09/2026.
//

#ifndef Q1_ECOMMERCE_TAD_PEDIDOS_H
#define Q1_ECOMMERCE_TAD_PEDIDOS_H

#include <time.h>

typedef struct Pedido Pedido;

typedef struct Fila Fila;

//*********TAD FILA BÁSICO************//
//Aloca uma fila vazia
Fila *aloca_fila();

//Verifica se a fila está vazia 
//Retorna 1 para vazia e 0 para não vazia
int fila_vazia(Fila *f);

//Insere um pedido na fila (enqueue)
void fila_inserir(Fila *f, Pedido *p);

//Remove um pedido da fila (dequeue)
Pedido *fila_remover(Fila *f);

//Remove todos os elementos da fila e libera memória
void fila_liberar(Fila *f);

//******PROCESSAR OS PEDIDOS**********//
//Lista os pedidos de uma fila, sem removê-los da mesma
//printf("%d\t%s\t%s\t%f\t%%lld\n", ...);
void listaFila(Fila *f);

void imprimePedido(Pedido *p);

//Aloca pedido
//Usar static time_t contador = 1790778920;
//E setar o p->horario = contador++; //o moodle aloca os pedidos ao mesmo tempo
//por isso não dá diferença entre os tempos e dá erro na lógica de concatenação depois
Pedido *alocaPedido(int id, char *cliente, char *canal, float valor);

//Libera a memória do pedido
void liberaPedido(Pedido *p);


//Concatena as filas dos três canais e retorna a fila do depósito
Fila* fila_concatenar(Fila *site, Fila *app, Fila *mkt);

//Imprime o total de pedidos por canal
// printf("Site: %d\n" ...
void relatorios_canal(Fila *site, Fila *app, Fila *mkt);

//Imprime o total de pedidos na fila de processamento do depósito
// printf("Fila de Processamento: %d\n", ...
void relatorios_deposito(Fila *f);

#endif //Q1_ECOMMERCE_TAD_PEDIDOS_H

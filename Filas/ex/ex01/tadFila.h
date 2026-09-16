#ifndef TADFILA_H
#define TADFILA_H

typedef struct fila canal;
typedef struct no pedido;

canal *criarFila();

pedido *criaPedido(int id, char *nome, char canal, float valor);

void enqueue(canal *f, pedido *novo);

void listaFila(canal *f);

canal *concatenaFila(canal *f_site, canal *f_app, canal *f_mkp);

void processaPedido(canal *f_aramazem);

int totalPedidosCanal(canal *f);

int totalPedidosEnvio(canal *f_armazem);

#endif
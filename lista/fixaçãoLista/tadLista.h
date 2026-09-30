#ifndef TADLISTA_H
#define TADLISTA_H

typedef struct lista lista;
typedef struct No produto;

lista *criaLista();

void inserirLista(lista *l, int id, float valor, int quant);

produto *retirarFila(lista *l);

void desconto(lista *l, float desc);

void imprimeLista(lista *l);

void relatorio(lista *l);

#endif
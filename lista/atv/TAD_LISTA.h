//
// Created by Vanessa on 30/09/2026.
//

#ifndef LISTA_TAD_LISTA_H
#define LISTA_TAD_LISTA_H
 
//**LISTA SIMPLESMENTE ENCADEADA***//
typedef struct listaSE TListaSE;

typedef struct no TNo;

TListaSE *alocaLista();

TNo *alocaNo(int valor);

int insereComecoLista(TListaSE *l, int valor);

int insereOrdenadoLista(TListaSE *l, int valor);

void imprimeListaSE(TListaSE *l);

//**LISTA DUPLAMENTE ENCADEADA***//
typedef struct listaDE TListaDE;

typedef struct noDE TNoDE;

TListaDE *alocaListaDE();

TNoDE *alocaNoDE(int valor);

int insereComecoListaDE(TListaDE *l, int valor);

int insereOrdenadoListaDE(TListaDE *l, int valor);

void imprimeListaDE(TListaDE *l);




#endif //LISTA_TAD_LISTA_H

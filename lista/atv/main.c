#include <stdio.h>
#include "TAD_LISTA.h"

int main() {
    TListaSE *lSE_i = alocaLista();
    TListaSE *lSE_o = alocaLista();

    if(!lSE_i || !lSE_o)
        return -1; 

    int vet[7] = {5, 2, 4,8, 47, 12,65};

    for (int i=0; i<7; i++)
    {
        insereComecoLista(lSE_i, vet[i]);
        insereOrdenadoLista(lSE_o, vet[i]);
    }
    imprimeListaSE(lSE_i);
    imprimeListaSE(lSE_o);

    /*
    TListaDE *lSE_i = alocaListaDE();
    TListaDE *lSE_o = alocaListaDE();

    if(!lSE_i || !lSE_o)
        return -1;

    int vet[7] = {5, 2, 4,8, 47, 12,65};

    for (int i=0; i<7; i++)
    {
        insereComecoListaDE(lSE_i, vet[i]);
        insereOrdenadoListaDE(lSE_o, vet[i]);
    }
   imprimeListaDE(lSE_i);
   imprimeListaDE(lSE_o);

    return 0;
    */ 
}

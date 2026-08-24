#include <stdio.h>
#include "candidatos.h"

int main(){

    int n;

    scanf("%d",&n);

    candidato *lista = criaListaCandidato(n);
    if(!lista) return -1;

    operacoes(lista, n);

    liberaCandidato(lista);

    return 0 ;
}
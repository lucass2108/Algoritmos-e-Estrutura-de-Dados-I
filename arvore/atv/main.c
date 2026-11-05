#include <stdio.h>
#include "TAD_DIC.h"
#include <string.h>

int main() {
    char nomeArquivo[20];
    char palavra[11];
    int tipoPercorrimento;
    dic *D = criaDic();
    scanf("%s", nomeArquivo);
    scanf("%s", palavra);
    scanf("%d", &tipoPercorrimento);

    carregaDicionario(D, nomeArquivo); 
    buscaPalavra(D, palavra);

    if(tipoPercorrimento == 1)
    {
        printf("Percorrimento em pré-ordem\n");
        percorrePreOrdem(getRaiz(D));
        return 0;
    }

    if (tipoPercorrimento == 2)
    {
        printf("\nPercorrimento em Ordem Alfabética\n");
        percorreEmOrdem(getRaiz(D));
        return 0;
    }

    if (tipoPercorrimento == 3)
    {
        printf("\nPercorrimento em Ordem Decrescente\n");
        percorrePosOrdem(getRaiz(D));
        return 0;
    }

}









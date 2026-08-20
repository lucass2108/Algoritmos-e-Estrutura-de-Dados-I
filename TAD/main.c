#include <stdio.h>
#include <stdlib.h>
#include "tadvet.h"

int main()
{
    char nomeArquivo[30] = "";
    int *vet;
    int tam, res;

    printf("Digite o nome do arquivo:");
    scanf("%s", nomeArquivo);

    printf("Digite a quantidadede dados do arquivo:");
    scanf("%d", &tam);

    vet = criaVet(tam);
    if (!vet)
    {
        printf("ERRO ao criar vet");
        return -1;
    }

    res = preencheVet(vet, tam, nomeArquivo);
    if (res == 0)
    {
        printf("ERRO ao preencher arq");
        return -1;
    }

    imprimeVet(vet, tam);

    printf("%d\n", acessarElemento(vet, 2));
    atribuiElemento(vet, 2, 98);
    printf("%d\n", acessarElemento(vet, 2));

    return 0;
}
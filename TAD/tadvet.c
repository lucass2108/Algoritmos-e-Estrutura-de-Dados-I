#include "tadVet.h"
#include <stdio.h>
#include <stdlib.h>

// Aloca e retorna um vetor de inteiros de tamamho tam
int *criaVet(int tam)
{
    int *vet;

    vet = (int *)malloc(tam * sizeof(int));
    if (!vet)
    {
        return 0;
    }

    return vet;
}

// Libera a memória do vetor
void libera(int *vet)
{
    free(vet);
}

// Retorna elemento X do vetor
int acessarElemento(int *vet, int pos)
{
    return vet[pos];
}

// Atribui valor a pos x do vetor
void atribuiElemento(int *vet, int pos, int valor)
{
    vet[pos] = valor;
}

// Retorna quantidade de elementos

// Preenche o vetor com valores do arquivo
// Retorna 1 se nn der erros e 0 se der
int preencheVet(int *vet, int tam, char nomeArquivo[])
{
    FILE *arq;
    int i = 0;

    arq = fopen(nomeArquivo, "r");
    if (!arq)
        return 0;

    while (!feof(arq) && i < tam)
    {
        fscanf(arq, "%d", &vet[i]);
        i++;
    }

    fclose(arq);

    return 1;
}

// Imprime o vetor
void imprimeVet(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\t", vet[i]);
    }
    printf("\n");
}

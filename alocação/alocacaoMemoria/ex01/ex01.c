#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int carregarVetor(char *nomeArquivo, int **vet)
{
    FILE *arq;
    int tamanho;
    int i = 0;

    arq = fopen(nomeArquivo, "r");
    if (!arq)
        return -1;

    fscanf(arq, "%d", &tamanho);

    *vet = (int *)malloc(tamanho * sizeof(int));
    if (!*vet)
        return -2;

    while (!feof(arq))
    {
        fscanf(arq, "%d", &(*vet)[i]);
        i++;
    }

    fclose(arq);

    return tamanho;
}

void imprimir(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }

    printf("\n");
}

int somar(int *vet, int tam)
{
    int soma = 0;

    for(int i = 0; i < tam; i++)
    {
        soma  += vet[i];
    }

    return soma;
}

int main()
{
    char nomeArquivo[30] = "alocacaoMemoria\\ex01\\nums.txt";
    int *vet;
    int tam;

    tam = carregarVetor(nomeArquivo, &vet);

    imprimir(vet, tam);

    printf("%d", somar(vet, tam));

    free(vet);

    return 0;
}
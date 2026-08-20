#include <stdio.h>
#include <string.h>

int carregarVetor(char nomeArquivo[], int vetor[], int tam)
{
    FILE *arq;
    int a;
    arq = fopen(nomeArquivo, "r");
    if (!arq)
    {
        return -1;
    }

    int i = 0;
    while (!feof(arq))
    {
        fscanf(arq, "%d", &a);
        vetor[i] = a;
        i++;
    }

    fclose(arq);

    return 1;
}

void menorValor(int vetor[], int tam)
{
}

int imprimeValor(int vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d\n", vet[i]);
    }
}

int escreveVetor(char nomeArquivo[])
{
}

int somaVetor(int vet[], int tam, int valor, char vetSaida[])
{
    FILE *arq2;
    for (int i = 0; i < tam; i++)
    {
        vet[i] = vet[i] + valor;
    }

    vetSaida = fopen(vetSaida, "w");
    if (!arq2)
    {
        return -1;
    }

    for (int i = 0; i < tam; i++)
    {
        
    }
}

int main()
{
    char nomeArquivo[30] = "ex01\\pratica01\\entrada.txt";
    char nomeArquivoSaida = "ex01\\pratica01\\entrada2.txt";
    int vetor[20];
    int valor;

    int res = carregarVetor(nomeArquivo, vetor, 15);
    if (res == -1)
    {
        printf("ERROR");
        return -1;
    }

    imprimeValor(vetor, 15);

    return 1;
}
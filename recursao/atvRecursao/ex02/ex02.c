#include <stdio.h>

int maiorRecDiv(int vet[], int inicio, int fim)
{
    printf("%d\t%d\n", inicio, fim);

    if (inicio == fim)
        return vet[inicio];

    int meio = (inicio + fim) / 2;

    int l = maiorRecDiv(vet, inicio, meio);

    int m = maiorRecDiv(vet, meio + 1, fim);

    if (l > m)
        return l;

    return m;
}

int main()
{
    int vet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int inicio = vet[0];
    int fim = vet[sizeof(vet) / sizeof(vet[0]) - 1];

    printf("O maior elemento do vetor e: %d", maiorRecDiv(vet, 0, 9));

    return 0;
}
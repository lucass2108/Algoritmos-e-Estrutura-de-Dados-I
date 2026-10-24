#include <stdio.h>

int maiorRecursivo(int vet[], int n)
{
    if (n == 1)
        return vet[0];

    int m = maiorRecursivo(vet, n - 1);

    if (vet[n - 1] > m)
        return vet[n - 1];

    return m;

        return 1;
}

int main()
{
    int vet[] = {2, 85, 85, 6, 0, 122, 8, 1024, 9, 3};
    int n = sizeof(vet) / sizeof(vet[0]);

    int maior = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (vet[i] > maior)
            maior = vet[i];
    }

    printf("%d\n", maior);
    printf("O maior elemento do vetor e: %d", maiorRecursivo(vet, 10));

    return 0;
}
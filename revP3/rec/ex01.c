#include <stdio.h>

int maiorRecursivo(int vet[], int n)
{
    if (n == 1)
        return vet[0];

    int res = maiorRecursivo(vet, n - 1);

    if (vet[n - 1] > n)
        return vet[n - 1];
    else
        return res;
}

int main()
{
    int vet[]= {10, 15, 88, 0, 1, -89};
    int n = sizeof(vet)/sizeof(vet[0]);

    printf("%d", maiorRecursivo(vet, n));

    return 0;
}
#include <stdio.h>

void geraSequenciais(int vet[], int pos, int n)
{
    if (pos == n)
        for (int i = 0; i < n; i++)
            printf("%d", vet[i]);

    printf("\n");
    return;

    vet[pos] = 0;
    geraSequenciais(vet, pos + 1, n);

    vet[pos] = 1;
    geraSequenciais(vet, pos + 1, n);
}

int main()
{
    int vet[3];

    geraSequenciais(vet, 0, 3);

    return 0;
}
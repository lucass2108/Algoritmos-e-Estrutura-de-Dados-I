#include <stdio.h>
#include <time.h>

void geraSequenciais(int vet[], int pos, int n, int *chamadas)
{
    (*chamadas)++;
    if (pos == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", vet[i]);

        printf("\n");
        return;
    }


    vet[pos] = 0;
    geraSequenciais(vet, pos + 1, n, chamadas);

    vet[pos] = 1;
    geraSequenciais(vet, pos + 1, n, chamadas);
}

int main()
{
    int n;
    scanf("%d", &n);

    int chamadas = 0;

    int vet[n];
    clock_t inicio,fim;
    double tempo_gasto;

    inicio = clock();

    geraSequenciais(vet, 0, n, &chamadas);

    fim = clock();

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Chamadas: %lld\n", chamadas);
    printf("Tempo: %f segundos\n", tempo_gasto);

    return 0;
}
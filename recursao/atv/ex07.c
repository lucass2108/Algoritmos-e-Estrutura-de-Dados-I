#include <stdio.h>

int buscaB(int vet[], int i, int tam, int n)
{
    if (i > tam)
        return -1;

    int pos = (i + tam) / 2;

    if (vet[pos] == n)
        return pos;

    if (vet[pos] > n)
    {
        return buscaB(vet, i, pos - 1, n);
    }

    if(vet[pos] < n)
    {
        return buscaB(vet, pos + 1, tam, n);
    }

    return -1;
}

int main()
{
    int vet[] = {-65,2,75,452,1024,1025,1026,10001,10002};
    int tam = sizeof(vet) / sizeof(vet[0]);
    int n = 75;
    int res;

    int i = 0;
    int fim = tam - 1;
    while (i <= fim)
    {
        int pos = (i + fim) / 2;
        res = pos;

        // Igual
        if (vet[pos] == n)
            break;

        // Menor
        if (vet[pos] > n)
            fim = pos - 1;

        // Maior
        if (vet[pos] < n)
            i = pos + 1;
    }

    printf("%d\n%d", res, buscaB(vet,i, fim, n));

    return 0;
}
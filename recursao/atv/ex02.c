#include <stdio.h>

void imprimeNum(int i, int lim)
{
    if (i > lim)
        return;

    printf("%d ", i);

    imprimeNum(i + 1, lim);
}

int main()
{
    int n = 1, lim;
    scanf("%d", &lim);

    for (int i = 1; i <= lim; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    imprimeNum(n, lim);

    return 0;
}

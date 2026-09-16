#include <stdlib.h>
#include <stdio.h>
#include "tadFila.h"

int main()
{
    filaInt *f = criaFila();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);

        enqueue(f, temp);
    }

    printf("%d\n", tamanhoFila(f));

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", dequeue(f));
    }

    return 0;
}
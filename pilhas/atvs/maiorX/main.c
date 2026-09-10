#include <stdlib.h>
#include <stdio.h>
#include "TAD_PILHA.h"

int main()
{
    pilha *p = criaPilha();

    int tam;
    scanf("%d", &tam);


    // 10 20 30 40 50
    // 50 40 30 20 10
    for(int i = 0; i < tam; i ++)
    {
        int valor;
        scanf("%d", &valor);
        push(p, valor);
    }

    int x;
    scanf("%d", &x);

    printf("%d\n", contaMaiores(p, x));

    for(int i = 0; i < tam; i++)
    {
        printf("%d\t", pop(p));
    }

    return 0;
}
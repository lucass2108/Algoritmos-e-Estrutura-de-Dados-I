#include <stdio.h>
#include "tadPilha.h"

int main()
{
    Pilha p;
    p = criaPilha();

    for (int i = 0; i < 5; i++)
    {
        int temp;
        scanf("%d", &temp);
        push(p, temp);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d", top(p));
        pop(p);
    }

    esvazia(p);

    return 0;
}
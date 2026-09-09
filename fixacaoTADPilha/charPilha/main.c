#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TAD_PILHA.h"

int main()
{
    pilha *p = criaPilha();
    char str[16];

    fgets(str, 15, stdin);

    str[strcspn(str, "\n")] = '\0';

    int i = 0;

    if(TPilha(p, str) == 1)
    {
        printf("VERDADEIRO");
    }
    else{
        printf("FALSO");
    }


    return 0;
}
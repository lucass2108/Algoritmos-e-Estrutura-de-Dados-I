#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "TAD_PILHA.h"

int main()
{
    char str[30];
    fgets(str, 30, stdin);
    str[strcspn(str,"\n")] = '\0';

    pilha *p = criaPilha();

    TPilha(p, str);

    return 0;
}
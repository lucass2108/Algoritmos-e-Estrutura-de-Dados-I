#include <stdio.h>
#include "TAD_PILHA_CHAR.h"

int main() {
    //DECLARAÇÃO DE VARIÁVEIS
    int res;
    char entrada[30];
    pChar *p = criaPilha();
    if (!p)
        return -1;

    fgets(entrada, 30, stdin);

    res = verificarExpressao(p, entrada);
    if (res == 1)
        printf("BALANCEADA");
    else
        printf("DESBALANCEADA");

    liberaPilha(p);
  
    return 0;
}

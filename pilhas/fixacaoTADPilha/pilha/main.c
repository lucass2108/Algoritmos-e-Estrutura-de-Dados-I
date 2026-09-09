#include <stdlib.h>
#include <stdlib.h>
#include "TAD_PILHA.h"

int main()
{
    pilha *p = criaPilha();
    int nums[] = {0,90,45,78,98,25,10,32,65,32,14,17,89,1,56};

    TPilha(p, nums);


    return 0;
}
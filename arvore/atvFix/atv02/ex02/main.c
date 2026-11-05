#include <stdio.h>
#include "tad_abp.h"

int main()
{
    int a[] = {10,5,12,5,89,74};
    int b[] = {9,4,11,4,88,73};

    abp *A = criaArvore();
    abp *B = criaArvore();

    for(int i = 0; i < sizeof(a)/sizeof(a[0]);i++)
    {
        insereNo(A, a[i]);
    }

    for(int i = 0; i < sizeof(b)/sizeof(b[0]);i++)
    {
        insereNo(B, b[i]);
    }

    printf("É isomorfa: %d \nÉ igual: %d \n", isomorfas(getRaix(A), getRaix(B)), igual(getRaix(A), getRaix(B)));

    return 0;
}
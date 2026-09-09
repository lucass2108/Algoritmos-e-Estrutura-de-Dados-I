#include <stdio.h>
#include "tadPilha.h"

void TPilha(Pilha pilha, int vet[])
{
    for (int i = 0; i < 15; i++)
    {
        if (vet[i] % 2 == 0)
        {
            push(pilha, vet[i]);
        }
        else
        {
            if (!pilhaVazia(pilha))
            {
                pop(pilha);
            }
        }
    }

    while (!pilhaVazia(pilha))
    {
        printf("%d ", top(pilha));
        pop(pilha);
    }
}

int main()
{
    int vet[15] = {1, 2, 3, 4, 6, 8, 7, 10, 12, 5, 14, 16, 9, 18, 20};

    Pilha p = criaPilha();

    TPilha(p, vet);

    return 0;
}
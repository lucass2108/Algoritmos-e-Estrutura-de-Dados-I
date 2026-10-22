#include <stdio.h>

void imprimeVetor(int arr[], int tam)
{
    if (tam == 0)
        return;

    printf("%d ", arr[0]);

    imprimeVetor(arr + 1, tam - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    imprimeVetor(arr, n);

    return 0;
}
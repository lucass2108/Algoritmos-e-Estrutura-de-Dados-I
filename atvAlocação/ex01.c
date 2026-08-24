#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void criptografar(char *cadeia, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (cadeia[i] == 'a' || cadeia[i] == 'A' || cadeia[i] == 'e' || cadeia[i] == 'E' || cadeia[i] == 'i' || cadeia[i] == 'I' || cadeia[i] == 'o' || cadeia[i] == 'O' ||
            cadeia[i] == 'u' || cadeia[i] == 'U')
        {
            cadeia[i] = '*';
        }
    }
}

int main()
{
    int n;
    char *cadeia;

    scanf("%d", &n);

    cadeia = (char *)malloc(n * sizeof(char));

    scanf("%s", cadeia);

    printf("%s\n", cadeia);

    criptografar(cadeia, n);

    printf("%s", cadeia);

    free(cadeia);

    return 0;
}
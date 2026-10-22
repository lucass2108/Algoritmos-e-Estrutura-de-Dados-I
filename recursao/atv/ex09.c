#include <stdio.h>
#include <string.h>

char *mensagem(char str[], char str2[], int i)
{
    if (str[i] == '\0')
        return str2;

    str2[strlen(str) - 1 - i] = str[i];

    return mensagem(str, str2, i + 1);
}

int main()
{
    char str[] = "Lucas";
    char str2[strlen(str)];
    char str3[strlen(str)];

    int i = 0;
    while (str[i] != '\0')
    {
        str2[strlen(str) - 1 - i] = str[i];
        i++;
    }

    printf("Iterativo: %s\t%s\n", str, str2);
    i = 0;
    printf("Recursivo: %s\t%s", str, mensagem(str, str3, i));

    return 0;
}
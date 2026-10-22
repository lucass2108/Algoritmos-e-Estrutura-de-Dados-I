#include <stdio.h>
#include <string.h>

int igual(char c, char *str)
{
    if (*str == '\0')
        return 0;

    return (*str == c) + igual(c, str + 1);
}

int main()
{
    char c = 't', str[] = "teste";
    int res = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (c == str[i])
            res++;
    }

    printf("%d\n%d", res, igual(c, str));

    return 0;
}
#include <stdio.h>
#include <string.h>

void imprimirReverso(char str[])
{
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

int verseTemCaractere(char str[], char caractere)
{
    int count = 0;
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == caractere)
        {
            count++;
        }
    }

    return count;
}

void trocarCaractere(char str[], char c1, char c2)
{
    for (int i = 0; i <= strlen(str); i++)
    {
        if (str[i] == c1)
        {
            str[i] = c2;
            break;
        }
    }

    printf("%s\n", str);
}

int main()
{
    char str1[21], str2[21];
    char c1, c2;
    int op = 0;

    fgets(str1, 21, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    while (op != 8)
    {

        // printf("1 - Tamanho da String \n2 - Concatenar\n");
        // printf("3 - Ver String ao contrário \n4 - Ver se tem caractere\n");
        // printf("5 - Trocar caractere \n6 - Ver se é substring\n");
        // printf("7 - Ler nova string \n8 - Sair\n");

        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 1:
            printf("%lu\n", strlen(str1));
            break;
        case 2:
            fgets(str2, 21, stdin);
            str2[strcspn(str2, "\n")] = '\0';

            strcat(str1, str2);
            printf("%s\n", str1);
            break;
        case 3:
            imprimirReverso(str1);
            break;
        case 4:
            scanf("%c", &c1);
            printf("%d\n", verseTemCaractere(str1, c1));
            break;
        case 5:
            scanf(" %c %c", &c1, &c2);
            trocarCaractere(str1, c1, c2);
            break;
        case 6:
            fgets(str2, 21, stdin);
            str2[strcspn(str2, "\n")] = '\0';

            if (strstr(str1, str2) != NULL)
            {
                printf("S\n");
            }
            else
            {
                printf("N\n");
            }
            break;
        case 7:
            fgets(str1, 21, stdin);
            str1[strcspn(str1, "\n")] = '\0';
            break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

void preencherNotas(float notas[10][3], char nomeArquivo[])
{
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        printf("ERROR");
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                fscanf(arq, "%f", &notas[i][j]);
            }
        }
    }

    fclose(arq);
}

void gerarRelatorio(float notas[10][3])
{
    int menorNota1 = 0, menorNota2 = 0, menorNota3 = 0;

    for (int i = 0; i < 10; i++)
    {
        if (notas[i][0] < notas[i][1] && notas[i][0] < notas[i][2])
        {
            menorNota1++;
        }
        else if (notas[i][1] < notas[i][0] && notas[i][1] < notas[i][2])
        {
            menorNota2++;
        }
        else
        {
            menorNota3++;
        }
    }
    printf("%d %d %d\n", menorNota1, menorNota2, menorNota3);
}

int main()
{
    char nomeArquivo[51];
    fgets(nomeArquivo, 51, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    float notas[10][3];

    preencherNotas(notas, nomeArquivo);
    gerarRelatorio(notas);

    return 0;
}

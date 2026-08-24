#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int linhas, int colunas)
{
    int **matriz = (int **)malloc(linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    return matriz;
}

void preencherMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimeMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int **multiplicaMatrizes(int **matrizA, int linhasA, int colunasA, int **matrizB, int linhasB, int colunasB)
{
    if (colunasA != linhasB)
    {
        return NULL;
    }

    int **res = alocarMatriz(linhasA, colunasB);

    for (int i = 0; i < linhasA; i++)
    {
        for (int j = 0; j < colunasB; j++)
        {
            res[i][j] = 0;

            for (int k = 0; k < colunasA; k++)
            {
                res[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    return res;
}

void liberarMatriz(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main()
{
    int linhasA, colunasA, linhasB, colunasB;
    int **matrizA, **matrizB, **res;

    scanf("%d %d", &linhasA, &colunasA);

    matrizA = alocarMatriz(linhasA, colunasA);
    preencherMatriz(matrizA, linhasA, colunasA);

    scanf("%d %d", &linhasB, &colunasB);

    matrizB = alocarMatriz(linhasB, colunasB);
    preencherMatriz(matrizB, linhasB, colunasB);

    res = multiplicaMatrizes(matrizA, linhasA, colunasA, matrizB, linhasB, colunasB);

    if (res == NULL)
    {
        printf("Nao foi possivel multiplicar as matrizes.");
    }
    else
    {
        imprimeMatriz(res, linhasA, colunasB);
        liberarMatriz(res, linhasA);
    }

    liberarMatriz(matrizA, linhasA);
    liberarMatriz(matrizB, linhasB);

    return 0;
}
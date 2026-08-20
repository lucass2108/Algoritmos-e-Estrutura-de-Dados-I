#include <stdio.h>
#include <stdlib.h>

//Assinatura das FunÃ§Ãµes
int **carregaMatriz(char nomeArquivo[], int linhas, int colunas);

void imprimeMatriz(int **mat, int linhas, int colunas);

void liberaMatriz(int **mat, int linhas);

void imprimeSoma(int **mat, int linhas, int colunas);


int main() {
    //DECLARAÃ‡ÃƒO DE VARIÃVEIS
    char nomeArquivo[30] = "alocaçãoMatriz\\4matriz.txt";
    int linhas, colunas;
    int **mat;

    //Ler a qtdade de linhas e colunas
    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &colunas);

    //alocar e carregar a matriz
    mat = carregaMatriz(nomeArquivo, linhas, colunas);
    if (!mat)
    {
        printf("Erro ao alocar matriz");
        return -1;
    }

    //imprimir a matriz
    imprimeMatriz(mat, linhas, colunas);

    //imprimir a soma das linhas
    imprimeSoma(mat, linhas, colunas);

    //desalocar memÃ³ria
    liberaMatriz(mat, linhas);

    return 0;
}

int **carregaMatriz(char nomeArquivo[], int linhas, int colunas)
{
    //DECLARAÃ‡ÃƒO DE VARIÃVEIS
    FILE *arq;
    int **mat;

    //ABRIR O ARQUIVO
    arq = fopen(nomeArquivo, "r");
    if (!arq)
        return NULL;

    //ALOCAR A MATRIZ
    mat = (int**) malloc(linhas * sizeof (int*));
    if (!mat)
    {
        fclose(arq);
        return NULL;
    }


    for(int i=0; i<linhas; i++)
    {
        mat[i] = (int*) malloc(colunas * sizeof(int));
        if (!mat[i])
        {
            liberaMatriz(mat, i);
            fclose(arq);
            return NULL;
        }
    }

    //PREENCHER A MATRIZ
    for(int i=0; i < linhas; i++)
    {
        for(int j=0; j<colunas;j++)
        {
            fscanf(arq, "%d\t", &mat[i][j]);
            if (ferror(arq)){
                return NULL;
            }
        }
    }

    //FECHAR O ARQUIVO
    fclose(arq);

    //RETORNAR A MATRIZ ALOCADA E CARREGADA
    return mat;

}

void imprimeMatriz(int **mat, int linhas, int colunas)
{
    for(int i=0; i< linhas; i++)
    {
        for(int j=0; j < colunas; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void liberaMatriz(int **mat, int linhas)
{
    for(int i=0; i< linhas; i++)
        free(mat[i]);

    free(mat);
}

void imprimeSoma(int **mat, int linhas, int colunas)
{
    int soma;

    printf("-----PROCESSAMENTO---\n");
    for (int i=0; i < linhas; i++)
    {
        soma = 0;
        for (int j=0; j < colunas; j++)
        {
            soma = soma + mat[i][j];
        }
        printf("Soma da linha %d : %d\n", i, soma);
    }
}

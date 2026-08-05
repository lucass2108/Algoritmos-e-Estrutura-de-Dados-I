#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome_produto[51];
    int codigo;
    float preco;
} Produto;

int carregarProdutos(Produto vetor[], char nomeArquivo[])
{
    FILE *arq = fopen(nomeArquivo, "r");

    if (arq == NULL)
    {
        printf("ERROR");
        return 0;
    }

    int i = 0;

    while (i < 100 && fscanf(arq, "%50s %d %f", vetor[i].nome_produto, &vetor[i].codigo, &vetor[i].preco) == 3)
    {
        i++;
    }

    fclose(arq);

    return i;
}

int buscarPorNome(Produto vetor[], int tam, char nomeProduto[])
{
    for (int i = 0; i < tam; i++)
    {
        if (strcmp(vetor[i].nome_produto, nomeProduto) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Produto produtos[100];
    char nomeArquivo[100] = "Ex00\\produtos\\produtos.txt";

    char buscarNome[100];

    int tam = carregarProdutos(produtos, nomeArquivo);

    //  printf("Quantidade lida: %d\n", tam);

    //  for (int i = 0; i < tam; i++) {
    //      printf("%s %d %.2f\n",
    //           produtos[i].nome_produto,
    //           produtos[i].codigo,
    //           produtos[i].preco);
    //}

    scanf("%99s", buscarNome);

    int posicao = buscarPorNome(produtos, tam, buscarNome);

    if (posicao != -1)
    {
        printf("Produto Encontrado: \n");
        printf("Nome: %s\n", produtos[posicao].nome_produto);
        printf("Codigo: %d\n", produtos[posicao].codigo);
        printf("Preco: %.2f\n", produtos[posicao].preco);
    }
    else
    {
        printf("Produto nao encontrado.\n");
    }

    return 0;

    //ok
}
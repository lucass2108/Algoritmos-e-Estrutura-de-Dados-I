#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome_animal[31];
    char categoria[16];
    float quantidade_kg_por_dia;
} Animal;

int carregarAnimais(Animal vetor[], char nomeArquivo[])
{
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        printf("ERROR");
        return 0;
    }

    int i = 0;
    while (i < 100 && fscanf(arq, "%30s %15s %f", vetor[i].nome_animal, vetor[i].categoria, &vetor[i].quantidade_kg_por_dia) == 3)
    {
        i++;
    }

    fclose(arq);

    return i;
}

float carregarMediaPorCategoria(Animal vetor[], int tam, char categoria[])
{
    float media = 0, count = 0;

    for (int i = 0; i < tam; i++)
    {
        if (strcmp(vetor[i].categoria, categoria) == 0)
        {
            media += vetor[i].quantidade_kg_por_dia;
            count++;
        }
    }

    if (count == 0)
    {
        return -1;
    }
    else
    {
        return media / count;
    }
}

float calcularCustoAlimentacao(Animal vetor[], int tam, float valorKg)
{
    float preco = 0;

    for (int i = 0; i < tam; i++)
    {
        preco += vetor[i].quantidade_kg_por_dia;
    }

    preco *= 30;
    preco *= valorKg;

    return preco;
}

int main()
{
    char nomeArquivo[51];
    fgets(nomeArquivo, 51, stdin);

    Animal animais[100];

    nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

    int tam = carregarAnimais(animais, nomeArquivo);

    char nomeCategoria[51];
    fgets(nomeCategoria, 51, stdin);
    nomeCategoria[strcspn(nomeCategoria, "\n")] = '\0';

    printf("Consumo medio: %0.2f\n", carregarMediaPorCategoria(animais, tam, nomeCategoria));

    float precoKg;
    scanf("%f", &precoKg);

    printf("Gasto por mes: %0.2f", calcularCustoAlimentacao(animais, tam, precoKg));

    return 0;
}
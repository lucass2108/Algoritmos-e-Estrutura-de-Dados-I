#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome_do_artista[31];
    char genero[11];
    float total_de_reproducoes;
    float ouvintes_unicos;
} Artista;

typedef struct
{
    char genero[11];
    float ouvintes_unicos;
} Genero;

int carregaDados(Artista vet[], char nomeArquivo[])
{
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
    {
        printf("ERROR");
        return 0;
    }

    for (int i = 0; i < 100; i++)
    {
        if (fscanf(arq, "%[^,],%[^,],%f,%f", vet[i].nome_do_artista, vet[i].genero, &vet[i].total_de_reproducoes, &vet[i].ouvintes_unicos) != 4)
        {
            fclose(arq);
            return i;
        }
    }
    fclose(arq);
    return 100;
}

void imprimeArtistas(Artista vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%s\t%s\t%0.2f\t%0.2f\n", vet[i].nome_do_artista, vet[i].genero, vet[i].total_de_reproducoes, vet[i].ouvintes_unicos);
    }
}

Artista *artistaMaisOuvido(Artista vet[], int tam)
{
    Artista *maisOuvido = &vet[0];

    for (int i = 0; i < tam; i++)
    {
        if (vet[i].total_de_reproducoes > maisOuvido->total_de_reproducoes)
        {
            maisOuvido = &vet[i];
        }
    }
    return maisOuvido;
}

void generoMusicalMaisOuvido(Artista vet[], int tam)
{
    Genero g[100];
    int count = 0;

    for (int i = 0; i < tam; i++)
    {
        int achou = -1;

        for (int j = 0; j < count; j++)
        {
            if (strcmp(vet[i].genero, g[j].genero) == 0)
            {
                achou = j;
                break;
            }
        }

        if (achou == -1)
        {
            strcpy(g[count].genero, vet[i].genero);
            g[count].ouvintes_unicos = vet[i].ouvintes_unicos;
            count++;
        }
        else
        {
            g[achou].ouvintes_unicos += vet[i].ouvintes_unicos;
        }
    }

    int maior = 0;
    for (int i = 0; i < count; i++)
    {
        if (g[i].ouvintes_unicos > g[maior].ouvintes_unicos)
        {
            maior = i;
        }
    }

    printf("%s\t%0.2f", g[maior].genero, g[maior].ouvintes_unicos);
}

int main()
{
    char nomeArquivo[100] = "Ex00\\spotify\\spotify.txt";
    Artista artistas[100];

    int tam = carregaDados(artistas, nomeArquivo);

    imprimeArtistas(artistas, tam);

    Artista *maisPopular = artistaMaisOuvido(artistas, tam);
    printf("\n%s\t%s\t%0.2f\t%0.2f\n", maisPopular->nome_do_artista, maisPopular->genero, maisPopular->total_de_reproducoes, maisPopular->ouvintes_unicos);

    generoMusicalMaisOuvido(artistas, tam);

}
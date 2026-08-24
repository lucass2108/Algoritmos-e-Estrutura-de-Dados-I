#include "candidatos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Candidatos
{
    int id;
    char nome[51];
    char escolaridade[51];
    int anoNas;
    char profissap[51];
};

// Função para alocar dinamicamente um conjunto  de n candidatos e preencher os dados de cada um
// Recebe como entrada N (quantidade de candidatos)
// Retorna um ponteiro para o conjunto alocado
candidato *criaListaCandidato(int n)
{
    candidato *candidatos;
    candidatos = (candidato *)malloc(n * sizeof(candidato));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &candidatos[i].id);
        getchar();

        fgets(candidatos[i].nome, 51, stdin);
        candidatos[i].nome[strcspn(candidatos[i].nome, "\n")] = '\0';

        fgets(candidatos[i].escolaridade, 51, stdin);
        candidatos[i].escolaridade[strcspn(candidatos[i].escolaridade, "\n")] = '\0';

        scanf("%d", &candidatos[i].anoNas);
        getchar();

        fgets(candidatos[i].profissap, 51, stdin);
        candidatos[i].profissap[strcspn(candidatos[i].profissap, "\n")] = '\0';
    }

    return candidatos;
}

// Função para buscar um candidato pela sua identidade
// Recebe como entrada a lista de candidatos, N (quantidade de candidatos) e a identidade a ser procurada
// Retorna um ponteiro para o candidato com a identidade desejada ou NULL caso contrário
candidato *buscaCId(candidato *lista, int n, int identidade)
{
    for (int i = 0; i < n; i++)
    {
        if (lista[i].id == identidade)
        {
            return &lista[i];
        }
    }

    return NULL;
}

// Função para retornar a quantidade de candidatos com uma determinada escolaridade
// Recebe como entrada a lista de candidatos, N (quantidade de candidatos) e a escolaridade desejada
int buscaCE(candidato *lista, int n, char *escolaridade)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (strcmp(lista[i].escolaridade, escolaridade) == 0)
        {
            count++;
        }
    }

    return count;
}

// Função para imprimir na tela nome de todos os candidatos com determinada profissão
// Recebe como entrada a lista de candidatos, N (quantidade de candidatos) e a profissão desejada
// Printf com o nome do candidato: printf("%s\n",...);
void imprimeNomeProf(candidato *lista, int n, char *profissao)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(lista[i].profissap, profissao) == 0)
        {
            printf("%s\n", lista[i].nome);
        }
    }
}

void operacoes(candidato *lista, int n)
{
    int op;

    do
    {
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            int id;
            scanf("%d", &id);

            candidato *res;
            res = buscaCId(lista, n, id);

            if (res == NULL)
            {
                printf("Nao foi possivel localizar o candidato pela sua identidade.\n");
            }
            else
            {
                printf("%s\n", res->nome);
            }

            break;

        case 2:
            char escolaridade[51];
            getchar();
            fgets(escolaridade, 51, stdin);
            escolaridade[strcspn(escolaridade, "\n")] = '\0';

            printf("Total: %d\n", buscaCE(lista, n, escolaridade));

            break;

        case 3:
        char prof[51];
        getchar();
        fgets(prof, 51, stdin);
        prof[strcspn(prof, "\n")] = '\0';

        imprimeNomeProf(lista, n, prof);
            break;

        default:
            break;
        }
    } while (op != 0);
}

// Função para liberar a memória alocada
void liberaCandidato(candidato *lista)
{
    free(lista);
}

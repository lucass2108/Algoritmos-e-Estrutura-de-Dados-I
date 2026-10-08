#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TAD_LISTA_CIRCULAR.h"

struct listaCircular
{
    TAtracao *inicio;
    int tam;
};

struct no
{
    int id;
    char nome[50];
    int hInicio;
    int hFim;
    TAtracao *prox;
};

// Aloca uma lista vazia
TListaC *alocaLista()
{
    TListaC *l = (TListaC *)malloc(sizeof(TListaC));
    if (l == NULL)
        return NULL;

    l->inicio = NULL;
    l->tam = 0;

    return l;
}

// Aloca um novo nó com os dados informados por parâmetro
TAtracao *alocaNo(int cod, char *nome, int h_inicio, int h_fim)
{
    TAtracao *novaAtracao = (TAtracao *)malloc(sizeof(TAtracao));
    if (novaAtracao == NULL)
        return NULL;

    novaAtracao->id = cod;
    strncpy(novaAtracao->nome, nome, sizeof(novaAtracao->nome) - 1);
    novaAtracao->nome[sizeof(novaAtracao->nome) - 1] = '\0';
    novaAtracao->hInicio = h_inicio;
    novaAtracao->hFim = h_fim;
    novaAtracao->prox = NULL;

    return novaAtracao;
}

// esvazia e libera toda memória da lista
void liberaLista(TListaC *l)
{
    if (l == NULL)
        return;

    if (l->inicio != NULL)
    {
        TAtracao *aux = l->inicio;
        TAtracao *prox;

        do
        {
            prox = aux->prox;
            free(aux);
            aux = prox;
        } while (aux != l->inicio);
    }

    free(l);
}

// Insere uma nova atração no final da lista de atrações
// Caso a inserção seja feita com sucesso, retorna 1
// Caso contrário, retorna -1
int insereFimLista(TListaC *l, TAtracao *novaAtracao)
{
    if (l == NULL || novaAtracao == NULL)
        return -1;

    if (l->inicio == NULL)
    {
        l->inicio = novaAtracao;
        novaAtracao->prox = novaAtracao;
    }
    else
    {
        TAtracao *aux = l->inicio;

        while (aux->prox != l->inicio)
            aux = aux->prox;

        aux->prox = novaAtracao;
        novaAtracao->prox = l->inicio;
    }

    l->tam++;

    return 1;
}

// Listar a rota: Exibe todos os pontos na ordem da rota.
void listaRota(TListaC *l)
{
    if (l == NULL || l->inicio == NULL)
        return;

    TAtracao *aux = l->inicio;

    do
    {
        printf("%d %s %d %d\n", aux->id, aux->nome, aux->hInicio, aux->hFim);
        aux = aux->prox;
    } while (aux != l->inicio);
}

// Listar percurso completo a partir de uma atração (busca pelo nome)
void listaPercursoCompleto(TListaC *l, char *nomeAtracao)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("atracao nao encontrada na rota\n");
        return;
    }

    TAtracao *inicio = l->inicio;
    int encontrou = 0;

    do
    {
        if (strcmp(inicio->nome, nomeAtracao) == 0)
        {
            encontrou = 1;
            break;
        }
        inicio = inicio->prox;
    } while (inicio != l->inicio);

    if (!encontrou)
    {
        printf("atracao nao encontrada na rota\n");
        return;
    }

    TAtracao *percurso = inicio;

    do
    {
        printf("%d - %s\n", percurso->id, percurso->nome);
        percurso = percurso->prox;
    } while (percurso != inicio);
}

// Listar percurso entre duas atrações (pelos códigos), respeitando o sentido da rota.
// Mostra só os pontos que ficam ENTRE as duas (sem a inicial e sem a final).
void listaPercursoEntreAtracoes(TListaC *l, int codAtr1, int codAtr2)
{
    if (l == NULL || l->inicio == NULL)
        return;

    // procura a atração inicial
    TAtracao *inicio = l->inicio;

    do
    {
        if (inicio->id == codAtr1)
            break;
        inicio = inicio->prox;
    } while (inicio != l->inicio);

    if (inicio->id != codAtr1)
    {
        printf("codigo inicial nao encontrado na rota\n");
        return;
    }

    // anda a partir da próxima até achar a final ou voltar ao ponto de partida
    TAtracao *atual = inicio->prox;

    while (atual != inicio && atual->id != codAtr2)
    {
        printf("%d - %s\n", atual->id, atual->nome);
        atual = atual->prox;
    }

    // deu a volta completa sem achar a atração final
    if (atual == inicio && inicio->id != codAtr2)
        printf("o codigo final nao foi encontrado na rota\n");
}

// Lista as atrações da rota que estarão abertas no horário pesquisado
void listaAtracoesAbertas(TListaC *l, int horarioPesquisa)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("nenhuma atracao aberta para o horario pesquisado\n");
        return;
    }

    TAtracao *aux = l->inicio;
    int encontrou = 0;

    do
    {
        if (horarioPesquisa >= aux->hInicio && horarioPesquisa < aux->hFim)
        {
            printf("%d - %s\n", aux->id, aux->nome);
            encontrou = 1;
        }
        aux = aux->prox;
    } while (aux != l->inicio);

    if (!encontrou)
        printf("nenhuma atracao aberta para o horario pesquisado\n");
}

// Carrega a rota a partir do arquivo linha_turismo_curitiba
// Retorna -1 se acontecer qualquer tipo de erro
int carregaRota(TListaC *rota, char *nomeArquivo)
{
    if (rota == NULL)
        return -1;

    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL)
        return -1;

    int cod, hInicio, hFim;
    char nome[50];
    char linha[200];

    while (fgets(linha, sizeof(linha), arq) != NULL)
    {
        if (strlen(linha) < 5) // ignora linha em branco
            continue;

        // lê o código e o nome (até o segundo ';')
        sscanf(linha, "%d;%49[^;];", &cod, nome);

        // posiciona p logo depois do segundo ';', onde começam os horários
        char *p = strchr(linha, ';');
        if (p == NULL)
            continue;
        p = strchr(p + 1, ';');
        if (p == NULL)
            continue;
        p++;

        // lê as duas horas, ignorando minutos e separadores
        int horas[2] = {0, 0};
        int n = 0;

        while (*p != '\0' && n < 2)
        {
            if (*p >= '0' && *p <= '9')
            {
                while (*p >= '0' && *p <= '9')
                {
                    horas[n] = horas[n] * 10 + (*p - '0');
                    p++;
                }
                n++;

                if (*p == ':') // pula os minutos
                {
                    p++;
                    while (*p >= '0' && *p <= '9')
                        p++;
                }
            }
            else
                p++;
        }

        hInicio = horas[0];
        hFim = horas[1];

        TAtracao *nova = alocaNo(cod, nome, hInicio, hFim);
        if (nova == NULL)
        {
            fclose(arq);
            return -1;
        }

        insereFimLista(rota, nova);
    }

    fclose(arq);
    return 1;
}

// Consulta uma atração pelo código
void consultaAtracao(TListaC *l, int codAtr)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("atracao nao encontrada na rota\n");
        return;
    }

    TAtracao *aux = l->inicio;

    do
    {
        if (aux->id == codAtr)
        {
            printf("%d %s %d %d \n", aux->id, aux->nome, aux->hInicio, aux->hFim);
            return;
        }
        aux = aux->prox;
    } while (aux != l->inicio);

    printf("atracao nao encontrada na rota\n");
}

// Mostra os dados da próxima atração a partir do nome informado
void consultaProxAtracao(TListaC *l, char *nomeAtracao)
{
    if (l == NULL || l->inicio == NULL)
    {
        printf("atracao nao encontrada na rota\n");
        return;
    }

    TAtracao *atual = l->inicio;

    do
    {
        if (strcmp(atual->nome, nomeAtracao) == 0)
        {
            TAtracao *prox = atual->prox;
            printf("%d %s %d %d \n", prox->id, prox->nome, prox->hInicio, prox->hFim);
            return;
        }
        atual = atual->prox;
    } while (atual != l->inicio);

    printf("atracao nao encontrada na rota\n");
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TAD_PILHA.h"

typedef struct PILHA pilha;
typedef struct NO_PILHA pacienteAtendido;

struct PILHA
{
    pacienteAtendido *inicio;
    int tam;
};

struct NO_PILHA
{
    int id;
    char nome[30];
    char tipoAtendimento[50];
    pacienteAtendido *prox;
};

// aloca uma pilha vazia
pilha *alocaPilha()
{
    pilha *p = (pilha *)malloc(sizeof(pilha));
    if (p == NULL)
        return NULL;

    p->tam = 0;
    p->inicio = NULL;

    return p;
}

// aloca e inicializa um paciente já atendido
pacienteAtendido *alocaPacienteAtendido(int id, char *nome, char *tipoAtendimento)
{
    pacienteAtendido *p = (pacienteAtendido *)malloc(sizeof(pacienteAtendido));
    if (p == NULL)
        return NULL;

    p->id = id;
    strcpy(p->nome, nome);
    strcpy(p->tipoAtendimento, tipoAtendimento);
    p->prox = NULL;

    return p;
}

// retorna o id do paciente
int p_getId(pacienteAtendido *p)
{
    if (p != NULL)
        return p->id;

    return -1;
}

// retorna o nome do paciente
char *p_getNome(pacienteAtendido *p)
{
    if (p != NULL)
        return p->nome;

    return NULL;
}

// retorna o tipo de atendimento do paciente
char *p_getAtendimento(pacienteAtendido *p)
{
    if (p != NULL)
        return p->tipoAtendimento;

    return NULL;
}

// retorna o tamanho da pilha - total de atendimentos já realizados
int tamPilha(pilha *p)
{
    if (p != NULL)
        return p->tam;

    return -1;
}

// esvazia e libera a pilha
void liberaPilha(pilha *p)
{
    while (p->inicio != NULL)
        pop(p);

    free(p);
}

// insere um paciente na pilha
void push(pilha *p, pacienteAtendido *novoPaciente)
{
    if (novoPaciente == NULL)
        return;

    novoPaciente->prox = p->inicio;

    p->tam++;
    p->inicio = novoPaciente;
}

// remove um paciente da pilha
pacienteAtendido *pop(pilha *p)
{
    if (p->inicio == NULL)
        return NULL;

    pacienteAtendido *aux = p->inicio;

    p->inicio = p->inicio->prox;

    p->tam--;

    return aux;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_FILA.h"

typedef struct FILA fila;
typedef struct NO pacienteFila;

struct FILA
{
    pacienteFila *inicio;
    pacienteFila *fim;
    int tam;
};

struct NO
{
    int id;
    char nome[30];
    char tipoAtendimento[50];
    pacienteFila *prox;
};

// aloca uma fila vazia
fila *alocaFila()
{
    fila *f = (fila *)malloc(sizeof(fila));
    if (f == NULL)
        return NULL;

    f->tam = 0;
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

// aloca e inicializa um paciente
pacienteFila *alocaPaciente(int id, char *nome, char *tipoAtendimento)
{
    pacienteFila *p = (pacienteFila *)malloc(sizeof(pacienteFila));
    if (p == NULL)
        return NULL;

    p->id = id;
    strcpy(p->nome, nome);
    strcpy(p->tipoAtendimento, tipoAtendimento);

    p->prox = NULL;

    return p;
}

// retorna o id do paciente
int getId(pacienteFila *p)
{
    if (p != NULL)
        return p->id;

    return -1;
}

// retorna o nome do paciente
char *getNome(pacienteFila *p)
{
    if (p != NULL)
        return p->nome;

    return NULL;
}

// retorna o tipo de atendimento do paciente
char *getAtendimento(pacienteFila *p)
{
    if (p != NULL)
        return p->tipoAtendimento;

    return NULL;
}

// retorna o tamanho da fila de atendimento
int tamFila(fila *f)
{
    if (f != NULL)
        return f->tam;

    return 0;
}

// esvazia e libera a fila
void liberaFila(fila *f)
{
    while (f->inicio == NULL)
        realizaAtendimento(f);

    free(f);
}

// insere paciente na fila
void inserePaciente(fila *f, pacienteFila *novoPaciente)
{
    if (novoPaciente == NULL)
        return;

    if (f->inicio == NULL)
    {
        f->inicio = novoPaciente;
    }
    else
    {
        f->fim->prox = novoPaciente;
    }

    f->fim = novoPaciente;

    f->tam++;
}

// realiza atendimento, removendo o paciente da fila
pacienteFila *realizaAtendimento(fila *f)
{
    if (f->inicio == NULL)
        return NULL;

    pacienteFila *no = f->inicio;

    f->inicio = f->inicio->prox;

    f->tam--;

    return no;
}
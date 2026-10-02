//
// Created by Vanessa on 30/09/2026.
//

#ifndef Q2_CLINICA_TAD_FILA_H
#define Q2_CLINICA_TAD_FILA_H

typedef struct FILA fila;
typedef struct NO pacienteFila;

//aloca uma fila vazia
fila *alocaFila(); 

//aloca e inicializa um paciente
pacienteFila *alocaPaciente(int id, char *nome, char *tipoAtendimento);

//retorna o id do paciente
int getId(pacienteFila *p);

//retorna o nome do paciente
char *getNome(pacienteFila *p);

//retorna o tipo de atendimento do paciente
char *getAtendimento(pacienteFila *p);

//retorna o tamanho da fila de atendimento
int tamFila(fila *f);

//esvazia e libera a fila
void liberaFila(fila *f);

//insere paciente na fila
void inserePaciente(fila *f, pacienteFila *novoPaciente);

//realiza atendimento, removendo o paciente da fila
pacienteFila *realizaAtendimento(fila *f);



#endif //Q2_CLINICA_TAD_FILA_H

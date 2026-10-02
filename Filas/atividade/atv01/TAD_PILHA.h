//
// Created by Vanessa on 30/09/2026.
//

#ifndef Q2_CLINICA_TAD_PILHA_H
#define Q2_CLINICA_TAD_PILHA_H

typedef struct PILHA pilha;
typedef struct NO_PILHA pacienteAtendido;

//aloca uma pilha vazia
pilha *alocaPilha(); 

//aloca e inicializa um paciente já atendido
pacienteAtendido *alocaPacienteAtendido(int id, char *nome, char *tipoAtendimento);

//retorna o id do paciente
int p_getId(pacienteAtendido *p);

//retorna o nome do paciente
char *p_getNome(pacienteAtendido *p);

//retorna o tipo de atendimento do paciente
char *p_getAtendimento(pacienteAtendido *p);

//retorna o tamanho da pilha - total de atendimentos já realizados
int tamPilha(pilha *p);

//esvazia e libera a pilha
void liberaPilha(pilha *p);

//insere um paciente na pilha
void push(pilha *p, pacienteAtendido *novoPaciente);

//remove um paciente da pilha
pacienteAtendido *pop(pilha *p);

#endif //Q2_CLINICA_TAD_PILHA_H

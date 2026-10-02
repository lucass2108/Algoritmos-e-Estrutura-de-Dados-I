#include <stdio.h>
#include "TAD_FILA.h"
#include "TAD_PILHA.h"

int main() {
    //DECLARAÇÃO DE VARIAVEIS
    int id;
    char nomePaciente[30];
    char tipoAtendimento[30]; //"consulta", "exame" ou "vacinação"
    int opcao;
    pacienteFila *pacienteFila; 
    pacienteAtendido *pacienteAtendido;

    fila *filaReq = alocaFila();
    pilha *atendimentosRealizados = alocaPilha();

    if (!filaReq || !atendimentosRealizados)
        return -1;

    //PROCESSAMENTO
    //LEITURA DA OPÇÃO
    //1 para adicionar paciente na fila
    //2 para remover paciente da fila e inserir na pilha de atendimentos realizados
    //3 para desfazer último atendimento
    //4 para relatórios
    //5 para sair
    scanf("%d", &opcao);
    // Processamento da opção escolhida
    while (opcao != 5)
    {
        switch (opcao) {
            case 1:
                //LEITURA DOS DADOS E INSERÇÃO DO PACIENTE NA FILA
                scanf("%d %s %s", &id, nomePaciente, tipoAtendimento);
                pacienteFila = alocaPaciente(id, nomePaciente,tipoAtendimento);
                inserePaciente(filaReq, pacienteFila);
                break;
            case 2: //remover paciente da fila e inserir na pilha de atendimentos realizados
                pacienteFila = realizaAtendimento(filaReq);
                if (pacienteFila != NULL)
                {
                    pacienteAtendido = alocaPacienteAtendido(getId(pacienteFila), getNome(pacienteFila), getAtendimento(pacienteFila));
                    if (pacienteAtendido != NULL)
                        push(atendimentosRealizados, pacienteAtendido);
                }
                break;
            case 3: //desfazer último atendimento - remove da pilha e insere na fila
                pacienteAtendido = pop(atendimentosRealizados);
                if (pacienteAtendido != NULL)
                {
                    pacienteFila = alocaPaciente(p_getId(pacienteAtendido), p_getNome(pacienteAtendido), p_getAtendimento(pacienteAtendido));
                    if (pacienteFila != NULL)
                        inserePaciente(filaReq, pacienteFila);
                }
                break;
            case 4: //relatório
                printf("Total de Pacientes Aguardando na Fila : %d.\n", tamFila(filaReq));
                printf("Total de Pacientes Atendidos : %d. \n", tamPilha(atendimentosRealizados));
                break;
            case 5:
                printf("Saindo do programa...\n");
                liberaPilha(atendimentosRealizados);
                liberaFila(filaReq);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
        scanf("%d", &opcao);

    }

    return 0;
}

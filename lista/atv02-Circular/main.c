#include <stdio.h>
#include "TAD_LISTA_CIRCULAR.h"

int main() {
    char nomeAtracao[60];
    int atr1, atr2, horario, opc;
    TListaC *rota = alocaLista();
    if (!rota)
        return -1;

    char nomeArquivo[30] = "linha_turismo_curitiba.txt";

    int res  = carregaRota(rota, nomeArquivo);
    if (res == -1)
        return -1;

    scanf("%d", &opc);
    while (opc >=1 && opc <=6)
    {
            switch (opc) {
                case 1:
                    listaRota(rota);
                    break; 

                case 2:
                    scanf(" %59[^\n]", nomeAtracao);
                    listaPercursoCompleto(rota, nomeAtracao);
                    break;

                case 3:
                    scanf("%d", &atr1);
                    scanf("%d", &atr2);
                    listaPercursoEntreAtracoes(rota, atr1, atr2);
                    break;
                case 4:
                    scanf("%d", &horario);
                    listaAtracoesAbertas(rota, horario);
                    break;
                case 5:
                    scanf("%d", &atr1);
                    consultaAtracao(rota, atr1);
                    break;
                case 6:
                    scanf(" %59[^\n]", nomeAtracao);
                    consultaProxAtracao(rota, nomeAtracao);
                    break;
                default:
                    // caso nenhum valor corresponda
                    break;
            }
        scanf("%d", &opc);
    }

    liberaLista(rota);

    return 0;
}

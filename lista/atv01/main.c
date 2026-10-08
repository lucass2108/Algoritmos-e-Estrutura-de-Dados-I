#include <stdio.h>
#include "TAD_LISTA.h"

int main() {
    //Declaração de Variáveis
    char nomeArquivo[30];
    int res;
    int taxa;

    TLista *lista = alocaLista();
    if (!lista)
        return -1;

    //leitura do nome do arquivo e carga dos dados
    scanf("%s", nomeArquivo); 

    res = carregaProdutos(lista, nomeArquivo);
    if(res == -1)
    {
        liberaLista(lista);
        return -1;
    }

    //imprime os produtos antes da alteração
    printf("Produtos Cadastrados\n");
    imprimeProdutos(lista);

    //leitura da taxa de desconto e aplicação do desconto
    scanf("%d", &taxa);

    res = atualizaPreco(lista, taxa);
    if(res == 1)
    {
        //imprime relatórios: lista atualizada e total de produtos
        printf("Produtos Atualizados\n");
        imprimeProdutos(lista);
    }
    imprimeTotal(lista);
     liberaLista(lista);

    return 0;
}

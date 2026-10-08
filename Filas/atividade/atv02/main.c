#include <stdio.h>
#include "tad_pedidos.h"
#include <string.h>

int main() {
    //DECLARAÇÃO DE VARIÁVEIS
    Fila *site, *app, *mkt, *deposito;
    Pedido *novoPedido, *pedidoProcessado;
    int id;
    char cliente[30];
    char canal[30]; //"site" "app" "mkt"
    float valorPedido; 
    time_t horario;
    int continua = 1;

    //INICIALIZAÇÃO DAS FILAS
    site = aloca_fila();
    app = aloca_fila();
    mkt = aloca_fila();
    if (!site || !app || !mkt)
        return -1;

    //INÍCIO DA LEITURA DOS PEDIDOS
    while(continua == 1)
    {
        //leitura dos dados do pedido - 1 por linha
        scanf("%d", &id); //id
        scanf("%s", cliente); //nome do cliente
        scanf("%s", canal); //canal
        scanf("%f", &valorPedido); //valor do pedido

        //alocar pedido
        novoPedido = alocaPedido(id, cliente, canal, valorPedido);

        //inserir na fila correta
        if (strcmp(canal, "site") == 0)
            fila_inserir(site, novoPedido);
        else
        {
            if(strcmp(canal, "app") == 0)
                fila_inserir(app, novoPedido);
            else
                fila_inserir(mkt, novoPedido);
        }

        //verificar se deseja continuar lendo os pedidos
        scanf("%d", &continua);
    }

    //EXIBIR TOTAL DE PEDIDOS POR CANAL E GERAR A FILA DE PROCESSAMENTO DO ARMAZEM
    relatorios_canal(site, app, mkt);
    printf("SITE\n");
    listaFila(site);
    printf("APP\n");
    listaFila(app);
    printf("MARKETPLACE\n");
    listaFila(mkt);

    deposito = fila_concatenar(site, app, mkt);
    if (!deposito)
        return -1;

    printf("FILA DE PROCESSAMENTO\n");
    listaFila(deposito);


    //PROCESSAR PEDIDOS ENQUANTO CONTINUA == 1
    continua = 1;
    printf("PROCESSANDO PEDIDOS\n");
    while(continua == 1 && fila_vazia(deposito) == 0)
    {
        pedidoProcessado = fila_remover(deposito);
        imprimePedido(pedidoProcessado);
        liberaPedido(pedidoProcessado);
        //verificar se deseja continuar lendo os pedidos
        scanf("%d", &continua);
    }

    //EXIBIR O TOTAL DE PEDIDOS NA FILA DE PROCESSAMENTO
    relatorios_deposito(deposito);

    //ENCERRAR
    fila_liberar(site);
    fila_liberar(app);
    fila_liberar(mkt);
    fila_liberar(deposito);

    return 0;
}

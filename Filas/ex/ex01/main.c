#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "tadFila.h"

int main()
{
    canal *f_site = criarFila();
    canal *f_app = criarFila();
    canal *f_mkp = criarFila();

    char sn = 'S';

    while (sn == 'S' || sn == 's')
    {
        printf("\nVamos as compras\n");

        printf("Digite o canal de compras - (S - Site / A - App / M - Marketplace):\n");

        char canalChar;
        scanf(" %c", &canalChar);

        printf("Digite o ID do produto:\n");

        int id;
        scanf("%d", &id);

        getchar();

        printf("Digite seu nome:\n");

        char nome[30];
        fgets(nome, 30, stdin);
        nome[strcspn(nome, "\n")] = '\0';

        printf("Digite o valor total:\n");

        float valor;
        scanf("%f", &valor);

        pedido *novo = criaPedido(id, nome, canalChar, valor);

        switch (canalChar)
        {
        case 'S':
        case 's':
            enqueue(f_site, novo);
            break;

        case 'A':
        case 'a':
            enqueue(f_app, novo);
            break;

        case 'M':
        case 'm':
            enqueue(f_mkp, novo);
            break;

        default:
            printf("Canal invalido!\n");
            free(novo);
            continue;
        }

        printf("\nOK\n");
        printf("Deseja adicionar mais algo? (S/N): ");
        scanf(" %c", &sn);
    }

    printf("\n===== RELATORIO DE PEDIDOS =====\n");

    printf("Site: %d pedidos\n", totalPedidosCanal(f_site));
    printf("App: %d pedidos\n", totalPedidosCanal(f_app));
    printf("Marketplace: %d pedidos\n", totalPedidosCanal(f_mkp));

    canal *final = concatenaFila(f_site, f_app, f_mkp);

    printf("\nTotal de envios: %d\n", totalPedidosEnvio(final));

    printf("\n===== FILA DE PROCESSAMENTO =====\n");
    listaFila(final);

    return 0;
}
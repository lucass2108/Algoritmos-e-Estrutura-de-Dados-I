//
// Created by Vanessa on 30/09/2026.
//

#ifndef Q1_PRODUTOS_TAD_LISTA_H
#define Q1_PRODUTOS_TAD_LISTA_H

// LISTA SIMPLESMENTE ENCADEADA D PRODUTOS

typedef struct lista TLista;
typedef struct no TProduto;

// aloca uma lista vazia
TLista *alocaLista();

// aloca e inicializa um produto
TProduto *alocaProduto(int codigo, float preco, int qtdEstoque);

// insere um produto na lista não ordenada -> inserir no começo da lista
// retorna 1 se inseriu corretamente e -1 se houver erro de qualquer natureza
int cadastraProduto(TLista *l, TProduto *novoProduto);

// atualiza o preço de todos os produtos com base na taxa
// taxa é um inteiro que representa a % de desconto e deve ser maior que 0 e menor ou igual 100
int atualizaPreco(TLista *l, int taxa);

// imprime os produtos na tela
// printf("%d\t%0.2f\t%d\n", ...
void imprimeProdutos(TLista *l);

// imprime o total de produtos que tenham quantidade maior que 500 unidades no estoque
// printf("Total de Produtos com quantidade maior que 500 : %d\n", ...
void imprimeTotal(TLista *l);

// esvazia e libera a lista
void liberaLista(TLista *l);

// Lê os dados do arquivo e insere na lista
int carregaProdutos(TLista *l, char *nomeArquivo);

#endif // Q1_PRODUTOS_TAD_LISTA_H

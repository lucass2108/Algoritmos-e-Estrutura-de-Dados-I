//
// Created by Vanessa on 01/10/2026.
//

#ifndef Q2_LISTACIRCULAR_TAD_LISTA_CIRCULAR_H
#define Q2_LISTACIRCULAR_TAD_LISTA_CIRCULAR_H

typedef struct listaCircular TListaC;

typedef struct no TAtracao;

//Aloca uma lista vazia
TListaC *alocaLista();

//Aloca um novo nó com os dados informados por parâmetro
TAtracao *alocaNo(int cod, char *nome, int h_inicio, int h_fim);
 
//esvazia e libera toda memória da lista
void liberaLista(TListaC *l);

//Insere uma nova atração no final da lista de atrações
//Caso a inserção seja feita com sucesso, retorna 1
//Caso contrário, retorna -1
int insereFimLista(TListaC *l, TAtracao *novaAtracao);

//Listar a rota: Exibe todos os pontos na ordem da rota.
//printf("%d   %s   %d   %d\n", ...
void listaRota(TListaC *l);

//Listar percurso completo: O usuário informa o nome de uma atração e o programa
// exibe a sequência completa da rota a partir dessa atração, percorrendo todos os pontos
// até retornar ao ponto de partida.
//Caso a atração não seja encontrada na rota, imprimir : Atracao nao encontrada na rota
//printf("%d - %s\n" ...
void listaPercursoCompleto(TListaC *l, char *nomeAtracao);

//Listar percurso entre duas atrações: O usuário informa o código da atração inicial
// e o código da atração final. O programa deve exibir a sequência de pontos percorrida
// entre as duas atrações, respeitando o sentido da rota.
//printf("%d   %s --", ...
//Caso a primeira atração não seja encontrada na rota, imprimir codigo inicial nao encontrado na rota
//Neste caso o programa encerra
//Caso a segunda atração não seja encontrada na rota, imprimir codigo final nao encontrado na rota.
//Neste caso, o programa deve imprimir o percurso completo até voltar no código inicial.
void listaPercursoEntreAtracoes(TListaC *l, int codAtr1, int codAtr2);

//Lista as atrações da Rota que estarão abertas no horário pesquisado
//Se não hover nenhuma, o programa imprime "nenhuma atracao aberta para o horário pesquisado"
void listaAtracoesAbertas(TListaC *l, int horarioPesquisa);

//Carrega a rota a partir do arquivo linha_turismo_curitiba
//Retorna -1 se acontecer qualquer tipo de erro
int carregaRota(TListaC *rota, char *nomeArquivo);

// O usuário informa o código de uma atração e o programa apresenta seus dados
// Caso a atração não seja encontrada na rota, imprimir : atracao nao encontrada na rota
//printf("%d %s %d %d \n" ...
void consultaAtracao(TListaC *l, int codAtr);

//O usuário informa o nome de uma atração e o programa apresenta os dados da próxima atração no percurso.
// Caso a atração não seja encontrada na rota, imprimir : Atracao nao encontrada na rota
//printf("%d %s %d %d \n" ...
void consultaProxAtracao(TListaC *l, char *nomeAtracao);



#endif //Q2_LISTACIRCULAR_TAD_LISTA_CIRCULAR_H

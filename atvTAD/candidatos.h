
#ifndef CANDIDATOS_H
#define CANDIDATOS_H

typedef struct Candidatos candidato;

// Função para alocar dinamicamente um conjunto  de n candidatos e preencher os dados de cada um
// Recebe como entrada N (quantidade de candidatos)
// Retorna um ponteiro para o conjunto alocado
candidato *criaListaCandidato(int n);

// Função para buscar um candidato pela sua identidade
// Recebe como entrada a lista de candidatos, N (quantidade de candidatos) e a identidade a ser procurada
// Retorna um ponteiro para o candidato com a identidade desejada ou NULL caso contrário
candidato *buscaCId (candidato *lista,int n, int identidade);

// Função para retornar a quantidade de candidatos com uma determinada escolaridade
// Recebe como entrada a lista de candidatos, N (quantidade de candidatos) e a escolaridade desejada 
int buscaCE(candidato *lista, int n, char *escolaridade);

// Função para imprimir na tela nome de todos os candidatos com determinada profissão
// Recebe como entrada a lista de candidatos, N (quantidade de candidatos) e a profissão desejada
// Printf com o nome do candidato: printf("%s\n",...); 
void imprimeNomeProf(candidato *lista, int n, char *profissao);


void operacoes(candidato *lista, int n);


// Função para liberar a memória alocada 
void liberaCandidato(candidato *lista);


#endif
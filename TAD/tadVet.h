#ifndef TADVET_H
#define TADVET_H

//Aloca e retorna um vetor de inteiros de tamamho tam
int *criaVet(int tam);

//Libera a memória do vetor
void libera(int *vet);

//Retorna elemento X do vetor
int acessarElemento(int *vet, int pos);

//Atribui valor a pos x do vetor
void atribuiElemento(int *vet, int pos, int valor);

//Retorna quantidade de elementos

//Preenche o vetor com valores do arquivo
//Retorna 1 se nn der erros e 0 se der
int preencheVet(int *vet, int tam, char nomeArquivo[]);

//Imprime o vetor
void imprimeVet(int *vet, int tam);


#endif

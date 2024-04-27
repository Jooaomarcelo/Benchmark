typedef struct vetor vetor;

vetor *criaVetor();

int *getVet(vetor *v);

long int *getCompara(vetor *v);

long int *getTrocas(vetor *v);

long long int getTam(vetor *v);

int* geraAleatorios(long long int tam, int semente);

int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente);

int* geraOrdenados(long long int tam, int ordem);

void escolhaOrdenacao(vetor *v);

#include <stdio.h>
#include <stdlib.h>

typedef struct par {
    long long int seed;
    int tipoOrdenacao;
    long long int tamAmostra;
}par;

typedef struct vet {
    int *v;
    long long int tamanho;
    long long int seed;
}vet;

FILE* abreArquivo();

par* obtemParametros(par* parametros);

void geraAmostraAleatoria(par* parametro, FILE* arquivo);

void geraAmostraCrescente(par* parametro, FILE* arquivo);

void geraAmostraSemiOrdenada(par* parametro, FILE* arquivo);

void geraAmostraDescrescente(par* parametro, FILE* arquivo);

vet* criaVetor(FILE* arquivo, vet *vetor);

void imprimeVetor(int* vetor, long long int tamanho);

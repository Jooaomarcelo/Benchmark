#include <stdio.h>
#include <stdlib.h>
#include "ES.h"

struct parametros {
    long long int seed;
    int tipoOrdenacao;
    long long int tamAmostra;
};

FILE* abreArquivo(){
    FILE* arquivo;
    char nomeArquivo[31];
    
    printf("Digite o nome do arquivo: \n");
    scanf(" %s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "w+");
    
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return NULL;
    }

    return arquivo;
}

void obtemParametros(par* parametros){
    parametros->tipoOrdenacao = 0;

    while (parametros->tipoOrdenacao < 1 || parametros->tipoOrdenacao > 4)
    {
        printf("Qual tipo de conjunto de números você deseja que seja criado (1 - Conjunto aleatório, 2 - Conjunto Crescente ,3 - Conjunto Semi-Ordenado, 4 - Conjunto Decrescente)?\n");
        scanf(" %d", &parametros->tipoOrdenacao);
    }

    printf("Qual o tamanho da amostra a ser criada?\n");
    scanf(" %lld", &parametros->tamAmostra);

    if (parametros->tipoOrdenacao == 1 || parametros->tipoOrdenacao == 3)
    {
        printf("Qual a semente da geração de numeros pseudo-aleatorios sera utilizada?\n");
        scanf(" %lld", &parametros->seed);
        srand(parametros->seed);
    }
    return;
}

void geraAmostraAleatoria(par *parametro, FILE* arquivo){
    rewind(arquivo);
    fprintf(arquivo, "%lld\n", parametro->tamAmostra);
    fprintf(arquivo, "%lld\n", parametro->seed);
    srand(parametro->seed);
    for(int i = 0 ; i < parametro->tamAmostra ; i++){
                fprintf(arquivo, "%d\n", rand());
            }
}

void geraAmostraCrescente(par* parametro, FILE* arquivo){
    rewind(arquivo);
    fprintf(arquivo, "%lld\n", parametro->tamAmostra);
    fprintf(arquivo, "%lld\n", parametro->seed);
    srand(parametro->seed);
    for(int i=0 ; i<parametro->tamAmostra ; i++){
                fprintf(arquivo, "%d\n", i);
            }
}

void geraAmostraSemiOrdenada(par* parametro, FILE* arquivo){
    rewind(arquivo);
    fprintf(arquivo, "%lld\n", parametro->tamAmostra);
    fprintf(arquivo, "%lld\n", parametro->seed);
    srand(parametro->seed);
    for(int i=0 ; i < parametro->tamAmostra ; i++){
                if (i < parametro->tamAmostra/10){
                    fprintf(arquivo, "%d\n", rand());
                }else{
                    fprintf(arquivo, "%d\n", i);
                }
            }
}

void geraAmostraDescrescente(par* parametro, FILE* arquivo){
    rewind(arquivo);
    fprintf(arquivo, "%lld\n", parametro->tamAmostra);
    fprintf(arquivo, "%lld\n", parametro->seed);
    srand(parametro->seed);
    for(int i = parametro->tamAmostra ; i > 0 ; i--){
                fprintf(arquivo, "%d\n", i);
            }
}

int* criaVetor(FILE* arquivo){
    int* vetor;
    long long int tamVetor;
    long long int seed;
    rewind(arquivo);
    fscanf(arquivo, " %lld", &tamVetor);
    fscanf(arquivo, " %lld", &seed);
    vetor = (int*)malloc(sizeof(int)*tamVetor);
    if (!vetor)
    {
        printf("Ocorreu um erro durante a alocação do vetor!\n");
        return NULL;
    }
    
    for(int i=0 ; i < tamVetor ; i++){
        fscanf(arquivo, " %d", &vetor[i]);
    }
    return vetor;
}

void imprimeVetor(int* vetor, FILE* arquivo){
    long long int tamVetor;
    rewind(arquivo);
    fscanf(arquivo, " %lld", &tamVetor);
    printf("Vetor = [");
    for (int i = 0 ; i < tamVetor-1 ; i++)
    {
        printf("%d, ", vetor[i]);
    }
    printf("%d]\n", vetor[tamVetor-1]);
}

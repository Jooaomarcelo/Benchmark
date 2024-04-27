#include "ES.h"
#include <stdlib.h>
#include <stdio.h>

struct vetor{
    long long int *vet;
    long int compara, trocas;
    long long int tam;
};

//Setando variáveis importantes para o sistema
vetor *criaVetor(){
    vetor *v = (vetor*)malloc(sizeof(vetor));

    printf("\nQual o tamanho do vetor?");
    scanf("%lld", &v->tam);
    v->tam = 100000;
    v->compara = v->trocas = 0;

    return v;
}

long long int *getVet(vetor *v){
    return v->vet;
}

long int *getCompara(vetor *v){
    return &v->compara;
}

void setCompara(vetor *v){
    v->compara = 0;
}

long int *getTrocas(vetor *v){
    return &v->trocas;
}

void setTrocas(vetor *v){
    v->trocas = 0;
}

long long int getTam(vetor *v){
    return v->tam;
}

long long int* geraAleatorios(long long int tam, int semente){
    long long int *vet = (long long int*)malloc(sizeof(long long int) * tam);
    srand(semente);
    for(long long int i = 0; i < tam; i++){
        vet[i] = rand();
    }
    return vet;
}

long long int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente){
    long long int *vet = (long long int*)malloc(sizeof(long long int) * tam), tamanho;
    long double valorPorcentagem = tam * ((long double)porcentagem/100.0);

    tamanho = (int)tam - valorPorcentagem;
    srand(semente);
    for(long long int i = 0; i < tam; i++){
        if(i < tamanho){
            vet[i] = i;
        }else{
            vet[i] = rand();
        }
    }
    return vet;
}

long long int* geraOrdenados(long long int tam, int ordem){
    long long int *vet = (long long int*)malloc(sizeof(long long int) * tam);
    if(ordem == 0){
        for(long long int i = 0; i < tam; i++){
            vet[i] = i;
        }
    }else if(ordem == 1){
        for(long long int i = tam, j = 0; i > 0; i--, j++){
            vet[j] = i;
        }
    }
    return vet;
}

void escolhaOrdenacao(vetor *v, int semente, int tipoOrdenacao, int porcentagem){
    if(tipoOrdenacao == 1){
        v->vet = geraAleatorios(v->tam, semente);
    }else if(tipoOrdenacao == 2){
        v->vet = geraQuaseOrdenados(v->tam, porcentagem, semente);
    }else if(tipoOrdenacao == 3){
        v->vet = geraOrdenados(v->tam, 0);
    }else{
        v->vet = geraOrdenados(v->tam, 1);
    }
}

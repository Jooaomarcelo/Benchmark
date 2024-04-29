#define pos 4

#include "ES.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

struct vetor{
    long long int *vet;
    long long int compara, trocas;
    long long int tam;
};

struct metricas{
    long double tempo[pos];
    long double compara[pos];
    long double trocas[pos];
};

metricas *criaMetricas(){
    metricas *tabela = (metricas*)malloc(sizeof(metricas));
    return tabela;
}

void setTabela(metricas *tabela, int tipo, long double tempo, long double comparacoes, long double troca){
    tabela->tempo[tipo] = tempo;
    tabela->compara[tipo] = comparacoes;
    tabela->trocas[tipo] = troca;
}

vetor *criaVetor(){
    vetor *v = (vetor*)malloc(sizeof(vetor));
    v->compara = v->trocas = 0;
    return v;
}

long long int getTam(vetor *v){
    return v->tam;
}

void setTam(vetor *v, long long int tam){
    v->tam = tam;
}

long long int *getVet(vetor *v){
    return v->vet;
}

long long int *getCompara(vetor *v){
    return &v->compara;
}

void setCompara(vetor *v){
    v->compara = 0;
}

long long int *getTrocas(vetor *v){
    return &v->trocas;
}

void setTrocas(vetor *v){
    v->trocas = 0;
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
    long long int *vet = (long long int*)malloc(sizeof(long long int) * tam), valorPorcentagem = (long long int)((long double)tam * ((float)porcentagem/100.0));
    //srand(time(NULL));
    srand(semente);
    for(long long int i = 0; i < tam; i++){
        if(i < valorPorcentagem){
            vet[i] = rand() + tam;
        }else{
            vet[i] = i;
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
    if(tipoOrdenacao == 0){
        v->vet = geraAleatorios(v->tam, semente);
    }else if(tipoOrdenacao == 1){
        v->vet = geraQuaseOrdenados(v->tam, porcentagem, semente);
    }else if(tipoOrdenacao == 2){
        v->vet = geraOrdenados(v->tam, 0);
    }else{
        v->vet = geraOrdenados(v->tam, 1);
    }
}

void printVetor(metricas *tabela){
    for(int t = 0; t < 3; t++) {
        printf("\n\n");
        for (int j = 0; j < pos; j++) {
            if(t == 0){
                printf("%Lf ", tabela->tempo[j]);
            }else if(t == 1){
                printf("%Lf ", tabela->compara[j]);
            }else{
                printf("%Lf ", tabela->trocas[j]);
            }
        }
        printf("\n");
    }
}

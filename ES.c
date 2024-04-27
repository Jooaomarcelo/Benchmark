#include "ES.h"
#include <stdlib.h>
#include <stdio.h>

struct vetor{
    int *vet;
    long int compara, trocas;
    long long int tam;
};

//Setando variáveis importantes para o sistema
vetor *criaVetor(){
    vetor *v = (vetor*)malloc(sizeof(vetor));

    printf("\nQual o tamanho do vetor?");
    scanf("%lld", &v->tam);
    v->compara = v->trocas = 0;

    return v;
}

int *getVet(vetor *v){
    return v->vet;
}

long int *getCompara(vetor *v){
    return &v->compara;
}

long int *getTrocas(vetor *v){
    return &v->trocas;
}

long long int getTam(vetor *v){
    return v->tam;
}

int* geraAleatorios(long long int tam, int semente){
    int *vet = (int*)malloc(sizeof(int) * tam);
    srand(semente);
    for(int i = 0; i < tam; i++){
        vet[i] = rand();
    }
    return vet;
}

int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente){
    int *vet = (int*)malloc(sizeof(int) * tam), valorPorcentagem = tam * (porcentagem/100), tamanho;
    tamanho = tam - valorPorcentagem;
    srand(semente);
    for(int i = 0; i < tam; i++){
        if(i < tamanho){
            vet[i] = i;
        }else{
            vet[i] = rand();
        }
    }
    return vet;
}

int* geraOrdenados(long long int tam, int ordem){
    int *vet = (int*)malloc(sizeof(int) * tam);
    if(ordem == 0){
        for(int i = 0; i < tam; i++){
            vet[i] = i;
        }
    }else if(ordem == 1){
        for(int i = tam, j = 0; i > 0; i--, j++){
            vet[j] = i;
        }
    }
    return vet;
}

void escolhaOrdenacao(vetor *v){
    int semente, ordem, tipoOrdenacao = 0, porcentagem;

    while (tipoOrdenacao < 1 || tipoOrdenacao > 4)
    {
        printf("Qual tipo de conjunto de números você deseja que seja criado (1 - Conjunto aleatório, 2 - Conjunto Semi-Ordenado ,3 - Conjunto Crescente, 4 - Conjunto Decrescente)?\n");
        scanf("%d", &tipoOrdenacao);
    }

    printf("\nDigite uma semente: ");
    scanf("%d", &semente);

    if(tipoOrdenacao == 1){
        v->vet = geraAleatorios(v->tam, semente);
    }else if(tipoOrdenacao == 2){
        printf("\nDigite a porcentagem que será desordenada: ");
        scanf("%d", &porcentagem);
        v->vet = geraQuaseOrdenados(v->tam, porcentagem, semente);
    }else if(tipoOrdenacao == 3){
        v->vet = geraOrdenados(v->tam, 0);
    }else{
        v->vet = geraOrdenados(v->tam, 1);
    }
}

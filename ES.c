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

#include <stdio.h>
#include <stdlib.h>
#include "ES.h"

FILE* abreArquivo(){
    FILE* arquivo;
    char nomeArquivo[31];
    
    printf("Digite o nome do arquivo: \n");
    scanf(" %s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r+");
    
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return NULL;
    }

    return arquivo;
}

par* obtemParametros(par* parametros){
    parametros = (par*)malloc(sizeof(par));
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
    return parametros;
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

vet* criaVetor(FILE* arquivo, vet *vetor){
    vetor = (vet*)malloc(sizeof(vet));
    rewind(arquivo);
    fscanf(arquivo, " %lld", &vetor->tamanho);
    fscanf(arquivo, " %lld", &vetor->seed);
    vetor->v = (int*)malloc(sizeof(int)*vetor->tamanho);
    if (!vetor)
    {
        printf("Ocorreu um erro durante a alocação do vetor!\n");
        return NULL;
    }
    
    for(int i=0 ; i < vetor->tamanho ; i++){
        fscanf(arquivo, " %d", &vetor->v[i]);
    }
    return vetor;
}

void imprimeVetor(int* vetor, long long int tamanho){
    printf("Vetor = [");
    for (int i = 0 ; i < tamanho ; i++)
    {
        printf("%d, ", vetor[i]);
    }
    printf("%d]\n", vetor[tamanho-1]);
}

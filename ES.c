#include <stdio.h>
#include <stdlib.h>

typedef struct parametros {
    long long int seed;
    int tipoOrdenacao;
    long long int tamAmostra;
}par;

FILE* abreArquivo(){
    FILE* arquivo;
    char nomeArquivo[31];
    
    printf("Digite o nome do arquivo: \n");
    scanf(" %s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "w");
    
    if (!arquivo)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    return arquivo;
}

par* obtemParamentros(){
    par* parametro;
    parametro->tipoOrdenacao = 0;

    while (parametro->tipoOrdenacao < 1 || parametro->tipoOrdenacao > 4)
    {
        printf("Qual tipo de conjunto de números você deseja que seja criado (1 - Conjunto aleatório, 2 - Conjunto Crescente ,3 - Conjunto Semi-Ordenado, 4 - Conjunto Decrescente)?\n");
        scanf(" %d", &parametro->tipoOrdenacao);
    }

    printf("Qual o tamanho da amostra a ser criada?\n");
    scanf(" %lld", parametro->tamAmostra);

    if (parametro->tipoOrdenacao == 1 || parametro->tipoOrdenacao == 3)
    {
        printf("Qual a semente da geração de numeros pseudo-aleatorios sera utilizada?\n")/
        scanf(" %lld", &parametro->seed);
        srand(parametro->seed);
    }
    return parametro;
}

void geraAmostraAleatoria(par parametro, FILE* arquivo){
    srand(parametro.seed);
    for(int i = 0 ; i < parametro.tamAmostra ; i++){
                fprintf(arquivo, " %d\n", rand());
            }
}

void geraAmostraCrescente(par parametro, FILE* arquivo){
    srand(parametro.seed);
    for(int i=0 ; i<parametro.tamAmostra ; i++){
                fprintf(arquivo, " %d\n", i);
            }
}

void geraAmostraSemiOrdenada(par parametro, FILE* arquivo){
    srand(parametro.seed);
    for(int i=0 ; i < parametro.tamAmostra ; i++){
                if (i < parametro.tamAmostra/10){
                    fprintf(arquivo, " %d\n", rand());
                }else{
                    fprintf(arquivo, " %d\n", i);
                }
            }
}

void geraAMostraDescrescente(par parametro, FILE* arquivo){
    srand(parametro.seed);
    for(int i = parametro.tamAmostra ; i > 0 ; i--){
                fprintf(arquivo, " %d\n", i);
            }
}

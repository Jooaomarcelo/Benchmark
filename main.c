
/* INCLUDES */

#include "sort.h"
#include "ES.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/* FUNÇÕES */

//Função responsável por chamar o respectivo método de ordenação.
double chamaOrdenacao(vetor *v, int metodos){
    clock_t inicio, fim; //Variáveis para calcularem o tempo
    switch (metodos) {
        case 0:
            inicio = clock();
            selectionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
            fim = clock();
            break;
        case 1:
            inicio = clock();
            insertionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
            fim = clock();
            break;
        case 2:
            inicio = clock();
            mergeSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
            fim = clock();
            break;
        case 3:
            inicio = clock();
            quickSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
            fim = clock();
            break;
        default:
            inicio = clock();
            quickSortDual(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
            fim = clock();
    }
    //Retornando o tempo de execução de respectivo método em mili segundos
    return (double)(fim - inicio)/(CLOCKS_PER_SEC/1000);
}

//Função principal
int main(void) {
    long long int entradas;
    int semente, linha;
    long double t, media, comparacoes, troca;

    vetor *v = criaVetor();
    metricas *tabela = criaMetricas();

    //Entradas 1000 - 10000 - 100000 - 500000 - 1000000
    entradas = 1000000;
    //Linha da entrada na matriz da tabela
    linha = 3;

    //Tipos: Aleatório - Semi-Ordenado - Crescente - Decrescente

    //Percorrendo os 5 tipos de métodos de ordenação
    for(int metodos = 0; metodos < 1; metodos++){

        printf("\n%d\n", metodos);

        //Percorrendo os tipos
        for(int tipos = 0; tipos < 4; tipos++){
            printf("Tipo: %d ", tipos);

            //Setando o tamanho do vetor para o tamanho da entrada
            setTam(v, entradas);

            //Setando variáveis auxiliares para a média dos valores
            media = troca = comparacoes = 0;

            //Verificando se os dados estarão aleatórios/desordenados
            if(tipos == 0 || tipos == 1){

                //Calculando a média de 5 execuções
                for(int i = 0; i < 5; i++){

                    //Setando a semente
                    semente = i;

                    //Cria vetor
                    escolhaOrdenacao(v, semente, tipos, 10);

                    //Chama método de ordenação
                    t = chamaOrdenacao(v, metodos);

                    //Preparando para calcular a média
                    media += t;
                    comparacoes += *getCompara(v);
                    troca += *getTrocas(v);

                    //Setando variáveis de comparações e trocas para 0
                    setTrocas(v);
                    setCompara(v);

                    free(getVet(v));
                }
                //Salva a média na matriz
                setTabela(tabela, tipos, linha, metodos, t/5.0, comparacoes/5.0, troca/5.0);
            }else{
                //Cria vetor
                escolhaOrdenacao(v, semente, tipos, 10);

                //Chama método de ordenação
                t = chamaOrdenacao(v, metodos);

                //Salva os dados na tabela
                setTabela(tabela, tipos, linha, metodos, t, (double)*getCompara(v), (double)*getTrocas(v));

                //Setando variáveis de comparações e trocas para 0
                setCompara(v);
                setTrocas(v);

                free(getVet(v));
            }
        }
    }

    for(int metodos = 0; metodos < 1; metodos++){
        printMatriz(tabela, metodos);
    }

    free(v);
    free(tabela);
    return 0;
}

#include <stdio.h>
#include "sort.h"
#include "ES.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
    long long int entradas[5] = {1000, 10000, 100000, 1000000, 10000000};
    int semente; //Escolhendo semente
    double t, media, comparacoes, troca;
    vetor *v = criaVetor();
    metricas *tabela = criaMetricas();
    clock_t inicio, fim;

    //Entradas 1000 - 10000 - 100000 - 1000000 - 10000000
    //Tipos: Aleatório - Crescente - Decrescente - Semi-Ordenado

    //Percorrendo os 7 tipos de métodos de ordenação
    for(int metodos = 0; metodos < 1; metodos++){
        //Percorrendo os tipos
        for(int tipos = 0; tipos < 4; tipos++){
            //Percorrendo as entradas
            for(int entrada = 0; entrada < 5; entrada++){
                setTam(v, entradas[entrada]);
                media = troca = comparacoes = 0;

                //Verificando se os dados estarão aleatórios/desordenados
                if(tipos == 0 || tipos == 3){
                    //Para garantir a média
                    for(int i = 0; i < 5; i++){
                        semente = i;

                        //Cria vetor
                        escolhaOrdenacao(v, semente, tipos, 10);

                        //Chama método de ordenação
                        switch (metodos) {
                            case 0:
                                inicio = clock();
                                bubbleSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                                fim = clock();
                                break;
                            case 1:
                                inicio = clock();
                                bubbleSortInteligente(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                                fim = clock();
                                break;
                            case 2:
                                inicio = clock();
                                selectionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                                fim = clock();
                                break;
                            case 3:
                                inicio = clock();
                                insertionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                                fim = clock();
                                break;
                            case 4:
                                inicio = clock();
                                mergeSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                                fim = clock();
                                break;
                            case 5:
                                inicio = clock();
                                quickSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                                fim = clock();
                                break;
                            default:
                                inicio = clock();
                                quickSortDual(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                                fim = clock();
                        }

                        //Salva tempo, salva comparação, salva trocas
                        t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
                        media += t;
                        comparacoes += *getCompara(v);
                        troca += *getTrocas(v);

                        setTrocas(v);
                        setCompara(v);

                        free(getVet(v));
                    }
                    //Salva a média na matriz
                    setTabela(tabela, tipos, entrada, metodos, t/5, comparacoes/5, troca/5);
                }else{
                    //Cria vetor
                    escolhaOrdenacao(v, semente, tipos, 10);

                    //Chama método de ordenação
                    switch (metodos) {
                        case 0:
                            inicio = clock();
                            bubbleSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                            fim = clock();
                            break;
                        case 1:
                            inicio = clock();
                            bubbleSortInteligente(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                            fim = clock();
                            break;
                        case 2:
                            inicio = clock();
                            selectionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                            fim = clock();
                            break;
                        case 3:
                            inicio = clock();
                            insertionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                            fim = clock();
                            break;
                        case 4:
                            inicio = clock();
                            mergeSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                            fim = clock();
                            break;
                        case 5:
                            inicio = clock();
                            quickSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                            fim = clock();
                            break;
                        default:
                            inicio = clock();
                            quickSortDual(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                            fim = clock();
                    }

                    //Salva tempo, salva comparação, salva trocas
                    t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
                    setTabela(tabela, tipos, entrada, metodos, t, (double)*getCompara(v), (double)*getTrocas(v));
                    setCompara(v);
                    setTrocas(v);

                    free(getVet(v));
                }
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

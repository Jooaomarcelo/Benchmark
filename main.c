/*
    Código-Fonte para a implementação de um sistema de Benchmark
    para algoritmos de ordenação.

    Grupo: 

    Criado em 14/04/2024
*/

#include <stdio.h>
#include <time.h>
#include "ES.h"
#include "sort.h"
/*
    Include das bibliotecas com funções de entrada e saída
    e dos algoritmos de ordenação.
*/

int main() {
    clock_t inicio, fim;
    FILE* arquivo;
    par *params;
    vet *vetor;
    char nomeArquivo[31];
    double t;
    int controle_criacao=0, controle_ordenacao=0, tipoOrdenacao=0;
    int trocas=0, compara=0;


    printf("----- Sistema de Benchmark -----\n");
    printf("O usuário ja possui os arquivos a serem analisados?\n0. Não\n1. Sim\n");
    scanf(" %d", &controle_criacao);
    if(controle_criacao == 0) {
        do {
            arquivo = abreArquivo(arquivo);
            params = obtemParametros(params);
            switch (params->tipoOrdenacao){
            case 1:
                geraAmostraAleatoria(params, arquivo);
                break;
            
            case 2:
                geraAmostraCrescente(params, arquivo);
                break;
            
            case 3:
                geraAmostraSemiOrdenada(params, arquivo);
                break;
            
            case 4:
                geraAmostraDescrescente(params, arquivo);
                break;
            
            default:
                break;
            }

            fclose(arquivo);
            printf("Todos os arquivos foram criados?\n0. Não\n1. Sim\n");
            scanf(" %d", &controle_criacao);
        } while(controle_criacao == 0);
    }
    
    while(controle_ordenacao == 0){
        arquivo = abreArquivo(arquivo);
        vetor = criaVetor(arquivo, vetor);
        imprimeVetor(vetor->v, vetor->tamanho);
        printf("Tipo de ordenação que se deseja analisar:\n1. Bolha\n2. Bolha Inteligente\n3. Seleção\n4. Inserção\n5. Merge-Sort\n6. Quick-Sort\n7. Dual-Pivot Quick-Sort");
        scanf(" %d", &tipoOrdenacao);
        trocas=0, compara=0;
        switch (tipoOrdenacao){
        case 1:
            inicio = clock();

            bubbleSort(vetor->v, vetor->tamanho, &compara, &trocas);

            fim = clock();

            t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
            printf("Tempo gasto: %.4fms\nNº de trocas: %d, Nº de comparações: %d\n", t, trocas, compara);
            break;
        
        case 2:
            inicio = clock();

            bubbleSortInteligente(vetor->v, vetor->tamanho, &compara, &trocas);

            fim = clock();
            t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
            printf("Tempo gasto: %.4fms\nNº de trocas: %d, Nº de comparações: %d\n", t, trocas, compara);
            break;

        case 3:
            inicio = clock();

            bubbleSortInteligente(vetor->v, vetor->tamanho, &compara, &trocas);

            fim = clock();
            t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
            printf("Tempo gasto: %.4fms\nNº de trocas: %d, Nº de comparações: %d\n", t, trocas, compara);
            break;
        
        case 4:
            inicio = clock();

            bubbleSortInteligente(vetor->v, vetor->tamanho, &compara, &trocas);

            fim = clock();
            t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
            printf("Tempo gasto: %.4fms\nNº de trocas: %d, Nº de comparações: %d\n", t, trocas, compara);
            break;
        
        case 5:
            inicio = clock();

            bubbleSortInteligente(vetor->v, vetor->tamanho, &compara, &trocas);

            fim = clock();
            t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
            printf("Tempo gasto: %.4fms\nNº de trocas: %d, Nº de comparações: %d\n", t, trocas, compara);
            break;
        
        default:
            break;
        }

        printf("Deseja continuar analisando os tipos de ordenação?\n0. Sim\n1. Não\n");
        scanf(" %d", &controle_ordenacao);
    } 
    return 0;
}
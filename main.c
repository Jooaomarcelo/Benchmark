#include <stdio.h>
#include "sort.h"
#include "ES.h"
#include <stdlib.h>

void printa(long long int *vet, long long int tam){
    printf("\nPrintando vetor: ");
    for(int i = 0; i < tam; i++){
        printf("%lld ", vet[i]);
    }
}

int main(void) {
    vetor *v = criaVetor();
    int qualOrdenacao = 7, tipoOrdenacao = 4, semente = 15, porcentagem = 10;
    long long *vet;
    FILE *file = fopen("C:\\Users\\Usuario\\Documents\\01 - Universidade\\3 - Periodo\\CTCO02 - Algoritimo e Estruturas de Dados II\\8_Trabalho1\\Teste.txt", "w");
    
    printf("\n1 - BS, 2 - BSI, 3 - S, 4 - I, 5 - M, 6 - Q, 7 - QD");
    printf("\nDigite o qual ordenação você usará:");
    scanf("%d", &qualOrdenacao);

    while(qualOrdenacao > 0 && qualOrdenacao < 8){
        printf("\n\n1 - Aleatório, 2 - Semi-Aleatorio, 3 - Crescente, 4 - Decrescente");
        printf("\nDigite o tipo de ordenação: ");
        scanf("%d", &tipoOrdenacao);

        escolhaOrdenacao(v, semente, tipoOrdenacao, porcentagem);

        switch(qualOrdenacao){
            case 1:
                printf("\nBubbleSort");
                bubbleSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                break;
            case 2:
                printf("\nBubbleSortInteligênte");
                bubbleSortInteligente(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                break;
            case 3:
                printf("\nSelectionSort");
                selectionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                break;
            case 4:
                printf("\nInsertionSort");
                insertionSort(getVet(v), getTam(v), getCompara(v), getTrocas(v));
                break;
            case 5:
                printf("\nMergeSort");
                mergeSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                break;
            case 6:
                printf("\nQuickSort");
                quickSort(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
                break;
            default:
                printf("\nQuickSortDualPivot");
                quickSortDual(getVet(v), 0, getTam(v) - 1, getCompara(v), getTrocas(v));
        }
        
        printf("\nComparações: %ld\nTrocas: %ld", *getCompara(v), *getTrocas(v));

        vet = getVet(v);
        for(long long int i = 0; i < getTam(v); i++){
            fprintf(file, "%lld\n", vet[i]);
        }

        free(getVet(v));
        setCompara(v);
        setTrocas(v);

        
        printf("\n\n1 - BS, 2 - BSI, 3 - S, 4 - I, 5 - M, 6 - Q, 7 - QD");
        printf("\nDigite o qual ordenação você usará:");
        scanf("%d", &qualOrdenacao);
    }
    return 0;
}

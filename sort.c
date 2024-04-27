#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int *vet, int tam, int *compara, int *trocas){
    int aux;
    for(int i = 0; i < tam; i++){
        for(int j = 1; j < tam; j++){
            (*compara)++;
            if(vet[j] < vet[j-1]){
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
                (*trocas)++;
            }
        }
    }
}

void bubbleSortInteligente(int *vet, int tam, int *compara, int *trocas){
    int aux, ver = 0;
    for(int i = 0; i < tam && ver == 0; i++){
        for(int j = 1; j < tam - i; j++){
            ver = 1;
            (*compara)++;
            if(vet[j] < vet[j-1]){
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
                ver = 0;
                (*trocas)++;
            }
        }
    }
}

int menorElemento(int *vet, int tam, int i, int *compara){
    int menor = i;
    for(int j = i + 1; j < tam; j++){
        (*compara)++;
        if(vet[j] < vet[menor]){
            menor = j;
        }
    }
    return menor;
}

void selectionSort(int *vet, int tam, int *compara, int *trocas){
    int menor, aux;
    for(int i = 0; i < tam - 1; i++){
        menor = menorElemento(vet, tam, i+1, compara);
        (*compara)++;
        if(vet[i] > vet[menor]){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
            (*trocas)++;
        }
    }
}

void insertionSort(int *vet, int tam, int *compara, int *trocas){
    int aux, pos;
    for(int i = 1; i < tam; i++){
        pos = i - 1;
        aux = vet[i];
        while(vet[pos] > aux && pos >= 0){
            vet[pos+1] = vet[pos];
            pos--;
            (*trocas)++;
            (*compara)++;
        }
        (*compara)++;
        if(pos + 1 != i){
            vet[pos+1] = aux;
            (*trocas)++;
        }
    }
}

void merge(int *vet, int inicio, int meio, int fim, int *compara, int *trocas){
    int v1 = inicio, v2 = meio+1, *aux = (int*)malloc(sizeof(int) * (fim - inicio + 1)), i = 0;
    while(v1 <= meio && v2 <= fim){
        (*compara)++;
        if(vet[v1] < vet[v2]){
            aux[i++] = vet[v1++];
        }else{
            aux[i++] = vet[v2++];
        }
    }
    while(v1 <= meio){
        aux[i++] = vet[v1++];
    }
    while(v2 <= fim){
        aux[i++] = vet[v2++];
    }
    i = 0;
    for(int j = inicio; j <= fim; j++){
        (*trocas)++;
        vet[j] = aux[i++];
    }
    free(aux);
}

void mergeSort(int *vet, int inicio, int fim, int *compara, int *trocas){
    int meio = (inicio + fim)/2;
    (*compara)++;
    if(inicio < fim){
        mergeSort(vet, inicio, meio, compara, trocas);
        mergeSort(vet, meio+1, fim, compara, trocas);
        merge(vet, inicio, meio, fim, compara, trocas);
    }
}

void troca(int *v1, int *v2){
    int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

int particiona(int *vet, int inicio, int fim, int *compara, int *trocas){
    int pivo = vet[inicio], pos = inicio;
    for(int i = inicio + 1; i <= fim; i++){
        (*compara)++;
        if(vet[i] < pivo){
            pos++;
            (*compara)++;
            if(pos != i){
                troca(&vet[i], &vet[pos]);
                (*trocas)++;
            }
        }
    }
    (*compara)++;
    if(pos != inicio){
        troca(&vet[pos], &vet[inicio]);
        (*trocas)++;
    }
    return pos;
}

void quickSort(int *vet, int inicio, int fim, int *compara, int *trocas){
    int pivo;
    (*compara)++;
    if(inicio < fim){
        pivo = particiona(vet, inicio, fim, compara, trocas);
        quickSort(vet, inicio, pivo - 1, compara, trocas);
        quickSort(vet, pivo + 1, fim, compara, trocas);
    }
}

int particionaDual(int *vet, int inicio, int fim, int *p1, int *compara, int *trocas){
    int pivo1, pivo2, pos1 = inicio, pos2 = fim;
    (*compara)++;
    if(vet[inicio] > vet[fim]){
        troca(&vet[inicio], &vet[fim]);
        (*trocas)++;
    }
    pivo1 = vet[inicio], pivo2 = vet[fim];
    for(int i = inicio + 1; i <= pos2; i++){
        (*compara)++;
        if(vet[i] < pivo1){
            pos1++;
            (*compara)++;
            if(i != pos1){
                troca(&vet[i], &vet[pos1]);
                (*trocas)++;
            }
        }else if(vet[i] >= pivo2){
            pos2--;
            (*compara)++;
            while(i < pos2 && vet[pos2] > pivo2){
                pos2--;
                (*compara)++;
            }
            troca(&vet[i], &vet[pos2]);
            (*trocas)++;
            (*compara)++;
            if(vet[i] < pivo1) {
                pos1++;
                troca(&vet[i], &vet[pos1]);
                (*trocas)++;
            }
        }
    }
    troca(&vet[pos1], &vet[inicio]);
    troca(&vet[pos2], &vet[fim]);
    (*trocas+=2);
    *p1 = pos1;
    return pos2;
}

void quickSortDual(int *vet, int inicio, int fim, int *compara, int *trocas){
    int p1, p2;
    (*compara)++;
    if(inicio < fim){
        p2 = particionaDual(vet, inicio, fim, &p1, compara, trocas);
        quickSortDual(vet, inicio, p1 - 1, compara, trocas);
        quickSortDual(vet, p1 + 1, p2 - 1, compara, trocas);
        quickSortDual(vet, p2 + 1, fim, compara, trocas);
    }
}

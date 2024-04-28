#include "sort.h"
#include <stdlib.h>

void bubbleSort(long long int *vet, long long int tam, long int *compara, long int *trocas){
    long long int aux;
    for(long long int i = 0; i < tam; i++){
        for(long long int j = 1; j < tam; j++){
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

void bubbleSortInteligente(long long int *vet, long long int tam, long int *compara, long int *trocas){
    long long int aux;
    int ver = 0;
    for(long long int i = 0; i < tam && ver == 0; i++){
        for(long long int j = 1; j < tam - i; j++){
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

long long int menorElemento(long long int *vet, long long int tam, long long int i, long int *compara){
    long long int menor = i;
    for(long long int j = i + 1; j < tam; j++){
        (*compara)++;
        if(vet[j] < vet[menor]){
            menor = j;
        }
    }
    return menor;
}

void selectionSort(long long int *vet, long long int tam, long int *compara, long int *trocas){
    long long int menor, aux;
    for(long long int i = 0; i < tam - 1; i++){
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

void insertionSort(long long int *vet, long long int tam, long int *compara, long int *trocas){
    long long int aux, pos;
    for(long long int i = 1; i < tam; i++){
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

void merge(long long int *vet, long long int inicio, long long int meio, long long int fim, long int *compara, long int *trocas){
    long long int v1 = inicio, v2 = meio+1, i = 0, *aux = (long long int*)malloc(sizeof(long long int) * (fim - inicio + 1));

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
    for(long long int j = inicio; j <= fim; j++){
        (*trocas)++;
        vet[j] = aux[i++];
    }
    free(aux);
}

void mergeSort(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas){
    long long int meio = (inicio + fim)/2;
    (*compara)++;
    if(inicio < fim){
        mergeSort(vet, inicio, meio, compara, trocas);
        mergeSort(vet, meio+1, fim, compara, trocas);
        merge(vet, inicio, meio, fim, compara, trocas);
    }
}

void troca(long long int *v1, long long int *v2){
    long long int aux = *v1;
    *v1 = *v2;
    *v2 = aux;
}

long long int particiona(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas){
    long long int pivo = vet[inicio], pos = inicio;
    for(long long int i = inicio + 1; i <= fim; i++){
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

void quickSort(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas){
    long long int pivo;
    (*compara)++;
    if(inicio < fim){
        pivo = particiona(vet, inicio, fim, compara, trocas);
        quickSort(vet, inicio, pivo - 1, compara, trocas);
        quickSort(vet, pivo + 1, fim, compara, trocas);
    }
}

long long int particionaDual(long long int *vet, long long int inicio, long long int fim, long long int *p1, long int *compara, long int *trocas){
    long long int pivo1, pivo2, pos1 = inicio, pos2 = fim;

    (*compara)++;
    if(vet[inicio] > vet[fim]){
        troca(&vet[inicio], &vet[fim]);
        (*trocas)++;
    }

    pivo1 = vet[inicio], pivo2 = vet[fim];

    for(long long int i = inicio + 1; i < pos2; i++){
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

void quickSortDual(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas){
    long long int p1, p2;
    (*compara)++;
    if(inicio < fim){
        p2 = particionaDual(vet, inicio, fim, &p1, compara, trocas);
        quickSortDual(vet, inicio, p1 - 1, compara, trocas);
        quickSortDual(vet, p1 + 1, p2 - 1, compara, trocas);
        quickSortDual(vet, p2 + 1, fim, compara, trocas);
    }
}

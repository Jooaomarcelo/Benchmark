#ifndef INC_8_TRABALHO1_SORT_H
#define INC_8_TRABALHO1_SORT_H

/* Funções de Ordenação - Ascendente */

//Parte do algoritmo de seleção, serve para encontrar o menor elemento na parte desordenada
long long int menorElemento(long long int *vet, long long int tam, long long int i, long long int *compara);

//Algoritmo de seleção (selection sort)
//Complexidade: O(n²) comparações e O(1) trocas no melhor caso (ordenado), O(n²) comparações e O(n) trocas no pior caso(ordenado ao contrário)
//Estável: Não
void selectionSort(long long int *vet, long long int tam, long long int *compara, long long int *trocas);

//Algoritmo de inserção (insertion sort)
//Complexidade: O(n) comparações no melhor caso (ordenado), O(n²) comparações no pior caso (ordenado ao contrário)
//Estável: Sim
void insertionSort(long long int *vet, long long int tam, long long int *compara, long long int *trocas);

//Algoritmo que irá juntar as partes do vetor
void merge(long long int *vet, long long int inicio, long long int meio, long long int fim, long long int *compara, long long int *trocas);

//Algoritmo MergeSort (dividir para conquistar)
//Complexidade: O(n logn), esse algoritmo em si possui complexidade O(logn), mas o algoritmo merge possui complexidade O(n)
//Estável: Não
void mergeSort(long long int *vet, long long int inicio, long long int fim, long long int *compara, long long int *trocas);

//Função que fará uma troca no vetor
void troca(long long int *v1, long long int *v2);

//Algoritmo que adiciona o pivô na posição certa dele, e divide o vetor
long long int particiona(long long int *vet, long long int inicio, long long int fim, long long int *compara, long long int *trocas);

//Algoritmo QuickSort
//Complexidade: O(n logn) para os melhores casos (vetor totalmente aleatório), O(n²) para os piores casos (ordenado)
//Estável: Não
void quickSort(long long int *vet, long long int inicio, long long int fim, long long int *compara, long long int *trocas);

//Algoritmo particiona com os dois pivot (é o do JAVA.sort())
long long int particionaDual(long long int *vet, long long int inicio, long long int fim, long long int *p1, long long int *compara, long long int *trocas);

//Algoritmo Dual Pivot QuickSort
void quickSortDual(long long int *vet, long long int inicio, long long int fim, long long int *compara, long long int *trocas);

#endif //INC_8_TRABALHO1_SORT_H

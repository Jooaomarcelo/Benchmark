

/*
// Ordenação bolha e bolha inteligente:
int bolha (int *vet, int tam);
int bolhaInteligente (int *vet, int tam);


//Algoritmo BubbleSort
//Complexidade: O(n²)
//Estável: Sim
void bubbleSort(long long int *vet, long long int tam, long int *compara, long int *trocas);

//Algoritmo bubble sort otimizado
//Complexidade: O(n) no melhor caso (já ordenado), O(n²) no pior caso (ordenado ao contrário)
//Estável: Sim
void bubbleSortInteligente(long long  int *vet, long long int tam, long int *compara, long int *troca);

//Parte do algoritmo de seleção, serve para encontrar o menor elemento na parte desordenada
long long int menorElemento(long long int *vet, long long int tam, long long int i, long int *compara);


//Algoritmo de seleção (selection sort)
//Complexidade: O(n²) comparações e O(1) trocas no melhor caso (ordenado), O(n²) comparações e O(n) trocas no pior caso(ordenado ao contrário)
//Estável: Não
void selectionSort(long long int *vet, long long int tam, long int *compara, long int *trocas);

// QuickSort:
void quickSort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int fim);
*/

//Cabeçalhos com comparações e trocas

//Algoritmo BubbleSort
//Complexidade: O(n²)
//Estável: Sim
void bubbleSort(int *vet, int tam, int *compara, int *trocas);

//Algoritmo bubble sort otimizado
//Complexidade: O(n) no melhor caso (já ordenado), O(n²) no pior caso (ordenado ao contrário)
//Estável: Sim
void bubbleSortInteligente(int *vet, int tam, int *compara, int *troca);

//Parte do algoritmo de seleção, serve para encontrar o menor elemento na parte desordenada
int menorElemento(int *vet, int tam, int i, int *compara);

//Algoritmo de seleção (selection sort)
//Complexidade: O(n²) comparações e O(1) trocas no melhor caso (ordenado), O(n²) comparações e O(n) trocas no pior caso(ordenado ao contrário)
//Estável: Não
void selectionSort(int *vet, int tam, int *compara, int *trocas);


//Algoritmo de inserção (insertion sort)
//Complexidade: O(n) comparações no melhor caso (ordenado), O(n²) comparações no pior caso (ordenado ao contrário)
//Estável: Sim

void insertionSort(long long int *vet, long long int tam, long int *compara, long int *trocas);

//Algoritmo que irá juntar as partes do vetor
void merge(long long int *vet, long long int inicio, long long int meio, long long int fim, long int *compara, long int *trocas);

void insertionSort(int *vet, int tam, int *compara, int *trocas);

//Algoritmo que irá juntar as partes do vetor
void merge(int *vet, int inicio, int meio, int fim, int *compara, int *trocas);


//Algoritmo MergeSort (dividir para conquistar)
//Complexidade: O(n logn), esse algoritmo em si possui complexidade O(logn), mas o algoritmo merge possui complexidade O(n)
//Estável: Não

void mergeSort(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas);

//Função que fará uma troca no vetor
void troca(long long int *v1, long long int *v2);

//Algoritmo que adiciona o pivô na posição certa dele, e divide o vetor
long long int particiona(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas);

void mergeSort(int *vet, int inicio, int fim, int *compara, int *trocas);

//Função que fará uma troca no vetor
void troca(int *v1, int *v2);

//Algoritmo que adiciona o pivô na posição certa dele, e divide o vetor
int particiona(int *vet, int inicio, int fim, int *compara, int *trocas);


//Algoritmo QuickSort
//Complexidade: O(n logn) para os melhores casos (vetor totalmente aleatório), O(n²) para os piores casos (ordenado)
//Estável: Não

void quickSort(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas);

//Algoritmo particiona com os dois pivot (é o do JAVA.sort())
long long int particionaDual(long long int *vet, long long int inicio, long long int fim, long long int *p1, long int *compara, long int *trocas);

//Algoritmo Dual Pivot QuickSort
void quickSortDual(long long int *vet, long long int inicio, long long int fim, long int *compara, long int *trocas);

#endif //INC_8_TRABALHO1_SORT_H

void quickSort(int *vet, int inicio, int fim, int *compara, int *trocas);

//Algoritmo particiona com os dois pivot (é o do JAVA.sort())
int particionaDual(int *vet, int inicio, int fim, int *p1, int *compara, int *trocas);

//Algoritmo Dual Pivot QuickSort
void quickSortDual(int *vet, int inicio, int fim, int *compara, int *trocas);


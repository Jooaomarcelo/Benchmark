// Ordenação bolha e bolha inteligente:
int bolha (int *vet, int tam);
int bolhaInteligente (int *vet, int tam);

// Ordenação por seleção e a função para achar a posição
// do menor elemento em um vetor:
int acharMenor(int *v,int inicio, int tam);
void selecao(int *v, int tam);

// Ordenação por inserção:
void insertionSort(int *v, int tam);

// MergeSort:
void mergesort(int *v, int inicio, int fim);
void merge(int *v, int inicio, int meio, int fim);

// QuickSort:
void quickSort(int *v, int inicio, int fim);
int particiona(int *v, int inicio, int fim);

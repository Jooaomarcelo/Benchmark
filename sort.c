#include <stdio.h>
#include <stdlib.h>

int bolha (int *vet, int tam) {
	int cont=0, aux;
	for(int i=0;i<tam;i++) {
		for(int j=1;j<tam;j++) {
			if(vet[j] < vet[j-1]) {
				aux = vet[j-1];
				vet[j-1] = vet[j];
				vet[j] = aux;
			}
			cont++;
		}
	}
	return cont;
}

int bolhaInteligente (int *vet, int tam) {
	//troca=0 - Não houve troca
	//troca=1 - Houve troca
	int cont=0, aux, troca;

	for(int i=0;i<tam;i++) {
		troca=0;
		for(int j=1;j<tam-i;j++) {
			if(vet[j-1] > vet[j]) {
				aux = vet[j-1];
				vet[j-1] = vet[j];
				vet[j] = aux;
				troca = 1;
			}
			cont++;
		}
		if(troca==0)
			return cont;
		}
	return cont;
}

int acharMenor(int *v,int inicio, int tam) {
	int menor = v[inicio], posMenor = inicio;
	for(int i = inicio+1; i < tam; i++) {
		if(v[i] < menor) {
			menor = v[i];
			posMenor = i;
		}
	}
	return posMenor;
}

void selecao(int *v, int tam) {
	int marc=0, menor=0;
	while(marc < tam-1) {
		menor = acharMenor(v, marc, tam);
		if(v[menor] < v[marc]) {
			int aux=v[marc];
			v[marc] = v[menor];
			v[menor] = aux;
		}
		marc++;
	}
	return;
}

void insertionSort(int *v, int tam) {
	int pos, marcador, aux;
	for(marcador = 1; marcador < tam; marcador++) {
		pos = marcador - 1;
		aux = v[marcador];
		while(pos >= 0 && aux < v[pos]) {
			v[pos + 1] = v[pos];
			pos--;
		}
		v[pos+1] = aux;
	}
}

void mergesort(int *v, int inicio, int fim) {
	int meio = (inicio + fim)/2;
	if(inicio < fim) {
		mergesort(v, inicio, meio);
		mergesort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
}

void merge(int *v, int inicio, int meio, int fim) {
	// v1[inicio, meio], v2[meio+1, fim], k[inicio, fim]
	// vAux -> vetor auxiliar ordenado do vetor original
	int v1 = inicio, v2 = meio+1, k=0, *vAux;
	vAux = (int*)malloc((fim-inicio+1) * sizeof(int));

	// Copia os valores de v para vAux de forma ordenada
	while(v1 <= meio && v2 <= fim) {
		if(v[v1] < v[v2]) {
			vAux[k++] = v[v1++];
		}
		else {
			vAux[k++] = v[v2++];
		}
	}

	// Copia o resto de v1 ou de v2 para vAux
	while(v1 <= meio) {
		vAux[k++] = v[v1++];
	}
	while(v2 <= fim) {
		vAux[k++] = v[v2++];
	}

	// Copia os valores de vAux para vetor original
	for(int i=inicio;i<=fim;i++) {
		v[i] = vAux[i - inicio];
	}
	free(vAux);
}

void quickSort(int *v, int inicio, int fim) {
	if(inicio < fim) {
		int pivo = particiona(v, inicio, fim);
		quickSort(v, inicio, pivo - 1);
		quickSort(v, pivo + 1, fim);
	}
}

int particiona(int *v, int inicio, int fim) {
	int pos = inicio, pivo = v[inicio], aux;
	for(int i = inicio + 1; i <= fim; i++) {
		if(v[i] < v[pos]) {
			pos++;
			if(i != pos) {
				aux = v[i];
				v[i] = v[pos];
				v[pos] = aux;
			}
		}
	}
	v[inicio] = v[pos];
	v[pos] = pivo;
	return pos;
}


//Códigos com comparações e trocas

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
        (*compara)++;
        while(vet[pos] > aux && pos >= 0){
            vet[pos+1] = vet[pos];
            pos--;
        }
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
    if(inicio < fim){
        mergeSort(vet, inicio, meio, compara, trocas);
        mergeSort(vet, meio+1, fim, compara, trocas);
        merge(vet, inicio, meio, fim, compara, trocas);
    }
}

int particiona(int *vet, int inicio, int fim, int *compara, int *trocas){
    int pivo = vet[inicio], aux, pos = inicio;
    for(int i = inicio + 1; i <= fim; i++){
        (*compara)++;
        if(vet[i] < pivo){
            pos++;
            (*compara)++;
            if(pos != i){
                aux = vet[i];
                vet[i] = vet[pos];
                vet[pos] = aux;
                (*trocas)++;
            }
        }
    }
    (*compara)++;
    if(pos != inicio){
        aux = vet[pos];
        vet[pos] = vet[inicio];
        vet[inicio] = aux;
        (*trocas)++;
    }
    return pos;
}

void quickSort(int *vet, int inicio, int fim, int *compara, int *trocas){
    int pivo;
    if(inicio < fim){
        pivo = particiona(vet, inicio, fim, compara, trocas);
        quickSort(vet, inicio, pivo - 1, compara, trocas);
        quickSort(vet, pivo + 1, fim, compara, trocas);
    }
}

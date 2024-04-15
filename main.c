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
    double t;
    inicio = clock();
    fim = clock();
    t = ((float)(fim - inicio))/((CLOCKS_PER_SEC/1000));
    printf("%.4fms\n", t);
    return 0;
}
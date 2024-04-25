#include <stdio.h>
#include <stdlib.h>

typedef struct parametros par;

FILE* abreArquivo();

par* obtemParamentros();

void geraAmostraAleatoria(par parametro, FILE* arquivo);

void geraAmostraCrescente(par parametro, FILE* arquivo);

void geraAmostraSemiOrdenada(par parametro, FILE* arquivo);

void geraAMostraDescrescente(par parametro, FILE* arquivo);

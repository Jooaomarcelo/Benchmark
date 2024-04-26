#include <stdio.h>
#include <stdlib.h>

typedef struct parametros par;

FILE* abreArquivo();

par* obtemParametros();

void geraAmostraAleatoria(par parametro, FILE* arquivo);

void geraAmostraCrescente(par parametro, FILE* arquivo);

void geraAmostraSemiOrdenada(par parametro, FILE* arquivo);

void geraAmostraDescrescente(par parametro, FILE* arquivo);

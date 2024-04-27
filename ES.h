#ifndef INC_8_TRABALHO1_ES_H
#define INC_8_TRABALHO1_ES_H

typedef struct vetor vetor;

vetor *criaVetor();

int *getVet(vetor *v);

long int *getCompara(vetor *v);

long int *getTrocas(vetor *v);

long long int getTam(vetor *v);

int* geraAleatorios(long long int tam, int semente);

int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente);

int* geraOrdenados(long long int tam, int ordem);

void escolhaOrdenacao(vetor *v);

#endif //INC_8_TRABALHO1_ES_H

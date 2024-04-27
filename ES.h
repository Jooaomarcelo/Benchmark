#ifndef INC_8_TRABALHO1_ES_H
#define INC_8_TRABALHO1_ES_H

typedef struct vetor vetor;

vetor *criaVetor();

long long int *getVet(vetor *v);

long int *getCompara(vetor *v);

long int *getTrocas(vetor *v);

long long int getTam(vetor *v);

long long int* geraAleatorios(long long int tam, int semente);

long long int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente);

long long int* geraOrdenados(long long int tam, int ordem);

void escolhaOrdenacao(vetor *v, int semente, int tipoOrdenacao, int porcentagem);

#endif //INC_8_TRABALHO1_ES_H

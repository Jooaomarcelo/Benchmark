#ifndef INC_8_TRABALHO1_ES_H
#define INC_8_TRABALHO1_ES_H

typedef struct vetor vetor;

typedef struct metricas metricas;

metricas *criaMetricas();

void setTabela(metricas *tabela, int tipo, int entrada, int metodo, double tempo, double comparacoes, double troca);

vetor *criaVetor();

void setTam(vetor *v, long long int tam);

long long int *getVet(vetor *v);

long int *getCompara(vetor *v);

void setCompara(vetor *v);

long int *getTrocas(vetor *v);

void setTrocas(vetor *v);

long long int getTam(vetor *v);

long long int* geraAleatorios(long long int tam, int semente);

long long int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente);

long long int* geraOrdenados(long long int tam, int ordem);

void escolhaOrdenacao(vetor *v, int semente, int tipoOrdenacao, int porcentagem);

void printMatriz(metricas *tabela, int metodo);

#endif //INC_8_TRABALHO1_ES_H

#ifndef INC_8_TRABALHO1_ES_H
#define INC_8_TRABALHO1_ES_H

/* Estruturas para lidar com os dados */

//Estrutura que contém o vetor a ser ordenado/já ordenado, as variáveis de trocas e comparações, e o tamanho do vetor.
typedef struct vetor vetor;

//Estrutura que contém 3 matrizes, as linhas são as entradas e as colunas os tipos de ordenação (Aleatório - Semi-Aleatório - Crescente - Decrescente).
//A primeira matriz é a de tempo, a segunda é a de trocas, e a última é a de comparações.
typedef struct metricas metricas;

/* Funções para o gerenciamento dos dados e das estruturas */

//Aloca um vetor de 5 posições do tipo métricas.
metricas *criaMetricas();

//Na tabela dada, salva os dados do método passado em 3 matrizes. A de tempo, comparações, e trocas.
void setTabela(metricas *tabela, int tipo, int entrada, int metodo, double tempo, double comparacoes, double troca);

//Aloca dinamicamente uma variável do tipo vetor.
vetor *criaVetor();

//Retorna o tamanho do vetor.
long long int getTam(vetor *v);

//Seta o valor do tamanho do vetor para lidar com as diferentes entradas de dados.
void setTam(vetor *v, long long int tam);

//Retorna o vetor.
long long int *getVet(vetor *v);

//Retorna o endereço da variável de comparações.
long long int *getCompara(vetor *v);

//Seta o valor da variável de comparações para 0.
void setCompara(vetor *v);

//Retorna o endereço da variável de trocas.
long long int *getTrocas(vetor *v);

//Seta o valor da variável de trocas para 0.
void setTrocas(vetor *v);

//Recebe o tamanho do vetor e uma semente, com isso é gerado um vetor de tam elementos aleatórios.
long long int* geraAleatorios(long long int tam, int semente);

//Recebe o tamanho do vetor, a porcentagem que estará desordenada e uma semente, com isso é gerado um vetor de tam elementos, a parte desordenada estará no início.
long long int* geraQuaseOrdenados(long long int tam, int porcentagem, int semente);

//Recebe o tamanho de vetor e a ordem, se a ordem for 0 o vetor retornada estará crescente, se for 1 o vetor retornado estará decrescente.
long long int* geraOrdenados(long long int tam, int ordem);

//Função responsável por chamar os tipos de ordenação e salvar o vetor retornado no vetor da estrutura vetor.
void escolhaOrdenacao(vetor *v, int semente, int tipoOrdenacao, int porcentagem);

//Função que imprime na tela as informações das matrizes da estrutura métricas.
void printMatriz(metricas *tabela, int metodo);

#endif //INC_8_TRABALHO1_ES_H

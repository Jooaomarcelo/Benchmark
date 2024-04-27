typedef struct vetor vetor;

vetor *criaVetor();

int *getVet(vetor *v);

long int *getCompara(vetor *v);

long int *getTrocas(vetor *v);

long long int getTam(vetor *v);

int* geraAleatorios(long long int tam, int semente);

int* geraQuaseOrdenados(long long int tam, int porcentagem);

int* geraOrdenados(long long int tam, int ordem);

void escolhaOrdenacao(vetor *v, int semente, int tipoOrdenacao, int porcentagem);

#include "../h/aresta.h"

//Cria uma matriz NxN de acordo com o tamanho do vetor de pontos (N) passado
//Cada posicao [i][j] da matriz contem a distancia entre os pontos i e j
Aresta** calculaDistanciasVetorPontos(VetorPontos v) {
    Aresta** matriz = (Aresta**) malloc(v.tamanho*sizeof(Aresta*));
    for(int i = 0; i < v.tamanho; i++)
        matriz[i] = (Aresta*) malloc(v.tamanho*sizeof(Aresta));
    
    for(int i = 0; i < v.tamanho; i++)
        for(int j = i; j < v.tamanho; j++) {
            if(i == j) {
                matriz[i][i].distancia = 0.0;
                matriz[i][i].p1 = matriz[i][i].p2 = NULL;
            }
            else {
                matriz[j][i].distancia = calculaDistanciaPontos(v.vetor_interno[i], v.vetor_interno[j]);
                matriz[i][j].distancia = 0.0;

                matriz[i][j].p1 = NULL;
                matriz[i][j].p2 = NULL;
                
                matriz[j][i].p1 = &(v.vetor_interno[i]);
                matriz[j][i].p2 = &(v.vetor_interno[j]);
            }
        }

    return matriz;
}

static int comparaArestas(const void* a1, const void* a2) {
    double diferenca = ((Aresta*) a1)->distancia - ((Aresta*) a2)->distancia;
    
    if(diferenca < 0) return -1; 
    return 1;
}

Aresta* criaConjunto(Aresta** matriz, int n) {
    int temp = (((n*n)- n)/2);
    Aresta* aresta = (Aresta*) malloc(temp*sizeof(Aresta));
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i != j){
                aresta[count] = matriz[j][i];
                count++;
            }
        }
    }

    qsort(aresta,temp,sizeof(Aresta),comparaArestas);

    return aresta;
}

//Imprime a matriz de distancias na saida padrao
void imprimeMatrizDistancias(Aresta** matriz, int tamanho) {
    for(int i = 0; i < tamanho; i++)
        for(int j = 0; j < tamanho; j++)
            if(matriz[i][j].p1)
                j == tamanho - 1 ? printf("%0.2lf\n", matriz[i][j].distancia) : printf("%0.2lf\t", matriz[i][j].distancia);
            else
                j == tamanho - 1 ? printf("-\n") : printf("-\t");
}

//Imprime a matriz de distancias na saida padrao
void imprimeConjuntoArestas(Aresta* a, int tamanho) {
    for(int i = 0; i < tamanho; i++)
            printf("p1: %s, p2: %s, distancia: %0.2lf\n", a[i].p1->nome, a[i].p2->nome, a[i].distancia);
}


//Libera todas as alocações dinâmicas oriundas do criamento da matriz 'matriz'
void liberaMatrizDistancias(Aresta** matriz, int tamanho) { 
    for(int i = 0; i < tamanho; i++)
        free(matriz[i]);
    free(matriz);
}

void liberaConjunto(Aresta* c) {
    free(c);
}
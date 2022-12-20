#ifndef MATRIZ_DISTANCIAS
#define MATRIZ_DISTANCIAS

#include "../h/vetor_pontos.h"

typedef struct aresta_t {
    double distancia;
    Ponto* p1;
    Ponto* p2;
} Aresta;

//Cria uma matriz NxN de acordo com o tamanho do vetor de pontos (N) passado
//Cada posicao [i][j] da matriz contem a distancia entre os pontos i e j
Aresta** calculaDistanciasVetorPontos(VetorPontos v);

Aresta* criaConjunto(Aresta** matriz, int n);

//Imprime a matriz de distancias na saida padrao
void imprimeMatrizDistancias(Aresta** matriz, int tamanho);

void imprimeConjuntoArestas(Aresta* a, int tamanho);

//Libera todas as alocações dinâmicas oriundas do criamento da matriz 'matriz'
void liberaMatrizDistancias(Aresta** matriz, int tamanho);

void liberaConjunto(Aresta* c);

#endif
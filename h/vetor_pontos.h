#ifndef ARRAY_PONTOS_H
#define ARRAY_PONTOS_H

#include "../h/ponto.h"

typedef struct vetor_pontos_t {
    Ponto* vetor_interno;
    int tamanho_maximo;
    int tamanho;
} VetorPontos;

//Inicializa um vetor de Pontos de acordo com um arquivo de entrada
VetorPontos vetorPontosInit(FILE *fp);

//Imprime os pontos de um vetor 'v'
void imprimeVetorPontos(VetorPontos v);

//Libera a memória alocada pelo vetor de pontos 'v'
void liberaVetorPontos(VetorPontos v);

#endif
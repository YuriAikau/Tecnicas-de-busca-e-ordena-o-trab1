#ifndef PONTO_H
#define PONTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Struct Ponto que possui identificacao, dimensao e coordenadas de um ponto
typedef struct ponto_t {
    char* nome;
    int indice;
    int dimensao;
    double* coordenadas;
} Ponto;

//Imprime um ponto na saida padrao
void imprimePonto(Ponto p);

//Calcula a distancia Euclidiana entre dois pontos p1 e p2 de dimensao N
double calculaDistanciaPontos(Ponto p1, Ponto p2);

//Libera o espaco na heap ocupada por uma estrutura do tipo Ponto
void liberaPonto(Ponto p);

#endif
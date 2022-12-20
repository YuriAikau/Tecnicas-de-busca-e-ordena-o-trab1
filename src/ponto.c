#include <math.h>
#include "../h/ponto.h"

//Imprime um ponto na saida padrao
void imprimePonto(Ponto p) {
    printf("Nome: %s, Indice: %d, Coordenadas: ", p.nome, p.indice);
    
    for(int i = 0; i < p.dimensao; i++)
        i == p.dimensao - 1 ? printf("%0.2lf\n", p.coordenadas[i]) : printf("%0.2lf, ", p.coordenadas[i]);
}

//Calcula a distancia Euclidiana entre dois pontos p1 e p2 de dimensao N
double calculaDistanciaPontos(Ponto p1, Ponto p2) {
    double acumulador = 0.0;

    for(int i = 0; i < p1.dimensao; i++)
        acumulador += pow(p1.coordenadas[i] - p2.coordenadas[i], 2);
    
    return sqrt(acumulador);
}

//Libera o espaco na heap ocupada por uma estrutura do tipo Ponto
void liberaPonto(Ponto p) {
    free(p.nome);
    free(p.coordenadas);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define sum(A) ((A*A)-A)/2

#include "../h/arvore.h"

int main (int argc, char** argv) {

    clock_t start,stop;

    start = clock();

    int k = atoi(argv[2]);
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    VetorPontos vetor_pontos = vetorPontosInit(fp);
    int quantidade_pontos = vetor_pontos.tamanho;

    Aresta** matriz = calculaDistanciasVetorPontos(vetor_pontos);

    Aresta* conjunto = criaConjunto(matriz, quantidade_pontos);
    Aresta* conjunto_arestas_conectadas = malloc((quantidade_pontos - k)*sizeof(Aresta));

    No* vetor_nos = criaArvore(vetor_pontos);
    /*

    int contador = 0;
    for(int i = 0; i < sum(quantidade_pontos); i++) {
        if(UF_union(vetor_nos, conjunto[i].p1, conjunto[i].p2)) {
            conjunto_arestas_conectadas[contador] = conjunto[i];
            contador++;
        }
        if(contador >= quantidade_pontos - k)
            break;
    }
    */

    imprimeArvore(vetor_nos, quantidade_pontos);

    /*
    char* vetor_grupos[k];
    contador = 0;
    for(int i = 0; i < quantidade_pontos; i++)
        if(vetor_nos[i].ponto->indice == root(vetor_nos, vetor_nos[i].ponto)->indice) {
            vetor_grupos[contador] = strdup(vetor_nos[i].ponto->nome);
            contador++;
            if(contador == k)
                break;
        }
    
    for(int i = 0; i < k; i++)
        printf("%s\n", vetor_grupos[i]);

    contador = 0;
    for(int i = 0; i < quantidade_pontos; i++)
    */    
            

    liberaMatrizDistancias(matriz, vetor_pontos.tamanho);
    liberaVetorPontos(vetor_pontos);
    liberaConjunto(conjunto);
    liberaArvore(vetor_nos);
    free(conjunto_arestas_conectadas);
    fclose(fp);

    stop = clock();

    printf("\nTempo decorrido: %.5f\n", ((double)stop-start)/CLOCKS_PER_SEC);
    
    return 0;
}
















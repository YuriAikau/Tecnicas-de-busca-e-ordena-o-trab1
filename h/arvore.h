#ifndef ARVORE_H
#define ARVORE_H

#include "../h/aresta.h"

typedef struct no_t {
    Ponto* ponto;
    Ponto* pai;
} No;

No* criaArvore(VetorPontos vetor_pontos);

Ponto* UF_find(No* vetor_nos, Ponto* p);

int UF_union(No* vetor_nos, Ponto* p, Ponto* q);

bool UF_connected(No* vetor_nos, Ponto* p, Ponto* q);

void imprimeArvore(No* vetor_nos, int tamanho);

void liberaArvore(No* vetor_nos);

Ponto* root(No* vetor_nos, Ponto* p);

#endif //ARVORE_H
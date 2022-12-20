#include "../h/arvore.h"

No* criaArvore(VetorPontos vetor_pontos) {
    // int temp = vetor_pontos.tamanho - k - 2;
    No* vetor_nos = (No*) malloc(vetor_pontos.tamanho*sizeof(No));

    for(int i = 0; i < vetor_pontos.tamanho; i++)
        vetor_nos[i].ponto = vetor_nos[i].pai = &vetor_pontos.vetor_interno[i];

    return vetor_nos;
}

Ponto* UF_find(No* vetor_nos, Ponto* p) {
    return vetor_nos[p->indice].pai;
}

Ponto* root(No* vetor_nos, Ponto* p) {
    Ponto* temp = p;
    while(UF_find(vetor_nos, temp)->indice != temp->indice) {
        // vetor_nos[temp->indice].pai = vetor_nos[vetor_nos[temp->indice].pai->indice].pai;
        temp = UF_find(vetor_nos, temp);
    }

    return temp;
}

int UF_union(No* vetor_nos, Ponto* p, Ponto* q) {
    Ponto* i = root(vetor_nos, p);
    Ponto* j = root(vetor_nos, q);

    if(i->indice != j->indice) {
        vetor_nos[j->indice].pai = i;
        return 1;
    }

    return 0;
}

bool UF_connected(No* vetor_nos, Ponto* p, Ponto* q) {
    return root(vetor_nos, p) == root(vetor_nos, q);
}

void imprimeArvore(No* vetor_nos, int tamanho){
    for(int i = 0; i < tamanho; i++) printf("Ponto: %s \t Pai: %s, Root: %s\n", vetor_nos[i].ponto->nome, vetor_nos[i].pai->nome, root(vetor_nos, vetor_nos[i].ponto)->nome);
}

void liberaArvore(No* vetor_nos) {
    free(vetor_nos);
}
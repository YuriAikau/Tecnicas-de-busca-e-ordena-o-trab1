#include "../h/vetor_pontos.h"

//Inicializa um vetor de Pontos de acordo com um arquivo de entrada
VetorPontos vetorPontosInit(FILE *fp) {
    const size_t tamanho_maximo_inicial = 2;

    VetorPontos vetor_pontos;
    vetor_pontos.vetor_interno = (Ponto*) malloc(tamanho_maximo_inicial*sizeof(Ponto));
    vetor_pontos.tamanho_maximo = tamanho_maximo_inicial;
    vetor_pontos.tamanho = 0;

    size_t lenght = 0;
    int tamLinha = 0;
    int numVirgulas = 0;
    char *linha = NULL;
    char *token = NULL;
    int count = 0;

    while((tamLinha = getline(&linha, &lenght, fp)) != -1) {
        for(int i = 0; i < tamLinha; i++) {
            if(linha[i] == ',') {
                numVirgulas++;
            }
        }

        vetor_pontos.tamanho++;

        if(vetor_pontos.tamanho > vetor_pontos.tamanho_maximo) {
            vetor_pontos.vetor_interno = realloc(vetor_pontos.vetor_interno, 2*vetor_pontos.tamanho_maximo*sizeof(Ponto));
            vetor_pontos.tamanho_maximo *= 2;           
        }
        
        vetor_pontos.vetor_interno[vetor_pontos.tamanho - 1].coordenadas = (double*) malloc(numVirgulas * sizeof(double));
        vetor_pontos.vetor_interno[vetor_pontos.tamanho - 1].dimensao = numVirgulas;
        vetor_pontos.vetor_interno[vetor_pontos.tamanho - 1].indice = vetor_pontos.tamanho - 1;

        token = strtok(linha, ",");

        while(token){
            if(count == 0) {
                vetor_pontos.vetor_interno[vetor_pontos.tamanho - 1].nome = strdup(token);
                token = strtok(NULL, ",");
                count++;
                continue;
            }

            vetor_pontos.vetor_interno[vetor_pontos.tamanho - 1].coordenadas[count-1] = atof(token);
            token = strtok(NULL, ",");
            count++;
        }

        count = 0;
        numVirgulas = 0;
    }

    free(linha);

    return vetor_pontos;
}

//Imprime os pontos de um vetor 'v'
void imprimeVetorPontos(VetorPontos v) {
    for(int i = 0; i < v.tamanho; i++)
        imprimePonto(v.vetor_interno[i]);
}

//Libera a memória alocada pelo vetor de pontos 'v'
void liberaVetorPontos(VetorPontos v) {
    for(int i = 0; i < v.tamanho; i++)
        liberaPonto(v.vetor_interno[i]);
    
    free(v.vetor_interno);
}
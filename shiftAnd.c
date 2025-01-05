#include "shiftAnd.h"

void printBits(int num, int tamanho) {
    for(int i = tamanho - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int *criarMascara(int *padrao, int padraoTamanho) {
    int tamanhoAlfabeto = 13;
    int *mascara = (int*)malloc(tamanhoAlfabeto * sizeof(int));
    for(int i = 0; i < tamanhoAlfabeto; i++){
        mascara[i] = 0;
    }
    for(int i = 0; i < padraoTamanho; i++){
        mascara[padrao[i]] = mascara[padrao[i]] | ((1 << (padraoTamanho - 1)) >> i);
    }
    return mascara;
}

int *copiaVetor(int *vet, int tam){
    int *novo = (int*) malloc (sizeof(int) * tam);
    for(int i = 0; i < tam; i++){
        novo[i] = vet[i];
    }
    return novo;
}

void incrementarVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i]++;
        if (vetor[i] > 12) {
            vetor[i] = 1; // Ajusta para o intervalo de 1 a 12
        }
    }
}

void shiftAnd(NO *nota){
    int *original = nota->original;
    int *plagio = nota->plagio;
    int *copiaPlagio = copiaVetor(plagio, nota->plagioTamanho);

    int **mascaras = (int**) malloc(sizeof(int*) * 13);

    for(int i = 0; i < 13; i++){
        mascaras[i] = criarMascara(copiaPlagio, nota->plagioTamanho);
        incrementarVetor(copiaPlagio, nota->plagioTamanho);
    }

    free(copiaPlagio);
    
    int *r = (int*) malloc (sizeof(int) * 13);

    for(int i = 0; i < 13; i++) r[i] = 0;

/*     for(int i = 0; i < 12; i++){
        printBits(mascara[i], 12);
    } */

    for(int i = 0; i < nota->originalTamanho; i++) {
        for(int j = 0; j < 13; j++) {

            r[j] = ((r[j] >> 1) | (1 << (nota->plagioTamanho - 1))) & mascaras[j][original[i]];
            
            if((r[j] & (1 << (nota->plagioTamanho - 1))) != 0) {
                printf("S %d\n", i - nota->plagioTamanho + 1);
                for(int k = 0; k < 13; k++) {
                    free(mascaras[k]);
                }
                free(mascaras);
                free(r);
                return;
            }
        }
    }

    printf("N\n");
    for(int i = 0; i < 13; i++) {
        free(mascaras[i]);
    }
    free(mascaras);
    free(r);
}

void resolucaoShiftAnd(Fila *notas) {
    NO *aux = notas->inicio;
    while(aux != NULL) {
        shiftAnd(aux);
        aux = aux->prox;
    }
}
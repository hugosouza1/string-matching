#include "shiftAnd.h"

void printBits(unsigned long long num, int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%llu", (num >> i) & 1);
    }
    printf("\n");
}

unsigned long long *criarMascara(int *padrao, int padraoTamanho) {
    int tamanhoAlfabeto = 13;
    unsigned long long *mascara = (unsigned long long*)malloc(tamanhoAlfabeto * sizeof(unsigned long long));
    for (int i = 0; i < tamanhoAlfabeto; i++) {
        mascara[i] = 0;
    }
    for (int i = 0; i < padraoTamanho; i++) {
        mascara[padrao[i]] |= ((1ULL << (padraoTamanho - 1)) >> i);
    }
    return mascara;
}

int *copiaVetor(int *vet, int tam) {
    int *novo = (int*) malloc(sizeof(int) * tam);
    for (int i = 0; i < tam; i++) {
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

int shiftAnd(NO *nota, int *contador) {
    int *original = nota->original;
    int *plagio = nota->plagio;
    int *copiaPlagio = copiaVetor(plagio, nota->plagioTamanho);

    unsigned long long **mascaras = (unsigned long long**) malloc(sizeof(unsigned long long*) * 13);

    for (int i = 0; i < 13; i++) {
        mascaras[i] = criarMascara(copiaPlagio, nota->plagioTamanho);
        incrementarVetor(copiaPlagio, nota->plagioTamanho);
    }
    
    free(copiaPlagio);
    
    unsigned long long *r = (unsigned long long*) malloc(sizeof(unsigned long long) * 13);

    for (int i = 0; i < 13; i++) r[i] = 0;

    for (int i = 0; i < nota->originalTamanho; i++) {
        for (int j = 0; j < 13; j++) {
            (*contador)++;
            r[j] = ((r[j] >> 1) | (1ULL << (nota->plagioTamanho - 1))) & mascaras[j][original[i]];
            
            if ((r[j] & 1ULL) != 0) {
                //printf("S %d | ", i - nota->plagioTamanho + 1);
                for (int k = 0; k < 13; k++) {
                    free(mascaras[k]);
                }
                free(mascaras);
                free(r);
                return i - nota->plagioTamanho + 1;
            }
        }
    }

    //printf("N | ");
    for (int i = 0; i < 13; i++) {
        free(mascaras[i]);
    }
    free(mascaras);
    free(r);
    return -1;
}

int* resolucaoShiftAnd(Fila *notas) {
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho);
    int i = 0, contador = 0;
    while(aux != NULL){
        resultado[i] = shiftAnd(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações.\n", contador);
    return resultado;
}
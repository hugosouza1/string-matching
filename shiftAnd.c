#include "shiftAnd.h"

int *criarMascara(NO* nota) {
    int tamanhoAlfabeto = 13;
    int *mascara = (int*)malloc(tamanhoAlfabeto * sizeof(int));

    for(int i = 0; i < tamanhoAlfabeto; i++) { // Inicializa a máscara
        mascara[i] = 0;
    }
    for(int i = 0; i < nota->plagioTamanho; i++) {
        mascara[nota->plagio[i]] |= (1 << i); // Cria a máscara
    } // Cada posição do vetor máscara vai ter um bit setado para 1, representando a ocorrência de um elemento da string
    return mascara;
}

void shiftAnd(NO* nota) {
    int *original = nota->original;
    int *plagio = nota->plagio;

    int *mascara = criarMascara(nota);

    int r = 0;

    for(int i = 0; i < nota->originalTamanho; i++) {
        r = ((r >> 1) | (1 << (nota->plagioTamanho - 1))) & mascara[original[i]];
        if(r & (1 << (nota->plagioTamanho - 1)) != 0) {
            printf("Plagio encontrado na posicao %d\n", i - nota->plagioTamanho + 1);
            free(mascara);
            return;
        }
    }
    printf("Plagio nao encontrado\n");
    free(mascara);
}

void resolucaoShiftAnd(Fila *notas) {
    NO *aux = notas->inicio;
    while(aux != NULL) {
        shiftAnd(aux);
        aux = aux->prox;
    }
}
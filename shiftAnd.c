#include "shiftAnd.h"

void printBits(int num, int tamanho) {
    for(int i = tamanho - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int *criarMascara(NO *nota) {
    int tamanhoAlfabeto = 13;
    int *mascara = (int*)malloc(tamanhoAlfabeto * sizeof(int));
    for(int i = 0; i < tamanhoAlfabeto; i++){
        mascara[i] = 0;
    }
    for(int i = 0; i < nota->plagioTamanho; i++){
        mascara[nota->plagio[i]] = mascara[nota->plagio[i]] | ((1 << (nota->plagioTamanho - 1)) >> i);
    }
    return mascara;
}

void shiftAnd(NO *nota){
    int *original = nota->original;
    int *plagio = nota->plagio;
    int *mascara = criarMascara(nota);
    
    int *r = (int*)malloc(12 * sizeof(int));
    for(int i = 0; i < 12; i++)  r[i] = 0;

    for(int i = 0, j = 0; i < nota->originalTamanho; i++, j++){

        for(int k = 0; k < 12; k++){
            int h = i + k;
            h = h < 12 ? h : h - 12;
            r[k] = ((r[k] >> 1) | (1 << (nota->plagioTamanho - 1))) & mascara[original[i]];
        }
        
        //print nao sei oq 
        //   printf("i: %d, original[i]: %d, r: ", diferenca, original[diferenca]);printBits(r, nota->plagioTamanho);printf("mascara[original[i]]: ");printBits(mascara[original[diferenca]], nota->plagioTamanho);printf("\n");

        for(int k = 0; k < 12; k++){
            if((r[k] & 1) != 0){
                printf("S %d\n", i - nota->plagioTamanho + 1);
                free(mascara);
                return;
            }
        }
    }
    printf("N\n");
    free(mascara);
}

void resolucaoShiftAnd(Fila *notas) {
    NO *aux = notas->inicio;
    while(aux != NULL) {
        shiftAnd(aux);
        aux = aux->prox;
    }
}
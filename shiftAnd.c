#include "shiftAnd.h"

void printBits(int num, int tamanho) {
    for(int i = tamanho - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int tomShift(int valor, int tom) {
    valor += tom;
    if(valor > 12) {
        valor -= 12;
    }
    return valor;
}

int *criarMascara(NO *nota) {
    int tamanhoAlfabeto = 12;
    int *mascara = (int*)malloc(tamanhoAlfabeto * sizeof(int));
    for(int i = 0; i < tamanhoAlfabeto; i++){
        mascara[i] = 0;
    }
    for(int i = 0; i < nota->plagioTamanho; i++){
        mascara[nota->plagio[i]-1] = mascara[nota->plagio[i]-1] | ((1 << (nota->plagioTamanho - 1)) >> i);
    }
    return mascara;
}

void shiftAnd(NO *nota){
    int *original = nota->original;
    int *plagio = nota->plagio;
    int *mascara = criarMascara(nota);

    int r = 0;
    int tom = tons(original[0], plagio[0]), k = 0;
    
    for(int i = 0; i < nota->originalTamanho; i++){
        if(tomShift(original[i], tom) != plagio[k]) {
            if(r != 0 && i > 0) {
                if(original[i] == original[i-1]) {
                    int prefixoValido = 1;
                    for(int j = 0; j < k-1; j++) {
                        if(plagio[j] != plagio[j+1]) prefixoValido = 0;
                    }
                    if(prefixoValido) continue;
                }
            }
            k = r = 0;
            tom = tons(original[i], plagio[k]);
        }
        r = ((r >> 1) | (1 << (nota->plagioTamanho - 1))) & mascara[tomShift(original[i], tom)-1];

        if((r & 1) == 1){
            printf("S %d\n", i - nota->plagioTamanho + 1);
            free(mascara);
            return;
        }
        k++;
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
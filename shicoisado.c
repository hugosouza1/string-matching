#include "shiftAnd.h"


// Função para criar a máscara de bits
long long int *criarMascara(NO *nota) {
    int tamanhoAlfabeto = 12;
    long long int *mascara = (long long int*)malloc(tamanhoAlfabeto * sizeof(long long int));
    for (int i = 0; i < tamanhoAlfabeto; i++) {
        mascara[i] = 0;
    }
    for (int i = 0; i < nota->plagioTamanho; i++) {
        mascara[nota->plagio[i] - 1] |= (1LL << (nota->plagioTamanho - 1 - i));
    }
    return mascara;
}

// Função Shift-And adaptada para buscar padrões transpostos em tons
int shiftAnd(NO *nota, int *contador) {
    int *original = nota->original;
    int *plagio = nota->plagio;
    long long int *mascara = criarMascara(nota);

    unsigned long long r = 0;
    int tom = tons(original[0], plagio[0]), k = 0;

    for (int i = 0; i < nota->originalTamanho; i++) {
        if (tomShift(original[i], tom) != plagio[k]) {
            if (r != 0 && i > 0) {
                if (original[i] == original[i - 1] && tomShift(original[i], tom) == plagio[0]) continue;
            }
            k = r = 0;
            tom = tons(original[i], plagio[k]);
        }
        (*contador)++;
        r = ((r >> 1) | (1LL << (nota->plagioTamanho - 1))) & mascara[tomShift(original[i], tom) - 1];

        if ((r & 1) == 1) {
            //printf("S %d | ", i - nota->plagioTamanho + 1);
            free(mascara);
            return i - nota->plagioTamanho + 1;
        }
        k++;
    }
    //printf("N | ");
    free(mascara);
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

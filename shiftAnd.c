#include "shiftAnd.h"

void printBits(int *num, int particoes) {
    for(int i = 0; i < particoes; i++) {
        for(int j = 31; j >= 0; j--) { // Imprime do MSB para LSB
            printf("%d", (num[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}


// Função para criar a máscara de bits
int **criarMascara(NO *nota) {
    int tamanhoAlfabeto = 12;
    int **mascara = (int**)malloc(tamanhoAlfabeto * sizeof(int*));
    int particoes = (nota->plagioTamanho + 31) / 32; // Arredondar para cima
    
    for (int i = 0; i < tamanhoAlfabeto; i++) {
        mascara[i] = (int*)calloc(particoes, sizeof(int)); // Inicializa com 0
    }
   
    for (int i = 0; i < nota->plagioTamanho; i++) {
        int global_pos = nota->plagioTamanho - i - 1; // Posição global inversa
        int part = global_pos / 32;
        int bit = global_pos % 32;
        mascara[nota->plagio[i] - 1][part] |= (1 << bit);
    }
    return mascara;
}

void destroiMascara(int **mascara, NO *nota) {
    int particoes = (nota->plagioTamanho + 31) / 32;
    for(int i = 0; i < 12; i++) {
        free(mascara[i]);
    }
    free(mascara);
}

// Função Shift-And adaptada para buscar padrões transpostos em tons
int shiftAnd(NO *nota, int *contador) {
    int *original = nota->original;
    int *plagio = nota->plagio;
    int **mascaras = criarMascara(nota);
    int particoes = (nota->plagioTamanho + 31) / 32;
    
    printf("PARTICOES - TAMANHO: %d - %d\n", particoes, nota->plagioTamanho);
    for(int i = 0; i < 12; i++) {
        printBits(mascaras[i], particoes);
    }
    
    int *r = (int*)malloc(particoes * sizeof(int));
    for(int i = 0; i < particoes; i++) r[i] = 0;
    int tom = tons(original[0], plagio[0]), k = 0;
    printf("%d\n", nota->originalTamanho);

    for (int i = 0; i < nota->originalTamanho; i++) {
        if (tomShift(original[i], tom) != plagio[k]) {
            if (r != 0 && i > 0) {
                if (original[i] == original[i - 1] && tomShift(original[i], tom) == plagio[0]) continue;
            }
            k = 0;
            for(int j = 0; j < particoes; j++) r[j] = 0;
            tom = tons(original[i], plagio[k]);
        }
        (*contador)++;

        // & mascaras[tomShift(original[i], tom) - 1][j]
        int shift = 1;
        for(int j = 0; j < particoes; j++) {
            if(shift == 1){
                shift = r[j] & 1;
                if(j == 0){
                    r[j] = (r[j] >> 1) | (1 << ((nota->plagioTamanho % 32) - 1));
                } else {
                    r[j] = (r[j] >> 1) | (1 << 31);
                }

            } else {
                shift = r[j] & 1;
                r[j] = r[j] >> 1;
            }
            
        }

        for(int j = 0, jj = particoes -1; j < particoes; j++, jj--){
            r[j] &= mascaras[tomShift(original[i], tom) - 1][jj];    
        }

        printBits(r, particoes);




        if ((r[particoes-1] & 1) != 0) { // condição de sucesso
            //printf("S %d | ", i - nota->plagioTamanho + 1);
            destroiMascara(mascaras, nota);
            return i - nota->plagioTamanho + 1;
        }
        k++;
    }

    //printf("N | ");
    destroiMascara(mascaras, nota);
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

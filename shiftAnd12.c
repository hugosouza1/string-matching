#include "shiftAnd.h"

void printBits(int num, int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int *criarMascara(int *padrao, int padraoTamanho) {
    int tamanhoAlfabeto = 13;
    int *mascara = (int*)malloc(tamanhoAlfabeto * sizeof(int));
    for (int i = 0; i < tamanhoAlfabeto; i++) {
        mascara[i] = 0;
    }
    for (int i = 0; i < padraoTamanho; i++) {
        mascara[padrao[i]] |= ((1 << (padraoTamanho - 1)) >> i);
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
    int *plagio = copiaVetor(nota->plagio, nota->plagioTamanho);
    int *copiaPlagio = copiaVetor(plagio, nota->plagioTamanho);

    int *mascaras = (int*) malloc(sizeof(int) * 13);

    
    int *r = (int*) malloc(sizeof(int) * 13);


    for (int i = 0; i < 13; i++) r[i] = 0;

    
    for(int j = 0; j < 12; j++){
        mascaras = criarMascara(plagio, nota->plagioTamanho);

        for (int i = 0; i < nota->originalTamanho; i++) {
                (*contador)++;
                r = ((r >> 1) | (1 << (nota->plagioTamanho - 1))) & mascaras[original[i]];
                
                if ((r[j] & 1) == 1) {
                    //printf("S %d | ", i - nota->plagioTamanho + 1);

                    free(mascaras);
                    free(r);
                    return i - nota->plagioTamanho + 1;
                }
            }

        incrementarVetor(plagio, nota->plagioTamanho);
    }

    //printf("N | ");

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


// #include "shiftAnd.h"

// void printBits(int *num, int particoes) {
//     for(int i = 0; i < particoes; i++) {
//         for(int j = 31; j >= 0; j--) { // Imprime do MSB para LSB
//             printf("%d", (num[i] >> j) & 1);
//         }
//         printf(" ");
//     }
//     printf("\n");
// }


// // Função para criar a máscara de bits
// int **criarMascara(NO *nota) {
//     int tamanhoAlfabeto = 12;
//     int **mascara = (int**)malloc(tamanhoAlfabeto * sizeof(int*));
//     int particoes = (nota->plagioTamanho + 31) / 32; // Arredondar para cima
    
//     for (int i = 0; i < tamanhoAlfabeto; i++) {
//         mascara[i] = (int*)calloc(particoes, sizeof(int)); // Inicializa com 0
//     }
   
//     for (int i = 0; i < nota->plagioTamanho; i++) {
//         int global_pos = nota->plagioTamanho - i - 1; // Posição global inversa
//         int part = global_pos / 32;
//         int bit = global_pos % 32;
//         mascara[nota->plagio[i] - 1][part] |= (1 << bit);
//     }
//     return mascara;
// }

// void destroiMascara(int **mascara, NO *nota) {
//     int particoes = (nota->plagioTamanho + 31) / 32;
//     for(int i = 0; i < 12; i++) {
//         free(mascara[i]);
//     }
//     free(mascara);
// }

// // Função Shift-And adaptada para buscar padrões transpostos em tons
// int shiftAnd(NO *nota, int *contador) {
//     int *original = nota->original;
//     int *plagio = nota->plagio;
//     int particoes = (nota->plagioTamanho + 31) / 32;

//     int ***mascaras = (int***)malloc(12 * sizeof(int**));
//     for(int i = 0; i < 12; i++) {
//         sobeTom(nota, i);
//         mascaras[i] = criarMascara(nota); 
//     }
    
//     printf("PARTICOES - TAMANHO: %d - %d\n", particoes, nota->plagioTamanho);
//     for(int i = 0; i < 12; i++) {
//         printBits(mascaras[i], particoes);
//     }
    
//     int *r = (int*)malloc(particoes * sizeof(int));
//     int tom = tons(original[0], plagio[0]), k = 0;
//     printf("%d\n", nota->originalTamanho);

//     for(int g = 0; g < 12; g++){
//         for(int i = 0; i < particoes; i++) r[i] = 0;

//         for (int i = 0; i < nota->originalTamanho; i++) {
//             if (tomShift(original[i], tom) != plagio[k]) {
//                 if (r != 0 && i > 0) {
//                     if (original[i] == original[i - 1] && tomShift(original[i], tom) == plagio[0]) continue;
//                 }
//                 k = 0;
//                 for(int j = 0; j < particoes; j++) r[j] = 0;
//                 tom = tons(original[i], plagio[k]);
//             }
//             (*contador)++;

//             // & mascaras[tomShift(original[i], tom) - 1][j]
//             for(int j = 0; j < particoes; j++) {
//                 if (j == 0) {
//                     // Primeira partição: desloca e insere bit no topo
//                     r[j] = (r[j] >> 1) | (1 << 31) ;
//                 } else {
//                     // Verifica se há bit de transporte da partição anterior
//                     if((r[j - 1] & 1) == 1) {
//                         r[j] = (r[j] >> 1) | (1 << 31);
//                     } else {
//                         r[j] = (r[j] >> 1);
//                     }
//                 }
//             }

//             printBits(r, particoes);
//             for(int j = 0; j < particoes; j++){
//                 int **mascAux  = mascaras[g];
//                 r[j] &= mascAux[tomShift(original[i], tom) - 1][j];
                
//             }




//             if ((r[particoes-1] & (1 <<( nota->plagioTamanho -1) % 32)) != 0) { // condição de sucesso
//                 //printf("S %d | ", i - nota->plagioTamanho + 1);
//                 destroiMascara(mascaras, nota);
//                 return i - nota->plagioTamanho + 1;
//             }
//             k++;
//         }
//     }

//     //printf("N | ");
//     destroiMascara(mascaras, nota);
//     return -1;
// }

// int* resolucaoShiftAnd(Fila *notas) {
//     NO *aux = notas->inicio;
//     int *resultado = (int*)malloc(sizeof(int) * notas->tamanho);
//     int i = 0, contador = 0;
//     while(aux != NULL){
//         resultado[i] = shiftAnd(aux, &contador);
//         aux = aux->prox; i++;
//     }
//     printf("Foram feitas %d comparações.\n", contador);
//     return resultado;
// }

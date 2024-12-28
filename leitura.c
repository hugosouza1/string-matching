#include "leitura.h"

int *converterOriginal(double *original, int originalTam){
    int *originalConvertida = (int*)malloc(originalTam * sizeof(int));
    for(int i = 0; i < originalTam; i++){
        if(original[i] == 64.5)      originalConvertida[i] = 12;
        else if(original[i] == 65)   originalConvertida[i] = 1; // A
        else if(original[i] == 65.5) originalConvertida[i] = 2; // A#
        else if(original[i] == 66)   originalConvertida[i] = 3; // B
        else if(original[i] == 67)   originalConvertida[i] = 4; // C
        else if(original[i] == 67.5) originalConvertida[i] = 5; //C#
        else if(original[i] == 68)   originalConvertida[i] = 6; // D
        else if(original[i] == 68.5) originalConvertida[i] = 7; //D#
        else if(original[i] == 69)   originalConvertida[i] = 8; // E
        else if(original[i] == 70)   originalConvertida[i] = 9; // F
        else if(original[i] == 70.5) originalConvertida[i] = 10; // F#
        else if(original[i] == 71)   originalConvertida[i] = 11; // G
        else if(original[i] == 71.5) originalConvertida[i] = 12; // G#
    }
    return originalConvertida;
}

int *converterCopia(double *copia, int copiaTam){
    int *copiaConvertida = (int*)malloc(copiaTam * sizeof(int));
    for(int i = 0; i < copiaTam; i++){
        if(copia[i] == 64.5)      copiaConvertida[i] = 12;
        else if(copia[i] == 65)   copiaConvertida[i] = 1; // A
        else if(copia[i] == 65.5) copiaConvertida[i] = 2; // A#
        else if(copia[i] == 66)   copiaConvertida[i] = 3; // B
        else if(copia[i] == 67)   copiaConvertida[i] = 4; // C
        else if(copia[i] == 67.5) copiaConvertida[i] = 5; //C#
        else if(copia[i] == 68)   copiaConvertida[i] = 6; // D
        else if(copia[i] == 68.5) copiaConvertida[i] = 7; //D#
        else if(copia[i] == 69)   copiaConvertida[i] = 8; // E
        else if(copia[i] == 70)   copiaConvertida[i] = 9; // F
        else if(copia[i] == 70.5) copiaConvertida[i] = 10; // F#
        else if(copia[i] == 71)   copiaConvertida[i] = 11; // G
        else if(copia[i] == 71.5) copiaConvertida[i] = 12; // G#
    }
    return copiaConvertida;
}

Fila * leitura(char *path){
    FILE  *arq = fopen(path, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    Fila *fila = criaFila();

    while(1){
        int originalTam = 0, copiaTam = 0;
        int tamMax = 0;

        char *numero = (char*)malloc(500 * sizeof(char));
        fgets(numero, 500, arq);
        sscanf(numero, "%d %d", &originalTam, &copiaTam);
        free(numero);

        //printf("teste %d %d\n", originalTam, copiaTam);
        if(originalTam == 0 && copiaTam == 0){
            break;
        } 

        //--------------------------------------------------//

        double *original = (double*)malloc(originalTam * sizeof(double));
        double *copia = (double*)malloc(copiaTam * sizeof(double));
        tamMax = originalTam * 5;

        char *linha = (char*)malloc(tamMax * sizeof(char)); // Tamanho da linha ao quadrado + 1 para o terminador nulo
        fgets(linha, tamMax, arq); // Ler a linha inteira

        char *token = strtok(linha, " ");
        for(int i = 0; token != NULL && i < originalTam; i++) {
            if(token[1] == '#'){
                double temp = token[0] ;
                original[i] = temp + 0.5;
            } else if(token[1] == 'b'){
                double temp = token[0] ;
                original[i] = temp - 0.5;
            } else {
                original[i] = token[0];
            }
            token = strtok(NULL, " ");
        }

        fgets(linha, tamMax, arq); // Ler a linha inteira

        char *token2 = strtok(linha, " ");
        for(int i = 0; token2 != NULL && i < copiaTam; i++) {
            if(token2[1] == '#'){
                double temp = token2[0] ;
                copia[i] = temp + 0.5;
            } else if(token2[1] == 'b'){
                double temp = token2[0] ;
                copia[i] = temp - 0.5;
            } else {
                copia[i] = token2[0];
            }
            token2 = strtok(NULL, " ");
        }
        
        int *originalConvertida = converterOriginal(original, originalTam);
        int *copiaConvertida = converterCopia(copia, copiaTam);
        free(original); free(copia);
        enfileirar(fila, originalConvertida, copiaConvertida, originalTam, copiaTam);
        free(linha);
    }

    fclose(arq);
    return fila;
}
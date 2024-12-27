#include "leitura.h"

void converter(double *original, double *copia, int originalTam, int copiaTam){
    for(int i = 0; i < originalTam; i++){
        if(original[i] == 64.5) original[i] = 12;
        else if(original[i] == 65) original[i] = 1; // A
        else if(original[i] == 65.5) original[i] = 2; // A#
        else if(original[i] == 66) original[i] = 3; // B
        else if(original[i] == 67) original[i] = 4; // C
        else if(original[i] == 67.5) original[i] = 5; //C#
        else if(original[i] == 68) original[i] = 6; // D
        else if(original[i] == 68.5) original[i] = 7; //D#
        else if(original[i] == 69) original[i] = 8; // E
        else if(original[i] == 70) original[i] = 9; // F
        else if(original[i] == 70.5) original[i] = 10; // F#
        else if(original[i] == 71) original[i] = 11; // G
        else if(original[i] == 71.5) original[i] = 12; // G#
    }

    for(int i = 0; i < copiaTam; i++){
        if(copia[i] == 64.5) copia[i] = 12;
        else if(copia[i] == 65) copia[i] = 1; // A
        else if(copia[i] == 65.5) copia[i] = 2; // A#
        else if(copia[i] == 66) copia[i] = 3; // B
        else if(copia[i] == 67) copia[i] = 4; // C
        else if(copia[i] == 67.5) copia[i] = 5; //C#
        else if(copia[i] == 68) copia[i] = 6; // D
        else if(copia[i] == 68.5) copia[i] = 7; //D#
        else if(copia[i] == 69) copia[i] = 8; // E
        else if(copia[i] == 70) copia[i] = 9; // F
        else if(copia[i] == 70.5) copia[i] = 10; // F#
        else if(copia[i] == 71) copia[i] = 11; // G
        else if(copia[i] == 71.5) copia[i] = 12; // G#
    }
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
        
        converter(original, copia, originalTam, copiaTam);
        enfileirar(fila, original, copia, originalTam, copiaTam);
        free(linha);
    }

    fclose(arq);
    return fila;
}
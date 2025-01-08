#include "leitura.h"

int *identificaTecla(double *melodia, int melodiaTamanho){
    int *teclas = (int*)malloc(melodiaTamanho * sizeof(int));
    for(int i = 0; i < melodiaTamanho; i++){
        if(melodia[i] == 64.8)                             teclas[i] = 12; //Ab
        else if(melodia[i] == 65)                          teclas[i] = 1; // A
        else if(melodia[i] == 65.2 || melodia[i] == 65.8)  teclas[i] = 2; // A#
        else if(melodia[i] == 66   || melodia[i] == 66.8)  teclas[i] = 3; // B
        else if(melodia[i] == 67   || melodia[i] == 66.2)  teclas[i] = 4; // C
        else if(melodia[i] == 67.2 || melodia[i] == 67.8)  teclas[i] = 5; //C#
        else if(melodia[i] == 68)                          teclas[i] = 6; // D
        else if(melodia[i] == 68.2 || melodia[i] == 68.8)  teclas[i] = 7; //D#
        else if(melodia[i] == 69   || melodia[i] == 69.8)  teclas[i] = 8; // E
        else if(melodia[i] == 70   || melodia[i] == 69.2)  teclas[i] = 9; // F
        else if(melodia[i] == 70.2 || melodia[i] == 70.8 ) teclas[i] = 10; // F#
        else if(melodia[i] == 71)                          teclas[i] = 11; // G
        else if(melodia[i] == 71.2)                        teclas[i] = 12; // G#
    }
    return teclas;
}

int *converteMelodia(char *linha, double *array, int arrayTamanho) {
    char *token = strtok(linha, " ");
    for(int i = 0; token != NULL && i < arrayTamanho; i++) {
        if(token[1] == '#'){
            double temp = token[0] ;
            array[i] = temp + 0.2;
        } else if(token[1] == 'b'){
            double temp = token[0] ;
            array[i] = temp - 0.2;
        } else {
            array[i] = token[0];
        }
        token = strtok(NULL, " ");
    }
    return identificaTecla(array, arrayTamanho);
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

        tamMax = originalTam * 5;
        char *linha = (char*)malloc(tamMax * sizeof(char)); // Tamanho da linha ao quadrado + 1 para o terminador nulo
        double *original = (double*)malloc(originalTam * sizeof(double));
        double *copia = (double*)malloc(copiaTam * sizeof(double));

        fgets(linha, tamMax, arq); // Ler a linha inteira
        int *originalConvertida = converteMelodia(linha, original, originalTam);

        fgets(linha, tamMax, arq); // Ler a linha inteira
        int *copiaConvertida = converteMelodia(linha, copia, copiaTam);

        enfileirar(fila, originalConvertida, copiaConvertida, originalTam, copiaTam);
        free(linha); free(original); free(copia);
    }

    fclose(arq);
    return fila;
}
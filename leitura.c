#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila * leitura(char *path){
    FILE  *arq = fopen(path, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    Fila *fila = criaFila();

    while( 1 ){
        int originalTam = 1, copiaTam = 1;
        fscanf(arq, "%d %d", &originalTam, &copiaTam);
        if(originalTam == 0 && copiaTam == 0) break;

        //--------------------------------------------------//

        int *original = (int*)malloc(originalTam * sizeof(int));

        char *linha = (char*)malloc(originalTam * sizeof(char));
        fgets(linha, originalTam , arq);

        char *token = strtok(linha, " ");
        for(int i = 0; token != NULL; i++) {
            if(token[1] == '#'){
                original[i] = linha[0] + 10;
            } else {
                original[i] = linha[0] - 10;
            }
            token = strtok(NULL, " ");
        }

        int *copia = (int*)malloc(copiaTam * sizeof(int));
        
        //--------------------------------------------------//

        fgets(linha, copiaTam , arq);

        char *token2 = strtok(linha, " ");
        for(int i = 0; token2 != NULL; i++) {
            if(token2[1] == '#'){
                copia[i] = linha[0] + 10;
            } else {
                copia[i] = linha[0] - 10;
            }
            token2 = strtok(NULL, " ");
        }

        enfileirar(fila, original, copia, originalTam, copiaTam);
        free(linha);
    }

    fclose(arq);
    return fila;
}
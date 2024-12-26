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

    while(1){
        int originalTam = 0, copiaTam = 0;

        char *numero = (char*)malloc(200 * sizeof(char));
        fgets(numero, 200, arq);
        sscanf(numero, "%d %d", &originalTam, &copiaTam);
        free(numero);

        printf("teste %d %d\n", originalTam, copiaTam);
        if(originalTam == 0 && copiaTam == 0) break;

        //--------------------------------------------------//

        int *original = (int*)malloc(originalTam * sizeof(int));
        int *copia = (int*)malloc(copiaTam * sizeof(int));

        char *linha = (char*)malloc((originalTam * originalTam + 1) * sizeof(char)); // Tamanho da linha ao quadrado + 1 para o terminador nulo
        fgets(linha, originalTam * originalTam + 1, arq); // Ler a linha inteira

        char *token = strtok(linha, " ");
        for(int i = 0; token != NULL && i < originalTam; i++) {
            if(token[1] == '#'){
                original[i] = token[0] + 10;
            } else if(token[1] == 'b'){
                original[i] = token[0] - 10;
            } 
            original[i] = token[0];
            
            token = strtok(NULL, " ");
        }

        free(linha);
        linha = (char*)malloc((copiaTam * copiaTam + 1) * sizeof(char)); // Tamanho da linha ao quadrado + 1 para o terminador nulo
        fgets(linha, copiaTam * copiaTam + 1, arq); // Ler a linha inteira

        char *token2 = strtok(linha, " ");
        for(int i = 0; token2 != NULL && i < copiaTam; i++) {
            if(token2[1] == '#'){
                copia[i] = token2[0] + 10;
            } else if(token2[1] == 'b'){
                copia[i] = token2[0] - 10;
            }
            copia[i] = token2[0];
            token2 = strtok(NULL, " ");
        }

        enfileirar(fila, original, copia, originalTam, copiaTam);
        free(linha);
    }

    fclose(arq);
    return fila;
}
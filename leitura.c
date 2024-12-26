#include "leitura.h"

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

        enfileirar(fila, original, copia, originalTam, copiaTam);
        free(linha);
    }

    fclose(arq);
    return fila;
}
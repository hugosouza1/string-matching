#include "saida.h"

void escrita(int *metodo, char* nomeMetodo, int tamanho) {

    FILE *arquivo = fopen("tp3.out", "w"); // Abre o arquivo para escrita ("w" - write)
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivo, "%s\n", nomeMetodo);

    for(int i = 0; i < tamanho; i++) {
        if(metodo[i] == -1) {
            fprintf(arquivo, "N\n");
        } else {
            fprintf(arquivo, "S %d\n", metodo[i]);
        }
    }

    fclose(arquivo); // Fecha o arquivo
}
#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "tons.h"

void BMH(NO *nota){
    int *tabela = (int*)malloc(12 * sizeof(int));
    for(int i = 0; i < 12; i++) tabela[i] = nota->plagioTamanho;
    for(int j = 1; j < nota->plagioTamanho; j++) {
        if(tabela[nota->plagio[j] - 1] == nota->plagioTamanho) tabela[nota->plagio[j] - 1] = j;
    }
    for(int i = 0; i < 12; i++) printf("%d ", tabela[i]);
    printf("\n");
}

void resolucaoBMH(Fila *notas) {
    NO *aux = notas->inicio;
    while(aux != NULL) {
        BMH(aux);
        aux = aux->prox;
    }
}
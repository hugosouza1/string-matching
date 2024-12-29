#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "tons.h"

int *criaTabela(NO *nota) {
    int *tabela = (int*)malloc(12 * sizeof(int));
    for(int i = 0; i < 12; i++) tabela[i] = nota->plagioTamanho;
    for(int j = 1; j < nota->plagioTamanho; j++) {
        int tecla = nota->plagio[nota->plagioTamanho-1 - j];
        if(tabela[tecla-1] > j) tabela[tecla-1] = j ;
    }
    //for(int i = 0; i < 12; i++) printf("%d ", tabela[i]);
    //printf("\n");
    
    return tabela;
}

void BMH(NO *nota){
    int *tabela = criaTabela(nota);
    int i = 0, j = 0 + nota->plagioTamanho-1;
    int plagio = 0;
    
    while(i + nota->plagioTamanho-1 < nota->originalTamanho) {
        j = i + nota->plagioTamanho-1;
        int k = nota->plagioTamanho-1;
        while((nota->original[j] == nota->plagio[k]) && (j > 0)) {
            j--; k--;
        }
        if(k <= 0) {
            printf("S %d\n", i);
            return;
        } else {
            i = i + tabela[nota->original[j]-1];
        }
    }
    printf("N\n");
    
}

void resolucaoBMH(Fila *notas) {
    NO *aux = notas->inicio;
    while(aux != NULL) {
        BMH(aux);
        aux = aux->prox;
    }
}
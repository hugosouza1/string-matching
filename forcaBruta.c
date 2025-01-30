#include "forcaBruta.h"


int forcaBruta(NO *nota, int *contador){
    int *original = nota->original;
    int *plagio = nota->plagio;

    for(int i = 0; i < nota->originalTamanho; i++){

        for(int j = i, k = 0; j < nota->originalTamanho; j++, k++){
            (*contador)++;
            if(tons(original[j], plagio[k]) != tons(original[i], plagio[0])){
                //printf("%d-", i);
                break;
            }
            if(k == nota->plagioTamanho - 1){
                //printf("S %d | ", i);
                return i;
            }
            if(j == nota->originalTamanho - 1){
                //printf("N | ");
                return -1;
            }
        }
    }
}


int* resolucaoForcaBruta(Fila *notas){
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho);
    int i = 0, contador = 0;
    while(aux != NULL){
        resultado[i] = forcaBruta(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações.\n", contador);
    return resultado;
}
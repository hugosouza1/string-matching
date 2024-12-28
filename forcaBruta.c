#include "forcaBruta.h"


void forcaBruta(NO *nota){
    double *original = nota->original;
    double *plagio = nota->plagio;

    for(int i = 0; i < nota->originalTamanho; i++){

        for(int j = i, k = 0; j < nota->originalTamanho; j++, k++){
            if(tons(original[j], plagio[k]) != tons(original[i], plagio[0])){
                //printf("%d-", i);
                break;
            }
            if(k == nota->plagioTamanho - 1){
                printf("S %d\n", i);
                return;
            }
            if(j == nota->originalTamanho - 1){
                printf("N \n");
                return;
            }
        }
    }
}


void resolucaoForcaBruta(Fila *notas){
    NO *aux = notas->inicio;
    while(aux != NULL){
        forcaBruta(aux);
        aux = aux->prox;
    }
        
}
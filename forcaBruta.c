#include "forcaBruta.h"

int tons(double primeiro, double segundo){
    int diferenca = segundo - primeiro;
    if(diferenca < 0){
        diferenca = 12 + diferenca;
    }
    return diferenca;
}

void forcaBruta(NO *nota){
    double *original = nota->original;
    double *plagio = nota->plagio;

    for(int i = 0; i < nota->originalTamanho; i++){

        for(int j = i, k = 0; j < nota->originalTamanho; j++, k++){
            if(tons(original[j], plagio[k]) != tons(original[i], plagio[0])){
                break;
            }
            if(j == nota->originalTamanho - 1 && k == nota->plagioTamanho - 1){
                printf("Caso: %d\n", i);
                return;
            }
        }
    }
     

    printf("Caso %d: Nao ha correspondencia\n", nota->originalTamanho);
}


void resolucaoForcaBruta(Fila *notas){
    NO *aux = notas->inicio;
    while(aux != NULL){
        forcaBruta(aux);
        aux = aux->prox;
        
    }
        
}
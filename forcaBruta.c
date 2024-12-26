#include "forcaBruta.h"

void forcaBruta(NO *nota){
    double *original = nota->original;
    double *plagio = nota->plagio;
    for(int i = 0; i < nota->originalTamanho; i++){
        for(int j = 0; j < nota->plagioTamanho ; j++){
            int tom = fabs(original[i] - plagio[j]);
            int quantidade = 0;
            int local = i+i;
            for(int k = i+1; k < nota->originalTamanho; k++){
                for(int l = 0; l < nota->plagioTamanho; l++){
                    if(((plagio[l] - original[k] + tom) == 0)){
                        quantidade++;                        
                    }
                }
            }
            if(quantidade == nota->plagioTamanho){
                printf("local: %d = %d\n", local, quantidade);
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
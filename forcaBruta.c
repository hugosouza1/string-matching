#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void forcaBruta(NO *nota){
    int *original = nota->original;
    int *plagio = nota->plagio;

}



void resolucaoForcaBruta(Fila *notas){
    NO *aux = notas->inicio;
    while(aux != NULL){
        forcaBruta(aux);
        aux = aux->prox;
        
    }
        
}
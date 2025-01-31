#include "tons.h"

int tons(int primeiro, int segundo){
    int diferenca = segundo - primeiro;
    if(diferenca < 0){
        diferenca = 12 + diferenca;
    }
    return diferenca;
}

int tomShift(int nota, int tom) {
    nota += tom;
    if(nota > 12) {
        nota -= 12;
    }
    return nota;
}

void sobeTom(NO *nota, int tom){
    while(nota != NULL){
        for(int i = 0; i < nota->plagioTamanho; i++){
            nota->plagio[i] += tom;
            if(nota->plagio[i] > 12){
                nota->plagio[i] = nota->plagio[i] - 12;
            }
        }
        nota = nota->prox;
    }
}
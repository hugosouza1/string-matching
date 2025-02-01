#include "tons.h"

// Verifica a diferença entre duas notas
int tons(int primeiro, int segundo){
    int diferenca = segundo - primeiro;
    if(diferenca < 0){
        diferenca = 12 + diferenca;
    }
    return diferenca;
}

// Eleva o valor de uma nota 
int tomShift(int nota, int tom) {
    nota += tom;
    if(nota > 12) {
        nota -= 12;
    }
    return nota;
}
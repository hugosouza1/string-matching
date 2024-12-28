#include "tons.h"

int tons(double primeiro, double segundo){
    int diferenca = segundo - primeiro;
    if(diferenca < 0){
        diferenca = 12 + diferenca;
    }
    return diferenca;
}

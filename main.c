#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "leitura.h"
#include "KMP.h"
#include "forcaBruta.h"
#include "./BMH.h"

double tempoDecorridoCPU = 0;

int main(int *arg, char *argv[]){

    Fila *fila = leitura(argv[1]);
    imprimirFila(fila);
    
    resolucaoForcaBruta(fila);
    printf("\n");
    resolucaoKMP(fila);
    resolucaoBMH(fila);

    destroiFila(fila);
    
    
    
    return 0;
}
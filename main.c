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
    //imprimirFila(fila);
    int x = atoi(argv[2]);
    switch(x){
        case 1:
            resolucaoForcaBruta(fila);
            break;
        case 2:
            resolucaoKMP(fila);
            break;
        case 3:
            resolucaoBMH(fila);
            break;
        case 4:
            //resolucaoShiftAnd(fila);
            break;
        case 5:
            resolucaoForcaBruta(fila);
            printf("\n");
            resolucaoKMP(fila);
            printf("\n");
            resolucaoBMH(fila);
            //printf("\n");
            //resolucaoShiftAnd(fila);
            break;
    }

    destroiFila(fila);
    
    
    
    return 0;
}
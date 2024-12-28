#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "leitura.h"
#include "forcaBruta.h"

double tempoDecorridoCPU = 0;

int main(int *arg, char *argv[]){

    Fila *fila = leitura(argv[1]);
    imprimirFila(fila);
    resolucaoForcaBruta(fila);
    destroiFila(fila);

    
    return 0;
}
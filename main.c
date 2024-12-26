#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "leitura.h"
#include "forcaBruta.h"

int main(int *arg, char *argv[]){

    Fila *fila = leitura(argv[1]);
    imprimirFila(fila);
    resolucaoForcaBruta(fila);
    destroiFila(fila);

    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "leitura.h"

int main(int *arg, char *argv[]){
    Fila *fila = leitura(argv[1]);
    imprimirFila(fila);
    destroiFila(fila);
    return 0;
}
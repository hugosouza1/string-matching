#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "leitura.h"
#include "forcaBruta.h"
#include "KMP.h"
#include "./BMH.h"
#include "./shiftAnd.h"
#include "saida.h"
#include "cronometro.h"

double tempoDecorridoCPU = 0;

int geraArquivo();

int main(int *arg, char *argv[]){

    struct timeval inicio = iniciaCronometro();

    Fila *fila = leitura(argv[1]);

    finalizaCronometro(inicio, "leitura");
 
    //----------------------------------------------------------------------//

    inicio = iniciaCronometro();

    int *resultado = NULL; // Alocado na função de resolução
    char *nome = NULL; // Nome do processo
    int x = atoi(argv[2]);
    switch(x){
        case 1:
            nome = "Força Bruta";
            resultado = resolucaoForcaBruta(fila);
            break;
        case 2:
            nome = "KMP";
            resultado = resolucaoKMP(fila);
            break;
        case 3:
            nome = "BMH";
            resultado = resolucaoBMH(fila);
            break;
        case 4:
            nome = "Shift-And";
            resultado = resolucaoShiftAnd(fila);
            break;
    }
    finalizaCronometro(inicio, "Processamento da cadeia de carateres");
    
    //----------------------------------------------------------------------//

    inicio = iniciaCronometro();
    
    escrita(resultado, nome, fila->tamanho);

    finalizaCronometro(inicio, "escrita");

    free(resultado);
    destroiFila(fila);
    return 0;
}
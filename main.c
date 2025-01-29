#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "leitura.h"
#include "forcaBruta.h"
#include "KMP.h"
#include "./BMH.h"
#include "./shiftAnd.h"

double tempoDecorridoCPU = 0;

int main(int *arg, char *argv[]){

    Fila *fila = leitura(argv[1]);
    //imprimirFila(fila);
    int x = atoi(argv[2]);
    switch(x){
        case 1:
            printf("Forca Bruta:\n");
            resolucaoForcaBruta(fila);
            break;
        case 2:
            printf("KMP:\n");
            resolucaoKMP(fila);
            break;
        case 3:
            printf("BMH:\n");
            resolucaoBMH(fila);
            break;
        case 4:
            printf("ShiftAnd:\n");
            resolucaoShiftAnd(fila);
            break;

            
        case 5:  //teste
            printf("Forca Bruta:\n"); 
            resolucaoForcaBruta(fila);
            printf("\n");
            printf("KMP:\n");
            resolucaoKMP(fila);
            printf("\n");
            printf("BMH:\n");
            resolucaoBMH(fila);
            printf("\n");
            printf("ShiftAnd:\n");
            resolucaoShiftAnd(fila);
            break;
    }

    destroiFila(fila);
    
    
    
    return 0;
}


void geraAruivo(){
   srand(time(NULL));

    FILE *teste = fopen("teste.txt", "w");

    for (int i = 0; i < 15; i++) {

        int x = 40 + (rand() % 100);
        int *vet = (int*) malloc(sizeof(int) * x);
        if (vet == NULL) {
            printf("Erro ao alocar memória para vet\n");
            return 1;
        }

        for (int j = 0; j < x; j++) {
            vet[j] = 65 + (rand() % 6);
        }

        int ini = rand() % (x / 2);
        int fifi = ini +1+ (rand() % (x / 2));
        if (fifi > x) fifi = x;

        int *vet2 = (int*) malloc(sizeof(int) * (fifi - ini));
        if (vet2 == NULL) {
            printf("Erro ao alocar memória para vet2\n");
            free(vet);
            return 1;
        }

        for (int k = ini, j = 0; k < fifi; k++, j++) {
            vet2[j] = vet[k];
        }

        fprintf(teste, "%d %d\n", x, (fifi - ini));
        for (int ii = 0; ii < x; ii++) {
            fprintf(teste, "%c ", vet[ii]);
        }
        fprintf(teste, "\n");

        for (int iii = 0; iii < fifi - ini; iii++) {
            fprintf(teste, "%c ", vet2[iii]);
        }
        fprintf(teste, "\n");

        free(vet);
        free(vet2);
    }

    fclose(teste); 

}

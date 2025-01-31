#include "BMH.h"

int *criaTabelaBMH(NO *nota, int tom){
    int *tabela = (int*)malloc(12 * sizeof(int));
    for (int i = 0; i < 12; i++){
        tabela[i] = nota->plagioTamanho; 
    }

    for (int i = 0; i < nota->plagioTamanho - 1; i++){
        tabela[tomShift(nota->plagio[i], tom) - 1] = nota->plagioTamanho - i - 1; 
    }
    return tabela;
}

int BMH(NO *nota, int* contador){

    for(int tom = 0; tom < 12; tom++){
        int i = nota->plagioTamanho - 1; 

        int *tabela = criaTabelaBMH(nota, tom);

        while (i < nota->originalTamanho){
            int k = i;
            int j = nota->plagioTamanho - 1;
    
            while (j >= 0 && nota->original[k] == tomShift(nota->plagio[j], tom)){
                (*contador)++;
                j--;
                k--;
            }

            if (j < 0){
                free(tabela);
                return i - nota->plagioTamanho + 1;
            } 
            
            i += tabela[nota->original[i] - 1]; 
        
        }

        free(tabela);
    }
    
    return -1;
}

int* resolucaoBMH(Fila *notas){
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho);
    int i = 0, contador = 0;
    while(aux != NULL){
        resultado[i] = BMH(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações(BMH).\n", contador);
    return resultado;
}



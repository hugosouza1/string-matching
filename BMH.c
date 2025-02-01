#include "BMH.h"

int *criaTabelaBMH(NO *nota, int tom){
    int *tabela = (int*)malloc(12 * sizeof(int)); // Tabela de deslocamento
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
            int k = i;                        // k é o índice do texto
            int j = nota->plagioTamanho - 1; // j é o índice do padrão
            // Compara elevando o tom do plagio para bater com o tom do original
            while (j >= 0 && nota->original[k] == tomShift(nota->plagio[j], tom)){ 
                (*contador)++; // Contador de comparações
                j--;
                k--;
            }

            if (j < 0){
                free(tabela);
                return i - nota->plagioTamanho + 1; // Achou o padrão
            } 
            
            i += tabela[nota->original[i] - 1]; 
        
        }

        free(tabela);
    }
    
    return -1; // Não achou o padrão
}

int* resolucaoBMH(Fila *notas){
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho); // Vetor de resultado
    int i = 0, contador = 0;
    while(aux != NULL){
        resultado[i] = BMH(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações(BMH).\n", contador);
    return resultado;
}



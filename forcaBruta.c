#include "forcaBruta.h"


int forcaBruta(NO *nota, int *contador){
    int *original = nota->original;
    int *plagio = nota->plagio;

    for(int i = 0; i < nota->originalTamanho; i++){ // Percorre o texto

        for(int j = i, k = 0; k < nota->plagioTamanho && j < nota->originalTamanho; j++, k++){ // Percorre o padrão
            (*contador)++; // Contador de comparações
            if(tons(original[j], plagio[k]) != tons(original[i], plagio[0])){
                // Verifica o tom comparando o tom dos primeiros com os seguintes
                break;
            }
            if(k == nota->plagioTamanho - 1){
                return i; // Achou o padrão 
            }
        }
    }
    return -1; // Não achou o padrão
}


int* resolucaoForcaBruta(Fila *notas){
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho); // Vetor de resultado
    int i = 0, contador = 0;
    while(aux != NULL){
        resultado[i] = forcaBruta(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações(Forca Bruta).\n", contador);
    return resultado;
}
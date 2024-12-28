#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./fila.h"

NO *criaNO() {
    NO *no = (NO*)malloc(sizeof(NO));
    no->prox = NULL;
    no->original = no->plagio = NULL;
    no->originalTamanho = no->plagioTamanho = 0;
    return no;
}

void destroiNO(NO *no){
    free(no->original);
    free(no->plagio);
    free(no);
}


Fila *criaFila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if(fila != NULL){
        fila->inicio = fila->final = NULL;
    }
    fila->tamanho = 0;
    return fila;
}

void destroiFila(Fila *fila) {
    if(fila == NULL) return;
    while(fila->inicio != NULL){
        NO *aux = fila->inicio;
        fila->inicio = fila->inicio->prox;
        destroiNO(aux);
    }
    free(fila);
}

int enfileirar(Fila *fila, int *original, int * plagio, int  originalTamanho, int plagioTamanho) {
    if(fila == NULL) return 0;
    NO *novo = criaNO();
    novo->original = original;
    novo->plagio = plagio;
    novo->originalTamanho = originalTamanho;
    novo->plagioTamanho = plagioTamanho;

    if(estaVaziaFila(fila)){
        fila->inicio = novo;
    } else {
        fila->final->prox = novo;
    }   
    fila->tamanho++;
    fila->final = novo;
    return 1;
}

int desenfileirar(Fila *fila) {
    if(fila == NULL) return 0;
    if(estaVaziaFila(fila)) return 0;
    NO *aux = fila->inicio;
    fila->inicio = aux->prox;
    if(fila->final == aux) fila->final = aux->prox;
    destroiNO(aux);
    fila->tamanho--;
    return 1;
}

 void imprimirFila(Fila *fila){
    if (fila == NULL) return;
    NO *aux = fila->inicio;
    while (aux != NULL){
        printf("Original: ");
        for(int i = 0; i < aux->originalTamanho; i++){
            printf("%.1d ", aux->original[i]);
        }
        printf("\nPlagio: ");
        for(int i = 0; i < aux->plagioTamanho; i++){
            printf("%.1d ", aux->plagio[i]);
        }
        printf("\n");
        aux = aux->prox;
    }
    printf("\n");
}

int estaVaziaFila(Fila *fila){
    return fila->inicio == NULL;
}
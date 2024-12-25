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
    destroiMatriz(no->original, no->originalTamanho);
    destroiMatriz(no->plagio, no->plagioTamanho);
    free(no);
}


// mudar o local depois
void alocaMatriz(char **matriz, int tamanho){
    matriz = (char**)malloc(tamanho * sizeof(char*));
    for(int i = 0; i < tamanho; i++){
        matriz[i] = (char*)malloc(2 * sizeof(char));
    }
}

void destroiMatriz(char **matriz, int tamanho){
    for(int i = 0; i < tamanho; i++){
        free(matriz[i]);
    }
    free(matriz);
}


Fila *criaFila(){
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    if(fila != NULL){
        fila->inicio = fila->final = NULL;
    }
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

int enfileirar(Fila *fila, char **original, char **plagio, int originalTamanho, int plagioTamanho) {
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
    return 1;
}

/* void imprimirFila(Fila *fila){
    if (fila == NULL) return;
    NO *aux = fila->inicio;
    int number = 1;
    while (aux != NULL){
        printf("%d\n", number); number++;
        imprimeSudoku(aux->sudoku);
        aux = aux->prox;
    }
    printf("\n");
}
 */
/* int tamanhoFila(Fila *fila){
    if(fila == NULL) return -1;
    return fila->tamanho;
} */
#ifndef FILA_H
#define FILA_H

typedef struct No {
    int originalTamanho;
    int plagioTamanho;

    char ** original;        
    char ** plagio;        
    struct No *prox;
} NO;

typedef struct {
    NO *inicio;
    NO *final;
} Fila;

Fila *criaFila();
void destroiFila(Fila *fila);
int enfileirar(Fila *fila, int** sudoku);
int desenfileirar(Fila *fila);
int estaVaziaFila(Fila *fila);
void imprimirFila(Fila *fila);
int tamanhoFila(Fila *fila);

#endif
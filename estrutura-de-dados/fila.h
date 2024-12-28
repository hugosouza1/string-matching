#ifndef FILA_H
#define FILA_H

typedef struct No {
    int originalTamanho;
    int plagioTamanho;

    double * original;        
    double * plagio;        
    struct No *prox;
} NO;

typedef struct {
    NO *inicio;
    NO *final;
    int tamanho;
} Fila;

Fila *criaFila();
void destroiFila(Fila *fila);
int enfileirar(Fila *fila, double *original, double * plagio, int  originalTamanho, int plagioTamanho);
int desenfileirar(Fila *fila);
void imprimirFila(Fila *fila);
int estaVaziaFila(Fila *fila);

#endif
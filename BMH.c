#include "BMH.h"

typedef struct Pair {
    int esquerda, direita;
} Pair;

int *criaTabelaBMH(NO *nota) {
    int *tabela = (int*)malloc(12 * sizeof(int));
    for(int i = 0; i < 12; i++) {
        tabela[i] = nota->plagioTamanho; // inicializa a tabela com o tamanho maximo de deslocamento
    }

    for(int i = 0; i < nota->plagioTamanho-1; i++) { // menos 1 para nao alterar o ultimo caractere
        tabela[nota->plagio[i] -1] = nota->plagioTamanho - i - 1; // atualiza a tabela com o deslocamento correto (distancia do caractere ao final da string)
    }
    return tabela;
}

int tomBMH(int valor, int tom) {
    valor += tom;
    if(valor > 12) {
        valor %= 12;
    }
    return valor;
}

void BMH(NO *nota){
    int *tabela = criaTabelaBMH(nota);
    int i = nota->plagioTamanho - 1;  // começa a partir do fim da copia (plagio)
    int tom = tons(nota->original[i], nota->plagio[nota->plagioTamanho - 1]);
    //printf("Pulos: ");

    while(i < nota->originalTamanho && i >= 0){
        //printf("%d ", i);
        // k é o indice do original, j é o indice do plagio
        int k = i; 
        int j = nota->plagioTamanho - 1; 

        while(j >= 0 && (tomShift(nota->original[k], tom) == nota->plagio[j])){
            j--;
            k--;
        }

        if(j < 0){
            printf("S %d\n", i - nota->plagioTamanho + 1); // correcao, pq o i é o indice do final da string
            free(tabela);
            return;
        }

        int m = 0, shift = -1;
        while(m < nota->plagioTamanho - 1 && i + 1 < nota->originalTamanho){
            int diferencaTom = tons(nota->original[i], nota->plagio[m]);
                if(tomShift(nota->original[i+1], diferencaTom) == nota->plagio[m+1]){
                    shift = nota->plagio[m] - 1;
                }
            m++;
        }

        //printf("shift: %d\n", shift);
        if(shift != -1){
            i += tabela[shift];
        } else {
            i += tabela[nota->original[i] - 1]; // desloca o indice de acordo com a tabela
        }
        tom = tons(nota->original[i], nota->plagio[nota->plagioTamanho - 1]);
    }
    free(tabela);

    printf("N\n");
    return;
}

void resolucaoBMH(Fila *notas) {
    NO *aux = notas->inicio;
    while(aux != NULL) {
        BMH(aux);
        aux = aux->prox;
    }
}

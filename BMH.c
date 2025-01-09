#include "BMH.h"

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
        valor -= 12;
    }
    return valor;
}

void BMH(NO *nota){
    int *tabela = criaTabelaBMH(nota);
    int i = nota->plagioTamanho - 1;  // começa a partir do fim da copia (plagio)

    while(i < nota->originalTamanho && i >= 0){
        // k é o indice do original, j é o indice do plagio
        int k = i; 
        int j = nota->plagioTamanho - 1; 

        int aux = j, aux2 = k; // auxiliares para guardar os indices do começo da comparação
        while(j >= 0 && (tons(nota->original[k], nota->plagio[j]) == tons(nota->original[aux2], nota->plagio[aux]))){
            j--;
            k--;
        }

        if(j < 0){
            printf("S %d\n", i - nota->plagioTamanho + 1); // correcao, pq o i é o indice do final da string
            free(tabela);
            return;
        }

        i += tabela[tomBMH(nota->original[i], tons(nota->original[i], nota->plagio[j])) - 1]; // desloca o indice de acordo com a tabela

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
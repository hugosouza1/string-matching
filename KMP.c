#include "KMP.h"

// Tabela que calcula o tamanho do prefixo e sufixo e permite que
// atualize na busca, sem retroceder na busca
int *criarTabelaLPS(int *padrao, int tamanho) { 
    int *tabela = (int*)malloc(tamanho * sizeof(int));
    int i = 0, j = 1;
    tabela[0] = 0;
    while (j < tamanho) {
        if (padrao[i] == padrao[j]) { // Se os caracteres forem iguais - caso 1
            i++;
            tabela[j] = i;
            j++;
        } else {
            if (i != 0) { // Se os caracteres forem diferentes e i for diferente de 0 - caso 3
                i = tabela[i - 1];
            } else { // Se os caracteres forem diferentes e i for igual a 0 - caso 2
                tabela[j] = 0;
                j++;
            }
        }
    }
    return tabela;
}

int KMP(NO* nota, int *contador) {
    int *texto = nota->original;
    int *padrao = nota->plagio;

    int i = 0, j = 0;
    int *tabela = criarTabelaLPS(padrao, nota->plagioTamanho);
    int tom = tons(texto[0], padrao[0]);

    while (i < nota->originalTamanho && j < nota->plagioTamanho) {
        (*contador)++;
        //printf("i = %d, j = %d, texto[i] = %d, padrao[j] = %d, tom = %d\n", i, j, texto[i], padrao[j], tom);
        if (tomShift(texto[i], tom) == padrao[j]) {
            i++;
            j++;
            if (j == nota->plagioTamanho) {
                free(tabela);
                return i - j; // Padrão encontrado
            }
        } else {
            if (j != 0) {
                j = tabela[j - 1]; // Atualiza j usando a tabela LPS
            } else {
                i++;
            }
            tom = tons(texto[i], padrao[0]); // Recalcula tom com o novo j
        }
    }

    free(tabela);
    return -1; // Padrão não encontrado
}

int* resolucaoKMP(Fila *notas) {
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho);
    int i = 0, contador = 0;
    while (aux != NULL) {
        resultado[i] = KMP(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações(KMP).\n", contador);
    return resultado;
}
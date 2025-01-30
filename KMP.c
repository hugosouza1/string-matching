#include "KMP.h"


//tabela que calcula o tamanho do prefixo e sufixo e permite que
//atualize na busca, sem retroceder na busca
int *criarTabelaLPS(int *padrao, int tamanho){ 
    int *tabela = (int*)malloc(tamanho * sizeof(int));
    int i = 0, j = 1;
    tabela[0] = 0;
    while(j < tamanho){
        if(padrao[i] == padrao[j]){ //se os caracteres forem iguais - caso 1
            i++;
            tabela[j] = i;
            j++;
        }else{
            if(i != 0){             //se os caracteres forem diferentes e i for diferente de 0 - caso 3
                i = tabela[i - 1];
            }else{                  //se os caracteres forem diferentes e i for igual a 0 - caso 2
                tabela[j] = 0;
                j++;
            }
        }
    }
    return tabela;
}

int KMP(NO* nota, int* contador){
    int *texto = nota->original;
    int *padrao = nota->plagio;
    int *tabela = criarTabelaLPS(padrao, nota->plagioTamanho);
    for(int tom = 0; tom < 12; tom++){

        int i = 0, j = 0;
        while( i < nota->originalTamanho){
            (*contador)++;
            if(texto[i] == tomShift(padrao[j], tom)){
                i++;
                j++;
                if(j == nota->plagioTamanho){
                    //printf("S %d | ", i-j);
                    free(tabela);
                    return i - j;
                }
            }else{
                if((i < nota->originalTamanho)) {
                    if(j != 0){
                        j = tabela[j - 1]; 
                    }else{ 
                        i++;     
                    }
                } else {
                    i++;
                }
            }
        }
    }
    //printf("N | ");
    free(tabela);
    return -1;
}

int* resolucaoKMP(Fila *notas){
    NO *aux = notas->inicio;
    int *resultado = (int*)malloc(sizeof(int) * notas->tamanho);
    int i = 0, contador = 0;
    while(aux != NULL){
        resultado[i] = KMP(aux, &contador);
        aux = aux->prox; i++;
    }
    printf("Foram feitas %d comparações.\n", contador);
    return resultado;
}
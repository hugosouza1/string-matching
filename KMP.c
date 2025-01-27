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

void KMP(NO* nota){
    int *texto = nota->original;
    int *padrao = nota->plagio;
    
    int i = 0, j = 0;
    int k = 0, h = 0; // indices para auxiliar na busca
    int *tabela = criarTabelaLPS(padrao, nota->plagioTamanho);
    int tom = tons(texto[0], padrao[0]);
    while( i < nota->originalTamanho){
        if(tomShift(texto[i], tom) == padrao[j]){
            i++;
            j++;
            if(j == nota->plagioTamanho){
                printf("S %d\n", i-j);
                free(tabela);
                return;
            }
        }else{
            if((i < nota->originalTamanho)) {
                if(j != 0){
                    j = tabela[j - 1]; //usa a tabela para atualizar o j
                                       //sem retroceder na busca
                    if(j == 0) tom = tons(texto[i], padrao[j]);
                }else{ 
                    i++;     
                    tom = tons(texto[i], padrao[j]);
                }
            } else {
                i++;
            }
        }
    }
    printf("N\n");
    free(tabela);
}

void resolucaoKMP(Fila *notas){
    NO *aux = notas->inicio;
    while(aux != NULL){
        KMP(aux);
        aux = aux->prox;
    }
}
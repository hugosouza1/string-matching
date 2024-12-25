#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leitura(char *path){
    FILE  *arq = fopen(path, "r");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    int m = 1, t = 1;
    while( 1 ){
        fscanf(arq, "%d %d", &m, &t);
        if(m == 0 && t == 0) break;
        
        fgets(arq;
        
    }


}
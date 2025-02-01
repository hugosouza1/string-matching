#include <stdio.h>
#include <stdlib.h>
#include "./estrutura-de-dados/fila.h"
#include "leitura.h"
#include "forcaBruta.h"
#include "KMP.h"
#include "./BMH.h"
#include "./shiftAnd.h"
#include "saida.h"
#include "cronometro.h"

double tempoDecorridoCPU = 0;

int geraArquivo();

int main(int *arg, char *argv[]){

    struct timeval inicio = iniciaCronometro();

    Fila *fila = leitura(argv[1]);

    finalizaCronometro(inicio, "leitura");
    //----------------------------------------------------------------------//

    inicio = iniciaCronometro();

    int *resultado = NULL; // Alocado na função de resolução
    char *nome = NULL; // Nome do processo
    int x = atoi(argv[2]);
    switch(x){
        case 1:
            nome = "Força Bruta";
            resultado = resolucaoForcaBruta(fila);
            break;
        case 2:
            nome = "KMP";
            resultado = resolucaoKMP(fila);
            break;
        case 3:
            nome = "BMH";
            resultado = resolucaoBMH(fila);
            break;
        case 4:
            nome = "Shift-And";
            resultado = resolucaoShiftAnd(fila);
            break;
    }
    finalizaCronometro(inicio, "Processamento da cadeia de carateres");
    
    //----------------------------------------------------------------------//

    inicio = iniciaCronometro();
    
    escrita(resultado, nome, fila->tamanho);

    finalizaCronometro(inicio, "escrita");

    free(resultado);
    destroiFila(fila);
    return 0;
}




// Função para gerar uma nota musical aleatória (A, B, C, D, E, F, G) com possibilidade de sustenido ou bemol
char* gerarNota() {
    char* nota = (char*) malloc(3 * sizeof(char)); // Aloca espaço para a nota (2 caracteres + '\0')
    char notas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int indice = rand() % 7; // Escolhe uma nota aleatória
    nota[0] = notas[indice]; // Define a nota base

    // Decide se a nota será natural, sustenido ou bemol
    int modificador = rand() % 3; // 0: natural, 1: sustenido, 2: bemol

    // Regras para sustenidos e bemóis
    if (nota[0] == 'B' || nota[0] == 'E') {
        // Notas B e E não podem ter sustenidos
        if (modificador == 1) modificador = 0; // Força natural
    } else if (nota[0] == 'C' || nota[0] == 'F') {
        // Notas C e F não podem ter bemóis
        if (modificador == 2) modificador = 0; // Força natural
    }

    // Aplica o modificador
    if (modificador == 1) {
        nota[1] = '#'; // Adiciona sustenido
        nota[2] = '\0'; // Termina a string
    } else if (modificador == 2) {
        nota[1] = 'b'; // Adiciona bemol
        nota[2] = '\0'; // Termina a string
    } else {
        nota[1] = '\0'; // Nota natural, sem modificador
    }

    return nota;
}

int geraArquivo() {
    srand(time(NULL));

    FILE* teste = fopen("teste.txt", "w");
    if (teste == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < 10000; i++) {
        int x = 1000 + (rand() % 400);

        char** vet = (char**) malloc(sizeof(char*) * x);
        for (int j = 0; j < x; j++) {
            vet[j] = gerarNota();
        }

        int ini = 5 + rand() % (x / 2);
        int fifi = ini + ini / 4 + (rand() % (x / 2));
        if (fifi > x) fifi = x;

        char** vet2 = (char**) malloc(sizeof(char*) * (fifi - ini));
        if (vet2 == NULL) {
            printf("Erro ao alocar memória para vet2\n");
            for (int j = 0; j < x; j++) free(vet[j]);
            free(vet);
            return 1;
        }
        
        // Copia os elementos de vet para vet2
        for (int iii = 0; iii < fifi - ini; iii++) {
            vet2[iii] = strdup(vet[ini + iii]);  // Aloca e copia a string corretamente
        }

        // Escreve no arquivo
        fprintf(teste, "%d %d\n", x, (fifi - ini));
        for (int ii = 0; ii < x; ii++) {
            fprintf(teste, "%s ", vet[ii]);
        }
        fprintf(teste, "\n");

        for (int iii = 0; iii < fifi - ini; iii++) {
            fprintf(teste, "%s ", vet2[iii]);
        }
        fprintf(teste, "\n");

        for (int j = 0; j < x; j++) free(vet[j]);
        for (int j = 0; j < fifi - ini; j++) free(vet2[j]);
        free(vet);
        free(vet2);
    }

    fprintf(teste, "0 0\n");
    fclose(teste);

    return 0;
}
#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "./cronometro.h"

struct timeval iniciaCronometro(){
    struct timeval inicio;
    gettimeofday(&inicio, NULL);
    return inicio;
}

void finalizaCronometro(struct timeval inicio, char *processo){
    struct rusage usage;
    struct timeval fim;
    gettimeofday(&fim, NULL);
    long seconds = fim.tv_sec - inicio.tv_sec;
    long  microseconds = fim.tv_usec - inicio.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;
    printf("Tempo de %s(cronologico): %.6f segundos\n", processo, (elapsed));
    getrusage(RUSAGE_SELF, &usage);
    printf("Tempo de %s(CPU): %.6lf segundos\n", 
           processo, (usage.ru_utime.tv_sec + usage.ru_utime.tv_usec * 1e-6) - tempoDecorridoCPU);

    tempoDecorridoCPU = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec * 1e-6;
}
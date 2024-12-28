#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <sys/time.h>

extern double tempoDecorridoCPU;

struct timeval iniciaCronometro();
void finalizaCronometro(struct timeval inicio, char *processo);
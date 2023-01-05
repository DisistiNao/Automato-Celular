#include<stdio.h>
#include <time.h>
#include "automato.h"

int main()
{
    int **M;
    int dimensao;
    
    double tempo_gasto = 0.0;
    clock_t inicio = clock();

    lerDimensao(&dimensao);
    M = alocaMatriz(dimensao);
    lerMatriz(M, dimensao);

    operacao(M, dimensao);
    printMatriz(M, dimensao);

    desalocaMatriz(&M, dimensao);

    clock_t fim = clock();
    tempo_gasto += (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n", tempo_gasto);

    return 0;
}

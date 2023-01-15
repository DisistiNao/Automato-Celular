#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

void lerDimensao(int *tamMatriz)
{
    scanf("%i", tamMatriz);
}

int **alocaMatriz(int tamMatriz)
{
    int **M;

    M = malloc(tamMatriz * sizeof(int *));

    for (int i = 0; i < tamMatriz; i++)
        M[i] = malloc(tamMatriz * sizeof(int));

    for (int i = 0; i < tamMatriz; i++)
        for (int j = 0; j < tamMatriz; j++)
            M[i][j] = 0;

    return M;
}

void desalocaMatriz(int ***matriz, int tamMatriz)
{
    for (int i = 0; i < tamMatriz; i++)
        free((*matriz)[i]);
    free(*matriz);
}

void lerMatriz(int **matriz, int tamMatriz)
{
    for (int i = 0; i < tamMatriz; i++)
        for (int j = 0; j < tamMatriz; j++)
            scanf("%i", &matriz[i][j]);
}

void operacao(int **matriz, int tamMatriz)
{
    for (int i = 0; i < tamMatriz; i++)
        for (int j = 0; j < tamMatriz; j++)
            if (matriz[i][j])
            {
                int cont = 0;

                if (matriz[i - 1][j - 1])
                    cont++;
                if (matriz[i - 1][j])
                    cont++;
                if (matriz[i - 1][j + 1])
                    cont++;
                if (matriz[i][j - 1])
                    cont++;
                if (matriz[i][j + 1])
                    cont++;
                if (matriz[i + 1][j - 1])
                    cont++;
                if (matriz[i + 1][j])
                    cont++;
                if (matriz[i + 1][j + 1])
                    cont++;

                if (cont != 2 && cont != 3)
                    matriz[i][j] = -1;
            }

    for (int i = 0; i < tamMatriz; i++)
        for (int j = 0; j < tamMatriz; j++)
            if (matriz[i][j] == 0)
            {
                int cont = 0;

                if (i != 0)
                {
                    if(j != 0)
                        if (matriz[i - 1][j - 1] == 1 || matriz[i - 1][j - 1] == -1)
                            cont++;
                    if (matriz[i - 1][j] == 1 || matriz[i - 1][j] == -1)
                        cont++;
                    if(j != tamMatriz - 1)
                        if (matriz[i - 1][j + 1] == 1 || matriz[i - 1][j + 1] == -1)
                            cont++;
                }

                if(j != 0)
                    if (matriz[i][j - 1] == 1 || matriz[i][j - 1] == -1)
                        cont++;
                if(j != tamMatriz - 1)
                    if (matriz[i][j + 1] == 1 || matriz[i][j + 1] == -1)
                        cont++;

                if (i != tamMatriz - 1)
                {
                    if(j != 0)
                        if (matriz[i + 1][j - 1] == 1 || matriz[i + 1][j - 1] == -1)
                            cont++;
                    if (matriz[i + 1][j] == 1 || matriz[i + 1][j] == -1)
                        cont++;
                    if(j != tamMatriz - 1)
                        if (matriz[i + 1][j + 1] == 1 || matriz[i + 1][j + 1] == -1)
                            cont++;
                }

                if (cont == 3)
                    matriz[i][j] = 2;
            }

    for (int i = 0; i < tamMatriz; i++)
        for (int j = 0; j < tamMatriz; j++)
        {
            if (matriz[i][j] == -1)
                matriz[i][j] = 0;
            if (matriz[i][j] == 2)
                matriz[i][j] = 1;
        }
}

void printMatriz(int **matriz, int tamMatriz)
{
    printf("\n");

    for (int i = 0; i < tamMatriz; i++)
    {
        for (int j = 0; j < tamMatriz; j++)
            printf("%i ", matriz[i][j]);
        printf("\n");
    }
}
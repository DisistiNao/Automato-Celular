#include<stdio.h>
#include<stdlib.h>

void lerTam(int *tam) {
    scanf("%i", tam);
}

int **alocaMatriz(int tam) {
    int **M;

    M = calloc (tam, sizeof (int*));

    for(int i=0; i < tam; i++)
        M[i] = calloc (tam, sizeof (int)) ;

    return M;
}

void lerMatriz(int **M, int tam) {
    for (int i = 0; i < tam; i++)
        for (int j = 0; j < tam; j++)
            scanf("%i", &M[i][j]);
}

void operacao(int **M, int tam) {
    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if(M[i][j]) {
                int cont = 0;

                if(M[i - 1][j - 1])
                    cont++;
                if(M[i - 1][j])
                    cont++;
                if(M[i - 1][j + 1])
                    cont++;
                if(M[i][j - 1])
                    cont++;
                if(M[i][j + 1])
                    cont++;
                if(M[i + 1][j - 1])
                    cont++;
                if(M[i + 1][j])
                    cont++;
                if(M[i + 1][j + 1])
                    cont++;

                if(cont != 2 && cont != 3)
                    M[i][j] = -1;
            }

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++)
            if(M[i][j] == 0) {
                int cont = 0;

                if(i != 0) {
                    if((M[i - 1][j - 1] == 1 || M[i - 1][j - 1] == -1) && j != 0)
                        cont++;
                    if(M[i - 1][j] == 1 || M[i - 1][j] == -1)
                        cont++;
                    if((M[i - 1][j + 1] == 1 || M[i - 1][j + 1] == -1) && j != tam - 1)
                        cont++;
                }

                if((M[i][j - 1] == 1 || M[i][j - 1] == -1) && j != 0)
                    cont++;
                if((M[i][j + 1] == 1 || M[i][j + 1] == -1) && j != tam - 1)
                    cont++;
                
                if(i != tam - 1) {
                    if((M[i + 1][j - 1] == 1 || M[i + 1][j - 1] == -1) && j != 0)
                        cont++;
                    if(M[i + 1][j] == 1 || M[i + 1][j] == -1)
                        cont++;
                    if((M[i + 1][j + 1] == 1 || M[i + 1][j + 1] == -1) && j != tam - 1)
                        cont++;
                }
                
                if(cont == 3)
                    M[i][j] = 2;
            }   

    for(int i = 0; i < tam; i++)
        for(int j = 0; j < tam; j++) {
            if(M[i][j] == -1)
                M[i][j] = 0;
            if(M[i][j] == 2)
                M[i][j] = 1;

        }
}

void printResultado(int **M, int tam) {
    printf("\n");

    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++)
            printf("%i ", M[i][j]);
        printf("\n");
    }
}

void desalocaMatriz(int ***M, int tam) {
  for (int i = 0; i < tam; i++)
    free((*M)[i]);
  free(*M);
}

int main()
{
    int **M;
    int tam;

    lerTam(&tam);
    M = alocaMatriz(tam);
    lerMatriz(M, tam);

    operacao(M, tam);
    printResultado(M, tam);

    desalocaMatriz(&M, tam);

    return 0;
}

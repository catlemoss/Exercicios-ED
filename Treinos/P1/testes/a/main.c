#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMatriz.h"

#define MAX_STRING 20

int main ()
{
    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE *saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int linhas = 0;
    int colunas = 0;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    tMatriz* mat = criaMatriz(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char* palavra = malloc (MAX_STRING * sizeof(char));
            fscanf(entrada, "%s", palavra);
            addNaMatriz(mat, i, j, palavra);

            free (palavra);
        }
    }

    imprimeMatriz(saida, mat);

    fprintf(saida, "============================\n");

    tMatriz* ord = ordenada(mat);
    imprimeMatriz(saida, ord);

    fclose(entrada);
    fclose(saida);

    liberaMatriz(mat);
    liberaMatriz(ord);

    return 0;
}
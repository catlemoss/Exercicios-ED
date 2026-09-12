#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMatriz.h"

#define STRING 20

int main ()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int linhas, colunas;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    tMatriz* mat = criaMatriz(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char *string = malloc(STRING * sizeof(char));
            fscanf(entrada, "%s", string);

            modificaMatriz(mat, i, j, string);

            free (string);
        }
    }

    imprimeMatriz(mat, saida);

    fprintf(saida, "============================\n");

    tMatriz* ordenada = ordenaMatriz(mat);
    imprimeMatriz(ordenada, saida);

    liberaMatriz(mat);
    liberaMatriz(ordenada);

    fclose(entrada);
    fclose(saida);

    return 0;
}
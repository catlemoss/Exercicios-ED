#include <stdio.h>
#include <stdlib.h>

#include "tMatriz.h"

int main ()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE *saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int linhas = 0, colunas = 0;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    tMatriz* mat = criaMatriz(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int num;
            fscanf(entrada, "%d", &num);
            addNaMatriz(mat, i, j, num);
        }
    }

    fprintf(saida, "Matriz original:\n");
    imprimeMatriz(saida, mat);

    fprintf(saida, "============================\n");

    fprintf(saida, "Matriz de vizinhanca:\n");
    tMatriz* viz = maiorNumVizinho(mat);
    imprimeMatriz(saida, viz);

    fclose(entrada);
    fclose(saida);

    liberaMatriz(mat);
    liberaMatriz(viz);

    return 0;
}
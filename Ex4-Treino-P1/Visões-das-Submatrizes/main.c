#include <stdio.h>
#include <stdlib.h>

#include "tMatriz.h"

int main ()
{
    FILE* entrada = fopen("entrada3.txt", "r");
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
            int num;
            fscanf(entrada, "%d", &num);
            addNaMatriz(mat, i, j, num);
        }
    }

    int linha_ini, linha_fim, col_ini, col_fim;
    fscanf(entrada, "%d %d %d %d", &linha_ini, &linha_fim, &col_ini, &col_fim);

    fprintf(saida, "Matriz Original:\n");
    imprimeMatriz(saida, mat);

    fprintf(saida, "Visão Submatriz %d-%d %d-%d:\n", linha_ini, linha_fim, col_ini, col_fim);
    tMatriz* sub = criaSubMatriz(mat, linha_ini, linha_fim, col_ini, col_fim);
    imprimeMatriz(saida, sub);
    liberaSubMatriz(sub);

    imprimeSubVisoesQuadradas(saida, mat);

    liberaMatriz(mat);

    fclose(entrada);
    fclose(saida);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "tMatriz.h"

struct matriz
{
    int linhas, colunas;
    int** mat;
};

tMatriz* criaMatriz(int linhas, int colunas)
{
    tMatriz* mat = malloc (sizeof(tMatriz));
    if (mat == NULL) exit(1);

    mat->linhas = linhas;
    mat->colunas = colunas;

    mat->mat = malloc (linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++)
    {
        mat->mat[i] = malloc (colunas * sizeof(int));
    }

    return mat;
}

void addNaMatriz(tMatriz* mat, int i, int j, int num)
{
    mat->mat[i][j] = num;
}

void liberaMatriz(tMatriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        free (mat->mat[i]);
    }

    free (mat->mat);
    free (mat);
}

tMatriz* maiorNumVizinho(tMatriz* mat)
{
    tMatriz* viz = criaMatriz(mat->linhas, mat->colunas);

    for (int i = 0; i < viz->linhas; i++)
    {
        for (int j = 0; j < viz->colunas; j++)
        {
            addNaMatriz(viz, i, j, mat->mat[i][j]);
        }
    }

    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            if (i == 0 || i == mat->linhas-1 || j == 0 || j == mat->colunas-1) continue;

            int maior = mat->mat[i][j];
            
            if (maior < mat->mat[i-1][j]) maior = mat->mat[i-1][j];    // cima
            if (maior < mat->mat[i+1][j]) maior = mat->mat[i+1][j];    // baixo
            if (maior < mat->mat[i][j-1]) maior = mat->mat[i][j-1];    // esquerda
            if (maior < mat->mat[i][j+1]) maior = mat->mat[i][j+1];    // direita

            viz->mat[i][j] = maior;
        }
    }

    return viz;
}

void imprimeMatriz(FILE* saida, tMatriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            fprintf(saida, "%d", mat->mat[i][j]);

            if (j < mat->colunas-1) fprintf(saida, " ");
        }
        fprintf(saida, "\n");
    }
}
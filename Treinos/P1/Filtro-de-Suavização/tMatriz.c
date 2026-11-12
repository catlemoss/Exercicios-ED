#include <stdio.h>
#include <stdlib.h>

#include "tMatriz.h"

struct matriz
{
    int linhas, colunas;
    int **mat;
};

tMatriz* criaMatriz(int linhas, int colunas)
{
    tMatriz* mat = malloc (sizeof (tMatriz));
    if (mat == NULL) exit(1);

    mat->linhas = linhas;
    mat->colunas = colunas;

    mat->mat = malloc (linhas * sizeof(int *));

    for (int i = 0; i < linhas; i++)
    {
        mat->mat[i] = malloc (colunas * sizeof(int));
    }

    return mat;
}

void modificaElemento(tMatriz* mat, int i, int j, int elem)
{
    mat->mat[i][j] = elem;
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

tMatriz* suavizacao(tMatriz* mat)
{
    tMatriz* suave = criaMatriz(mat->linhas, mat->colunas);

    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            if (i == 0 || i == mat->linhas -1 ||
                j == 0 || j == mat->colunas -1)
            {
                suave->mat[i][j] = mat->mat[i][j];
            }

            else
            {
                int soma = 0;
                int contador = 0;

                for (int x = i-1; x <= i+1; x++)
                {
                    for (int y = j-1; y <= j+1; y++)
                    {
                        soma += mat->mat[x][y];
                        contador++;
                    }
                }

                suave->mat[i][j] = soma / contador;
            }
        }
    }

    return suave;
}

void imprimeMatriz(tMatriz* mat, FILE *saida)
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

    fprintf(saida, "\n");
}
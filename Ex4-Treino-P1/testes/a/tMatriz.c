#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMatriz.h"

struct matriz
{
    int linhas, colunas;
    char*** mat;
};

tMatriz* criaMatriz(int linhas, int colunas)
{
    tMatriz* mat = malloc (sizeof(tMatriz));
    if (mat == NULL) exit(1);

    mat->linhas = linhas;
    mat->colunas = colunas;

    mat->mat = malloc (linhas * sizeof(char**));

    for (int i = 0; i < linhas; i++)
    {
        mat->mat[i] = malloc (colunas * sizeof(char*));

        for (int j = 0; j < colunas; j++)
        {
            mat->mat[i][j] = NULL;
        }
    }

    return mat;
}

void addNaMatriz(tMatriz* mat, int i, int j, char* string)
{
    int letras = strlen(string) +1;

    mat->mat[i][j] = malloc (letras * sizeof(char));
    strcpy(mat->mat[i][j], string);
}

void liberaMatriz(tMatriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            free (mat->mat[i][j]);
        }

        free (mat->mat[i]);
    }

    free (mat->mat);
    free (mat);
}

tMatriz* ordenada(tMatriz* mat)
{
    tMatriz* ord = criaMatriz(mat->linhas, mat->colunas);

    for (int i = 0; i < ord->linhas; i++)
    {
        for (int j = 0; j < ord->colunas; j++)
        {
            addNaMatriz(ord, i, j, mat->mat[i][j]);
        }
    }

    int total = ord->linhas * ord->colunas;

    for (int i = 0; i < total -1; i++)
    {
        for (int j = 0; j < total -i -1; j++)
        {
            if (strcmp(ord->mat[i][j], ord->mat[i+1][j+1]) > 0)
            {
                char* aux = ord->mat[i][j];
                ord->mat[i][j] = ord->mat[i+1][j+1];
                ord->mat[i+1][j+1] = aux;
            }
        }
    }

    return ord;
}

void imprimeMatriz(FILE* saida, tMatriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            fprintf(saida, "%s", mat->mat[i][j]);

            if (j < mat->colunas-1) fprintf(saida, " ");
        }
        fprintf(saida, "\n");
    }
}
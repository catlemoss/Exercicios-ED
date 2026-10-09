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

void modificaMatriz(tMatriz* mat, int i, int j, char* string)
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

tMatriz* ordenaMatriz(tMatriz* mat)
{
    tMatriz* ordenada = criaMatriz(mat->linhas, mat->colunas);

    for (int i = 0; i < ordenada->linhas; i++)
    {
        for (int j = 0; j < ordenada->colunas; j++)
        {
            int tam = strlen(mat->mat[i][j]) +1;
            
            ordenada->mat[i][j] = malloc (tam);
            strcpy(ordenada->mat[i][j], mat->mat[i][j]);
        }
    }

    int total = mat->linhas * mat->colunas;

    for (int i = 0; i < total -1; i++)
    {
        for (int j = 0; j < total -i -1; j++)
        {
            int linha1 = j / ordenada->colunas;
            int coluna1 = j % ordenada->colunas;

            int linha2 = (j+1) / ordenada->colunas;
            int coluna2 = (j+1) % ordenada->colunas;

            if (strcmp(ordenada->mat[linha1][coluna1], ordenada->mat[linha2][coluna2]) > 0)
            {
                char* aux = ordenada->mat[linha1][coluna1];
                ordenada->mat[linha1][coluna1] = ordenada->mat[linha2][coluna2];
                ordenada->mat[linha2][coluna2] = aux;
            }
        }
    }

    return ordenada;
}

void imprimeMatriz(tMatriz* mat, FILE* saida)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            if (mat->mat[i][j] == NULL)
            {
                printf("POSICAO NULL: [%d][%d]\n", i, j);
            }
            else
            {
                fprintf(saida, "%s", mat->mat[i][j]);
            }

            if (j < mat->colunas-1) fprintf(saida, " ");
        }
        fprintf(saida, "\n");
    }
}
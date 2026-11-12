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

void addNaMatriz(tMatriz* mat, int i, int j, int elem)
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

void liberaSubMatriz(tMatriz* sub)
{
    free(sub->mat);
    free(sub);
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
    fprintf(saida, "\n");
}

tMatriz* criaSubMatriz(tMatriz* mat, int linha_ini, int linha_fim, int col_ini, int col_fim)
{
    tMatriz* sub = malloc (sizeof(tMatriz));
    if (sub == NULL) exit(1);

    sub->linhas = linha_fim - linha_ini +1;
    sub->colunas = col_fim - col_ini +1;

    sub->mat = malloc (sub->linhas * sizeof(int*));

    for (int i = 0; i < sub->linhas; i++)
    {
        sub->mat[i] = &mat->mat[linha_ini +i][col_ini];
    }

    return sub;
}

void imprimeSubVisoesQuadradas(FILE* saida, tMatriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            int linhas_restantes = mat->linhas -i;
            int colunas_restantes = mat->colunas -j;

            int max_tam;

            if (linhas_restantes < colunas_restantes) max_tam = linhas_restantes;
            else max_tam = colunas_restantes;

            for (int x = 0; x < max_tam; x++)
            {
                tMatriz* sub = criaSubMatriz(mat, i, i+x, j, j+x);

                fprintf(saida,"Submatriz quadrada %dx%d em (%d,%d):\n", x+1, x+1, i, j);
                imprimeMatriz(saida, sub);

                liberaSubMatriz(sub);
            }
        }
    }
}
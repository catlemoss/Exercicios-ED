/*

CATARINA LEMOS SILVEIRA - 2025100885

*/

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
    fprintf(saida, "\n");
    // correção -> add
}

tMatriz* criaSubMatriz(tMatriz* origem, int linha_ini, int linha_fim, int col_ini, int col_fim)
{
    tMatriz* sub = malloc (sizeof(tMatriz));

    sub->linhas = linha_fim - linha_ini +1;
    sub->colunas = col_fim - col_ini +1;

    sub->mat = malloc (sub->linhas * sizeof(char*));
    // correção -> sub->mat = NULL

    for (int i = 0; i < sub->linhas; i++)
    {
        sub->mat[i] = &origem->mat[linha_ini + i][col_ini];
    }

    return sub;
}

void imprimeSubVisoesQuadradas(FILE* saida, tMatriz* origem)
{
    for (int i = 0; i < origem->linhas; i++)
    {
        for (int j = 0; j < origem->colunas; j++)
        {
            int linhas_restantes = origem->linhas -i;
            int colunas_restantes = origem->colunas -j;

            int max_tam; 

            if (linhas_restantes < colunas_restantes) max_tam = linhas_restantes;
            else max_tam = colunas_restantes;

            for (int x = 0; x < max_tam; x++)
            {
                fprintf(saida, "Submatriz quadrada %dx%d em (%d,%d):\n", x+1, x+1, i, j);

                tMatriz* sub = criaSubMatriz(origem, i, i+x, j, j+x);
                imprimeMatriz(saida, sub);
                liberaSubMat(sub);
            }
        }
    }
}

void liberaSubMat(tMatriz* sub)
{
    free (sub->mat);
    free (sub);
}

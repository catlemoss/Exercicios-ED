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

    mat->mat[i][j] = malloc(letras * sizeof(char));
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

void buscaPalavra(tMatriz* mat, char* palavra)
{
    int achei = 0;
    int linha = -1;
    int coluna = -1;

    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            if (strcmp(mat->mat[i][j], palavra) == 0)
            {
                achei = 1;
                linha = i;
                coluna = j;
            }
        }
    }

    if (achei) printf("Palavra encontrada na posicao [%d][%d] :)!\n", linha, coluna);
    else printf("Palavra não encontrada... :(\n");
}

void imprimeMatriz(tMatriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            printf("%s", mat->mat[i][j]);

            if (j < mat->colunas-1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}
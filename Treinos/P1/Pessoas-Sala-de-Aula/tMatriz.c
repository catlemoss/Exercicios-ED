#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMatriz.h"

struct Matriz
{
    int linha, coluna;
    char ***mat;
};

tMatriz* criaMatriz(int linhas, int colunas)
{
    tMatriz *matriz = malloc (sizeof(tMatriz));
    if (matriz == NULL) exit(1);

    matriz->linha = linhas;
    matriz->coluna = colunas;

    matriz->mat = malloc (linhas * sizeof(char**));

    for (int i = 0; i < linhas; i++)
    {
        matriz->mat[i] = malloc (colunas * sizeof(char*));

        for (int j = 0; j < colunas; j++)
        {
            matriz->mat[i][j] = NULL;
        }
    }

    return matriz;
}

void modificaElemento (tMatriz* mat, int linha, int coluna, char *elem)
{
    int letras = strlen(elem)+1;

    mat->mat[linha][coluna] = malloc(letras * sizeof(char));
    strcpy(mat->mat[linha][coluna], elem);
}

void liberaMatriz(tMatriz* Matriz)
{
    for (int i = 0; i < Matriz->linha; i++)
    {   
        for (int j = 0; j < Matriz->coluna; j++)
        {
            free(Matriz->mat[i][j]);
        }

        free(Matriz->mat[i]);
    }

    free(Matriz->mat);
    free(Matriz);
}

tMatriz* transposta(tMatriz* Matriz)
{
    tMatriz *tsp = criaMatriz(Matriz->coluna, Matriz->linha);

    for (int i = 0; i < Matriz->coluna; i++)
    {
        for (int j = 0; j < Matriz->linha; j++)
        {
            tsp->mat[i][j] = malloc(strlen(Matriz->mat[j][i]) +1);
            strcpy(tsp->mat[i][j], Matriz->mat[j][i]);
        }
    }

    return tsp;
}

tMatriz* ordemAlf(tMatriz* Matriz)
{
    tMatriz *alf = criaMatriz(Matriz->linha, Matriz->coluna);

    // copia da matriz
    for (int i = 0; i < Matriz->linha; i++)
    {
        for (int j = 0; j < Matriz->coluna; j++)
        {
            alf->mat[i][j] = malloc(strlen(Matriz->mat[i][j]) +1);
            strcpy(alf->mat[i][j], Matriz->mat[i][j]);
        }
    }

    int total = Matriz->linha * Matriz->coluna;

    for (int i = 0; i < total-1; i++)                            
    {
        for (int j = 0; j < total -1 -i; j++)             
        {
            int linha1 = j / Matriz->coluna;                // grupos de colunas completas / qual linha
            int coluna1 = j % Matriz->coluna;               // sobra das colunas completas / pos na lin

            int linha2 = (j+1) / Matriz->coluna;
            int coluna2 = (j+1) % Matriz->coluna;

            if (strcmp(alf->mat[linha1][coluna1], alf->mat[linha2][coluna2]) > 0)
            {
                char *aux = alf->mat[linha1][coluna1];
                alf->mat[linha1][coluna1] = alf->mat[linha2][coluna2];
                alf->mat[linha2][coluna2] = aux;
            }
        }
    }


    return alf;
}

void imprimeMatriz(tMatriz* Matriz)
{
    for (int i = 0; i < Matriz->linha; i++)
    {
        for (int j = 0; j < Matriz->coluna; j++)
        {
            printf("%s", Matriz->mat[i][j]);

            if (j < Matriz->coluna-1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int getNLinhas(tMatriz* Matriz)
{
    return Matriz->linha;
}

int getNColunas(tMatriz* Matriz)
{
    return Matriz->coluna;
}
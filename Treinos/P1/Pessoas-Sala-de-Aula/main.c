#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMatriz.h"

int main ()
{
    FILE *entrada = freopen("entrada.txt", "r", stdin);
    if (entrada == NULL) exit(1);

    FILE *saida = freopen("saida.txt", "w", stdout);
    if (saida == NULL) exit(1);

    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    tMatriz *mat = criaMatriz(linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char nome[20];
            scanf("%s", nome);
            modificaElemento(mat, i, j, nome);
        }
    }

    imprimeMatriz(mat);

    printf("== Primeiro experimento:\n");
    tMatriz *tsp = transposta(mat);
    imprimeMatriz(tsp);

    printf("== Segundo experimento:\n");
    tMatriz *alf = ordemAlf(mat);
    imprimeMatriz(alf);

    liberaMatriz(mat);
    liberaMatriz(tsp);
    liberaMatriz(alf);

    return 0;
}
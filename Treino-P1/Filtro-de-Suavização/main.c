#include <stdio.h>
#include <stdlib.h>

#include "tMatriz.h"

int main ()
{
    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE *saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int linhas, colunas;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    tMatriz *mat = criaMatriz(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int num;
            fscanf(entrada, "%d", &num);
            modificaElemento(mat, i, j, num);
        }
    }

    imprimeMatriz(mat, saida);

    fprintf(saida, "A matriz com filtro de suavização eh:\n");
    tMatriz *suave = suavizacao(mat);
    imprimeMatriz(suave, saida);

    liberaMatriz(mat);
    liberaMatriz(suave);

    fclose(entrada);
    fclose(saida);
    
    return 0;
}
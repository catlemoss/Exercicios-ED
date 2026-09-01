#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main ()
{
    FILE *entrada = freopen("entrada.txt", "r", stdin);
    if (entrada == NULL) exit(1);

    FILE *saida = freopen("saida.txt", "w", stdout);
    if (saida == NULL) exit(1);

    int linhas, colunas;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    Matriz *mat = inicializaMatriz(linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int num;
            fscanf(entrada, "%d", &num);
            modificaElemento(mat, i, j, num);
        }
    }

    imprimeMatriz(mat);

    printf("A matriz transposta eh:\n");
    Matriz *tsp = transposta(mat);
    imprimeMatriz(tsp);

    printf("A matriz multiplicacao eh:\n");
    Matriz *mult = multiplicacao(mat, tsp);
    imprimeMatriz(mult);

    /*
    printf("Troque os numeros da mat!\nEscolha sua linha, coluna e seu numero: ");
    int nlinha, ncoluna, elem;
    scanf("%d %d %d", &nlinha, &ncoluna, &elem);

    if (nlinha >= recuperaNLinhas(mat))
    {
        printf("Linha invalida!\n");
        return 0;
    }
    else if (ncoluna >= recuperaNColunas(mat))
    {
        printf("Coluna invalida!\n");
        return 0;
    }

    modificaElemento(mat, nlinha, ncoluna, elem);
    imprimeMatriz(mat);

    printf("Imprima uma linha! Escolha sua linha: ");
    int myLinha;
    scanf("%d", &myLinha);

    if (nlinha >= recuperaNLinhas(mat))
    {
        printf("Linha invalida!\n");
        return 0;
    }

    imprimeLinha(mat, myLinha);
    */

    destroiMatriz(mat);
    destroiMatriz(tsp);
    destroiMatriz(mult);

    return 0;
}
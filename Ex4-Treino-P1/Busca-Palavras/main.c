#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tMatriz.h"

#define STRING 20

int main ()
{
    FILE *entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    int linhas, colunas;
    fscanf(entrada, "%d %d", &linhas, &colunas);

    tMatriz* mat = criaMatriz(linhas, colunas);

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            char palavra[STRING];
            fscanf(entrada, "%s", palavra);

            addNaMatriz(mat, i, j, palavra);
        }
    }

    imprimeMatriz(mat);

    printf("============================\n");

    while (1)
    {
        printf("==> Digite a palavra para o caça-palavras ou 0, caso queira sair:\n");

        char find_palavra[STRING];
        scanf("%s", find_palavra);

        if (strcmp(find_palavra, "0") == 0)
        {
            printf("Program ended with exit code: 0\n");
            break;
        }

        else
        {
            buscaPalavra(mat, find_palavra);
            printf("\n");
        }
    }

    liberaMatriz(mat);

    fclose(entrada);
    
    return 0;
}
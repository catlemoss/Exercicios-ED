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
            char *palavra = malloc(STRING * sizeof(char));
            fscanf(entrada, "%s", palavra);

            addNaMatriz(mat, i, j, palavra);

            free (palavra);
        }
    }

    imprimeMatriz(mat);

    printf("============================\n");

    char *find_palavra = malloc(STRING * sizeof(char));

    while (1)
    {
        printf("==> Digite a palavra para o caça-palavras ou 0, caso queira sair:\n");

        scanf("%s", find_palavra);

        if (strcmp(find_palavra, "0") == 0) break;

        buscaPalavra(mat, find_palavra);
        printf("\n");
    }

    free (find_palavra);

    liberaMatriz(mat);

    fclose(entrada);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tSupermercado.h"

int main ()
{
    FILE *arq = fopen("entrada.txt", "r");
    if (arq == NULL) exit(1);

    int qntProdutos;
    fscanf(arq, "%d", &qntProdutos);

    tProduto **produtos = malloc(qntProdutos * sizeof(tProduto*));

    for (int i = 0; i < qntProdutos; i++)
    {
        int id;
        fscanf (arq, "%d", &id);

        produtos[id-1] = leProduto(arq);
    }

    tSupermercado *super = leSupermercado(arq, produtos);

    imprimeSupermercado(super);
    liberaSupermercado(super);

    for (int i = 0; i < qntProdutos; i++)
    {
        liberaProduto(produtos[i]);
    }
    free (produtos);

    fclose(arq);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tProduto.h"

struct Produto
{
    char *nome;
    float valor;
};

tProduto* criaProduto(char *nome, float valor)
{
    tProduto *p = calloc(1, sizeof(tProduto));
    if (p == NULL) exit(1);

    p->nome = malloc((strlen(nome)+1) * sizeof(char));
    strcpy(p->nome, nome);

    p->valor = valor;

    return p;
}

void liberaProduto(tProduto* produto)
{
    free (produto->nome);
    free (produto);
}

tProduto* leProduto(FILE *arq)
{
    char nome[100];
    float valor;

    fscanf (arq, "%99s %f", nome, &valor);

    return criaProduto(nome, valor);
}

char* getNomeProduto(tProduto* produto)
{
    return produto->nome;
}

float getValorProduto(tProduto* produto)
{
    return produto->valor;
}
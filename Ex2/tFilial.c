#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tFilial.h"

struct Filial
{
    char *nome;
    tEstoque *estoque;
};

tFilial* criaFilial(char *nome, tEstoque *estoque)
{
    tFilial *f = calloc(1, sizeof(tFilial));
    if (f == NULL) exit(1);

    f->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(f->nome, nome);

    f->estoque = estoque;

    return f;
}

void liberaFilial(tFilial *filial)
{
    liberaEstoque(filial->estoque);
    free (filial->nome);
    free (filial);
}

tFilial* leFilial(FILE *arq, tProduto **produtos)
{
    char nome[100];
    fscanf(arq, "%s", nome);

    tEstoque *estoque = leEstoque(arq, produtos);

    return criaFilial(nome, estoque);
}

char* getNomeFilial(tFilial *filial)
{
    return filial->nome;
}

tEstoque* getEstoqueFilial(tFilial *filial)
{
    return filial->estoque;
}

void imprimeFilial(tFilial* filial)
{
    printf("Filial: %s\n", filial->nome);
    imprimeEstoque(filial->estoque);
}
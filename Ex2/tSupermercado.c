#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tSupermercado.h"

struct Supermercado
{
    char *nome;
    tFilial **filiais;
    int qntFiliais;
    float valor_total_estoque;
};

tSupermercado* criaSupermercado(char *nome, int qntFiliais)
{
    tSupermercado *s = calloc(1, sizeof(tSupermercado));
    if (s == NULL) exit(1);

    s->nome = malloc((strlen(nome)+1) * sizeof(char));
    strcpy(s->nome, nome);

    s->filiais = malloc(qntFiliais * sizeof(tFilial*));
    s->qntFiliais = qntFiliais;

    return s;
}

void liberaSupermercado(tSupermercado *super)
{
    for (int i = 0; i < super->qntFiliais; i++)
    {
        liberaFilial(super->filiais[i]);
    }

    free (super->filiais);
    free (super->nome);
    free (super);
}

tSupermercado* leSupermercado(FILE *arq, tProduto **produtos)
{
    char nome[100];
    int qntFiliais;

    fscanf(arq, "%s", nome);
    fscanf(arq, "%d", &qntFiliais);

    tSupermercado *super =criaSupermercado(nome, qntFiliais);

    for (int i = 0; i < qntFiliais; i++)
    {
        super->filiais[i] = leFilial(arq, produtos);
    }

    return super;
}

char* getNomeSupermercado(tSupermercado *super)
{
    return super->nome;
}

int getQntFiliaisSupermercado(tSupermercado *super)
{
    return super->qntFiliais;
}

tFilial* getFilialSupermercado(tSupermercado *super, int pos)
{
    return super->filiais[pos];
}

float getValorTotalSupermercado(tSupermercado *super)
{
    return super->valor_total_estoque;
}

void imprimeSupermercado(tSupermercado *super)
{
    for (int i = 0; i < super->qntFiliais; i++)
    {
        super->valor_total_estoque += getValorEstoque(getEstoqueFilial(super->filiais[i]));
    }

    printf("Nome do Supermercado: %s\n", super->nome);

    for (int i = 0; i < super->qntFiliais; i++)
    {
        imprimeFilial(super->filiais[i]);
    }
}
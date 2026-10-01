#include <stdio.h>
#include <stdlib.h>

#include "tEstoque.h"

struct Estoque
{
    float valor;
    int qntItens;
    tItem **itens;
};

tEstoque* criaEstoque(int qntItens)
{
    tEstoque *e = calloc(1, sizeof(tEstoque));
    if (e == NULL) exit(1);

    e->itens = malloc(qntItens * sizeof(tItem*));
    e->qntItens = qntItens;
    
    return e;
}

void liberaEstoque(tEstoque* estoque)
{
    for (int i = 0; i < estoque->qntItens; i++)
    {
        liberaItem(estoque->itens[i]);
    }

    free (estoque->itens);
    free (estoque);
}

tEstoque* leEstoque(FILE *arq, tProduto **produtos)
{
    int qntItens;
    fscanf (arq, "%d", &qntItens);

    tEstoque *estoque = criaEstoque(qntItens);

    for (int i = 0; i < estoque->qntItens; i++)
    {
        estoque->itens[i] = leItem(arq, produtos);
    }

    return estoque;
}

int getQntItensEstoque(tEstoque* estoque)
{
    return estoque->qntItens;
}

float getValorEstoque(tEstoque* estoque)
{
    return estoque->valor;
}

tItem* getItemEstoque(tEstoque* estoque, int pos)
{
    return estoque->itens[pos];
}

void imprimeEstoque(tEstoque* estoque)
{
    for (int i = 0; i < estoque->qntItens; i++)
    {
        estoque->valor += getQntItem(estoque->itens[i]) * 
            getValorProduto(getProdutoItem(estoque->itens[i]));
    }

    printf("Estoque: %.2f\n", estoque->valor);

    for (int i = 0; i < estoque->qntItens; i++)
    {
        imprimeItem(estoque->itens[i]);
    }
}
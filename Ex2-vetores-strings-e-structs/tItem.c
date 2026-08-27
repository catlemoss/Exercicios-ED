#include <stdio.h>
#include <stdlib.h>

#include "tItem.h"

struct Item
{
    int qnt;
    tProduto *produto;
};

tItem* criaItem(tProduto *produto, int qnt)
{
    tItem *i = calloc(1, sizeof(tItem));
    if (i == NULL) exit(1);

    i->qnt = qnt;
    i->produto = produto;

    return i;
}

tItem* leItem(FILE *arq, tProduto **produtos)
{
    int idProduto;
    int qnt;

    fscanf (arq, "%d %d", &idProduto, &qnt);

    tProduto *produto = produtos[idProduto-1];

    return criaItem(produto, qnt);
}

void liberaItem(tItem* Item)
{
    free (Item);
}

int getQntItem(tItem* Item)
{
    return Item->qnt;
}

tProduto* getProdutoItem(tItem* Item)
{
    return Item->produto;
}

void imprimeItem(tItem* item)
{
    printf("Item: %s, valor unitario: %.2f, quantidade: %d\n",
        getNomeProduto(getProdutoItem(item)),
        getValorProduto(getProdutoItem(item)),
        item->qnt
    );
}
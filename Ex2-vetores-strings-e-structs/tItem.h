#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

#include "tProduto.h"

typedef struct Item tItem;

tItem* criaItem(tProduto* produto, int qnt);
void liberaItem(tItem* Item);

tItem* leItem(FILE *arq, tProduto **produtos);

int getQntItem(tItem* Item);
tProduto* getProdutoItem(tItem* Item);

void imprimeItem(tItem* item);

#endif
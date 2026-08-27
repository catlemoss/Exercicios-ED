#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdio.h>

#include "tItem.h"

typedef struct Estoque tEstoque;

tEstoque* criaEstoque(int qntItens);
void liberaEstoque(tEstoque* estoque);

tEstoque* leEstoque(FILE *arq, tProduto **produtos);

int getQntItensEstoque(tEstoque* estoque);
float getValorEstoque(tEstoque* estoque);
tItem* getItemEstoque(tEstoque* estoque, int pos);

void imprimeEstoque(tEstoque* estoque);

#endif
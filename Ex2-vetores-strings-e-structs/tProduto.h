#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>

typedef struct Produto tProduto;

tProduto* criaProduto(char *nome, float valor);
void liberaProduto(tProduto* produto);

tProduto* leProduto(FILE *arq);

char* getNomeProduto(tProduto* produto);
float getValorProduto(tProduto* produto);

#endif
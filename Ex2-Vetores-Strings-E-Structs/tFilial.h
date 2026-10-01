#ifndef FILIAL_H
#define FILIAL_H

#include <stdio.h>

#include "tEstoque.h"
#include "tProduto.h"

typedef struct Filial tFilial;

tFilial* criaFilial(char *nome, tEstoque *estoque);
void liberaFilial(tFilial *filial);

tFilial* leFilial(FILE *arq, tProduto **produtos);

char* getNomeFilial(tFilial *filial);
tEstoque* getEstoqueFilial(tFilial *filial);

void imprimeFilial(tFilial* filial);

#endif
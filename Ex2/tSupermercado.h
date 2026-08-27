#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <stdio.h>

#include "tFilial.h"
#include "tProduto.h"

typedef struct Supermercado tSupermercado;

tSupermercado* criaSupermercado(char *nome, int qntFiliais);
void liberaSupermercado(tSupermercado *super);

tSupermercado* leSupermercado(FILE *arq, tProduto **produtos);

char* getNomeSupermercado(tSupermercado *super);
int getQntFiliaisSupermercado(tSupermercado *super);
tFilial* getFilialSupermercado(tSupermercado *super, int pos);
float getValorTotalSupermercado(tSupermercado *super);

void imprimeSupermercado(tSupermercado *super);

#endif
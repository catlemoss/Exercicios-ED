#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>

typedef struct matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void addNaMatriz(tMatriz* mat, int i, int j, int num);
void liberaMatriz(tMatriz* mat);

tMatriz* maiorNumVizinho(tMatriz* mat);

void imprimeMatriz(FILE* saida, tMatriz* mat);

#endif
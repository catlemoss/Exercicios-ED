#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>

typedef struct matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void modificaMatriz(tMatriz* mat, int i, int j, char* string);
void liberaMatriz(tMatriz* mat);

tMatriz* ordenaMatriz(tMatriz* mat);

void imprimeMatriz(tMatriz* mat, FILE* saida);

#endif
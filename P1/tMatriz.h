/*

CATARINA LEMOS SILVEIRA - 2025100885

*/

#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>

typedef struct matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void addNaMatriz(tMatriz* mat, int i, int j, char* string);
void liberaMatriz(tMatriz* mat);
void imprimeMatriz(FILE* saida, tMatriz* mat);

tMatriz* criaSubMatriz(tMatriz* origem, int linha_ini, int linha_fim, int col_ini, int col_fim);
void imprimeSubVisoesQuadradas(FILE* saida, tMatriz* origem);

void liberaSubMat(tMatriz* sub);

#endif
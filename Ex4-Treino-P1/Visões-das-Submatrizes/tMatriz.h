#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <stdio.h>

typedef struct matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void addNaMatriz(tMatriz* mat, int i, int j, int elem);
void liberaMatriz(tMatriz* mat);
void imprimeMatriz(FILE* saida, tMatriz* mat);

tMatriz* criaSubMatriz(tMatriz* mat, int linha_ini, int linha_fim, int col_ini, int col_fim);
void imprimeSubVisoesQuadradas(FILE*saida, tMatriz* mat);
void liberaSubMatriz(tMatriz* sub);

#endif
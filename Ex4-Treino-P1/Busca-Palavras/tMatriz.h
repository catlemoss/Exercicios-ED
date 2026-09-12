#ifndef _MATRIZ__H_
#define _MATRIZ_H_

typedef struct matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void addNaMatriz(tMatriz* mat, int i, int j, char* string);
void liberaMatriz(tMatriz* mat);

void buscaPalavra(tMatriz* mat, char* palavra);

void imprimeMatriz(tMatriz* mat);

#endif
#ifndef _Matriz_H
#define _Matriz_H

#include <stdio.h>

typedef struct Matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void modificaElemento (tMatriz* mat, int linha, int coluna, char *elem);
void liberaMatriz(tMatriz* Matriz);

tMatriz* transposta(tMatriz* Matriz);
tMatriz* ordemAlf(tMatriz* Matriz);
void imprimeMatriz(tMatriz* Matriz);

int getNLinhas(tMatriz* Matriz);
int getNColunas(tMatriz* Matriz);

#endif
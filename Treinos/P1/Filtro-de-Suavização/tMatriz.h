#ifndef _Matriz_H_
#define _Matriz_H_

typedef struct matriz tMatriz;

tMatriz* criaMatriz(int linhas, int colunas);
void modificaElemento(tMatriz* mat, int i, int j, int elem);
void liberaMatriz(tMatriz* mat);

tMatriz* suavizacao(tMatriz* mat);

void imprimeMatriz(tMatriz* mat, FILE *saida);

#endif
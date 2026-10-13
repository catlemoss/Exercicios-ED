#ifndef FILA_H
#define FILA_H

#include "amostra.h"

typedef struct fila tFila;

tFila* criaFila(void);
void insereFila(tFila* fila, Amostra* amostra);
Amostra* retiraFila (tFila* fila);
int estaVaziaFila(tFila* fila);
void liberaFila(tFila* fila);
void imprimeFila(tFila* fila);

int getNElemFila(tFila* fila);

#endif
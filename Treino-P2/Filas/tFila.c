#include <stdio.h>
#include <stdlib.h>

#include "tFila.h"

#define TAM 6

struct fila
{
    int ini;
    int qnt;

    float fila[TAM];
};

void insereFila(tFila* fila, float amostra)
{
    int fim;

    if (!fila || fila->qnt == TAM)
    {
        printf("Fila cheia!\n");
        return;
    }

    fim = (fila->ini + fila->qnt) % TAM;
    fila->fila[fim] = amostra;

    fila->qnt++;
}

float retiraFila (tFila* fila)
{
    if (!fila || fila->qnt == 0)
    {
        printf("Fila vazia!\n");
        exit (1);
    }

    float valor = fila->fila[fila->ini];

    fila->ini = (fila->ini +1) % TAM;
    fila->qnt--;

    return valor;
}
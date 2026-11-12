#include <stdio.h>
#include <stdlib.h>

#include "tFilaEnc.h"

typedef struct cell tCell;
struct cell
{
    float valor;
    struct cell* prox;
};

struct filaEnc
{
    tCell* ini;
    tCell* fim;
};

void insereFilaEnc(tFilaEnc* fila, float amostra)
{
    tCell* new = malloc (sizeof(tCell));

    new->valor = amostra;
    new->prox = NULL;

    if (fila->ini == NULL)
    {
        fila->ini = new;
        fila->fim = new;
    }
    else
    {
        fila->fim->prox = new;
        fila->fim = new;
    }
}

float retiraFilaEnc(tFilaEnc* fila)
{
    if (!fila || fila->ini == NULL)
    {
        printf("Fila vazia!\n");
        exit(1);
    }
    
    tCell* aux = fila->ini;

    float retirado = aux->valor;

    fila->ini = aux->prox;

    if (fila->ini == NULL) fila->fim = NULL;

    free (aux);

    return retirado;
}
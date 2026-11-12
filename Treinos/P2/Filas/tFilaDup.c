#include <stdio.h>
#include <stdlib.h>

#include "tFilaDup.h"

typedef struct cell
{
    float valor;

    struct cell* ant;
    struct cell* prox;
} tCell;

struct FilaDup
{
    tCell* ini;
    tCell* fim;
};

void insereFilaDup(tFilaDup* fila, float amostra)
{
    tCell* new = malloc (sizeof(tCell));

    new->valor = amostra;

    new->ant = NULL;
    new->prox = fila->ini;

    if (fila->ini != NULL)
    {
        fila->ini->ant = new;
    }
    else
    {
        fila->fim = new;
    }

    fila->ini = new;
}

float retiraFilaDup(tFilaDup* fila)
{
    if (fila->ini == NULL)
    {
        printf("Fila vazia!\n");
        exit(1);
    }

    tCell* aux = fila->fim;

    float retirado = aux->valor;

    fila->fim = aux->ant;
    
    if (fila->fim == NULL)
    {
        fila->ini = NULL;
    }
    else
    {
        fila->fim->prox = NULL;
    }

    free (aux);

    return retirado;
}
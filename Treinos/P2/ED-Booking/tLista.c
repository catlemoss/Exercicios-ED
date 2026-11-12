#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"

typedef struct celula tCelula;
struct celula
{
    Reserva* reserva;

    struct celula* ant;
    struct celula* prox;
};

struct lista
{
    tCelula* ini;
    tCelula* fim;
};

tLista* criaLista()
{
    tLista* lista = malloc (sizeof(tLista));

    lista->ini = malloc (sizeof(tCelula));

    lista->ini->ant = NULL;
    lista->ini->prox = NULL;
    lista->ini->reserva = NULL;

    lista->fim = lista->ini;

    return lista;
}

void imprimeLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        imprimeReserva(atual->reserva);

        atual = atual->prox;
    }
}

void liberaLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        tCelula* depois = atual->prox;
        free (atual);

        atual = depois;
    }

    free (lista->ini);
    free (lista);
}

void insereLista(tLista* lista, Reserva* reserva)
{
    tCelula* newCell = malloc (sizeof(tCelula));

    newCell->reserva = reserva;

    newCell->ant = lista->fim;
    newCell->prox = NULL;

    lista->fim->prox = newCell;
    lista->fim = newCell;
}

void retiraLista(tLista* lista, Reserva* reserva)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->reserva == reserva) break;

        atual = atual->prox;
    }
    if (atual == NULL) return;

    atual->ant->prox = atual->prox;

    if (atual->prox != NULL)
    {
        atual->prox->ant = atual->ant;
    }
    else
    {
        lista->fim = atual->ant;
    }

    free (atual);
}
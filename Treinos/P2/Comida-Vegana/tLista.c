#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "ComidaVegana.h"
#include "ComidaNaoVegana.h"

#define MAX_STRING 10
#define veg 0
#define notveg 1

typedef struct celula tCelula;
struct celula
{
    void* info;             // comidas
    int tipo;               // veg or not

    struct celula* ant;     // antes de mim
    struct celula* prox;    // depois de mim
};

struct lista
{
    tCelula* ini;
    tCelula* fim;
};

tLista* criaLista()
{
    tLista* lista = malloc (sizeof(tLista));

    lista->ini = malloc (sizeof(tCelula));  // nossa sensei sentinela

    lista->ini->info = NULL;
    lista->ini->ant = NULL;
    lista->ini->prox = NULL;

    lista->fim = lista->ini;

    return lista;
}

void insereLista(tLista* lista, void* info, int tipo)
{
    tCelula* newCell = malloc (sizeof(tCelula));

    newCell->info = info;
    newCell->tipo = tipo;

    newCell->prox = NULL;
    newCell->ant = lista->fim;

    lista->fim->prox = newCell;
    lista->fim = newCell;
}

void imprimeLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->tipo == veg)
        {
            imprimeComidaVegana((ComidaVegana*) atual->info);
        }

        else if (atual->tipo == notveg)
        {
            imprimeComidaNaoVegana((ComidaNaoVegana*) atual->info);
        }

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

    free (lista->ini);      // libera a sensei sentinela
    free (lista);
}

int retiraLista(tLista* lista, void* comida)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->info == comida) break;

        atual = atual->prox;
    }
    if (atual == NULL) return 0;

    atual->ant->prox = atual->prox;

    // ultima bolacha do pacote...
    if (atual->prox != NULL)
    {
        atual->prox->ant = atual->ant;
    }
    else
    {
        lista->fim = atual->ant;
    }

    free (atual);

    return 1;
}

int getNumElementosLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;
    int contador = 0;

    while (atual != NULL)
    {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

float calculaValorLista(tLista* lista)
{
    float total = 0.0;

    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->tipo == veg)
        {
            total += 30.0;
        }

        else if (atual->tipo == notveg)
        {
            total += retornaValorComidaNaoVegana((ComidaNaoVegana*) atual->info);
        }

        atual = atual->prox;
    }

    return total;
}
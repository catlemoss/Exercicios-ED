#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "tGato.h"
#include "tCao.h"

enum
{
    MANSO, BRAVO
};

enum
{
    GATO, CAO
};

typedef struct cell tCell;
struct cell
{
    void* info;
    int tipo;

    struct cell* ant;
    struct cell* prox;
};

struct lista
{
    tCell* ini;
    tCell* fim;
};

tLista* criaLista()
{
    tLista* lista = malloc (sizeof(tLista));

    lista->ini = malloc (sizeof(tCell));

    lista->ini->info = NULL;
    lista->ini->tipo = -1;

    lista->ini->ant = NULL;
    lista->ini->prox = NULL;

    lista->fim = lista->ini;

    return lista;
}

void liberaLista(tLista* lista)
{
    tCell* atual = lista->ini->prox;

    while (atual != NULL)
    {
        tCell* depois = atual->prox;

        free (atual);

        atual = depois;
    }

    free (lista->ini);
    free (lista);
}

void imprimeLista(FILE* saida, tLista* lista)
{
    tCell* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->tipo == GATO)
        {
            imprimeGato(saida, (tGato*) atual->info);
        }
        else if (atual->tipo == CAO)
        {
            imprimeCachorro(saida, (tCao*) atual->info);
        }

        atual = atual->prox;
    }
}

void insereLista(tLista* lista, void* info, int tipo)
{
    tCell* newCell = malloc (sizeof(tCell));

    newCell->info = info;
    newCell->tipo = tipo;

    newCell->ant = lista->fim;
    newCell->prox = NULL;

    lista->fim->prox = newCell;
    lista->fim = newCell;
}

int retiraLista(tLista* lista, char* nome)
{
    tCell* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->tipo == GATO)
        {
            if (strcmp(getNomeGato((tGato*) atual->info), nome) == 0)
            {
                break;
            }
        }
        else if (atual->tipo == CAO)
        {
            if (strcmp(getNomeCachorro((tCao*) atual->info), nome) == 0)
            {
                break;
            }
        }

        atual = atual->prox;
    }
    if (atual == NULL) return 0;

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

    return 1;
}

float calculaValor(tLista* lista)
{
    tCell* atual = lista->ini->prox;
    int contaG = 0;
    int contaC = 0;

    while (atual != NULL)
    {
        if (atual->tipo == GATO)
        {
            if (getAgressividadeGato((tGato*) atual->info) == BRAVO)
            {
                contaG += 35;
            }
            else contaG += 30;
        }

        else if (atual->tipo == CAO)
        {
            if (getAgressividadeCachorro((tCao*) atual->info) == BRAVO)
            {
                contaC += 45;
            }
            else contaC += 40;
        }

        atual = atual->prox;
    }

    return contaG + contaC;
}
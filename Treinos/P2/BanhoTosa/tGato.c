#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tGato.h"

enum {
    MANSO, BRAVO
};

struct gato
{
    char* nome;
    int agressividade;
};

tGato* inicGato(char* nome, int agressividade)
{
    tGato* gato = malloc (sizeof(tGato));

    gato->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(gato->nome, nome);

    gato->agressividade = agressividade;

    return gato;
}

void liberaGato(tGato* gato)
{
    free (gato->nome);
    free (gato);
}

void imprimeGato(FILE* saida, tGato* gato)
{
    fprintf(saida, "NOME: %s --- ", gato->nome);
    fprintf(saida, "BRAVO? : ");

    if (gato->agressividade == BRAVO) fprintf(saida, "Sim");
    else fprintf(saida, "Nao");

    fprintf(saida, "\n");
}

void atribuiNivelAgressividadeGato(tGato* nome, int agressividade)
{
    nome->agressividade = agressividade;
}

char* getNomeGato(tGato* gato)
{
    return gato->nome;
}

int getAgressividadeGato(tGato* gato)
{
    return gato->agressividade;
}
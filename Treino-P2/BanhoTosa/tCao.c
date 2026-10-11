#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tCao.h"

enum {
    MANSO, BRAVO
};

struct cao
{
    char* nome;
    int agressividade;
};

tCao* inicCachorro(char* nome, int agressividade)
{
    tCao* cao = malloc (sizeof(tCao));

    cao->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(cao->nome, nome);

    cao->agressividade = agressividade;

    return cao;
}

void liberaCachorro(tCao* cao)
{
    free (cao->nome);
    free (cao);
}

void imprimeCachorro(FILE* saida, tCao* cao)
{
    fprintf(saida, "NOME: %s --- ", cao->nome);
    fprintf(saida, "BRAVO? : ");

    if (cao->agressividade == BRAVO) fprintf(saida, "Sim");
    else fprintf(saida, "Nao");

    fprintf(saida, "\n");
}

void atribuiNivelAgressividadeCachorro(tCao* nome, int agressividade)
{
    nome->agressividade = agressividade;
}

char* getNomeCachorro(tCao* cao)
{
    return cao->nome;
}

int getAgressividadeCachorro(tCao* cao)
{
    return cao->agressividade;
}
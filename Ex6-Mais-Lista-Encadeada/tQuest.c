#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tQuest.h"

struct questao
{
    int id;
    char* enunciado;
};

tQuest* criaQuest(int id, char* enunciado)
{
    tQuest* questao = malloc (sizeof(tQuest));

    questao->id = id;

    questao->enunciado = malloc ((strlen(enunciado)+1) * sizeof(char));
    strcpy(questao->enunciado, enunciado);

    return questao;
}

void liberaQuest(tQuest* questao)
{
    free (questao->enunciado);
    free (questao);
}

void imprimeQuest(FILE* saida, tQuest* questao)
{
    fprintf(saida, "ID: Q%d, Enunciado: %s\n", questao->id, questao->enunciado);
}

int getId(tQuest* questao)
{
    return questao->id;
}

char* getEnunciado(tQuest* questao)
{
    return questao->enunciado;
}
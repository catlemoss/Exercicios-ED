#ifndef QUEST_H
#define QUEST_H

#include <stdio.h>

typedef struct questao tQuest;

tQuest* criaQuest(int id, char* enunciado);
void liberaQuest(tQuest* questao);
void imprimeQuest(FILE* saida, tQuest* questao);

int getId(tQuest* questao);
char* getEnunciado(tQuest* questao);

#endif
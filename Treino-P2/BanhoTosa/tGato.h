#ifndef GATO_H
#define GATO_H

#include <stdio.h>

typedef struct gato tGato;

tGato* inicGato(char* nome, int agressividade);
void liberaGato(tGato* gato);
void imprimeGato(FILE* saida, tGato* gato);

void atribuiNivelAgressividadeGato(tGato* nome, int agressividade);

char* getNomeGato(tGato* gato);
int getAgressividadeGato(tGato* gato);

#endif
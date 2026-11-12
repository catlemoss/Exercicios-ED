#ifndef CAO_H
#define CAO_H

#include <stdio.h>

typedef struct cao tCao;

tCao* inicCachorro(char* nome, int agressividade);
void liberaCachorro(tCao* cao);
void imprimeCachorro(FILE* saida, tCao* cao);

void atribuiNivelAgressividadeCachorro(tCao* nome, int agressividade);

char* getNomeCachorro(tCao* cao);
int getAgressividadeCachorro(tCao* cao);

#endif
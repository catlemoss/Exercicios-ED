#ifndef INFO_H
#define INFO_H

#include <stdio.h>

typedef struct info tInfo;

tInfo* criaInfo(int latitude, int longitude, float temperatura);
void liberaInfo(tInfo* info);
void imprimeInfo(FILE* saida, tInfo* info);

int getLat(tInfo* info);
int getLong(tInfo* info);
float getTemp(tInfo* info);

#endif
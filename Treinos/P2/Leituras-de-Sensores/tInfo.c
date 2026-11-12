#include <stdio.h>
#include <stdlib.h>

#include "tInfo.h"

struct info
{
    int latitude;
    int longitude;
    float temperatura;
};

tInfo* criaInfo(int latitude, int longitude, float temperatura)
{
    tInfo* info = malloc (sizeof(tInfo));

    info->latitude = latitude;
    info->longitude = longitude;
    info->temperatura = temperatura;

    return info;
}

void liberaInfo(tInfo* info)
{
    free (info);
}

void imprimeInfo(FILE* saida, tInfo* info)
{
    fprintf(saida, "%d %d %.2f\n", info->latitude, info->longitude, info->temperatura);
}

int getLat(tInfo* info)
{
    return info->latitude;
}

int getLong(tInfo* info)
{
    return info->longitude;
}

float getTemp(tInfo* info)
{
    return info->temperatura;
}
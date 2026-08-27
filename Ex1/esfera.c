/*
Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r.
A área da superfície e o volume são dados, respectivamente, por 4pir² e 4pir³ / 3.
*/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265359

typedef struct
{
    float r, area, volume;
} tEsfera;

void calc_esfera (float r, float* area, float* volume)
{
    *area = 4.0 * PI * r*r;
    *volume = (4.0 * PI * r*r*r) / 3.0;
}

int main ()
{
    tEsfera *esfera = calloc (1, sizeof(tEsfera));
    scanf("%f\n", &esfera->r);

    calc_esfera (esfera->r, &esfera->area, &esfera->volume);

    printf("Area: %.2f\n", esfera->area);
    printf("Volume: %.2f\n", esfera->volume);

    free (esfera);
}
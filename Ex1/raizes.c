/*
Implemente uma função que calcule as raízes de uma equação do segundo grau, do tipo ax2
+ bx + c = 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float a, b, c;
} tEquacao;

int raizes (float a, float b, float c, float* x1, float* x2)
{
    float delta = (b*b) - 4.0 * a * c;

    if (delta < 0) return 0;

    *x1 = ((b*-1) + sqrt(delta)) / 2.0 * a;
    *x2 = ((b*-1) - sqrt(delta)) / 2.0 * a;

    return 1;
}

int main ()
{
    tEquacao *eq = calloc (1, sizeof(tEquacao));
    scanf("%f %f %f\n", &eq->a, &eq->b, &eq->c);

    float *x1 = calloc (1, sizeof(float));
    float *x2 = calloc (1, sizeof(float));

    if (!raizes(eq->a, eq->b, eq->c, x1, x2)) return 0;

    printf("X1: %.2f\n", *x1);
    printf("X2: %.2f\n", *x2);

    free (eq);
    
    return 0;
}
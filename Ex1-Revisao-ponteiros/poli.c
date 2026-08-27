/*
Implemente uma função que permita a avaliação de polinômios. Cada polinômio é definido por
um vetor que contém seus coeficientes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double avalia (double* poli, int grau, double x)
{
    double result = 0.0;
    for (int i = 0; i <= grau; i++)
    {
        result += poli[i] * pow(x, i); 
    }

    return result;
}

int main ()
{
    printf("Qual o grau?\n");
    int grau;
    scanf("%d\n", &grau);

    double *poli = malloc (grau * sizeof(int));
    for (int i = 0; i <= grau; i++)
    {
        scanf("%lf", &poli[i]);
    }

    printf("Qual o valor de x?\n");
    double x;
    scanf("%lf", &x);

    double result = avalia (poli, grau, x);
    printf("O polinomio tem resultado = %.2lf\n", result);

    free (poli);
    return 0;
}
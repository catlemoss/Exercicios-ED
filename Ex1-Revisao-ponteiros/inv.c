/*
Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de
tamanho n e inverta a ordem dos elementos armazenados nesse mesmo vetor.
*/

#include <stdio.h>
#include <stdlib.h>

void inverte (int n, int* vet)
{
    int aux;

    for (int i = 0; i < n / 2; i++)
    {
        aux = vet[i];
        vet[i] = vet[n-i-1];
        vet[n-i-1] = aux;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

int main ()
{
    int n;
    scanf("%d\n", &n);

    int *vet = malloc (n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }

    inverte (n, vet);

    free (vet);
    return 0;
}
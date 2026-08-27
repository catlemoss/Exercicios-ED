/*
Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de
tamanho n e retorne quantos números pares estão armazenados nesse vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int pares (int n, int* vet)
{
    int contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] % 2 == 0) contador++;
    }

    return contador;
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

    int nPares = pares (n, vet);
    printf("Tem %d pares.\n", nPares);

    free (vet);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#include "tFila.h"
#include "amostra.h"

#define MAX_ELEM 100

/*
    processo de inserção e remoção em extremidades opostas
    da fila faz com que a fila “ande” no vetor
*/

struct fila
{
    int nElemFila;
    int proxRetirado;           // inicio da fila

    Amostra* amostras[MAX_ELEM];
};

tFila* criaFila(void)
{
    tFila* fila = malloc (sizeof(tFila));

    fila->nElemFila = 0;
    fila->proxRetirado = 0;

    return fila;
}

void insereFila(tFila* fila, Amostra* amostra)
{
    int fim;

    if (fila->nElemFila == MAX_ELEM)
    {
        printf("A fila esta cheia!\n");
        exit(1);
    }

    if (retornaIdade(amostra) >= 60)
    {
        // andamos uma posicao para tras
        fila->proxRetirado = (fila->proxRetirado -1 +MAX_ELEM) % MAX_ELEM;

        fim = fila->proxRetirado;
    }

    else
    {
        fim = (fila->proxRetirado + fila->nElemFila) % MAX_ELEM;
    }

    fila->amostras[fim] = amostra;
    fila->nElemFila++;
}

Amostra* retiraFila (tFila* fila)
{
    Amostra* amostra;

    if (estaVaziaFila(fila))
    {
        printf("A fila esta vazia!!\n");
        exit(1);
    }

    // vamos tirar o elemento do inicio da fila
    amostra = fila->amostras[fila->proxRetirado];
    fila->amostras[fila->proxRetirado] = NULL;

    fila->proxRetirado = (fila->proxRetirado +1) % MAX_ELEM;
    fila->nElemFila--;

    return amostra;
}

int estaVaziaFila(tFila* fila)
{
    return fila->nElemFila == 0;
}

void liberaFila(tFila* fila)
{
    for (int i = 0; i < fila->nElemFila; i++)
    {
        int pos = (fila->proxRetirado + i) % MAX_ELEM;
        liberaAmostra(fila->amostras[pos]);
    }

    free (fila);
}

void imprimeFila(tFila* fila)
{
    for (int i = 0; i < fila->nElemFila; i++)
    {
        int pos = (fila->proxRetirado + i) % MAX_ELEM;
        imprimeAmostra(fila->amostras[pos]);
    }

    printf("\n");
}

int getNElemFila(tFila* fila)
{
    return fila->nElemFila;
}

/*
Amostra* getAmostra(tFila* fila, int i)
{
    if (i < 0 || i >= fila->nElemFila)
        return NULL;

    int pos = (fila->proxRetirado + i) % MAX_ELEM;

    return fila->amostras[pos];
}
*/
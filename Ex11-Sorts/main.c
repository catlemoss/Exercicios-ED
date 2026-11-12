#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functs.h"

#define MAX_VET 100000
#define MAX_BUSCAS 100000

int main ()
{
    // aqui fixa os numeros aleatorios gerados pelo rand
    srand(time(NULL));

    // ======= CRIA VETOR =======
    int* origin = malloc (MAX_VET * sizeof(int));   
    int* copy = malloc (MAX_VET * sizeof(int));

    for (int i = 0; i < MAX_VET; i++)
    {
        origin[i] = rand();
    }

    /* 
    // ======= ORIGINAL =======
    printf("Vetor Origin:\n");
    imprimeVet(origin, MAX_VET);
    */


    // ======= TEMPO =======
    clock_t inicio, fim;
    double tempo;

    // ======= BUBBLE =======
    //printf("Bubble:\n");
    copyVet(copy, origin, MAX_VET);

    inicio = clock();
        bubbleSort(copy, MAX_VET);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Bubble: %.6f s\n", tempo);
    //imprimeVet(copy, MAX_VET);


    // ======= QUICK =======
    //printf("Quick:\n");
    copyVet(copy, origin, MAX_VET);

    inicio = clock();
        quickSort(copy, MAX_VET);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Quick: %.6f s\n", tempo);
    //imprimeVet(copy, MAX_VET);

    // ======= QSORT =======
    //printf("qSort:\n");
    copyVet(copy, origin, MAX_VET);

    inicio = clock();
        qsort(copy, MAX_VET, sizeof(int), comparaInt);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo qSort: %.6f s\n", tempo);
    //imprimeVet(copy, MAX_VET);


    // ======= BUSCA LIN =======
    volatile int pos;

    inicio = clock();

    // uma busca so nao mostrou tempo direito, ent pq nao 100 000 buscas?
    // estamos buscando -1 para obrigar o for a rodar o vetor inteiro ja q nn existe, bem mais easy
    for (int i = 0; i < MAX_BUSCAS; i++)
    {
        pos = buscaLinear(copy, MAX_VET, -1);
    }
    fim = clock();

    printf("Tempo Linear: %.6f s\n",
    (double)(fim - inicio) / CLOCKS_PER_SEC);


    // ======= BUSCA BIN =======
    inicio = clock();
    for (int i = 0; i < MAX_BUSCAS; i++)
    {
        pos = buscaBin(copy, MAX_VET, -1);
    }
    fim = clock();

    printf("Tempo Binaria: %.6f s\n",
    (double)(fim - inicio) / CLOCKS_PER_SEC);


    // ======= BSHEARCH =======
    int elem = -1;
    volatile int encontrados = 0;

    inicio = clock();
    for (int i = 0; i < 100000; i++)
    {
        if (bsearch(&elem, copy, MAX_VET, sizeof(int), comparaInt) != NULL) encontrados++;
    }
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo bSearch: %.6f s\n", tempo);

    free (origin);
    free (copy);

    return 0;
}
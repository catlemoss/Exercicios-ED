#include <stdio.h>
#include <stdlib.h>

#include "functs.h"

/*
Melhor e pior caso = O(n²)
Tem dois laços aninhados
*/
void bubbleSort(int* vet, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (vet[j] > vet[j+1])
            {
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

/*
Melhor caso = O(n log n)
Pior caso = O(n²)
Tem divisao recursiva do vetor.
No melhor caso ficam partes meio iguais.
No pior caso as partes ficam estranhas e desiguais.
*/
void quickSort(int* vet, int n)
{
    if (n <= 1) return;         // condição de parada

    else
    {
        int pivo = vet[0];
        int a = 1;              // start na esquerda e goes to direita
        int b = n-1;            // começa na right and vai para left

        do {
            // a procura alguem maior q o pivo
            while (a < n && vet[a] <= pivo) a++;

            // b procura alguem menor ou igual ao pivo
            while (vet[b] > pivo) b--;

            // troca
            if (a < b)
            {
                int aux = vet[a];
                vet[a] = vet[b];
                vet[b] = aux;

                a++; b--;
            }

        } while (a <= b);

        // coloca o pivo no lugar certo
        vet[0] = vet[b];
        vet[b] = pivo;
        
        // ordena o antes e depois do pivo
        quickSort(vet, b);
        quickSort(&vet[a], n-a);
    }
}

/*
Melhor caso = O(1)
Pior caso = O(n)
Pode acabar tendo q percorrer todo o vetor
*/
int buscaLinear(int* vet, int n, int elem)
{
    for (int i = 0; i < n; i++)
    {
        // achamos yey, retorna a pos
        if (elem == vet[i]) return i;
    }

    return -1;
}

/*
Melhor caso = O(1)
Pior caso = O(log n)
Elimina metade das posicoes a cada rodada
So funciona se o vetor estiver ordenado.
*/
int buscaBin(int* vet, int n, int elem)
{
    int ini = 0;
    int fim = n-1;
    int meio;

    // enquanto a parte restante for maior que zero
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;

        if (elem < vet[meio])
        {
            fim = meio - 1;             // ajusta a ultima pos
        }

        else if (elem > vet[meio])
        {
            ini = meio + 1;             // ajusta primeira pos
        }

        else
        {
            return meio;                // achamos yey
        }
    }
    
    return -1;
}

/*
Melhor caso = O(n)
Pior caso = O(n)
Pra nao ficar repetindo isso o tempo todo
*/
void copyVet(int* copia, int* vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        copia[i] = vet[i];
    }
}

/*
Melhor caso = O(n)
Pior caso = O(n)
Impressao minha ou sua?
*/
void imprimeVet(int* vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n\n");
}

/*
Melhor caso = O(1)
Pior caso = O(1)
Num constante de comparacoes.
Pelo q eu entendi o qsort e o bsearch PRECISAM de funcao generica afs
*/
int comparaInt(const void* a, const void* b)
{
    const int* A = a;
    const int* B = b;

    if (*A < *B) return -1;
    else if (*A > *B) return 1;
    else return 0;
}
/*
Implemente uma função que receba um vetor de inteiros (vet) de tamanho n. Essa função deve
alocar dinamicamente um outro vetor também de tamanho n que contenha os endereços dos
valores do vetor de inteiros de forma ordenada crescente, ficando a primeira posição do vetor de
ponteiros o endereço do menor valor até a última posição, que conterá o endereço do maior valor.
*/

#include <stdio.h>
#include <stdlib.h>

int** inverte2 (int n, int* vet)
{
    int **vetDoVet = malloc (n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        vetDoVet[i] = &vet[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (*vetDoVet[j] > *vetDoVet[j+1])
            {
                int *aux = vetDoVet[j];
                vetDoVet[j] = vetDoVet[j+1];
                vetDoVet[j+1] = aux;
            }
        }
    }

    return vetDoVet;
}

int main ()
{
    printf("Quantos numeros?\n");
    int n;
    scanf("%d\n", &n);

    printf("Insira seus numeros:\t");
    int *vet = malloc (n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet[i]);
    }
    
    int **vetDoVet = inverte2 (n, vet);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *vetDoVet[i]);
    }
    
    free (vetDoVet);
    free (vet);
    return 0;
}
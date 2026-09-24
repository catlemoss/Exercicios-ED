/*
    Lista simplesmente encadeada com sentinela de Estudantes.
    24/09/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#define MAX_STRING 20

int main ()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int nAlunos;
    fscanf(entrada, "%d", &nAlunos);

    tLista* lista = criaLista();

    for (int i = 0; i < nAlunos; i++)
    {
        int matricula;
        char* nome = malloc (MAX_STRING * sizeof(char));
        float cr;

        fscanf(entrada, "%d %s %f", &matricula, nome, &cr);

        tAluno* aluno = criaAluno(matricula, nome, cr);
        insereAluno(lista, aluno);

        free (nome);
    }

    imprimeLista(saida, lista);
    fprintf(saida, "Media: %.2f\n", calculaMedia(lista));

    int matricula;
    while (fscanf(entrada, "%d", &matricula) != EOF)
    {
        fprintf(saida, "================\n");

        retiraAluno(lista, matricula);

        imprimeLista(saida, lista);
        fprintf(saida, "Media: %.2f\n", calculaMedia(lista));
    }

    fclose(entrada);
    fclose(saida);

    liberaLista(lista);

    return 0;
}
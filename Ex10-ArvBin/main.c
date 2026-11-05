/*
    Implemente um TAD ABB de alunos (criação, inserção, busca, retirada, liberação e altura).
    Escolha a chave de busca (matrícula? nome? sua escolha...)
*/

#include <stdio.h>
#include <stdlib.h>

#include "tAbb.h"

#define MAX_NOME 20

int main ()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    tAbb* arvore = criaArv();

    int nAlunos;
    fscanf(entrada, "%d", &nAlunos);

    int mat;
    char* nome = malloc (MAX_NOME * sizeof(char));

    for (int i = 0; i < nAlunos; i++)
    {
        fscanf(entrada, "%d %19s", &mat, nome);

        tAluno* aluno = criaAluno(mat, nome);
        arvore = insereArv(arvore, aluno);
    }
    free (nome);

    // arvore com tudo
    fprintf(saida, "Arvore Inicial (altura %d)\n", alturaArv(arvore));
    imprimeArv(saida, arvore);
    fprintf(saida, "\n");

    while (fscanf(entrada, "%d", &mat) == 1)
    {
        tAluno* aluno = buscaArv(arvore, mat);

        if (aluno != NULL)
        {
            arvore = retiraArv(arvore, aluno);
        }
    }

    fprintf(saida, "Arvore Final (altura %d)\n", alturaArv(arvore));
    imprimeArv(saida, arvore);
    fprintf(saida, "\n");

    // set me free
    arvore = liberaArv(arvore);

    fclose(entrada);
    fclose(saida);

    return 0;
}
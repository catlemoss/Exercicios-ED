#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tAluno.h"

struct aluno
{
    char* nome;
    int mat;
};

tAluno* criaAluno(int mat, char* nome)
{
    tAluno* aluno = malloc (sizeof(tAluno));

    aluno->mat = mat;

    aluno->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(aluno->nome, nome);

    return aluno;
}

void liberaAluno(tAluno* aluno)
{
    free (aluno->nome);
    free (aluno);
}

void imprimeAluno(FILE* saida, tAluno* aluno)
{
    fprintf(saida, "%s", aluno->nome);
}

char* getNomeAluno(tAluno* aluno)
{
    return aluno->nome;
}

int getMatriculaAluno(tAluno* aluno)
{
    return aluno->mat;
}
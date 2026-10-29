#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tAluno.h"

struct aluno
{
    char* nome;
    int mat;
    float cr;
};

tAluno* criaAluno(char* nome, int mat, float cr)
{
    tAluno* aluno = malloc (sizeof(tAluno));

    aluno->mat = mat;
    aluno->cr = cr;

    aluno->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(aluno->nome, nome);

    return aluno;
}

void liberaAluno(tAluno* aluno)
{
    free (aluno->nome);
    free (aluno);
}

void imprimeAluno(tAluno* aluno)
{
    printf("%s", aluno->nome);
}

char* getNomeAluno(tAluno* aluno)
{
    return aluno->nome;
}

int getMatriculaAluno(tAluno* aluno)
{
    return aluno->mat;
}

float getCrAluno(tAluno* aluno)
{
    return aluno->cr;
}
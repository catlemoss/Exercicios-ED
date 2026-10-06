#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tAluno.h"

struct aluno
{
    char* nome;
    int cpf;
    float cr;
};

tAluno* criaAluno(char* nome, int cpf, float cr)
{
    tAluno* aluno = malloc (sizeof(tAluno));

    aluno->cpf = cpf;
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

void imprimeAluno(FILE* saida, tAluno* aluno)
{
    fprintf(saida, "%s, CPF: %d e CR: %.2f\n", aluno->nome, aluno->cpf, aluno->cr);
}

char* getNomeAluno(tAluno* aluno)
{
    return aluno->nome;
}

int getCpfAluno(tAluno* aluno)
{
    return aluno->cpf;
}

float getCrAluno(tAluno* aluno)
{
    return aluno->cr;
}
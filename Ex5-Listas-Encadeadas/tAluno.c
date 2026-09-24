#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tAluno.h"

struct aluno
{
    int matricula;
    char* nome;
    float cr;
};

tAluno* criaAluno(int matricula, char *nome, float cr)
{
    tAluno* aluno = malloc (sizeof(tAluno));

    aluno->matricula = matricula;
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
    fprintf(saida, "%d %s %.1f\n", aluno->matricula, aluno->nome, aluno->cr);
}

int getMatricula(tAluno* aluno)
{
    return aluno->matricula;
}
char* getNome(tAluno* aluno)
{
    return aluno->nome;
}
float getCr(tAluno* aluno)
{
    return aluno->cr;
}

void setMatricula(tAluno* aluno, int matricula)
{
    aluno->matricula = matricula;
}
void setNome(tAluno* aluno, char* nome)
{
    free (aluno->nome);

    int letras = strlen(nome) +1;
    aluno->nome = malloc (letras * sizeof(char));
    strcpy(aluno->nome, nome);
}
void setCr(tAluno* aluno, float cr)
{
    aluno->cr = cr;
}
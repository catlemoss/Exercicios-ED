#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tAluno.h"

struct aluno
{
    int matricula;
    char* nome;
};

tAluno* criaAluno(char *nome, int matricula)
{
    tAluno* aluno = malloc (sizeof(tAluno));

    aluno->matricula = matricula;

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
    printf("  %d %s\n", aluno->matricula, aluno->nome);
}

int getMatricula(tAluno* aluno)
{
    return aluno->matricula;
}
char* getNome(tAluno* aluno)
{
    return aluno->nome;
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
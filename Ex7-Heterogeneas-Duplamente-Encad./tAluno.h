#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>

typedef struct aluno tAluno;

tAluno* criaAluno(char* nome, int cpf, float cr);
void liberaAluno(tAluno* aluno);
void imprimeAluno(FILE* saida, tAluno* aluno);

char* getNomeAluno(tAluno* aluno);
int getCpfAluno(tAluno* aluno);
float getCrAluno(tAluno* aluno);

#endif
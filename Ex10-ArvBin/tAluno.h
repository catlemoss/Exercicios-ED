#ifndef ALUNO_H
#define ALUNO_H

#include <stdio.h>

typedef struct aluno tAluno;

tAluno* criaAluno(int mat, char* nome);
void liberaAluno(tAluno* aluno);
void imprimeAluno(FILE* saida, tAluno* aluno);

char* getNomeAluno(tAluno* aluno);
int getMatriculaAluno(tAluno* aluno);

#endif
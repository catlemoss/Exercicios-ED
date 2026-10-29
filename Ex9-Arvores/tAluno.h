#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno tAluno;

tAluno* criaAluno(char* nome, int mat, float cr);
void liberaAluno(tAluno* aluno);
void imprimeAluno(tAluno* aluno);

char* getNomeAluno(tAluno* aluno);
int getMatriculaAluno(tAluno* aluno);
float getCrAluno(tAluno* aluno);

#endif
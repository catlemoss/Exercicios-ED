#ifndef _Aluno_H
#define _Aluno_H

#include <stdio.h>

typedef struct aluno tAluno;

tAluno* criaAluno(int matricula, char *nome, float cr);
void liberaAluno(tAluno* aluno);
void imprimeAluno(FILE* saida, tAluno* aluno);

// retorna uma info
int getMatricula(tAluno* aluno);
char* getNome(tAluno* aluno);
float getCr(tAluno* aluno);

// muda uma info
void setMatricula(tAluno* aluno, int matricula);
void setNome(tAluno* aluno, char* nome);
void setCr(tAluno* aluno, float cr);

#endif
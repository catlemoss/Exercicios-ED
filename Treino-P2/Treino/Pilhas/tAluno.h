#ifndef _Aluno_H
#define _Aluno_H

typedef struct aluno tAluno;

tAluno* criaAluno(char* nome, int matricula);
void liberaAluno(tAluno* aluno);
void imprimeAluno(tAluno* aluno);

// retorna uma info
int getMatricula(tAluno* aluno);
char* getNome(tAluno* aluno);
float getCr(tAluno* aluno);

// muda uma info
void setMatricula(tAluno* aluno, int matricula);
void setNome(tAluno* aluno, char* nome);

#endif
#ifndef PROF_H
#define PROF_H

#include <stdio.h>

typedef struct prof tProf;

tProf* criaProf(char* nome, int cpf, float salario);
void liberaProf(tProf* prof);
void imprimeProf(FILE* saida, tProf* prof);

char* getNomeProf(tProf* prof);
int getCpfProf(tProf* prof);
float getSalarioProf(tProf* prof);

#endif
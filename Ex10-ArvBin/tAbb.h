#ifndef Abb_H
#define Abb_H

#include <stdio.h>

#include "tAluno.h"

typedef struct abb tAbb;

tAbb* criaArv();
tAbb* insereArv(tAbb* arv, tAluno* aluno);
tAbb* retiraArv(tAbb* arv, tAluno* aluno);
tAbb* liberaArv(tAbb* arv);

tAluno* buscaArv(tAbb* arv, int mat);

void imprimeArv(FILE* saida, tAbb* arv);

int alturaArv(tAbb* arv);

#endif
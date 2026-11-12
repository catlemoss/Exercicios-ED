#ifndef PDUPLA_H
#define PDUPLA_H

#include "tAluno.h"

typedef struct pdupla tPdupla;

//Inicializa a estrutura da Pdupla
tPdupla* inicPdupla();

//inclui no topo
void push1 (tPdupla* pdupla, tAluno* aluno);
void push2 (tPdupla* pdupla, tAluno* aluno);

//retira do topo
tAluno* pop1 (tPdupla* pdupla);
tAluno* pop2 (tPdupla* pdupla);

//imprime do topo para a base
void imprimePdupla(tPdupla* pdupla);

//Retorna 1 se Pdupla vazia e 0 caso contrário
int vazia (tPdupla* pdupla);

//Destroi a Pdupla para não os alunos...
void destroiPdupla(tPdupla* pdupla);

#endif
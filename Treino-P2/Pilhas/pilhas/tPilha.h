#ifndef PILHA_H
#define PILHA_H

#include "tAluno.h"

typedef struct pilha tPilha;

//Inicializa a estrutura da pilha
tPilha* inicPilha();

//inclui no topo
void push (tPilha* pilha, tAluno* aluno);

//retira do topo
tAluno* pop (tPilha* pilha);

//imprime do topo para a base
void imprimePilha(tPilha* pilha);

//Retorna 1 se pilha vazia e 0 caso contrário
int vazia (tPilha* pilha);

//Destroi a pilha para não os alunos...
void destroiPilha(tPilha* pilha);

#endif
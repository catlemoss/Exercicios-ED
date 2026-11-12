#include <stdio.h>
#include <stdlib.h>

#include "tPilha.h"

#define TAM 10                  //tamanho da pilha

struct pilha 
{
    int topo;                   //vai começar com 0 (na minha implementacao)
    tAluno* alunos[TAM];
};

//Inicializa a estrutura da pilha
tPilha* inicPilha()
{
    tPilha* pilha = malloc (sizeof(tPilha));

    pilha->topo = 0;            // proxima posicao livre do vetor

    return pilha;
}

//inclui no topo
void push (tPilha* pilha, tAluno* aluno)
{
    if (!pilha || pilha->topo >= TAM || !aluno)
    {
        printf("Pilha cheia ou aluno invalido!!!\n");
        return;
    }

    pilha->alunos[pilha->topo] = aluno;
    pilha->topo++;
}

//retira do topo
tAluno* pop (tPilha* pilha)
{
    if (vazia(pilha))
    {
        printf("A pilha esta vazia!\n");
        return NULL;
    }

    tAluno* retirado = pilha->alunos[pilha->topo-1];
    pilha->topo--;

    return retirado;
}

//imprime do topo para a base
void imprimePilha(tPilha* pilha)
{
    if (!pilha) return;

    for (int i = pilha->topo -1; i >= 0; i--)
    {
        imprimeAluno(pilha->alunos[i]);
    }

    printf("\n");
}

//Retorna 1 se pilha vazia e 0 caso contrário
int vazia (tPilha* pilha)
{
    return pilha->topo == 0;
}

//Destroi a pilha para não os alunos...
void destroiPilha(tPilha* pilha)
{
    if (!pilha) return;

    free (pilha);
}
#include <stdio.h>
#include <stdlib.h>

#include "tPdupla.h"

#define TAM 10                  //tamanho da pilha

typedef struct indiceP tindiceP;
struct indiceP
{
    int base;
    int topo;             // a posição do último elemento inserido naquela pilha
};

struct pdupla
{
    tAluno* alunos[TAM];

    tindiceP pilha1;
    tindiceP pilha2;
};

//Inicializa a estrutura da Pdupla
tPdupla* inicPdupla()
{
    tPdupla* dupla = malloc (sizeof(tPdupla));

    dupla->pilha1.base = 0;
    dupla->pilha1.topo = -1;

    dupla->pilha2.base = TAM -1;
    dupla->pilha2.topo = TAM;

    return dupla;
}

//inclui no topo
void push1(tPdupla* pdupla, tAluno* aluno)
{
    if (!pdupla || pdupla->pilha1.topo == pdupla->pilha2.topo -1 || !aluno)
    {
        printf("Pilha cheia ou aluno invalido!!!\n");
        return;
    }

    pdupla->pilha1.topo++;
    pdupla->alunos[pdupla->pilha1.topo] = aluno;
}

void push2(tPdupla* pdupla, tAluno* aluno)
{
    if (!pdupla || pdupla->pilha1.topo == pdupla->pilha2.topo -1 || !aluno)
    {
        printf("Pilha cheia ou aluno invalido!!!\n");
        return;
    }

    pdupla->pilha2.topo--;
    pdupla->alunos[pdupla->pilha2.topo] = aluno;
}

//retira do topo
tAluno* pop1(tPdupla* pdupla)
{
    if (!pdupla || pdupla->pilha1.topo == -1)
    {
        printf("A pilha esta vazia!\n");
        return NULL;
    }

    tAluno* retirado = pdupla->alunos[pdupla->pilha1.topo];
    pdupla->pilha1.topo--;

    return retirado;
}

tAluno* pop2(tPdupla* pdupla)
{
    if (!pdupla || pdupla->pilha2.topo == TAM)
    {
        printf("A pilha esta vazia!\n");
        return NULL;
    }

    tAluno* retirado = pdupla->alunos[pdupla->pilha2.topo];
    pdupla->pilha2.topo++;

    return retirado;
}

//imprime do topo para a base
void imprimePdupla(tPdupla* pdupla)
{
    if (!pdupla) return;

    printf("Pilha 1:\n");
    for (int i = pdupla->pilha1.topo; i >= pdupla->pilha1.base; i--)
    {
        imprimeAluno(pdupla->alunos[i]);
    }

    printf("\nPilha 2:\n");

    for (int i = pdupla->pilha2.topo; i <= pdupla->pilha2.base; i++)
    {
        imprimeAluno(pdupla->alunos[i]);
    }

    printf("\n");
}

//Retorna 1 se Pdupla vazia e 0 caso contrário
int vazia (tPdupla* pdupla)
{
    return pdupla->pilha1.topo == -1 && pdupla->pilha2.topo == TAM;
}

//Destroi a Pdupla para não os alunos...
void destroiPdupla(tPdupla* pdupla)
{
    if (!pdupla) return;

    free (pdupla);
}
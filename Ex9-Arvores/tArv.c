#include <stdio.h>
#include <stdlib.h>

#include "tArv.h"

struct arv
{
    tAluno* info;

    struct arv* esq;
    struct arv* dir;
};

//Cria uma árvore vazia
tArv* arv_criavazia (void)
{
    return NULL;
}

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e a subárvore direita
tArv* arv_cria (tAluno* aluno, tArv* esq, tArv* dir)
{
    tArv* arv = malloc (sizeof(tArv));

    arv->info = aluno;

    arv->esq = esq;
    arv->dir = dir;

    return arv;
}

//libera o espaço de memória ocupado pela árvore a
tArv* arv_libera (tArv* arv)
{
    if (!arv_vazia(arv))
    {
        arv_libera(arv->esq);
        arv_libera(arv->dir);

        liberaAluno(arv->info);
        
        free (arv);
    }

    return NULL;
}

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (tArv* arv)
{
    return arv == NULL;
}

// tem q tartar o retorno da recursividade

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (tArv* arv, int mat)
{
    if (arv_vazia(arv)) return 0;

    if (getMatriculaAluno(arv->info) == mat) return 1;

    return arv_pertence(arv->esq, mat) || arv_pertence(arv->dir, mat);
}

//imprime as informações dos nós da árvore <raiz e d> e <> (árvore vazia)
void arv_imprime (tArv* arv)
{
    printf("<");

    if (!arv_vazia(arv))
    {
        imprimeAluno(arv->info);
        arv_imprime(arv->esq);
        arv_imprime(arv->dir);
    }

    printf(">");
}

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
tArv* arv_pai (tArv* arv, int mat)
{
    if (arv_vazia(arv)) return NULL;

    if (!arv_vazia(arv->esq) && getMatriculaAluno(arv->esq->info) == mat)
    {
        return arv;
    }

    if (!arv_vazia(arv->dir) && getMatriculaAluno(arv->dir->info) == mat)
    {
        return arv;
    }

    tArv* pai = arv_pai(arv->esq, mat);

    if (pai != NULL) return pai;

    return arv_pai(arv->dir, mat);
}

//retorna a quantidade de folhas de uma arvore binaria
int folhas (tArv* arv)
{
    if (arv_vazia(arv)) return 0;

    if (arv_vazia(arv->esq) && arv_vazia(arv->dir)) return 1;

    return folhas(arv->esq) + folhas(arv->dir);
}

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (tArv* arv, int mat)
{
    if (arv_vazia(arv)) return 0;

    int conta = 0;

    if (getMatriculaAluno(arv->info) == mat) conta = 1;

    return conta + ocorrencias(arv->esq, mat) + ocorrencias(arv->dir, mat);
}
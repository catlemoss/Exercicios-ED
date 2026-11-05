#include <stdio.h>
#include <stdlib.h>

#include "tAbb.h"

struct abb
{
    tAluno* info;
    struct abb* esq;
    struct abb* dir;
};

tAbb* criaArv()
{
    return NULL;
}

tAbb* insereArv(tAbb* arv, tAluno* aluno)
{
    if (arv == NULL)
    {
        arv = malloc (sizeof (tAbb));

        arv->info = aluno;

        arv->esq = NULL;
        arv->dir = NULL;
    }

    else if (getMatriculaAluno(aluno) < getMatriculaAluno(arv->info))
    {
        arv->esq = insereArv(arv->esq, aluno);
    }

    else arv->dir = insereArv(arv->dir, aluno);

    return arv;
}

tAluno* buscaArv(tAbb* arv, int mat)
{
    if (arv == NULL) return NULL;

    if (getMatriculaAluno(arv->info) > mat)
    {
        return buscaArv(arv->esq, mat);
    }
    else if (getMatriculaAluno(arv->info) < mat)
    {
        return buscaArv(arv->dir, mat);
    }

    return arv->info;
}

tAbb* retiraArv(tAbb* arv, tAluno* aluno)
{   
    if (arv == NULL || aluno == NULL) return arv;

    if (getMatriculaAluno(arv->info) > getMatriculaAluno(aluno))
    {
        arv->esq = retiraArv(arv->esq, aluno);
    }

    else if (getMatriculaAluno(arv->info) < getMatriculaAluno(aluno))
    {
        arv->dir = retiraArv(arv->dir, aluno);
    }

    // achamos o no
    else
    {
        // no sem filhos
        if (arv->esq == NULL && arv->dir == NULL)
        {
            liberaAluno(arv->info);
            free (arv);
            return NULL;
        }

        // um filho na direita
        else if (arv->esq == NULL)
        {
            tAbb* aux = arv->dir;
            
            liberaAluno(arv->info);
            free (arv);

            return aux;
        }

        // um filho na esquerda
        else if (arv->dir == NULL)
        {
            tAbb* aux = arv;
            arv = arv->esq;
            free (aux);
        }

        // no tem two kids
        else
        {
            tAbb* aux = arv->esq;

            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }

            tAluno* antigo = arv->info;

            arv->info = aux->info;
            aux->info = antigo;

            arv->esq = retiraArv(arv->esq, antigo);
        }
    }

    return arv;
}

tAbb* liberaArv(tAbb* arv)
{
    if (arv != NULL)
    {
        liberaArv(arv->esq);
        liberaArv(arv->dir);

        liberaAluno(arv->info);
        free (arv);
    }

    return NULL;
}

void imprimeArv(FILE* saida, tAbb* arv)
{
    fprintf(saida, "<");

    if (arv != NULL)
    {
        imprimeAluno(saida, arv->info);

        imprimeArv(saida, arv->esq);
        imprimeArv(saida, arv->dir);
    }

    fprintf(saida, ">");
}

int alturaArv(tAbb* arv)
{
    if (arv == NULL) return -1;

    int esq = alturaArv(arv->esq);
    int dir = alturaArv(arv->dir);

    if (esq > dir) return esq + 1;
    else return dir + 1; 
}
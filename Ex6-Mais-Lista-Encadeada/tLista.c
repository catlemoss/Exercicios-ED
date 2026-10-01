#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"

// uma celula guarda uma info e o endereço da proxima celula
// é uma caixinha
typedef struct celula tCelula;
struct celula
{
    tQuest* questao;
    struct celula* prox;
};

struct lista
{
    tCelula* ini;
    tCelula* fim;
};

tLista* criaLista()
{
    tLista* lista = malloc (sizeof(tLista));

    lista->ini = malloc(sizeof(tCelula));       
    // nossa sentinela e a sua celula

    lista->ini->questao = NULL;
    lista->ini->prox = NULL;                    
    // nosso primeiro questao real

    lista->fim = lista->ini;                    
    // a sentinela eh nosso ultimo ja q nn tem ninguem

    return lista;
}

void insereQuest(tLista* lista, tQuest* questao)
{
    tCelula* newCelula = malloc (sizeof(tCelula));

    newCelula->questao = questao;
    newCelula->prox = NULL;

    lista->fim->prox = newCelula;                // célula última aponta para a nova
    lista->fim = newCelula;
}

/*
    1. procura o questao
    2. tira ele da corrente
    3. se era o último, arruma o fim
    4. libera o questao
    5. libera a célula
*/
void retiraQuest(tLista* lista, int id)
{
    tCelula* anterior = lista->ini;
    tCelula* atual = lista->ini->prox;

    while (atual != NULL && id != getId(atual->questao))
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;

    anterior->prox = atual->prox;                   
    // tiramos o questao da correntinha de ponteiros

    // nosso questao removido era o ultimo?
    if (atual == lista->fim)
    {
        lista->fim = anterior;
    }

    liberaQuest(atual->questao);
    free (atual);
}

void imprimeLista(FILE* saida, tLista* lista)
{
    tCelula* atual;

    for (atual = lista->ini->prox; atual != NULL; atual = atual->prox)
    {
        imprimeQuest(saida, atual->questao);
    }
}

void liberaLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        tCelula* depois = atual->prox;

        liberaQuest(atual->questao);
        free(atual);

        atual = depois;
    }

    free (lista->ini);
    free (lista);
}

void retiraCopia(tLista* lista)
{
    tCelula* atual = lista->ini->prox;      // questao que queremos manter / base

    while (atual != NULL)
    {
        tCelula* anterior = atual;          // celula de antes da analisada
        tCelula* sherlock = atual->prox;    // celula q estamos analisando

        while (sherlock != NULL)
        {
            if (getId(atual->questao) == getId(sherlock->questao))
            {
                anterior->prox = sherlock->prox;

                if (sherlock == lista->fim) lista->fim = anterior;

                tCelula* retira = sherlock;
                sherlock = sherlock->prox;

                liberaQuest(retira->questao);
                free (retira);
            }

            else
            {
                anterior = sherlock;
                sherlock = sherlock->prox;
            }
        }

        atual = atual->prox;
    }
}

tLista* mergeLista(tLista* lista1, tLista* lista2)
{
    tLista* merge = criaLista();

    tCelula* atual1 = lista1->ini->prox;

    while (atual1 != NULL)
    {
        tQuest* copy = criaQuest(getId(atual1->questao), getEnunciado(atual1->questao));
        insereQuest(merge, copy);

        atual1 = atual1->prox;
    }

    tCelula* atual2 = lista2->ini->prox;

    while (atual2 != NULL)
    {
        tQuest* copy = criaQuest(getId(atual2->questao), getEnunciado(atual2->questao));
        insereQuest(merge, copy);

        atual2 = atual2->prox;
    }

    return merge;
}

tQuest* buscaQuest(tLista* lista, int id)
{
    // começa no primeiro item de vdd da lista
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (getId(atual->questao) == id)
        {
            return atual->questao;
        }

        atual = atual->prox;
    }

    return NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"

// [Patricia | *] -> [Joao | *] -> [Maria | NULL]
// uma celula guarda uma info e o endereço da proxima celula
// é uma caixinha

typedef struct celula tCelula;
struct celula
{
    tAluno* aluno;
    struct celula* prox;
};

struct lista
{
    tCelula* ini;
    tCelula* fim;
};

/*
    LISTA VAZIA

    ini
    ↓
    [SENTINELA] -> NULL
    ↑
    fim
*/
/*
    LISTA COM ALUNOS

    ini
    ↓
    [SENTINELA] -> [Patricia] -> [Joao] -> [Maria] -> NULL
                                            ↑
                                            fim
*/

tLista* criaLista()
{
    tLista* lista = malloc (sizeof(tLista));

    lista->ini = malloc(sizeof(tCelula));       // nossa sentinela e a sua celula

    lista->ini->aluno = NULL;
    lista->ini->prox = NULL;                    // nosso primeiro aluno real

    lista->fim = lista->ini;                    // a sentinela eh nosso ultimo ja q nn tem ninguem

    return lista;
}

void insereAluno(tLista* lista, tAluno* aluno)
{
    tCelula* newCelula = malloc (sizeof(tCelula));

    newCelula->aluno = aluno;
    newCelula->prox = NULL;

    lista->fim->prox = newCelula;                // célula última aponta para a nova
    lista->fim = newCelula;
}

/*
    1. procura o aluno
    2. tira ele da corrente
    3. se era o último, arruma o fim
    4. libera o aluno
    5. libera a célula
*/
void retiraAluno(tLista* lista, int matricula)
{
    tCelula* anterior = lista->ini;
    tCelula* atual = lista->ini->prox;

    while (atual != NULL && matricula != getMatricula(atual->aluno))
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;

    anterior->prox = atual->prox;                   // tiramos o aluno da correntinha de ponteiros

    // nosso aluno removido era o ultimo?
    if (atual == lista->fim)
    {
        lista->fim = anterior;
    }

    liberaAluno(atual->aluno);
    free (atual);
}

void imprimeLista(FILE* saida, tLista* lista)
{
    tCelula* atual;

    for (atual = lista->ini->prox; atual != NULL; atual = atual->prox)
    {
        imprimeAluno(saida, atual->aluno);
    }
}

void liberaLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        tCelula* depois = atual->prox;

        liberaAluno(atual->aluno);
        free(atual);

        atual = depois;
    }

    free (lista->ini);
    free (lista);
}

float calculaMedia(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    float soma = 0;
    int qnt = 0;

    while (atual != NULL)
    {
        soma += getCr(atual->aluno);
        qnt++;

        atual = atual->prox;
    }

    if (qnt == 0) return 0;

    return soma / qnt;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "tAluno.h"
#include "tProf.h"

// informação
// endereço da próxima caixinha
typedef struct celula tCelula;
struct celula
{
    void* info;                         // ponteiro generico
    char tipo;                          // identificando a info

    struct celula* prox;                // quem vem depois?
    struct celula* ant;                 // quem vem antes?
};

struct lista
{
    tCelula* ini;
    tCelula* fim;
};

tLista* criaLista()
{
    tLista* lista = malloc (sizeof(tLista));

    lista->ini = malloc(sizeof(tCelula));       // nossa sentinela e a sua celula

    lista->ini->info = NULL;
    lista->ini->prox = NULL;             // nossa primeira pessoa real
    lista->ini->ant = NULL;

    lista->fim = lista->ini;             // a sentinela eh nosso ultimo ja q nn tem ninguem

    return lista;
}

void inserePessoa(tLista* lista, void* info, char tipo)
{
    tCelula* newCelula = malloc (sizeof(tCelula));

    newCelula->info = info;
    newCelula->tipo = tipo;

    newCelula->prox = NULL;               // nao tem ninguem depois do new ult
    newCelula->ant = lista->fim;          // quem está antes do new ult?

    lista->fim->prox = newCelula;         // old ult aponta para novo ult
    lista->fim = newCelula;               // newCelula é o new fim
}

void retiraPessoa(tLista* lista, int cpf)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->tipo == 'A')
        {
            if (getCpfAluno((tAluno*) atual->info) == cpf) break;
        }

        else if (atual->tipo == 'P')
        {
            if (getCpfProf((tProf*) atual->info) == cpf) break;
        }

        atual = atual->prox;
    }
    if (atual == NULL) return;

    // S <--> A <--> B <--> C
    atual->ant->prox = atual->prox;          // A->prox = C

    if (atual->prox != NULL)
    {
        atual->prox->ant = atual->ant;       // C->ant = A
    }   

    // se fosse o ultimo da lista...
    if (atual == lista->fim)
    {
        lista->fim = atual->ant;             // novo fim = quem vinha antes de B
    }

    if (atual->tipo == 'A') liberaAluno((tAluno*) atual->info);
    else if (atual->tipo == 'P') liberaProf((tProf*) atual->info);
    free (atual);
}

void imprimeLista(FILE* saida, tLista* lista)
{
    tCelula* atual;

    int somaP = 0;
    fprintf(saida, "PROFESSORES\n");
    for (atual = lista->ini->prox; atual != NULL; atual = atual->prox)
    {
        if (atual->tipo == 'P')
        {
            imprimeProf(saida, (tProf*) atual->info);
            somaP++;
        }
    }

    fprintf(saida, "\nMédia de salário dos %d professores: %.2f\n", somaP, calculaMediaSalario(lista));

    int somaA = 0;
    fprintf(saida, "\nALUNOS\n");
    for (atual = lista->ini->prox; atual != NULL; atual = atual->prox)
    {
        if (atual->tipo == 'A')
        {
            imprimeAluno(saida, (tAluno*)atual->info);
            somaA++;
        }
    }

    fprintf(saida, "\nMédia de CR dos %d alunos: %.2f\n", somaA, calculaMediaCr(lista));
}

void liberaLista(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        tCelula* depois = atual->prox;

        if (atual->tipo == 'A') liberaAluno((tAluno*) atual->info);
        else if (atual->tipo == 'P') liberaProf((tProf*) atual->info);
        free(atual);

        atual = depois;
    }

    free (lista->ini);
    free (lista);
}

void* buscaPessoa(tLista* lista, int cpf)
{
    // começa no primeiro item de vdd da lista
    tCelula* atual = lista->ini->prox;

    while (atual != NULL)
    {
        if (atual->tipo == 'A')
        {
            if (getCpfAluno((tAluno*)atual->info) == cpf) return atual->info;
        }

        else
        {
            if (getCpfProf((tProf*)atual->info) == cpf) return atual->info;
        }

        atual = atual->prox;
    }

    return NULL;
}

float calculaMediaCr(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    float soma = 0;
    int qnt = 0;

    while (atual != NULL)
    {
        if (atual->tipo == 'A')
        {
            soma += getCrAluno((tAluno*) atual->info);
            qnt++;
        }

        atual = atual->prox;
    }

    if (qnt == 0) return 0;

    return soma / qnt;
}

float calculaMediaSalario(tLista* lista)
{
    tCelula* atual = lista->ini->prox;

    float soma = 0;
    int qnt = 0;

    while (atual != NULL)
    {
        if (atual->tipo == 'P')
        {
            soma += getSalarioProf((tProf*) atual->info);
            qnt++;
        }

        atual = atual->prox;
    }

    if (qnt == 0) return 0;

    return soma / qnt;
}
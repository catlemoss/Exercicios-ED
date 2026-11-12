#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "tInfo.h"

typedef struct cell tCell;
struct cell
{
    tInfo* info;

    struct cell* ant;
    struct cell* prox;
};

struct lista
{
    char* nome;

    tCell* ini;             // nossa sensei sentinela
    tCell* fim;             // a ultima celula

    tLista* proxPessoa;     // aponta para outra lista
};

tLista* criaLista(char* nome)
{
    tLista* lista = malloc (sizeof(tLista));

    lista->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(lista->nome, nome);

    lista->ini = malloc (sizeof(tCell));        // nao pode esquecer da sensei sentinela!

    lista->ini->info = NULL;    
    lista->ini->ant = NULL;
    lista->ini->prox = NULL;

    lista->fim = lista->ini;

    lista->proxPessoa = NULL;

    return lista;
}

void liberaLista(tLista* lista)
{
    tCell* atual = lista->ini->prox;

    while (atual != NULL)
    {
        tCell* depois = atual->prox;

        liberaInfo(atual->info);
        free (atual);

        atual = depois;
    }

    free (lista->nome);
    free (lista->ini);
    free (lista);
}

void imprimeLista(FILE* saida, tLista* lista)
{
    tCell* atual = lista->ini->prox;

    fprintf(saida, "Pessoa: %s\n", lista->nome);

    while (atual != NULL)
    {
        imprimeInfo(saida, atual->info);

        atual = atual->prox;
    }

    fprintf(saida, "\n");
}

void insereLista(tLista* lista, tInfo* info)
{
    tCell* newCell = malloc (sizeof(tCell));

    newCell->info = info;

    newCell->ant = lista->fim;
    newCell->prox = NULL;

    lista->fim->prox = newCell;
    lista->fim = newCell;
}

void retiraLista(tLista* lista)
{
     tCell* atual = lista->ini->prox;

    float lat = 0;
    float longi = 0;
    float temp = 0;

    int contador = 0;

    while (atual != NULL)
    {
        lat += getLat(atual->info);
        longi += getLong(atual->info);
        temp += getTemp(atual->info);

        contador++;
        atual = atual->prox;
    }
    if (contador == 0) return;

    float medialat = lat / contador;
    float medialongi = longi / contador;
    float mediatemp = temp / contador;

    atual = lista->ini->prox;               // tem q reiniciar pq ele foi pra null no loop antigo

    while (atual != NULL)
    {
        tCell* depois = atual->prox;

        if (getLat(atual->info) > medialat * 1.5 ||
            getLong(atual->info) > medialongi * 1.5 ||
            getTemp(atual->info) > mediatemp * 1.5)
        {

            atual->ant->prox = atual->prox;

            if (atual->prox != NULL)
            {
                atual->prox->ant = atual->ant;
            }
            else
            {
                lista->fim = atual->ant;
            }

            liberaInfo(atual->info);
            free (atual);
        }

        atual = depois;
    }
}

tLista* adicionaPessoa(tLista* principal, tLista* nova)
{
    if (principal == NULL) return nova;
    
    tLista* atual = principal;

    while (atual->proxPessoa != NULL)
    {
        atual = atual->proxPessoa;
    }

    atual->proxPessoa = nova;

    return principal;
}

tLista* buscaPessoa(tLista* principal, char* nome)
{
    tLista* atual = principal;

    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            return atual;
        }

        atual = atual->proxPessoa;
    }

    return NULL;
}

void imprimePessoas(FILE* saida, tLista* pessoas)
{
    tLista* atual = pessoas;

    while (atual != NULL)
    {
        imprimeLista(saida, atual);

        atual = atual->proxPessoa;
    }
}

void retiraPessoas(tLista* pessoas)
{
    tLista* atual = pessoas;

    while (atual != NULL)
    {
        retiraLista(atual);

        atual = atual->proxPessoa;
    }
}

void liberaPessoas(tLista* pessoas)
{
    tLista* atual = pessoas;

    while (atual != NULL)
    {
        tLista* depois = atual->proxPessoa;

        liberaLista(atual);

        atual = depois;
    }
}
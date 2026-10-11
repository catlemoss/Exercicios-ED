#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

#include "tInfo.h"

typedef struct lista tLista;

tLista* criaLista(char* nome);
void liberaLista(tLista* lista);
void imprimeLista(FILE* saida, tLista* lista);
void insereLista(tLista* lista, tInfo* info);
void retiraLista(tLista* lista);

tLista* adicionaPessoa(tLista* principal, tLista* nova);
tLista* buscaPessoa(tLista* principal, char* nome);
void imprimePessoas(FILE* saida, tLista* pessoas);
void retiraPessoas(tLista* pessoas);
void liberaPessoas(tLista* pessoas);

#endif
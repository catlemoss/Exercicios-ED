#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include "tQuest.h"

typedef struct lista tLista;

tLista* criaLista();
void insereQuest(tLista* lista, tQuest* quest);
void retiraQuest(tLista* lista, int id);
void imprimeLista(FILE* saida, tLista* lista);
void liberaLista(tLista* lista);

void retiraCopia(tLista* lista);
tLista* mergeLista(tLista* lista1, tLista* lista2);

tQuest* buscaQuest(tLista* lista, int id);

#endif
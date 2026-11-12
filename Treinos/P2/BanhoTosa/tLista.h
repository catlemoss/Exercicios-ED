#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>

typedef struct lista tLista;

tLista* criaLista();
void liberaLista(tLista* lista);
void imprimeLista(FILE* saida, tLista* lista);
void insereLista(tLista* lista, void* info, int tipo);
int retiraLista(tLista* lista, char* nome);

float calculaValor(tLista* lista);

#endif
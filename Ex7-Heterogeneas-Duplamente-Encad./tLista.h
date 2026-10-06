#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>

typedef struct lista tLista;

tLista* criaLista();
void inserePessoa(tLista* lista, void* info, char tipo);
void retiraPessoa(tLista* lista, int cpf);
void imprimeLista(FILE* saida, tLista* lista);
void liberaLista(tLista* lista);

void* buscaPessoa(tLista* lista, int cpf);
float calculaMediaCr(tLista* lista);
float calculaMediaSalario(tLista* lista);

#endif
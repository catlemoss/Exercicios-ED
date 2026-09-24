#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include "tAluno.h"

typedef struct lista tLista;

tLista* criaLista();
void insereAluno(tLista* lista, tAluno* aluno);
void retiraAluno(tLista* lista, int matricula);
void imprimeLista(FILE* saida, tLista* lista);
void liberaLista(tLista* lista);

float calculaMedia(tLista* lista);

#endif
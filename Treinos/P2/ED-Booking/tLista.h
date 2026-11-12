#ifndef LISTA_H
#define LISTA_H

#include "Reserva.h"

typedef struct lista tLista;

tLista* criaLista();
void imprimeLista(tLista* lista);
void liberaLista(tLista* lista);
void insereLista(tLista* lista, Reserva* reserva);
void retiraLista(tLista* lista, Reserva* reserva);

#endif
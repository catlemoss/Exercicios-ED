#ifndef LISTA_H
#define LISTA_H

typedef struct lista tLista;

tLista* criaLista();
void insereLista(tLista* lista, void* info, int tipo);
void imprimeLista(tLista* lista);
void liberaLista(tLista* lista);
int retiraLista(tLista* lista, void* comida);

int getNumElementosLista(tLista* lista);
float calculaValorLista(tLista* lista);

#endif
#ifndef FUNCTS_H
#define FUNCTS_H

void bubbleSort(int* vet, int n);
void quickSort(int* vet, int n);

int buscaLinear(int* vet, int n, int elem);
int buscaBin(int* vet, int n, int elem);

void copyVet(int* copia, int* vet, int n);
void imprimeVet(int* vet, int n);

int comparaInt(const void* a, const void* b);

#endif
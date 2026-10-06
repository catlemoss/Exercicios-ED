#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tProf.h"

struct prof
{
    char* nome;
    int cpf;
    float salario;
};

tProf* criaProf(char* nome, int cpf, float salario)
{
    tProf* prof = malloc (sizeof(tProf));

    prof->cpf = cpf;
    prof->salario = salario;

    prof->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(prof->nome, nome);

    return prof;
}

void liberaProf(tProf* prof)
{
    free (prof->nome);
    free (prof);
}

void imprimeProf(FILE* saida, tProf* prof)
{
    fprintf(saida, "%s, CPF: %d e Salário: %.2f\n", prof->nome, prof->cpf, prof->salario);
}

char* getNomeProf(tProf* prof)
{
    return prof->nome;
}

int getCpfProf(tProf* prof)
{
    return prof->cpf;
}

float getSalarioProf(tProf* prof)
{
    return prof->salario;
}
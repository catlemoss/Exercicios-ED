#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "tAluno.h"
#include "tProf.h"

#define MAX_STRING 30

int main()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int numPessoas;
    fscanf(entrada, "%d", &numPessoas);

    tLista* lista = criaLista();

    for (int i = 0; i < numPessoas; i++)
    {
        char tipo;
        fscanf(entrada, " %c", &tipo);

        if (tipo == 'A')
        {
            char* nome = malloc(MAX_STRING * sizeof(char));
            int cpf;
            float cr;

            fscanf(entrada, "%29s %d %f\n", nome, &cpf, &cr);
            tAluno* aluno = criaAluno(nome, cpf, cr);

            inserePessoa(lista, aluno, 'A');

            free (nome);
        }

        else if (tipo == 'P')
        {
            char* nome = malloc(MAX_STRING * sizeof(char));
            int cpf;
            float salario;

            fscanf(entrada, "%29s %d %f\n", nome, &cpf, &salario);
            tProf* prof = criaProf(nome, cpf, salario);

            inserePessoa(lista, prof, 'P');

            free (nome);
        }
    }

    imprimeLista(saida, lista);

    // SET ME FREEEEEEE
    liberaLista(lista);

    fclose(entrada);
    fclose(saida);

    return 0;
}
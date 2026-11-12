#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"

#define MAX_STRING 30

int main ()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    tLista* pessoas = NULL;

    char* nome = malloc (MAX_STRING * sizeof(char));        
    int latitude;
    int longitude;
    float temperatura;

    while (fscanf(entrada, " %29s %d %d %f\n", nome, &latitude, &longitude, &temperatura) != EOF)
    {
        tInfo* info = criaInfo(latitude, longitude, temperatura);
        tLista* pessoa = buscaPessoa(pessoas, nome);

        if (pessoa == NULL)
        {
            pessoa = criaLista(nome);
            pessoas = adicionaPessoa(pessoas, pessoa);
        }

        insereLista(pessoa, info);
    }

    free (nome);
    fclose(entrada);

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    imprimePessoas(saida, pessoas);

    fprintf(saida, "==== sem os outliers ====\n\n");

    retiraPessoas(pessoas);
    imprimePessoas(saida, pessoas);

    liberaPessoas(pessoas);

    fclose(saida);

    return 0;
}
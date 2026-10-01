#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"

#define MAX_STRING 30

int main()
{
    FILE* entrada = fopen("entrada.txt", "r");
    if (entrada == NULL) exit(1);

    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    int numQuestBanca;
    fscanf(entrada, "%d", &numQuestBanca);

    tLista* questsBanca = criaLista();

    for (int i = 0; i < numQuestBanca; i++)
    {
        int id;
        char* enunciado = malloc (MAX_STRING * sizeof(char));

        fscanf(entrada, " Q%d %29[^\n]", &id, enunciado);

        tQuest* questao = criaQuest(id, enunciado);
        insereQuest(questsBanca, questao);

        free (enunciado);
    }

    // PROVA 1
    tLista* p1 = criaLista();
    char* nomeP1 = malloc (MAX_STRING * sizeof(char));
    fscanf(entrada, "%s", nomeP1);

    int nQuests1;
    fscanf(entrada, "%d", &nQuests1);

    for (int i = 0; i < nQuests1; i++)
    {
        int ids;
        fscanf(entrada, " Q%d", &ids);

        tQuest* quest = buscaQuest(questsBanca, ids);
        if (quest != NULL)
        {
            tQuest* copy = criaQuest(getId(quest), getEnunciado(quest));
            insereQuest(p1, copy);
        }

        // criamos uma copia da questao para q banca e p1/p2 nn tivessem o mesmo ponteiro
    }

    fprintf(saida, "Prova: %s\n", nomeP1);        
    imprimeLista(saida, p1);
    

    // PROVA 2
    tLista* p2 = criaLista();
    char* nomeP2 = malloc (MAX_STRING * sizeof(char));
    fscanf(entrada, "%s", nomeP2);

    int nQuests2;
    fscanf(entrada, "%d", &nQuests2);

    for (int i = 0; i < nQuests2; i++)
    {
        int ids;
        fscanf(entrada, " Q%d", &ids);
        
        tQuest* quest = buscaQuest(questsBanca, ids);
        if (quest != NULL)
        {
            tQuest* copy = criaQuest(getId(quest), getEnunciado(quest));
            insereQuest(p2, copy);
        }
    }

    fprintf(saida, "Prova: %s\n", nomeP2);        
    imprimeLista(saida, p2);

    // MERGE
    tLista* merge = mergeLista(p1, p2);

    fprintf(saida, "Prova: Merge\n");
    imprimeLista(saida, merge);

    retiraCopia(merge);

    fprintf(saida, "Prova: Merge\n");
    imprimeLista(saida, merge);

    // SET ME FREEEEEEE
    liberaLista(questsBanca);
    liberaLista(p1);
    liberaLista(p2);
    liberaLista(merge);

    free (nomeP1);
    free (nomeP2);

    fclose(entrada);
    fclose(saida);

    return 0;
}
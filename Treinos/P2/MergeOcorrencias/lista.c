#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

/*TipoItem Aluno (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD. Devem ser definidos campos:
 - nome (string)
 - matricula (int) */
struct aluno
{
    char* nome;
    int matricula;
};

/*Tipo que define a lista (tipo opaco)
 Estrutura interna do tipo deve ser definida na implementacao do TAD.
 Usar lista COM Sentinela */

typedef struct cell tCell;
struct cell
{
    TAluno* aluno;

    tCell* prox;
};

struct lista
{
    tCell* prim;
    tCell* ult;
};

/*Inicializa o sentinela de uma lista
 * inputs: nenhum
 * output: Sentinela inicializado (lista vazia)
 * pre-condicao: nenhuma
 * pos-condicao: sentinela da lista de retorno existe e os campos primeiro e ultimo apontam para NULL */
TLista* CriaLista()
{
    TLista* lista = malloc (sizeof(TLista));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

/*Inicializa um TipoItem aluno
 * inputs: o nome e a matricula do aluno
 * output: um ponteiro para o tipo TAluno criado
 * pre-condicao: nome e matricula validos
 * pos-condicao: tipo TAluno criado, com os campos nome e matricula COPIADOS */
TAluno* InicializaAluno(char* nome, int matricula)
{
    TAluno* aluno = malloc (sizeof(TAluno));

    aluno->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(aluno->nome, nome);

    aluno->matricula = matricula;

    return aluno;
}

/*Insere um aluno na primeira posicao da lista de alunos
 * inputs: aluno a ser inserido na lista (do tipo TAluno) e a lista
 * output: nenhum
 * pre-condicao: aluno n�o NULL e lista n�o NULL (mas, a lista pode estar vazia)
 * pos-condicao: lista contem o aluno inserido na primeira posicao */
void InsereAluno (TLista* lista, TAluno* aluno)
{
    tCell* newCell = malloc (sizeof(tCell));

    newCell->aluno = aluno;
    newCell->prox = lista->prim;

    lista->prim = newCell;

    // if lista vazia
    if (lista->ult == NULL) lista->ult = newCell;
}

/*Retira a primeira ocorrencia de um aluno de matricula mat da lista de alunos
 * inputs: a lista e a matricula do aluno a ser retirado da lista
 * output: o aluno (do tipo TAluno) retirado da lista ou NULL, se o aluno nao se encontrar na lista
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem a primeira ocorrencia do aluno de matricula mat */
TAluno* Retira (TLista* lista, int mat)
{
    tCell* atual = lista->prim;
    tCell* anterior = NULL;

    while (atual != NULL)
    {
        if (atual->aluno->matricula == mat) break;

        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return NULL;

    // remover 1 elemento
    if (anterior == NULL) lista->prim = atual->prox;
    else anterior->prox = atual->prox;

    // remover ultimo elemento
    if (atual == lista->ult) lista->ult = anterior;

    TAluno* removido = atual->aluno;
    free (atual);
    return removido;
}

/* Retira as repeticoes na lista. Ou seja, deixa apenas uma referencia para cada aluno na lista
 * inputs: a lista
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: lista nao contem repeticoes de alunos - APENAS UMA OCORRENCIA DE CADA ALUNO */
void RetiraRepetidos (TLista* lista)
{
    tCell* fixo = lista->prim;  // elemento q estamos usando para procurar as rept
   
    while (fixo != NULL)
    {
        tCell* anterior = fixo;
        tCell* atual = fixo->prox;

        while (atual != NULL)
        {
            if (fixo->aluno == atual->aluno)
            {
                tCell* repetido = atual;

                anterior->prox = atual->prox;

                // se for the last of us
                if (atual == lista->ult) lista->ult = anterior;

                atual = anterior->prox;

                free (repetido);
            }

            else
            {
                anterior = atual;
                atual = atual->prox;
            }
        }

        fixo = fixo->prox;
    }
}


/* Intercala os alunos das turmas 1 e 2 em uma nova lista. Por exemplo, se a turma 1 tiver (a1->a2->a3) e a turma 2 tiver (b1->b2->b3->b4->b5), a funcao deve retornar uma nova lista formada pelos elementos (a1->b1->a2->b2->a3->b3->b4->b5). Se uma das  listas tiver mais elementos que a outra, os elementos excedentes s�o transferidos na mesma ordem para a nova lista. As listas originais devem ficar vazias (com sentila prim e ult apontando para NULL).
 * inputs: duas listas n�o nulas (por�m, podem estar vazias)
 * output: uma nova lista com os elementos intercalados
 * pre-condicao: listas turma1 e turma2 nao sao NULL (mas podem estar vazias)
 * pos-condicao: lista retornada contem os elementos intercalados. As listas de entrada vazias (apenas com sentinela). */
TLista* Merge (TLista* turma1, TLista* turma2)
{
    TLista* merge = CriaLista();

    tCell* atual1 = turma1->prim;
    tCell* atual2 = turma2->prim;


    while (atual1 != NULL && atual2 != NULL)
    {
        if (atual1 != NULL)
        {
            tCell* proximo = atual1->prox;

            if (merge->prim == NULL) merge->prim = atual1;
            else merge->ult->prox = atual1;

            merge->ult = atual1;
            atual1->prox = NULL;

            atual1 = proximo;
        }   

        if (atual2 != NULL)
        {
            tCell* proximo = atual2->prox;

            if (merge->prim == NULL) merge->prim = atual2;
            else merge->ult->prox = atual2;

            merge->ult = atual2;
            atual2->prox = NULL;

            atual2 = proximo;
        }
    }

    turma1->prim = NULL;
    turma1->ult = NULL;

    turma2->prim = NULL;
    turma2->ult = NULL;

    return merge;
}

/* Libera a memoria alocada para o aluno
 * inputs: o aluno do tipo TAluno*
 * output: nenhum
 * pre-condicao: aluno n�o NULL
 * pos-condicao: toda a memoria alocada para o aluno foi liberada (inclusive para o nome) */
void LiberaAluno (TAluno* aluno)
{
    free (aluno->nome);
    free (aluno);
}

/*Imprime os dados de todos os alunos da lista
 * inputs: a lista de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas, pode estar vazia)
 * pos-condicao: dados dos alunos impressos na saida padrao */
void Imprime (TLista* lista)
{
    tCell* atual = lista->prim;
    int aluno = 1;

    while (atual != NULL)
    {
        printf("Aluno %d:\n", aluno);
        printf("\tNome: %s\n", atual->aluno->nome);
        printf("\tMatricula: %d\n", atual->aluno->matricula);

        aluno++;
        atual = atual->prox;
    }
}

/*Libera toda a memoria alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
 * inputs: a lista encadeada de alunos
 * output: nenhum
 * pre-condicao: lista nao eh NULL (mas pode estar vazia)
 * pos-condicao: toda memoria alocada eh liberada (use valgrind!) */
void LiberaLista (TLista* lista)
{
    tCell* atual = lista->prim;

    while (atual != NULL)
    {
        tCell* depois = atual->prox;

        LiberaAluno(atual->aluno);
        free (atual);

        atual = depois;
    }

    free (lista);
}
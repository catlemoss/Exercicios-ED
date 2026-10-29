#include <stdio.h>

#include "tPilha.h"
#include "tAluno.h"

int main ()
{
    tPilha* p = inicPilha();

    tAluno* ana = criaAluno("Ana", 101);
    tAluno* bia = criaAluno("Bia", 102);

    push(p, ana);
    push(p, bia);

    printf("Alunos:\n");
    imprimePilha(p);

    tAluno* retirado = pop(p);

    printf("Aluno retirado:\n");
    imprimeAluno(retirado);

    liberaAluno(retirado);

    while (!vazia(p))
    {
        tAluno* aluno = pop(p);
        liberaAluno(aluno);
    }

    destroiPilha(p);

    return 0;
}
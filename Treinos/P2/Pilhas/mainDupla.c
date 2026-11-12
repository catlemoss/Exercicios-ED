#include <stdio.h>

#include "tPdupla.h"
#include "tAluno.h"

int main ()
{
    tPdupla* pilha = inicPdupla();

    tAluno* ana = criaAluno("Ana", 100);
    tAluno* bia = criaAluno("Bia", 102);
    tAluno* carlos = criaAluno("Carlos", 103);
    tAluno* daniela = criaAluno("Daniela", 105);

    push1(pilha, ana);
    push1(pilha, bia);

    push2(pilha, carlos);
    push2(pilha, daniela);

    imprimePdupla(pilha);


    tAluno* retirado = pop1(pilha);

    printf("Aluno retirado:\n");
    imprimeAluno(retirado);

    liberaAluno(retirado);

    while ((retirado = pop1(pilha)) != NULL)
    {
        liberaAluno(retirado);
    }
    while ((retirado = pop2(pilha)) != NULL)
    {
        liberaAluno(retirado);
    }

    destroiPdupla(pilha);

    return 0;
}
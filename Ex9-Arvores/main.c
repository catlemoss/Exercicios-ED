#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tArv.h"

int main ()
{
    // alunos
    tAluno* catarina = criaAluno("Catarina", 3, 10);
    tAluno* sofia = criaAluno("Sofia", 1306, 9.9);
    tAluno* bia = criaAluno("Bia", 12, 8.7);
    tAluno* raposo = criaAluno("Raposo", 12, 0);
    tAluno* aquariano = criaAluno("Aquariano", 2, 6.6);
    tAluno* dostoievski = criaAluno("Dostoievski", 225, 5);

    // arvore de baixo para cima
    /* sub-árvore "d" */
    tArv* a1 = arv_cria(raposo, arv_criavazia(), arv_criavazia());
    /* sub-árvore "b" */
    tArv* a2 = arv_cria(sofia, arv_criavazia(), a1);
    /* sub-árvore "e" */
    tArv* a3 = arv_cria(aquariano, arv_criavazia(), arv_criavazia());
    /* sub-árvore "f" */
    tArv* a4 = arv_cria(dostoievski, arv_criavazia(), arv_criavazia());
    /* sub-árvore "c" */
    tArv* a5 = arv_cria(bia, a3, a4);
    /* árvore "a" */
    tArv* a = arv_cria(catarina, a2, a5);

    /*
    tArv* a = arv_cria(catarina,
                    arv_cria(sofia, 
                        arv_criavazia(),
                        arv_cria(raposo, arv_criavazia(), arv_criavazia())),
                    arv_cria(bia,
                        arv_cria(aquariano, arv_criavazia(), arv_criavazia()),
                        arv_cria(dostoievski, arv_criavazia(), arv_criavazia()))
            );
    */

    // imprimi arv
    printf("ARVORE:\n");
    arv_imprime(a);
    printf("\n");
    printf("\n");

    // arv vazia
    printf("ARVORE VAZIA: %d\n", arv_vazia(a));
    printf("\n");

    // tem na arv?
    printf("PERTENCE:\n");
    printf("Matricula 2: %d\n", arv_pertence(a, 2));
    printf("Matricula 0: %d\n", arv_pertence(a, 0));
    printf("\n");

    // folhas
    printf("FOLHAS: %d\n", folhas(a));
    printf("\n");

    // quantas vezes na arv?
    printf("OCORRENCIAS:\n");
    printf("Matricula 12: %d\n", ocorrencias(a, 12));
    printf("Matricula 0: %d\n", ocorrencias(a, 0));
    printf("\n");

    // papis?
    printf("PAI:\n");
    tArv* pai = arv_pai(a, 225);
    if (pai == a5) printf("Pai de Dostoievski: Bia\n");
    else printf("Dostoievski nao tem pai...\n");
    printf("\n");

    // pai da catarina?
    printf("PAI DA RAIZ:\n");
    pai = arv_pai(a, 3);
    if (pai == NULL) printf("A raiz nao possui pai!\n");
    else printf("A raiz nao deveria ter pai...\n");
    printf("\n");

    // arv esvaziada
    printf("TESTANDO ARVORE VAZIA:\n");
    tArv* vazia = arv_criavazia();
    printf("Vazia: %d\n", arv_vazia(vazia));
    printf("Folhas: %d\n", folhas(vazia));
    printf("Pertence: %d\n", arv_pertence(vazia, 3));
    printf("Ocorrencias: %d\n", ocorrencias(vazia, 3));
    if (arv_pai(vazia, 3) == NULL) printf("Arvore vazia nao possui pai!\n");
    vazia = arv_libera(vazia);
    printf("\n");

    // arvore com um no
    printf("TESTANDO ARVORE COM UM NO:\n");
    tAluno* unico = criaAluno("Unico", 999, 10);
    tArv* arv_unica = arv_cria(unico, arv_criavazia(), arv_criavazia());
    arv_imprime(arv_unica);
    printf("\n");
    printf("Folhas: %d\n", folhas(arv_unica));
    printf("Pertence: %d\n", arv_pertence(arv_unica, 999));
    printf("Ocorrencias: %d\n", ocorrencias(arv_unica, 999));
    if (arv_pai(arv_unica, 999) == NULL) printf("O unico no nao possui pai!\n");
    arv_unica = arv_libera(arv_unica);
    printf("\n");

    // nao existe pai...
    printf("PAI INEXISTENTE:\n");
    pai = arv_pai(a, 999);
    if (pai == NULL) printf("Correto!\n");
    else printf("Naooooo!\n");
    printf("\n");

    // set me free
    a = arv_libera(a);
    printf("ARVORE LIBERADA: %d\n", arv_vazia(a));

    return 0;
}
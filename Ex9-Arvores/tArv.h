#ifndef ARV_H
#define ARV_H

#include "tAluno.h"

typedef struct arv tArv;

//Cria uma árvore vazia
tArv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e com subárvore esquerda e a subárvore direita
tArv* arv_cria (tAluno* aluno, tArv* esq, tArv* dir);

//libera o espaço de memória ocupado pela árvore a
tArv* arv_libera (tArv* arv);

//retorna true se a árvore estiver vazia e false caso contrário
int arv_vazia (tArv* arv);

//indica a ocorrência (1) ou não (0) do aluno (pela chave de busca mat)
int arv_pertence (tArv* arv, int mat);

//imprime as informações dos nós da árvore <raiz e d> e <> (árvore vazia)
void arv_imprime (tArv* arv);

//retorna a mãe/pai de um dado no que contém o aluno com a matrícula mat
tArv* arv_pai (tArv* arv, int mat);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (tArv* arv);

//retorna o numero de ocorrencias de um dado aluno na árvore
int ocorrencias (tArv* arv, int mat);

#endif
#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

//Tipo matriz (tipo opaco)
//Estrutura interna do tipo deve ser definida na implementacao do TAD
struct matriz
{
    int linhas, colunas;
    int *mat;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz *m = malloc (sizeof(Matriz));
    if (m == NULL) exit(1);
    
    m->linhas = nlinhas;
    m->colunas = ncolunas;

    m->mat = malloc (nlinhas*ncolunas * sizeof(int));

    return m;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    mat->mat[linha * mat->colunas + coluna] = elem;
    // k = i * n + j,
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna sao validos na matriz
 * pos-condicao: mat nao eh modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat->mat[linha * mat->colunas + coluna];
}

/*Retorna o numero de colunas da matriz mat
 * inputs: a matriz
 * output: o numero de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNColunas (Matriz* mat)
{
    return mat->colunas;
}

/*Retorna o numero de linhas da matriz mat
 * inputs: a matriz
 * output: o numero de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada
 */
int recuperaNLinhas (Matriz* mat)
{
    return mat->linhas;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat nao eh modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat)
{
    Matriz *tsp = inicializaMatriz(mat->colunas, mat->linhas);

    for (int i = 0; i < mat->colunas; i++)
    {
        for (int j = 0; j < mat->linhas; j++)
        {
            tsp->mat[i * tsp->colunas + j] = mat->mat[j * mat->colunas + i];
        }
    }

    return tsp;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicacao
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas de mat1 correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 nao sao modificadas e a matriz multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2)
{
    if (mat1->colunas != mat2->linhas) exit(1);

    Matriz *mult = inicializaMatriz(mat1->linhas, mat2->colunas);

    for (int i = 0; i < mult->linhas; i++)
    {
        for (int j = 0; j < mult->colunas; j++)
        {
            mult->mat[i * mult->colunas + j] = 0;

            for (int k = 0; k < mat1->colunas; k++)
            {
                mult->mat[i * mult->colunas + j] += 
                    mat1->mat[i * mat1->colunas + k] * 
                    mat2->mat[k * mat2->colunas + j];
            }
        }
    }

    return mult;
}

/*Imprime a matriz completa
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat)
{
    for (int i = 0; i < mat->linhas; i++)
    {
        for (int j = 0; j < mat->colunas; j++)
        {
            printf("%d ", mat->mat[i * mat->colunas + j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*Imprime apenas uma linha da matriz
 * inputs: matriz mat e o indice da linha
 * output: nenhum
 * pre-condicao: matriz mat existe e indice eh valido na matriz
 * pos-condicao: nenhuma
 */
void imprimeLinha (Matriz* mat, int indice)
{
    for (int j = 0; j < mat->colunas; j++)
    {
        printf("%d ", mat->mat[indice * mat->colunas + j]);
    }
    printf("\n");
}

/*Libera toda a memoria alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: memoria ocupada por linhas e colunas liberada!
 */
void destroiMatriz (Matriz* mat)
{
    free (mat->mat);
    free (mat);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pedido.h"

/* Define o tipo TPedido (tipo opaco). Estrutura interna deste tipo eh definida na implementacao do TAD.
 * Trata-se da sentinela da lista e deve conter as seguintes informacoes:
 * Dono do pedido (char*) e os campos prim e ult da sentinela
 */

typedef struct cell tCell;
struct cell
{
    TProduto* produto;

    tCell* prox;
};

struct pedido
{
    char* dono;

    tCell* prim;
    tCell* ult;
};

/*----------------------------------------------------------------------
 * Inicializa o pedido de um cliente (ou seja, a sentinela!)
 * inputs: nome do dono do pedido
 * output: Pedido inicializado
 * pre-condicao: nome devidamente alocado
 * pos-condicao: Pedido inicializado contendo o nome como informado
 *---------------------------------------------------------------------- */
TPedido* InicPedido (char* dono)
{
    TPedido* pedido = malloc (sizeof(TPedido));

    pedido->dono = malloc ((strlen(dono)+1) * sizeof(char));
    strcpy(pedido->dono, dono);

    pedido->prim = NULL;
    pedido->ult = NULL;

    return pedido;
}

/*----------------------------------------------------------------------
 * Inclui um produto no pedido de um cliente (ou seja, a sentinela!). Inserir ao FINAL!
 * Lembrando que um produto nao pode ser inserido mais de uma vez no pedido! Neste caso, exiba a mensagem "Produto já existe no pedido\n"
 * inputs: o pedido e o produto a ser inserido
 * output: nada
 * pre-condicao: pedido e produto foram devidamente inicializados
 * pos-condicao: produto inserido no pedido OU lista inalterada (caso o produto ja esteja na lista)
 *----------------------------------------------------------------------*/
void IncluiProdutoPedido (TPedido* pedido, TProduto* prod)
{
    tCell* atual = pedido->prim;

    while (atual != NULL)
    {
        if (strcmp(RetornaNome(atual->produto), RetornaNome(prod)) == 0)
        {
            printf("Produto já existe no pedido\n");
            return;
        }

        atual = atual->prox;
    }

    tCell* newCell = malloc (sizeof(tCell));

    newCell->produto = prod;
    newCell->prox = NULL;

    if (pedido->prim == NULL) pedido->prim = newCell;
    else pedido->ult->prox = newCell;

    pedido->ult = newCell;
}

/*----------------------------------------------------------------------
 * Imprime todos os dados de um pedido (o dono seguido de todos os produtos e ingredientes)
 * Caso o pedido seja novo e nao tenha ainda produtos, exibir a mensagem "Nao ha produtos neste pedido!\n"
 * inputs: o pedido
 * output: nada
 * pre-condicao: pedido devidamente inicializado
 * pos-condicao: funcao nao alterad os dados do pedido
 *----------------------------------------------------------------------*/
void ImprimePedido (TPedido* pedido)
{
    tCell* atual = pedido->prim;

    if (atual == NULL)
    {
        printf("Nao ha produtos neste pedido!\n");
        return;
    }

    printf("\nPedido de: %s\n", pedido->dono);

    while (atual != NULL)
    {
        ImprimeIngredientes(atual->produto);

        atual = atual->prox;
    }
}

/*----------------------------------------------------------------------
 * Retira a unica ocorrência do produto (caso ele exista na lista).
 * Importante!!! Esta funcao nao libera o produto! Apenas o retira do pedido!
 * inputs: o pedido e, o produto a ser retirado
 * output: nada
 * pre-condicao: pedido e produto devidamente inicializados
 * pos-condicao: pedido nao contem o produto
 *----------------------------------------------------------------------*/
void RetiraProdutoPedido (TPedido* pedido, char* prod)
{
    tCell* atual = pedido->prim;
    tCell* anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(RetornaNome(atual->produto), prod) == 0)
        {
            break;
        }

        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) return;

    // remover o 1 elemento
    if (anterior == NULL) pedido->prim = atual->prox;
    else anterior->prox = atual->prox;

    // remover o ultimo elemento
    if (atual == pedido->ult) pedido->ult = anterior;

    free (atual);
}

//A função envia pedido verifica se há restrição calórica ou restrição alimentar
//Se estiver tudo ok, retira o pedido da lista (libera o pedido, porém não libera o produto) e retorna 1
//Se não estiver ok, a lista permanece a mesma e a função retorna zero

/*----------------------------------------------------------------------
 * Primeiramente, verifica se há restrição calórica ou restrição alimentar, de acordo com os parametros
 **** Para a restricao calorica, deve-se somar as calorias de todos o produtos do pedido! Caso o numero de calorias do pedido ultrapasse a restricao, exiba a mensagem : "Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!"
 ****** Para a restricao alimentar, deve-se verificar se algum produto contem como ingrediente a restricao especificada. Caso algum produto contenha o ingrediente indicado, exiba a mensagem: nPedido não Enviado! Restricao alimentar no produto: %s\n
* Se estiver tudo certo (ou seja respeitando-se as restricoes), destroi o pedido da pessoa, porém não libera os produtos) e retorna 1
 * inputs: o pedido e as restricoes calorica e alimentar
 * output: 0 (problema em algumas das restricoes). 1 (pedido enviado)
 * pre-condicao: pedido devidamente inicializado e strings validas
 * pos-condicao: se houver problema com as restricoes, o pedido deve ficar inalterado. se estiver tudo ok com as restricoes, deve destruir o pedido, porem os produtos nao devem ser liberados (pois podem estar em outros pedidos, de outras pessoas).
 *----------------------------------------------------------------------*/
int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar)
{
    tCell* atual = pedido->prim;

    int somaCaloria = 0;

    while (atual != NULL)
    {
        somaCaloria += Calorias(atual->produto);

        if (VerificaIngrediente(atual->produto, restricao_alimentar))
        {
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", RetornaNome(atual->produto));
            return 0;
        }

        atual = atual->prox;
    }

    if (somaCaloria > restricao_calorica)
    {
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    atual = pedido->prim;

    while (atual != NULL)
    {
        tCell* prox = atual->prox;

        free(atual);

        atual = prox;
    }

    free(pedido->dono);
    free(pedido);

    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "Pedido.h"

#define PARAMETRO 500
#define veg 0
#define notveg 1

//2 listas
//1 lista comidas > 500 calorias (calóricos)
//1 lista comidas <=500 calorias (magros)
/*Tipo que define um pedido (tipo opaco)
 *Um pedido deve ter os seguintes atributos:
 * * Numero do pedido
 * * Uma lista de comidas (veganas e nao veganas) com calorias > 500 (alimentos calóricos)
 * * Uma lista de comidas (veganas e nao veganas) com calorias <=500 (alimentos magros)
 * */
struct pedido
{
  int num;

  tLista* calorica;
  tLista* magra;
};

/* Cria um pedido, ainda vazio, com duas listas de alimentos, vazias
* inputs: numero do pedido.
* output: pedido alocado e vazia, com listas de alimentos ainda vazias
* pre-condicao: nao tem
* pos-condicao: pedido alocado e vazio, com listas de alimentos criadas e vazias
 */
Pedido* inicPedido (int numero)
{
  Pedido* pedido = malloc (sizeof(Pedido));

  pedido->num = numero;

  pedido->calorica = criaLista();
  pedido->magra = criaLista();

  return pedido;
}

/* Insere uma comida vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaVegana (Pedido* pedido, ComidaVegana* food)
{
  // calorias > 500 (alimentos calóricos)
  //calorias <= 500 (alimentos magros)

  if (retornaCaloriasComidaVegana(food) > PARAMETRO)
  {
    insereLista(pedido->calorica, food, veg);
  }
  else
  {
    insereLista(pedido->magra, food, veg);
  }
}


/* Insere uma comida não vegana em uma das listas de alimentos, dependendo do seu nível de caloria
* inputs: referência para a um pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: pedido contém o alimento em uma de suas listas, dependendo do nível de calorias do alimento  */
void insereComidaNaoVegana (Pedido* pedido, ComidaNaoVegana* food)
{
  if (retornaCaloriasComidaNaoVegana(food) > PARAMETRO)
  {
    insereLista(pedido->calorica, food, notveg);
  }
  else
  {
    insereLista(pedido->magra, food, notveg);
  }
}

//retorna o numero do pedido
int retornaNumeroPedido(Pedido* pedido)
{
  return pedido->num;
}

/* Essa função atualiza a situação de uma comida nao vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaNaoVegana(Pedido* pedido, ComidaNaoVegana* food)
{
  if (retornaCaloriasComidaNaoVegana(food) > PARAMETRO && retiraLista(pedido->magra, food))
  {
    insereLista(pedido->calorica, (ComidaNaoVegana*) food, notveg);
  }
  else if (retornaCaloriasComidaNaoVegana(food) <= PARAMETRO && retiraLista(pedido->calorica, food))
  {
    insereLista(pedido->magra, (ComidaNaoVegana*) food, notveg);
  }
}

/* Essa função atualiza a situação de uma comida vegana no pedido. Caso o alimento esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para o pedido e a referência para o alimento
* output: nenhum
* pre-condicao: pedido alocado e alimento alocado
* pos-condicao: alimento deve estar na lista correta, de acordo com seu nível de calorias */
void atualizaSituacaoComidaVegana(Pedido* pedido, ComidaVegana* food)
{
  if (retornaCaloriasComidaVegana(food) > PARAMETRO && retiraLista(pedido->magra, food))
  {
    insereLista(pedido->calorica, (ComidaVegana*) food, veg);
  }
  else if (retornaCaloriasComidaVegana(food) <= PARAMETRO && retiraLista(pedido->calorica, food))
  {
    insereLista(pedido->magra, (ComidaVegana*) food, veg);
  }
}


//Imprime os dados do pedido, seguindo o formato a seguir
/*Imprimindo Detalhes do Pedido número: 123
  Valor total do Pedido: 135.90

 Lista de Itens de Baixa Caloria: 1
 Nome comida nao vegana: Picanha, valor: 90.50, calorias: 300

 Lista de Itens de Alta Caloria: 2
 Nome comida vegana: Empadao, calorias: 600
 Nome comida nao vegana: Sorvete de Creme, valor: 15.40, calorias: 600
*/
void imprimePedido (Pedido* pedido)
{
  printf("Imprimindo Detalhes do Pedido número: %d\n", pedido->num);
  printf("Valor total do Pedido: %.2f\n", calculaValorPedido(pedido));

  printf("Lista de Itens de Baixa Caloria: %d\n", getNumElementosLista(pedido->magra));
  imprimeLista(pedido->magra);

  printf("Lista de Itens de Alta Caloria: %d\n", getNumElementosLista(pedido->calorica));
  imprimeLista(pedido->calorica);

  printf("\n\n");
}

//comida vegana tem o valor fixo de 30 reais
float calculaValorPedido (Pedido* pedido)
{
  float total = 0.0;

  total += calculaValorLista(pedido->calorica);
  total += calculaValorLista(pedido->magra);

  return total;
}

/* Libera toda a memória alocada
* inputs: referencia para o pedido
* output: não tem
* pre-condicao: pedido alocado
* pos-condicao: Toda a memória liberada, a não ser alimentos, que são responsabilidade do cliente. */
void liberaPedido (Pedido* pedido)
{
  liberaLista(pedido->calorica);
  liberaLista(pedido->magra);
  
  free (pedido);
}
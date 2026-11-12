#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tLista.h"
#include "tBanhoTosa.h"

enum
{
    MANSO, BRAVO
};

enum
{
    GATO, CAO
};

/*Tipo que define a loja de banho e tosa (tipo opaco)
 *Cada loja deve ter os seguintes atributos:
 * * Nome da loja
 * * Uma lista de animais (gatos e cachorros) agressivos
 * * Uma lista de animais (gatos e cachorros) mansos
 * */
struct banhotosa
{
    char* nome;

    tLista* bravos;
    tLista* mansos;
};


/* Cria uma loja de banho e tosa, ainda vazia, com duas listas de animais vazias
* inputs: nome da loja (char*). Esta função deve alocar dinamicamente o nome da loja.
* output: loja alocada e vazia, com listas de animais ainda vazias
* pre-condicao: nao tem
* pos-condicao: loja alocada e vazia, com listas de animais criadas e vazias  */
BanhoTosa* inicBanhoTosa(char* nome)
{
    BanhoTosa* banho = malloc (sizeof(BanhoTosa));

    banho->nome = malloc ((strlen(nome)+1) * sizeof(char));
    strcpy(banho->nome, nome);

    banho->bravos = criaLista();
    banho->mansos = criaLista();

    return banho;
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraCachorro(BanhoTosa* loja, tCao* dog)
{
    if (getAgressividadeCachorro(dog) == MANSO)
    {
        insereLista(loja->mansos, (tCao*) dog, CAO);
    }
    else if (getAgressividadeCachorro(dog) == BRAVO)
    {
        insereLista(loja->bravos, (tCao*) dog, CAO);
    }
}

/* Insere o cachorro em uma das listas de animais, dependendo do seu nível de agressividade
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: loja contém o animal e uma de suas listas, dependendo do nível de agressividade do animal  */
void cadastraGato(BanhoTosa* loja, tGato* cat)
{
    if (getAgressividadeGato(cat) == MANSO)
    {
        insereLista(loja->mansos, (tGato*) cat, GATO);
    }
    else if (getAgressividadeGato(cat) == BRAVO)
    {
        insereLista(loja->bravos, (tGato*) cat, GATO);
    }
}


/* Essa função atualiza a situação de um gato na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoGato(BanhoTosa* loja, tGato* cat)
{
    if (getAgressividadeGato(cat) == MANSO && retiraLista(loja->bravos, getNomeGato(cat)))
    {
        insereLista(loja->mansos, (tGato*) cat, GATO);
    }
    else if (getAgressividadeGato(cat) == BRAVO && retiraLista(loja->mansos, getNomeGato(cat)))
    {
        insereLista(loja->bravos, (tGato*) cat, GATO);
    }
}

/* Essa função atualiza a situação de um cachorro na loja. Caso ele esteja na lista errada, ele é devidamente MOVIDO para a lista correta.
* inputs: referência para a loja e a referência para o animal
* output: nenhum
* pre-condicao: loja alocada e animal alocado
* pos-condicao: animal deve estar na lista correta, de acordo com seu nível de agressividade */
void atualizaSituacaoCachorro(BanhoTosa* loja, tCao* dog)
{
    if (getAgressividadeCachorro(dog) == MANSO && retiraLista(loja->bravos, getNomeCachorro(dog)))
    {
        insereLista(loja->mansos, (tCao*) dog, CAO);
    }
    else if (getAgressividadeCachorro(dog) == BRAVO && retiraLista(loja->mansos, getNomeCachorro(dog)))
    {
        insereLista(loja->bravos, (tCao*) dog, CAO);
    }
}

/* Imprime os dados da Loja (nome, e conteúdo das listas)
* inputs: referencia para a loja
* output: nenhum
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
void imprimeBanhoTosa(FILE* saida, BanhoTosa* loja)
{
    fprintf(saida, "=== %s ===\n", loja->nome);

    fprintf(saida, "Animais Bravos:\n");
    imprimeLista(saida, loja->bravos);

    fprintf(saida, "\n");
    
    fprintf(saida, "Animais Mansos: \n");
    imprimeLista(saida, loja->mansos);

    fprintf(saida, "\n");
}


/* Calcula o valor que a loja vai receber caso todos os animais tomem banho.
 Valor Gato: 30 reais, Valor Cachorro: 40 reais. Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
* inputs: referencia para a loja
* output: valor da receita
* pre-condicao: loja alocada
* pos-condicao: nenhuma alteração feita nos conteúdos das estruturas de dados */
float calculaReceita(BanhoTosa* loja)
{
    return calculaValor(loja->bravos) + calculaValor(loja->mansos);
}


/* Libera toda a memória alocada
* inputs: referencia para a loja
* output: não tem
* pre-condicao: loja alocada
* pos-condicao: Toda a memória liberada, a não ser gatos e cachorros, que são responsabilidade do cliente. */
void liberaBanhoTosa(BanhoTosa* loja)
{
    liberaLista(loja->bravos);
    liberaLista(loja->mansos);

    free (loja->nome);
    free (loja);
}

//
//  Este é o testador3.c, testa TODAS as funcionalidades
//  Pode valer até 10 pontos.
//
//
//  Created by Patricia Dockhorn Costa on 19/06/22.
//

#include <stdio.h>
#include <stdlib.h>

#include "tBanhoTosa.h"

enum
{
    MANSO, BRAVO
};

int main(int argc, const char * argv[]) {

    //cadastra uns cachorrinhos e gatinhos
    //nome e nível de agressividade
    
    tCao* iris = inicCachorro("Iris", BRAVO);
    tCao* bob = inicCachorro("Bob", MANSO);
    tCao* baby = inicCachorro("Baby", MANSO);

    tGato* branca = inicGato("Branca", BRAVO);
    tGato* ronaldo = inicGato("RonaldoCesar", MANSO);
    

    //cria uma instância do banho tosa
    BanhoTosa* loja = inicBanhoTosa("PetShow");
        
    //cadastra os cachorrinhos e gatinhos
    cadastraGato(loja, branca);
    cadastraGato(loja, ronaldo);
    
    cadastraCachorro(loja, iris);
    cadastraCachorro(loja, bob);
    cadastraCachorro(loja, baby);
    
    FILE* saida = fopen("saida.txt", "w");
    if (saida == NULL) exit(1);

    //imprime tudo
    imprimeBanhoTosa(saida, loja);
    
    //muda nível de agressividade (por exemplo, bob ficou agressivo)
    atribuiNivelAgressividadeCachorro(bob, BRAVO);
    
    //precisa atualizar a situação do Bob na loja
    atualizaSituacaoCachorro(loja, bob);
    
    //mesma coisa com a branca
    atribuiNivelAgressividadeGato(branca, MANSO);
    atualizaSituacaoGato(loja, branca);

    //Imprime tudo agora, com a nova situação da loja
    imprimeBanhoTosa(saida, loja);
    
    
    //calcula valor a receber
    float valor = calculaReceita(loja);
    printf("\nValor a Receber %.2f\n", valor);
    
    //libera tudo
    liberaBanhoTosa(loja);
    
    liberaGato(branca);
    liberaGato(ronaldo);
    
    liberaCachorro(iris);
    liberaCachorro(bob);
    liberaCachorro(baby);

    return 0;
}

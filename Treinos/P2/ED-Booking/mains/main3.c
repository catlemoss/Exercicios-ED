//
//  main3.c
//  Testa criacao, insercao, impressao, retira e liberacao (vale ateh 10,0)
//  ReservasED
//
//  Created by Patricia Dockhorn Costa on 24/06/25.
//

#include <stdio.h>
#include "EDBooking.h"

int main(int argc, const char * argv[]) {

    
    //iniciando os EdBooking dos hotéis
    EdBooking* aruan = criaEdBooking("Aruan");
    EdBooking* quality = criaEdBooking("Quality");
    
    //fazendo um "banco" de reservas do hotel Aruan
    Reserva* patricia_aruan = criaReserva("Patricia");
    Reserva* joao_aruan = criaReserva("Joao");
    Reserva* iris_aruan = criaReserva("Iris");
    Reserva* edu_aruan = criaReserva("Edu");
    
    //fazendo um "banco" de reservas do hotel Quality
    Reserva* bob_quality = criaReserva("Bob");
    Reserva* maria_quality = criaReserva("Maria");
    Reserva* alice_quality = criaReserva("Alice");
    
    //imprime com nada, soh para verificar
    imprimeEdBooking(aruan);
    imprimeEdBooking(quality);
    
    //insere as reservas do Hotel Aruan
    insereReserva(aruan, patricia_aruan);
    insereReserva(aruan, joao_aruan);
    insereReserva(aruan, iris_aruan);
    insereReserva(aruan, edu_aruan);
    
    //insere as reservas do Hotel Quality
    insereReserva(quality, bob_quality);
    insereReserva(quality, maria_quality);
    insereReserva(quality, alice_quality);
 
    //imprime com tudo na lista de reservas "gerais"
    imprimeEdBooking(aruan);
    imprimeEdBooking(quality);
    
    //Gerencia as reservas do Hotel Aruan
    pagaReserva(patricia_aruan);
    pagaReserva(joao_aruan);
    atualizaReserva(aruan, patricia_aruan);//vai para "confirmadas"
    atualizaReserva(aruan, joao_aruan); //vai para "confirmadas"
    atualizaReserva(aruan, edu_aruan); //deve ir para "lixo"
    
    imprimeEdBooking(aruan);
    
    //Gerencia as reservas do Hotel Quality
    pagaReserva(bob_quality);
    atualizaReserva(quality, bob_quality); //vai para "confirmadas"
    pagaReserva(alice_quality);
    atualizaReserva(quality, alice_quality); //vai para "confirmadas"
    atualizaReserva(quality, maria_quality);//deve ir para "lixo"
    
    imprimeEdBooking(quality);
    
    //libera os sistemas
    liberaEdBooking(aruan);
    liberaEdBooking(quality);
    
    //libera as reservas
    liberaReserva(patricia_aruan);
    liberaReserva(joao_aruan);
    liberaReserva(iris_aruan);
    liberaReserva(edu_aruan);

    liberaReserva(bob_quality);
    liberaReserva(maria_quality);
    liberaReserva(alice_quality);
    
    
    return 0;
}


//
//  main1.c
//  Testa criacao, insercao e impressao (vale ateh 6,0)
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
    
    return 0;
}

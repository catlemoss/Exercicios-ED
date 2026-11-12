//
//  Reserva.c
//  ReservasED
//
//  Created by Patricia Dockhorn Costa on 24/06/25.
//

#include "Reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Tipo que define uma reserva no sistema
struct reserva {
    int id; //identificador único da reserva
    char* dono;
    time_t criacao; //tive a ideia de usar este atributo para retirar todas as reservas "antigas", mas achei que ficaria muito complicado para 2 horas :)
    int confirmada; // 0 (nao confirmada), 1 (confirmada)
};

Reserva* criaReserva (char* dono){
    //variável estática para manter o valor anterior de id
    static int id = 0;
    Reserva* nova = malloc (sizeof(Reserva));
    nova->id = id++;
    nova->dono = strdup (dono);
    //pega o tempo "agora" para a reserva
    nova->criacao = time (NULL);
    //inicia todas confirmadas
    nova->confirmada = 0;
    
    return nova;
}


int retornaId(Reserva* reserva){
    return reserva->id;
}

void pagaReserva (Reserva* reserva){
    reserva->confirmada = 1;
}

int ehConfirmada(Reserva* reserva){
    return reserva->confirmada;
}


void imprimeReserva(Reserva* reserva){
    
    printf("      Reserva %d, Dono: %s, Dia/hora: %s", reserva->id, reserva->dono, ctime(&reserva->criacao));
}

void liberaReserva(Reserva* reserva){
    
    free(reserva->dono);
    free(reserva);
}

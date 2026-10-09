//
//  Reserva.h
//  ReservasED
//
//  Created by Patricia Dockhorn Costa on 24/06/25.
//

#ifndef Reserva_h
#define Reserva_h

#include <stdio.h>

/*Tipo opaco que define uma reserva no sistema de reservas
*/
typedef struct reserva Reserva;

 /* Cria uma reserva de uma determinada pessoa
 * inputs: nome da pessoa que fez a reserva, que deve ser alocado dinamicamente
 * output: Reserva alocada
 * pre-condicao: string dono não nula
 * pos-condicao: reserva alocada, com seus atributos inicializados*/
Reserva* criaReserva (char* dono);

/* Retorna o identificador único da reserva
* inputs: a reserva
* output: identificador único da reserva
* pre-condicao: reserva alocada e não nula
* pos-condicao: reserva inalterada */
int retornaId(Reserva* reserva);

/* "Paga" a reserva, ou seja, faz a confirmacao da reserva
* inputs: a reserva
* output: não tem
* pre-condicao: reserva alocada e não nula
* pos-condicao: confirmacao da reserva alterada para paga */
void pagaReserva (Reserva* reserva);


/* Retorna se a reserva estah confirmada(1) ou nao(0)
* inputs: a reserva
* output: confirmada(1) ou nao confirmada (0)
* pre-condicao: reserva alocada e não nula
* pos-condicao: reserva inalterada */
int ehConfirmada(Reserva* reserva);


/* Imprime os dados da reserva, no formato exemplo:
 * * Reserva 2, Dono: Iris, Dia/hora: Tue Jun 24 13:45:05 2025
* inputs: a reserva
* output: não tem
* pre-condicao: reserva alocada e não nula
* pos-condicao: reserva inalterada */
void imprimeReserva(Reserva* reserva);

//libera a memória alocada para a reserva
/* Libera a memória alocada para a reserva
* inputs: a reserva
* output: não tem
* pre-condicao: reserva alocada e não nula
* pos-condicao: toda a memoria alocada para a reserva eh liberada */
void liberaReserva(Reserva* reserva);


#endif /* Reserva_h */

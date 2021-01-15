/*
 * DIO_CONFIG.h
 *
 * Created: 11/12/2020 7:22:27 PM
 *  Author: karim
 */ 

/*#define  ---> Text Replacement*/

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_
/*CPU library*/
#include "CPU_CONFIGURATION.h"
/************************************** DIO-Registers *******************************************/
/*
#define DDRA  (*(volatile Uint8t*)(0x3A))
#define PORTA (*(volatile Uint8t*)(0x3B))
#define PINA  (*(volatile Uint8t*)(0x39))

#define DDRB  (*(volatile Uint8t*)(0x37))
#define PORTB (*(volatile Uint8t*)(0x38))
#define PINB  (*(volatile Uint8t*)(0x36))

#define DDRC  (*(volatile Uint8t*)(0x34))
#define PORTC (*(volatile Uint8t*)(0x35))
#define PINC  (*(volatile Uint8t*)(0x33))

#define DDRD  (*(volatile Uint8t*)(0x31))
#define PORTD (*(volatile Uint8t*)(0x32))
#define PIND  (*(volatile Uint8t*)(0x30))
*/
/*DIO PORTS*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3
/*DIO PINS*/
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7
/*DIO PIN State*/
#define DIO_PIN_LOW  0
#define DIO_PIN_HIGH 1
/*DIO PIN Direction*/
#define DIO_PIN_INPUT  0
#define DIO_PIN_OUTPUT 1
/*DIO PORT State*/
#define DIO_PORT_LOW  0x00 /*0000 0000*//*0*/
#define DIO_PORT_HIGH 0xFF /*1111 1111*//*255*/
/*DIO PORT Direction*/
#define DIO_PORT_INPUT  0x00
#define DIO_PORT_OUTPUT 0xFF                                                                  
#endif /* DIO_CONFIG_H_ */
/*	Author: jbui019
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	//Inputs
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	//Output
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;

    while (1) {
	unsigned char i;
	unsigned char count = 0x00;
	tempA = PINA;
	tempB = PINB;

	for(i = 0; i < 8; i++){
		if((tempA & (0x01 << i)) != 0){
			count++;
		}			
	}

	for(i = 0; i < 8; i++){
                if((tempB & (0x01 << i)) != 0){
                        count++;
                }
        }
	
	PORTC = count;
	

    }
    return 1;
}

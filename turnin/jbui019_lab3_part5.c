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
	//Inputs/Output
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;

    /* Insert your solution below */
	unsigned char tempD = 0x00;
	unsigned char tempBI = 0x00;
	unsigned char tempBO = 0x00;
	//unsigned char tempB = 0x00;

    while (1) {
	tempD = PIND;
	tempBI = PINB & 0x01;
	tempBO = 0x00;

	if(tempD >= 0x23){
		tempBO = 0x02;
	}
	else if((tempD < 0x23) && (tempD >= 0x03)){
		tempBO = 0x04;
	}		 	
	else{
		tempBO = 0x00;
	}			
	
	PORTB = tempBO | tempBI;
    }
    return 1;
}

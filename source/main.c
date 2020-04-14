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
	//DDRB = 0x00; PORTB = 0xFF;
	//Output
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char tempA = 0x00;
	unsigned char tempC = 0x00;
	//unsigned char tempB = 0x00;

    while (1) {
	tempA = PINA & 0x0F;
	tempC = 0x00;

	if(tempA == 0x00){
		tempC = 0x00;
	}
	//Levels 1-2
	else if(tempA <3){
		tempC = 0x60;	
	}
	//levels 3-4
	else if(tempA < 5){
		tempC = 0x70;
	}
	//levels 5-6
	else if(tempA < 7){
		tempC = 0x38;
	}
	//levels 7-9
	else if(tempA < 10){
		tempC = 0x3C;
	}
	//levels 10-12
	else if(tempA < 13){
		tempC = 0x3E;
	}	
	//levels 13-15
	else{
		tempC = 0x3F;
	}
	
	
	
	PORTC = tempC;	


	

    }
    return 1;
}

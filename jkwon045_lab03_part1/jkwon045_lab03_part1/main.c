/* Partner(s) Name & E-mail: Fei Yao Li fli034@ucr.edu
 * Lab Section: 21
 * Assignment: Lab 3 Exercise 1
 * Exercise Description: [optional - include for your own benefit]
 * 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */ 

#include <avr/io.h>

enum LT_STATES { Init, Press1, WaitP1, Press2, WaitP2} state;

void LT_TickFct(){
	unsigned char a0 = PINA & 0x01;
	
	switch(state){ //Transitions
		case Init:
			state = Press1;
			break;
		case Press1:
			state = ( a0 == 1 ) ? Press1 : WaitP1;
			break;
		case WaitP1:
			state = ( a0 == 0 ) ? WaitP1 : Press2;
			break;
		case Press2:
			state = ( a0 == 1 ) ? Press2 : WaitP2;
			break;
		case WaitP2:
			state = ( a0 == 0 ) ? WaitP2 : Press1;
			break;
		default:
			state = Init;
			break;	
	}
	
	switch(state){ //Actions
		case Init:
			PORTB = 0x01;
			break;
		case Press1:
			PORTB = 0x01;
			break;
		case WaitP1:
			break;
		case Press2:
			PORTB = 0x02;
			break;
		case WaitP2:
			break;
		default:
			break;		
	}
	
};


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Initializing Input
	DDRB = 0xFF; PORTB = 0x00; // Initializing Output
    while (1) 
    {
		LT_TickFct();
    }
}


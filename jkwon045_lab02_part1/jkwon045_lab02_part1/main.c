/*	Partner(s) Name & E-mail: Fei Yao Li fli034@ucr.edi
 *	Lab Section: 21
 *	Assignment: Lab # 2 Exercise # 1
 *	Exercise Description: [optional - include for your own benefit]
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */


#include <avr/io.h>

// Bit-access function
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
	//Initializing Ports
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
    DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
	unsigned char count = 0;
	
    while (1) 
    {
		count = 0;
		
		for( unsigned char i = 0; i < 8; i++ ){
			count = (GetBit(PINA, i) == 1) ? count+1 : count;
			count = (GetBit(PINB, i) == 1) ? count+1 : count;
		}
		
		PORTC = count;
    }
}


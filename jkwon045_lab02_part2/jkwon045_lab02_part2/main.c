/*	Partner(s) Name & E-mail: Fei Yao Li fli034@ucr.edi
 *	Lab Section: 21
 *	Assignment: Lab # 2 Exercise # 2
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
    DDRA = 0x00; PORTA = 0xFF; //PortA is an input
	DDRC = 0xFF; PORTC = 0x00; //PortC is an output
 
	unsigned char fuelLevel = 0x00;
	unsigned char indicator = 0x00;
    while (1) 
    {
		indicator = 0x00;
		fuelLevel = PINA & 0x0F;
		if ( fuelLevel > 0 ) indicator = SetBit(indicator, 5, 1);
		if ( fuelLevel > 2 ) indicator = SetBit(indicator, 4, 1);
		if ( fuelLevel > 4 ) indicator = SetBit(indicator, 3, 1);
		if ( fuelLevel > 6 ) indicator = SetBit(indicator, 2, 1);
		if ( fuelLevel > 9 ) indicator = SetBit(indicator, 1, 1);
		if ( fuelLevel > 12 ) indicator = SetBit(indicator, 0, 1);
		
		if ( fuelLevel < 5 ) indicator = SetBit(indicator, 6, 1);
		
		PORTC = indicator;
	}
}


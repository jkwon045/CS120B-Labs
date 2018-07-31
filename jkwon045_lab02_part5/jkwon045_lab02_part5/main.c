/*
 * jkwon045_lab02_part5.c
 *
 * Created: 7/31/2018 2:07:44 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}

int main(void)
{
    DDRD = 0x00; PORTD = 0xFF; //input
	DDRB = 0xFE; PORTB = 0x00; //input for LSB & output for Rest
	
	unsigned char indicator = 0x00;
	unsigned short weight = 0;
    while (1) 
    {
		//Zeroing out values
		weight = 0;
		indicator = 0x00;
		
		weight = (PIND << 1) + GetBit(PINB, 0);
		
		if ( weight > 70 ) indicator = SetBit(indicator, 1, 1);
		else if ( weight > 5 ) indicator = SetBit(indicator, 2, 1);
		
		PORTB = indicator;
		
    }
}


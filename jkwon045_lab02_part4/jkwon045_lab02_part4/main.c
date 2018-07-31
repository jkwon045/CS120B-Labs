/*
 * jkwon045_lab02_part4.c
 *
 * Created: 7/31/2018 1:59:06 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; //Input
	DDRB = 0xFF; PORTB = 0x00; //Output
	DDRC = 0xFF; PORTC = 0x00; //Output
    while (1) 
    {
		PORTB = (PINA & 0xF0) >> 4;
		PORTC = (PINA & 0x0F) << 4;
    }
}


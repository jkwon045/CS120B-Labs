/*
 * jkwon045_lab01_part2.c
 *
 * Created: 7/30/2018 2:13:49 PM
 * Author : ucrcse
 */ 

#include <avr/io.h>


int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; //Port A is input
	DDRC = 0xFF; PORTC = 0x00; //Port C is output
	
	//Values to store if parking spot is full
	unsigned char ps0 = 0x00;
	unsigned char ps1 = 0x00;
	unsigned char ps2 = 0x00;
	unsigned char ps3 = 0x00;
	//Output
	unsigned int cntavail = 0x00;
    /* Replace with your application code */
    while (1) 
    {
		cntavail = 0x00;
		//Reading pin values
		ps0 = PINA & 0x01;
		ps1 = PINA & 0x02;
		ps2 = PINA & 0x04;
		ps3 = PINA & 0x08;
		
		if (ps0 == 0x00){
			cntavail++;
		}
		if (ps1 == 0x00){
			cntavail++;
		}
		if (ps2 == 0x00){
			cntavail++;
		}
		if (ps3 == 0x00){
			cntavail++;
		}
		
		PORTC = cntavail;	
    }
}


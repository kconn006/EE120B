/*
 * EE120B_lab1_pt1.c
 *
 * Created: 7/31/2018 9:38:48 AM
 * Author : Keilani
 *Partner : Kiana McCullough
 */ 
#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs,

	// initialize to 0s
	unsigned char tmpB = 0x00; 	// Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A

	while(1)
	{
		// (1) Read input
		tmpA = PINA & 0x03;
		
		//led = 1 when door is open and light is 0

		if (tmpA == 0x01) { // True if PA0 is 1
			tmpB = (tmpB & 0xFE) | 0x01;
			// (clear rightmost 2 bits, then set to 1)
		}

		else {
			tmpB = 0x00;
		}

		PORTB = tmpB;
	}
	
	return 0;
}
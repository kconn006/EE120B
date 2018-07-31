/*
 * EE120B_lab1_pt1.c
 *
 * Created: 7/31/2018 9:38:48 AM
 * Author : Keilani
 */ 

#include <avr/io.h>
#define garage_sensor PINA 
#define light_sensor PINA 
#define  LED PORTA 
int main(void)
{
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	
	while(1)
	{
		// 1) Read input
		//light sensor = PA1
		light_sensor = PINA & 0x03;
		garage_sensor = PINA & 0x01;

		// 2) Perform computation
		// if PA1 is 1, set PB0 = 00, else = if PA0 is 1, PB0 = 1
		if (light_sensor & 0x01 == 0) { 
			LED = 0;
		}
		else {
			//Garage_sensor = PA0
			if (garage_sensor == 1) {
				LED = 1;
			}
			if else {
				LED = 0;
		}
		// 3) Write output
		PORTB = LED;
	}
	return 0;
}

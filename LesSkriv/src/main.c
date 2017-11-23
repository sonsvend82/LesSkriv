// INCLUDE-files
#include <board.h>
#include <sysclk.h>
#include <stdio_serial.h>
#include <gpio.h>
#include <conf_usart_serial.h>
#include <Egen.h>
// Learn about volatile variables.
// http://en.wikipedia.org/wiki/Volatile_variable
// Function that initialize clock, board and serial port.

void init(void){
	const usart_serial_options_t usart_serial_options =
	{
		.baudrate = USART_SERIAL_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits = USART_SERIAL_STOP_BIT
	};
	//Initialize the synchronous clock system.
	sysclk_init();
	//Initialize the board. The board-specific conf_board.h file contains
	//the configuration of the board initialization.
	board_init();
	// Initialize Serial Interface using Stdio Library
	stdio_serial_init(USART_SERIAL_C0, &usart_serial_options);
}
//Example - how to use serial port
int main(void){
	init();
	// Print welcome message
	printf("\n\rHello AVR World!\n\r");
}
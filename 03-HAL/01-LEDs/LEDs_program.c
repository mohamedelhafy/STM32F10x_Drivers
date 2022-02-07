/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 7 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/

// first including my Standerd LIBs
#include "STD_TYPES.h"
#include "BIT_MATH.h"


// including the Needed Interface files from lower layers 
// here there is no lower layers
#include "GPIO_interface.h"

// including My own Driver Files in this order
#include "LEDs_interface.h"
#include "LEDs_private.h"
#include "LEDs_config.h"

/********************************************************************************************************/
/*	Function Name        : LED_vInit																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description : initializing the LED by make the pin that connect to output					*/
/********************************************************************************************************/
void LED_vInit(uint8 copy_u8PortName, uint8 copy_u8PinNumber)
{
	GPIO_vSetPinMode(copy_u8PortName, copy_u8PinNumber, OUTPUT_2MHZ_PUSH_PULL);
}




/********************************************************************************************************/
/*	Function Name        : LED_vTurnOn																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName and unsigned char copy_u8PinNumber				*/
/*							unsigned char copy_u8Mode													*/
/*	Function Description : turn the LED on By set the pin to high										*/
/********************************************************************************************************/
void LED_vTurnOn(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode)
{
	switch (copy_u8Mode)
	{
		case ACTIVE_HIGH	: // Active High = Logic high ON the pin to turn on
							GPIO_vWritePin(copy_u8PortName, copy_u8PinNumber, HIGH_OUT);
							break;
		case ACTIVE_LOW		: // Active Low = Logic low ON the pin to turn on
							GPIO_vWritePin(copy_u8PortName, copy_u8PinNumber, LOW_OUT);
							break;
		default				:
							/* Return Error */ break;
	}
}





/********************************************************************************************************/
/*	Function Name        : LED_vTurnOff																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*							unsigned char uint8 copy_u8Mode												*/
/*	Function Description : turn the LED on By set the pin to high										*/
/********************************************************************************************************/
void LED_vTurnOff(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode)
{
	switch (copy_u8Mode)
	{
		case ACTIVE_HIGH	: // Active High = Logic high ON the pin to turn off
							GPIO_vWritePin(copy_u8PortName, copy_u8PinNumber, LOW_OUT);
							break;
		case ACTIVE_LOW		: // Active Low = Logic low ON the pin to turn off
							GPIO_vWritePin(copy_u8PortName, copy_u8PinNumber, HIGH_OUT);
							break;
		default				:
							/* Return Error */ break;
	}
}





/********************************************************************************************************/
/*	Function Name        : LED_vToggle																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description : toggle the LED 																*/
/********************************************************************************************************/
void LED_vToggle(uint8 copy_u8PortName, uint8 copy_u8PinNumber)
{
	GPIO_vToggle(copy_u8PortName, copy_u8PortName);
}





/********************************************************************************************************/
/*	Function Name        : LED_u8readState																*/
/*	Function Returns     : unsigned char																*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description : read the value of the led is it on or not									*/
/********************************************************************************************************/
uint8 LED_u8readState(uint8 copy_u8PortName, uint8 copy_u8PinNumber)
{
	return GPIO_u8GetPinVal(copy_u8PortName, copy_u8PinNumber);
}
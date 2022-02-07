/****************************************************************************************/
/* Author  : Mohamed Farag Elhafy														*/
/* Date    : 7 FEB 2022			 														*/
/* Version : V02		         														*/
/****************************************************************************************/

// first including my Standerd LIBs
#include "STD_TYPES.h"
#include "BIT_MATH.h"


// including the Needed Interface files from lower layers 
// here there is no lower layers
#include "GPIO_interface.h"

// including My own Driver Files in this order
#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"


/********************************************************************************************************/
/*	Function Name        : SWITCH_vInit																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*							unsigned char copy_u8Mode 													*/
/*	Function Description : Set the pin as input															*/
/********************************************************************************************************/
void SWITCH_vInit(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode)
{
	switch(copy_u8Mode)
	{
		case INTERNAL_PULLED_UP		:
								GPIO_vSetPinMode(copy_u8PortName, copy_u8PortName, INPUT_PULLED);
								GPIO_vWritePin(copy_u8PortName, copy_u8PortName, HIGH_OUT);
								break;

		case INTERNAL_PULLED_DOWN	:
								GPIO_vSetPinMode(copy_u8PortName, copy_u8PortName, INPUT_PULLED);
								GPIO_vWritePin(copy_u8PortName, copy_u8PortName, HIGH_OUT);
								break;

		case FLOATING				:
								GPIO_vSetPinMode(copy_u8PortName, copy_u8PinNumber, INPUT_FLOATING);
								break;
		default						: /* Return Error */ break;
	}
}





/********************************************************************************************************/
/*	Function Name        : SWITCH_u8read																*/
/*	Function Returns     : unsigned char																*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*							unsigned char copy_u8Mode 													*/
/*	Function Description : access the Pin register and read the bit value of the this pin 				*/
/********************************************************************************************************/
uint_8 SWITCH_u8read(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode)
{
	uint8 LOC_u8Status = DUMMY_DATA;
	switch(copy_u8Mode)
	{
		case INTERNAL_PULLED_UP 	:
		case FLOATING 				:
								if (GPIO_u8GetPinVal(copy_u8PortName, copy_u8PinNumber))
								{
									LOC_u8Status = NOT_SET ;
								}
								else
								{
									LOC_u8Status = SET ;
								}
								break;
		case INTERNAL_PULLED_DOWN	:
								if (GPIO_u8GetPinVal(copy_u8PortName, copy_u8PinNumber))
								{
									LOC_u8Status = SET ;
								}
								else
								{
									LOC_u8Status = NOT_SET ;
								}
								break;
		default 					: /* Return Error */ break;
	}
	return LOC_u8Status;
}
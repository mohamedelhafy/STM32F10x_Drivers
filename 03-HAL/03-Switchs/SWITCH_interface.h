/****************************************************************************************/
/* Author  : Mohamed Farag Elhafy														*/
/* Date    : 7 FEB 2022																	*/
/* Version : V02																		*/
/****************************************************************************************/


#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H


#define INTENAL_PULLED_UP		0
#define INTENAL_PULLED_DOWN		1
#define FLOATING				2



#define NOT_SET		0
#define SET 		1

/********************************************************************************************************/
/*	Function Name        : SWITCH_vInit																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*							unsigned char copy_u8Mode 													*/
/*	Function Description : Set the pin as input															*/
/********************************************************************************************************/
void SWITCH_vInit(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode);





/********************************************************************************************************/
/*	Function Name        : SWITCH_u8read																*/
/*	Function Returns     : unsigned char																*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*							unsigned char copy_u8Mode 													*/
/*	Function Description : access the Pin register and read the bit value of the this pin 				*/
/********************************************************************************************************/
uint_8 SWITCH_u8read(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode);






#endif // SWITCH_INTERFACE_H
/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 7 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef LEDS_INTERFACE_H
#define LEDS_INTERFACE_H

#define ACTIVE_HIGH		0 
#define ACTIVE_LOW		1



/********************************************************************************************************/
/*	Function Name        : LED_vInit																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description : initializing the LED by make the pin that connect to output					*/
/********************************************************************************************************/
void LED_vInit(uint8 copy_u8PortName, uint8 copy_u8PinNumber);





/********************************************************************************************************/
/*	Function Name        : LED_vTurnOn																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName and unsigned char copy_u8PinNumber				*/
/*							unsigned char copy_u8Mode													*/
/*	Function Description : turn the LED on By set the pin to high										*/
/********************************************************************************************************/
void LED_vTurnOn(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode);





/********************************************************************************************************/
/*	Function Name        : LED_vTurnOff																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*							unsigned char uint8 copy_u8Mode												*/
/*	Function Description : turn the LED on By set the pin to high										*/
/********************************************************************************************************/
void LED_vTurnOff(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode);





/********************************************************************************************************/
/*	Function Name        : LED_vToggle																	*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description : toggle the LED 																*/
/********************************************************************************************************/
void LED_vToggle(uint8 copy_u8PortName, uint8 copy_u8PinNumber);





/********************************************************************************************************/
/*	Function Name        : LED_u8readState																*/
/*	Function Returns     : unsigned char																*/
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description : read the value of the led is it on or not									*/
/********************************************************************************************************/
uint8 LED_u8readState(uint8 copy_u8PortName, uint8 copy_u8PinNumber);


#endif // LEDS_INTERFACE_H
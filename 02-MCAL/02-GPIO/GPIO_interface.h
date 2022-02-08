/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 6 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define HIGH_OUT 					1
#define LOW_OUT						0

// port names
#define	PORTA 		0
#define	PORTB 		1
#define	PORTC 		2
#define	PORTD 		3
#define	PORTE 		4
#define	PORTF 		5
#define	PORTG 		6


// pin numbers
#define PIN0		0
#define PIN1		1
#define PIN2		2
#define PIN3		3
#define PIN4		4
#define PIN5		5
#define PIN6		6
#define PIN7		7
#define PIN8		8
#define PIN9		9
#define PIN10		10
#define PIN11		11
#define PIN12		12
#define PIN13		13
#define PIN14		14
#define PIN15		15


// Mode And Configs
#define INPUT_ANALOG						0b0000
#define INPUT_FLOATING						0b0100
#define INPUT_PULLED						0b1000
#define OUTPUT_10MHZ_PUSH_PULL				0b0001
#define OUTPUT_10MHZ_OPEN_DRAIN				0b0101
#define OUTPUT_10MHZ_ALTFUNC_PUSH_PULL		0b1001
#define OUTPUT_10MHZ_ALTFUNC_OPEN_DRAIN		0b1101
#define OUTPUT_2MHZ_PUSH_PULL				0b0010
#define OUTPUT_2MHZ_OPEND_RAIN				0b0110
#define OUTPUT_2MHZ_ALTFUNC_PUSH_PULL		0b1010
#define OUTPUT_2MHZ_ALTFUNC_OPEN_DRAIN		0b1110
#define OUTPUT_50MHZ_PUSH_PULL				0b0011
#define OUTPUT_50MHZ_OPEND_RAIN				0b0111
#define OUTPUT_50MHZ_ALTFUNC_PUSH_PULL		0b1011
#define OUTPUT_50MHZ_ALTFUNC_OPEN_DRAIN		0b1111


/*********************************************************************************************************/
/*	Function Name        : GPIO_vSetPinMode                                                              */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portName unsigned char pinNumber unsigned char mode             */
/*	Function Description : Set pin Mode                                                                  */
/*********************************************************************************************************/
void GPIO_vSetPinMode(uint8 copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Mode);




/*********************************************************************************************************/
/*	Function Name        : GPIO_vWritePin                                                                */
/*	Function Returns     : void                                                                          */
/*	Function Arguments   : unsigned char portName unsigned char pinNumber unsigned char valwe            */
/*	Function Description : Set pin value                                                                 */
/*********************************************************************************************************/
void GPIO_vWritePin(uint8 portName, uint8 pinNumer, uint8 value);





/********************************************************************************************************/
/*	Function Name 		: GPIO_u8GetPinVal																*/
/*	Function Returns	: unsigned char																	*/
/*	Function Arguments	: unsigned char portName unsigned char copy_u8PinNumber 						*/
/*	Function Description: Return Pin value                                                              */
/********************************************************************************************************/
uint8 GPIO_u8GetPinVal(uint8 portName, uint8 pinNumer);






/********************************************************************************************************/
/*	Function Name 		: GPIO_vToggle																	*/
/*	Function Returns	: void																			*/
/*	Function Arguments	: unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description: toggle the Pin 																*/
/********************************************************************************************************/
void GPIO_vToggle(uint8 copy_u8PortName, uint8 copy_u8PinNumber);






/********************************************************************************************************/
/*	Function Name 		: GPIO_vLockPin																	*/
/*	Function Returns	: void																			*/
/*	Function Arguments	: unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description: Lock the Mode of Pin															*/
/********************************************************************************************************/
void GPIO_vLockPin(uint8 copy_u8PortName, uint8 copy_u8PinNumber);



#endif	// GPIO_INTERFACE_H
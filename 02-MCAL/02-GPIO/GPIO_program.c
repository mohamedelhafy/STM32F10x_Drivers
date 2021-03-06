/****************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                       */
/* Date    : 6 FEB 2022                                                                 */
/* Version : V02 and compatable with the other file V01                                 */
/****************************************************************************************/




// first including my Standerd LIBs
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// including the Needed Interface files from lower layers 
// here there is no lower layers
#include "RCC_interface.h"

// including My own Driver Files in this order
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

/********************************************************************************************************/
/*	Function Name        : GPIO_vSetPinMode                                                             */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber                 */
/*							unsigned char copy_u8copy_u8Mode                                            */
/*	Function Description : Set pin copy_u8Mode                                                          */
/********************************************************************************************************/
void GPIO_vSetPinMode(portName_t copy_u8PortName, pinNumber_t copy_u8PinNumber, uint8 copy_u8Mode)
{

	switch(copy_u8PortName)
	{
	/*********************************************************************************************************/
	/*                                              PORTA                                                    */
	/*********************************************************************************************************/
		case PORTA :
					if (copy_u8PinNumber <= 7)
					{
						/****************************************************************************/
						/*           if you use this Please don't forget to define var "i"          */
						/****************************************************************************/
						/*            you Can Loop 4 time And use tht SET and CLR Macros            */
						/*         with this code I Check the First Bit of the copy_u8Mode          */
						/*                     if it = 1 I will set the Bit                         */
						/*                    if it = 0 I will clear the Bit                        */
						/*                the Bit Number = (copy_u8PinNumber*4+i)                   */
						/****************************************************************************/
						/*	for (i=0;i<4;i++)                                                       */
						/*	{                                                                       */
						/*		if ((copy_u8Mode>>i)&1)                                             */
						/*		{                                                                   */
						/*		 	SET_BIT(PORTA_CRL , ((copy_u8PinNumber*4)+i));	                */
						/*		}                                                                   */
						/*		else                                                                */
						/*		{                                                                   */
						/*			CLR_BIT(PORTA_CRL , ((copy_u8PinNumber*4)+i));                  */
						/*		}                                                                   */
						/*	}                                                                       */
						/****************************************************************************/
						/*                              you Can also use this code                  */
						/****************************************************************************/
						/*                           Clear All Bit By ANDing it with 0              */
						/*                           And ORing it with the copy_u8Mode              */
						/****************************************************************************/	
						PORTA_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTA_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
					else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTA_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTA_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTB                                               */
	/*********************************************************************************************************/
		case PORTB :
					if (copy_u8PinNumber <= 7)
					{	
						PORTB_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTB_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
						else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTB_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTB_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                    PORTC                                              */
	/*********************************************************************************************************/	
		case PORTC :
						if (copy_u8PinNumber <= 7)
					{	
						PORTC_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTC_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
						else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTC_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTC_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTD                                               */
	/*********************************************************************************************************/
		case PORTD :
					if (copy_u8PinNumber <= 7)
					{	
						PORTD_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Location	s 
						PORTD_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
						else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTD_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTD_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                    PORTE                                              */
	/*********************************************************************************************************/
		case PORTE :
					if (copy_u8PinNumber <= 7)
					{	
						PORTE_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Location	s 
						PORTE_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
						else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTE_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTE_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                  PORTF                                                */
	/*********************************************************************************************************/	
		case PORTF :
					if (copy_u8PinNumber <= 7)
					{	
						PORTF_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Location	s 
						PORTF_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
						else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTF_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTF_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                              PORTG                                                    */
	/*********************************************************************************************************/
		case PORTG :
						if (copy_u8PinNumber <= 7)
				{	
						PORTG_CRL &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Location	s 
						PORTG_CRL |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable	
					}
						else if (copy_u8PinNumber <= 15)
					{
						copy_u8PinNumber-=8;
						PORTG_CRH &= ~ ((0b1111) << (copy_u8PinNumber*4));	// Clear All Bits In This Locations 
						PORTG_CRH |= ((copy_u8Mode) << (copy_u8PinNumber*4));		// Set the Bits Accordig to the copy_u8Mode variable
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                 Default                                               */
	/*********************************************************************************************************/
		default     : /* Return Error */ break;
	}
}





/*********************************************************************************************************/
/*	Function Name        : GPIO_vWritePin                                                            */
/*	Function Returns     : void                                                                      */
/*	Function Arguments   : unsigned char portName unsigned char pinNumber unsigned char valwe        */
/*	Function Description : Set pin value                                                             */
/*********************************************************************************************************/
void GPIO_vWritePin(portName_t copy_u8PortName, uint8 copy_u8PinNumber, uint8 copy_u8Value)
{
	switch(copy_u8PortName)
	{
	/*********************************************************************************************************/
	/*                                                   PORTA                                               */
	/*********************************************************************************************************/
		case PORTA :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTA_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTA_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTA_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTA_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTB                                               */
	/*********************************************************************************************************/
		case PORTB :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTB_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTB_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTB_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTB_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTC                                               */
	/*********************************************************************************************************/
		case PORTC :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTC_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTC_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTC_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTC_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTD                                               */
	/*********************************************************************************************************/
		case PORTD :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTD_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTD_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTD_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTD_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTE                                               */
	/*********************************************************************************************************/
		case PORTE :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTE_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTE_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTE_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTE_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTF                                               */
	/*********************************************************************************************************/
		case PORTF :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTF_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTF_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTF_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTF_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
	/*                                                   PORTG                                               */
	/*********************************************************************************************************/
		case PORTG :
					if (copy_u8Value == HIGH_OUT)
					{
						// SET_BIT(PORTG_ODR, copy_u8PinNumber); // Read and Set Bit in ODR
						PORTG_BSRR = (1<<copy_u8PinNumber); // set the Bit Directly
					}
					else if (copy_u8Value == LOW_OUT)
					{
						// CLR_BIT(PORTG_ODR, copy_u8PinNumber); // Read and Clear Bit
						PORTG_BRR = (1<<copy_u8PinNumber); // Reset the Bit directly
					}
					else 
					{
						/* Return Error */
					}
					break;
	/*********************************************************************************************************/
		default     : /* Return Error */ break;
	}
}





/********************************************************************************************************/
/*	Function Name        : GPIO_u8GetPinVal                                                         */
/*	Function Returns     : unsigned char                                                            */
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber             */
/*	Function Description : Return Pin value                                                         */
/********************************************************************************************************/
uint8 GPIO_u8GetPinVal(portName_t copy_u8PortName, pinNumber_t copy_u8PinNumber)
{
	uint8 LOC_u8Result = DUMMY_DATA ;
	switch(copy_u8PortName)
	{
	/*********************************************************************************************************/
	/*                                            PORTA                                                      */
	/*********************************************************************************************************/
		case PORTA 	:
					LOC_u8Result = GET_BIT(PORTA_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTB                                                      */
	/*********************************************************************************************************/
		case PORTB 	:
					LOC_u8Result = GET_BIT(PORTB_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                               PORTC                                                   */
	/*********************************************************************************************************/
		case PORTC 	:
					LOC_u8Result = GET_BIT(PORTC_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                               PORTD                                                   */
	/*********************************************************************************************************/
		case PORTD 	:
					LOC_u8Result = GET_BIT(PORTD_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                               PORTE                                                   */
	/*********************************************************************************************************/
		case PORTE 	:
					LOC_u8Result = GET_BIT(PORTE_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                               PORTF                                                   */
	/*********************************************************************************************************/
		case PORTF 	:
					LOC_u8Result = GET_BIT(PORTF_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                               PORTG                                                   */
	/*********************************************************************************************************/
		case PORTG 	:
					LOC_u8Result = GET_BIT(PORTG_IDR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
		default		: /* Return Error */ break;
	}
	return LOC_u8Result;
}




/********************************************************************************************************/
/*	Function Name        : GPIO_vToggle                                                             */
/*	Function Returns     : void                                                                     */
/*	Function Arguments   : unsigned char copy_u8PortName unsigned char copy_u8PinNumber             */
/*	Function Description : toggle the Pin output                                                    */
/********************************************************************************************************/
void GPIO_vToggle(portName_t copy_u8PortName, pinNumber_t copy_u8PinNumber)
{
	switch(copy_u8PortName)
	{
	/*********************************************************************************************************/
	/*                                            PORTA                                                      */
	/*********************************************************************************************************/
		case PORTA 	:
					TOG_BIT(PORTA_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTB                                                      */
	/*********************************************************************************************************/
		case PORTB 	:
					TOG_BIT(PORTB_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTC                                                      */
	/*********************************************************************************************************/
		case PORTC 	:
					TOG_BIT(PORTC_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTD                                                      */
	/*********************************************************************************************************/
		case PORTD 	:
					TOG_BIT(PORTD_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTE                                                      */
	/*********************************************************************************************************/
		case PORTE 	:
					TOG_BIT(PORTE_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTF                                                      */
	/*********************************************************************************************************/
		case PORTF 	:
					TOG_BIT(PORTF_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTG                                                      */
	/*********************************************************************************************************/
		case PORTG 	:
					TOG_BIT(PORTG_ODR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
		default		: /* Return Error */ break;
	}
}





/********************************************************************************************************/
/*	Function Name 		: GPIO_vLockPin																	*/
/*	Function Returns	: void																			*/
/*	Function Arguments	: unsigned char copy_u8PortName unsigned char copy_u8PinNumber					*/
/*	Function Description: Lock the Mode of Pin															*/
/********************************************************************************************************/
void GPIO_vLockPin(portName_t copy_u8PortName, pinNumber_t copy_u8PinNumber)
{
	switch(copy_u8PortName)
	{
	/*********************************************************************************************************/
	/*                                            PORTA                                                      */
	/*********************************************************************************************************/
		case PORTA 	:
					SET_BIT(PORTA_LCKR, copy_u8PinNumber); 
					break;
	/*********************************************************************************************************/
	/*                                            PORTB                                                      */
	/*********************************************************************************************************/
		case PORTB 	:
					SET_BIT(PORTB_LCKR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTC                                                      */
	/*********************************************************************************************************/
		case PORTC 	:
					SET_BIT(PORTC_LCKR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTD                                                      */
	/*********************************************************************************************************/
		case PORTD 	:
					SET_BIT(PORTD_LCKR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTE                                                      */
	/*********************************************************************************************************/
		case PORTE 	:
					SET_BIT(PORTE_LCKR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTF                                                      */
	/*********************************************************************************************************/
		case PORTF 	:
					SET_BIT(PORTF_LCKR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
	/*                                            PORTG                                                      */
	/*********************************************************************************************************/
		case PORTG 	:
					SET_BIT(PORTG_LCKR, copy_u8PinNumber);
					break;
	/*********************************************************************************************************/
		default		: /* Return Error */ break;
	}
}




/********************************************************************************************************/
/*	Function Name 		: GPIO_vEnablePort                                                              */
/*	Function Returns	: void                                                                          */
/*	Function Arguments	: unsigned char copy_u8PortName                                                 */
/*	Function Description: Enable clock For port                                                         */
/********************************************************************************************************/
void GPIO_vEnablePort(uint8 copy_u8PortName)
{
	switch(copy_u8PortName)
	{
		case PORTA : RCC_vEnableClock(RCC_APB2, RCC_IOPA_EN); break; // Enable Clock for Port A
		case PORTB : RCC_vEnableClock(RCC_APB2, RCC_IOPB_EN); break; // Enable Clock for Port B
		case PORTC : RCC_vEnableClock(RCC_APB2, RCC_IOPC_EN); break; // Enable Clock for Port C
		case PORTD : RCC_vEnableClock(RCC_APB2, RCC_IOPD_EN); break; // Enable Clock for Port D
		case PORTE : RCC_vEnableClock(RCC_APB2, RCC_IOPE_EN); break; // Enable Clock for Port E
		case PORTF : RCC_vEnableClock(RCC_APB2, RCC_IOPF_EN); break; // Enable Clock for Port F
		case PORTG : RCC_vEnableClock(RCC_APB2, RCC_IOPG_EN); break; // Enable Clock for Port G
	}
}






/********************************************************************************************************/
/*	Function Name 		: GPIO_vEnablePort                                                              */
/*	Function Returns	: void                                                                          */
/*	Function Arguments	: unsigned char copy_u8PortName                                                 */
/*	Function Description: Enable clock For port                                                         */
/********************************************************************************************************/
void GPIO_vDisablePort(uint8 copy_u8PortName)
{
	switch(copy_u8PortName)
	{
		case PORTA : RCC_vDisableClock(RCC_APB2, RCC_IOPA_EN); break; // Disable Clock for Port A
		case PORTB : RCC_vDisableClock(RCC_APB2, RCC_IOPB_EN); break; // Disable Clock for Port B
		case PORTC : RCC_vDisableClock(RCC_APB2, RCC_IOPC_EN); break; // Disable Clock for Port C
		case PORTD : RCC_vDisableClock(RCC_APB2, RCC_IOPD_EN); break; // Disable Clock for Port D
		case PORTE : RCC_vDisableClock(RCC_APB2, RCC_IOPE_EN); break; // Disable Clock for Port E
		case PORTF : RCC_vDisableClock(RCC_APB2, RCC_IOPF_EN); break; // Disable Clock for Port F
		case PORTG : RCC_vDisableClock(RCC_APB2, RCC_IOPG_EN); break; // Disable Clock for Port G
	}
}
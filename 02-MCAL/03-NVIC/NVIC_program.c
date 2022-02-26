/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 9 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************LOWER_LAYERS***************/



/**************MY_HADER_FILES*************/
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"








/********************************************************************************************************/
/*	Function Name        : NVIC_vEnableInterrupt                                                        */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Set interrupt ensble in NVIC                                                 */
/********************************************************************************************************/
void NVIC_vEnableInterrupt(uint8 copy_u8IntNumber)
{
	if (copy_u8IntNumber<31)
	{
		/***************************************************************************************/
		/* writing 0 in the ISER Regs has no efact so i use the = instade of use SET_BIT Macro */
		/***************************************************************************************/
		NVIC_ISER0 = (1 << copy_u8IntNumber);
	}
	else if (copy_u8IntNumber < 63)
	{
		copy_u8IntNumber-=32;
		NVIC_ISER1 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 67)
	{
		copy_u8IntNumber-=64;
		NVIC_ISER2 = (1 << copy_u8IntNumber);
	}
	else
	{
		/*   Return Error   */
	}
}




/********************************************************************************************************/
/*	Function Name        : NVIC_vDisableInterrupt                                                       */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Disable interrupt ensble in NVIC                                             */
/********************************************************************************************************/
void NVIC_vDisableInterrupt(uint8 copy_u8IntNumber)
{
	if (copy_u8IntNumber<31)
	{
		/***************************************************************************************/
		/* writing 0 in the ICER Regs has no efact so i use the = instade of use SET_BIT Macro */
		/***************************************************************************************/
		NVIC_ICER0 = (1 << copy_u8IntNumber);
	}
	else if (copy_u8IntNumber < 63)
	{
		copy_u8IntNumber-=32;
		NVIC_ICER1 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 67)
	{
		copy_u8IntNumber-=64;
		NVIC_ICER2 = (1 << copy_u8IntNumber);
	}
	else
	{
		/*   Return Error   */
	}
}











/********************************************************************************************************/
/*	Function Name        : NVIC_vSetPendingFlag                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Set pending Flag                                                             */
/********************************************************************************************************/
void NVIC_vSetPendingFlag(uint8 copy_u8IntNumber)
{
	if (copy_u8IntNumber<31)
	{
		/***************************************************************************************/
		/* writing 0 in the ISPR Regs has no efact so i use the = instade of use SET_BIT Macro */
		/***************************************************************************************/
		NVIC_ISPR0 = (1 << copy_u8IntNumber);
	}
	else if (copy_u8IntNumber < 63)
	{
		copy_u8IntNumber-=32;
		NVIC_ISPR1 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 67)
	{
		copy_u8IntNumber-=64;
		NVIC_ISPR2 = (1 << copy_u8IntNumber);
	}
	else
	{
		/*   Return Error   */
	}
}











/********************************************************************************************************/
/*	Function Name        : NVIC_vSetPendingFlag                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Clear pending Flag                                                           */
/********************************************************************************************************/
void NVIC_vClearPendingFlag(uint8 copy_u8IntNumber)
{
	if (copy_u8IntNumber<31)
	{
		/***************************************************************************************/
		/* writing 0 in the ICPR Regs has no efact so i use the = instade of use SET_BIT Macro */
		/***************************************************************************************/
		NVIC_ICPR0 = (1 << copy_u8IntNumber);
	}
	else if (copy_u8IntNumber < 63)
	{
		copy_u8IntNumber-=32;
		NVIC_ICPR1 = (1 << copy_u8IntNumber);
	}
	else if(copy_u8IntNumber < 67)
	{
		copy_u8IntNumber-=64;
		NVIC_ICPR2 = (1 << copy_u8IntNumber);
	}
	else
	{
		/*   Return Error   */
	}
}







/********************************************************************************************************/
/*	Function Name        : NVIC_u8GetActiveFlag                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Get Active Flag that told me if this int is executed                         */
/********************************************************************************************************/
uint8 NVIC_u8GetActiveFlag(uint8 copy_u8IntNumber)
{
	uint8 Loc_u8Result;
	if (copy_u8IntNumber<31)
	{
		Loc_u8Result = GET_BIT(NVIC_IBAR0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber < 63)
	{
		copy_u8IntNumber-=32;
		Loc_u8Result = GET_BIT(NVIC_IBAR1 , copy_u8IntNumber);

	}
	else if(copy_u8IntNumber < 67)
	{
		copy_u8IntNumber-=64;
		Loc_u8Result = GET_BIT(NVIC_IBAR2 , copy_u8IntNumber);
	}
	else
	{
		Loc_u8Result = DUMMY_DATA;
	}
	return Loc_u8Result; 
}


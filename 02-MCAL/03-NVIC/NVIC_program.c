/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 1 MAR 2022                                                                   */
/* Version : V02                                                                          */
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
void NVIC_vEnableInterrupt(E_PinPerioity_t copy_u8IntNumber)
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
void NVIC_vDisableInterrupt(E_PinPerioity_t copy_u8IntNumber)
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
void NVIC_vSetPendingFlag(E_PinPerioity_t copy_u8IntNumber)
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
void NVIC_vClearPendingFlag(E_PinPerioity_t copy_u8IntNumber)
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
uint8 NVIC_u8GetActiveFlag(E_PinPerioity_t copy_u8IntNumber)
{
	uint8 Loc_u8Result;
	if (copy_u8IntNumber<31)
	{
		Loc_u8Result = GET_BIT(NVIC_IABR0 , copy_u8IntNumber);
	}
	else if (copy_u8IntNumber < 63)
	{
		copy_u8IntNumber-=32;
		Loc_u8Result = GET_BIT(NVIC_IABR1 , copy_u8IntNumber);

	}
	else if(copy_u8IntNumber < 67)
	{
		copy_u8IntNumber-=64;
		Loc_u8Result = GET_BIT(NVIC_IABR2 , copy_u8IntNumber);
	}
	else
	{
		Loc_u8Result = DUMMY_DATA;
	}
	return Loc_u8Result; 
}







/********************************************************************************************************/
/*	Function Name        : NVIC_vSetGroupSubType                                                        */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32GroupSubgroupType                                      */
/*	Function Description : Set Sw periority                                                             */
/********************************************************************************************************/
void NVIC_vSetGroupSubType(uint32 copy_u32GroupSubgroupType)
{
	/* set the Comp Of group and Sub Group */
	SBC_AIRCR = copy_u32GroupSubgroupType ;
}








/********************************************************************************************************/
/*	Function Name        : NVIC_vSetSWPeriority                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : signed char copy_s8IntId unsigned char copy_u8periority                      */
/*	Function Description : Set Sw periority                                                             */
/********************************************************************************************************/
void NVIC_vSetSWPeriority(sint8 copy_s8IntId , uint8 copy_u8GroupPeriority , uint8 copy_u8SubgroupPeriority)
{
	uint8 Loc_u8Periority = copy_u8SubgroupPeriority|copy_u8GroupPeriority ;
	
	/* External peripheral */

	if (copy_s8IntId >= 0)
	{
		NVIC_IPR[copy_s8IntId] = Loc_u8Periority << 4 ; // Set periority for InId
	}
	else
	{
		/* core peripheral */
	}
}

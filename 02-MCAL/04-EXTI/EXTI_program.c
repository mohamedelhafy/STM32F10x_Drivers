/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 27 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/




/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************LOWER_LAYERS***************/



/**************MY_HADER_FILES*************/
#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"






/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void EXTI_vEnableEXTI(E_Line_t copy_E_Line, E_Port_t copy_E_Port, E_State_t copy_E_Mode)
{
	switch(copy_E_Mode)
	{
		case RISE_EDGE: SET_BIT(EXTI->RTSR, copy_E_Line);  break; // Enable the Raising Edge Synsablity
		case FALL_EDGE: SET_BIT(EXTI->FTSR, copy_E_Line);  break; // Enable the Falling Edge Synsablity
		case ON_CHANGE: SET_BIT(EXTI->RTSR, copy_E_Line);         // Enable the Raising Edge Synsablity
                        SET_BIT(EXTI->FTSR, copy_E_Line);  break; // Enable the Falling Edge Synsablity
		default:   /* Return Error */                      break;
	}
	SET_BIT(EXTI->IMR, copy_E_Line);    // Set the Interrupt Not Masked

	AFIO_vSetEXTIConfigration(copy_E_Line, copy_E_Port);
}








/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void EXTI_vDisableEXTI(E_Line_t copy_E_Line)
{
	CLR_BIT(EXTI->IMR, copy_E_Line);    // Clear the Interrupt Not Masked
}








/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void EXTI_vSwTrigger(E_Line_t copy_E_Line)
{
	SET_BIT(EXTI->SWIER, copy_E_Line);    // Set The Software Interrupt Flag
}


/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 27 FEB 2022                                                                  */
/* Version : V01                                                                          */
/* Futur DEVS : Handle the ISRs                                                           */
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
/*	Function Name        : EXTI_vEnableEXTI                                                             */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : E_Line_t copy_E_Line E_Port_t copy_E_Port E_State_t copy_E_Mode              */
/*                         void (* copyEXTI_fCallBake)(void)                                            */
/*	Function Description : Enable Interupt And srt the Call Back                                        */
/********************************************************************************************************/
void EXTI_vEnableEXTI(E_Line_t copy_E_Line, E_Port_t copy_E_Port, E_State_t copy_E_Mode, void (* copyEXTI_fCallBake)(void))
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
/*	Function Name        : EXTI_vDisableEXTI                                                            */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : E_Line_t copy_E_Line                                                         */
/*	Function Description : Disable the Interupt                                                         */
/********************************************************************************************************/
void EXTI_vDisableEXTI(E_Line_t copy_E_Line)
{
	CLR_BIT(EXTI->IMR, copy_E_Line);    // Clear the Interrupt Not Masked
}








/********************************************************************************************************/
/*	Function Name        : EXTI_vSwTrigger                                                              */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : E_Line_t copy_E_Line                                                         */
/*	Function Description : Det the SW pending Flag to force the interrupt                               */
/********************************************************************************************************/
void EXTI_vSwTrigger(E_Line_t copy_E_Line)
{
	SET_BIT(EXTI->SWIER, copy_E_Line);    // Set The Software Interrupt Flag
}


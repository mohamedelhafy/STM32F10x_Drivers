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

void (* EXTI_fCallBack[10])(void);




/********************************************************************************************************/
/*	Function Name        : EXTI_vEnableEXTI                                                             */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : E_Line_t copy_E_Line E_Port_t copy_E_Port E_State_t copy_E_Mode              */
/*                         void (* copyEXTI_fCallBake)(void)                                            */
/*	Function Description : Enable Interupt And srt the Call Back                                        */
/********************************************************************************************************/
void EXTI_vEnableEXTI(E_Line_t copy_E_Line, E_Port_t copy_E_Port, E_State_t copy_E_Mode, void (* copyEXTI_fCallBack)(void))
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

	switch(copy_E_Line)
	{
		case LINE0      : EXTI_fCallBack[0] = copyEXTI_fCallBack; break; // Set the Call Back ptr
		case LINE1      : EXTI_fCallBack[1] = copyEXTI_fCallBack; break; // Set the Call Back ptr
		case LINE2      : EXTI_fCallBack[2] = copyEXTI_fCallBack; break; // Set the Call Back ptr
		case LINE3      : EXTI_fCallBack[3] = copyEXTI_fCallBack; break; // Set the Call Back ptr
		case LINE4      : EXTI_fCallBack[4] = copyEXTI_fCallBack; break; // Set the Call Back ptr

		case LINE5      : 
		case LINE6      : 
		case LINE7      : 
		case LINE8      : 
		case LINE9      : EXTI_fCallBack[5] = copyEXTI_fCallBack; break; // Set the Call Back ptr

		case LINE10     : // Make it or with 11 &12&13&14&15
		case LINE11     : 
		case LINE12     : 
		case LINE13     : 
		case LINE14     : 
		case LINE15     : EXTI_fCallBack[6] = copyEXTI_fCallBack; break; // Set the Call Back ptr
	}
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













void EXTI0_IRQHandler(void)
{
	EXTI_fCallBack[0]();
	SET_BIT(EXTI -> PR , LINE0);
}





void EXTI1_IRQHandler(void)
{
	EXTI_fCallBack[1]();
	SET_BIT(EXTI -> PR , LINE1);
}




void EXTI2_IRQHandler(void)
{
	EXTI_fCallBack[2]();
	SET_BIT(EXTI -> PR , LINE2);
}



void EXTI3_IRQHandler(void)
{
	EXTI_fCallBack[3]();
	SET_BIT(EXTI -> PR , LINE3);
}




void EXTI4_IRQHandler(void)
{
	EXTI_fCallBack[4]();
	SET_BIT(EXTI -> PR , LINE4);
}





void EXTI9_5_IRQHandler(void)
{
	EXTI_fCallBack[5]();
}





void EXTI15_10_IRQHandler(void)
{
	EXTI_fCallBack[6]();
}

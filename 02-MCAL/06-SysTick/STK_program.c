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
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"





/********************************************************************************************************/
/*	Function Name        : STK_vInit                                                                    */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Set the Input clock According to the configration file                       */
/*                         disable the Systick and Systick INT                                          */
/********************************************************************************************************/
void STK_vInit(void)
{
	#if CLK_SRC == AHB
		STK->CTRL.ClkSource =  0;
	#else
		STK->CTRL.ClkSource =  1;
	#endif
}










/********************************************************************************************************/
/*	Function Name        : STK_vSetBuyWait                                                              */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32Ticks                                                  */
/*	Function Description : Enable the Systick and load the copy_u32Ticks value in Load Reg              */
/*                         wait till the count reach to 0 then disable the Systick and return           */
/********************************************************************************************************/
void STK_vSetBuyWait(uint32 copy_u32Ticks)
{
	STK->LOAD = copy_u32Ticks;
	STK->CTRL.TicInt = 0;
	STK->CTRL.Enable = 1;
	while(!STK->CTRL.CountFlag);
	STK->CTRL.Enable = 0;
}










/********************************************************************************************************/
/*	Function Name        : STK_vSetIntervalSingle                                                       */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32Ticks, poiter to void function tack void               */
/*	Function Description : Set the interval and set the call Back to call it when finish                */
/********************************************************************************************************/
void STK_vSetIntervalSingle(uint32 copy_u32Ticks ,void (*copySTK_fCallBack)(void))
{
	STK->LOAD = copy_u32Ticks;
	STK->CTRL.TicInt = 1;
	STK->CTRL.Enable = 1;
	STK_callBack = copySTK_fCallBack;
}










/********************************************************************************************************/
/*	Function Name        : STK_vSetIntervalPeriodic                                                     */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32Ticks, poiter to void function tack void               */
/*	Function Description : Set the interval and set the call Back to call it when finish                */
/********************************************************************************************************/
void STK_vSetIntervalPeriodic(uint32 copy_u32Ticks ,void (*copySTK_fCallBack)(void))
{
	STK->LOAD = copy_u32Ticks;
	STK->CTRL.TicInt = 1;
	STK->CTRL.Enable = 1;
	STK_callBack = copySTK_fCallBack;
}










/********************************************************************************************************/
/*	Function Name        : STK_vStopTimer                                                               */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Stop and Disable the Systick                                                 */
/********************************************************************************************************/
void STK_vStopTimer(void)
{
	STK->CTRL.Enable = 0;
}










/********************************************************************************************************/
/*	Function Name        : STK_u32GetElapsedTime                                                        */
/*	Function Returns     : unsigned long                                                                */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Return the value counted                                                     */
/********************************************************************************************************/
uint32 STK_u32GetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL);
}










/********************************************************************************************************/
/*	Function Name        : STK_u32GetRemainingTime                                                      */
/*	Function Returns     : unsigned long                                                                */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Return the Remaining ticks                                                   */
/********************************************************************************************************/
uint32 STK_u32GetRemainingTime(void)
{
	return STK->VAL;
}







/********************************************************************************************************/
/*	Function Name        : SysTick_Handler                                                              */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : ISR                                                                          */
/********************************************************************************************************/
void SysTick_Handler(void)
{
	STK_callBack();
}
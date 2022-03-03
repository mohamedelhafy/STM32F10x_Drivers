/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/






/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************LOWER_LAYERS***************/




/**************MY_HADER_FILES*************/
#include "Delay.h"






/********************************************************************************************************/
/*	Function Name        : DELAY_vMS                                                                    */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32NumberOfMs                                             */
/*	Function Description : Delay Number of Ms                                                           */
/********************************************************************************************************/
void DELAY_vMS(uint32 copy_u32NumberOfMs)
{
	uint64 LOC_u32LoopVal;
	LOC_u32LoopVal = (F_CPU/1000)*copy_u32NumberOfMs;
	for(; LOC_u32LoopVal >0; LOC_u32LoopVal--);
}








/********************************************************************************************************/
/*	Function Name        : DELAY_vUS                                                                    */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32NumberOfUs                                             */
/*	Function Description : Delay Number of Us                                                           */
/********************************************************************************************************/
void DELAY_vUS(uint32 copy_u32NumberOfUs)
{
	uint64 LOC_u32LoopVal;
	LOC_u32LoopVal = (F_CPU/1000000)*copy_u32NumberOfUs;
	for(; LOC_u32LoopVal >0; LOC_u32LoopVal--);
}
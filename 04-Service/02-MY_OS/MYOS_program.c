/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"


/**************LOWER_LAYERS***************/
#include "STK_interface.h"



/**************MY_HADER_FILES*************/
#include "MYOS_interface.h"
#include "MYOS_private.h"
#include "MYOS_config.h"








/********************************************************************************************************/
/*	Function Name        : MYOS_vCreatTask                                                              */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8Periority, unsigned short Copy_u16Priodicity pointer to */
/*                         void function take void                                                      */
/*	Function Description : Creat the Task                                                               */
/********************************************************************************************************/
void MYOS_vCreatTask(uint8 copy_u8Periority, uint16 copy_u16Priodicity, void (*copy_Fptr)(void))
{
	OS_Tasks[copy_u8Periority].priodicity = copy_u16Priodicity;
	OS_Tasks[copy_u8Periority].Fptr = copy_Fptr;

}






/********************************************************************************************************/
/*	Function Name        : MYOS_vStart                                                                  */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Make the os start                                                            */
/********************************************************************************************************/
void MYOS_vStart(void)
{
	uint32 LOC_u32Tick;
	/* Initialization */
	STK_vInit(); // Initialize the Systick in AHB/8
	/* Tick => 1Msec */
	LOC_u32Tick = (F_CPU/8)/1000;
	STK_vSetIntervalPeriodic(LOC_u32Tick, MYOS_vScheduler );
}










volatile uint16 TickCount;

/********************************************************************************************************/
/*	Function Name        : MYOS_vStart                                                                  */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Make the os start                                                            */
/********************************************************************************************************/
static void MYOS_vScheduler(void)
{
	uint8 i;
	for (i = 0; i < NUMBER_OF_TASKS ; i++)
	{
		if ((TickCount % OS_Tasks[i].priodicity) == 0)
		{
			OS_Tasks[i].Fptr();
		}
	}
	TickCount++;
}























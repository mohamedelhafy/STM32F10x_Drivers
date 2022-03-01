/********************************************************************************************/
/* Author  : Mohamed Farag Elhafy															*/
/* Date    : 5 FEB 2022																		*/
/* Version : V01																			*/
/********************************************************************************************/

// first including my Standerd LIBs
#include "STD_TYPES.h" 
#include "BIT_MATH.h"

// including the Needed Interface files from lower layers 
// here there is no lower layers

// including My own Driver Files in this order
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"




/********************************************************************************************************/
/*	Function Name        : RCC_vInitSysClock															*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : void																			*/
/*	Function Description : Set the System CLock	according to the configration Values					*/
/********************************************************************************************************/
void RCC_vInitSysClock(void)
{
	





/********************************************************************************************************/
/*	Function Name        : RCC_vEnableClock																*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char Copy_u8BusId unsigned char Copy_u8PreId						*/
/*	Function Description : Enable the clock to the prephiral											*/
/********************************************************************************************************/
void RCC_vEnableClock(uint8 Copy_u8BusId , uint8 Copy_u8PreId)
{
	if (Copy_u8PreId<=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB   : SET_BIT(RCC_AHBENR  ,Copy_u8PreId);   break;
			case RCC_APB1  : SET_BIT(RCC_APB1ENR ,Copy_u8PreId);   break;
			case RCC_APB2  : SET_BIT(RCC_APB2ENR ,Copy_u8PreId);   break;
			default        :    /* Return Error */ break;
		}
	}
	else
	{
		/* Return Error*/
	}
}





/********************************************************************************************************/
/*	Function Name        : RCC_vDisableClock															*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char Copy_u8BusId unsigned char Copy_u8PreId						*/
/*	Function Description : Enable the clock to the prephiral											*/
/********************************************************************************************************/
void RCC_vDisableClock(uint8 Copy_u8BusId , uint8 Copy_u8PreId)
{
	if (Copy_u8PreId<=31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB   : CLR_BIT(RCC_AHBENR  ,Copy_u8PreId);   break;
			case RCC_APB1  : CLR_BIT(RCC_APB1ENR ,Copy_u8PreId);   break;
			case RCC_APB2  : CLR_BIT(RCC_APB2ENR ,Copy_u8PreId);   break;
			default        :    /* Return Error */ break;
		}
	}
	else
	{
		/* Return Error*/
	}
}
/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 27 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/




/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/**************LOWER_LAYERS***************/
#include "RCC_interface.h"


/**************MY_HADER_FILES*************/
#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"




/************************************************************************/
/* Temperary I just need one Function                                   */
/************************************************************************/



/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void AFIO_vSetEXTIConfigration(uint8 copy_u8Line, uint8 copy_u8PortMap)
{
	RCC_vEnableClock(RCC_APB2, RCC_AFIO_EN);
	AFIO->EXTICR[copy_u8Line >> 2] & = ~(0b1111 << (copy_u8Line & 0b11));
	AFIO->EXTICR[copy_u8Line >> 2] | = ((copy_u8PortMap) << (copy_u8Line & 0b11));
}






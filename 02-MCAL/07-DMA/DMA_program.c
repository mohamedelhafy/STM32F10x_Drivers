/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 12 MAR 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/


/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"


/**************LOWER_LAYERS***************/



/**************MY_HADER_FILES*************/
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"



void ( *DMA_CallBackChannel[7] )( void );




/********************************************************************************************************/
/*	Function Name        : DMA_vChannalInit                                                             */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description :                                                      */
/********************************************************************************************************/
void DMA_vChannalInit(void)
{
	
}









/********************************************************************************************************/
/*	Function Name        : DMA_vChannalStart                                                            */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description :                                                      */
/********************************************************************************************************/
void DMA_vChannalStart(Channals_t Copy_EChannalID, u32 * Copy_Pu32SourceAddress, u32 * Copy_pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
	if(IS_BIT_SET(DMA->Channal[Copy_EChannalID].CCR,0)) 
	{
		/* Disable It*/
		CLR_BIT(DMA->Channal[Copy_EChannalID].CCR,0);
		/*It Take Time To Be Disable So Wait Time */
		while(IS_BIT_SET(DMA->Channal[Copy_EChannalID].CCR,0))
		{

		} 		
	}
	else 
	{
	/* Return Error*/
	}

	/* Set Address*/
	DMA->Channal[Copy_EChannalID].CPAR = Copy_Pu32SourceAddress;
	DMA->Channal[Copy_EChannalID].CMAR = Copy_pu32DestinationAddress;

	/* Block Length */
	DMA->Channal[Copy_EChannalID].CNDTR = Copy_u16BlockLength;

	/* Set the Channal Enable*/
	SET_BIT(DMA->Channal[Copy_EChannalID].CCR,0);
}











void MDMA_VidSetCallBackChannel1(Channals_t Copy_EChannalID ,void ( *Ptr ) ( void ) )
{
	switch(Copy_EChannalID)
	{
		case Channal1: DMA_CallBackChannel[0] = Ptr ; break;
		case Channal2: DMA_CallBackChannel[1] = Ptr ; break;
		case Channal3: DMA_CallBackChannel[2] = Ptr ; break;
		case Channal4: DMA_CallBackChannel[3] = Ptr ; break;
		case Channal5: DMA_CallBackChannel[4] = Ptr ; break;
		case Channal6: DMA_CallBackChannel[5] = Ptr ; break;
		case Channal7: DMA_CallBackChannel[6] = Ptr ; break;
		default : /*Return Error */    break;
	}
}




void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel[0]();

}



void DMA1_Channel2_IRQHandler(void){

	DMA_CallBackChannel[1]();

}



void DMA1_Channel3_IRQHandler(void){

	DMA_CallBackChannel[2]();

}



void DMA1_Channel4_IRQHandler(void){

	DMA_CallBackChannel[3]();

}



void DMA1_Channel5_IRQHandler(void){

	DMA_CallBackChannel[4]();

}



void DMA1_Channel6_IRQHandler(void){

	DMA_CallBackChannel[5]();

}

void DMA1_Channel7_IRQHandler(void){

	DMA_CallBackChannel[6]();

}
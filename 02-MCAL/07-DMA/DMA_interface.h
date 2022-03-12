/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 12 MAR 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H



typedef enum 
{
	Channal1=0,
	Channal2  ,
	Channal3  ,
	Channal4  ,
	Channal5  ,
	Channal6  ,
	Channal7  ,
}Channals_t;




/********************************************************************************************************/
/*	Function Name        : DMA_vChannalInit                                                             */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description :                                                      */
/********************************************************************************************************/
void DMA_vChannalInit(void);









/********************************************************************************************************/
/*	Function Name        : DMA_vChannalStart                                                            */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description :                                                      */
/********************************************************************************************************/
void DMA_vChannalStart(u32 Copy_Pu32SourceAddress, u32 Copy_pu32DestinationAddress, u16 Copy_u16BlockLength);






















#endif // DMA_INTERFACE_H
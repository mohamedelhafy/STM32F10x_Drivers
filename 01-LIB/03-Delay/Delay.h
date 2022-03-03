/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/








#ifndef DELAY_H
#define DELAY_H

/* Please Write the CPU Speed Before you use this Funcs*/
#ifndef F_CPU
	#define F_CPU          8000000ul
#endif





/********************************************************************************************************/
/*	Function Name        : DELAY_vMS                                                                    */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32NumberOfMs                                             */
/*	Function Description : Delay Number of Ms                                                           */
/********************************************************************************************************/
void Delay_vMS(uint32 copy_u32NumberOfMs);








/********************************************************************************************************/
/*	Function Name        : DELAY_vUS                                                                    */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32NumberOfUs                                             */
/*	Function Description : Delay Number of Us                                                           */
/********************************************************************************************************/
void Delay_vUS(uint32 copy_u32NumberOfUs);






#endif // DELAY_H
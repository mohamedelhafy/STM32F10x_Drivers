/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 5 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

	/* Options : 	RCC_HSE_CRYSTAL
					RCC_HSE_RC
					RCC_HSI
					RCC_PLL               */
	#define RCC_CLOCK_TYPE		RCC_HSI


	/*  Incase you choose the PLL option

		Options :	RCC_PLL_IN_HSIDiv2
					RCC_PLL_IN_HSEDiv2
					RCC_PLL_IN_HSE
	*/
	/*  Note    :   Select Value only if you you have PLL as input Clock source */
	#if 	RCC_CLOCK_TYPE == RCC_PLL
	#define RCC_PLL_INPUT		RCC_PLL_IN_HSIDiv2

	// Choose the Mul Value
	/*	Options :   from 2 to 16 */
	#define	RCC_PULL_MUL_VAL	9// choosing 9 as default val Feel free to chang it accordig your ablication	    
	#endif



#endif // RCC_CONFIG_H

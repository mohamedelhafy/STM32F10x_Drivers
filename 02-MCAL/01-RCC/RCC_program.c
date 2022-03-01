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
	#if 	RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL

		SET_BIT(RCC_CR , RCC_HSEON);				// Enable the HSE 
		while(IS_BIT_CLEAR(RCC_CR ,RCC_HSERDY));	// Wait till the Hardware set the ready bit
		CLR_BIT(RCC_CR , RCC_HSEPYB);				// Make sure to clear the ByPass Bit 
		SET_BIT(RCC_CR , RCC_CSSON);				// Enable the Clock security System circuit
		SET_BIT(RCC_CFGR, RCC_SW0);

	#elif	RCC_CLOCK_TYPE == RCC_HSE_RC 

		SET_BIT(RCC_CR , RCC_HSEON);				// Enable The HSE
		while(IS_BIT_CLEAR(RCC_CR ,RCC_HSERDY));	// Wait till the Hardware set the ready bit
		SET_BIT(RCC_CR , RCC_HSEPYB);				// Set ByPass to RC circuit
		SET_BIT(RCC_CR , RCC_CSSON);				// Enable the Clock security System circuit
		SET_BIT(RCC_CFGR, RCC_SW0);
		CLR_BIT(RCC_CFGR, RCC_SW1);

	#elif	RCC_CLOCK_TYPE == RCC_HSI 

		SET_BIT(RCC_CR , RCC_HSION);                // Enable the HSI
		while(IS_BIT_CLEAR(RCC_CR ,RCC_HSIRDY));    // Wait till the Hardware set the ready bit
		SET_BIT(RCC_CR , RCC_CSSON);                // Enable the Clock security System circuit
		// Choose the Input Clock to the processor
		CLR_BIT(RCC_CFGR, RCC_SW0);
		CLR_BIT(RCC_CFGR, RCC_SW1);

	#elif	RCC_CLOCK_TYPE == RCC_PLL

		#if 	RCC_PLL_INPUT == RCC_PLL_IN_HSIDiv2
			
			SET_BIT(RCC_CR, RCC_HSION);                  // Enable the HSI
			while(IS_BIT_CLEAR(RCC_CR, RCC_HSIRDY));     // Wait till the Hardware set the ready bit  
			CLR_BIT(RCC_CFGR, RCC_PLLSRC);               // Select the PLL Source as HSI/2
			SET_BIT(RCC_CR, RCC_PLLON);                  // Enable the PLL 
			while(IS_BIT_CLEAR(RCC_CR, RCC_PLLRDY));     // Wait till the Hardware set the ready bit 
			// Choose the Input Clock to the processor
			SET_BIT(RCC_CFGR, RCC_SW1);
			CLR_BIT(RCC_CFGR, RCC_SW0);

		#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSEDiv2

			SET_BIT(RCC_CR, RCC_HSEON);                  // Enable the HSE   
			while(IS_BIT_CLEAR(RCC_CR, RCC_HSERDY));     // Wait till the Hardware set the ready bit
			SET_BIT(RCC_CFGR, RCC_PLLSRC);               // Select the PLL Source as HSE
			SET_BIT(RCC_CFGR, RCC_PLLXTPRE);             // Select the Pre Scaler
			SET_BIT(RCC_CR, RCC_PLLON);                  // Enable the PLL      
			while(IS_BIT_CLEAR(RCC_CR, RCC_PLLRDY));     // Wait till the Hardware set the ready bit 
			// Choose the Input Clock to the processor               
			SET_BIT(RCC_CFGR, RCC_SW1);
			CLR_BIT(RCC_CFGR, RCC_SW0);

		#elif	RCC_PLL_INPUT == RCC_PLL_IN_HSE

			SET_BIT(RCC_CR, RCC_HSEON);                 // Enable the HSE   
			while(IS_BIT_CLEAR(RCC_CR, RCC_HSERDY));    // Wait till the Hardware set the ready bit    
			SET_BIT(RCC_CFGR, RCC_PLLSRC);              // Select the PLL Source as HSE
			CLR_BIT(RCC_CFGR, RCC_PLLXTPRE);            // Select the Pre Scaler
			SET_BIT(RCC_CR, RCC_PLLON);                 // Enable the PLL      
			while(IS_BIT_CLEAR(RCC_CR, RCC_PLLRDY));    // Wait till the Hardware set the ready bit 
			// Choose the Input Clock to the processor 
			SET_BIT(RCC_CFGR, RCC_SW1);
			CLR_BIT(RCC_CFGR, RCC_SW0);

		#else	
			#error ("Please Choose the Right PLL Option") 
		#endif
		
	#else     
		#error ("you Choose wrong Clock Type")
	#endif


// Handling the PLL MUL 
// Handling the Bus Pre 
}





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
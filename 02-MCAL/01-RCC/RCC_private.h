/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 5 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// Register definations 


// Start address 0x40021000
#define BASE_RCC_ADRRESS  0x40021000

// offset of My Register from Base Address
#define RCC_CR_OFFSET           0x00 
#define RCC_CFGR_OFFSET         0x04
#define RCC_CIR_OFFSET          0x08
#define RCC_APB2RSTR_OFFSET     0x0C 
#define RCC_APB1RSTR_OFFSET     0x10 
#define RCC_AHBENR_OFFSET       0x14 
#define RCC_APB2ENR_OFFSET      0x18 
#define RCC_APB1ENR_OFFSET      0x1C 
#define RCC_BDCR_OFFSET         0x20
#define RCC_CSR_OFFSET          0x24


// defining the Registers and derefrance them
#define RCC_CR              *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_CR_OFFSET))
#define RCC_CFGR            *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_CFGR_OFFSET))
#define RCC_CIR             *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_CIR_OFFSET))
#define RCC_APB2RSTR        *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_APB2RSTR_OFFSET))
#define RCC_APB1RSTR        *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_APB1RSTR_OFFSET))
#define RCC_AHBENR          *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_AHBENR_OFFSET))
#define RCC_APB2ENR         *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_APB2ENR_OFFSET))
#define RCC_APB1ENR         *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_APB1ENR_OFFSET))
#define RCC_BDCR            *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_BDCR_OFFSET))
#define RCC_CSR             *((volatile uint32*)(BASE_RCC_ADRRESS+RCC_CSR_OFFSET))




// Clock Types
#define RCC_HSE_CRYSTAL  		0
#define RCC_HSE_RC       		1
#define RCC_HSI          		2
#define RCC_PLL          		3



#define RCC_PLL_IN_HSIDiv2		0
#define RCC_PLL_IN_HSEDiv2		1
#define RCC_PLL_IN_HSE 			2


#endif // RCC_PRIVATE_H

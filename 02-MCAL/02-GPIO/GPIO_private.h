/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 6 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H
// Register definitions 
// Define Base Address for ports A&B&C Address 
#define PORTA_BASE_ADDRESS	0x40010800
#define PORTB_BASE_ADDRESS	0x40010C00
#define PORTC_BASE_ADDRESS	0x40011000


// Define the Base ADBRESS For ports D&E&F&G for futur use in other MC have these ports
#define PORTD_BASE_ADDRESS	0x40011400
#define PORTE_BASE_ADDRESS	0x40011800
#define PORTF_BASE_ADDRESS	0x40011C00
#define PORTG_BASE_ADDRESS	0x40012000


// offset of My Register from Base Address
#define GPIOx_CRL_OFFSET	0x00
#define GPIOx_CRH_OFFSET	0x04
#define GPIOx_IDR_OFFSET	0x08
#define GPIOx_ODR_OFFSET	0x0C
#define GPIOx_BSRR_OFFSET	0x10
#define GPIOx_BRR_OFFSET 	0x14
#define GPIOx_LCKR_OFFSET	0x18

// PORTA Registers 
#define PORTA_CRL			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTA_CRH			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTA_IDR			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTA_ODR			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTA_BSRR			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTA_BRR 			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTA_LCKR			*((uint32 *)(PORTA_BASE_ADDRESS + GPIOx_LCKR_OFFSET))


//PORTB Registers
#define PORTB_CRL			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTB_CRH			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTB_IDR			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTB_ODR			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTB_BSRR			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTB_BRR 			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTB_LCKR			*((uint32 *)(PORTB_BASE_ADDRESS + GPIOx_LCKR_OFFSET))


// PORTC Registers 
#define PORTC_CRL			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTC_CRH			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTC_IDR			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTC_ODR			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTC_BSRR			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTC_BRR 			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTC_LCKR			*((uint32 *)(PORTC_BASE_ADDRESS + GPIOx_LCKR_OFFSET))


// PORTD Registers For Future use 
#define PORTD_CRL			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTD_CRH			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTD_IDR			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTD_ODR			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTD_BSRR			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTD_BRR 			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTD_LCKR			*((uint32 *)(PORTD_BASE_ADDRESS + GPIOx_LCKR_OFFSET))



// PORTE Registers For Future use 
#define PORTE_CRL			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTE_CRH			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTE_IDR			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTE_ODR			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTE_BSRR			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTE_BRR 			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTE_LCKR			*((uint32 *)(PORTE_BASE_ADDRESS + GPIOx_LCKR_OFFSET))


// PORTF Registers For Future use 
#define PORTF_CRL			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTF_CRH			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTF_IDR			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTF_ODR			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTF_BSRR			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTF_BRR 			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTF_LCKR			*((uint32 *)(PORTF_BASE_ADDRESS + GPIOx_LCKR_OFFSET))


// PORTG Registers for Future use
#define PORTG_CRL			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_CRL_OFFSET))
#define PORTG_CRH			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_CRH_OFFSET))
#define PORTG_IDR			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_IDR_OFFSET))
#define PORTG_ODR			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_ODR_OFFSET))
#define PORTG_BSRR			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_BSRR_OFFSET))
#define PORTG_BRR 			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_BRR_OFFSET))
#define PORTG_LCKR			*((uint32 *)(PORTG_BASE_ADDRESS + GPIOx_LCKR_OFFSET))




#endif  // GPIO_PRIVATE_H
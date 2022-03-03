/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 27 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/
 





#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* EXTI Base Address from Data Sheet */
#define EXTI_BASE_ADDRESS    0x40010400


typedef struct 
{
	volatile uint32 IMR   ;
	volatile uint32 EMR   ;
	volatile uint32 RTSR  ;
	volatile uint32 FTSR  ;
	volatile uint32 SWIER ;
	volatile uint32 PR    ;
}EXTI_t;


#define EXTI     ((volatile EXTI_t *)EXTI_BASE_ADDRESS)











#endif  // EXTI_PRIVATE_H
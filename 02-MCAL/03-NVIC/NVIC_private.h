/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 9 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H
/* 0xE000E100 Base Adress */
#define NVIC_BASE_ADDRESS   0xE000E100


/**************************     Set Offsets     **************************/
/*  Set interrupt Regs offset   */
#define NVIC_ISER0_OFFSET   0x00
#define NVIC_ISER1_OFFSET   0x04
#define NVIC_ISER2_OFFSET   0x08

/*  Clear interrupt Regs offset */
#define NVIC_ICER0_OFFSET   0x80
#define NVIC_ICER1_OFFSET   0x84
#define NVIC_ICER2_OFFSET   0x88



/*   Interrupt Set pending Regs offset */
#define NVIC_ISPR0_OFFSET   0x100
#define NVIC_ISPR1_OFFSET   0x104
#define NVIC_ISPR2_OFFSET   0x108


/*   Interrupt Clear pending Regs offset */
#define NVIC_ICPR0_OFFSET   0x180
#define NVIC_ICPR1_OFFSET   0x184
#define NVIC_ICPR2_OFFSET   0x188



/*   Interrupt Active Flag Regs offset  */
#define NVIC_IABR0_OFFSET   0x200
#define NVIC_IABR1_OFFSET   0x204
#define NVIC_IABR2_OFFSET   0x208



/**************************     Register definition     *********************************/
/*  Set interrupt Regs */
#define NVIC_ISER0          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ISER0_OFFSET))
#define NVIC_ISER1          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ISER1_OFFSET))
#define NVIC_ISER2          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ISER2_OFFSET))


/*  Clear interrupt Regs */
#define NVIC_ICER0          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ICER0_OFFSET))
#define NVIC_ICER1          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ICER1_OFFSET))
#define NVIC_ICER2          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ICER2_OFFSET))

/*   Interrupt Set Priority Regs */
#define NVIC_ISPR0          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ISPR0_OFFSET))
#define NVIC_ISPR1          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ISPR1_OFFSET))
#define NVIC_ISPR2          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ISPR2_OFFSET))



/*   Interrupt Clear pending Regs */
#define NVIC_ICPR0          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ICPR0_OFFSET))
#define NVIC_ICPR1          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ICPR1_OFFSET))
#define NVIC_ICPR2          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_ICPR2_OFFSET))


/* Active Bit Regs  */
#define NVIC_IABR0          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_IABR0_OFFSET))
#define NVIC_IABR1          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_IABR1_OFFSET))
#define NVIC_IABR2          *((volatile uint32*)(NVIC_BASE_ADDRESS + NVIC_IABR2_OFFSET))



#endif   // NVIC_PRIVATE_H
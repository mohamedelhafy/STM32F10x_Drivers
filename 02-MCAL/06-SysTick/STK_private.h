/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 1 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/************************ the Call Back ptr ************************/
void (*STK_callBack)(void);

/************************ the Base Address ************************/
#define STK_BASE_ADDRESS         0xE000E010


typedef struct{
    volatile uint32 Enable    : 1 ;
    volatile uint32 TicInt    : 1 ;
    volatile uint32 ClkSource : 1 ;
    volatile uint32 Reserved  : 13;
    volatile uint32 CountFlag : 1 ;
    volatile uint32 Reserved2 : 15;
}u32_STK_CTRL_Reg;






typedef struct 
{
	volatile u32_STK_CTRL_Reg     CTRL ;
	volatile uint32               LOAD ;
	volatile uint32               VAL  ;
	volatile uint32               CALIB;
}STK_Reg_t;

#define STK       ((volatile STK_Reg_t *)(STK_BASE_ADDRESS))










#endif //STK_PRIVATE_H
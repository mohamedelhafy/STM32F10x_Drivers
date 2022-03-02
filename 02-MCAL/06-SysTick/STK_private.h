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
    u32 Enable    : 1 ;
    u32 TicInt    : 1 ;
    u32 ClkSource : 1 ;
    u32 Reserved  : 13;
    u32 CountFlag : 1 ;
    u32 Reserved2 : 15;
}u32_STK_CTRL_Reg;






typedef struct 
{
	u32_STK_CTRL_Reg     CTRL ;
	uint32               LOAD ;
	uint32               VAL  ;
	uint32               CALIB;
}STK_Reg_t;

#define STK       ((volatile STK_Reg_t *)(STK_BASE_ADDRESS))










#endif //STK_PRIVATE_H
/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 9 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H


/********************************************************************************************************/
/*	Function Name        : NVIC_vEnableInterrupt                                                        */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Set pin copy_u8Mode                                                          */
/********************************************************************************************************/
void NVIC_vEnableInterrupt(uint8 copy_u8IntNumber);





/********************************************************************************************************/
/*	Function Name        : NVIC_vDisableInterrupt                                                       */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Disable interrupt ensble in NVIC                                             */
/********************************************************************************************************/
void NVIC_vDisableInterrupt(uint8 copy_u8IntNumber);








/********************************************************************************************************/
/*	Function Name        : NVIC_vSetPendingFlag                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Set pending Flag                                                             */
/********************************************************************************************************/
void NVIC_vSetPendingFlag(uint8 copy_u8IntNumber);





/********************************************************************************************************/
/*	Function Name        : NVIC_vClearpendingFlag                                                       */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Clear pending Flag                                                           */
/********************************************************************************************************/
void NVIC_vClearPendingFlag(uint8 copy_u8IntNumber);





/********************************************************************************************************/
/*	Function Name        : NVIC_u8GetActiveFlag                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8IntNumber                                               */
/*	Function Description : Get Active Flag that told me if this int is executed                         */
/********************************************************************************************************/
uint8 NVIC_u8GetActiveFlag(uint8 copy_u8IntNumber);





/********************************************************************************************************/
/*	Function Name        : NVIC_vSetGroupSubgroupComp                                                   */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : signed char copy_s8IntId unsigned char copy_u8periority                      */
/*	Function Description : Get Active Flag that told me if this int is executed                         */
/********************************************************************************************************/
void NVIC_vSetGroupSubgroupComp(uint32 copy_u32GroupSubgroupComp);








/********************************************************************************************************/
/*	Function Name        : NVIC_vSetGroupSubType                                                        */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32GroupSubgroupType                                      */
/*	Function Description : Set Sw periority                                                             */
/********************************************************************************************************/
void NVIC_vSetGroupSubType(uint32 copy_u32GroupSubgroupType);







/********************************************************************************************************/
/*	Function Name        : NVIC_vSetSWPeriority                                                         */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : signed char copy_s8IntId unsigned char copy_u8periority                      */
/*	Function Description : Set Sw periority                                                             */
/********************************************************************************************************/
void NVIC_vSetSWPeriority(sint8 copy_s8IntId , uint8 copy_u8GroupPeriority , uint8 copy_u8SubgroupPeriority);







/***************    Group Types    *********************/
#define GROUP4_AND_SUB0                0x05FA0300  // 4-bit for group and 0-bit for sub
#define GROUP3_AND_SUB1                0x05FA0400  // 3-bit for group and 1-bit for sub
#define GROUP2_AND_SUB2                0x05FA0500  // 2-bit for group and 2-bit for sub
#define GROUP1_AND_SUB3                0x05FA0600  // 1-bit for group and 3-bit for sub
#define GROUP0_AND_SUB4                0x05FA0700  // 0-bit for group and 4-bit for sub




/***************    NVIC pins Order    *********************/
#define NVIC_SW_PERIORITY_WWDG               0
#define NVIC_SW_PERIORITY_PVD                1
#define NVIC_SW_PERIORITY_TAMPER             2
#define NVIC_SW_PERIORITY_RTC                3
#define NVIC_SW_PERIORITY_FLASH              4
#define NVIC_SW_PERIORITY_RCC                5
#define NVIC_SW_PERIORITY_EXTI0              6
#define NVIC_SW_PERIORITY_EXTI1              7
#define NVIC_SW_PERIORITY_EXTI2              8
#define NVIC_SW_PERIORITY_EXTI3              9
#define NVIC_SW_PERIORITY_EXTI4              10
#define NVIC_SW_PERIORITY_DMA1_Channel1      11
#define NVIC_SW_PERIORITY_DMA1_Channel2      12
#define NVIC_SW_PERIORITY_DMA1_Channel3      13
#define NVIC_SW_PERIORITY_DMA1_Channel4      14
#define NVIC_SW_PERIORITY_DMA1_Channel5      15
#define NVIC_SW_PERIORITY_DMA1_Channel6      16
#define NVIC_SW_PERIORITY_DMA1_Channel7      17
#define NVIC_SW_PERIORITY_ADC1_2             18
#define NVIC_SW_PERIORITY_CAN1_TX            19
#define NVIC_SW_PERIORITY_CAN1_RX0           20
#define NVIC_SW_PERIORITY_CAN1_RX1           21
#define NVIC_SW_PERIORITY_CAN1_SCE           22
#define NVIC_SW_PERIORITY_EXTI9_5            23
#define NVIC_SW_PERIORITY_TIM1_BRK           24
#define NVIC_SW_PERIORITY_TIM1_UP            25
#define NVIC_SW_PERIORITY_TIM1_TRG_COM       26
#define NVIC_SW_PERIORITY_TIM1_CC            27
#define NVIC_SW_PERIORITY_TIM2               28
#define NVIC_SW_PERIORITY_TIM3               29
#define NVIC_SW_PERIORITY_TIM4               30
#define NVIC_SW_PERIORITY_I2C1_EV            31
#define NVIC_SW_PERIORITY_I2C1_ER            32
#define NVIC_SW_PERIORITY_I2C2_EV            33
#define NVIC_SW_PERIORITY_I2C2_ER            34     
#define NVIC_SW_PERIORITY_SPI1               35  
#define NVIC_SW_PERIORITY_SPI2               36
#define NVIC_SW_PERIORITY_USART1             37
#define NVIC_SW_PERIORITY_USART2             38
#define NVIC_SW_PERIORITY_USART3             39
#define NVIC_SW_PERIORITY_EXTI15_10          40 
#define NVIC_SW_PERIORITY_RTCAlarm           41
#define NVIC_SW_PERIORITY_OTG_FS_WKUP        42   
#define NVIC_SW_PERIORITY_TIM5               50
#define NVIC_SW_PERIORITY_SPI3               51
#define NVIC_SW_PERIORITY_UART4              52
#define NVIC_SW_PERIORITY_UART5              53
#define NVIC_SW_PERIORITY_TIM6               54
#define NVIC_SW_PERIORITY_TIM7               55
#define NVIC_SW_PERIORITY_DMA2_Channel1      56
#define NVIC_SW_PERIORITY_DMA2_Channel2      57
#define NVIC_SW_PERIORITY_DMA2_Channel3      58
#define NVIC_SW_PERIORITY_DMA2_Channel4      59
#define NVIC_SW_PERIORITY_DMA2_Channel5      60
#define NVIC_SW_PERIORITY_ETH                61
#define NVIC_SW_PERIORITY_ETH_WKUP           62
#define NVIC_SW_PERIORITY_CAN2_TX            63
#define NVIC_SW_PERIORITY_CAN2_RX0           64
#define NVIC_SW_PERIORITY_CAN2_RX1           65
#define NVIC_SW_PERIORITY_CAN2_SCE           66
#define NVIC_SW_PERIORITY_OTG_FS             67










#endif  // NVIC_INTERFACE_H
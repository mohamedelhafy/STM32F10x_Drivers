/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 5 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


//Define prephiral bus
#define RCC_AHB          0     // Advanced High performance Bus
#define RCC_APB1         1     // 
#define RCC_APB2         2
/*************************************************************/
/* RCC_CR Register dicriptions this is the control Register  */
/*************************************************************/
#define RCC_HSION        0    // For ON the High Speed Internal (HSI) '1'for on '0' for off
#define RCC_HSIRDY       1    // when the clock from HSI Stable the hardware will Set this
// to trim the Clock
#define RCC_HSITRIM0     3    // Enable me to trim or add to my clock Software configrable 
#define RCC_HSITRIM1     4    // Enable me to trim or add to my clock Software configrable 
#define RCC_HSITRIM2     5    // Enable me to trim or add to my clock Software configrable 
#define RCC_HSITRIM3     6    // Enable me to trim or add to my clock Software configrable 
#define RCC_HSITRIM4     7    // Enable me to trim or add to my clock Software configrable 
//hardware clabration 
#define RCC_HSICAL0      8    // hardware Calebration For the Clock Read only
#define RCC_HSICAL1      9    // hardware Calebration For the Clock Read only
#define RCC_HSICAL2      10   // hardware Calebration For the Clock Read only
#define RCC_HSICAL3      11   // hardware Calebration For the Clock Read only
#define RCC_HSICAL4      12   // hardware Calebration For the Clock Read only
#define RCC_HSICAL5      13   // hardware Calebration For the Clock Read only
#define RCC_HSICAL6      14   // hardware Calebration For the Clock Read only
#define RCC_HSICAL7      15   // hardware Calebration For the Clock Read only

#define RCC_HSEON        16   // High Speed External Enabled (HSE)
#define RCC_HSERDY       17   // when the HSE Stable the hardware will Set this
#define RCC_HSEPYB       18   // 
#define RCC_CSSON        19   // 
#define RCC_PLLON        24   // 
#define RCC_PLLRDY       25   // 


/*************************************/
/* RCC_CFGR Bits discriptions        */
/*************************************/
#define RCC_SW0          0    // 
#define RCC_SW1          1    // 
#define RCC_SWS0         2    // 
#define RCC_SWS1         3    // 
#define RCC_HPRE0        4    // 
#define RCC_HPRE1        5    // 
#define RCC_HPRE2        6    // 
#define RCC_HPRE3        7    // 
#define RCC_PPRE10       8    // 
#define RCC_PPRE11       9    // 
#define RCC_PPRE12       10   // 
#define RCC_PPRE20       11   // 
#define RCC_PPRE21       12   // 
#define RCC_PPRE22       13   // 
#define RCC_ADCPRE0      14   // 
#define RCC_ADCPRE1      15   // 
#define RCC_PLLSRC       16   // 
#define RCC_PLLXTPRE     17   // 
#define RCC_PLLMUL0      18   // 
#define RCC_PLLMUL1      19   // 
#define RCC_PLLMUL2      20   // 
#define RCC_PLLMUL3      21   // 
#define RCC_USBPRE       22   // 
#define RCC_MCO0         24   // 
#define RCC_MCO1         25   // 
#define RCC_MCO2         26   // 




/**************************************/
/*RCC_CIR bit Discriptoins            */
/**************************************/
#define RCC_LSIRDYF      0    // 
#define RCC_LSERDYF      1    // 
#define RCC_HSIRDYF      2    // 
#define RCC_HSERDYF      3    // 
#define RCC_PLLRDYF      4    // 
#define RCC_CSSF         7    // 
#define RCC_LSIRDYIE     8    // 
#define RCC_LSERDYIE     9    // 
#define RCC_HSIRDYIE     10   // 
#define RCC_HSERDYIE     11   // 
#define RCC_PLLRDYIE     12   // 
#define RCC_LSIRDYC      16   // 
#define RCC_LSERDYC      17   // 
#define RCC_HSIRDYC      18   // 
#define RCC_HSERDYC      19   // 
#define RCC_PLLRDYC      20   // 
#define RCC_CSSC         21   // 





/***************************************/
/* RCC_APB2RSTR bit Discriptoins       */
/***************************************/
#define RCC_AFIO_RST     0    // 
#define RCC_IOPA_RST     2    // 
#define RCC_IOPB_RST     3    // 
#define RCC_IOPC_RST     4    // 
#define RCC_IOPD_RST     5    // 
#define RCC_IOPE_RST     6    // 
#define RCC_IOPF_RST     7    // 
#define RCC_IOPG_RST     8    // 
#define RCC_ADC1_RST     9    // 
#define RCC_ADC2_RST     10   // 
#define RCC_TIM1_RST     11   // 
#define RCC_SPI1_RST     12   // 
#define RCC_TIM8_RST     13   //
#define RCC_USART1_RST   14   // 
#define RCC_ADC3_RST     15   // 
#define RCC_TIM9_RST     19   // 
#define RCC_TIM10_RST    20   // 
#define RCC_TIM11_RST    21   // 


/*****************************************/
/* RCC_APB1RSTR bit Discriptons          */
/*****************************************/
#define RCC_TIM2_RST     0    // 
#define RCC_TIM3_RST     1    // 
#define RCC_TIM4_RST     2    // 
#define RCC_TIM5_RST     3    // 
#define RCC_TIM6_RST     4    // 
#define RCC_TIM7_RST     5    // 
#define RCC_TIM12_RST    6    // 
#define RCC_TIM13_RST    7    // 
#define RCC_TIM14_RST    8    // 
#define RCC_WWDG_RST     11   // 
#define RCC_SPI2_RST     14   // 
#define RCC_SPI3_RST     15   // 
#define RCC_USART2_RST   17   // 
#define RCC_USART3_RST   18   // 
#define RCC_UART4_RST    19   // 
#define RCC_UART5_RST    20   // 
#define RCC_I2C1_RST     21   // 
#define RCC_I2C2_RST     22   // 
#define RCC_USB_RST      23   // 
#define RCC_CAN_RST      25   // 
#define RCC_BKP_RST      27   // 
#define RCC_PWR_RST      28   // 
#define RCC_DAC_RST      29   // 


/************************************/
/* RCC_AHBENR bit discriptions      */
/************************************/
#define RCC_DMA1_EN      0    // 
#define RCC_DMA2_EN      1    // 
#define RCC_SRAM_EN      2    // 
#define RCC_FLITF_EN     4    // 
#define RCC_CRC_EN       6    // 
#define RCC_FSMC_EN      8    // 
#define RCC_SDIO_EN      10   // 


/***********************************/
/* RCC_APB2ENR bit discriptions    */
/***********************************/
#define RCC_AFIO_EN      0    // 
#define RCC_IOPA_EN      2    // 
#define RCC_IOPB_EN      3    // 
#define RCC_IOPC_EN      4    // 
#define RCC_IOPD_EN      5    // 
#define RCC_IOPE_EN      6    // 
#define RCC_IOPF_EN      7    // 
#define RCC_IOPG_EN      8    // 
#define RCC_ADC1_EN      9    // 
#define RCC_ADC2_EN      10   // 
#define RCC_TIM1_EN      11   // 
#define RCC_SPI1_EN      12   // 
#define RCC_TIM8_EN      13   // 
#define RCC_USART1_EN    14   // 
#define RCC_ADC3_EN      15   // 
#define RCC_TIM9_EN      19   // 
#define RCC_TIM10_EN     20   // 
#define RCC_TIM11_EN     21   // 



/*************************************/
/* RCC_APB1ENR bit discriptios       */
/*************************************/
#define RCC_TIM2_EN      0    // 
#define RCC_TIM3_EN      1    // 
#define RCC_TIM4_EN      2    // 
#define RCC_TIM5_EN      3    // 
#define RCC_TIM6_EN      4    // 
#define RCC_TIM7_EN      5    // 
#define RCC_TIM12_EN     6    // 
#define RCC_TIM13_EN     7    // 
#define RCC_TIM14_EN     8    // 
#define RCC_WWDG_EN      11   // 
#define RCC_SPI2_EN      14   // 
#define RCC_SPI3_EN      15   // 
#define RCC_USART2_EN    17   // 
#define RCC_USART3_EN    18   // 
#define RCC_UART4_EN     19   // 
#define RCC_UART5_EN     20   // 
#define RCC_I2C1_EN      21   // 
#define RCC_I2C2_EN      22   // 
#define RCC_USB_EN       23   // 
#define RCC_CAN_EN       25   // 
#define RCC_BKP_EN       27   // 
#define RCC_PWR_EN       28   // 
#define RCC_DAC_EN       29   // 


/**********************************/
/* RCC_BDCR bit discriptions      */
/**********************************/
#define RCC_LSE_ON       0    // 
#define RCC_LSE_RDY      1    // 
#define RCC_LSE_BYP      2    // 
#define RCC_RTC_SEL0     8    // 
#define RCC_RTC_SEL1     9    // 
#define RCC_RTC_EN       15   // 
#define RCC_BD_RST       16   // 


/*********************************/
/* RCC_CSR bit discriptions      */
/*********************************/
#define RCC_LSI_ON       0    // 
#define RCC_LSI_RDY      1    // 
#define RCC_RMVF         24   // 
#define RCC_PIN_RSTF     26   // 
#define RCC_POR_RSTF     27   // 
#define RCC_SFT_RSTF     28   // 
#define RCC_IWDG_RSTF    29   // 
#define RCC_WWDG_RSTF    30   // 
#define RCC_LPWR_RSTF    31   //






/********************************************************************************************************/
/*	Function Name        : RCC_vInitSysClock															*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : void																			*/
/*	Function Description : Set the System CLock	according to the configration Values					*/
/********************************************************************************************************/
void RCC_vInitSysClock(void);



/********************************************************************************************************/
/*	Function Name        : RCC_vEnableClock																*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char Copy_u8BusId unsigned char Copy_u8PreId						*/
/*	Function Description : Enable the clock to the prephiral											*/
/********************************************************************************************************/
void RCC_vEnableClock(uint8 Copy_u8BusId , uint8 Copy_u8PreId);




/********************************************************************************************************/
/*	Function Name        : RCC_vDisableClock															*/
/*	Function Returns     : void																			*/
/*	Function Arguments   : unsigned char Copy_u8BusId unsigned char Copy_u8PreId						*/
/*	Function Description : Enable the clock to the prephiral											*/
/********************************************************************************************************/
void RCC_vDisableClock(uint8 Copy_u8BusId , uint8 Copy_u8PreId);



#endif // RCC_INTERFACE_H

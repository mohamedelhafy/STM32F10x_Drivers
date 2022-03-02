/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 1 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H







/********************************************************************************************************/
/*	Function Name        : STK_vInit                                                                    */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Set the Input clock According to the configration file                       */
/*                         disable the Systick and Systick INT                                          */
/********************************************************************************************************/
void STK_vInit(void);










/********************************************************************************************************/
/*	Function Name        : STK_vSetBuyWait                                                              */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32Ticks                                                  */
/*	Function Description : Enable the Systick and load the copy_u32Ticks value in Load Reg              */
/*                         wait till the count reach to 0 then disable the Systik and return            */
/********************************************************************************************************/
void STK_vSetBuyWait(uint32 copy_u32Ticks);










/********************************************************************************************************/
/*	Function Name        : STK_vSetIntervalSingle                                                       */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned long copy_u32Ticks, poiter to void function tack void               */
/*	Function Description : Set the interval and set the call Back to call it when finish                */
/********************************************************************************************************/
void STK_vSetIntervalSingle(uint32 copy_u32Ticks ,void (*copySTK_fCallBack)(void));










/********************************************************************************************************/
/*	Function Name        : STK_vSetIntervalPeriodic                                                     */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : 
/*	Function Description : 
/********************************************************************************************************/
void STK_vSetIntervalPeriodic(uint32 copy_u32Ticks ,void (*copySTK_fCallBack)(void));










/********************************************************************************************************/
/*	Function Name        : STK_vStopTimer                                                               */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Stop and Disable the Systick                                                 */
/********************************************************************************************************/
void STK_vStopTimer(void);










/********************************************************************************************************/
/*	Function Name        : STK_u32GetElapsedTime                                                        */
/*	Function Returns     : unsigned long                                                                */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Return the value counted                                                     */
/********************************************************************************************************/
uint32 STK_u32GetElapsedTime(void);










/********************************************************************************************************/
/*	Function Name        : STK_u32GetRemainingTime                                                      */
/*	Function Returns     : unsigned long                                                                */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Return the Remaining ticks                                                   */
/********************************************************************************************************/
uint32 STK_u32GetRemainingTime(void);










#endif // STK_INTERFACE_H
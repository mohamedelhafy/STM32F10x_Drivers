/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/



#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H




/********************************************************************************************************/
/*	Function Name        : LEDMRX_vInit                                                                 */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Init the LED_Matrix 8*8                                                      */
/********************************************************************************************************/
void LEDMRX_vInit(void);














/********************************************************************************************************/
/*	Function Name        : LEDMRX_vInit                                                                 */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Print data on                                                                */
/********************************************************************************************************/
void LEDMRX_vDisplay(uint8 *Copy_u8Data);











#endif  // LEDMRX_INTERFACE_H
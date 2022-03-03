/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/





/****************STD_LIBs*****************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Delay.h"


/**************LOWER_LAYERS***************/
#include "GPIO_interface.h"


/**************MY_HADER_FILES*************/
#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"







/********************************************************************************************************/
/*	Function Name        : LEDMRX_vSetRowVal                                                            */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Disable all Column                                                           */
/********************************************************************************************************/
static void LEDMRX_vDisableAllCols(void)
{
	/* Make All Conected COL As high*/
	GPIO_vWritePin(LEDMRX_COL0_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL1_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL2_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL3_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL4_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL5_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL6_PIN, HIGH_OUT);
	GPIO_vWritePin(LEDMRX_COL7_PIN, HIGH_OUT);
}











/********************************************************************************************************/
/*	Function Name        : LEDMRX_vSetRowVal                                                            */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8Value                                                   */
/*	Function Description : Set the Value of Column                                                      */
/********************************************************************************************************/
static void LEDMRX_vSetRowVal(uint8 copy_u8Value)
{
	/* Set the Val of Row*/
	GPIO_vWritePin(LEDMRX_ROW0_PIN, GET_BIT(copy_u8Value, 0));
	GPIO_vWritePin(LEDMRX_ROW1_PIN, GET_BIT(copy_u8Value, 1));
	GPIO_vWritePin(LEDMRX_ROW2_PIN, GET_BIT(copy_u8Value, 2));
	GPIO_vWritePin(LEDMRX_ROW3_PIN, GET_BIT(copy_u8Value, 3));
	GPIO_vWritePin(LEDMRX_ROW4_PIN, GET_BIT(copy_u8Value, 4));
	GPIO_vWritePin(LEDMRX_ROW5_PIN, GET_BIT(copy_u8Value, 5));
	GPIO_vWritePin(LEDMRX_ROW6_PIN, GET_BIT(copy_u8Value, 6));
	GPIO_vWritePin(LEDMRX_ROW7_PIN, GET_BIT(copy_u8Value, 7));
}











/********************************************************************************************************/
/*	Function Name        : LEDMRX_vInit                                                                 */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Init the LED_Matrix 8*8                                                      */
/********************************************************************************************************/
void LEDMRX_vInit(void)
{
	GPIO_vSetPinMode(LEDMRX_ROW0_PIN, 0b0010); // Set the ROW0 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW1_PIN, 0b0010); // Set the ROW1 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW2_PIN, 0b0010); // Set the ROW2 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW3_PIN, 0b0010); // Set the ROW3 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW4_PIN, 0b0010); // Set the ROW4 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW5_PIN, 0b0010); // Set the ROW5 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW6_PIN, 0b0010); // Set the ROW6 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_ROW7_PIN, 0b0010); // Set the ROW7 PIN As PUSH PULL Output


	GPIO_vSetPinMode(LEDMRX_COL0_PIN, 0b0010); // Set the COL0 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL1_PIN, 0b0010); // Set the COL1 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL2_PIN, 0b0010); // Set the COL2 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL3_PIN, 0b0010); // Set the COL3 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL4_PIN, 0b0010); // Set the COL4 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL5_PIN, 0b0010); // Set the COL5 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL6_PIN, 0b0010); // Set the COL6 PIN As PUSH PULL Output
	GPIO_vSetPinMode(LEDMRX_COL7_PIN, 0b0010); // Set the COL7 PIN As PUSH PULL Output
}











/********************************************************************************************************/
/*	Function Name        : LEDMRX_vInit                                                                 */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Init the LED_Matrix 8*8                                                      */
/********************************************************************************************************/
void LEDMRX_vDisplay(uint8 *Copy_u8Data)
{
	/* Column 0*/
	LEDMRX_vDisableAllCols();
	LEDMRX_vSetRowVal(copy_u8Value[0]);
	GPIO_vWritePin(LEDMRX_COL0_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL0_PIN, HIGH_OUT);

	/* Column 1*/
	LEDMRX_vSetRowVal(copy_u8Value[1]);
	GPIO_vWritePin(LEDMRX_COL1_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL1_PIN, HIGH_OUT);

	/* Column 2*/
	LEDMRX_vSetRowVal(copy_u8Value[2]);
	GPIO_vWritePin(LEDMRX_COL2_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL2_PIN, HIGH_OUT);

	/* Column 3*/
	LEDMRX_vSetRowVal(copy_u8Value[3]);
	GPIO_vWritePin(LEDMRX_COL3_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL3_PIN, HIGH_OUT);

	/* Column 4*/
	LEDMRX_vSetRowVal(copy_u8Value[4]);
	GPIO_vWritePin(LEDMRX_COL4_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL4_PIN, HIGH_OUT);

	/* Column 5*/
	LEDMRX_vSetRowVal(copy_u8Value[5]);
	GPIO_vWritePin(LEDMRX_COL5_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL5_PIN, HIGH_OUT);

	/* Column 6*/
	LEDMRX_vSetRowVal(copy_u8Value[6]);
	GPIO_vWritePin(LEDMRX_COL6_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL6_PIN, HIGH_OUT);

	/* Column 7*/
	LEDMRX_vSetRowVal(copy_u8Value[7]);
	GPIO_vWritePin(LEDMRX_COL7_PIN, LOW_OUT);
	Delay_vUS(2500); // 2.5 Msec
	GPIO_vWritePin(LEDMRX_COL7_PIN, HIGH_OUT);
}
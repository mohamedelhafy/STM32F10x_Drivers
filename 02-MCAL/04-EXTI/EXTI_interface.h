/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 27 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/
 



/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/



#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


typedef enum 
{
	RISE_EDGE =0,
	FALL_EDGE   ,
	ON_CHANGE   
}E_State_t;



typedef enum 
{
	PA=0,
	PB  ,
	PC  ,
	PD  ,
	PE  ,
	PF  ,
	PG
}E_Port_t;




typedef enum 
{
	LINE0 = 0,
	LINE1    ,
	LINE2    ,
	LINE3    ,
	LINE4    ,
	LINE5    ,
	LINE6    ,
	LINE7    ,
	LINE8    ,
	LINE9    ,
	LINE10   ,
	LINE11   ,
	LINE12   ,
	LINE13   ,
	LINE14   ,
	LINE15   ,
	LINE16   ,
	LINE17   ,
	LINE18   ,
	LINE19   
}E_Line_t;





/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void EXTI_vEnableEXTI(E_Line_t copy_E_Line, E_Port_t copy_E_Port, E_State_t copy_E_Mode);








/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void EXTI_vDisableEXTI(E_Line_t copy_E_Line);









/********************************************************************************************************/
/*	Function Name        :  */
/*	Function Returns     :  */
/*	Function Arguments   :  */
/*	Function Description :  */
/********************************************************************************************************/
void EXTI_vSwTrigger(E_Line_t copy_E_Line);





#endif  // EXTI_INTERFACE_H
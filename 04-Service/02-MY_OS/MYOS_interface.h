/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




#ifndef MYOS_INTERFACE_H
#define MYOS_INTERFACE_H





/********************************************************************************************************/
/*	Function Name        : MYOS_vCreatTask                                                              */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : unsigned char copy_u8Periority, unsigned short Copy_u16Priodicity pointer to */
/*                         void function take void                                                      */
/*	Function Description : Creat the Task                                                               */
/********************************************************************************************************/
void MYOS_vCreatTask(uint8 copy_u8Periority, uint16 copy_u16Priodicity, void (*copy_Fptr)(void));






/********************************************************************************************************/
/*	Function Name        : MYOS_vStart                                                                  */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Make the os start                                                            */
/********************************************************************************************************/
void MYOS_vStart(void);






/********************************************************************************************************/
/*	Function Name        : MYOS_vKillTask                                                               */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   :                */
/*	Function Description : Kill the task                                                                */
/********************************************************************************************************/
void MYOS_vKillTask();









#endif // MYOS_INTERFACE_H
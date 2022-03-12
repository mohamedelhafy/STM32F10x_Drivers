/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 3 MAR 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/




#ifndef MYOS_PRIVATE_H
#define MYOS_PRIVATE_H


#ifndef NULL
#define NULL   (void *)0
#endif


typedef struct 
{
	uint16 priodicity;
	void (*Fptr)(void);

}Task;



/*Array of struct hold the tasks  */
static Task OS_Tasks[NUMBER_OF_TASKS] = {NULL};




/********************************************************************************************************/
/*	Function Name        : MYOS_vStart                                                                  */
/*	Function Returns     : void                                                                         */
/*	Function Arguments   : void                                                                         */
/*	Function Description : Make the os start                                                            */
/********************************************************************************************************/
static void MYOS_vScheduler(void);









#endif // MYOS_PRIVATE_H
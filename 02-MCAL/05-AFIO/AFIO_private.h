/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 27 FEB 2022                                                                  */
/* Version : V01                                                                          */
/******************************************************************************************/




#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H



typedef struct 
{
	uint32 EVCR     ;
	uint32 MAPR1    ;
	uint32 EXTICR[4];
	uint32 MAPR2    ;
}APIO_t;


/* AFIO Base Address from Data sheet */
#define AFIO_BASE_ADDRESS    0x40010000

#define AFIO          ((volatile AFIO_t *) AFIO_BASE_ADDRESS)






#endif  // AFIO_PRIVATE_H
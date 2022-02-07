/******************************************************************************************/
/* Author  : Mohamed Farag Elhafy                                                         */
/* Date    : 4 FEB 2022                                                                   */
/* Version : V01                                                                          */
/******************************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

//sitting or clear or toggle or read a specific  bit 
#define SET_BIT(VAR,BIT)   VAR |=   (1 << (BIT))      // for sitting bit make OR"|" with one shifted lift by the pin number  
#define CLR_BIT(VAR,BIT)   VAR &=  ~(1 << (BIT))     // for clearing bit make AND"&" with the complement of one shifted lift by the pin number 
#define TOG_BIT(VAR,BIT)   VAR ^=   (1 << (BIT))    // for toggling bit make XOR"^" with the one shifted lift by the pin number
#define READ_BIT(VAR,BIT)  ((VAR >> BIT) & 1)      // for reading bit shift the VAR right with bit number then and the answer with one
#define GET_BIT(VAR,BIT)   ((VAR >> BIT) & 1)     // for reading bit shift the VAR right with bit number then and the answer with one

//asking is the bit if is set or not 
#define IS_BIT_SET(VAR,BIT)     ((VAR >> BIT) & 1)    // for return one is the bit is one make the same like GET_BIT
#define IS_BIT_CLEAR(VAR,BIT)  !((VAR >> BIT) & 1)   // for return one if the bit is zero make not of the GET_BIT

// Rotating the numbers bits
#define ROR(reg,num) reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num))  // rotate right the bits of the number  
#define ROL(reg,num) reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num)) // rotate lift the bits of the number


#endif
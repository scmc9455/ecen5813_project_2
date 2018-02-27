/*********************************************************************************************
@file - circbuf.h
@brief - circbuf.h file is the header file for the circular buffer functionality

This file contains the functions for a circular buffer to place items in memory 
and control/monitor that memory.
The buffer element size is uint8_t and size given at time of allocation.
Pointer should be passed into functions, 
The buffer and structure should be placed on the heap.
The buffer needs to be atomic by enabling/disabling global interrupts 
with (__enable_irq() and __disable_irq()) CMSYS 
functions (not needed on the BBB or HOST: map to nothing).

bufferFull and BufferEmpty needs to be static inline 
(These need to be accounted for on the C89 compiler)???

This file is the source for the circular buffer functions
1. CB_init
2. CB_destroy
3. CB_buffer_add_item
4. CB_buffer_remove_item
5. CB_is_full
6. CB_is_empty
7. CB_peek

@author - Scott McElroy

@date - February 25, 2018

Created for ECEN5813
**********************************************************************************************/
#ifndef __CIRCBUF_H__
#define __CIRCBUF_H__

#include <stdint.h>
#include <stdlib.h>

#define START_CRITICAL() /*Defines enable function of interrupts*/
#define END_CRITICAL()   /*Defines disable function of interrupts*/

typedef struct {
  Base Memory Pointer
  Head
  Tail
  Length/Size
  Count
}CB_t;

typedef enum {
  Success/No Error
  Circular Buffer Null Pointer Errors
  No Length Error
  Buffer Full Error
  Buffer Empty Error
} CB_e;

/*********************************************************************************************/
/***********************************CB_INIT***************************************************/
/**********************************************************************************************
@brief- This function is initializes the circular buffer

This function initializes a circular buffer with length and the pointer to the buffer
The function returns error codes on success of failure
The buffer allocates Head,Tail, and count

@param - pointer type of the buffer
@param - buffer length
@return - status of the buffer
**********************************************************************************************/

<CB enum type> CB_init(<pointer of buffer type>,<length of buffer>);

/*********************************************************************************************/
/***********************************CB_Destroy************************************************/
/**********************************************************************************************
@brief- This function deallocates the memory of the circular buffer

The function takes in a pointer of the buffer to be destroyed and deallocates the entire buffer
including memory and pointers using FREE. The pointer of the buffer is set to NULL.

@param - pointer type to the buffer
@return - status of the buffer
**********************************************************************************************/

<CB enum type> CB_destroy(<pointer of buffer type>);

/*********************************************************************************************/
/******************************CB_buffer_add_item*********************************************/
/**********************************************************************************************
@brief- This function adds an item to the buffer

The function takes in a pointer to the buffer, and data to be added.
The function returns the success or failure of the buffer function.

@param - pointer to the buffer
@param - data to add to the buffer
@return - status of the buffer
**********************************************************************************************/

<CB enum type> CB_buffer_add_item(<buffer to add to>,<data to add>);

/*********************************************************************************************/
/******************************CB_buffer_remove_item******************************************/
/**********************************************************************************************
@brief- This function removes an item to the buffer

The function takes in a pointer to the buffer, and variable to store/remove item from the bufer
The function returns the success or failure of the buffer function.

@param - pointer type of the buffer
@param - variable to store the removed data
@return - status of the buffer
**********************************************************************************************/

<CB enum type> CB_buffer_remove_item(<buffer to remove from>,<variable to store data removed>);

/*********************************************************************************************/
/************************************CB_is_full***********************************************/
/**********************************************************************************************
@brief- This function will check to see if the buffer is full

The function takes in a pointer to the buffer, and checks to see if the buffer is full.

@param - pointer type of the buffer
@return - Full or Not Full (1 or 0)
**********************************************************************************************/

static inline <CB enum type> CB_is_full(<buffer to check>) __attribute__ ((always_inline));

/*********************************************************************************************/
/************************************CB_is_empty**********************************************/
/**********************************************************************************************
@brief- This function will check to see if the buffer is empty

The function takes in a pointer to the buffer, and checks to see if the buffer is empty.

@param - pointer type of the buffer
@return - Empty or Not Empty (1 or 0)
**********************************************************************************************/

static inline <CB enum type> CB_is_empty(<buffer to check>) __attribute__ ((always_inline));

/*********************************************************************************************/
/****************************************CB_peek**********************************************/
/**********************************************************************************************
@brief- This function will check to see if the buffer is empty

The function takes in a pointer to the buffer, and checks to see if the buffer is empty.

@param - pointer type of the buffer
@param - position from the head of the buffer to peek
@param - pointer to hold the data peeked at
@return - Status of the operation
**********************************************************************************************/

<CB enum type> CB_peek(<buffer to peek into>,<position to peek>,<holder for the peeked value>);


#endif /*__CIRCBUF_H__*/

/*********************************************************************************************/
/**************************************End of File********************************************/
/*********************************************************************************************/

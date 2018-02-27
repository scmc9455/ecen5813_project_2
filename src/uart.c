/*********************************************************************************************
@file - uart.c
@brief - uart.c file is the source file for the uart functionality

This file contains the functions for the uart functions for the KL25z freedom board.
The library contains the method of transmitting and receiving data characters without
the use of printf and debug console.
The freedom board has an on board UART to USB connector to use OpenSDA.

UART Setup
- LSb first
- 1 Start/1 Stop Bits
- 8-bit data transfers
- No Parity
- The fastest BAUD is 115200/38400/57200 Baud
BAUD Value is not hardcoded

This file header contains functions
1. CB_init
2. CB_destroy
3. CB_buffer_add_item
4. CB_buffer_remove_item
5. CB_is_full
6. CB_is_empty
7. CB_peek

@author - Scott McElroy

@date - February 26, 2018

Created for ECEN5813
**********************************************************************************************/

#include "uart.c"

/*********************************************************************************************/
/***********************************UART_Configure********************************************/
/**********************************************************************************************
@brief- This function configures the UART module

This function configures the UART module settings setup and BAUD rate

@param - settings
@return - status of the UART
**********************************************************************************************/

<type> UART_configure(<settings>)
{
  return 0;
}

/*********************************************************************************************/
/***********************************UART_send*************************************************/
/**********************************************************************************************
@brief- This UART function is to send one byte data

This function is for UART module to send out data through this module in one byte
This function blocks on transmitted data.

@param - pointer to the data to send
@return - status of the UART
**********************************************************************************************/

<type> UART_send(<data-to-send>)
{
  return 0;
}

/*********************************************************************************************/
/***********************************UART_send_n***********************************************/
/**********************************************************************************************
@brief- This UART function is to send a data block

This function is for UART module to send out data through this module in a block of bytes
This function also takes in the amount of data to be transmitted.
This function blocks on transmitted data.

@param - pointer to the data to send
@param - length of data to be sent
@return - status of the UART
**********************************************************************************************/

<type> UART_send(<data-to-send>,<length-of-data>)
{
  return 0;
}

/*********************************************************************************************/
/***********************************UART_receive**********************************************/
/**********************************************************************************************
@brief- This UART function is to receive one byte of data

This function is for UART module to recieve data through this module in one byte
This function blocks until receive data is complete.

@param - pointer to the location to put received data
@return - status of the UART
**********************************************************************************************/

<type> UART_receive(<received-data>)
{
  return 0;
}

/*********************************************************************************************/
/***********************************UART_receive_n********************************************/
/**********************************************************************************************
@brief- This UART function is to receive a block of data

This function is for UART module to recieve data through this module in one block of data
This function also takes in the number of items for the block to receive.
This function blocks until receive data is complete.

@param - pointer to the location to put received data
@param - number of items to be received
@return - status of the UART
**********************************************************************************************/

<type> UART_receive(<received-data>,<length-of-data_to_receive>)
{
  return 0;
}

/*********************************************************************************************/
/***********************************UART0-IRQHandler******************************************/
/**********************************************************************************************
@brief- This function handles the interrupts of the UART module

This function handles both receive and transmit interrupts.
The interrupt clears the associated flags when complete if they were set.
This is a short function.

@param - void
@return - void
**********************************************************************************************/

void UART0_IRQHandler()
{
  return 0;
}

#endif /*__UART_H__*/

/*********************************************************************************************/
/***********************************END of FILE***********************************************/
/*********************************************************************************************/

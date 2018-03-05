/*********************************************************************************************
@file - uart.h
@brief - uart.h file is the header file for the uart functionality

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
1. UART_configure
2. UART_send
3. UART_send_n
4. UART_receive
5. UART_receive_n
6. IRQHandler

@author - Scott McElroy

@date - March 3, 2018

Created for ECEN5813
**********************************************************************************************/
#ifndef __UART_H__
#define __UART_H__

#include <stdint.h>
#include <stdlib.h>

typedef enum{
  UART_SUCCESS =0,
  UART_FAIL    =1
}status_e;

#define BAUD_HS  (115200)
#define BAUD_MS  (57200)
#define BAUD_LS  (38400)
/*System Defines*/
#define SIM_SCGC4 (*((volatile uint32_t *)(0x40048034)))
#define SIM_SCGC5 (*((volatile uint32_t *)(0x40048038)))
#define SIM_SCGC6 (*((volatile uint32_t *)(0x4004803C)))
#define SIM_SCGC7 (*((volatile uint32_t *)(0x40048040)))

#define SIM_PORTA_MASK (0x200)
#define SIM_PORTB_MASK (0x400)
#define SIM_PORTC_MASK (0x800)
#define SIM_PORTD_MASK (0x1000)
#define SIM_PORTE_MASK (0x2000)

#define SIM_UART0_MASK (0x400)
#define SIM_UART1_MASK (0x800)
#define SIM_UART2_MASK (0x1000)

#define PORTA_PCR1 (*((volatile uint32_t *)(0x40049004)))
#define PORTA_PCR2 (*((volatile uint32_t *)(0x40049008)))

#define ALT0 (0b000 << 8)
#define ALT2 (0b010 << 8)

#define SIM_SOPT2 (*((volatile uint32_t *)(0x40048004)))
#define SIM_SOPT5 (*((volatile uint32_t *)(0x40048010)))
/*UART Defines*/
#define UART0SRC_MCGFLLCLK (0b01 << 26)
#define PLLFLLSEL          (0b1 << 16)
#define UART0RXSRC         (0b1 << 2)
#define UART0TXSRC         (0b11)

#define UART0_BDH  (*((volatile uint32_t *)(0x4006A000)))
#define UART0_BDL  (*((volatile uint32_t *)(0x4006A001)))
#define UART0_C1   (*((volatile uint32_t *)(0x4006A002)))
#define UART0_C2   (*((volatile uint32_t *)(0x4006A003)))
#define UART0_S1   (*((volatile uint32_t *)(0x4006A004)))
#define UART0_S2   (*((volatile uint32_t *)(0x4006A005)))
#define UART0_C3   (*((volatile uint32_t *)(0x4006A006)))
#define UART0_D    (*((volatile uint32_t *)(0x4006A007)))
#define UART0_C4   (*((volatile uint32_t *)(0x4006A00A)))
#define UART0_C5   (*((volatile uint32_t *)(0x4006A00B)))

#define UART_PARITY_EN  (0b1 << 1)
#define UART_STOP_BIT   (0b1 << 5)
#define UART_8BIT       (0b1 << 4)
#define UART_TX_EN      (0b1 << 3)
#define UART_RX_EN      (0b1 << 2)
#define UART_RIE        (0b1 << 5)
#define UART_TIE        (0b1 << 7)
#define OSR_16x         (0b01111)
#define UART_SBR_BDH    (0b1111)
#define UART_SBR_BDL    (0xFF)
#define MCGFLLCLK_4MHz  (4000000)
#define UART_MSB_FIRST  (0b1 << 5)
#define UART_TDRE       (0b1 << 7)
#define UART_RDRF       (0b1 << 5)

/*Including CMSIS and device.h info*/
#define UART0_interrupt (12)
#define __NVIC_SET_REG      (*((uint32_t *)(0xE000E100)))
#define __NVIC_CLEAR_REG    (*((uint32_t *)(0xE000E180)))
#define disable_NVIC_IRQ(x) (1 << ((uint32_t)(x) & 0x1F))
#define enable_NVIC_IRQ(x)  (1 << ((uint32_t)(x) & 0x1F))

/*Define the Macros to turn on and off the global interrupts*/
#define START_CRITICAL(x)  (enable_NVIC_IRQ(x))
#define END_CRITICAL(x)    (disable_NVIC_IRQ(x)) 

/*********************************************************************************************/
/***********************************UART_Configure********************************************/
/**********************************************************************************************
@brief- This function configures the UART module

This function configures the UART module settings
This includes port, baud and UART module.

@param - baud: settings to configure speed
@return -status of the UART
**********************************************************************************************/

status_e UART_configure(uint32_t baud);

/*********************************************************************************************/
/***********************************UART_send*************************************************/
/**********************************************************************************************
@brief- This UART function is to send one byte data

This function is for UART module to send out data through this module in one byte
This function blocks on transmitted data.

@param - *data: pointer to the data to send
@return - status of the UART
**********************************************************************************************/

status_e UART_send(uint8_t *data);

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

status_e UART_send_n(uint8_t *data, size_t length);

/*********************************************************************************************/
/***********************************UART_receive**********************************************/
/**********************************************************************************************
@brief- This UART function is to receive one byte of data

This function is for UART module to recieve data through this module in one byte
This function blocks until receive data is complete.

@param - pointer to the location to put received data
@return - status of the UART
**********************************************************************************************/

status_e UART_receive(uint8_t *data);

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

status_e UART_receive_n(uint8_t *data, size_t length);

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

void UART0_IRQHandler();

#endif /*__UART_H__*/

/*********************************************************************************************/
/***********************************END of FILE***********************************************/
/*********************************************************************************************/

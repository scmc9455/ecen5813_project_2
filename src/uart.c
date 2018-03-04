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
1. UART_configure
2. UART_send
3. UART_send_n
4. UART_receive
5. UART_receive_n
6. IRQHandler

uses the circbuf

@author - Scott McElroy

@date - March 3, 2018

Created for ECEN5813
**********************************************************************************************/

#include "uart.h"

/*********************************************************************************************/
/***********************************UART_Configure********************************************/
/**********************************************************************************************
@brief- This function configures the UART module

This function configures the UART module settings
This includes port, baud and UART module.

@param - baud: settings to configure speed
@return -status of the UART
**********************************************************************************************/

status_e UART_configure(uint32_t baud)
{
    uint16_t prescaler;
    uint8_t prescaler_l, prescaler_h;

    /*This code will configure PORTA UART0*/
    SIM_SCGC5 |= SIM_PORTA_MASK;
    /*Configure the SIM for UART0*/
    SIM_SCGC4 |= SIM_UART0_MASK;
    /*Set the port characteristics*/
    /*For PORTA-UART0, pin 1=RX and pin2=TX*/
    PORTA_PCR1 &= ALT0; /*ALT0 and the &= resets the bits*/
    PORTA_PCR1 |= ALT2; /*ALT2 is UART for this port*/
    PORTA_PCR2 &= ALT0; /*ALT0 and the &= resets the bits*/
    PORTA_PCR2 |= ALT2; /*ALT2 is UART for this port*/

    /*Set the UART clock to be MGCFLLCLK through SOPT2 SIM module*/
    SIM_SOPT2 |= UART0SRC_MCGFLLCLK;
    SIM_SOPT2 &= ~PLLFLLSEL; /*Selects the FLL clock for UART instead of PLL*/

    /*Changing the UART0 to output through the UART0 pins*/
    SIM_SOPT5 &= ~(UART0RXSRC + UART0TXSRC);

    /*Setting the UART proper setup*/
    UART0_BDH &= ~(UART_STOP_BIT); /*clears the stop bit to get 1-bit ports*/
    /*clears the UART transmission data to 8-bits and disabling the parity*/
    UART0_C1 &= ~(UART_8BIT + UART_PARITY_EN); 
    /*Sets the transmission to LSB*/
    UART0_S2 &= ~UART_MSB_FIRST;     

    /*Set up the over sampling, defualt value is *16*/
    UART0_C4 |= OSR_16x; 
    /*Set the BAUD rate in the BDL and BDH register*/
    /*The calculation is for the prescaler= MCGFLLCLK_4MHz/((OSR+1)*baudrate)*/
    UART0_BDH &= ~(UART_SBR_BDH); /*Clearing out the prescaler*/
    UART0_BDL &= ~(UART_SBR_BDL); /*Clearing out the prescaler*/
 
    /*Value is calculated for the prescaler and put into a variable to be broken up*/
    prescaler = (MCGFLLCLK_4MHz/((OSR_16x + 1) * baud));
    /*put the low value into the prescaler low so it fits into the register*/
    prescaler_l = (uint8_t)(prescaler);
    /*subtracting the low value from the prescaler bit then leaves the leftover*/
    prescaler_h = (uint8_t)((prescaler)-(uint16_t)(prescaler_l));
    /*put those vavlues into the register*/
    UART0_BDH |= (prescaler_h);
    UART0_BDL |= (prescaler_l);

    /*enable the UART transmit and receive now that the module is configured*/
    UART0_C2 |= (UART_TX_EN + UART_RX_EN);

    return UART_SUCCESS;
}

/*********************************************************************************************/
/***********************************UART_send*************************************************/
/**********************************************************************************************
@brief- This UART function is to send one byte data

This function is for UART module to send out data through this module in one byte
This function blocks on transmitted data.
Send and receive requests can be enable through interrupts outside of this filein main.

@param - *data: pointer to the data to send
@return - status of the UART
**********************************************************************************************/

status_e UART_send(uint8_t *data)
{
    if(data==NULL)
    {
        return UART_FAIL;
    }
    
    while((UART0_S1 & UART_TDRE) == 0); /*wait for the buffer to be open, then transmit*/
    UART0_D = *data;

    return UART_SUCCESS;
}

/*********************************************************************************************/
/***********************************UART_send_n***********************************************/
/**********************************************************************************************
@brief- This UART function is to send a data block

This function is for UART module to send out data through this module in a block of bytes
This function also takes in the amount of data to be transmitted.
This function blocks on transmitted data.
Send and receive requests can be enable through interrupts outside of this filein main.

@param - *data: pointer to the data to send
@param - length: length of data to be sent
@return - status of the UART
**********************************************************************************************/

status_e UART_send_n(uint8_t *data, size_t length)
{
    if(data == NULL)
    {
       return UART_FAIL;
    } 
    /*create a temporary variable for the block transmit*/
    uint32_t i;
    /*run a loop base on the length of the data to be able to transmit the whole block*/
    for(i=0;i<length;i++)
    {
        while((UART0_S1 & UART_TDRE) == 0); /*wait for the buffer to be open, then transmit*/
        UART0_D = *data;
        data += 1;
    }
     
    return UART_SUCCESS;
}

/*********************************************************************************************/
/***********************************UART_receive**********************************************/
/**********************************************************************************************
@brief- This UART function is to receive one byte of data

This function is for UART module to recieve data through this module in one byte
This function blocks until receive data is complete.
Send and receive requests can be enable through interrupts outside of this filein main.

@param - *data: pointer to the location to put received data
@return - status of the UART
**********************************************************************************************/

status_e UART_receive(uint8_t *data)
{
    if(data == NULL)
    {
       return UART_FAIL;
    } 

    while((UART0_S1 & UART_RDRF) == 0); /*wait for the buffer to be full receive*/
    *data = UART0_D; /*Stores the value from the receive buffer into the data pointer*/

    return UART_SUCCESS;
}

/*********************************************************************************************/
/***********************************UART_receive_n********************************************/
/**********************************************************************************************
@brief- This UART function is to receive a block of data

This function is for UART module to recieve data through this module in one block of data
This function also takes in the number of items for the block to receive.
This function blocks until receive data is complete.
Send and receive requests can be enable through interrupts outside of this filein main.

@param - *data: pointer to the location to put received data
@param - length: number of items to be received
@return - status of the UART
**********************************************************************************************/

status_e UART_receive_n(uint8_t *data, size_t length)
{
    if(data == NULL)
    {
       return UART_FAIL;
    } 
    /*create a temporary variable for the block transmit*/
    uint32_t i;
    /*run a loop base on the length of the data to be able to transmit the whole block*/
    for(i=0;i<length;i++)
    {
        while((UART0_S1 & UART_RDRF) == 0); /*wait for the buffer to be full receive*/
        *data = UART0_D; /*Stores the value from the receive buffer into the data pointer*/
        data += 1; /*increase the data pointer*/
    }

    return UART_SUCCESS;
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
    /*Disables any more UART interrupts from happening*/
    __NVIC_CLEAR_REG |= disable_NVIC_IRQ(UART0_interrupt);

    /*If a transmit interrupt was enabled and the UART TX data register is empty*/
    /*store the global variable into the data register*/
    if(((UART0_C2 & UART_TIE)!=0) && ((UART0_S1 & UART_TDRE) != 0))
    {
        UART0_C2 &= ~(UART_TIE); /*Clear the transmit interrupt enable*/ 
        /*Re-enbles UART interrupts prior to leaving the handler*/
        __NVIC_SET_REG |= enable_NVIC_IRQ(UART0_interrupt);
        return;
    }

    /*If a receive interrupt was enabled and the UART RX data register is full*/
    /*take the data register and put it into the global variable*/
    if(((UART0_C2 & UART_RIE)!=0) && ((UART0_S1 & UART_RDRF)!=0))
    {
        /*Re-enbles UART interrupts prior to leaving the handler*/
        __NVIC_SET_REG |= enable_NVIC_IRQ(UART0_interrupt);
        return;
    }

    return;
}

/*********************************************************************************************/
/***********************************END of FILE***********************************************/
/*********************************************************************************************/

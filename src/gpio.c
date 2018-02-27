/*********************************************************************************************
@file - gpio.c

@brief - gpio.c file a source file for the manipulation of port registers

This is the source file for port manipulation functions
The included function declarations are
1. GPIO_Configure
2. Toggle_Red_LED
3. PORTB_set
4. PORTD_Set
5. PORTB_Clear
6. PORTD_Clear
7. PORTB_Toggle
8. PORTD_Toggle

@author - Scott McElroy

@date - February 25, 2018

Created for ECEN5813
**********************************************************************************************/
#include "gpio.h"

#include <stdint.h>
#include <stdlib.h>

/*********************************************************************************************/
/******************************GPIO_Configure*************************************************/
/**********************************************************************************************
@brief- This function configures the RGB LEDs to output their intial values

RGB LED constants are configured in the header files.
Red LED is PORTB-Pin18 initial state off
Green LED is PORTB-Pin19 initial state off
Blue LED is PORTD-Pin1 initial state off

@param - void
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void GPIO_Configure()
{
    
}

/*********************************************************************************************/
/******************************Toggle_RED_LED*************************************************/
/**********************************************************************************************
@brief- This function toggles the Red LEDs

@param - void
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void Toggle_Red_LED()
{
    
}

/*********************************************************************************************/
/******************************PORTB_Set******************************************************/
/**********************************************************************************************
@brief- This function sets the portB register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void PORTB_Set(uint8_t bit_num)
{
    
}

/*********************************************************************************************/
/******************************PORTD_Set******************************************************/
/**********************************************************************************************
@brief- This function set the portD register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void PORTD_Set(uint8_t bit_num)
{
    
}

/*********************************************************************************************/
/******************************PORTB_Clear****************************************************/
/**********************************************************************************************
@brief- This function clears the portB register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void PORTB_Clear(uint8_t bit_num)
{
    
}

/*********************************************************************************************/
/******************************PORTD_Clear****************************************************/
/**********************************************************************************************
@brief- This function clears the portD register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void PORTD_Clear(uint8_t bit_num)
{
    
}

/*********************************************************************************************/
/******************************PORTB_Toggle**************************************************/
/**********************************************************************************************
@brief- This function toggles the portB register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void PORTB_Toggle(uint8_t bit_num)
{
    
}

/*********************************************************************************************/
/******************************PORTD_Toggle***************************************************/
/**********************************************************************************************
@brief- This function toggles the portD register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void PORTD_Toggle(uint8_t bit_num)
{
    
}

/*********************************************************************************************/
/******************************END of file****************************************************/

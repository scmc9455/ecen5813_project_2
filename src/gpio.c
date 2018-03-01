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
    /*Turn the clock on for the portB and portD modules*/
    SIM_SCGC5 |= (SIM_SCGC5_PORTB + SIM_SCGC5_PORTD)

    PORTB_PCR18 |= ALT1; /*Sets the portB_pin18 to be gpio*/
    PORTB_PCR19 |= ALT1; /*Sets the portB_pin19 to be gpio*/
    PORTD_PCR1 |= ALT1;  /*Sets the portD_pin1 to be gpio*/

    GPIOB_PDDR |= (RGB_RED_PIN + RGB_GREEN_PIN); /*Sets pin 18 and pin 19 to outputs*/
    GPIOD_PDDR |= (RGB_BLUE_PIN); /*Sets portd pin 1 to output*/

    GPIOB_PCOR |= (RGB_RED_PIN + RGB_GREEN_PIN); /*converts pin 18 and pin 19 to logic low*/
    GPIOD_PCOR |= (RGB_BLUE_PIN); /*converts port d pin 1 to logic low*/
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
    GPIOB_PTOR |= (RGB_RED_PIN); /*toggles portb bit 18 in the toggle register */
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
    GPIOB_PSOR |= (0x1 << bit_num);/*sets the value in the port b register based on bit number*/
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
    GPIOD_PSOR |= (0x1 << bit_num);/*sets the value in the port d register based on bit number*/
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
    GPIOB_PCOR |= (0x1 << bit_num); /*clears the value in port b register based on bit number*/
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
    GPIOD_PCOR |= (0x1 << bit_num); /*clears the value in port d register from bit number*/    
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
    GPIOB_PTOR |= (0x1 << bit_num); /*toggles port b register based on bit number*/    
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
    GPIOD_PTOR |= (0x1 << bit_num); /*toggles port d register based on bit number*/       
}

/*********************************************************************************************/
/******************************END of file****************************************************/

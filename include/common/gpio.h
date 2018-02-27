/*********************************************************************************************
@file - gpio.h

@brief - gpio.h file the header file for the manipulation of port registers

This is the header file for port manipulation functions
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
#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>
#include <stdlib.h>

#define RGB_RED_PIN        (???)
#define RGB_GREEN_PIN      (???)
#define RGB_BLUE_PIN       (???)

#define RGB_RED_ON()     (PORTB_Set( RGB_RED_PIN ))
#define RGB_RED_OFF()    (PORTB_Clear( RGB_RED_PIN ))
#define RGB_RED_TOGGLE() (PORTB_Toggle( RGB_RED_PIN ))

#define RGB_GREEN_ON()     (PORTB_Set( RGB_GREEN_PIN ))
#define RGB_GREEN_OFF()    (PORTB_Clear( RGB_GREEN_PIN ))
#define RGB_GREEN_TOGGLE() (PORTB_Toggle( RGB_GREEN_PIN ))

#define RGB_BLUE_ON()     (PORTD_Set( RGB_BLUE_PIN ))
#define RGB_BLUE_OFF()    (PORTD_Clear( RGB_BLUE_PIN ))
#define RGB_BLUE_TOGGLE() (PORTD_Toggle( RGB_BLUE_PIN ))

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

static inline void GPIO_Configure() __attribute__ ((always_inline)) ;

/*********************************************************************************************/
/******************************Toggle_RED_LED*************************************************/
/**********************************************************************************************
@brief- This function toggles the Red LEDs

@param - void
@return - void
**********************************************************************************************/

static inline void Toggle_Red_LED() __attribute__ ((always_inline));

/*********************************************************************************************/
/******************************PORTB_Set******************************************************/
/**********************************************************************************************
@brief- This function sets the portB register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

static inline void PORTB_Set(uint8_t bit_num) __attribute__ ((always_inline));

/*********************************************************************************************/
/******************************PORTD_Set******************************************************/
/**********************************************************************************************
@brief- This function set the portD register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

static inline void PORTD_Set(uint8_t bit_num) __attribute__ ((always_inline));

/*********************************************************************************************/
/******************************PORTB_Clear****************************************************/
/**********************************************************************************************
@brief- This function clears the portB register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

static inline void PORTB_Clear(uint8_t bit_num) __attribute__ ((always_inline));

/*********************************************************************************************/
/******************************PORTD_Clear****************************************************/
/**********************************************************************************************
@brief- This function clears the portD register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

static inline void PORTD_Clear(uint8_t bit_num) __attribute__ ((always_inline));

/*********************************************************************************************/
/******************************PORTB_Toggle**************************************************/
/**********************************************************************************************
@brief- This function toggles the portB register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

static inline void PORTB_Toggle(uint8_t bit_num) __attribute__ ((always_inline));

/*********************************************************************************************/
/******************************PORTD_Toggle***************************************************/
/**********************************************************************************************
@brief- This function toggles the portD register output bit field

@param - bit_num: The bit to be changed in the port register
@return - void
**********************************************************************************************/

static inline void PORTD_Toggle(uint8_t bit_num) __attribute__ ((always_inline));

/*********************************************************************************************/

#endif /*__GPIO_H__*/

/*********************************************************************************************/
/******************************END of file****************************************************/

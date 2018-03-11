/*********************************************************************************************
@file - main.c

@brief - main program header file

This program only calls functions from project2
This also include all the necessary libraries and headers that are used in each of the files

@author - Scott McElroy

@date - February 25, 2018

Created for ECEN5813
**********************************************************************************************/

#include "project1.h"
#include "project2.h"

#include "gpio.h"

int main(void)
{
    uint32_t run=1;
    #ifdef PROJECT1	
        project1();
    #endif
    
    #ifdef PROJECT2	
        project2();
    #endif

    #ifdef BOARD	
        GPIO_Configure();
        while(run)
        {
            PORTB_Toggle(RGB_RED_PIN);
            for(uint32_t delay=0; delay<10000; delay++){};
            PORTD_Toggle(RGB_GREEN_PIN);
            for(uint32_t delay=0; delay<10000; delay++){};
        }
    #endif

    while(run){};    
}

/*********************************************************************************************/
/**************************************End of File********************************************/
/*********************************************************************************************/

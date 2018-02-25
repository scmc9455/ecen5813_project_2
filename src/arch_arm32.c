/*********************************************************************************************
@file - arch_arm32.c

@brief - arch_arm32 file is the source file for the ARM Architecture functionality

This file is the source for the data.c file and includes the functions
1. ARM32_AIRCR_get_endianness_setting

@author - Scott McElroy

@date - February 8, 2018

Created for ECEN5813
**********************************************************************************************/

#include "arch_arm32.h"
#include <stdint.h>
#include <stdlib.h>

/*********************************************************************************************/
/*************ARM32_AIRCR_get_endianness_setting**********************************************/
/**********************************************************************************************
@brief- This function is to read Endianness of the ARM register.

Reports the endianness of the processor from the AIRCR.
This is meant to be an inline function.

@param - none
@return - the endianness of the processor
**********************************************************************************************/
__attribute__ ((always_inline)) static inline uint32_t ARM32_AIRCR_get_endianness_setting()
{

    uint32_t endian_var;
    uint32_t *aircr_ptr = (uint32_t *)(__AIRCR);

    endian_var = *aircr_ptr && __AIRCR_ENDIANNESS_MASK; 
    /*Set endain_var to only have one bit*/
    endian_var = endian_var >> __AIRCR_ENDIANNESS_OFFSET; /* shift bit down to the LSb */

    return (endian_var);
}	

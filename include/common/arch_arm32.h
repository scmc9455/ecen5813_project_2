/*********************************************************************************************
@file - arch_arm32.h

@brief - arch_arm32 file is the header file for the ARM Architecture functionality

This file is the header for the arch_arm32.c file and includes the functions
1. ARM32_AIRCR_get_endianness_setting

@author - Scott McElroy

@date - February 8, 2018

Created for ECEN5813
**********************************************************************************************/

#ifndef __ARCH_ARM32__
#define __ARCH_ARM32__

#include <stdint.h>

#define __SCB_ADDRESS             (0xE000ED00)
#define __AIRCR_ADDRESS_OFFSET    (12)
#define __AIRCR                   (__SCB_ADDRESS + __AIRCR_ADDRESS_OFFSET)
#define __AIRCR_ENDIANNESS_OFFSET (16)
#define __AIRCR_ENDIANNESS_MASK   (0x00008000)

/*********************************************************************************************/
/****************ARM32_AIRCR_get_endianness_setting**********************************************/
/**********************************************************************************************
@brief- This function is to read Endianness of the ARM register.

Reports the endianness of the processor from the AIRCR.
This is meant to be an inline function.

@param - none
@return - the endianness of the processor
**********************************************************************************************/

static inline uint32_t ARM32_AIRCR_get_endianness_setting() __attribute__((always_inline));

#endif /*_ARCH_ARM32_*/

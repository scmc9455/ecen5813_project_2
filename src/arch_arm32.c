/*********************************************************************************************
@file - arch_arm32.c

@brief - arch_arm32 file is the source file for the ARM Architecture functionality

This file is the source for the arch_arm32 acrhitecture file and includes the functions
1. ARM32_AIRCR_get_endianness_setting
2. ARM32_CCR_get_stack_alignment
3. ARM32_CPUID_get_part_number
4. ARM32_CCR_enable_divide_by_zero_trap
5. ARM32_CCR_enable_unaligned_access_trap
6. ARM32_create_unaligned_access_trap
7. ARM32_create_divide_by_zero_trap

@author - Scott McElroy

@date - February 25, 2018

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

/*********************************************************************************************/
/******************ARM32_CCR_get_stack_alignment**********************************************/
/**********************************************************************************************
@brief- This function reads the CCR register and returns the stack alignment value

This function is used to get the alignment of the stack value and directly memory
dereferenced. 

@param - void
@return - value of the alignment
**********************************************************************************************/

__attribute__ ((always_inline)) static inline uint32_t ARM32_CCR_get_stack_alignment()
{
  return 0;
}

/*********************************************************************************************/
/********************ARM32_CPUID_get_part_number**********************************************/
/**********************************************************************************************
@brief- This function reads the CPU ID register and returns part number and ARM Core

This function is used to get the value of the ARM core type and part number and returns
the direct memory dereferenced value

@param - void
@return - part number of ARM core
**********************************************************************************************/

__attribute__ ((always_inline)) static inline uint32_t ARM32_CPUID_get_part_number()
{
  return 0xC24;
}

/*********************************************************************************************/
/********************ARM32_CCR_enable_divide_by_zero******************************************/
/**********************************************************************************************
@brief- This function writes the CCR register to set the divide by zero trap

This function is used to set the value of the divide by zero bit in CCR to 1 (DIV_0_TRP)
This function uses a direct memory dereference

@param - void
@return - 1 if the function ran correctly
**********************************************************************************************/

__attribute__ ((always_inline)) static inline uint32_t ARM32_CCR_enable_divide_by_zero()
{
  return 1;
}

/*********************************************************************************************/
/*****************ARM32_CCR_enable_unaligned access_trap**************************************/
/**********************************************************************************************
@brief- This function writes the CCR register to set the unaligned memory access trap

This function is used to set the value of the unaligned memory trap bit in CCR to 1 (UNALIGN_TRP). This function uses a direct memory dereference

@param - void
@return - 1 if the function ran correctly
**********************************************************************************************/

__attribute__ ((always_inline)) static inline uint32_t ARM32_CCR_enable_unaligned access_trap()
{
  return 1;
}

/*********************************************************************************************/
/*********************ARM32_create_unaligned_access_trap**************************************/
/**********************************************************************************************
@brief- This function performs an unaligned memory access that triggers UNALIGN_TRP

This function is used to perform unaligned access so that is triggers the trap from CCR

@param - void
@return - void
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void ARM32_create_unaligned access_trap()
{

}

/*********************************************************************************************/
/*********************ARM32_create_divide_by_zero_trap****************************************/
/**********************************************************************************************
@brief- This function performs a divide by zero that triggers (DIV_0_TRP)

This function is used to perform a divide by zero so that is triggers the trap from CCR
This function should not return and should create a usage fault exception

@param - void
@return - should not return
**********************************************************************************************/

__attribute__ ((always_inline)) static inline void ARM32_create_divide_by_zero_trap()
{

}

/*********************************************************************************************/
/**************************************End of File********************************************/
/**********************************************************************************************

/*********************************************************************************************
@file - unit_tests.c
@brief - unit_teste.c file is the source file for the testing functionality of all of the various functions included in this project2

Tests will incude
memory.c
-memmove tests
-memset tests
-memzero tests
-reverse
conversion.c
-atoi
-itoa
data.c
-Endianess conversion
circbuf.c
-various tests

@author - Scott McElroy

@date - March 4, 2018

Created for ECEN5813
**********************************************************************************************/

#include "unit_tests.h"

/*********************************************************************************************/
/***********************************main for testing******************************************/
/**********************************************************************************************
@brief- This function is the main loop for the tests

@param - void
@return - void
**********************************************************************************************/

void main()
{
   uint8_t total=0;   
 
    printf("total = %d \n",total)
    total += memmove_tests();
    printf("total = %d \n",total);
    total += memset_tests();
    printf("total = %d \n",total)
    total += memzero_tests();
    printf("total = %d \n",total)
    total += reverse_tests();
    printf("total = %d \n",total)
    total += atoi_tests();
    printf("total = %d \n",total)
    total += itoa_tests();
    printf("total = %d \n",total)
    total += endianness_tests();
    printf("total = %d \n",total)
    total += circbuf_tests();

    printf("The total number of functions that failed is %d \n",total);

    return;
}

/*********************************************************************************************/
/**************************************memmove_tests******************************************/
/**********************************************************************************************
@brief- This function tests the memmove features

Tests:
invalid pointers
No overlap
SRC in DST
DST in SRT
DST == SRC

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e memmove_tests()
{
    return TEST_PASS;
}

/*********************************************************************************************/
/**************************************memset_tests******************************************/
/**********************************************************************************************
@brief- This function tests the memmove features

Tests:
invalid pointers
checks the set

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e memset_tests()
{
    return TEST_PASS;     
}

/*********************************************************************************************/
/**************************************memzero_tests******************************************/
/**********************************************************************************************
@brief- This function tests the memzero features

Tests:
invalid pointers
checks the set

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e memzero_tests()
{
    return TEST_PASS;    
}

/*********************************************************************************************/
/**************************************reverse_tests******************************************/
/**********************************************************************************************
@brief- This function tests the reverse features

Tests:
invalid pointers
checks odd reverses
checks even reverses
checks characters

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e reverse_tests()
{
    return TEST_PASS;    
}

/*********************************************************************************************/
/*****************************************atoi_tests******************************************/
/**********************************************************************************************
@brief- This function tests the atoi function

Tests:
invalid pointers
zero integers
max sized integers

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e atoi_tests()
{
    return TEST_PASS;    
}

/*********************************************************************************************/
/*****************************************itoa_tests******************************************/
/**********************************************************************************************
@brief- This function tests the itoa function

Tests:
invalid pointers
zero integers
max sized integers

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e itoa_tests()
{
    return TEST_PASS;    
}

/*********************************************************************************************/
/***********************************endianness_tests******************************************/
/**********************************************************************************************
@brief- This function tests the endianness function

Tests:
invalid pointers
valid conversions
conversions back

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e endianness_tests()
{
    return TEST_PASS;    
}

/*********************************************************************************************/
/*************************************circbuf_tests*******************************************/
/**********************************************************************************************
@brief- This function tests the circular buffer function

Tests: 
checks to make sure buffer is on the heap
invalid pointers
non-initialized buffers
Add and remove features
buffer full feature
Wrap-add
Wrap remove
Overfill
Over Empty

@param - void
@return - test_type: passing of failing
**********************************************************************************************/

test_type_e circbuf_tests()
{
    return TEST_PASS;    
}

/*********************************************************************************************/
/*************************************circbuf_tests*******************************************/
/*********************************************************************************************/

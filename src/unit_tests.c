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

#include <stdio.h>
#include <stdint.h>
#include "platform.h"
#include "project1.h"
#include "memory.h"
#include "conversion.h"
#include "debug.h"

#include "project2.h"
#include "uart.h"
#include "circbuf.h"
#include "gpio.h"

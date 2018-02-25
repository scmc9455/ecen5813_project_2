/*********************************************************************************************
@file - main.c

@brief - main program header file

This program only calls functions from project1
This also include all the necessary libraries and headers that are used in each of the files

@author - Scott McElroy

@date - February 9, 2018

Created for ECEN5813
**********************************************************************************************/

#include "project1.h"

int main(void)
{
    uint32_t run = 1;
    	
    /* Call program only calls functions from project1() using a compile time switch */
    project1();
	
    while(run)
    {	
        /* infinite loop in code */
    }
}

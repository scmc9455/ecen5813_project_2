/*********************************************************************************************
@file - main.c

@brief - main program header file

This program only calls functions from project2
This also include all the necessary libraries and headers that are used in each of the files

@author - Scott McElroy

@date - February 25, 2018

Created for ECEN5813
**********************************************************************************************/

//#include "project1.h"
#include "project2.h"

#include "MKL25Z4.h"

int main(void)
{
    uint32_t run=1;
    #ifdef PROJECT1
        project1();
    #endif
    
    #ifdef PROJECT2
        program2();
    #endif

    while(run){};    
}

/*********************************************************************************************/
/**************************************End of File********************************************/
/*********************************************************************************************/

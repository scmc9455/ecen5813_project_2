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

int main(void)
{
    #ifdef PROJECT1	
        project1();
    #endif
    
    #ifdef PROJECT2	
        project2();
    #endif
}

/*********************************************************************************************/
/**************************************End of File********************************************/
/*********************************************************************************************/

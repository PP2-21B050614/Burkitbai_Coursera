/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Header file for statistical analysis operations.
 *
 * Declares functions for analyzing an array of unsigned char data,
 * including minimum, maximum, mean, median, sorting, and printing functions.
 *
 * @author Burkitbai Nurai
 * @date October 24, 2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

void print_statistics(unsigned char * array, unsigned int length);
void print_array(unsigned char * array, unsigned int length);
unsigned char find_median(unsigned char * array, unsigned int length);
unsigned char find_mean(unsigned char * array, unsigned int length);
unsigned char find_maximum(unsigned char * array, unsigned int length);
unsigned char find_minimum(unsigned char * array, unsigned int length);
void sort_array(unsigned char * array, unsigned int length);

#endif /* __STATS_H__ */
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
 * @file stats.c 
 * @brief Implementation file for statistical analysis operations.
 *
 * Implements functions to calculate minimum, maximum, mean, median,
 * sort array in descending order, and display results.
 *
 * @author Burkitbai Nurai
 * @date October 24, 2026
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,    8, 194,    2,    6,
                             114,  88,  45,  76, 123,  87,  25,   23,
                             200, 122, 150,  90,  92,  87, 177,  244,
                             201,   6,  12,  60,   8,   2,   5,   67,
                               7,  87, 250, 230,  99,   3, 100,   90};

  printf("--- Initial Array ---\n");
  print_array(test, SIZE);

  print_statistics(test, SIZE);

  printf("\n--- Array After Sorting (Descending) ---\n");
  print_array(test, SIZE);
}

void print_statistics(unsigned char * array, unsigned int length) {
    unsigned char min = find_minimum(array, length);
    unsigned char max = find_maximum(array, length);
    unsigned char mean = find_mean(array, length);
    unsigned char median = find_median(array, length);

    printf("\n--- Statistical Analysis Report ---\n");
    printf("Maximum Value: %u\n", max);
    printf("Minimum Value: %u\n", min);
    printf("Mean Value:    %u\n", mean);
    printf("Median Value:  %u\n", median);
}

void print_array(unsigned char * array, unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        printf("%3u ", array[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}

unsigned char find_median(unsigned char * array, unsigned int length) {
    sort_array(array, length);
    
    if (length % 2 == 0) {
        unsigned int mid = length / 2;
        return (array[mid - 1] + array[mid]) / 2;
    } else {
        return array[length / 2];
    }
}

unsigned char find_mean(unsigned char * array, unsigned int length) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (unsigned char)(sum / length);
}

unsigned char find_maximum(unsigned char * array, unsigned int length) {
    unsigned char max = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

unsigned char find_minimum(unsigned char * array, unsigned int length) {
    unsigned char min = array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

void sort_array(unsigned char * array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        for (unsigned int j = 0; j < length - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                unsigned char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
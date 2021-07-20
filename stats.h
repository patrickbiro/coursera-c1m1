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
* @file <Add File Name>
* @brief <Add Brief Description Here >
*
* <Add Extended Description Here>
*
* @author <Add FirsName LastName>
* @date <Add date >
*
*/
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */
/*----------------------------------------*/
/* Prints an array to the screenr*/
/*----------------------------------------*/
void print_array(unsigned char * array, unsigned int array_length) {
  printf("start of array print \n");
  for( int i = 0 ; i < array_length; i++ ) {
    printf("%d \n", array[i]);
  }
  printf("end of array print \n");
}

/*----------------------------------------*/
/* Sorts an array from largest to smallest value*/
/*----------------------------------------*/
void sort_array(unsigned char * array, unsigned int array_length) {
/*For each array item, we check if items further in the array are larger. The larger number between i and the end of the array is moved to position i.
Itereatively, the array is sorted by increasing values*/
  for( int i = 0 ; i < array_length; i++ ) {    //First loop goes through the array
    for( int j = 0 ; j < array_length; j++ ){   //Second loop check on the reamining array items if they are small than current element
      if (array[i]>array[j]) {  //If an item further in the array is small than the i item, it is permuted so it is in growing order
        int temp;
        temp = array[i];
        array[i]=array[j];
        array[j]=temp;
      }
    }
  }
}

/*----------------------------------------*/
/* Find median value of an array. Return a integer so it's rounded down to the nearest whole number*/
/*----------------------------------------*/
unsigned int find_median(unsigned char * array, unsigned int array_length) {
  unsigned int median_value;
  //To avoid alterating the inital array, we copy it in a new array
  unsigned char array_copy[array_length];
  for( int i = 0 ; i < array_length; i++ ) {
    array_copy[i]=array[i];
  }
  //Sorts the copied array to allow the median calculation
  sort_array(array_copy,array_length);
  //Check if the number of elements are odd or not.
  //If odd, it will make the average between the n/2-1 and n/2 elements. Otherwise median is the n/2 (because it will round down the result of odd number division by 2).
  if (array_length % 2 == 0) {
    median_value = (array_copy[array_length/2-1] + array_copy[array_length/2])/2;
  } else {
    median_value =  array_copy[array_length/2];
  }
  return median_value;
}

/*----------------------------------------*/
/* Find mean value of an array as an integer*/
/*----------------------------------------*/
unsigned int find_mean(unsigned char * array, unsigned int array_length){
  unsigned int array_sum = 0;
  unsigned int array_mean;
  for( int i = 0 ; i < array_length; i++ ) {
    array_sum+=array[i];
  }
  array_mean = array_sum / array_length;
  return array_mean;
}

/*----------------------------------------*/
/* Find the maximum value within an array of numbers*/
/*----------------------------------------*/
unsigned int find_maximum(unsigned char * array, unsigned int array_length) {
  unsigned int array_max = 0;
  for( int i = 0 ; i < array_length; i++ ) {
    if (array_max<array[i]) {
      array_max=array[i];
    }
  }
  return array_max;
}

/*----------------------------------------*/
/* Find the minimum value within an array of numbers*/
/*----------------------------------------*/
unsigned int find_minimum(unsigned char * array, unsigned int array_length) {
  unsigned int array_min = array[1];
  for( int i = 0 ; i < array_length; i++ ) {
    if (array_min>array[i]) {
      array_min=array[i];
    }
  }
  return array_min;
}

/*----------------------------------------*/
/* Prints the statistics of an array including minimum, maximum, mean, and median. */
/*----------------------------------------*/

void print_statistics(unsigned char * array, unsigned int array_length) {
  unsigned int array_min = find_minimum(array, array_length);
  unsigned int array_max = find_maximum(array, array_length);
  unsigned int array_median = find_median(array, array_length);
  unsigned int array_mean = find_mean(array, array_length);

  printf("Array minimum value is: %d \n", array_min);
  printf("Array maximum value is: %d \n", array_max);
  printf("Array median value is: %d \n", array_median);
  printf("Array mean value is: %d \n", array_mean);
}

#endif /* __STATS_H__ */

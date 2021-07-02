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

void print_statistics() {

}

void print_array() {
  /*printf("start \n");
  for( int i = 0 ; i < test_array_length; i++ ) {
    printf("%d \n", test[i]);
  }*/
}

void find_median() {

}

void find_mean() {

}

void find_maximum() {

}

void find_minimum() {

}

void sort_array(unsigned char * array, unsigned int array_size) {
/*For each array item, we check if items further in the array are larger. The larger number between i and the end of the array is moved to position i.
At the end, the array is sorted by increasing values*/
  for( int i = 0 ; i < array_size; i++ ) {    //First loop goes through the array
    for( int j = 0 ; j < array_size; j++ ){   //Second loop check on the reamining array items if they are small than current element
      if (array[i]>array[j]) {  //If an item further in the array is small than the i item, it is permuted so it is in growing order
        int temp;
        temp = array[i];
        array[i]=array[j];
        array[j]=temp;
      }
    }

  }

  /*printf("start \n");
  for( int i = 0 ; i < array_size; i++ ) {
    printf("%d \n", array[i]);
  }*/
}


#endif /* __STATS_H__ */

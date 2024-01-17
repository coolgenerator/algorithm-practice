#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "sort.h"
#include "test.h"


void printArray(int array[], size_t count){
    std::cout << "[ ";
    for(size_t i=0;i<count;++i){
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
}

int main(){
    int array[] {5,9,2,4,3,0,1};
    size_t count = sizeof(array)/sizeof(array[0]);
    printArray(array, count);
    // test merge sort
    Sort<int>::mergeSort(array, 0, count-1);
    printArray(array, count);

    int array1[] {5,9,2,4,3,0,1};
    size_t count1 = sizeof(array1)/sizeof(array1[0]);
    printArray(array1, count1);
    // test selection
    testEquals(4, Sort<int>::selection(array1, count1, 4), "Test selection");
    
    // test quick sort
    Sort<int>::quickSort(array1, count1);
    printArray(array1, count1);

    return 0;
}
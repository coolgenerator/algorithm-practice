#include <cstddef>
#include <stdint.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <stdexcept>
#ifndef SORT_H
#define SORT_H

#define MASK 1

template<typename T>
class Sort {
public:
    static void selectionSort(T array[], size_t count){
        for(int i = 0; i < count - 1; ++i){
            swap(array, i, getMin(array, i, count - 1));
        }
    }

    static void RadixSort(uint32_t array[], size_t count){
        int idx{0};
        std::vector<uint32_t> b0;
        std::vector<uint32_t> b1;
        for(size_t i=0; i<count; ++i)
            ((array[i] & MASK) == 0 ? b0 : b1).push_back(array[i]);
        bucketSort(b0, b1);
        for(size_t i=0; i<b0.size(); ++i)
            array[idx++] = b0[i];
        for(size_t i=0; i<b1.size(); ++i)
            array[idx++] = b1[i];
    }

    static void mergeSort(T array[], size_t start, size_t end){
        if (start >= end) return;
        size_t mid = start + (end - start) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }

    static void quickSort(T array[], size_t size){
        quick(array, 0, size-1);
    } 
    
    /**
    The selection algorithm is an algorithm for finding the kth smallest value in a collection of ordered values
    */
    static T selection(const T array[], size_t size, size_t position){
        if(position > size) throw std::runtime_error("selection index out of range");
        T* temp = new T[size];
        for(size_t i = 0; i < size; ++i) temp[i] = array[i];
        size_t start = 0;
        size_t end = size - 1;
        size_t pivot = partition(temp, start, end);
        while(pivot != position){
            if(position < pivot) 
                end = pivot - 1;
            else 
                start = pivot + 1;
            pivot = partition(temp, start, end);
        }
        T result = temp[position];
        delete[] temp;
        return result;
    } 
    
    
private:
    size_t getMax(T array[], size_t start, size_t end){
        T max{start};
        for(int i = start; i <= end; ++i)
            if(array[max] < array[i]) max = i;
        return max;
    }

    size_t getMin(T array[], size_t start, size_t end){
        T max{start};
        for(int i = start; i <= end; ++i)
            if(array[max] > array[i]) max = i;
        return max;
    }

    static void swap(T array[], size_t a, size_t b){
        T tmp{array[a]};
        array[a] = array[b];
        array[b] = tmp;
    }

    static void bucketSort(std::vector<uint32_t>& b0, std::vector<uint32_t>& b1){
        std::vector<uint32_t> t0;
        std::vector<uint32_t> t1;
        for(size_t i = 1; i< sizeof(uint32_t) << 3; ++i){
            t0.clear();
            t1.clear();
            for(size_t j=0; j<b0.size(); ++j){
                (b0[j] & (MASK << i) == 0 ? t0 : t1).push_back(b0[j]);
                std::cout << b0[j] << " ";
            }
            for(size_t j=0; j<b1.size(); ++j){
                (b1[j] & (MASK << i) == 0 ? t0 : t1).push_back(b1[j]);
                std::cout << b1[j] << " ";
            }
            copyVector(t0, b0);
            copyVector(t1, b1);
            std::cout << std::endl;
        }
    }
    
    static void copyVector(std::vector<uint32_t>& src, std::vector<uint32_t>& dst){
        dst.clear();
        for(uint32_t i : src)
            dst.push_back(i);
    }
    
    // put pivot value into correct position
    static size_t partition(T array[], size_t start, size_t end){
        T pval = array[end];
        size_t pivot = start;
        for(size_t ptr = start; ptr < end; ++ptr){
            if(array[ptr] < pval){
                if(pivot != ptr)
                    swap(array, ptr, pivot);
                ++pivot;
            }
        }
        swap(array, end, pivot);
        return pivot;
    }
    
    // call a recursive function
    static void quick(T array[], size_t start, size_t end){
        if (start >= end) return;
        int pivot = array[start];
        int count = 0;
        for (size_t i = start + 1; i <= end; i++) {
            if (array[i] <= pivot)
                ++count;
        }
        int pivotIdx = start + count;
        // put the first value into correct position
        swap(array, pivotIdx, start);
        
        // partition two sequences
        size_t left = start;
        size_t right = end;
        while (left < pivotIdx && right > pivotIdx) {
            while (array[left] <= pivot) ++right;
            while (array[right] > pivot) --left;
            swap(array, left++, right--);
        }
        quick(array, start, pivotIdx - 1);
        quick(array, pivotIdx + 1, end);
    }
    
    
    static void merge(T array[], int left, int mid, int right){
        size_t leftSize = mid - left + 1;
        size_t rightSize = right - mid;
        
        T* lArr = new T[leftSize];
        T* rArr = new T[rightSize];
        for (size_t i = 0; i < leftSize; ++i)
            lArr[i] = array[left + i];
        for (size_t j = 0; j < rightSize; ++j)
            rArr[j] = array[mid + 1 + j];
    
        size_t i = 0;     // index of left array
        size_t j = 0;     // index of right array
        size_t merged = left;  // index of merged array
        
        // compare the values in two arrays and put them into correct position
        while (i < leftSize && j < rightSize) {
            if (lArr[i] <= rArr[j]) {
                array[merged] = lArr[i];
                ++i;
            } else {
                array[merged] = rArr[j];
                ++j;
            }
            ++merged;
        }
        while (i < leftSize) {
            array[merged] = lArr[i];
            ++i;
            ++merged;
        }
        while (j < rightSize) {
            array[merged] = rArr[j];
            ++j;
            ++merged;
        }
        delete[] lArr;
        delete[] rArr;
    }
};

#endif
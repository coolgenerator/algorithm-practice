#include <functional>
#include <cstddef>
#include <iostream>
#include "heap.h"

#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

#define DEFAULT_SIZE 128
#define SCALING_FACTOR 2


template<typename T>
class ArrayHeap : public Heap<T>
{ 
public:
    ArrayHeap(std::function<bool(const T&, const T&)> comparator) 
        : ArrayHeap(comparator, DEFAULT_SIZE) { }

    ArrayHeap(std::function<bool(const T&, const T&)> comparator, size_t initialSize) 
        : store{new T[initialSize]}, count{0}, currentSize{initialSize}, comparator{comparator} { }

    ArrayHeap(std::function<bool(const T&, const T&)> comparator, const T srcArray[], size_t size){ 
        for (size_t i = 0; i < size; ++i) {
            store[i] = srcArray[i];
        }
        heapify(store, size);
    }
    
    ~ArrayHeap() { delete[] store; }

    void add(const T& item){
        ++count;
        if(count > currentSize) resize();
        store[count] = item;
        upHeap(count);
    }

    void remove(){
        if (empty()){
            return;
        }
        store[0] = store[--count];
        downHeap(0);
    }

    T get() const{
        return store[1];
    }

    bool empty() const{
        return count == 0;
    }

    void clear(){
        count = 0;
    }

private:
    T*  store;
    size_t currentSize;
    size_t count;
    std::function<bool(const T&, const T&)> comparator;

    void downHeap(const size_t parent){
        size_t lc = parent << 1;
        size_t rc = lc + 1;
        T tmp;
        if(lc < count && comparator(store[parent], store[lc])){
            tmp = store[parent];
            store[parent] = store[lc];
            store[lc] = tmp;
        }
        if(rc < count && comparator(store[parent], store[rc])){
            tmp = store[parent];
            store[parent] = store[rc];
            store[rc] = tmp;
        }
    }

    void upHeap(const size_t child) {
        size_t parent = child >> 1;
        if(parent == 0) return;
        T tmp;
        if (comparator(store[parent], store[child])) {
            tmp = store[parent];
            store[parent] = store[child];
            store[child] = tmp;
            upHeap(child);
        }
    }

    void heapify(T array[], size_t size){
        for (size_t i = size / 2; i >= 0; --i)
            downHeap(i);
    }
    
    void resize(){
        currentSize *= SCALING_FACTOR;
        T* newStore = new T[currentSize];
        for (size_t i = 0; i < count; ++i) {
            newStore[i] = store[i];
        }
        delete[] store;
        store = newStore;
    }
};


#endif /* ARRAY_HEAP_H */

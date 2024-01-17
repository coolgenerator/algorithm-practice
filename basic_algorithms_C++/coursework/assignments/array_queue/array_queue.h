#include "queue.h"
#include <stdexcept>
#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#define DEFAULT_SIZE 128
#define SCALLING_FACT 2

template<typename T>
class ArrayQueue : public Queue<T>{
    public:
        ArrayQueue() : ArrayQueue(DEFAULT_SIZE) { }
        ArrayQueue(const size_t initialSize): storeSize{initialSize}, store{new T[initialSize]{}}, head{-1}, tail{-1} { }
        ~ArrayQueue() {delete[] store;}
    
        /** Adds an item to the back of the queue */
        void enqueue(const T& item){
            // if the queue is full, resize the queue and continue
            if((tail + 1) % storeSize == head){
                resize();
            }
            if(head == -1) head =0;
            tail = (tail+1)%storeSize;
            store[tail] = item; 
        }

        /** Remove but does not return the item in the front of the queue*/
        void dequeue(){
            if(empty()) throw std::runtime_error("dequeue on empty queue");
            head = (head+1)%storeSize;
            // if head is greater than tail, set array to empty
            if(head > tail){
                clear();
            }
        }

        /** returns but does not remove the item at the front of the queue */
        T front() const{
            if(empty()) throw std::runtime_error("front on empty queue");
            return store[head];
        }

        /** Returns true if the queue is empty or false otherwise */
        bool empty() const{
            return head == -1;
        }

        /** Empty the queue */
        void clear(){
            head = -1;
            tail = -1;
        }
    private:
        T* store;
        size_t storeSize;
        int head;
        int tail;
        void resize(){
            size_t newStoreSize = storeSize * SCALLING_FACT;
            T* newStore{new T[newStoreSize]};
            for(size_t i=0;i<storeSize;++i){
                newStore[i] = store[(head+i)%storeSize];
            }
            delete[] store;
            store = newStore;
            head = 0;
            tail = storeSize-1;
            storeSize = newStoreSize;
        }
};

#endif

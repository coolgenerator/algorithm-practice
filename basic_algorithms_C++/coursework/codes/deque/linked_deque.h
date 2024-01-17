#include "deque.h"
#include <stdexcept>
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

template<typename T>
struct Node{
    T item;
    Node<T>* next;
};
template<typename T>
class LinkedDeque : public Deque<T> {
    public:
        LinkedDeque() : head{nullptr}, tail{nullptr} { }
        ~LinkedDeque() { 
            clear();
        }
        /** Adds an item to the front of the Deque
         *  Param: an item of type T
        */
        void pushFront(const T& item){
            head = new Node<T>{item, head};
            if(tail == nullptr) tail = head;
        }

        /** Adds an item to the back of the Deque
         *  Param: an item of type T
        */
        void pushBack(const T& item){
            // Node<T>* tmp(tail);
            if(empty()){
                pushFront(item);
            } else {
                tail->next = new Node<T>{item, nullptr};
                tail = tail->next;
            }
        }

        /** Removes and returns the item at the front of the Deque
         *  Returns item of type T
        */
        T popFront(){
            if(empty()) throw std::runtime_error("popFront on empty deque");
            T item{head->item};
            Node<T>* tmp{head};
            head = head->next;
            delete tmp;            
            if(empty()) tail = nullptr;
            return item;
        }

        /** Removes and returns the item at the back of the Deque
         *  Returns item of type T
        */
        T popBack(){
            T item;
            return item;
        }

        /** Returns the item at the front of the Deque
         *  Returns item of type T
        */
        T front() const{
            if(empty()) throw std::runtime_error("front on empty deque");
            T item;
            return item;
        }

        /** Returns the item at the back of the Deque
         *  Returns item of type T
        */
        T back() const{
            T item;
            return item;
        }

        /** Removes all entries in the Deque*/
        void clear(){
            Node<T>* it{head};
            while(!empty()){
                head = head->next;
                delete it;
                it = head;
            }
            tail = nullptr;
        }

        /** Returns true if the Deque is empty or false otherwise*/
        bool empty() const {
            return head == nullptr;
        }
    private:
        Node<T>* head;
        Node<T>* tail;
};

#endif
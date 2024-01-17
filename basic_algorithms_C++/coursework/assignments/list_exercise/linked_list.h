#include <stdexcept>

#include "list.h"

#ifndef LINKED_LIST
#define LINKED_LIST

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T>
class LinkedList : public List<T>{
public:
    /** constructor */
    LinkedList() : head{nullptr}, tail{nullptr}, count{0} {}
    /** destructor */
    ~LinkedList() { clear(); }

    /** Add an item to the list 
     * Param1: the item to add */
    void add(const T& item){
        Node<T>* newNode{new Node<T>{item, nullptr}};
        if(empty()) {
            head = tail = newNode;
        }else{
        tail->next = newNode;
        tail = tail->next;
        }
        ++count;
    }

    /** Add an item to the list at a certain position
     * Param1: the item to add
     * Param2: the position (1 <= p <= n + 1) in which to insert the item 
     * Throws: std::out_of_range error if param1 is out of range */ 
    void add(const T& item, size_t pos){
        if(pos < 1 || pos > count + 1) throw std::runtime_error("Add position out of index");
        if(pos == count + 1) add(item);
        Node<T>* newNode{new Node<T>{item, nullptr}};
        Node<T>* ptr = head;
        for (size_t i = 1; i < pos - 1; i++){
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        ++count;
    }
    
    /** Rempove and return an item at a certain position 
     * Param1: the poisition of the item to remove and return (1 <= p <= n) */
    T remove(size_t pos){
        if(pos < 1 || pos > count) throw std::runtime_error("Remove position out of index");
        Node<T>* deleteNode;
        if (pos == 1){
            deleteNode = head;
            head = head->next;
        } else {
            Node<T>* ptr = head;
            for (size_t i = 1; i < pos; i++){
                ptr = ptr->next;
            }
            deleteNode = ptr->next;
            ptr->next = deleteNode->next;
        }
        T data = deleteNode->data;
        delete deleteNode;
        --count;
        return data;
    }

    /** Replace an item in the list at a certain position
     * Param1: The item to add to the list
     * Param2: The position of the item that gets replaced (1 <= p <= n)
     * Throws: std::out_of_range error if param1 is out of range */ 
    void replace(const T& item, size_t pos){
        if(pos < 1 || pos > count) throw std::runtime_error("Replace position out of index");
        Node<T>* ptr = head;
        for (size_t i = 1; i < pos; i++)
            ptr = ptr->next;
        ptr->data = item;
    }

    /** Returns the item at a certain position but does not remove it
     * Param1: the position of the item to be returned (1 <= p <= n) 
     * Return: the item at the position
     * Throws: std::out_of_range error if param1 is out of range */ 
    T at(size_t pos) const{
        if(pos < 1 || pos > count) throw std::runtime_error("At position out of index");
        Node<T>* ptr = head;
        for (size_t i = 1; i < pos; i++)
            ptr = ptr->next;
        return ptr->data;
    }

    /** Check for containment of an item
     * Param1: the search term
     * Return: true if the list contains the item or false otherwise */
    bool contains(const T& item) const{
        Node<T>* ptr = head;
        while (ptr != nullptr){
            if (ptr->data == item)
                return true;
            ptr = ptr->next;
        }
        return false;
    }

    /** Returns the quantity of items stored in the list */
    size_t size() const{
        return count;
    }

    /** Test of the list is empty  
     * Return true if the list is empty or false otherwise */
    bool empty() const{
        return count == 0;
    }

    /** Clear the list */
    void clear(){
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        count = 0;
    }
private:
    Node<T>* head;
    Node<T>* tail;
    size_t count;
};

#endif /* LINKED_LIST */

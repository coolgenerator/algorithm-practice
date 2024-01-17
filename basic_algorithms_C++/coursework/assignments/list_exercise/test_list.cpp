// who:  Jason Wang
// what: Test Linked List
// why:  Topic 2: List ADT
// when: 3/28/2023

#include <iostream>

#include "test.h"
#include "list.h"
#include "linked_list.h"

int main(int argc, char const *argv[])
{
    List<int>* list = new LinkedList<int>();
    // Test add() function
    list->add(1);
    list->add(2);
    list->add(3);
    equals(static_cast<size_t>(3), list->size(), "size() returns the correct size of the list");
    equals(1, list->at(1), "at(1) returns the correct value");
    equals(3, list->at(3), "at(3) returns the correct value");
    
    // Test add() function with index
    list->add(4, 2);
    equals(4, list->at(2), "add(4, 2) adds the element at the correct index");
    equals(static_cast<size_t>(4), list->size(), "size() returns the correct size of the list after add(4, 2)");

    // Test remove() function
    int removed = list->remove(3);
    equals(3, removed, "remove(3) returns the correct value");
    equals(static_cast<size_t>(3), list->size(), "size() returns the correct size of the list after remove(3)");
    equals(false, list->contains(3), "contains(3) returns false after remove(3)");
    
    // Test replace() function
    list->replace(5, 2);
    equals(5, list->at(2), "replace(5, 2) replaces the correct value");
    
    // Test clear() function
    list->clear();
    equals(true, list->empty(), "empty() returns true after clear()");
    return 0;
}

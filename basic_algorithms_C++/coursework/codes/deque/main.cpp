#include "deque.h"
#include "linked_deque.h"
#include <iostream>

template<typename T>
void testEqual(const T& expected, const T& actual, const std::string& testname){
    if(expected == actual) std::cout << "Success: on " << testname << std::endl;
    else std::cout << "ERROR: Failure on " << testname << std::endl;
}

void testEmpty(const LinkedDeque<int>& ld){
    if(ld.empty()) std::cout << "Success: on empty" << std::endl;
    else std::cout << "ERROR: Empty failed" << std::endl;
}

void testNotEmpty(const LinkedDeque<int>& ld){
    if(!ld.empty()) std::cout << "Success: not empty" << std::endl;
    else std::cout << "ERROR: Empty failed" << std::endl;
}

int main(){
    LinkedDeque<int> ld;
    testEqual<bool>(ld.empty(), true, "equalEmpty");
    testEmpty(ld);
    ld.pushBack(10);
    testEqual<bool>(ld.empty(), 10, "pushback");
    testNotEmpty(ld);
    ld.pushBack(20);
    std::cout << ld.back() << " " << ld.front() << std::endl;
    ld.clear();
    testEmpty(ld);
    testEqual<bool>(ld.empty(), true, "equalEmpty");
    return 0;
}
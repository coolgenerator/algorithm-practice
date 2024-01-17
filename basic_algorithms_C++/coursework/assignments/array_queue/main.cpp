#include <iostream>
#include "array_queue.h"
template<typename T>
void testEqual(const T& expected, const T& actual, const std::string& testname){
    if(expected == actual) std::cout << "Success: on " << testname << std::endl;
    else std::cout << "ERROR: Failure on " << testname << std::endl;
}

void testEmpty(const ArrayQueue<int>& q){
    if(q.empty()) std::cout << "Success: on empty" << std::endl;
    else std::cout << "ERROR: Empty failed" << std::endl;
}

void testNotEmpty(const ArrayQueue<int>& q){
    if(!q.empty()) std::cout << "Success: not empty" << std::endl;
    else std::cout << "ERROR: Empty failed" << std::endl;
}
int main(){
    ArrayQueue<int> q{10};
    testEqual<bool>(q.empty(), true, "Equal Empty");
    for(size_t i=0;i<100;++i){
        q.enqueue(i);
    }
    testNotEmpty(q);
    for(size_t i=0;i<100;++i){
        std::cout << q.front() << " ";
        q.dequeue();    
    }
    std::cout << std::endl;
    
    testEmpty(q);
    return 0;
}

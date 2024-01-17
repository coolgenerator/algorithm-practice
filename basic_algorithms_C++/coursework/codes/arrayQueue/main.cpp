#include <iostream>
#include "array_queue.h"

int main(){
    ArrayQueue<int> q;
    for(size_t i=0;i<100;++i){
        q.enqueue(i);
    }
    for(size_t i=0;i<100;++i){
        std::cout << q.front() << " ";
        q.dequeue();    
    }
    std::cout << std::endl;
    if(q.empty()) std::cout << "q is an empty queue" << std::endl;
    else std::cout << "q is not empty" << std::endl;
    return 0;
}
#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    msac::Stack<int> stack;
    for(size_t i = 0; i < 100; ++i)
        stack.push(i);
    std::cout << stack.getString() << std::endl;
    while(!stack.empty()){
        cout << stack.peek() << " ";
        stack.pop();
    }
    return 0;
}

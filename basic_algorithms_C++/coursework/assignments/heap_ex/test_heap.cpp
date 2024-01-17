#include "heap.h"
#include "array_heap.h"
#include "test.h"

int main(int argc, char const *argv[])
{
    ArrayHeap<int> intHeap([](const int& a, const int& b){ return a > b; });

    //test add
    intHeap.add(3);
    equals(true, intHeap.get() == 3, "Heap add 3");
    intHeap.add(2);
    equals(true, intHeap.get() == 2, "Heap add 2");
    intHeap.add(1);
    equals(true, intHeap.get() == 1, "Heap add 1");
    intHeap.add(4);
    equals(true, intHeap.get() == 1, "Heap add 4");
    
    // test remove
    intHeap.remove();
    equals(true, intHeap.get() == 2, "Heap remove test");

    // test clear
    intHeap.clear();
    equals(true, intHeap.empty(), "Heap clear test");
    
    // test heapify
    int arr[] = {3, 2, 1, 4, 5};
    int size = sizeof(arr) / sizeof(int);

    ArrayHeap<int> heap([](const int& a, const int& b){ return a > b; }, arr, size);
    equals(true, heap.get() == 1, "Heapify test");
    std::cout << "Heap contents: ";
    while(!heap.empty()) {
        std::cout << heap.get() << " ";
        heap.remove();
    }
    std::cout << std::endl;

    return 0;
}


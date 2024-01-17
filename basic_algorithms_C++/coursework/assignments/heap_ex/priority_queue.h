#include <functional>
#include "array_heap.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template<typename T>
class PriorityQueue
{
public:
    PriorityQueue(std::function<bool(const T&, const T&)> comparator)
       : queue{ArrayHeap<T>(comparator)} { }

    void enqueue(const T& item) { queue.add(item); }
    void dequeue() { queue.remove(); }
    T front() { return queue.get(); }
    bool empty() { return queue.empty(); }
    void clear() { queue.clear(); }
private:
    ArrayHeap<T> queue;
};

#endif /* PRIORITY_QUEUE_H */

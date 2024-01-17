#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
struct Queue
{
    virtual ~Queue() { }
    
    /** Adds an item to the back of the queue */
    virtual void enqueue(const T&) = 0;

    /** Remove but does not return the item in the front of the queue*/
    virtual void dequeue() = 0;

    /** returns but does not remove the item at the front of the queue */
    virtual T front() const = 0;

    /** Returns true if the queue is empty or false otherwise */
    virtual bool empty() const = 0;

    /** Empty the queue */
    virtual void clear() = 0;
};

#endif /* QUEUE_H */
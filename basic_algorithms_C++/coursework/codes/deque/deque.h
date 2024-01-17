#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
struct Deque{
    ~Deque() { }
    /** Adds an item to the front of the Deque
     *  Param: an item of type T
    */
    virtual void pushFront(const T&) = 0;

    /** Adds an item to the back of the Deque
     *  Param: an item of type T
    */
    virtual void pushBack(const T&) = 0;

    /** Removes and returns the item at the front of the Deque
     *  Returns item of type T
    */
    virtual T popFront() = 0;

    /** Removes and returns the item at the back of the Deque
     *  Returns item of type T
    */
    virtual T popBack() = 0;

    /** Returns the item at the front of the Deque
     *  Returns item of type T
    */
    virtual T front() const = 0;

    /** Returns the item at the back of the Deque
     *  Returns item of type T
    */
    virtual T back() const = 0;

    /** Removes all entries in the Deque*/
    virtual void clear() = 0;

    /** Returns true if the Deque is empty or false otherwise*/
    virtual bool empty() const = 0;
};

#endif
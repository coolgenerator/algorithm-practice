#include <cstddef>
#include <functional>
#include <stdexcept>

#include "set.h"

#ifndef HASH_SET_H
#define HASH_SET_H
#define DEFAULT_SIZE 128
#define MAX_PROBE_ATTAMPTS 15

enum Prober {
    LINEAR,
    QUADRATIC
};


template<typename T>
class HashSet : public Set<T> {
    using HASHER = std::function<size_t(const T&)>;
public:
    HashSet(HASHER hashcode, Prober prober) : HashSet(hashcode, prober, DEFAULT_SIZE) { }
    HashSet(HASHER hashcode, Prober prober, size_t initialSize) : hashcode{hashcode}, proberNum{prober}, currentSize{initialSize}, count{0}, store{new T[initialSize]} {
        probe = (prober == LINEAR) ? linearProbe : quadraticProbe;
    }
    /** adds an item to the set. 
     *  throws an runtime error if the item already a member
    */
    void add(const T& item){
        if (contains(item)) {
            throw std::runtime_error("Item already exists in the set.");
        }
        if (count == currentSize) {
            resize(currentSize * 2);
        }
        int index = (this->*prober)(hashcode(item));
        store[index] = item;
        count++;
    }

    /** removes the item from the set
     *  throws a runtime error if the item is not a member
    */
    T remove(const T& item){
        if (!contains(item)) {
            throw std::runtime_error("Item is not a member of the set.");
        }
        int index = (this->*prober)(hashcode(item));
        T result = store[index];
        store[index] = T{};
        count--;
        if (currentSize > DEFAULT_SIZE && count < currentSize / 4) {
            resize(currentSize / 2);
        }
        return result;
    }

    /** returns true if the set is empty or false otherwise */
    bool empty() const{
        return currentSize == 0;
    }

    /** returns true if the item is a member or false otherwise */
    bool contains(const T& item) const{
        int index = (this->*prober)(hashcode(item));
        return store[index] == item;
    }

    /** returns the number of members in the set */
    size_t size() const{
        return count;
    }

private:
    T* store;
    size_t currentSize;
    size_t count;
    HASHER hashcode;
    Prober proberNum;
    std::function<size_t(size_t)> probe;
    int prober(size_t hashcode){
        switch(proberNum){
            case LINEAR:
                return linearProbe(hashcode);
            case QUADRATIC:
                return quadraticProbe(hashcode);
        }
    }
    int linearProbe(size_t hashcode)
    {
        for(size_t i = 0; i < MAX_PROBE_ATTAMPTS; ++i){
            size_t index = (hashcode + i) % currentSize;
            if(store[index] == T{}) {
                return index;
            }
        }
        throw std::runtime_error("Linear probing failed");
    }

    int quadraticProbe(size_t hashcode)
    {
        for(size_t i = 0; i < MAX_PROBE_ATTAMPTS; ++i){
            size_t index = (hashcode + i*i) % currentSize;
            if(store[index] == T{}) {
                return index;
            }
        }
        throw std::runtime_error("Quadratic probing failed");
    }
    
    void resize(size_t newSize) {
        T* newStore = new T[newSize];
        for (size_t i = 0; i < currentSize; i++) {
            if (store[i] != T{}) {
                int idx = find(store[i], newSize);
                newStore[idx] = store[i];
            }
        }
        delete[] store;
        store = newStore;
        currentSize = newSize;
    }
    
    int find(const T& item) const {
        size_t hash = hashcode(item);
        size_t idx = hash % currentSize;
        size_t i = 0;
        while(store[idx] != item && store[idx] != T{}) {
            idx = prober(hash) % currentSize;
        }
        if (store[idx] == item) {
            return idx;
        }
        return -1;
    }

};

#endif /* HASH_SET_H */

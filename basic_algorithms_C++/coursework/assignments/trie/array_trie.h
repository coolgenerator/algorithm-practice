#include <string>
#include "trie_node.h"
#include "set.h"
#include <cstddef>

#ifndef ARRAY_TRIE_H
#define ARRAY_TRIE_H
#define DEFAULT_SIZE 128
#define SCALING_FACT 2

template<typename T>
class ArrayTrie : public Set<std::string> {
public:
    /**
     * Three arrays
     * dictionary array holds the index of first character
     * symbol array holds the rest of characters for each string
     * next array holds the index for next possible character
    */
    ArrayTrie() : symbolSize{DEFAULT_SIZE}, symbol{new char[DEFAULT_SIZE]{}}, next{new int[DEFAULT_SIZE]{-1}}, tail{0}, count{0} { }
    ~ArrayTrie() { 
        delete[] symbol;
        delete[] next;
    }

    // return true if sucessfully add the string, otherwise return false
    bool add(const T& ele) {
        std::string str = static_cast<std::string>(ele);
        if(contains(str)) return false;
        size_t idx;
        if(dictionary[lookup(str[0])] != -1){
            dictionary[lookup(str[0])] = tail;
            idx = tail;
        } else {
            idx = dictionary[lookup(str[0])];
        }
        for(size_t i = 1; i < str.length(); ++i){
            if(symbol[idx] != str[i] || symbol[idx] == '*'){
                //check next
                --idx;
                while(next[idx] != -1){
                    idx = next[idx];
                    if(symbol[idx] == str[i]) {
                        ++idx;
                        break;
                    }
                }
                if(symbol[idx] != str[i]){
                    next[idx] = tail;
                    idx = tail;
                    symbol[tail++] = str[i];
                    if(tail >= symbolSize) resize();
                }
            }
            ++idx;
        }
        symbol[tail++] = '*';
        ++count;
        return true;
    }

    // return true if it contains that string, otherwise return false
    bool contains(const T& ele) const {
        std::string str = static_cast<std::string>(ele);
        if(dictionary[lookup(str[0])] == -1) return false;
        size_t idx = dictionary[lookup(str[0])];
        for (size_t i = 1; i < str.length(); ++i){
            if (symbol[idx] == str[i])
                ++idx;
            if(next[idx] == -1) return false;
            while(next[idx] != -1){
                idx = next[idx];
                if(symbol[idx] == str[i]){
                    ++idx;
                    break;
                }
            }
            return false;
        }
        return symbol[idx] == '*';
    }

    // return true if successfully remove the string, otherwise return false
    bool remove(const T & ele) {
        std::string str = static_cast<std::string>(ele);
        if (!contains(str)) return false;
        size_t idx = dictionary[lookup(str[0])];
        for (size_t i = 1; i < str.length(); ++i)
        {
            if (symbol[idx] == str[i])
                ++idx;
            if(next[idx] == -1) return false;
            while(next[idx] != -1){
                idx = next[idx];
                if(symbol[idx] == str[i]){
                    ++idx;
                    break;
                }
            }
        }
        // to remove the asterisl of that specific word, but does not affect other words
        symbol[idx] = ' ';
        --count;
        return true;
    }

    // return true if it is empty, otherwise return false
    bool empty() const {
        return count == 0;
    }

    // return the amount of string
    size_t size() const {
        return count;
    }
private:
    int dictionary[64] {-1};
    char* symbol;
    int* next;
    size_t symbolSize;
    size_t tail;
    size_t count;
    void resize(){
        symbolSize *= SCALING_FACT;
        char* newSymbol = new char[symbolSize]{};
        int* newNext = new int[symbolSize]{};
        for (size_t i = 0; i < tail; ++i)
        {
            newSymbol[i] = symbol[i];
            newNext[i] = next[i];
        }
        delete[] symbol;
        delete[] next;
        symbol = newSymbol;
        next = newNext;
    }
    constexpr int lookup(const char c){
        if(c >= 'A' && c <= 'Z') return c - 'A';
        if(c >= 'a' && c <= 'z') return c - 'a' + 26;
        if(c >= '0' && c <= '9') return c - '0' + 52;
        if(c == '_') return 63;
        if(c == ' ') return 64;
        return -1;
    }
};

#endif

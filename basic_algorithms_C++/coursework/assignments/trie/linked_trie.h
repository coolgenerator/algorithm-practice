#include <string>
#include "trie_node.h"
#include "set.h"

#ifndef LINKED_TRIE_H
#define LINKED_TRIE_H
#define SCOPE 64


template<typename T>
class LinkedTrie : public Set<std::string> {
public:
    LinkedTrie() : head{new TrieNode<SCOPE>()}, count{0} {  }
    ~LinkedTrie(){
        deleteNode(head);
    }
    
    // return true if successfully add str to trie, return false otherwise
    bool add(const T& ele){
        std::string str = static_cast<std::string>(ele);
        if(contains(str)) return false;
        TrieNode<SCOPE>* ptr = head; 
        if(str.length() < 1) return false;
        for(int i = 0; i < str.length(); ++i){
            int c = lookup(str[i]);
            if(c != -1){
                ptr->next[c] = new TrieNode<SCOPE>();
                ptr = ptr->next[c];
            }
        }
        ptr->terminal = true;
        ++count;
        return true;
    }
    
    // return true if trie contains str, otherwise return false
    bool contains(const T& ele) const{
        std::string str = static_cast<std::string>(ele);
        TrieNode<SCOPE>* ptr = head;
        for(int i = 0; i < str.length(); ++i){
            int c = lookup(str[i]);
            if(c == -1 || ptr->next[c] == nullptr) return false;
            ptr = ptr->next[c];
        }
        if(ptr->terminal == true) return true;
        return false;
    }
    
    // return true if trie successfully remove str, return false otherwise
    bool remove(const T& ele){
        std::string str = static_cast<std::string>(ele);
        TrieNode<SCOPE>* ptr = head;
        if(!contains(str)) return false;
        for(int i = 0; i < str.length(); ++i){
            int c = lookup(str[i]);
            if(c == -1 || ptr->next[c] == nullptr) return false;
            ptr = ptr->next[c];
        }
        ptr->terminal = false;
        --count;
        if(count == 0) head->terminal = true;
        return true;
    }
    
    // return true if the trie is empty, false otherwise
    bool empty() const{
        return head->terminal;
    }
    
    // return the amount of string in the trie
    size_t size() const{
        return count;
    }
private:
    TrieNode<SCOPE>* head;
    size_t count;
    void deleteNode(TrieNode<SCOPE>* ptr){
        if(!ptr) return;
        for (size_t i = 0; i < 26; i++){
            deleteNode(ptr->next[i]);
            delete ptr->next[i];
            ptr->next[i] = nullptr;
        }
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

#endif /* LINKED_TRIE_H */

#include <iostream>
#include <string>
#include <sstream>


namespace msac{
    template<typename S>
    struct Node{
        S item;
        Node<S>* next{nullptr};
    };
    template<typename T>
    class Stack{
    public:
        bool empty() {return head == nullptr;}
        void push(const T& item){
            head = new Node<T>{item, head};
        }
        void pop(){
            if(empty()) throw std::runtime_error("pop operation on empty stack");
            Node<T>* tmp{head};
            head = head->next;
            delete tmp;
            tmp = nullptr; // this is not necessary because tmp is in a scope
        }
        T peek(){
            if(empty()) throw std::runtime_error("peek operation on empty stack");
            return head->item;
        }
        std::string getString(){
            std::stringstream str{};
            Node<T>* ptr{head};
            while(ptr!=nullptr){
                str << ptr->item << " ";
                ptr = ptr->next;
            }
            return str.str();
        }
    private:
        Node<T>* head{nullptr};
    };
}

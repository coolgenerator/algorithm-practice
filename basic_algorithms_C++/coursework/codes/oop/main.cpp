// Name: Jason Wang
// Class: CSCI 240 M/W @12
// 3/6/2023
#include "pet.h"
#include "fish.h"
#include "dog.h"
#include <vector>
#include <iostream>

int main(){
    // Pet* p{new Fish("fred", 12)};
    std::vector<Pet*> pets{
        new Fish("Fred", 12),
        new Dog("Speckles", 20)
    };
    for(const Pet* p: pets){
        std::cout << p->speak() << std::endl;
    }
    return 0;
}
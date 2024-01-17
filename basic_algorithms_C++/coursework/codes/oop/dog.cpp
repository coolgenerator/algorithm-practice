#include "dog.h"
#include "pet.h"

Dog::Dog(const std::string& name, const size_t age) : Pet(name, "dog", age){}
std::string Dog::speak() const { return "whoof-whoof"; }
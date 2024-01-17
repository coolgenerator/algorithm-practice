#include "fish.h"
#include "pet.h"

Fish::Fish(const std::string& name, const size_t age) : Pet(name, "fish", age){}
std::string Fish::speak() const { return "blub-blub"; }
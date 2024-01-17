#include "pet.h"

Pet::Pet(const std::string& name, const std::string& species, const size_t age): name{name}, species{species}, age{age} { }
std::string Pet::getName() { return name; }
std::string Pet::getSpecies() { return species; }
size_t Pet::getAge() { return age; }
std::string Pet::speak() const { return "N/A"; }
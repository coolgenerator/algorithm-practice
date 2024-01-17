#include <string>
#ifndef PET_H
#define PET_H

class Pet{
    public:
    // ~Pet();
    Pet(const std::string&, const std::string&, const size_t);
    ~Pet() { }
    std::string getName();
    std::string getSpecies();
    size_t getAge();
    virtual std::string speak() const = 0;

    private:
    std::string name;
    size_t age;
    std::string species;
};


#endif
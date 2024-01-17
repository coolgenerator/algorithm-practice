#include "pet.h"

class Dog : public Pet{
    public:
    Dog(const std::string&, const size_t);
    ~Dog() {};
    std::string speak() const;
};
#include "pet.h"

class Fish : public Pet{
    public:
    Fish(const std::string&, const size_t);
    ~Fish() {}
    std::string speak() const;
};
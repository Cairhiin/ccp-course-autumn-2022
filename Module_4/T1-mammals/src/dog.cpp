#include "dog.hpp"

Dog::Dog(const std::string& name, double weight) 
                : Mammal(weight), name_(name) { }

const std::string& Dog::MakeSound() {
    static std::string sound { "Wuff!" };
    return sound;
}

const std::string& Dog::GetName() const {
    return name_;
}
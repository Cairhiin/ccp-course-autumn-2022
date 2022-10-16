#include "cat.hpp"

Cat::Cat(const std::string& name, double weight) 
                : Mammal(weight), name_(name) { }

const std::string& Cat::MakeSound() {
    static std::string sound { "Meow" };
    return sound;
}

const std::string& Cat::GetName() const {
    return name_;
}
#ifndef AALTO_ELEC_CPP_DOG_CLASS
#define AALTO_ELEC_CPP_DOG_CLASS

#include <string>

//Definition of simple a class with some errors

class Dog {

public:
    Dog(const int& age, const std::string& name);
    
    void SetAge(int age);
    const int& GetAge() const;
    void SetName(std::string name);
    const std::string& GetName() const;

private:
    int age_;
    std::string name_;
};

#endif
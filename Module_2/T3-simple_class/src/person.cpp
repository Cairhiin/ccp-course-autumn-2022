/*
**Objective:** Learn how to write a class definition.

In this task you will write the class definition for a **Person** class. You
have been provided with a main function that does not compile in the initial
state, because the class does not yet exist.

The Person class has two attributes: **Name** of the person, and the
**birthyear** of the person. In addition, there are two class functions to
be implemented: **GetName** that returns the name, and **GetAge** that takes a
year as an argument and returns the age of the person for that year. When
everything works properly, the program should output:

    Kalle Kankkunen is 24 years old.
    Ville Vinkkunen is 28 years old.
    Liisi Pirinen is 70 years old.

The class definition should be in the .hpp file, and the class functions
should be implemented in the .cpp file.
*/
#include <string>
#include "person.hpp"

Person::Person(const std::string& name, int birthyear)
    : name_(name), birthyear_(birthyear) {    
}

Person::Person(std::string& name, int birthyear)
    : name_(name), birthyear_(birthyear) {    
}

const std::string& Person::GetName() const {
    return name_;
}

int Person::GetAge(int year) const {
    return year - birthyear_;
}

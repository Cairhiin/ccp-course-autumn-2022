/**
 * \file dog_class.cpp
 * \brief Dog class implementation
 *
 * \details
 *
 *
 */
/*
**Objective:** Learn to construct the basic building blocks in class
definition, by fixing a broken class definition.

The exercise template contains a simple class **Dog** that has
(or is supposed to have) a constructor and a few small functions for
setting the age and the name of the dog, and asking them.
The class implements information hiding normally:
The class member variables should not be accessible directly from
outside the class, but the class state should be altered using the
functions that are accessible from elsewhere.

Both *dog_class.hpp* and *dog_class.cpp* contain errors that prevent
the program from compiling. Fix these errors such that the code compiles
and works correctly.

The main function should print the following output when everything works:

    The dog is called Mr. Wuf and it is 5 years old!
*/
#include "dog_class.hpp"

// Definitions of class functions with some errors


Dog::Dog(const int& a, const std::string& n) { 
  age_ = a; 
  name_ = n; 
}

void Dog::SetAge(int a) {
      age_ = a; 
}

const int& Dog::GetAge() const {
      return age_; 
}


void Dog::SetName(std::string n) {
      name_ = n; 
}


const std::string& Dog::GetName() const {
      return name_; 
}

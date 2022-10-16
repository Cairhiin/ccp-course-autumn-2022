#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

#include <string>

class Person {
    public:
        Person(const std::string& name, int birthyear);
        Person(std::string&, int);
        const std::string& GetName() const;
        int GetAge(int year) const; 

    private:
        std::string name_;
        int birthyear_;
};

#endif
#include "boat.hpp"
#include <vector>
#include <sstream>
#include <algorithm>

Boat::Boat(std::string register_number, std::string owner, std::string name, double draft, double power) 
            : Vehicle(register_number, owner), name_(name), draft_(draft), power_(power) { 
}

void Boat::Write(std::ostream &stream) {
    stream << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" 
            << name_ << ";" << draft_ << ";" << power_ << "\n";
}

void Boat::Print() {
    std::cout << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" 
            << name_ << ";" << draft_ << ";" << power_ << std::endl;
}

Boat *Boat::Read(std::istream &stream) {
    char idCheck = stream.peek();
    std::string line;
    
    if (idCheck != 'B') {
        return NULL;
    }

    std::getline(stream, line);
    // First replace current spaces with an underscore!
    std::replace(line.begin(), line.end(), ' ', '_');
    // Then replace the semi colons with spaces to separate the arguments
    std::replace(line.begin(), line.end(), ';', ' ');
    std::stringstream ss;
    ss.str(line);

    std::string id, register_number, owner, model;
    double draft, power;
    
    ss >> id >> register_number >> owner >> model >> draft >> power;

    if (ss) {
        // Replace the possible underscores with spaces again
        std::replace(model.begin(), model.end(), '_', ' ');
        std::replace(owner.begin(), owner.end(), '_', ' ');

        return new Boat(register_number, owner, model, draft, power);
    }
     
    return NULL;
}
#include "aircraft.hpp"
#include <vector>
#include <algorithm>
#include <sstream>

Aircraft::Aircraft(std::string register_number, std::string owner, std::string model, double wingspan, unsigned int cruise_speed) 
            : Vehicle(register_number, owner), model_(model), wingspan_(wingspan), cruise_speed_(cruise_speed) { 
}

void Aircraft::Write(std::ostream &stream) {
    stream << "A;" << GetRegisterNumber() << ";" << GetOwner() << ";" 
            << model_ << ";" << wingspan_ << ";" << cruise_speed_ << "\n";
}

void Aircraft::Print() {
    std::cout << "A;" << GetRegisterNumber() << ";" << GetOwner() << ";" 
            << model_ << ";" << wingspan_ << ";" << cruise_speed_ << std::endl;
}

Aircraft *Aircraft::Read(std::istream &stream) {
    char idCheck = stream.peek();
    std::string line;

    if (idCheck != 'A') {
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
    double wingspan;
    unsigned int cruise_speed;
    
    ss >> id >> register_number >> owner >> model >> wingspan >> cruise_speed;

    if (ss) {
        // Replace the possible underscores with spaces again
        std::replace(model.begin(), model.end(), '_', ' ');
        std::replace(owner.begin(), owner.end(), '_', ' ');
    
        return new Aircraft(register_number, owner, model, wingspan, cruise_speed);
    }
     
    return NULL;
}
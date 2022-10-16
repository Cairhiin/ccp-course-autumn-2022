#include "register.hpp"
#include "aircraft.hpp"
#include "boat.hpp"
#include <fstream>
#include <iostream>

Register::~Register() {
    for (auto vehicle : vehicles_) {
        std::cout << "Deleting: " << vehicle->GetRegisterNumber() << std::endl;
        delete(vehicle);
    }
}

void Register::Add(Vehicle* v) {
    vehicles_.push_back(v);
}

void Register::Save(const std::string& filename) const {
    std::ofstream os(filename);
    for (auto vehicle : vehicles_) {
        vehicle->Write(os);
    }
}

bool Register::ReadLine(std::istream& stream) {
    Vehicle* vehicle { Aircraft::Read(stream) };
    if (vehicle == NULL) vehicle = Boat::Read(stream);
    if (vehicle) {
        Add(vehicle);
        return true;
    }
    
    //Read and discard line as it holds no viable vehicle data
    std::string line;
    std::getline(stream, line);
    return false;
}

int Register::Load(const std::string& filename) {
    std::ifstream stream(filename);
    int count { 0 };
      if (stream.rdstate() & (stream.failbit | stream.badbit)) {
          std::cerr << "Failed" << std::endl;
          return -1;
      } else {
          while (!stream.eof()) {
            if (ReadLine(stream) == true) ++count;
          }
      }
      return count;
}

void Register::Print() {
    for (auto vehicle : vehicles_) {
        vehicle->Print();
    }
}

size_t Register::Size() const {
    return vehicles_.size();
}
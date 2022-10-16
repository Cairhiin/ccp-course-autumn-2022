#include "dragon.hpp"

Dragon::Dragon(const std::string& name, size_t age, size_t size) 
            : name_(name), age_(age), size_(size) {

}

const std::string& Dragon::GetName() const {
    return name_;
}

size_t Dragon::GetAge() const {
    return age_;
}

size_t Dragon::GetSize() const { 
    return size_;
}

const std::list<Treasure>& Dragon::GetTreasures() const {
    return treasure_;
}

std::ostream& operator<<(std::ostream& os, const Dragon& cave) {
    os << "Dragon named: " << cave.GetName() << ", age: " << cave.GetAge() << ", size: " << cave.GetSize() << std::endl;
    os << "Treasures:" << std::endl;
    for (auto treasure : cave.GetTreasures()) {
        os << treasure.name << std::endl;
    }
    return os;
}
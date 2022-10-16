#include "dragon_cave.hpp"

// Define DragonCave's methods here

DragonCave::~DragonCave() {
    for(auto it : inhabitants_) {
        std::cout << "Deleting " << it->GetName() << std::endl;
        delete it;
    }
    inhabitants_.clear(); 
}
const std::list<Dragon*>& DragonCave::GetDragons() const {
    return inhabitants_;
}

void DragonCave::Accommodate(Dragon* dragon) { 
    inhabitants_.push_back(dragon); 
}
 
void DragonCave::Evict(const std::string& name) { 
    for (auto it = inhabitants_.begin(); it != inhabitants_.end(); ++it) {
        if ((*it)->GetName() == name) {
            inhabitants_.erase(it);
            break;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const DragonCave& dragonCave) {
    out << "DragonCave dwellers:\n";
    out << "\n";
    long unsigned count { 0 };
    for (auto dragon : dragonCave.GetDragons()) {
        if (count < dragonCave.GetDragons().size() - 1) out << *dragon << std::endl;
        else out << *dragon;
        ++count;
    }
    return out;
}
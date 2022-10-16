#include "magic_dragon.hpp"
#include <algorithm>

MagicDragon::MagicDragon(const std::string& name, size_t age, size_t size)
        : Dragon(name, age, size) {}

void MagicDragon::Eat(std::list<Food>& food) {
    for (auto it = food.begin(); it != food.end(); it++) {
        if (it->type == 2) {
            ++size_;
            std::cout << "Magic dragon ate: " << it->name << std::endl;
            it = food.erase(it);
            it--;
        }
    }
}

void MagicDragon::Hoard(std::list<Treasure>& treasure) {
    for (auto it = treasure.begin(); it != treasure.end(); it++) {
        if (it->type == 2) {
            treasure_.push_back(*it);
            std::cout << "Magic dragon received: " << it->name << std::endl;
            it = treasure.erase(it);
            it--;
        }
    }
}
// Define MagicDragon's methods here

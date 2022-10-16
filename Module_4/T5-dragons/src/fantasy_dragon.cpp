#include "fantasy_dragon.hpp"
#include <algorithm>

FantasyDragon::FantasyDragon(const std::string& name, size_t age, size_t size)
        : Dragon(name, age, size) {}

void FantasyDragon::Eat(std::list<Food>& food) {
    for (auto it = food.begin(); it != food.end(); it++) {
        if (it->type == 0 || it->type == 1) {
            ++size_;
            std::cout << "Fantasy dragon ate: " << it->name << std::endl;
            it = food.erase(it);
            it--;
        }
    }
}

void FantasyDragon::Hoard(std::list<Treasure>& treasure) {
    for (auto it = treasure.begin(); it != treasure.end(); it++) {
        if (it->type == 0) {
            treasure_.push_back(*it);
            std::cout << "Fantasy dragon received: " << it->name << std::endl;
            it = treasure.erase(it);
            it--;
        }
    }
}
// Define FantasyDragon's methods here

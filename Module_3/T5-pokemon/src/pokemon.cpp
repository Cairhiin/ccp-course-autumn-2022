#include "pokemon.hpp"

PokemonCollection::PokemonCollection(PokemonCollection collection,
                    PokemonCollection collection2) {
    std::copy(collection.begin(), collection.end(), std::back_inserter(pokemons_));
    std::copy(collection2.begin(), collection2.end(), std::back_inserter(pokemons_));
    SortByName();
    pokemons_.unique();
}

void PokemonCollection::Add(const std::string& name, size_t id) {
    pokemons_.push_back(std::make_pair(name, id));
}

bool PokemonCollection::Remove(const std::string& name, size_t id) {
    for (auto it = pokemons_.begin(); it != pokemons_.end(); it++) {
        if (it->first == name && it->second == id) {
            pokemons_.erase(it);
            return true;
        }
    }
    return false;
}

void PokemonCollection::Print() const {
    for (auto it = pokemons_.begin(); it != pokemons_.end(); it++) {
        std::cout << "id: " << it->second << ", name: " << it->first << std::endl;
    }
}

void PokemonCollection::SortByName() {
    pokemons_.sort([](const std::pair<std::string, size_t> a, std::pair<std::string, size_t> b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
}

void PokemonCollection::SortById() {
    pokemons_.sort([](const std::pair<std::string, size_t> a, std::pair<std::string, size_t> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
}
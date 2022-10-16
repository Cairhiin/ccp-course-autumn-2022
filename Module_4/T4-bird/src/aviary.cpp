#include "aviary.hpp"
Aviary::~Aviary() {
     for(auto it : inhabitants_) {
        std::cout << "Deleting " << it->GetName() << std::endl;
        delete it;
     }
}

void Aviary::Add(Bird* bird) {
    //if (!bird) throw std::logic_exception("Empty pointer!");
    inhabitants_.push_back(bird);
  }
  
void Aviary::SpeakAll(std::ostream& out) {
    for (auto bird : inhabitants_) {
      bird->Speak(out);
    }
  }
  
int Aviary::Size() {
    return inhabitants_.size();
}
  
Bird* Aviary::operator[](size_t idx) {
    return inhabitants_.at(idx);
}
  
const Bird* Aviary::operator[](size_t idx) const {
    return inhabitants_.at(idx);
}
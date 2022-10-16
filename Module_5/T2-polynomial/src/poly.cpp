#include "poly.hpp"
#include <sstream>
#include <iostream>

int Poly::operator[](int exp) const {
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly operator-(const Poly& p) { 
    Poly newPoly { p };
    for (auto it = p.cbegin(); it != p.cend(); ++it) {
        newPoly[it->first] = (it->second * -1);
    }

    return newPoly;
}

Poly& Poly::operator+=(const Poly& b) {
    for (auto it = b.cbegin(); it != b.cend(); ++it) {
        const int firstKey = it->first;
        const int secondVal = values_[it->first];
        values_[firstKey] = it->second + secondVal;
    }

    return *this;
}
    
Poly& Poly::operator-=(const Poly& b) {
    for (auto it = b.cbegin(); it != b.cend(); ++it) {
        const int firstKey = it->first;
        const int secondVal = values_[it->first];
        values_[firstKey] =  secondVal - it->second;
    }

    return *this;
}

std::istream& operator>>(std::istream& is, Poly& p) {
    std::string s;
    is >> s;
 
    for (unsigned i = 0; i < s.length(); i++)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                if (i > 0 && s[i-1] != ' ') s.insert(i++, " ");
            }
            if (s[i] == 'x') s[i] = ' ';
        } 

    std::stringstream ss;
    ss << s;
  
    while (!ss.eof()) {        
        int multiplier { 0 };
        int exp { 0 };
        ss >> multiplier >> exp;
        if (multiplier != 0) {
            p[exp] += multiplier;
        }
    }
   
    return is;
}

std::ostream& operator<<(std::ostream& os, const Poly& p) {
    if (p.crbegin() == p.crend()) return os;
    for (auto it = p.crbegin(); it != p.crend(); it++) {
        if (it != p.crbegin() && it->second > 0) os << "+";
        if (it->second != 0)
            os << it->second << "x" << it->first;
    }

    return os;
}

Poly operator+(const Poly& a, const Poly& b) {
    Poly newPoly { a };
    for (auto it = b.cbegin(); it != b.cend(); ++it) {
        newPoly[it->first] += it->second;
    }

    return newPoly;
}

Poly operator-(const Poly& a, const Poly& b) { 
    Poly newPoly { a };
     for (auto it = b.cbegin(); it != b.cend(); ++it) {
        newPoly[it->first] -= it->second;
    }

    return newPoly;
}

bool operator<(const Poly& a, const Poly& b) { 
    auto it1 = a.crbegin();
    auto it2 = b.crbegin(); 
    if (it1 == a.crend() && it2 != b.crend()) return true; 
    if ((it1 != a.crend() && it2 == b.crend()) ||
        (it1 == a.crend() && it2 == b.crend())) return false; 
    
    return it1->first < it2->first;
}

bool operator==(const Poly& a, const Poly& b) {
    auto it1 = a.crbegin();
    auto it2 = b.crbegin();
    if (it1 == a.crend() && it2 == b.crend()) return true;
    if (it1 == a.crend() || it2 == b.crend()) return false; 
    
    return it1->first == it2->first;
}

bool operator>(const Poly& a, const Poly& b) {
    auto it1 = a.crbegin();
    auto it2 = b.crbegin(); 
    if (it1 != a.crend() && it2 == b.crend()) return true; 
    if ((it1 == a.crend() && it2 != b.crend()) ||
        (it1 == a.crend() && it2 == b.crend())) return false; 
    
    return it1->first > it2->first;
}

bool operator!=(const Poly& a, const Poly& b) { 
    return !(operator==(a, b));
}

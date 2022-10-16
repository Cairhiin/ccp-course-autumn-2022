#ifndef AALTO_ELEC_CPP_TO_STRING_CLASS
#define AALTO_ELEC_CPP_TO_STRING_CLASS

#include <string>
#include <iostream>
#include <sstream>

/* As an introduction to templates you will write and specialize a template function 
 * for formatting the contents of a container (string, vector, list, ...) into a string, 
 * assuming that the elements of the container are printable (with the << operator). 
 *
 * This function is called ToString and it returns the container contents in the following format 
 * (assuming a container of strings with three elements: "foo", "bar" and "baz"): 
{ foo, bar, baz }
 * (assuming a container of ints with three elements: 10, -5 and 4): 
{ 10, -5, 4 }
 * When passed a std::string, the function should, instead of returning a list of characters { f, o, o, b, a, r }, 
 * just put double quotes around the string:
"foobar"
 * Additionally, overload the function with a version that, instead of a container, 
 * takes begin and end iterators, and formats the contents in the format specified above for containers 
 * (no special handling for string iterators).
 *
 * Notes:
 * You may assume that std::strings have their regular interface. 
 * For other containers, only use the iterator interface (begin and end functions).
 * Your functions must work with at least bidirectional iterators. Note that such 
 * iterators do not have operators + and - (but they do have ++ and --).
 * If you'd really want to provide printing support for containers, 
 * you should write operator<< for them instead of a ToString function.
 * This would allow printing containers that contain other containers, etc.
 */

template <typename T>
std::string ToString(T a) {
    std::string newString = "{ ";
    auto it = a.begin();
    while (true) {
        newString += std::to_string(*it);                    
        it++;
        if (it != a.end()) {
            newString += ", ";
        } else {
            break;
        }
    }
    newString += " }"; 
    return newString;
}

template <typename T>
std::string ToString(T a, T b) {
    auto it = a;
    std::ostringstream strs;
    strs << "{ ";
    while (true) {
        strs << *it;                   
        it++;
        if (it != b) {
            strs << ", ";
        } else {
            break;
        }
    }
    strs << " }"; 
    return strs.str();
}

template <>
std::string ToString(std::string s) {
    return '\"' + s + '\"';
}


#endif
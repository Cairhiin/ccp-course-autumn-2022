/*
**Objective:** Practice basic handling of the *vector* type.

In this exercise you will need to implement the following three functions
that operate on given *int* - type vectors.

  * `GetMin` that will return the smallest value stored in the vector.

  * `GetMax` that will return the largest value stored in the vector.

  * `GetAverage` that will return the average of the values stored in the
    vector. The returned value will be of *double* type, even though
    the input values are *int*.
*/
#include "vector.hpp"

#include <vector>
#include <iostream>

int GetMin(std::vector<int> v) {
    int min = 1000;
    for (unsigned int i=0; i<v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
        }
    }
    return min; 
}

int GetMax(std::vector<int> v) {
    int max = -1000;
    for (unsigned int i=0; i<v.size(); i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;  
}

double GetAvg(std::vector<int> v) {
    double sum = 0.0;
    for (unsigned int i=0; i<v.size(); i++) {
        sum += v[i];
    }
    return sum/v.size();  
}

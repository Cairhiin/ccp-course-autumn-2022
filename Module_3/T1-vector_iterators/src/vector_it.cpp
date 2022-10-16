#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  int number = 0;   

  while (std::cin >> number) {
    v.push_back(number); 
  } 

  return v;
}

void PrintSum1(const std::vector<int>& v) {
  for (auto it = v.begin(); it < v.end() - 1; it++) {
    int nextNumber { *(it + 1) };
    int currentNumber { *it };
    std::cout << currentNumber + nextNumber << " ";
  }
  std::cout << std::endl;
}

void PrintSum2(const std::vector<int>& v) {
  for (auto itBegin = v.begin(), itEnd = v.end() - 1; itBegin < itEnd; itBegin++, itEnd--) {
    int sum { *itBegin + *itEnd };
    std::cout << sum << " ";
  }
  std::cout << std::endl;
} 
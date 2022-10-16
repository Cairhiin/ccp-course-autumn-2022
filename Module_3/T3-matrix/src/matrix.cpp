#include "matrix.hpp"

#include <iostream>
#include <vector>

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  int number;
  std::vector<std::vector<int>> matrix;
  std::vector<int> row;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> number;
      row.push_back(number);
    }
    matrix.push_back(row);
    row.clear();
  }

  return matrix;
}

Matrix Rotate90Deg(const Matrix &m) {
  std::vector<std::vector<int>> matrix = { m };

    for (int i = 0; i < (int)matrix.size(); i++) {
      for (int j = i; j < (int)matrix.size(); j++) {
        std::swap(matrix[i][j], matrix[j][i]);;
      }
    }
  
    int k;
    for (int i = 0; i < (int)matrix.size(); i++) {
      k = matrix.size()-1;
      for (int j = 0; j < k; j++) {
        std::swap(matrix[i][j], matrix[i][k]);
        k--;
      }
    }

    return matrix;
}

void Print(const Matrix &m) {
  std::cout << "Printing out a " << m.size() << " x " << m.size() << " matrix:" << std::endl;
  for (auto i : m) {
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

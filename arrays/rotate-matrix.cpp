/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>

void rotateImage(std::vector<std::vector<int>>& matrix) {
  int n = matrix.size();

  // Transpose matrix
  for (int i = 0;i < n;i++) {
    for (int j = i;j < n;j++) {
      int temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  // Reverse matrix
  for (int i = 0;i < n;i++) {
    std::reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  std::vector<std::vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  for (int i = 0;i < matrix.size(); i++) {
    for (int j = 0;j < matrix[i].size();j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
  rotateImage(matrix);
  for (int i = 0;i < matrix.size(); i++) {
    for (int j = 0;j < matrix[i].size();j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

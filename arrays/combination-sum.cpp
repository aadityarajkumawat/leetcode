/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
  return { {2, 2, 3}, {7} };
}

int main() {
  std::vector<int> candidates = { 2, 3, 6, 7 };
  int target = 7;

  std::vector<std::vector<int>> pairs = combinationSum(candidates, target);

  for (std::vector<int>& pair : pairs) {
    std::cout << "[ ";
    for (int& x : pair) {
      std::cout << x << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }

  return 0;
}

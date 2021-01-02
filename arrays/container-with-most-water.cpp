/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>

int getMaxArea(std::vector<int>& height) {
  int i = height.size() - 1;
  int maxArea = 0;
  for (int j = 0;j < i;) {
    maxArea = std::max(maxArea, std::min(height[i], height[j]) * (i - j));

    if (height[i] > height[j]) {
      j++;
    }
    else {
      i--;
    }
  }

  return maxArea;
}

int main() {
  std::vector<int> height = { 4, 3, 2, 1, 4 };
  int maxA = getMaxArea(height);
  std::cout << maxA << std::endl;
  return 0;
}

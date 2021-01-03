/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
  int index = -1;
  for (int i = 0;i < nums.size();i++) {
    if (nums[i] == target) {
      index = i;
    }
  }

  return index;
}

int main() {
  return 0;
}
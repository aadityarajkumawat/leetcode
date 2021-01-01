/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
  int i = 0;

  for (int j = 0;j < nums.size();j++) {
    if (nums[i] != nums[j]) {
      i++;
      nums[i] = nums[j];
    }
  }

  return i + 1;
}

int main() {
  std::vector<int> nums = { 1, 1, 2, 2, 3, 3, 3, 4 };
  int nn = removeDuplicates(nums);
  std::cout << nn << std::endl;

  return 0;
}

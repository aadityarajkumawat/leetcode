/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
  int i = nums.size() - 2;
  while (i >= 0 && nums[i + 1] <= nums[i]) {
    i--;
  }
  if (i >= 0) {
    int j = nums.size() - 1;
    while (j >= 0 && nums[j] <= nums[i]) {
      j--;
    }
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    std::reverse(nums.begin() + i + 1, nums.end());
  }
}

int main() {
  std::vector<int> nums = { 1, 2, 3 };
  nextPermutation(nums);
  for (int& x : nums) {
    std::cout << x;
  }
  std::cout << std::endl;
  return 0;
}

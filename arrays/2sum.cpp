/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
  int n = nums.size();
  std::vector<int> required_nums = {};
  for (int i = 0;i < n - 1;i++) {
    int first_part = nums[i];
    for (int j = i + 1;j < n;j++) {
      int second_part = target - first_part;
      if (second_part == nums[j]) {
        required_nums.push_back(i);
        required_nums.push_back(j);
      }
    }
  }

  return required_nums;
}

int main() {
  std::vector<int> nums = { 3, 5, 2, 1 };
  int target = 7;
  std::vector<int> found_indices = twoSum(nums, target);

  for (int& x : found_indices) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}

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

std::vector<int> twoSumOnSteroids(std::vector<int>& nums, int target) {
  int low = 0;
  int high = nums.size() - 1;
  std::vector<int> required_nums = {};

  while(low < high) {
    if(nums[low] + nums[high] == target) {
      required_nums.push_back(low);
      required_nums.push_back(high);
      break;
    }
    else if(nums[low] + nums[high] > target) {
      high--;
    }
    else {
      low++;
    }
  }

  return required_nums;
}

int main() {
  std::vector<int> nums = { 1, 2, 3, 5 };
  int target = 7;
  std::vector<int> found_indices = twoSumOnSteroids(nums, target);

  for (int& x : found_indices) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}

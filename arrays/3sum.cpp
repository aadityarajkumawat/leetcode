/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> res = {};
  for (int i = 0;i < nums.size() - 2;i++) {
    std::vector<int> aTriplet = {};
    int target = nums[i];
    std::cout << target << std::endl;
    int low = i + 1;
    int high = nums.size() - 1;
    int sum = 0 - nums[i];
    while (low < high) {
      if (nums[low] + nums[high] == target) {
        aTriplet.push_back(nums[i]);
        aTriplet.push_back(nums[low]);
        aTriplet.push_back(nums[high]);
      }
      // low++;
      high--;
    }
    res.push_back(aTriplet);
  }
  return res;
}

int main() {
  std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
  std::vector<std::vector<int>> f = threeSum(nums);

  for (std::vector<int>& aTrip : f) {
    for (int& x : aTrip) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>
// -1, -1, 0, 1, 2, 4
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  if (nums.size() < 3) {
    return {};
  }
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> res = {};
  for (int i = 0;i < nums.size() - 2;i++) {
    std::vector<int> aTriplet = {};
    int target = nums[i];
    int low = i + 1;
    int high = nums.size() - 1;
    int sum = 0 - nums[i];
    while (low < high) {
      if (nums[low] + nums[high] == sum) {
        aTriplet.push_back(nums[i]);
        aTriplet.push_back(nums[low]);
        aTriplet.push_back(nums[high]);
        break;
      }
      else if (nums[low] + nums[high] > sum) {
        high--;
      }
      else {
        low++;
      }
    }
    if (aTriplet.size() > 0) {
      res.push_back(aTriplet);
    }
  }
  return res;
}

int main() {
  std::vector<int> nums = { 0,0,0,0 };
  std::vector<std::vector<int>> f = threeSum(nums);

  for (std::vector<int>& aTrip : f) {
    for (int& x : aTrip) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

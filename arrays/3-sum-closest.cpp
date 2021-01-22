/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int threeSumClosest(std::vector<int>& nums, int target) {
  std::sort(nums.begin(), nums.end());
  int n = nums.size();

  int i = 0;
  int diff = INT_MAX;

  while (i < n - 2 && diff != 0) {
    int low = i + 1;
    int high = n - 1;

    while (low < high) {
      int sum = nums[i] + nums[low] + nums[high];

      if (std::abs(sum - target) < std::abs(diff)) {
        diff = target - sum;
      }

      if (sum < target) {
        low++;
      }
      else {
        high--;
      }
    }
    i++;
  }

  return (target - diff);
}

int main() {
  std::vector<int> nums = { -1, 2, 1, -4 };
  int target = 1;
  std::cout << threeSumClosest(nums, target) << std::endl;
  return 0;
}

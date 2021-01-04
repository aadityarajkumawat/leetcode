/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  // Sorting vector to use two pointer algorithm
  std::sort(nums.begin(), nums.end());
  // Output array
  std::vector<std::vector<int>> op_arr = {};

  for (int i = 0;i < nums.size() - 2;i++) {
    std::vector<int> aTrip = {};
    if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
      // Using two pointer algorithm
      int low = i + 1;
      int high = nums.size() - 1;
      // finding two nos having sum = -(current number)
      int sum = 0 - nums[i];

      while (low < high) {
        if (nums[low] + nums[high] == sum) {
          if (aTrip.size() == 3) {
            aTrip.clear();
          }
          aTrip.push_back(nums[i]);
          aTrip.push_back(nums[low]);
          aTrip.push_back(nums[high]);

          while (low < high && nums[low] == nums[low + 1]) {
            low++;
          }
          while (low < high && nums[high] == nums[high - 1]) {
            high--;
          }
          low++;
          high--;

          if (aTrip.size() == 3) {
            op_arr.push_back(aTrip);
          }
        }
        else if (nums[low] + nums[high] > sum) {
          high--;
        }
        else {
          low++;
        }
      }
    }
  }

  return op_arr;
}

int main() {
  std::vector<int> nums = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
  std::vector<std::vector<int>> f = threeSum(nums);

  for (std::vector<int>& aTrip : f) {
    for (int& x : aTrip) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}

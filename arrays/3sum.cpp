/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>
// I will have to use HashMap to pass all test cases, so will return here later
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  if (nums.size() < 3) {
    return {};
  }
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> res = {};
  int prevLow = -100, prevHigh = -100, prevI = -100;
  for (int i = 0;i < nums.size() - 2;i++) {
    std::vector<int> aTriplet = {};
    int low = i + 1;
    int high = nums.size() - 1;
    int sum = 0 - nums[i];

    while (low < high) {
      if (i == 1) {
        std::cout << "low->" << prevLow << "->" << nums[low] << std::endl;
        std::cout << "high->" << prevHigh << "->" << nums[high] << std::endl;
      }
      if (nums[low] + nums[high] == sum && ((prevLow != nums[low] && prevHigh != nums[high]) ||
        (prevI != nums[i] && prevLow != nums[low]) || (prevI != nums[i] && prevHigh != nums[high]))) {
        if (aTriplet.size() == 3) {
          res.push_back(aTriplet);
          aTriplet.clear();
        }

        aTriplet.push_back(nums[i]);
        aTriplet.push_back(nums[low]);
        aTriplet.push_back(nums[high]);

        prevLow = nums[low];
        prevHigh = nums[high];
        prevI = nums[i];
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

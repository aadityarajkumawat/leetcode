/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int>& nums) {
  int n = nums.size();
  int min_sum = 0;
  sort(nums.begin(), nums.end());

  int i = 0;
  while (i < n) {
    min_sum += nums[i];
    i += 2;
  }

  return min_sum;
}

int main() {
  std::vector<int> nums = { 6,2,6,5,1,2 };
  int max_sum = arrayPairSum(nums);
  std::cout << max_sum << std::endl;
  return 0;
}

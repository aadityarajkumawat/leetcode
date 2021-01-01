/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
  int i = 0;
  for (int j = 0;j < nums.size();j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i++;
    }
  }

  std::vector<int>::iterator to = nums.end();
  std::vector<int>::iterator from = prev(to, nums.size() - i);

  nums.erase(from, to);

  return nums.size();
}


int main() {
  std::vector<int> nums = { 1, 2, 3, 2, 3, 3, 1 };
  int req = removeElement(nums, 3);

  std::cout << req << std::endl;

  return 0;
}

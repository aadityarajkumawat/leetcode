/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
using namespace std;

bool isOneBitCharcter(vector<int>& nums) {
  int size = nums.size(), i = 0;
  while (i < size) {
    if (nums[i] == 1) {
      i += 2;
    }
    else {
      if (i == size - 1) {
        return true;
        i++;
      }
      i++;
    }
  }
  return false;
}

int main() {
  vector<int> nums = { 0, 1, 0 };

  if (isOneBitCharcter(nums)) {
    cout << "Yehhh" << endl;
  }
  else {
    cout << "Mehhh" << endl;
  }

  return 0;
}

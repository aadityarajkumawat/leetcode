#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<int>::iterator i;
  vector<int>::iterator j;
  vector<int>::iterator k;

  for (i = nums.begin(); i < nums.end(); i++) {
    for (j = nums.begin(); j < nums.end(); j++) {
      for (k = nums.begin(); k < nums.end(); k++) {
        if ((*i) + (*j) + (*k) == 0) {
          cout << "<" << (*i) << "," << (*j) << "," << (*k) << ">";
        }
      }
      cout << endl;
    }
  }

  cout << endl;

  return { {1, -1, 0} };
}

int main() {
  vector<int> nums = { -1, 0, 1, 2, -1, -4 };
  vector<vector<int>> res = threeSum(nums);
  return 0;
}


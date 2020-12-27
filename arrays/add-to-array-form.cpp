/**
* Practice Everyday
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> addToArrayForm(std::vector<int>& A, int K) {
  if (K == 0) {
    return A;
  }
  std::vector<int> res;
  int n = A.size() - 1;
  int curr = K;

  while (n > -1) {
    K += A[n];
    res.push_back(K % 10);
    K /= 10;
    n--;
  }

  reverse(res.begin(), res.end());

  return res;
}

int main() {
  std::vector<int> k = { 3,8,0,3,0,2,7,0,7,6,4,9,9,1,7,6,6,1,6,4 };
  std::vector<int> mm = addToArrayForm(k, 670);
  for (int& x : mm) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}

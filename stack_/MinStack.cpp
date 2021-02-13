#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
// vdh
class MinStack {
private:
  int ptr;
  std::vector <int> arr;
public:
  MinStack() {
    ptr = -1;
    arr = {};
  }

  void push(int x) {
    arr.push_back(x);
  }

  void pop() {
    arr.pop_back();
  }

  int top() {
    int last = arr[arr.size() - 1];
    return last;
  }

  int getMin() {
    int m = INT_MAX;
    for (int i = 0;i < arr.size();i++) {
      m = std::min(m, arr[i]);
    }
    return m;
  }
};

int main() {
  MinStack* stack = new MinStack();
  // Pushing
  stack->push(12);
  stack->push(-1);
  stack->push(4);
  stack->push(6);
  stack->push(9);

  // Pop
  stack->pop();

  // Top
  int top_element = stack->top();

  // Get Min
  int min_num = stack->getMin();

  std::cout << top_element << std::endl;
  std::cout << min_num << std::endl;

  return 0;
}

/**
* Practice Everyday
*/
#include <iostream>

int main() {
  int my_array[] = { 2, 5, 1, 0, 3 };
  int n = sizeof(my_array) / sizeof(my_array[0]);
  // Reversing array
  int start = 0; int end = n - 1;
  while (start < n / 2) {
    int temp = my_array[start];
    my_array[start] = my_array[end];
    my_array[end] = temp;
    start++;
    end--;
  }

  for (int i = 0;i < n; i++) {
    std::cout << my_array[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}

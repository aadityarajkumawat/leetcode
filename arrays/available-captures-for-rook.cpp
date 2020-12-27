/**
* Practice Everyday
*/
#include <iostream>
#include <vector>

int numRookCaptures(std::vector<std::vector<char>>& board) {
  int captures = 0;
  // Finding position of rook (x, y)
  int x, y;
  for (int i = 0;i < 8;i++) {
    std::vector<char> current_row = board[i];
    for (int j = 0;j < 8;j++) {
      if (current_row[j] == 'R') {
        x = j;
        y = i;
      }
    }
  }

  // Traversing in north
  int iterator = y - 1;
  while (iterator > -1) {
    std::vector<char> current_row = board[iterator];
    if (current_row[x] == 'B') {
      break;
    }
    else if (current_row[x] == 'p') {
      captures++;
      break;
    }
    iterator--;
  }

  // Traversing in east
  iterator = x + 1;
  while (iterator < 8) {
    std::vector<char> current_row = board[y];
    if (current_row[iterator] == 'B') {
      break;
    }
    else if (current_row[iterator] == 'p') {
      captures++;
      break;
    }
    iterator++;
  }

  iterator = y + 1;
  while (iterator < 8) {
    std::vector<char> current_row = board[iterator];
    if (current_row[x] == 'B') {
      break;
    }
    else if (current_row[x] == 'p') {
      captures++;
      break;
    }
    iterator++;
  }

  // Traversing in west
  iterator = x - 1;
  while (iterator > -1) {
    std::vector<char> current_row = board[y];
    if (current_row[iterator] == 'B') {
      break;
    }
    else if (current_row[iterator] == 'p') {
      captures++;
      break;
    }
    iterator--;
  }

  return captures;
}

int main() {
  std::vector<std::vector<char>> board = {
  {'.', '.', '.', '.', '.', '.', '.', '.'},

  {'.', '.', '.', 'p', '.', '.', '.', '.'},

  {'.', '.', '.', 'p', '.', '.', '.', '.'},

  {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},

  {'.', '.', '.', '.', '.', '.', '.', '.'},

  {'.', '.', '.', 'B', '.', '.', '.', '.'},

  {'.', '.', '.', 'p', '.', '.', '.', '.'},

  {'.', '.', '.', '.', '.', '.', '.', '.'} };

  int x = numRookCaptures(board);
  std::cout << x << std::endl;

  return 0;
}

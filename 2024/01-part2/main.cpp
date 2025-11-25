#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int main() {
  std::vector<int> left_numbers;
  std::vector<int> right_numbers;

  int num1, num2;
  int pair_count = 1;

  std::cout << "Input 2 number each line, then Ctrl+D to continue." << std::endl;

  while (std::cin >> num1 >> num2) {
    left_numbers.push_back(num1);
    right_numbers.push_back(num2);

    pair_count++;
  }

  std::vector<int> distances;
  for (int num : left_numbers) {
    int count = 0;
    for (int i : right_numbers) {
      if (num == i) {
        count++;
      }
    }
    distances.push_back(num * count);
  }

  int total = 0;
  for (int num : distances) {
    total += num;
  }

  std::cout << "Total: " << total << std::endl;

  return 0;
}

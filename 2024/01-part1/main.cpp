#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

int calculate_distance(int x, int y) {
  int z = x - y;

  if (z > 0) return z;

  return -z;
}

int main() {
  std::vector<int> left_numbers;
  std::vector<int> right_numbers;

  int num1, num2;
  int pair_count = 1;

  std::cout << "Input 2 qqnumber each line, then Ctrl+D to continue." << std::endl
  while (std::cin >> num1 >> num2) {
    left_numbers.push_back(num1);
    right_numbers.push_back(num2);

    pair_count++;
  }

  sort(left_numbers.begin(), left_numbers.end());
  sort(right_numbers.begin(), right_numbers.end());

  std::vector<int> distances;
  for (int i = 0; i < pair_count - 1; i++) {
    distances.push_back(calculate_distance(left_numbers[i], right_numbers[i]));
  }

  int total = 0;
  for (int num : distances) {
    total += num;
  }

  std::cout << "Total: " << total << std::endl;

  return 0;
}
